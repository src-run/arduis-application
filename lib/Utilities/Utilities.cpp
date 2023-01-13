
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Utilities.h"

byte getPinMode(byte pin)
{
    const byte bit { digitalPinToBitMask(pin) };
    const byte prt { digitalPinToPort(pin) };

    if ((NOT_A_PORT == prt) || (NOT_A_PIN == pin) || (0 == bit) || (bit & (bit - 1))) {
        return PIN_MODE_UNKNOWN;
    }

    volatile byte *reg = portModeRegister(prt);

    if (*reg & bit) {
        return PIN_MODE_OUTPUT;
    }

    volatile byte *out = portOutputRegister(prt);

    if (*out & bit) {
        return PIN_MODE_INPUT_PULLUP;
    }

    return PIN_MODE_INPUT;
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
