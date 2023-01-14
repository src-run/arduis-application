
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "CommonArduino.h"

enum PeriodUnits : unsigned long {
    MILLIS = 1,
    SECOND = PeriodUnits::MILLIS * 1000,
    MINUTE = PeriodUnits::SECOND * 60,
    HOUR   = PeriodUnits::MINUTE * 60,
    DAY    = PeriodUnits::HOUR   * 24,
    WEEK   = PeriodUnits::DAY    * 7,
};

class PeriodTimer {
    protected:
        unsigned long _millisLast { 0 };
        unsigned long _periodOrig { 0 };
        unsigned long _periodTime { 0 };
        PeriodUnits   _periodUnit { PeriodUnits::MILLIS };
        bool          _resetsAuto { true };

    public:
        PeriodTimer(PeriodUnits periodUnit = PeriodUnits::MILLIS, unsigned long periodTime = 0, bool resetsAuto = true);
        PeriodTimer(unsigned long periodTime = 0, bool resetsAuto = true) : PeriodTimer(PeriodUnits::MILLIS, periodTime, resetsAuto) {};

        void setPeriodTime(unsigned long periodTime);
        void setPeriodUnit(PeriodUnits periodUnit);
        void setResetsAuto(bool resetsAuto);

        bool ready();
        void reset();

        operator bool() { return ready(); };
};
