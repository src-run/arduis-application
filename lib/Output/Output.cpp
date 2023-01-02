
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

void outSysSetup(unsigned long baud)
{
    Serial.begin(baud);
    while(!Serial);
    Serial.println();
}

const String getStepInfoSkip(bool skip)
{
    if (!skip) {
        return "";
    }

    const String skipFormat = "[Skipped due to %03i%% skip chance setting]";
    char         skipBuffer[skipFormat.length()];

    snprintf(
        skipBuffer,
        skipFormat.length(),
        skipFormat.c_str(),
        getLedPatternItem()->skipItemFrac * 100 / 255
    );

    return strPadsCharLft(String(skipBuffer), -1);
}

void outStepInfo(bool skip)
{
    Serial.println(
        getStepInfoMain() +
        getStepInfoMore() +
        getStepInfoSkip(skip)
    );
}

const String getStepInfoMain()
{
    static const byte   nameMaxLen = getLedPatternListNamesMaxLength() + 2;
    static const String outsFormat = "Selected pattern %02d of %02d (%s mode): %-" + String(nameMaxLen) + "s (%03lus / %03lums / %03lums / %03lums)";
    char                outsBuffer[outsFormat.length() + nameMaxLen];

    snprintf(
        outsBuffer,
        outsFormat.length() + nameMaxLen,
        outsFormat.c_str(),
        getLedPatternListStepNumb(),
        getLedPatternListSize(),
        LED_PTN_STEP_RAND ? "random" : "ordered",
        strQuote(getLedPatternItemName()).c_str(),
        getLedPatternItem()->callExecMili / 1000,
        getLedPatternItem()->randHuesMili,
        getLedPatternItem()->waitLoopMili,
        getLedPatternItem()->waitFadeMili
    );

    return String(outsBuffer);
}

const String getStepInfoMore()
{
    String info = "";

    if (isLedPaletteStepRunning()) {
        info = info + getStepInfoMorePalette();
    }

    if (info.length() > 0) {
        info = strPadsCharLft(info, -1);
    }

    return info;
}

const String getStepInfoMorePalette()
{
    const byte   nameMaxLen = getLedPaletteListNamesMaxLength() + 2;
    const String moreFormat = "[Palette %03d of %03d (%s mode): %-" + String(nameMaxLen) + "s]";
    char         moreBuffer[moreFormat.length() + nameMaxLen];

    snprintf(
        moreBuffer,
        moreFormat.length() + nameMaxLen,
        moreFormat.c_str(),
        getLedPaletteListStepNumb(),
        getLedPaletteListSize(),
        LED_PTN_CPAL_RAND ? "random" : "ordered",
        strQuote(getLedPaletteItemName()).c_str()
    );

    return moreBuffer;
}

const byte getLedPatternListNamesMaxLength()
{
    static byte length = ([]() -> byte {
        for (unsigned int i = 0; i < getLedPatternListSize(); i++) {
            length = max(length, getLedPatternItemName(i).length());
        }

        return length;
    })();

    return length;
}

const byte getLedPaletteListNamesMaxLength()
{
    static byte length = ([]() -> byte {
        for (unsigned int i = 0; i < getLedPaletteListSize(); i++) {
            length = max(length, getLedPaletteItemName(i).length());
        }

        return length;
    })();

    return length;
}
