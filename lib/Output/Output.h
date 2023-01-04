
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#ifndef _ARDUIS_HR_OUTPUT
#define _ARDUIS_HR_OUTPUT

#include <Arduino.h>

#include <Palettes.h>
#include <Patterns.h>
#include <Utilities.h>

void         outSysSetup(const unsigned long baud = OUT_SERIAL_BAUD);

void         outStepInfo(const bool skip = false, const fract8 perc = 0);
const String getStepInfoMain();
const String getStepInfoMore();
const String getStepInfoMorePalette();
const String getStepInfoSkip(const bool skip, const fract8 perc);

const byte   getLedPatternListNamesMaxLength(const byte a = 2);
const byte   getLedPaletteListNamesMaxLength(const byte a = 2);

#endif
