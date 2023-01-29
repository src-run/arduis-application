
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
    SYS_WIRE_OBJECT.begin();
    delay(500);

    if (SYS_WIRE_D_STAT) {
        writeScannedI2C();
    }
}

void writeScannedI2C()
{
    byte counter { 1 };

    for(byte address = 1; address < 127; address++) {
        const I2CDeviceInfo device {
            counter,
            address,
            ([](byte address) -> byte {
                SYS_WIRE_OBJECT.beginTransmission(address);
                return SYS_WIRE_OBJECT.endTransmission();
            })(address),
        };

        if (device.endCode == 0 || device.endCode == 4) {
            outI2CFoundInfo(device);
            ++counter;
        }
    }
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

String getCompilationDate()
{
    return F(__DATE__);
}

String getCompilationTime()
{
    return F(__TIME__);
}

DateTimeReading getCompilationDateTime()
{
    return DateTimeReading(DateTime(getCompilationDate().c_str(), getCompilationTime().c_str()));
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
