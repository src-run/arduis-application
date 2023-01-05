
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Strands.h"

CRGB ledStrandUsedColors[LED_STR_NUM];
CRGB ledStrandHeldColors[LED_STR_NUM];

void initializeStrand()
{
    FastLED.addLeds<LED_STR_CTL, LED_STR_PIN, LED_STR_ORD>(ledStrandUsedColors, LED_STR_NUM);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS);

    ledRelay.begin();
    ledRelay.turnOn();

    FastLED.setBrightness(0);
    FastLED.delay(1000);
}
