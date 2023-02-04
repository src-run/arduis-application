
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Timers.h"

PeriodTimer PatternPeriodTimer { PeriodUnits::SECOND };
PeriodTimer PalettePeriodTimer { PeriodUnits::SECOND };
PeriodTimer ByteNumPeriodTimer { PeriodUnits::MILLIS };
PeriodTimer TempHumPeriodTimer { PeriodUnits::MINUTE };
PeriodTimer SelectsPeriodTimer { PeriodUnits::MILLIS };
PeriodTimer FrameTimeWaitTimer { PeriodUnits::MILLIS };

void setupTimers()
{
    PatternPeriodTimer.setPeriodTime(getLedPatternItemCallExecSecs() ?: LED_PTN_SEC_CYCLE);
    PalettePeriodTimer.setPeriodTime(getLedPaletteItemCallExecSecs() ?: LED_PAL_SEC_CYCLE);
    ByteNumPeriodTimer.setPeriodTime(getLedPatternItemRandHuesMili() ?: LED_STR_MIL_COLOR);
    TempHumPeriodTimer.setPeriodTime(20);
    SelectsPeriodTimer.setPeriodTime(750);
    FrameTimeWaitTimer.setPeriodTime(1000 / LED_STR_FPS);
}
