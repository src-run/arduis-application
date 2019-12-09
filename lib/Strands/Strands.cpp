
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Strands.h"

CRGB ledStrandColors[LED_STRDS_LEN];

void strandsInitializePower(int delayMilliseconds) {
    ledStrandsRelay.begin();
    ledStrandsRelay.turnOn();
    delay(delayMilliseconds);
    ledStrandsRelay.turnOff();
}

void strandsInitializeSetup() {
    FastLED.addLeds<LED_STRDS_CTL, LED_STRDS_PIN, LED_STRDS_ORD>(ledStrandColors, LED_STRDS_LEN);
    FastLED.setCorrection(TypicalPixelString);
    FastLED.setBrightness(LED_STRDS_BRT);
}

void strandsInitialize(int delayMilliseconds) {
    strandsInitializePower(delayMilliseconds);
    strandsInitializeSetup();
}

void strandsPattern(int index) {
    ledChainPatternItems[index]();
}

void strandsDisplay(int delay) {
    FastLED.show();
    FastLED.delay(delay ? delay : 1000 / LED_STRDS_FPS);
}
