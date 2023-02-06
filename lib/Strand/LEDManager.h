
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "CommonFastLED.h"
#include "Config.h"
#include "Random.h"
#include "Utilities.h"

struct LEDMaxPower {
    unsigned int maxVolts;
    unsigned int maxMAmps;
};

class LEDManager {
    private:
        unsigned int       _ledStrSize;
        LEDColorCorrection _correction;
        LEDMaxPower        _ledsMaxPwr;

    public:
        CRGB               _ledColours[LED_STR_NUM];

        LEDManager(unsigned int ledStrSize = LED_STR_NUM, LEDColorCorrection correction = LED_STR_CRCT, LEDMaxPower ledsMaxPwr = { LED_PWR_MAX_VOLTS, LED_PWR_MAX_MAMPS }) :
            _ledStrSize { ledStrSize },
            _correction { correction },
            _ledsMaxPwr { ledsMaxPwr }
        {};

        void setupFastLED();
};
