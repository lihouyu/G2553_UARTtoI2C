/*
 * config.h
 *
 *  Created on: 2013-6-8
 *      Author: hyli
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define UART_PSEL   P1SEL
#define UART_PSEL2  P1SEL2

#define UART_TX     BIT2
#define UART_RX     BIT1

#define UART_BRCLK  UCSSEL_2

#define UART_BR0    0xE2
#define UART_BR1    0x04
#define UART_MCTL   UCBRS_0

#endif /* CONFIG_H_ */
