
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

void outSysSetup(const unsigned long baud)
{
    Serial.begin(baud);

    while(!Serial) {
        // wait for serial to become available
    }

    Serial.println();
}

void outStepInfo(const bool skip, const byte perc)
{
    Serial.println(
        getStepInfoMain() +
        getStepInfoMore() +
        getStepInfoSkip(skip, perc)
    );
}

String getStepInfoMain()
{
    static const String outsFormat = F("Selected pattern %02u of %02u (%s mode): %s (%03lus / %03lums / %03lums / %03lums / %03u%%)");
    static const byte   outsBufLen = outsFormat.length() + getLedPatternListNamesMaxLength();
    char                outsBufOut[outsBufLen];

    snprintf(
        outsBufOut,
        outsBufLen,
        outsFormat.c_str(),
        getLedPatternListStepNumb(),
        getLedPatternListSize(),
        getItemsPlacementDesc(LED_PTN_STEP_RAND),
        strPadsCharRgt(strQuote(getLedPatternItemName()), getLedPatternListNamesMaxLength()).c_str(),
        miliToSeconds(getLedPatternItemCallExecMili()),
        getLedPatternItemRandHuesMili(),
        getLedPatternItemWaitLoopMili(),
        getLedPatternItemWaitFadeMili(),
        cstrPerc(getLedPatternItemSkipItemFrac())
    );

    return String(outsBufOut);
}

String getStepInfoMore()
{
    String info = "";

    if (isLedPaletteStepRunning()) {
        info = info + getStepInfoMorePalette();
    }

    return info.length() > 0 ? strPadsCharLft(info, -1) : info;
}

String getStepInfoMorePalette()
{
    static const String moreFormat = F("| Palette %03u of %03u (%s mode): %s (%03lus)");
    static const byte   moreLength = moreFormat.length() + getLedPaletteListNamesMaxLength();
    char                moreBuffer[moreLength];

    snprintf(
        moreBuffer,
        moreLength,
        moreFormat.c_str(),
        getLedPaletteListStepNumb(),
        getLedPaletteListSize(),
        getItemsPlacementDesc(LED_PTN_CPAL_RAND),
        strPadsCharRgt(
            strQuote(getLedPaletteItemName()),
            getLedPaletteListNamesMaxLength()
        ).c_str(),
        miliToSeconds(LED_STR_PAL_CYCLE)
    );

    return String(moreBuffer);
}

String getStepInfoSkip(const bool skip, const byte perc)
{
    if (false == skip) {
        return String();
    }

    static const String skipFormat = F("| Skipped (%03u%% <= %03u%%)");
    static const byte   skipBufLen = skipFormat.length();
    char                skipBufOut[skipBufLen];

    snprintf(
        skipBufOut,
        skipBufLen,
        skipFormat.c_str(),
        cstrPerc(perc),
        cstrPerc(getLedPatternItemSkipItemFrac())
    );

    return strPadsCharLft(String(skipBufOut), -1);
}

char* getItemsPlacementDesc(bool random)
{
    static char typeRand[] = "random";
    static char typeOrdr[] = "ordered";

    return random ? typeRand : typeOrdr;
}

byte getLedPatternListNamesMaxLength(const byte a)
{
    static byte length = ([a]() -> byte {
        byte l = 0;

        for (unsigned int i = 0; i < getLedPatternListSize(); i++) {
            l = max(l, getLedPatternItemName(i).length());
        }

        return l + a;
    })();

    return length;
}

byte getLedPaletteListNamesMaxLength(const byte a)
{
    static byte length = ([a]() -> byte {
        byte l = 0;

        for (unsigned int i = 0; i < getLedPaletteListSize(); i++) {
            l = max(l, getLedPaletteItemName(i).length());
        }

        return l + a;
    })();

    return length;
}
