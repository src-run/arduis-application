
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

#define LED_GRP_LEN       50
#define LED_GRP_NUM       5

#define LED_STR_NUM       LED_GRP_LEN * LED_GRP_NUM
#define LED_STR_PIN       6
#define LED_STR_BRT       80
#define LED_STR_CTL       WS2812B
#define LED_STR_ORD       RGB
#define LED_STR_FPS       240
#define LED_STR_SEC_CYCLE 120000
#define LED_STR_SEC_COLOR 20

#define LED_PWR_MAX_VOLTS 5
#define LED_PWR_MAX_MAMPS 60000

extern CRGB ledStrandColors[LED_STR_NUM];

#endif
