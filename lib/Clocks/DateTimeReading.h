
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
#include "UtilitiesInline.h"
#include "DateTimeFormat.h"

class DateTimeReading {
    private:
        DateTime   _reading;
        const char _dayList[7][12] { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    public:
        DateTimeReading(const DateTime reading) : _reading { reading } {};
        DateTime& getInternalDateTime();
        String    format(DateTimeFormat f = DateTimeFormat::FORMAT_ISO8601_FULL);
        String    format(String         f);

    protected:
        String resolveFormatSpecifierValue(DateTimeFormat f);
};
