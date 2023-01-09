
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "PeriodTimer.h"

PeriodTimer::PeriodTimer(PeriodUnit periodUnit, unsigned long periodTime, bool resetsAuto)
{
    setAutoResets(resetsAuto);
    setPeriodTime(periodTime);
    setPeriodUnit(periodUnit);
    reset();
}

void PeriodTimer::setAutoResets(bool resetsAuto)
{
    _resetsAuto = resetsAuto;
}

void PeriodTimer::setPeriodUnit(PeriodUnit periodUnit)
{
    _periodUnit = periodUnit;

    setPeriodTime(_periodOrig);
}

void PeriodTimer::setPeriodTime(unsigned long periodTime)
{
    _periodOrig = periodTime;
    _periodTime = periodTime * _periodUnit;

    resetAuto();
}

bool PeriodTimer::ready()
{
    if(max(0, millis() - _lastTriggerTime) < _periodTime) {
        return false;
    }

    resetAuto();

    return true;
}

void PeriodTimer::reset()
{
    _lastTriggerTime = millis();
}

void PeriodTimer::resetAuto()
{
    if (_resetsAuto) {
        reset();
    }
}
