
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Timer.h"

Timer::Timer()
{
    reset();
    setPeriod(1);
}

Timer::Timer(unsigned long timePeriod)
{
    reset();
    setPeriod(timePeriod);
}

void Timer::setPeriod(unsigned long timePeriod, bool timeResets)
{
    _timePeriod = timePeriod;

    if (timeResets) {
        reset();
    }
}

void Timer::setPeriodFromMili(unsigned long timePeriod, bool timeResets)
{
    setPeriod(timePeriod, timeResets);
}

void Timer::setPeriodFromSecs(unsigned int timePeriod, bool timeResets)
{
    setPeriod(static_cast<unsigned long>(timePeriod) * 1000, timeResets);
}

unsigned long Timer::getPeriod()
{
    return _timePeriod;
}

unsigned long Timer::getLastTrigger()
{
    return _lastTrigger;
}

unsigned long Timer::getTime()
{
    return millis();
}

unsigned long Timer::getElapsed()
{
    return max(0, getTime() - getLastTrigger());
}

unsigned long Timer::getRemaining()
{
    return max(0, getPeriod() - getElapsed());
}

bool Timer::ready()
{
    if(getElapsed() < getPeriod()) {
        return false;
    }

    reset();

    return true;
}

void Timer::reset()
{
    _lastTrigger = getTime();
}

void Timer::trigger()
{
    _lastTrigger = getTime() - getPeriod();
}
