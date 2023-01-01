
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_MAIN
#define _ARDUIS_HR_MAIN 1

//#define FASTLED_ALLOW_INTERRUPTS 0

#include <Arduino.h>
#include <Relay.h>
#include <FastLED.h>
#include <stdio.h>

#include "Palettes.h"
#include "Patterns.h"
#include "Relays.h"
#include "Utilities.h"

void cycle(bool fadeEnds = LED_PTN_FADE_ENBL, bool fadeInit = LED_PTN_FADE_ENBL);

#endif
