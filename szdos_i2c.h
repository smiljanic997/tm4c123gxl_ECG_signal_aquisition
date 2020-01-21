/*
 * szdos_i2c.h
 *
 *  Created on: Jan 1, 2020
 *      Author: smiljanic997
 */

#ifndef SZDOS_I2C_H_
#define SZDOS_I2C_H_

#include <stdint.h>

void InitI2C0(void);
uint32_t I2CReceive(uint32_t slave_addr, uint8_t reg);

#endif /* SZDOS_I2C_H_ */
