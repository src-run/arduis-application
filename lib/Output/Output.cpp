
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

void setupOutput(const unsigned long baud)
{
    Serial.begin(baud);

    while(!Serial) {
        delay(1);
    }

    delay(2000);
}

void outStepInfo(const bool skipped, const byte chances)
{
    Serial.print(F("--> "));
    Serial.print(getStepInfoMain());
    Serial.print(getStepInfoMore());
    Serial.print(getStepInfoSkip(skipped, chances));
    Serial.println();
    Serial.flush();
}

String getStepInfoMain()
{
    const String       outsFormat { F("Pattern %02u of %02u (mode %s/%s/%s/%s): [%02u] => %s (%04us / %03ums)") };
    char               outsBuffer [ outsFormat.length() + getLedPatternListNamesMaxLength()
        - 4 + 2 // %02u
        - 4 + 2 // %02u
        - 2 + 1 // %s
        - 2 + 1 // %s
        - 2 + 1 // %s
        - 2 + 1 // %s
        - 4 + 2 // %02u
        - 2     // %s
        - 4 + 4 // %04u
        - 4 + 3 // %03u
        + 1     // terminator
    ];

    sprintf(
        outsBuffer,
        outsFormat.c_str(),
        getLedPatternListStepNumbReal(),
        getLedPatternListSize(),
        getItemsPlacementDesc(LED_PTN_RAND_INIT).c_str(),
        getItemsPlacementDesc(LED_PTN_RAND_NEXT).c_str(),
        getItemsPlacementDesc(LED_PTN_RAND_NEXT && LED_PTN_RAND_SEQL == false).c_str(),
        getItemsGlintModeDesc(EffectGlints.isEnabled()).c_str(),
        getLedPatternListStepNumb(),
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

#if OUT_COUNTS_STAT
    moreString += strPadsCharLft(getStepInfoMoreCounter(), -1);
#endif

    if (isLedPaletteStepRunning()) {
        moreString += strPadsCharLft(getStepInfoMorePalette(), -1);
    }

    return moreString;
}

String getStepInfoMorePalette()
{
    const String moreFormat { F("| Palette %02u of %02u (mode %s/%s/%s): [%02u] => %s (%03us / %01ux)") };
    char         moreBuffer [ moreFormat.length() + getLedPaletteListNamesMaxLength()
        - 4 + 2 // %02u
        - 4 + 2 // %02u
        - 2 + 1 // %s
        - 2 + 1 // %s
        - 2 + 1 // %s
        - 4 + 2 // %02u
        - 2 + 2 // %s + "quotes"
        - 4 + 3 // %03u
        - 4 + 1 // %01u
        + 1     // terminator
    ];

    sprintf(
        moreBuffer,
        moreFormat.c_str(),
        getLedPaletteListStepNumbReal(),
        getLedPaletteListSize(),
        getItemsPlacementDesc(LED_PAL_RAND_INIT).c_str(),
        getItemsPlacementDesc(LED_PAL_RAND_NEXT).c_str(),
        getItemsPlacementDesc(LED_PAL_RAND_NEXT && LED_PAL_RAND_SEQL == false).c_str(),
        getLedPaletteListStepNumb(),
        strPadsCharRgt(
            strQuote(getLedPaletteItemName()),
            getLedPaletteListNamesMaxLength()
        ).c_str(),
        getLedPaletteItemCallExecSecs(),
        EffectFactor.resolve()
    );

    return String(moreBuffer);
}

String getStepInfoMoreCounter()
{
#if OUT_COUNTS_STAT
    const unsigned int count { CycleCount.getCount() };

    CycleCount.reset();

    if (count <= 10) {
        return F("| PT: NULL ");
    }

    const String moreFormat { F("| PT: %05u") };
    char         moreBuffer [ moreFormat.length() - 4 + 5 + 1 ];

    sprintf(
        moreBuffer,
        moreFormat.c_str(),
        count
    );

    return String(moreBuffer);
#endif
}

String getStepInfoSkip(const bool skipped, const byte chances)
{
    const String skipFormat { F("| Skipped (%03u%% >= %03u%%)") };
    char         skipBuffer [ skipFormat.length() - 4 + 3 - 2 + 1 - 4 + 3 - 2 + 1 + 1 ];

    sprintf(
        skipBuffer,
        skipFormat.c_str(),
        cstrPerc(getLedPatternItemActionDetail()->skipChance),
        cstrPerc(chances)
    );

    return skipped ? strPadsCharLft(String(skipBuffer), -1) : "";
}

byte getListNamesMaxLength(const byte add, unsigned int (*getListSize)(), const char* (*getItemName)(const unsigned int))
{
    byte len { 0 };

    for (unsigned int i = 0; i < getListSize(); i++) {
        len = maxInt(len, strlen(getItemName(i)));
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
#if OUT_MINPWR_STAT
    const String       ampsFormat { F("%.02f") };
    const unsigned int ampsLength { String(LED_PWR_MAX_MAMPS / 1000U).length() + 3 };
    char               ampsBuffer [ ampsLength + 1 ];

    sprintf(
        ampsBuffer,
        ampsFormat.c_str(),
        maximumBrightness.inputA
    );

    const String outsFormat { F("### FastLED driving %03u pixels available brightness percentage of target with %01uV @ %sA: %3u%% / %3u%% (%03u / %03u / 255)") };
    char         outsBuffer[outsFormat.length() + ampsLength];

    sprintf(
        outsBuffer,
        outsFormat.c_str(),
        maximumBrightness.pixels,
        maximumBrightness.inputV,
        strPadsCharLft(ampsBuffer, ampsLength, F("0")).c_str(),
        maximumBrightness.levelMaximum * 100 / maximumBrightness.levelRequest,
        byteToPerc(maximumBrightness.levelMaximum),
        maximumBrightness.levelMaximum,
        maximumBrightness.levelRequest
    );

    Serial.println(outsBuffer);
#endif
}

void outI2CFoundInfo(const I2CDeviceInfo& deviceInfo)
{
#if SYS_WIRE_D_STAT
    const String outsDevStr { SYS_WIRE_D_VERB ? getI2CFoundDesc(deviceInfo) : F("") };
    const String outsFormat { F("### I2C:%d - Device found : 0x%02X%s%s") };
    char         outsBuffer[outsFormat.length() + outsDevStr.length() + 9 + 1];

    sprintf(
        outsBuffer,
        outsFormat.c_str(),
        deviceInfo.i,
        deviceInfo.address,
        outsDevStr.c_str(),
        getItemsAvailModeDesc(deviceInfo.endCode == 0, F(""), F(" (FAILURE)"), false).c_str()
    );

    Serial.println(outsBuffer);
#endif
}

void outLoopTimeInfo(const LoopTimeResult& result)
{
    /*
    const String format { F("--- Primary loop stats: { \"avg-time\": %.02f, \"min-time\": %2u, \"max-time\": %2u, \"std-deviation\": %.04f, \"std-error\": %.04f, \"samples\": \"%03d/%03d\", \"sample-freq\": \"%02d\" }") };
    char         buffer [ format.length()
        - 5 + intLen(result.average, 2)      // %.02f
        - 3 + intLen(result.minimum)         // %2u
        - 3 + intLen(result.maximum)         // %2u
        - 5 + intLen(result.stdDeviation, 4) // %.04f
        - 5 + intLen(result.stdError, 4)     // %.04f
        - 4 + intLen(result.sampleCount)     // %03d
        - 4 + intLen(result.sampleAvail)     // %03d
        - 4 + intLen(result.sampleFrequency) // %02d
        + 1                                  // terminator
    ];
    */
    const String format { F("--- Looping average: %.02fms (with a %2ums minimum and %2ums maximum) [std deviation: %.04f, std error: %.04f, samples: %03d/%03d/%02d]") };
    char         buffer [ format.length()
        - 5 + intLen(result.average, 2)      // %.02f
        - 3 + intLen(result.minimum)         // %2u
        - 3 + intLen(result.maximum)         // %2u
        - 5 + intLen(result.stdDeviation, 4) // %.04f
        - 5 + intLen(result.stdError, 4)     // %.04f
        - 4 + intLen(result.sampleCount)     // %03d
        - 4 + intLen(result.sampleAvail)     // %03d
        - 4 + intLen(result.sampleFrequency) // %02d
        + 1                                  // terminator
    ];

    sprintf(
        buffer,
        format.c_str(),
        result.average,
        result.minimum,
        result.maximum,
        result.stdDeviation,
        result.stdError,
        result.sampleCount,
        result.sampleAvail,
        result.sampleFrequency
    );

    Serial.println(buffer);
}
