
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "Common.h"

class MillisTimeRunner {
    protected:
        unsigned long _timePeriod;
        unsigned long _lastTrigger = 0;

    public:
        MillisTimeRunner();
        MillisTimeRunner(unsigned long timePeriod);
        void setPeriod(unsigned long timePeriod);
        unsigned long getPeriod();
        unsigned long getLastTrigger();
        unsigned long getTime();
        unsigned long getElapsed();
        unsigned long getRemaining();
        bool ready();
        void reset();
        void trigger();
        operator bool() { return ready(); }
};

void initializeRunner();

extern MillisTimeRunner cyclePatternMillisTimeRunner;
extern MillisTimeRunner cyclePaletteMillisTimeRunner;
extern MillisTimeRunner cycleByteNumMillisTimeRunner;
