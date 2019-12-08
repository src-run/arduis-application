
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
    while (!Serial);
    Serial.begin(9600);

    rtcInitialize();
    selectorInitialize();
    strandsInitialize();
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
}
