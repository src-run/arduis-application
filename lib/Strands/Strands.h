
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_STRANDS
#define _ARDUIS_HR_STRANDS

#include <Arduino.h>
#include <FastLED.h>

#include "Switcher.h"

#ifndef LED_STRDS_LEN
    #define LED_STRDS_LEN 250
#endif

#ifndef LED_STRDS_PIN
    #define LED_STRDS_PIN 6
#endif

#ifndef LED_STRDS_BRT
    #define LED_STRDS_BRT 25
#endif

#ifndef LED_STRDS_CTL
    #define LED_STRDS_CTL WS2812B
#endif

#ifndef LED_STRDS_ORD
    #define LED_STRDS_ORD GRB
#endif

#ifndef LED_STRDS_FPS
    #define LED_STRDS_FPS 240
#endif

#ifndef LED_STRDS_SEC_CYCLE
    #define LED_STRDS_SEC_CYCLE 20000
#endif

#ifndef LED_STRDS_SEC_COLOR
    #define LED_STRDS_SEC_COLOR 10
#endif

extern CRGB ledStrandColors[LED_STRDS_LEN];

void initializeStrandsPower(int delayMilliseconds);
void initializeStrandsSetup();
void initializeStrands(int delayMilliseconds = 2500);
void strandsDisplay(int delay = -1);

#endif
