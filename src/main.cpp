
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
    FastLED.addLeds<LED_STRDS_CTL, LED_STRDS_PIN, LED_STRDS_ORD>(ledStrandColors, LED_STRDS_LEN);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_POWER_MAX_V, LED_POWER_MAX_MA);

    setBrightnessNone();

    FastLED.delay(2000);

    incSelectedStep();
    runSelectedStep();
    ledFadeIn();
}

void loop()
{
    runSelectedStep();

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_COLOR) {
        ledChainBaseColorHue++;
    }

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_CYCLE) {
        ledFadeOut();
        incSelectedStep();
        runSelectedStep();
        ledFadeIn();
    }
}
