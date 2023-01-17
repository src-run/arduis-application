
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

enum PeriodUnits : unsigned long {
    MILLIS = 1,
    SECOND = PeriodUnits::MILLIS * 1000,
    MINUTE = PeriodUnits::SECOND * 60,
    HOUR   = PeriodUnits::MINUTE * 60,
    DAY    = PeriodUnits::HOUR   * 24,
    WEEK   = PeriodUnits::DAY    * 7,
};
