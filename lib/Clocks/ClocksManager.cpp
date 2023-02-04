
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "ClocksManager.h"

void ClocksManager::begins()
{
    if (!_started && !_clocker.begin(&SYS_WIRE_OBJECT)) {
        writeI2cDevFailureAndDelayForever("DS3231", _address);
    }

    _started = true;

    setupClockInfo();
    writeDebugInfo();
}

DateTimeReading ClocksManager::getDateTime()
{
    return DateTimeReading(_clocker.now());
}

void ClocksManager::setupClockInfo()
{
    if (_clocker.lostPower()) {
        _clocker.adjust(getCompilationDateTime().getInternalDateTime());
        _updated = true;
    }
}

void ClocksManager::writeDebugInfo()
{
    Serial.print(F("=== RTC   - Clock Reset  : "));
    Serial.println(_updated ? F("true") : F("false"));
    Serial.print(F("=== RTC   - Compile DT   : "));
    Serial.println(getCompilationDateTime().format(DateTimeFormat::FORMAT_ISO8601_FULL));
    Serial.print(F("=== RTC   - Current DT   : "));
    Serial.println(getDateTime().format(DateTimeFormat::FORMAT_ISO8601_FULL));
    Serial.print(F("=== RTC   - Current Unix : "));
    Serial.println(getDateTime().format(DateTimeFormat::FORMAT_UNIXTIME));
}
