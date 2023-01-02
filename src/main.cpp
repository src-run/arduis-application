
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "main.h"

void setup()
{
    Serial.begin(19200);

    setPinModeOutput(LED_BUILTIN, LOW);

    FastLED.delay(1000);
    FastLED.addLeds<LED_STR_CTL, LED_STR_PIN, LED_STR_ORD>(ledStrandColors, LED_STR_NUM);
    FastLED.setCorrection(TypicalPixelString); //UncorrectedColor, TypicalPixelString, CRGB(255, 224, 204)
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS);

    ledRelay.begin();
    ledRelay.turnOn();

    FastLED.setBrightness(0);
    FastLED.delay(1000);

    cycle(false);
}

void loop()
{
    runSelectedStep();

    EVERY_N_MILLISECONDS(LED_STR_PAL_CYCLE) {
        incLedPaletteStep();
    }

    EVERY_N_MILLISECONDS(ledPatternList[getLedPatternListStepIndx()].randHuesMili) {
        ledPatternBaseColorHue++;
    }

    EVERY_N_MILLISECONDS(ledPatternList[getLedPatternListStepIndx()].callExecMili) {
        cycle();
    }
}

void cycle(bool fadeEnds, bool fadeInit)
{
    while(fadeEnds && runSelectedStepFadeEnds()) {
        runSelectedStep(false);
    }

    incSelectedStep();
    runSelectedStep();

    while(fadeInit && runSelectedStepFadeInit()) {
        runSelectedStep(false);
    }
}
