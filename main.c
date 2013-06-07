#include <msp430.h> 

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    // We are using external 16M-Hz crystal oscillator
    BCSCTL1 |= XTS;     // LFXT1 in high frequency mode
    BCSCTL3 |= XCAP_0;  // Internal capacitor set to 0

    BCSCTL2 |= (SELM_3 + SELS + DIVS_1);    // LFXT1CLK as source for MCLK & SMCLK
                                            // MCLK = LFXT1CLK = 16M-Hz
                                            // SMCLK = LFXT1CLK / 2 = 8M-Hz

    // Setup USCI as UART @115200
    UCA0CTL1 = UCSWRST;         // USCI software reset

    P1SEL |= (BIT1 + BIT2);     // Secondary function for P1.1 and P1.2
    P1SEL2 |= (BIT1 + BIT2);    // P1.1 as UCA0RXD, P1.2 as UCA0TXD

    UCA0CTL1 &= ~UCSWRST;       // Exit reset status
}
