
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
        unsigned long _lastTriggerTime;
        unsigned long _periodOrig;
        unsigned long _periodTime;
        PeriodUnit    _periodUnit;
        bool          _resetsAuto;

        void          resetAuto();

    public:
        PeriodTimer(PeriodUnit periodUnit, unsigned long periodTime = 0, bool resetsAuto = true);
        PeriodTimer(unsigned long periodTime = 0, bool resetsAuto = true) : PeriodTimer(PeriodUnit::MILLIS, periodTime, resetsAuto) {};

        void setAutoResets(bool resetsAuto);
        void setPeriodUnit(PeriodUnit periodUnit);
        void setPeriodTime(unsigned long periodTime);

        bool ready();
        void reset();

        operator bool() { return ready(); };
};
