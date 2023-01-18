
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
#include "CommonFastLED.h"
#include "CommonAdafruitRTClib.h"
#include "CommonAdafruitSHT4x.h"
#include "CommonAdafruitVEML7700.h"
#include "CommonAdafruitTSL2591.h"
#include "Power.h"
#include "Relays.h"
#include "Temper.h"
#include "Timers.h"
#include "Counter.h"
#include "Palettes.h"
#include "Patterns.h"
#include "EffectFactorGenerator.h"
#include "EffectFading.h"
#include "Output.h"

extern SimpleCounter CycleCount;

void          setup();
void          loop();
unsigned long runTimerPattern(bool doCycle = true);
unsigned long runTimerPalette(bool doCycle = true);
unsigned long runTimerByteNum();
void          setupCycles();
