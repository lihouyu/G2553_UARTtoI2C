#include <msp430.h> 

#include "config.h"
#include "functions.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;

    USCI_UART_init();
    USCI_A0_set_RXIE();

    __enable_interrupt();

    //while(1);
}

void USCI_UART_init() {
    // Setup USCI as UART @115200
    UCA0CTL1 = UCSWRST;                 // USCI software reset

    UART_PSEL |= (UART_RX + UART_TX);   // Secondary function for P1.1 and P1.2
    UART_PSEL2 |= (UART_RX + UART_TX);  // P1.1 as UCA0RXD, P1.2 as UCA0TXD

    UCA0CTL1 |= UART_BRCLK;             // Use SMCLK as clock source @8M-Hz
    // Using Low-Frequency Baud Rate Generation
    // Following typical values from the user guide
    // For baud rate @115200 from 8M-Hz
    UCA0BR0 = UART_BR0;
    UCA0BR1 = UART_BR1;
    UCA0MCTL = UART_MCTL;

    UCA0CTL1 &= ~UCSWRST;       // Exit reset status
}

void USCI_A0_set_TXIE() {
    IE2 |= UCA0TXIE;
}

void USCI_A0_set_RXIE() {
    IE2 |= UCA0RXIE;
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR(void) {
    //if (IFG2 & UCA0RXIFG) {     // Received 1 byte through UART on USCI_A0
        while (!(IFG2 & UCA0TXIFG));                // USCI_A0 TX buffer ready?
        UCA0TXBUF = UCA0RXBUF;                    // TX -> RXed character
    //}
}

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void) {
    if (IFG2 & UCA0TXIFG) {     // UCA0TXBUF is ready to accept data for sending through UART on USCI_A0
        UCA0TXBUF = 0x41;
    }
}
