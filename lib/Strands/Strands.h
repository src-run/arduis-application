
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
#include <Config.h>
#include <Relays.h>

extern CRGB ledStrandUsedColors[LED_STR_NUM];
extern CRGB ledStrandHeldColors[LED_STR_NUM];

void initializeStrand();

#endif
