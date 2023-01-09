
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Common.h"

enum UnitPeriod : unsigned long {
    MILLIS = 1,
    SECOND = 1000,
    MINUTE = 60000,
    HOUR   = 3600000,
};

class Timer {
    protected:
        unsigned long _lastTrigger;
        bool          _autoResets;
        unsigned long _timePeriod;
        UnitPeriod    _unitPeriod;

        unsigned long getTimePeriodElapsed();
        unsigned long getTimePeriodRemaining();

    public:
        Timer(UnitPeriod unitPeriod, unsigned long timePeriod = 0, bool autoResets = true);
        Timer(unsigned long timePeriod = 0, bool autoResets = true) : Timer(UnitPeriod::MILLIS, timePeriod, autoResets) {};

        void setAutoResets(bool autoResets);
        void setUnitPeriod(UnitPeriod unitPeriod);
        void setTimePeriod(unsigned long timePeriod);

        bool ready();
        void reset();

        operator bool() { return ready(); };
};
