
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "DateTimeReading.h"

DateTime& DateTimeReading::getInternalDateTime()
{
    return _reading;
}

String DateTimeReading::format(DateTimeFormat f)
{
    switch (f)
    {
        case DateTimeFormat::FORMAT_UNIXTIME:
            return String(_reading.unixtime());

        default:
            break;
    }

    return format(resolveFormatSpecifierValue(f));
}

String DateTimeReading::format(String f)
{
    byte length { cstrByte(f.length() + 1) };
    char buffer[length];

    f.toCharArray(buffer, length);

    return String(_reading.toString(buffer));
}

String DateTimeReading::resolveFormatSpecifierValue(DateTimeFormat f)
{
    switch (f) {
        case DateTimeFormat::FORMAT_VERBOSE_TIME:
            return F("hh:mm:ss");

        case DateTimeFormat::FORMAT_VERBOSE_DATE:
            return F("DDD, DD MMM YYYY");

        case DateTimeFormat::FORMAT_VERBOSE_FULL:
            return F("DDD, DD MMM YYYY hh:mm:ss");


        case DateTimeFormat::FORMAT_REGULAR_TIME:
            return F("hh:mm:ss");

        case DateTimeFormat::FORMAT_REGULAR_DATE:
            return F("DD MMM YYYY");

        case DateTimeFormat::FORMAT_REGULAR_FULL:
            return F("DD MMM YYYY hh:mm:ss");


        case DateTimeFormat::FORMAT_MINIMAL_TIME:
            return F("hh:mm:ss");

        case DateTimeFormat::FORMAT_MINIMAL_DATE:
            return F("YYYY-MM-DD");

        case DateTimeFormat::FORMAT_MINIMAL_FULL:
            return F("YYYY-MM-DD@hh:mm:ss");


        case DateTimeFormat::FORMAT_ISO8601_TIME:
            return F("hh:mm:ss");

        case DateTimeFormat::FORMAT_ISO8601_DATE:
            return F("YYYY-MM-DD");

        case DateTimeFormat::FORMAT_ISO8601_FULL:
        default:
            return F("YYYY-MM-DDThh:mm:ss");
    }
}
