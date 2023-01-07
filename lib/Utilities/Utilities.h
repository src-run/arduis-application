
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

#include "Config.h"

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

byte                 getPinMode(byte pin);

inline bool          setPinMode(byte pin, byte act)                                                   __attribute__((always_inline));
inline bool          setPinModeOutput(byte pin)                                                       __attribute__((always_inline));
inline bool          setPinModeOutput(byte pin, byte out)                                             __attribute__((always_inline));
inline bool          setPinModeInput(byte pin)                                                        __attribute__((always_inline));
inline bool          setPinModeInputPullup(byte pin)                                                  __attribute__((always_inline));

inline bool          isPinMode(byte pin, byte act)                                                    __attribute__((always_inline));
inline bool          isPinModeOutput(byte pin)                                                        __attribute__((always_inline));
inline bool          isPinModeInput(byte pin)                                                         __attribute__((always_inline));
inline bool          isPinModeInputPullup(byte pin)                                                   __attribute__((always_inline));

String               strPadsChar(const String value, const int padding = -1, const String useChar = " ", const StringPadDirection useSide = StringPadDirection::lft);

inline String        strPadsCharLft(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strPadsCharRgt(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strPadsCharEql(const String value, int padding = -1, const String useChar = " ") __attribute__((always_inline));
inline String        strQuote(const String value, const String quote = "\"")                          __attribute__((always_inline));

inline unsigned long miliToSeconds(const unsigned long val)                                           __attribute__((always_inline));

inline unsigned int  cstrPerc(const long p)                                                           __attribute__((always_inline));
inline byte          cstrByte(const long i)                                                           __attribute__((always_inline));
inline unsigned int  cstrUInt(const long i)                                                           __attribute__((always_inline));

inline bool          lt(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          lt(int x, int y)                                                                 __attribute__((always_inline));

inline void          initializeSystem()                                                               __attribute__((always_inline));

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

void initializeSystem()
{
    setPinModeOutput(LED_BUILTIN, SYS_ONBLED_ENBL ? HIGH : LOW);
}

#endif
