
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

    FastLED.delay(2000);

    ledStrandsRelay.turnOn();
    FastLED.addLeds<LED_STR_CTL, LED_STR_PIN, LED_STR_ORD>(ledStrandColors, LED_STR_NUM);
    FastLED.setCorrection(UncorrectedColor); //TypicalPixelString
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS);

    setBrightnessNone();

    FastLED.delay(2000);

    cycle(false);
}

void loop()
{
    runSelectedStep();

    EVERY_N_MILLISECONDS(LED_STR_SEC_COLOR) {
        ledChainBaseColorHue++;
    }

    EVERY_N_MILLISECONDS(LED_STR_SEC_CYCLE) {
        cycle();
    }
}

void cycle(bool fadeOut)
{
    while(runSelectedStepFadeEnds()) {
        runSelectedStep();
    }

    incSelectedStep();
    runSelectedStep();

    while(runSelectedStepFadeInit()) {
        runSelectedStep();
    }
}
