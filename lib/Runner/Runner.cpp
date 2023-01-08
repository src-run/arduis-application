
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Runner.h"

MillisTimeRunner cyclePatternMillisTimeRunner = MillisTimeRunner(LED_STR_SEC_CYCLE);
MillisTimeRunner cyclePaletteMillisTimeRunner = MillisTimeRunner(LED_STR_PAL_CYCLE);
MillisTimeRunner cycleByteNumMillisTimeRunner = MillisTimeRunner(LED_STR_SEC_COLOR);

MillisTimeRunner::MillisTimeRunner()
{
    reset(); setPeriod(1);
}

MillisTimeRunner::MillisTimeRunner(unsigned long timePeriod)
{
    reset(); setPeriod(timePeriod);
}

void MillisTimeRunner::setPeriod(unsigned long timePeriod)
{
    _timePeriod = timePeriod;
}

unsigned long MillisTimeRunner::getPeriod()
{
    return _timePeriod;
}

unsigned long MillisTimeRunner::getLastTrigger()
{
    return _lastTrigger;
}

unsigned long MillisTimeRunner::getTime()
{
    return millis();
}

unsigned long MillisTimeRunner::getElapsed()
{
    return getTime() - getLastTrigger();
}

unsigned long MillisTimeRunner::getRemaining()
{
    return max(0, getPeriod() - getElapsed());
}

bool MillisTimeRunner::ready()
{
    bool isReady = (getElapsed() >= getPeriod());
    if (isReady) { reset(); }
    return isReady;
}

void MillisTimeRunner::reset()
{
    _lastTrigger = getTime();
}

void MillisTimeRunner::trigger()
{
    _lastTrigger = getTime() - getPeriod();
}

void initializeRunner()
{
    cyclePatternMillisTimeRunner.setPeriod(getLedPatternItemCallExecMili());
    cyclePaletteMillisTimeRunner.setPeriod(getLedPaletteItemCallExecMili());
    cycleByteNumMillisTimeRunner.setPeriod(getLedPatternItemRandHuesMili());
}
