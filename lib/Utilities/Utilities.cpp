
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Utilities.h"

byte byteLimitLower(long i)
{
    return max(i, 0);
}

byte byteLimitUpper(long i)
{
    return min(i, 255);
}

byte byteLimit(long i)
{
    return byteLimitLower(byteLimitUpper(i));
}

byte getRandInt08(byte min, byte lim)
{
    return random8(min, lim);
}

byte getRandInt08(byte lim)
{
    return getRandInt08(0, lim);
}

unsigned int getRandInt16(unsigned int min, unsigned int lim)
{
    return random16(min, lim);
}

unsigned int getRandInt16(unsigned int lim)
{
    return getRandInt16(0, lim);
}

unsigned int getRandomSeed()
{
    return random16_get_seed();
}

unsigned int addRandomEntr(byte min, byte max)
{
    max = max ? random8(min, max(1, max)) : 0;

    for (byte i = 0; i < max; i++) {
        random16_add_entropy(getRandomSeed() * (analogRead(LED_BUILTIN) / random8(1, 100)));
    }

    return getRandomSeed();
}

unsigned int addRandomEntr(byte max)
{
    return addRandomEntr(0, max);
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

unsigned int getRandomIndx(unsigned int size)
{
    addRandomEntr();

    return getRandInt16(max(0, size - 1));
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
