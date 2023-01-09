
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Timer.h"

Timer::Timer(UnitPeriod unitPeriod, unsigned long timePeriod, bool autoResets)
{
    _unitPeriod = unitPeriod;
    _timePeriod = timePeriod;
    _autoResets = autoResets;
    reset();
}

void Timer::setAutoResets(bool autoResets)
{
    _autoResets = autoResets;
}

void Timer::setUnitPeriod(UnitPeriod unitPeriod)
{
    _unitPeriod = unitPeriod;
}

void Timer::setTimePeriod(unsigned long timePeriod)
{
    _timePeriod = timePeriod * _unitPeriod;

    if (_autoResets) {
        reset();
    }
}

bool Timer::ready()
{
    if(getTimePeriodElapsed() < _timePeriod) {
        return false;
    }

    reset();

    return true;
}

void Timer::reset()
{
    _lastTrigger = millis();
}

unsigned long Timer::getTimePeriodElapsed()
{
    return max(0, millis() - _lastTrigger);
}

unsigned long Timer::getTimePeriodRemaining()
{
    return max(0, _timePeriod - getTimePeriodElapsed());
}
