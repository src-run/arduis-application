
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Utilities.h"

void setupSystem()
{
    pinMode(LED_BUILTIN, PIN_MODE_OUTPUT);
    digitalWrite(LED_BUILTIN, SYS_OB_LED_ENBL ? HIGH : LOW);
}

void setupWiring()
{
    Wire.setClock(400000);
}

void delayForever(bool writeSerialMessage)
{
    if (writeSerialMessage) {
        Serial.println(F("!!! Halting execution (entering infinite loop) ..."));
    }

    while(true) {
        delay(1);
    }
}

void writeI2cDevFailureAndDelayForever(String device, byte address)
{
    const String format { F("!!! %s - Could not connect to i2c device at address \"%04X\" ...") };
    char         buffer [ format.length() + device.length() - 4 + 4 + 1 ];

    sprintf(
        buffer,
        format.c_str(),
        device.c_str(),
        address
    );

    Serial.println(buffer);

    delayForever(true);
}

String strPadsChar(const String value, const int padding, const String useChar, const StringPadDirection useSide)
{
    const unsigned int valSize { value.length() };
    const unsigned int padSize { padding < 0 ? abs(padding) : max(0, padding - valSize) };
    String             valRetn { };

    for (unsigned int i = 0; lt(i, padSize); i = i + useChar.length()) {
        valRetn = valRetn + useChar;
    }

    switch (useSide) {
        case StringPadDirection::lft:
            return valRetn + value;

        case StringPadDirection::rgt:
            return value + valRetn;

        case StringPadDirection::eql:
        default:
            return strPadsChar(
                strPadsChar(
                    value,
                    ceil(padding / 2),
                    useChar,
                    StringPadDirection::rgt
                ),
                floor(padding / 2),
                useChar,
                StringPadDirection::lft
            );
    }
}
