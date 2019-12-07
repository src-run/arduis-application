
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
    Serial.begin(9600);

    ledStrandsRelay.begin();
    ledStrandsRelay.turnOn();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    delay(2500);

    ledStrandsRelay.turnOff();
    FastLED.addLeds<LED_STRDS_CTL, LED_STRDS_PIN, LED_STRDS_ORD>(ledStrandColors, LED_STRDS_LEN);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setBrightness(LED_STRDS_BRT);
}

void loop()
{
    ledChainPatternItems[ledChainPatternIndex]();

    FastLED.show();
    FastLED.delay(1000/LED_STRDS_FPS);

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_COLOR) {
        ledChainBaseColorHue++;
    }

    EVERY_N_MILLISECONDS(LED_STRDS_SEC_CYCLE) {
        incrementSelectedPattern();
    }

    EVERY_N_MILLISECONDS(20000) {
        Serial.println("Toggling builtin LED [ ON] ...");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10000);
        Serial.println("Toggling builtin LED [OFF] ...");
        digitalWrite(LED_BUILTIN, LOW);
    }
}
