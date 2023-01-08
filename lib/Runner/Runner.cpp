
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Runner.h"

Timer PatternTimer = Timer();
Timer PaletteTimer = Timer();
Timer ByteNumTimer = Timer();

void setupRunner()
{
    PatternTimer.setPeriodFromSecs(getLedPatternItemCallExecSecs() ?: LED_PTN_SEC_CYCLE);
    PaletteTimer.setPeriodFromSecs(getLedPaletteItemCallExecSecs() ?: LED_PAL_SEC_CYCLE);
    ByteNumTimer.setPeriodFromMili(getLedPatternItemRandHuesMili() ?: LED_STR_SEC_COLOR);
}
