/**
 * LaunchPad as a I2C debug tool using the on board USB => UART bridge
 *
 * HouYu Li <karadog@hotmail.com>
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/**
 * UART functions
 */
void USCI_UART_plain_init();
//========================//

/**
 * I2C functions
 * From TI SLAA382
 */
void TI_USCI_I2C_receiveinit(unsigned char slave_address, unsigned char prescale);
void TI_USCI_I2C_transmitinit(unsigned char slave_address, unsigned char prescale);

void TI_USCI_I2C_receive(unsigned char byteCount, unsigned char *field);
void TI_USCI_I2C_transmit(unsigned char byteCount, unsigned char *field);

unsigned char TI_USCI_I2C_slave_present(unsigned char slave_address);
unsigned char TI_USCI_I2C_notready();
//========================//

#endif /* FUNCTIONS_H_ */
