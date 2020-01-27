/*
 * szdos_utils.c
 *
 *  Created on: Jan 27, 2020
 *      Author: smiljanic997
 */

#include "szdos_utils.h"

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"

void delay_ms(uint32_t ui32Ms) {

    // 1 clock cycle = 1 / SysCtlClockGet() second
    // 1 SysCtlDelay = 3 clock cycle = 3 / SysCtlClockGet() second
    // 1 second = SysCtlClockGet() / 3
    // 0.001 second = 1 ms = SysCtlClockGet() / 3 / 1000

    SysCtlDelay(ui32Ms * (SysCtlClockGet() / 3 / 1000));
}

void delay_us(uint32_t ui32Us) {
    SysCtlDelay(ui32Us * (SysCtlClockGet() / 3 / 1000000));
}
