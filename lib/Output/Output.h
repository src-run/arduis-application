
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "CommonFastLED.h"
#include "Config.h"
#include "Palettes.h"
#include "Patterns.h"
#include "Utilities.h"
#include "PowerCalculatedBrightness.h"

void   setupSerial(const unsigned long baud = OUT_SERIAL_BAUD);

void   outStepInfo(const bool skipped = false, const byte chances = 0);
String getStepInfoMain();
String getStepInfoMore();
String getStepInfoMorePalette();
String getStepInfoMoreCounter();
String getStepInfoSkip(const bool skipped, const byte chances);
void   outPwrLimitInfo(const PowerCalculatedBrightness& maximumBrightness);

String getItemsPlacementDesc(bool random);
String getItemsGlintModeDesc(bool glints);

byte   getListNamesMaxLength(const byte add, unsigned int (*getListSize)(const int), const char* (*getItemName)(const unsigned int));
byte   getLedPatternListNamesMaxLength(const byte add = 2);
byte   getLedPaletteListNamesMaxLength(const byte add = 2);
