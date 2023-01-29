
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

enum class DateTimeFormat : byte {
    FORMAT_ISO8601_FULL, FORMAT_ISO8601_TIME, FORMAT_ISO8601_DATE,
    FORMAT_VERBOSE_FULL, FORMAT_VERBOSE_TIME, FORMAT_VERBOSE_DATE,
    FORMAT_REGULAR_FULL, FORMAT_REGULAR_TIME, FORMAT_REGULAR_DATE,
    FORMAT_MINIMAL_FULL, FORMAT_MINIMAL_TIME, FORMAT_MINIMAL_DATE,
    FORMAT_UNIXTIME,
};
