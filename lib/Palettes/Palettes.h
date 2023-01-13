
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
#include "Patterns.h"
#include "PalettesGradient.h"
#include "PalettesList.h"
#include "PalettesAction.h"
#include "PalettesActionRunner.h"
#include "EffectDefinitionDetail.h"
#include "EffectDefinitionGlints.h"
#include "EffectDefinitionTimers.h"

struct PalettesIndexPosition {
    const unsigned int curr;
    const unsigned int next;
};

unsigned int               getLedPaletteListSize(const int adds = 0);

const PalettesAction*      getLedPaletteDeft();
const PalettesAction*      getLedPaletteItem(const unsigned int idx);
const PalettesAction*      getLedPaletteItem();

const EffectDefinitionDetail* getLedPaletteItemActionDetail(const unsigned int idx);
const EffectDefinitionDetail* getLedPaletteItemActionDetail();
const ActionRunnerPalette*    getLedPaletteItemActionRunner(const unsigned int idx);
const ActionRunnerPalette*    getLedPaletteItemActionRunner();
const EffectDefinitionTimers* getLedPaletteItemActionTimers(const unsigned int idx);
const EffectDefinitionTimers* getLedPaletteItemActionTimers();
const EffectDefinitionGlints* getLedPaletteItemActionGlints(const unsigned int idx);
const EffectDefinitionGlints* getLedPaletteItemActionGlints();

String        getLedPaletteItemName(const unsigned int idx);
String        getLedPaletteItemName();
const char*   getLedPaletteItemNameC(const unsigned int idx);
const char*   getLedPaletteItemNameC();
const CRGBPalette16 getLedPaletteItemComp(const unsigned int idx);
const CRGBPalette16 getLedPaletteItemComp();
unsigned int  getLedPaletteItemCallExecSecs();

unsigned int          getLedPaletteListRandIndx();
unsigned int          getLedPaletteListRandIndxSeql();
unsigned int          getLedPaletteListStepInit();
unsigned int          getLedPaletteListStepNext(unsigned int idx);
PalettesIndexPosition getLedPaletteListStepIndx(bool inc = false);
unsigned int          incLedPaletteListStepIndx();
unsigned int          getLedPaletteListStepNumb();

bool isLedPaletteStepNamed();
bool isLedPaletteStepStarted();
bool isLedPaletteStepRunning();

void incPalettesStep();
