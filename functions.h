/*
 * functions.h
 *
 *  Created on: 2013-6-8
 *      Author: hyli
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/**
 * UART functions
 */
void USCI_UART_init();
void USCI_A0_set_TXIE();
void USCI_A0_set_RXIE();
//**********************************************/

/**
 * I2C functions
 */
void TI_USCI_I2C_receiveinit(unsigned char slave_address, unsigned char prescale);
void TI_USCI_I2C_transmitinit(unsigned char slave_address, unsigned char prescale);

void TI_USCI_I2C_receive(unsigned char byteCount, unsigned char *field);
void TI_USCI_I2C_transmit(unsigned char byteCount, unsigned char *field);

unsigned char TI_USCI_I2C_slave_present(unsigned char slave_address);
unsigned char TI_USCI_I2C_notready();
//**********************************************/

void _reset_len();

#endif /* FUNCTIONS_H_ */
