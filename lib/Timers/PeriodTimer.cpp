
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
    _periodTime = periodTime * static_cast<unsigned long>(_periodUnit);

    if (_resetsAuto) {
        reset();
    }
}

void PeriodTimer::setPeriodTimeGtZero(unsigned long periodTime)
{
    if (periodTime > 0) {
        setPeriodTime(periodTime);
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

unsigned long PeriodTimer::getPeriodElapsed()
{
    return millis() - _millisLast;
}

unsigned long PeriodTimer::getPeriodRemaining()
{
    return max(0, _periodTime - getPeriodElapsed());
}

bool PeriodTimer::ready()
{
    if(getPeriodElapsed() < _periodTime) {
        return false;
    }

    reset();

    return true;
}

void PeriodTimer::reset()
{
    _millisLast = millis();
}

void PeriodTimer::resetConditionally(const bool condition)
{
    if (condition) {
        reset();
    }
}
