
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#ifndef _ARDUIS_HR_PALETTES
#define _ARDUIS_HR_PALETTES

#include <Arduino.h>
#include <FastLED.h>

#include <PalettesGradient.h>
#include <Output.h>
#include <Utilities.h>

typedef struct {
    const unsigned int curr;
    const unsigned int next;
} ledPaletteIndex;

typedef struct {
    const char                      *name;
    TProgmemRGBGradientPalette_byte *comp;
} customPaletteItem;

extern const customPaletteItem ledPaletteList[];

const unsigned int       getLedPaletteListSize();
const customPaletteItem *getLedPaletteItem(const unsigned int idx);
const customPaletteItem *getLedPaletteItem();
const String             getLedPaletteItemName(const unsigned int idx);
const String             getLedPaletteItemName();
CRGBPalette16            getLedPaletteItemComp();

unsigned int    getLedPaletteListRandIndx();
unsigned int    getLedPaletteListStepInit();
unsigned int    getLedPaletteListStepNext(unsigned int idx);
ledPaletteIndex getLedPaletteListStepIndx(bool inc = false);
unsigned int    incLedPaletteListStepIndx();
unsigned int    getLedPaletteListStepNumb();
bool            isLedPaletteStepStarted();
bool            isLedPaletteStepRunning();
void            incPalettesStep();

#endif
