
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
#include "Random.h"
#include "Utilities.h"
#include "Output.h"
#include "PalettesGradient.h"
#include "PalettesList.h"
#include "PalettesAction.h"
#include "PalettesActionRunner.h"
#include "EffectDefinitionDetail.h"
#include "EffectDefinitionGlints.h"
#include "EffectDefinitionTimers.h"

extern const unsigned int paletteSizeItems;

inline unsigned int   getLedPaletteListSize(const int adds = 0) __attribute__((always_inline));
const PalettesAction* getLedPaletteDeft();
const PalettesAction* getLedPaletteItem(const unsigned int idx);
const PalettesAction* getLedPaletteItem();

const EffectDefinitionDetail* getLedPaletteItemActionDetail(const unsigned int idx);
const EffectDefinitionDetail* getLedPaletteItemActionDetail();
const ActionRunnerPalette*    getLedPaletteItemActionRunner(const unsigned int idx);
const ActionRunnerPalette*    getLedPaletteItemActionRunner();
const EffectDefinitionTimers* getLedPaletteItemActionTimers(const unsigned int idx);
const EffectDefinitionTimers* getLedPaletteItemActionTimers();
const EffectDefinitionGlints* getLedPaletteItemActionGlints(const unsigned int idx);
const EffectDefinitionGlints* getLedPaletteItemActionGlints();

String              getLedPaletteItemName(const unsigned int idx);
String              getLedPaletteItemName();
const char*         getLedPaletteItemNameC(const unsigned int idx);
const char*         getLedPaletteItemNameC();
const CRGBPalette16 getLedPaletteItemComp(const unsigned int idx);
const CRGBPalette16 getLedPaletteItemComp();
unsigned int        getLedPaletteItemCallExecSecs();

unsigned int getLedPaletteListRandIndx();
unsigned int getLedPaletteListRandIndxSeql();
unsigned int getLedPaletteListStepInit();
unsigned int getLedPaletteListStepNext(unsigned int idx);
unsigned int getLedPaletteListStepIndx(bool indexIncr = false);
unsigned int incLedPaletteListStepIndx();
unsigned int getLedPaletteListStepNumb();

bool isLedPaletteStepNamed();
bool isLedPaletteStepStarted();
bool isLedPaletteStepRunning();

void incPalettesStep();

unsigned int getLedPaletteListSize(const int adds)
{
    return paletteSizeItems + adds;
}
