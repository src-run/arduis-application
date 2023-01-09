
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Runner.h"

Timer PatternTimer = Timer(UnitPeriod::SECOND);
Timer PaletteTimer = Timer(UnitPeriod::SECOND);
Timer ByteNumTimer = Timer(UnitPeriod::MILLIS);

void setupTimers()
{
    PatternTimer.setTimePeriod(getLedPatternItemCallExecSecs() ?: LED_PTN_SEC_CYCLE);
    PaletteTimer.setTimePeriod(getLedPaletteItemCallExecSecs() ?: LED_PAL_SEC_CYCLE);
    ByteNumTimer.setTimePeriod(getLedPatternItemRandHuesMili() ?: LED_STR_MIL_COLOR);
}
