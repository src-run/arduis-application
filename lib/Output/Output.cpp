
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Output.h"

uint8_t getLedChainListMaxNameLen()
{
    static uint8_t length = 0;

    if (0 == length) {
        for (auto i = 0; i < ledChainSize; i++) {
            length = max(length, String(ledChainList[i].name).length());
        }
    }

    return length;
}

uint8_t getCPaletteListMaxNameLen()
{
    static uint8_t length = 0;

    if (0 == length) {
        for (auto i = 0; i < ledChainSize; i++) {
            length = max(length, String(ledChainList[i].name).length());
        }
    }

    return length;
}

void outStepInfo()
{
    if (ledChainListMaxNameLen == 0) {
        for (uint16_t i = 0; i < ledChainSize; i++) {
            ledChainListMaxNameLen = String(ledChainList[i].name).length() > ledChainListMaxNameLen
                ? String(ledChainList[i].name).length()
                : ledChainListMaxNameLen;
        }

        ledChainListMaxNameLen += 2;
    }

    String outsFormat = "Selected pattern %02d of %02d: %-" + String(ledChainListMaxNameLen) + "s (%03lus / %03lums / %03lums / %03lums)";
    char   outsBuffer[outsFormat.length() + ledChainListMaxNameLen];

    snprintf(
        outsBuffer,
        outsFormat.length() + ledChainListMaxNameLen,
        outsFormat.c_str(),
        ledChainCallRefIndex + 1,
        ledChainSize,
        String('"' + String(ledChainList[ledChainCallRefIndex].name) + '"').c_str(),
        ledChainList[ledChainCallRefIndex].callExecMili / 1000,
        ledChainList[ledChainCallRefIndex].randHuesMili,
        ledChainList[ledChainCallRefIndex].waitLoopMili,
        ledChainList[ledChainCallRefIndex].waitFadeMili
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
    if (isCPaletteStepRunning()) {
        String outsFormat = "%03d/%03d:";
        char   outsBuffer[outsFormat.length()];

        sprintf(
            outsBuffer,
            outsFormat.c_str(),
            ledPaletteArrayIndex,
            cPaletteSize
        );

        return String(outsBuffer) + getCPaletteName() + String("(") + String(LED_STR_PAL_CYCLE / 1000) + String(")");
    }

    return String("");
}

uint8_t ledChainListMaxNameLen = 0;
uint8_t cPaletteListMaxNameLen = 0;
