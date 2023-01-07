
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

#include <Arduino.h>
#include <FastLED.h>

#include "Palettes.h"
#include "Patterns.h"
#include "Relay.h"
#include "Random.h"
#include "Config.h"
#include "Utilities.h"

void setup();
void loop();
void cyclePalette(bool fadeEnds = LED_PTN_FADE_ENBL, bool fadeInit = LED_PTN_FADE_ENBL);
void cyclePattern(bool fadeEnds = LED_PTN_FADE_ENBL, bool fadeInit = LED_PTN_FADE_ENBL);
void cycleRandHue();

#endif
