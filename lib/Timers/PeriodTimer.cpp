
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "PeriodTimer.h"

PeriodTimer::PeriodTimer(PeriodUnits periodUnit, unsigned long periodTime, bool resetsAuto)
{
    setResetsAuto(resetsAuto);
    setPeriodTime(periodTime);
    setPeriodUnit(periodUnit);
    reset();
}

void PeriodTimer::setPeriodTime(unsigned long periodTime)
{
    _periodOrig = periodTime;
    _periodTime = periodTime * _periodUnit;

    if (_resetsAuto) {
        reset();
    }
}

void PeriodTimer::setPeriodUnit(PeriodUnits periodUnit)
{
    _periodUnit = periodUnit;

    setPeriodTime(_periodOrig);
}

void PeriodTimer::setResetsAuto(bool resetsAuto)
{
    _resetsAuto = resetsAuto;
}

bool PeriodTimer::ready()
{
    if(max(0, millis() - _millisLast) < _periodTime) {
        return false;
    }

    reset();

    return true;
}

void PeriodTimer::reset()
{
    _millisLast = millis();
}
