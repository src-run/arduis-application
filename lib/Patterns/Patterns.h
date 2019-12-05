
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_PATTERNS
#define _ARDUIS_HR_PATTERNS 1

#include <Arduino.h>
#include <FastLED.h>

#include "Strands.h"
#include "Utilities.h"

void incrementSelectedPattern(int by = 1);
void runLedRainbowPattern();
void runLedGlitterPattern(fract8 chance = 80);
void runLedRainbowWithGlitterPattern();
void runLedConfettiPattern();
void runLedSinelonPattern();
void runLedBpmPattern(CRGBPalette16 palette, uint8_t time = 62);
void runLedBpmCloudColorsPattern();
void runLedBpmLavaColorsPattern();
void runLedBpmRainbowNormalColorsPattern();
void runLedBpmRainbowStripeColorsPattern();
void runLedBpmOceanColorsPattern();
void runLedBpmForestColorsPattern();
void runLedBpmPartyColorsPattern();
void runLedBpmHeatColorsPattern();
void runLedJugglePattern(uint8_t fade = 20);
void runLedJuggleFadeFastPattern();
void runLedJuggleFadeNormPattern();
void runLedJuggleFadeLongPattern();

typedef void (*SimplePatternList[])();

extern SimplePatternList ledChainPatternItems;

extern uint8_t ledChainPatternIndex;
extern uint8_t ledChainBaseColorHue;

#endif
