
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

void         outSysSetup(unsigned long baud = OUT_SERIAL_BAUD);
void         outStepInfo(bool skip = false);
const String getStepInfoMain();
const String getStepInfoMore();
const String getStepInfoMorePalette();
const String getStepInfoSkip(bool skip);

const byte   getLedPatternListNamesMaxLength();
const byte   getLedPaletteListNamesMaxLength();

#endif
