/*
 * ltc2309.h
 *
 *  Created on: Jan 1, 2020
 *      Author: smiljanic997
 */

#ifndef LTC2309_H_
#define LTC2309_H_

#include <stdint.h>


// Single Ended Channel Configuration  S/D O/S  S1  S0 UNI SLP
#define LTC2309_CH0         (0x80)  //  1   0   0   0   0   0   X   X
#define LTC2309_CH1         (0xC0)  //  1   1   0   0   0   0   X   X
#define LTC2309_CH2         (0x90)  //  1   0   0   1   0   0   X   X
#define LTC2309_CH3         (0xD0)  //  1   1   0   1   0   0   X   X
#define LTC2309_CH4         (0xA0)  //  1   0   1   0   0   0   X   X
#define LTC2309_CH5         (0xE0)  //  1   1   1   0   0   0   X   X
#define LTC2309_CH6         (0xB0)  //  1   0   1   1   0   0   X   X
#define LTC2309_CH7         (0xF0)  //  1   1   1   1   0   0   X   X


// LTC2309 Configuration Bits
#define LTC2309_SLEEP_MODE          (0x04)
#define LTC2309_EXIT_SLEEP_MODE     (0x00)
#define LTC2309_UNIPOLAR_MODE       (0x08)
#define LTC2309_BIPOLAR_MODE        (0x00)
#define LTC2309_SINGLE_ENDED_MODE   (0x80)
#define LTC2309_DIFFERENTIAL_MODE   (0x00)

// LTC2309 I2C Address
#define LTC2309_I2C_ADDRESS         (0x08)

#endif /* LTC2309_H_ */
