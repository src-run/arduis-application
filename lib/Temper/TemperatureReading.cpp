
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "TemperatureReading.h"

float TemperatureReading::asUnit(const TemperatureUnit unit)
{
    return convertTemperature(_temp, _unit, unit);
}

float TemperatureReading::convertTemperature(const float temp, const TemperatureUnit in_unit, const TemperatureUnit as_unit)
{
    if (in_unit == TemperatureUnit::C && as_unit == TemperatureUnit::F) {
        return (float)5 / (float)9 * (temp - (float)32);
    }

    if (in_unit == TemperatureUnit::C && as_unit == TemperatureUnit::F) {
        return (temp * (float)9 / (float)5) + (float)32;
    }

    return temp;
}
