
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Power.h"

const ACS712 ledPowerMeter {
    LED_PWR_MTR_PIN,
    LED_PWR_MTR_VOLTS,
    LED_PWR_MTR_MADC,
    LED_PWR_MTR_MVPA
};

void checkMinPwr(byte levelRequest)
{
    if (!OUT_MINPWR_STAT) { return; }

    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB { 255, 255, 255 });

    for (unsigned int mAmpsAllowed = 0; mAmpsAllowed <= LED_PWR_MAX_MAMPS; mAmpsAllowed = mAmpsAllowed + 100) {
        const PowerCalculatedBrightness limits {
            LED_STR_NUM,
            (double)mAmpsAllowed / (double)1000,
            LED_PWR_MAX_VOLTS,
            calculate_max_brightness_for_power_vmA(
                ledStrandsActiveColors,
                LED_STR_NUM,
                levelRequest,
                LED_PWR_MAX_VOLTS,
                mAmpsAllowed
            ),
            levelRequest
        };

        outPwrLimitInfo(limits);

        if (limits.levelMaximum >= limits.levelRequest) {
            break;
        }
    }

    FastLED.clear(true);
}
