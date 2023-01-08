
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Common.h"

class Timer {
    protected:
        unsigned long _timePeriod;
        unsigned long _lastTrigger = 0;

    public:
        Timer();
        Timer(unsigned long timePeriod);
        void setPeriod(unsigned long timePeriod, bool timeResets = false);
        void setPeriodFromMili(unsigned long timePeriod, bool timeResets = true);
        void setPeriodFromSecs(unsigned int timePeriod, bool timeResets = true);
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
