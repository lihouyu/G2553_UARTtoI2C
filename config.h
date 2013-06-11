/**
 * LaunchPad as a I2C debug tool using the on board USB => UART bridge
 *
 * HouYu Li <karadog@hotmail.com>
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/**
 * UART configuration values
 */
#define UART_PSEL   P1SEL
#define UART_PSEL2  P1SEL2

#define UART_TX     BIT2
#define UART_RX     BIT1

#define UART_BRCLK  UCSSEL_2    // Use SMCLK as baud rate generate source

// Following values are for Baud Rate @9600 from 12M-Hz
#define UART_BR0    0xE2
#define UART_BR1    0x04
#define UART_MCTL   UCBRS_0
//========================//

/**
 * I2C configuration values
 */
#define I2C_PSEL    P1SEL
#define I2C_PSEL2   P1SEL2

#define I2C_SDA     BIT7
#define I2C_SCL     BIT6

#define BR_100KHZ_12MHZ 0x78    // Baud Rate divider for 100kHz @12MHz

#define I2C_BR  BR_100KHZ_12MHZ
//========================//

#endif /* CONFIG_H_ */
