
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
#include "Counter.h"
#include "I2CUtilities.h"
#include "I2CDeviceInfo.h"
#include "PowerCalculatedBrightness.h"
#include "EffectDefinitionDetail.h"
#include "EffectFactor.h"
#include "EffectGlints.h"
#include "EffectStatus.h"

void   setupOutput(const unsigned long baud = OUT_SERIAL_BAUD);

void   outStepInfo(const bool skipped = false, const byte chances = 0);
String getStepInfoMain();
String getStepInfoMore();
String getStepInfoMorePalette();
String getStepInfoMoreCounter();
String getStepInfoSkip(const bool skipped, const byte chances);
void   outPwrLimitInfo(const PowerCalculatedBrightness& maximumBrightness);
void   outI2CFoundInfo(const I2CDeviceInfo& deviceInfo);

byte   getListNamesMaxLength(const byte add, unsigned int (*getListSize)(), const char* (*getItemName)(const unsigned int));
byte   getLedPatternListNamesMaxLength(const byte add = 2);
byte   getLedPaletteListNamesMaxLength(const byte add = 2);

inline String getItemsAvailModeDesc(bool status, String valueT, String valueF, bool shortDesc = true) __attribute__((always_inline));
inline String getItemsStateBoolDesc(bool status, bool shortDesc = true) __attribute__((always_inline));
inline String getItemsPlacementDesc(bool random, bool shortDesc = true) __attribute__((always_inline));
inline String getItemsGlintModeDesc(bool glints, bool shortDesc = true) __attribute__((always_inline));

String getItemsAvailModeDesc(bool status, String valueT, String valueF, bool shortDesc)
{
    return status
        ? (shortDesc ? valueT.substring(0, 1) : valueT)
        : (shortDesc ? valueF.substring(0, 1) : valueF);
}

String getItemsStateBoolDesc(bool status, bool shortDesc)
{
    return getItemsAvailModeDesc(status, F("true"), F("false"), shortDesc);
}

String getItemsPlacementDesc(bool random, bool shortDesc)
{
    return getItemsAvailModeDesc(random, F("rand"), F("seql"), shortDesc);
}

String getItemsGlintModeDesc(bool glints, bool shortDesc)
{
    return getItemsAvailModeDesc(glints, F("glints"), F("normal"), shortDesc);
}

// EXTERNAL DECLARATIONS/DEFINITIONS

extern const EffectDefinitionDetail* getLedPatternItemActionDetail();
extern String       getLedPatternItemName();
extern const char*  getLedPatternItemNameC();
extern const char*  getLedPatternItemNameC(const unsigned int);
extern unsigned int getLedPatternItemCallExecSecs();
extern unsigned int getLedPatternItemRandHuesMili();
extern unsigned int getLedPatternListStepNumb();
extern unsigned int getLedPatternListStepNumbReal();
extern unsigned int getLedPatternListSize();

extern bool         isLedPaletteStepRunning();
extern unsigned int getLedPaletteListStepNumb();
extern unsigned int getLedPaletteListStepNumbReal();
extern String       getLedPaletteItemName();
extern const char*  getLedPaletteItemNameC();
extern const char*  getLedPaletteItemNameC(const unsigned int);
extern unsigned int getLedPaletteItemCallExecSecs();
extern unsigned int getLedPaletteItemRandHuesMili();
extern unsigned int getLedPaletteListSize();
