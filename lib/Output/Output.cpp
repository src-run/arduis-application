
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

void setupSerial(const unsigned long baud)
{
    Serial.begin(baud);
    while(!Serial);
}

void outStepInfo(const bool skipped, const byte chances)
{
    Serial.print(F("-> "));
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
    String moreString { };

    if (OUT_COUNTS_STAT) {
        moreString += strPadsCharLft(getStepInfoMoreCounter(), -1);
    }

    if (isLedPaletteStepRunning()) {
        moreString += strPadsCharLft(getStepInfoMorePalette(), -1);
    }

    return moreString;
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

String getStepInfoMoreCounter()
{
    const String       moreFormat { F("| Prior counter: %05lu") };
    const unsigned int moreLength { moreFormat.length() + 1 };
    char               moreBuffer[moreLength];

    snprintf(
        moreBuffer,
        moreLength,
        moreFormat.c_str(),
        CycleCount.getCount()
    );

    CycleCount.reset();

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
    static const char* typeRandC { "r" };
    static const char* typeOrdrC { "s" };

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

void outPwrLimitInfo(const PowerCalculatedBrightness& maximumBrightness)
{
    const String       ampsFormat { F("%.02f") };
    const unsigned int ampsLength { String(LED_PWR_MAX_MAMPS / 1000U).length() + 3 };
    const String       outsFormat { F("## FastLED driving %03u pixels available brightness percentage of target with %01uV @ %sA: %3u%% / %3u%% (%03u / %03u / 255)") };
    char               ampsBuffer[ampsLength + 1];
    char               outsBuffer[outsFormat.length() + ampsLength];

    sprintf(
        ampsBuffer,
        ampsFormat.c_str(),
        maximumBrightness.inputA
    );

    sprintf(
        outsBuffer,
        outsFormat.c_str(),
        maximumBrightness.pixels,
        maximumBrightness.inputV,
        strPadsCharLft(ampsBuffer, ampsLength, "0").c_str(),
        maximumBrightness.levelMaximum * 100 / maximumBrightness.levelRequest,
        byteToPerc(maximumBrightness.levelMaximum),
        maximumBrightness.levelMaximum,
        maximumBrightness.levelRequest
    );

    Serial.println(outsBuffer);
}
