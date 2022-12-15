
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

    ledStrandsRelay.begin();
    ledStrandsRelay.turnOff();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    if (!sanityCheckFuncPointers()) {
        Serial.println("Invalid pattern func pointer lists!");
        while(true) {}
    }

    FastLED.delay(2000);

    ledStrandsRelay.turnOn();
    FastLED.addLeds<LED_STRDS_CTL, LED_STRDS_PIN, LED_STRDS_ORD>(ledStrandColors, LED_STRDS_LEN);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_POWER_MAX_V, LED_POWER_MAX_MA);

    setBrightnessNone();

    FastLED.delay(2000);

    cycle();
}

void loop()
{
    runSelectedStep();

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_COLOR) {
        ledChainBaseColorHue++;
    }

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_CYCLE) {
        cycle();
    }
}

void cycle()
{
    while(runSelectedStepFadeOut()) {
        runSelectedStep(false);
    }

    incSelectedStep();
    runSelectedStep();

    while(runSelectedStepFadeIn()) {
        runSelectedStep(false);
    }
}
