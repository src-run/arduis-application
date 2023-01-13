
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
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setBrightness(LED_PTN_FADE_ENBL ? 0 : LED_STR_BRT);
}

void runAmpCheck(byte targetBrightness, unsigned int mAInc, unsigned int mABeg)
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB { CRGB::White });

    for (unsigned int mA = mABeg; mA <= LED_PWR_MAX_MAMPS; mA = mA + mAInc) {
        const byte   maxBLevels { calculate_max_brightness_for_power_vmA(ledStrandsActiveColors, LED_STR_NUM, targetBrightness, LED_PWR_MAX_VOLTS, mA) };
        const String outsFormat { F("FastLED %03u pixels target brightness with %01uV @ %.02fA: %03u%% (%03u/%03u)") };
        char         outsBuffer[outsFormat.length()];

        sprintf(
            outsBuffer,
            outsFormat.c_str(),
            LED_STR_NUM,
            LED_PWR_MAX_VOLTS,
            (double)mA / (double)1000,
            maxBLevels * 100 / 255,
            maxBLevels,
            targetBrightness
        );

        Serial.println(outsBuffer);

        if (maxBLevels > targetBrightness || maxBLevels >= 255) {
            break;
        }
    }

    FastLED.clear(true);
}
