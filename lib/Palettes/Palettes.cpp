
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
    static const PalettesAction itemDefault {
        { "Mysts_Bk_Wi", 0 },
        { Palette_Mysts_Bk_Wi_c },
        { LED_PAL_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL },
    };

    return &itemDefault;
}

const PalettesAction* getLedPaletteItem(const unsigned int idx)
{
    return idx >= getLedPaletteListSize() ? getLedPaletteDeft() : &paletteListItems[idx];
}

const PalettesAction* getLedPaletteItem()
{
    return getLedPaletteItem(getLedPaletteListStepIndx().curr);
}

const ActionDetail* getLedPaletteItemActionDetail(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->detail);
}

const ActionDetail* getLedPaletteItemActionDetail()
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

const ActionTimers* getLedPaletteItemActionTimers(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->timers);
}

const ActionTimers* getLedPaletteItemActionTimers()
{
    return getLedPaletteItemActionTimers(getLedPaletteListStepIndx().curr);
}

const ActionGlints* getLedPaletteItemActionGlints(const unsigned int idx)
{
    return &(getLedPaletteItem(idx)->glints);
}

const ActionGlints* getLedPaletteItemActionGlints()
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

CRGBPalette16 getLedPaletteItemComp(const unsigned int idx)
{
    CRGBPalette16 palette = getLedPaletteItemActionRunner(idx)->gradient;

    return palette;
}

CRGBPalette16 getLedPaletteItemComp()
{
    return getLedPaletteItemComp(getLedPaletteListStepIndx().curr);
}

unsigned int getLedPaletteItemCallExecSecs()
{
    return getLedPaletteItemActionTimers()->runningTotalSecs;
}

unsigned int getLedPaletteListRandIndx()
{
    return LED_PAL_RAND_SEQL ? getLedPaletteListRandIndxSeql() : getRandomIndx(getLedPaletteListSize());
}

unsigned int getLedPaletteListRandIndxSeql()
{
    static bool         beg = false;
    static unsigned int len = getLedPaletteListSize();
    static unsigned int pos = 0;

    if (beg == false) {
        beg = true;

        for (unsigned int i = 0; i < len; i++) {
            paletteListOrder[i] = i;
        }
    }

    if (pos == 0) {
        pos = len;

        for (byte j = 0; j < randByte(LED_PAL_RAND_ENTR); j++) {
            for (unsigned int i = 0; i < len; i++) {
                const unsigned int n = randUInt(len - 1);
                const byte         v = paletteListOrder[n];
                paletteListOrder[n]    = paletteListOrder[i];
                paletteListOrder[i]    = v;
            }
        }
    }

    --pos;

    return paletteListOrder[constrain(pos, 0, len - 1)];
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
    static unsigned int idxCurr = getLedPaletteListStepInit();
    static unsigned int idxNext = getLedPaletteListStepNext(idxCurr);
    static bool         beg = false;

    if (beg && inc) {
        idxCurr = idxNext;
        idxNext = getLedPaletteListStepNext(idxCurr);
    }

    beg = true;

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

bool isLedPaletteStepStarted()
{
    return (
        ledPatternStepInit ||
        ledPatternStepRuns
    ) && (
        isMatch(getLedPatternItemNameC(), "palette-circle") ||
        isMatch(getLedPatternItemNameC(), "palette-circle-t")
    );
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

    if (isLedPaletteStepRunning()) {
        setLedPatternItemGlintsState(getLedPaletteItemActionGlints()->chances);
        outStepInfo();
    }
}
