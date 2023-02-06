
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
    _periodOrig = max(0U, periodTime);
    _periodTime = _periodOrig * getPeriodUnitMultiplier();

    if (_resetsAuto) {
        reset();
    }
}

unsigned int PeriodTimer::getPeriodOrig()
{
    return _periodOrig;
}

unsigned int PeriodTimer::getPeriodTime()
{
    return _periodTime;
}

void PeriodTimer::setPeriodUnit(PeriodUnits periodUnit)
{
    _periodUnit = periodUnit;

    setPeriodTime(_periodOrig);
}

PeriodUnits PeriodTimer::getPeriodUnit()
{
    return _periodUnit;
}

unsigned long PeriodTimer::getPeriodUnitMultiplier()
{
    return static_cast<unsigned long>(getPeriodUnit());
}

unsigned long PeriodTimer::getPeriodElapsed()
{
    return millis() - _millisLast;
}

unsigned long PeriodTimer::getPeriodRemaining()
{
    unsigned long remaining = max(0U, _periodTime - getPeriodElapsed());

    return remaining > getPeriodTime() ? 0 : remaining;
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

void PeriodTimer::setResetsAuto(bool resetsAuto)
{
    _resetsAuto = resetsAuto;
}
