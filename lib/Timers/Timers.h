
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "Config.h"
#include "Patterns.h"
#include "Palettes.h"
#include "PeriodTimer.h"

extern PeriodTimer PatternPeriodTimer;
extern PeriodTimer PalettePeriodTimer;
extern PeriodTimer ByteNumPeriodTimer;
extern PeriodTimer TempHumPeriodTimer;
extern PeriodTimer SelectsPeriodTimer;

void setupTimers();
