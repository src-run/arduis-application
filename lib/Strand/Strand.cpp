
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Strand.h"

CRGB ledStrandsActiveColors[LED_STR_NUM];
CRGB ledStrandsCustomColors[LED_STR_NUM];

void setupStrand()
{
    FastLED.addLeds<LED_STR_CTL, LED_STR_PIN, LED_STR_ORD>(ledStrandsActiveColors, LED_STR_NUM);
    FastLED.clear(true);
    FastLED.setBrightness(LED_FDR_LEVEL_BEG);
    FastLED.setCorrection(LED_STR_CRCT);
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS);
    FastLED.delay(500);
}
