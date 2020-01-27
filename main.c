/*
 * main.c
 *
 *  Created on: Jan 1, 2020
 *      Author: smiljanic997
 */

#include <stdint.h>
#include <stdbool.h>
#include "szdos_uart.h"
#include "szdos_i2c.h"
#include "ltc2309.h"
#include "driverlib/sysctl.h"

#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "pulseoximeter.h"
#include "utils/uartstdio.h"
#include "szdos_ftoa.h"
#include "szdos_utils.h"

#define CHANNEL_0_UNIPOLAR (LTC2309_CH0 | LTC2309_UNIPOLAR_MODE)

char buf[20];

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
    SYSCTL_XTAL_16MHZ);

    init_console();

    InitI2C0();

    while (1)
    {
        int32_t reading;
        reading = I2CReceive(LTC2309_I2C_ADDRESS, CHANNEL_0_UNIPOLAR);
        f = reading * 5.0 / 4095.0;
        UARTprintf("%s\n", ftoa(f, buf, 10));
        delay_us(4);
    }
}
