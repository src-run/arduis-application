
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Palettes.h"

unsigned int getLedPaletteListSize()
{
    return paletteSizeItems;
}

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

unsigned int getLedPaletteItemRandHuesMili()
{
    return getLedPaletteItemActionTimers()->iterateMilliSecs;
}

unsigned int getLedPaletteListRandIndxSeql(bool internalIndex)
{
    static bool paletteListOrderFirst { true };
    static byte paletteListOrderIndex { 0 };

    if (internalIndex) {
        return 0 == paletteListOrderIndex && paletteListOrderFirst
            ? 1
            : getLedPaletteListSize() - paletteListOrderIndex;
    }

    if (paletteListOrderIndex == 0) {
        paletteListOrderIndex = getLedPaletteListSize();

        for (byte i = 0; i < paletteListOrderIndex; i++) {
            paletteListOrder[i] = i;
        }

        for (byte j = 0; j < randByte(1, max(2, LED_PAL_RAND_ENTR)); j++) {
            for (byte i = 0; i < paletteListOrderIndex; i++) {
                const byte n { randByte(paletteListOrderIndex - 1) };
                const byte v { paletteListOrder[n] };

                paletteListOrder[n] = paletteListOrder[i];
                paletteListOrder[i] = v;
            }
        }

        if (paletteListOrderFirst && !LED_PAL_RAND_INIT) {
            for (byte i = 0; i < paletteListOrderIndex; i++) {
                if (0 == paletteListOrder[i]) {
                    paletteListOrder[i] = paletteListOrder[paletteListOrderIndex - 1];
                    paletteListOrder[paletteListOrderIndex - 1] = 0;

                    break;
                }
            }

            --paletteListOrderIndex;
        }

        paletteListOrderFirst = false;
    }

    --paletteListOrderIndex;

    return paletteListOrder[constrain(paletteListOrderIndex, 0, getLedPaletteListSize() - 1)];
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

unsigned int getLedPaletteListStepNumbReal()
{
    return LED_PAL_RAND_INIT || LED_PAL_RAND_SEQL
        ? getLedPaletteListRandIndxSeql(true)
        : getLedPaletteListStepNumb();
}

bool isLedPaletteStepNamed()
{
    return isMatch(getLedPatternItemNameC(), "palette-circle")
        || isMatch(getLedPatternItemNameC(), "palette-circle-t");
}

bool isLedPaletteStepStarted()
{
    return EffectStatus.isRunning() && isLedPaletteStepNamed();
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
        EffectFactor.refresh();
        EffectGlints.setChance(getLedPaletteItemActionGlints()->chances);
    }

    if (isLedPaletteStepRunning()) {
        outStepInfo();
    }
}
