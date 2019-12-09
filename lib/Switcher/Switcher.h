
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_SWITCHER
#define _ARDUIS_HR_SWITCHER

#include <Arduino.h>
#include <Relay.h>

#ifndef LED_RELAY_PIN
    #define LED_RELAY_PIN 33
#endif

extern Relay ledStrandsRelay;

#endif