
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

void   outSysSetup(const unsigned long baud = OUT_SERIAL_BAUD);
void   outStepInfo(const bool skip = false, const byte perc = 0);
String getStepInfoMain();
String getStepInfoMore();
String getStepInfoMorePalette();
String getStepInfoSkip(const bool skip, const byte perc);

char*  getItemsPlacementDesc(bool random);

byte   getLedPatternListNamesMaxLength(const byte a = 2);
byte   getLedPaletteListNamesMaxLength(const byte a = 2);

#endif
