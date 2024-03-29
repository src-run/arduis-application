
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
#include "Switch.h"
#include "Timers.h"
#include "Palettes.h"
#include "Patterns.h"

void          setup();
void          loop();
unsigned long runTimerCyclePattern(bool fadeToBlack = LED_PTN_FADE_ENBL, bool fadeToColor = LED_PTN_FADE_ENBL, bool doCycle = true);
unsigned long runTimerCyclePalette(bool fadeToBlack = LED_PTN_FADE_ENBL, bool fadeToColor = LED_PTN_FADE_ENBL, bool doCycle = true);
unsigned long runTimerCycleByteNum();
void          setupCycles();
