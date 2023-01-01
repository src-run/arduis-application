
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

uint8_t getLedPatternListMaxNameLen()
{
    static uint8_t length = 0;

    if (0 == length) {
        for (unsigned int i = 0; i < ledPatternSize; i++) {
            length = max(length, String(ledPatternList[i].name).length());
        }
    }

    return length;
}

uint8_t getLedPaletteListMaxNameLen()
{
    static uint8_t length = 0;

    if (0 == length) {
        for (unsigned int i = 0; i < ledPatternSize; i++) {
            length = max(length, String(ledPatternList[i].name).length());
        }
    }

    return length;
}

void outStepInfo()
{
    if (ledPatternListMaxNameLen == 0) {
        for (uint16_t i = 0; i < ledPatternSize; i++) {
            ledPatternListMaxNameLen = String(ledPatternList[i].name).length() > ledPatternListMaxNameLen
                ? String(ledPatternList[i].name).length()
                : ledPatternListMaxNameLen;
        }

        ledPatternListMaxNameLen += 2;
    }

    String outsFormat = "Selected pattern %02d of %02d: %-" + String(ledPatternListMaxNameLen) + "s (%03lus / %03lums / %03lums / %03lums)";
    char   outsBuffer[outsFormat.length() + ledPatternListMaxNameLen];

    snprintf(
        outsBuffer,
        outsFormat.length() + ledPatternListMaxNameLen,
        outsFormat.c_str(),
        ledPatternCallRefIndex + 1,
        ledPatternSize,
        String('"' + String(ledPatternList[ledPatternCallRefIndex].name) + '"').c_str(),
        ledPatternList[ledPatternCallRefIndex].callExecMili / 1000,
        ledPatternList[ledPatternCallRefIndex].randHuesMili,
        ledPatternList[ledPatternCallRefIndex].waitLoopMili,
        ledPatternList[ledPatternCallRefIndex].waitFadeMili
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
            ledPaletteArrayIndex,
            ledPaletteSize
        );

        return String(outsBuffer) + getLedPaletteName() + String("(") + String(LED_STR_PAL_CYCLE / 1000) + String(")");
    }

    return String("");
}

uint8_t ledPatternListMaxNameLen = 0;
uint8_t ledPaletteListMaxNameLen = 0;
