
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

unsigned long loopIterationCount { 0 };
unsigned long loopIterationTimes { 0 };

void setupSerial(const unsigned long baud)
{
    Serial.begin(baud);
    while(!Serial);
    Serial.println();
}

void outStepInfo(const bool skipped, const byte chances)
{
    Serial.print(getStepInfoMain());
    Serial.print(getStepInfoMore());
    Serial.print(getStepInfoSkip(skipped, chances));
    Serial.println();
}

String getStepInfoMain()
{
    const String       outsFormat { F("Pattern %02u of %02u (mode %s/%s/%s/%s): %s (%04us / %03ums)") };
    const unsigned int outsLength { outsFormat.length() + getLedPatternListNamesMaxLength() };
    char               outsBuffer[outsLength];

    snprintf(
        outsBuffer,
        outsLength,
        outsFormat.c_str(),
        getLedPatternListStepNumb(),
        getLedPatternListSize(),
        getItemsPlacementDesc(LED_PTN_RAND_INIT),
        getItemsPlacementDesc(LED_PTN_RAND_NEXT),
        getItemsPlacementDesc(LED_PTN_RAND_NEXT && LED_PTN_RAND_SEQL == false),
        getEffectAddonGlintsState() ? "g" : "n",
        strPadsCharRgt(
            strQuote(getLedPatternItemName()),
            getLedPatternListNamesMaxLength()
        ).c_str(),
        getLedPatternItemCallExecSecs(),
        getLedPatternItemRandHuesMili()
    );

    return String(outsBuffer);
}

String getStepInfoMore()
{
    String more = "";

    if (OUT_COUNTS_STAT) {
        more += strPadsCharLft(getStepInfoMoreLooping(), -1);
    }

    if (isLedPaletteStepRunning()) {
        more += strPadsCharLft(getStepInfoMorePalette(), -1);
    }

    return more;
}

String getStepInfoMorePalette()
{
    const String       moreFormat { F("| Palette %03u of %03u (mode %s/%s/%s): %s (%03us)") };
    const unsigned int moreLength { moreFormat.length() + getLedPaletteListNamesMaxLength() };
    char               moreBuffer[moreLength];

    snprintf(
        moreBuffer,
        moreLength,
        moreFormat.c_str(),
        getLedPaletteListStepNumb(),
        getLedPaletteListSize(),
        getItemsPlacementDesc(LED_PAL_RAND_INIT),
        getItemsPlacementDesc(LED_PAL_RAND_NEXT),
        getItemsPlacementDesc(LED_PAL_RAND_NEXT && LED_PAL_RAND_SEQL == false),
        strPadsCharRgt(
            strQuote(getLedPaletteItemName()),
            getLedPaletteListNamesMaxLength()
        ).c_str(),
        getLedPaletteItemCallExecSecs()
    );

    return String(moreBuffer);
}

String getStepInfoMoreLooping()
{
    const String       moreFormat { F("| Prior counter: %05lu") };
    const unsigned int moreLength { moreFormat.length() + 1 };
    char               moreBuffer[moreLength];

    snprintf(
        moreBuffer,
        moreLength,
        moreFormat.c_str(),
        loopIterationCount
    );

    loopIterationCount = 0;
    loopIterationTimes = 0;

    return String(moreBuffer);
}

String getStepInfoSkip(const bool skipped, const byte chances)
{
    const String       skipFormat { F("| Skipped (%03u%% >= %03u%%)") };
    const unsigned int skipLength { skipFormat.length() + 1 };
    char               skipBuffer[skipLength];

    snprintf(
        skipBuffer,
        skipLength,
        skipFormat.c_str(),
        cstrPerc(getLedPatternItemActionDetail()->skipChance),
        cstrPerc(chances)
    );

    return skipped ? strPadsCharLft(String(skipBuffer), -1) : "";
}

const char* getItemsPlacementDesc(bool random)
{
    const char* typeRandC { "r" };
    const char* typeOrdrC { "s" };
    const String typeRand { "r" };
    const String typeOrdr { "s" };

    return random ? typeRandC : typeOrdrC;
}

byte getListNamesMaxLength(const byte add, unsigned int (*getListSize)(const int), const char* (*getItemName)(const unsigned int))
{
    byte len { 0 };

    for (unsigned int i = 0; i < getListSize(0); i++) {
        len = max(len, strlen(getItemName(i)));
    }

    return len + add;
}

byte getLedPatternListNamesMaxLength(const byte add)
{
    return getListNamesMaxLength(
        add,
        &getLedPatternListSize,
        &getLedPatternItemNameC
    );
}

byte getLedPaletteListNamesMaxLength(const byte add)
{
    return getListNamesMaxLength(
        add,
        &getLedPaletteListSize,
        &getLedPaletteItemNameC
    );
}

void incLoopIterationCount()
{
    if (loopIterationCount >= 4294967295) {
        loopIterationCount = 0;
        loopIterationTimes++;
    }

    loopIterationCount++;
}
