
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

void outStepInfo(const bool skip, const fract8 perc)
{
    Serial.println(
        getStepInfoMain() +
        getStepInfoMore() +
        getStepInfoSkip(skip, perc)
    );
}

const String getStepInfoMain()
{
    static const String outsFormat = "Selected pattern %02d of %02d (%s mode): %-" + String(getLedPatternListNamesMaxLength()) + "s (%03ds / %03lums / %03lums / %03lums / %03i%%)";
    static const byte   outsBufLen = outsFormat.length() + getLedPatternListNamesMaxLength();
    char                outsBufOut[outsBufLen];

    snprintf(
        outsBufOut,
        outsBufLen,
        outsFormat.c_str(),
        getLedPatternListStepNumb(),
        getLedPatternListSize(),
        LED_PTN_STEP_RAND ? "random" : "ordered",
        strQuote(getLedPatternItemName()).c_str(),
        miliToSeconds(getLedPatternItem()->callExecMili),
        getLedPatternItem()->randHuesMili,
        getLedPatternItem()->waitLoopMili,
        getLedPatternItem()->waitFadeMili,
        fracToPercent(getLedPatternItem()->skipItemFrac)
    );

    return String(outsBufOut);
}

const String getStepInfoMore()
{
    String info = "";

    if (isLedPaletteStepRunning()) {
        info = info + getStepInfoMorePalette();
    }

    return info.length() > 0 ? strPadsCharLft(info, -1) : info;
}

const String getStepInfoMorePalette()
{
    static const String moreFormat = "| Palette %03d of %03d (%s mode): %-" + String(getLedPaletteListNamesMaxLength()) + "s (%03ds)";
    static const byte   moreBufLen = moreFormat.length() + getLedPaletteListNamesMaxLength();
    char                moreBufOut[moreBufLen];

    snprintf(
        moreBufOut,
        moreBufLen,
        moreFormat.c_str(),
        getLedPaletteListStepNumb(),
        getLedPaletteListSize(),
        LED_PTN_CPAL_RAND ? "random" : "ordered",
        strQuote(getLedPaletteItemName()).c_str(),
        miliToSeconds(LED_STR_PAL_CYCLE)
    );

    return String(moreBufOut);
}

const String getStepInfoSkip(const bool skip, const fract8 perc)
{
    if (false == skip) {
        return String();
    }

    static const String skipFormat = "| Skipped (%03d%% > %03d%% / %03i%% > %03i%% / %03d%% > %03d%% / %03i%% > %03i%% / %03d%% > %03d%% / %03i%% > %03i%%)";
    static const byte   skipBufLen = skipFormat.length();
    char                skipBufOut[skipBufLen];

    snprintf(
        skipBufOut,
        skipBufLen,
        skipFormat.c_str(),
        100 - fracToPercent(perc),
        fracToPercent(getLedPatternItem()->skipItemFrac),
        100 - fracToPercent(perc),
        fracToPercent(getLedPatternItem()->skipItemFrac),
        100 - (perc * 100 / 255),
        getLedPatternItem()->skipItemFrac * 100 / 255,
        100 - (perc * 100 / 255),
        getLedPatternItem()->skipItemFrac * 100 / 255,
        perc,
        getLedPatternItem()->skipItemFrac,
        perc,
        getLedPatternItem()->skipItemFrac
    );

    return strPadsCharLft(String(skipBufOut), -1);
}

const byte getLedPatternListNamesMaxLength(const byte a)
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

const byte getLedPaletteListNamesMaxLength(const byte a)
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
