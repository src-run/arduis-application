
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

struct ledPaletteIndex {
    const unsigned int curr;
    const unsigned int next;
};

struct customPaletteItem {
    byte                             posn;
    const char                      *name;
    TProgmemRGBGradientPalette_byte *comp;
    unsigned long                    callExecMili;
};

extern customPaletteItem ledPaletteList[];

unsigned int             getLedPaletteListSize(const int adds = 0);

const customPaletteItem *getLedPaletteItem(const unsigned int idx);
const customPaletteItem *getLedPaletteItem();

byte                     getLedPaletteItemPosn(const unsigned int idx);
byte                     getLedPaletteItemPosn();
String                   getLedPaletteItemName(const unsigned int idx);
String                   getLedPaletteItemName();
CRGBPalette16            getLedPaletteItemComp();
unsigned long            getLedPaletteItemCallExecMili();

unsigned int             getLedPaletteListRandIndx();
unsigned int             getLedPaletteListRandIndxSeql();
unsigned int             getLedPaletteListStepInit();
unsigned int             getLedPaletteListStepNext(unsigned int idx);
ledPaletteIndex          getLedPaletteListStepIndx(bool inc = false);
unsigned int             incLedPaletteListStepIndx();
unsigned int             getLedPaletteListStepNumb();

bool                     isLedPaletteStepStarted();
bool                     isLedPaletteStepRunning();

void                     incPalettesStep();
