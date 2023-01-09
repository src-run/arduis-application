
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
#include "PalettesGradient.h"

struct ledPaletteIndx {
    const unsigned int curr;
    const unsigned int next;
};

struct ledPaletteItem {
    const char                            *name;
    const TProgmemRGBGradientPalette_byte *comp;
    const unsigned int                     callExecSecs;
    const byte                             glintsChance;
    const byte                             rejectChance;
};

extern const ledPaletteItem ledPaletteList[];
extern byte                 ledPaletteSeql[];
extern const ledPaletteItem ledPaletteDeft;

unsigned int             getLedPaletteListSize(const int adds = 0);

const ledPaletteItem    *getLedPaletteDeft();
const ledPaletteItem    *getLedPaletteItem(const unsigned int idx);
const ledPaletteItem    *getLedPaletteItem();

String                   getLedPaletteItemName(const unsigned int idx);
String                   getLedPaletteItemName();
const char              *getLedPaletteItemNameC(const unsigned int idx);
const char              *getLedPaletteItemNameC();
CRGBPalette16            getLedPaletteItemComp(const unsigned int idx);
CRGBPalette16            getLedPaletteItemComp();
unsigned int             getLedPaletteItemCallExecSecs();
unsigned int             getLedPaletteItemGlintsChance();
unsigned int             getLedPaletteItemRejectChance();

unsigned int             getLedPaletteListRandIndx();
unsigned int             getLedPaletteListRandIndxSeql();
unsigned int             getLedPaletteListStepInit();
unsigned int             getLedPaletteListStepNext(unsigned int idx);
ledPaletteIndx           getLedPaletteListStepIndx(bool inc = false);
unsigned int             incLedPaletteListStepIndx();
unsigned int             getLedPaletteListStepNumb();

bool                     isLedPaletteStepStarted();
bool                     isLedPaletteStepRunning();

void                     incPalettesStep();
