
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

byte ledPatternListMaxNameLen = 0;
byte ledPaletteListMaxNameLen = 0;

byte getLedPatternListMaxNameLen()
{
    static byte length = 0;

    if (0 == length) {
        for (unsigned int i = 0; i < getLedPatternListSize(); i++) {
            length = max(length, String(ledPatternList[i].name).length());
        }
    }

    return length;
}

byte getLedPaletteListMaxNameLen()
{
    static byte length = 0;

    if (0 == length) {
        for (unsigned int i = 0; i < getLedPatternListSize(); i++) {
            length = max(length, String(ledPatternList[i].name).length());
        }
    }

    return length;
}

void outStepInfo()
{
    if (ledPatternListMaxNameLen == 0) {
        for (unsigned int i = 0; i < getLedPatternListSize(); i++) {
            ledPatternListMaxNameLen = String(ledPatternList[i].name).length() > ledPatternListMaxNameLen
                ? String(ledPatternList[i].name).length()
                : ledPatternListMaxNameLen;
        }

        ledPatternListMaxNameLen += 2;
    }

    const String outsFormat = "Selected pattern %02d of %02d: %-" + String(ledPatternListMaxNameLen) + "s (%03lus / %03lums / %03lums / %03lums)";
    char         outsBuffer[outsFormat.length() + ledPatternListMaxNameLen];

    snprintf(
        outsBuffer,
        outsFormat.length() + ledPatternListMaxNameLen,
        outsFormat.c_str(),
        getLedPatternListStepNumb(),
        getLedPatternListSize(),
        String('"' + String(getLedPatternItem().name) + '"').c_str(),
        getLedPatternItem().callExecMili / 1000,
        getLedPatternItem().randHuesMili,
        getLedPatternItem().waitLoopMili,
        getLedPatternItem().waitFadeMili
    );

    Serial.print(outsBuffer);

    String outsExtras = getStepInfoExtra();

    if (outsExtras.length() > 0) {
        Serial.print(" [");
        Serial.print(outsExtras);
        Serial.print("]");
    }

    Serial.println();
}

String getStepInfoExtra()
{
    if (isLedPaletteStepRunning()) {
        String outsFormat = "%03d/%03d:";
        char   outsBuffer[outsFormat.length()];

        sprintf(
            outsBuffer,
            outsFormat.c_str(),
            getLedPaletteListStepNumb(),
            getLedPaletteListSize()
        );

        return String(outsBuffer) + getLedPaletteStepName() + String("(") + String(LED_STR_PAL_CYCLE / 1000) + String(")");
    }

    return String("");
}
