
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Common.h"

enum PeriodUnit : unsigned long {
    MILLIS = 1,
    SECOND = PeriodUnit::MILLIS * 1000,
    MINUTE = PeriodUnit::SECOND * 60,
    HOUR   = PeriodUnit::MINUTE * 60,
    DAY    = PeriodUnit::HOUR   * 24,
    WEEK   = PeriodUnit::DAY    * 7,
};

class PeriodTimer {
    protected:
        unsigned long _millisLast { 0 };
        unsigned long _periodOrig { 0 };
        unsigned long _periodTime { 0 };
        PeriodUnit    _periodUnit { PeriodUnit::MILLIS };
        bool          _resetsAuto { true };

    public:
        PeriodTimer(PeriodUnit periodUnit = PeriodUnit::MILLIS, unsigned long periodTime = 0, bool resetsAuto = true);
        PeriodTimer(unsigned long periodTime = 0, bool resetsAuto = true) : PeriodTimer(PeriodUnit::MILLIS, periodTime, resetsAuto) {};

        void setPeriodTime(unsigned long periodTime);
        void setPeriodUnit(PeriodUnit periodUnit);
        void setResetsAuto(bool resetsAuto);

        bool ready();
        void reset();

        operator bool() { return ready(); };
};
