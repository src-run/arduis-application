
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Palettes.h"

const PalettesAction* getLedPaletteDeft()
{
    return &paletteItemDeflt;
}

const PalettesAction* getLedPaletteItem(const unsigned int idx)
{
    return idx >= getLedPaletteListSize()
        ? getLedPaletteDeft()
        : &paletteListItems[idx];
}

const PalettesAction* getLedPaletteItem()
{
    return getLedPaletteItem(getLedPaletteListStepIndx());
}

const EffectDefinitionDetail* getLedPaletteItemActionDetail(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->detail);
}

const EffectDefinitionDetail* getLedPaletteItemActionDetail()
{
    return getLedPaletteItemActionDetail(getLedPaletteListStepIndx());
}

const ActionRunnerPalette* getLedPaletteItemActionRunner(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->runner);
}

const ActionRunnerPalette* getLedPaletteItemActionRunner()
{
    return getLedPaletteItemActionRunner(getLedPaletteListStepIndx());
}

const EffectDefinitionTimers* getLedPaletteItemActionTimers(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->timers);
}

const EffectDefinitionTimers* getLedPaletteItemActionTimers()
{
    return getLedPaletteItemActionTimers(getLedPaletteListStepIndx());
}

const EffectDefinitionGlints* getLedPaletteItemActionGlints(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->glints);
}

const EffectDefinitionGlints* getLedPaletteItemActionGlints()
{
    return getLedPaletteItemActionGlints(getLedPaletteListStepIndx());
}

String getLedPaletteItemName(const unsigned int idx)
{
    return getLedPaletteItemNameC(idx);
}

String getLedPaletteItemName()
{
    return getLedPaletteItemNameC();
}

const char *getLedPaletteItemNameC(const unsigned int idx)
{
    return getLedPaletteItemActionDetail(idx)->name;
}

const char *getLedPaletteItemNameC()
{
    return getLedPaletteItemActionDetail()->name;
}

const CRGBPalette16 getLedPaletteItemComp(const unsigned int idx)
{
    return getLedPaletteItemActionRunner(idx)->gradient;
}

const CRGBPalette16 getLedPaletteItemComp()
{
    return getLedPaletteItemComp(getLedPaletteListStepIndx());
}

unsigned int getLedPaletteItemCallExecSecs()
{
    return getLedPaletteItemActionTimers()->runningTotalSecs;
}

unsigned int getLedPaletteListRandIndxSeql()
{
    static byte paletteListOrderIndex { 0 };

    if (paletteListOrderIndex == 0) {
        paletteListOrderIndex = getLedPaletteListSize();

        for (byte i = 0; i < paletteListOrderIndex; i++) {
            paletteListOrder[i] = i;
        }

        for (byte j = 0; j < randByte(LED_PAL_RAND_ENTR); j++) {
            for (byte i = 0; i < paletteListOrderIndex; i++) {
                const byte n = randByte(paletteListOrderIndex - 1);
                const byte v = paletteListOrder[n];
                paletteListOrder[n] = paletteListOrder[i];
                paletteListOrder[i] = v;
            }
        }
    }

    --paletteListOrderIndex;

    return paletteListOrder[paletteListOrderIndex];
}

unsigned int getLedPaletteListRandIndx()
{
    return LED_PAL_RAND_SEQL
        ? getLedPaletteListRandIndxSeql()
        : getRandomIndx(getLedPaletteListSize());
}

unsigned int getLedPaletteListStepInit()
{
    return LED_PAL_RAND_INIT
        ? getLedPaletteListRandIndx()
        : 0;
}

unsigned int getLedPaletteListStepNext(unsigned int idx)
{
    return LED_PAL_RAND_NEXT
        ? getLedPaletteListRandIndx()
        : ((idx + 1) % getLedPaletteListSize());
}

unsigned int getLedPaletteListStepIndx(bool indexIncr)
{
    static unsigned int indexCurr { getLedPaletteListStepInit() };
    static bool         isRunning { false };

    if (isRunning && indexIncr) {
        indexCurr = getLedPaletteListStepNext(indexCurr);
    }

    isRunning = true;

    return indexCurr;
}

unsigned int incLedPaletteListStepIndx()
{
    return getLedPaletteListStepIndx(true);
}

unsigned int getLedPaletteListStepNumb()
{
    return getLedPaletteListStepIndx() + 1;
}

bool isLedPaletteStepNamed()
{
    return isMatch(getLedPatternItemNameC(), "palette-circle")
        || isMatch(getLedPatternItemNameC(), "palette-circle-t");
}

bool isLedPaletteStepStarted()
{
    return (ledPatternStepInit || ledPatternStepRuns)
        && isLedPaletteStepNamed();
}

bool isLedPaletteStepRunning()
{
    return isLedPaletteStepStarted()
        && lt(getLedPaletteListStepIndx(), getLedPaletteListSize());
}

void incPalettesStep()
{
    incLedPaletteListStepIndx();

    if (isLedPaletteStepStarted()) {
        setEffectAddonGlintsState(getLedPaletteItemActionGlints()->chances);
    }

    if (isLedPaletteStepRunning()) {
        outStepInfo();
    }
}
