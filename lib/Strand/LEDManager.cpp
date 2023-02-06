
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include"LEDManager.h"

void LEDManager::setupFastLED()
{
    FastLED.addLeds<LED_STR_CTL, LED_STR_PIN, LED_STR_ORD>(_ledColours, _ledStrSize);
    FastLED.clear(true);
    FastLED.setBrightness(LED_FDR_LEVEL_BEG);
    FastLED.setCorrection(_correction);
    FastLED.setMaxPowerInVoltsAndMilliamps(_ledsMaxPwr.maxVolts, _ledsMaxPwr.maxMAmps);
    FastLED.delay(500);
}
