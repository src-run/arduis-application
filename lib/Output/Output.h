
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#pragma once

#include "Common.h"
#include "Palettes.h"
#include "Patterns.h"

void   initializeSerial(const unsigned long baud = OUT_SERIAL_BAUD);

void   outStepInfo(const bool skip = false, const byte perc = 0);
String getStepInfoMain();
String getStepInfoMore();
String getStepInfoMorePalette();
String getStepInfoSkip(const bool skip, const byte perc);

char*  getItemsPlacementDesc(bool random);

byte   getListNamesMaxLength(const byte add, unsigned int (*getListSize)(const int), String (*getItemName)(const unsigned int));
byte   getLedPatternListNamesMaxLength(const byte add = 2);
byte   getLedPaletteListNamesMaxLength(const byte add = 2);
