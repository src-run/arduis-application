
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

extern unsigned long loopIterationCount;
extern unsigned long loopIterationTimes;

void   setupSerial(const unsigned long baud = OUT_SERIAL_BAUD);

void   outStepInfo(const bool skipped = false, const byte chances = 0);
String getStepInfoMain();
String getStepInfoMore();
String getStepInfoMorePalette();
String getStepInfoMoreLooping();
String getStepInfoSkip(const bool skipped, const byte chances);

String getItemsPlacementDesc(bool random);

byte   getListNamesMaxLength(const byte add, unsigned int (*getListSize)(const int), const char* (*getItemName)(const unsigned int));
byte   getLedPatternListNamesMaxLength(const byte add = 2);
byte   getLedPaletteListNamesMaxLength(const byte add = 2);

void   incLoopIterationCount();
