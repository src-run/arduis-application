
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
#include "PeriodTimer.h"

extern PeriodTimer PatternPeriodTimer;
extern PeriodTimer PalettePeriodTimer;
extern PeriodTimer ByteNumPeriodTimer;

void setupTimers();
