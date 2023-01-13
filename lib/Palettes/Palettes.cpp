
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Palettes.h"

unsigned int getLedPaletteListSize(const int adds)
{
    return paletteSizeItems + adds;
}

const PalettesAction* getLedPaletteDeft()
{
    return &paletteListDeflt;
}

const PalettesAction* getLedPaletteItem(const unsigned int idx)
{
    return idx >= getLedPaletteListSize() ? getLedPaletteDeft() : &paletteListItems[idx];
}

const PalettesAction* getLedPaletteItem()
{
    return getLedPaletteItem(getLedPaletteListStepIndx().curr);
}

const EffectDefinitionDetail* getLedPaletteItemActionDetail(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->detail);
}

const EffectDefinitionDetail* getLedPaletteItemActionDetail()
{
    return getLedPaletteItemActionDetail(getLedPaletteListStepIndx().curr);
}

const ActionRunnerPalette* getLedPaletteItemActionRunner(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->runner);
}

const ActionRunnerPalette* getLedPaletteItemActionRunner()
{
    return getLedPaletteItemActionRunner(getLedPaletteListStepIndx().curr);
}

const EffectDefinitionTimers* getLedPaletteItemActionTimers(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->timers);
}

const EffectDefinitionTimers* getLedPaletteItemActionTimers()
{
    return getLedPaletteItemActionTimers(getLedPaletteListStepIndx().curr);
}

const EffectDefinitionGlints* getLedPaletteItemActionGlints(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->glints);
}

const EffectDefinitionGlints* getLedPaletteItemActionGlints()
{
    return getLedPaletteItemActionGlints(getLedPaletteListStepIndx().curr);
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
    return getLedPaletteItemComp(getLedPaletteListStepIndx().curr);
}

unsigned int getLedPaletteItemCallExecSecs()
{
    return getLedPaletteItemActionTimers()->runningTotalSecs;
}

unsigned int getLedPaletteListRandIndxSeql()
{
    static bool         beg { false };
    static unsigned int len { getLedPaletteListSize() };
    static unsigned int pos { 0 };

    if (beg == false) {
        beg = true;

        for (unsigned int i = 0; i < len; i++) {
            paletteListOrder[i] = i;
        }
    }

    if (pos == 0) {
        pos = len;

        for (unsigned int j = 0; j < randUInt(LED_PAL_RAND_ENTR); j++) {
            for (unsigned int i = 0; i < len; i++) {
                const unsigned int n = randUInt(len - 1);
                const unsigned int v = paletteListOrder[n];
                paletteListOrder[n]  = paletteListOrder[i];
                paletteListOrder[i]  = v;
            }
        }
    }

    --pos;

    return paletteListOrder[constrain(pos, 0, len - 1)];
}

unsigned int getLedPaletteListRandIndx()
{
    return LED_PAL_RAND_SEQL ? getLedPaletteListRandIndxSeql() : getRandomIndx(getLedPaletteListSize());
}

unsigned int getLedPaletteListStepInit()
{
    return LED_PAL_RAND_INIT ? getLedPaletteListRandIndx() : 0;
}

unsigned int getLedPaletteListStepNext(unsigned int idx)
{
    return LED_PAL_RAND_NEXT ? getLedPaletteListRandIndx() : ((idx + 1) % getLedPaletteListSize());
}

PalettesIndexPosition getLedPaletteListStepIndx(bool inc)
{
    static unsigned int idxCurr { getLedPaletteListStepInit() };
    static unsigned int idxNext { getLedPaletteListStepNext(idxCurr) };
    static bool         running { false };

    if (running && inc) {
        idxCurr = idxNext;
        idxNext = getLedPaletteListStepNext(idxCurr);
    }

    running = true;

    return {
        idxCurr,
        idxNext,
    };
}

unsigned int incLedPaletteListStepIndx()
{
    return getLedPaletteListStepIndx(true).curr;
}

unsigned int getLedPaletteListStepNumb()
{
    return getLedPaletteListStepIndx().curr + 1;
}

bool isLedPaletteStepNamed()
{
    return isMatch(getLedPatternItemNameC(), "palette-circle")
        || isMatch(getLedPatternItemNameC(), "palette-circle-t");
}

bool isLedPaletteStepStarted()
{
    return (ledPatternStepInit || ledPatternStepRuns) && isLedPaletteStepNamed();
}

bool isLedPaletteStepRunning()
{
    return isLedPaletteStepStarted() && lt(
        getLedPaletteListStepIndx().curr,
        getLedPaletteListSize()
    );
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
