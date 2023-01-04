
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Utilities.h"

byte cstrByte(const long i)
{
    return constrain(i, 0, 255);
}

unsigned int cstrUInt(const long i)
{
    return constrain(i, 0, 65535);
}

byte randByte(byte min, byte lim)
{
    addRandomEntrEveryNCalls();

    return random8(min, lim);
}

byte randByte(byte lim)
{
    addRandomEntrEveryNCalls();

    return randByte(0, lim);
}

byte randByte()
{
    addRandomEntrEveryNCalls();

    return randByte(0, 255);
}

unsigned int randUInt(unsigned int min, unsigned int lim)
{
    addRandomEntrEveryNCalls();

    return random16(min, lim);
}

unsigned int randUInt(unsigned int lim)
{
    addRandomEntrEveryNCalls();

    return randUInt(0, lim);
}

unsigned int randUInt()
{
    addRandomEntrEveryNCalls();

    return randUInt(0, 65535);
}

unsigned int getRandomSeed()
{
    return random16_get_seed();
}

unsigned int setRandomEntr(byte min, byte max)
{
    random16_set_seed(analogRead(LED_BUILTIN) * random8(100));

    return addRandomEntr(max);
}

unsigned int setRandomEntr(byte max)
{
    return setRandomEntr(0, max);
}

unsigned int addRandomEntr(byte min, byte max)
{
    max = max ? random8(min, max(1, max)) : 0;

    for (byte i = 0; i < max; i++) {
        random16_add_entropy(getRandomSeed() * (analogRead(LED_BUILTIN) / random8(1, 20) * random8(0, 2)));
    }

    return getRandomSeed();
}

unsigned int addRandomEntr(byte max)
{
    return addRandomEntr(0, max);
}

void addRandomEntrEveryNCalls(byte n)
{
    static unsigned int i = 0;

    if (0 == (i % n)) {
        addRandomEntr();
    }

    i++;
}

unsigned int getRandomIndx(unsigned int size)
{
    addRandomEntr();

    return randUInt(max(0, size - 1));
}

bool lt(int x, unsigned int y)
{
    return (x < 0) || (static_cast<unsigned int>(x) < y);
}

bool lt(unsigned int x, int y)
{
    return (y >= 0) && (x < static_cast<unsigned int>(y));
}

bool lt(unsigned int x, unsigned int y)
{
    return x < y;
}

bool lt(int x, int y)
{
    return x < y;
}

byte getPinMode(byte pin)
{
    const byte bit = digitalPinToBitMask(pin);
    const byte prt = digitalPinToPort(pin);

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

bool setPinMode(byte pin, byte act)
{
    pinMode(pin, act);
    delay(100);

    return isPinMode(pin, act);
}

bool setPinModeOutput(byte pin)
{
    return setPinMode(pin, PIN_MODE_OUTPUT);
}

bool setPinModeOutput(byte pin, byte out)
{
    setPinMode(pin, PIN_MODE_OUTPUT);
    digitalWrite(pin, out);
    delay(100);

    return isPinModeOutput(pin);
}

bool setPinModeInput(byte pin)
{
    return setPinMode(pin, PIN_MODE_INPUT);
}

bool setPinModeInputPullup(byte pin)
{
    return setPinMode(pin, PIN_MODE_INPUT_PULLUP);
}

bool isPinMode(byte pin, byte act)
{
    return getPinMode(pin) == act;
}

bool isPinModeOutput(byte pin)
{
    return isPinMode(pin, PIN_MODE_OUTPUT);
}

bool isPinModeInput(byte pin)
{
    return isPinMode(pin, PIN_MODE_INPUT);
}

bool isPinModeInputPullup(byte pin)
{
    return isPinMode(pin, PIN_MODE_INPUT_PULLUP);
}

const String strQuote(const String value, const String quote)
{
    return String(quote) + value + String(quote);
}

const String strPadsCharLft(const String value, int padSize, const String padChar)
{
    const unsigned int valSize = value.length();

    if (padSize < 0) {
        padSize = abs(padSize);
    } else {
        padSize = (padSize - valSize) >= 0 ? (padSize - valSize) : 0;
    }

    String valRetn;

    for (unsigned int i = 0; lt(i, padSize); i = i + padChar.length()) {
        valRetn = valRetn + padChar;
    }

    return valRetn + value;
}

const String strPadsCharRgt(const String value, int padSize, const String padChar)
{
    const unsigned int valSize = value.length();

    if (padSize < 0) {
        padSize = abs(padSize);
    } else {
        padSize = (padSize - valSize) >= 0 ? (padSize - valSize) : 0;
    }

    String valRetn;

    for (unsigned int i = 0; lt(i, padSize); i = i + padChar.length()) {
        valRetn = valRetn + padChar;
    }

    return valRetn + value;
}

const String strPadsChar(const String value, int padSize, const String padChar, const StringPadDirection padWhat)
{
    switch (padWhat) {
        case StringPadDirection::lft:
            return strPadsCharLft(
                value,
                padSize,
                padChar
            );

        case StringPadDirection::rgt:
            return strPadsCharRgt(
                value,
                padSize,
                padChar
            );

        default:
            return strPadsCharLft(
                strPadsCharRgt(
                    value,
                    floor(padSize / 2),
                    padChar
                ),
                ceil(padSize / 2),
                padChar
            );
    }
}

const unsigned int changeIntBase(unsigned int val, unsigned int curBase, unsigned int newBase)
{
    return ((val * newBase) / curBase);
}

const unsigned int fracToPercent(unsigned int val)
{
    return changeIntBase(val, 255, 100);
}

const unsigned int miliToSeconds(unsigned int val)
{
    return (val / 1000);
}
