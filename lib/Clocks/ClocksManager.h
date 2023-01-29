
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
#include "CommonAdafruitRTClib.h"
#include "Config.h"
#include "Utilities.h"
#include "DateTimeReading.h"

class ClocksManager {
    private:
        byte       _address;
        RTC_DS3231 _clocker;
        bool       _started { false };
        bool       _updated { false };

    public:
        ClocksManager(const byte address = 0x68) : _address { address } {};

        void               begins();
        DateTimeReading    getDateTime();

    protected:
        void setupClockInfo();
        void writeDebugInfo();
};
