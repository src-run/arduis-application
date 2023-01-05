
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_UTILITES
#define _ARDUIS_HR_UTILITES

#include <Arduino.h>
#include <FastLED.h>

#define ARRAY_SIZE(A) (*(&A + 1) - A)
//#define ARRAY_SIZE(A) ((int)(sizeof(A) / sizeof((A)[0])))

#define PIN_MODE_UNKNOWN      0xff
#define PIN_MODE_INPUT        INPUT
#define PIN_MODE_INPUT_PULLUP INPUT_PULLUP
#define PIN_MODE_OUTPUT       OUTPUT

enum StringPadDirection {
    lft = -1,
    eql =  0,
    rgt =  1,
};

byte getPinMode(byte pin);

bool setPinMode(byte pin, byte act);
bool setPinModeOutput(byte pin);
bool setPinModeOutput(byte pin, byte out);
bool setPinModeInput(byte pin);
bool setPinModeInputPullup(byte pin);

bool isPinMode(byte pin, byte act);
bool isPinModeOutput(byte pin);
bool isPinModeInput(byte pin);
bool isPinModeInputPullup(byte pin);

String strPadsChar(const String value, const int padding = -1, const String useChar = " ", const StringPadDirection useSide = StringPadDirection::lft);

inline String        strPadsCharLft(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strPadsCharRgt(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strPadsCharEql(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strQuote(const String value, const String quote = "\"")                          __attribute__((always_inline));

inline unsigned long miliToSeconds(const unsigned long val)                                           __attribute__((always_inline));

inline unsigned int  cstrPerc(const long p)                                                           __attribute__((always_inline));
inline byte          cstrByte(const long i)                                                           __attribute__((always_inline));
inline unsigned int  cstrUInt(const long i)                                                           __attribute__((always_inline));

inline byte          randByte()                                                                       __attribute__((always_inline));
inline byte          randByte(byte lim)                                                               __attribute__((always_inline));
inline byte          randByte(byte min, byte lim)                                                     __attribute__((always_inline));

inline unsigned int  randUInt()                                                                       __attribute__((always_inline));
inline unsigned int  randUInt(unsigned int lim)                                                       __attribute__((always_inline));
inline unsigned int  randUInt(unsigned int min, unsigned int lim)                                     __attribute__((always_inline));

inline unsigned int  setRandomEntr(byte min, byte max)                                                __attribute__((always_inline));
inline unsigned int  setRandomEntr(byte max = 8)                                                      __attribute__((always_inline));
inline unsigned int  addRandomEntr(byte min, byte max)                                                __attribute__((always_inline));
inline unsigned int  addRandomEntr(byte max = 8)                                                      __attribute__((always_inline));
inline void          addRandomEntrEveryNCalls(byte n = 16)                                            __attribute__((always_inline));

inline unsigned int  getRandomSeed()                                                                  __attribute__((always_inline));
inline unsigned int  getRandomIndx(unsigned int size)                                                 __attribute__((always_inline));

inline bool          lt(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          lt(int x, int y)                                                                 __attribute__((always_inline));

String strPadsCharLft(const String value, int padding, const String useChar)
{
    return strPadsChar(value, padding, useChar, StringPadDirection::lft);
}

String strPadsCharRgt(const String value, int padding, const String useChar)
{
    return strPadsChar(value, padding, useChar, StringPadDirection::rgt);
}

String strPadsCharEql(const String value, int padding, const String useChar)
{
    return strPadsChar(value, padding, useChar, StringPadDirection::eql);
}

String strQuote(const String value, const String quote)
{
    return String(quote) + value + String(quote);
}

unsigned long miliToSeconds(const unsigned long val)
{
    return (val / 1000);
}

inline unsigned int cstrPerc(const long p)
{
    return constrain(p, 0, 100);
}

inline byte cstrByte(const long i)
{
    return constrain(i, 0, 255);
}

inline unsigned int cstrUInt(const long i)
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

    if (0 == (i++ % n)) {
        addRandomEntr();
    }
}

unsigned int getRandomSeed()
{
    return random16_get_seed();
}

unsigned int getRandomIndx(unsigned int size)
{
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

#endif
