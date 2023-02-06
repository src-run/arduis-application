
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "Config.h"

#define ARRAY_SIZE(A) (*(&A + 1) - A)

#define PIN_MODE_UNKNOWN      0xff
#define PIN_MODE_INPUT        INPUT
#define PIN_MODE_INPUT_PULLUP INPUT_PULLUP
#define PIN_MODE_OUTPUT       OUTPUT

enum class StringPadDirection : byte {
    lft,
    eql,
    rgt
};

extern String        strPadsChar(const String, const int, const String, const StringPadDirection);

inline String        strPadsCharLft(const String value, int padding = -1, const String useChar = " ")        __attribute__((always_inline));
inline String        strPadsCharRgt(const String value, int padding = -1, const String useChar = " ")        __attribute__((always_inline));
inline String        strPadsCharEql(const String value, int padding = -1, const String useChar = " ")        __attribute__((always_inline));
inline String        strPadsNumbLft(const unsigned long value, int padding = -1, const String useChar = "0") __attribute__((always_inline));
inline String        strPadsNumbRgt(const unsigned long value, int padding = -1, const String useChar = "0") __attribute__((always_inline));
inline String        strPadsNumbEql(const unsigned long value, int padding = -1, const String useChar = "0") __attribute__((always_inline));
inline String        strQuote(const String value, const String quote = "\"")                                 __attribute__((always_inline));
inline String        strConditionalNothing(bool conditional, const String value)                             __attribute__((always_inline));
inline String        strConditionalTernary(bool conditional, const String valueT, const String valueF)       __attribute__((always_inline));

inline unsigned long miliToSeconds(const unsigned long val)                                           __attribute__((always_inline));

inline unsigned int  cstrPerc(const long p)                                                           __attribute__((always_inline));
inline byte          cstrByte(const long i)                                                           __attribute__((always_inline));
inline unsigned int  cstrUInt(const long i)                                                           __attribute__((always_inline));
inline unsigned int  cstrArrayIndex(const unsigned int index, const unsigned int size)                __attribute__((always_inline));

inline unsigned int  byteToPerc(const unsigned long i)                                                __attribute__((always_inline));

inline bool          lt(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          lt(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          lt(int x, int y)                                                                 __attribute__((always_inline));

inline bool          le(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          le(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          le(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          le(int x, int y)                                                                 __attribute__((always_inline));

inline bool          gt(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          gt(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          gt(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          gt(int x, int y)                                                                 __attribute__((always_inline));

inline bool          ge(int x, unsigned int y)                                                        __attribute__((always_inline));
inline bool          ge(unsigned int x, int y)                                                        __attribute__((always_inline));
inline bool          ge(unsigned int x, unsigned int y)                                               __attribute__((always_inline));
inline bool          ge(int x, int y)                                                                 __attribute__((always_inline));

inline bool          isMatch(const char *subject, const char *matcher)                                __attribute__((always_inline));
inline bool          isMatch(const char *subject, const String matcher)                               __attribute__((always_inline));
inline bool          isMatch(const String subject, const char *matcher)                               __attribute__((always_inline));
inline bool          isMatch(const String subject, const String matcher)                              __attribute__((always_inline));

inline unsigned int  intLen(const byte value)                                                         __attribute__((always_inline));
inline unsigned int  intLen(const signed short value)                                                 __attribute__((always_inline));
inline unsigned int  intLen(const unsigned short value)                                               __attribute__((always_inline));
inline unsigned int  intLen(const signed int value)                                                   __attribute__((always_inline));
inline unsigned int  intLen(const unsigned int value)                                                 __attribute__((always_inline));
inline unsigned int  intLen(const signed long value)                                                  __attribute__((always_inline));
inline unsigned int  intLen(const unsigned long value)                                                __attribute__((always_inline));
inline unsigned int  intLen(const float value, unsigned short precision = 2)                          __attribute__((always_inline));
inline unsigned int  intLen(const double value, unsigned short precision = 2)                         __attribute__((always_inline));

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

String strPadsNumbLft(const unsigned long value, int padding, const String useChar)
{
    return strPadsChar(String { value }, padding, useChar, StringPadDirection::lft);
}

String strPadsNumbRgt(const unsigned long value, int padding, const String useChar)
{
    return strPadsChar(String { value }, padding, useChar, StringPadDirection::rgt);
}

String strPadsNumbEql(const unsigned long value, int padding, const String useChar)
{
    return strPadsChar(String { value }, padding, useChar, StringPadDirection::eql);
}

String strQuote(const String value, const String quote)
{
    return String(quote) + value + String(quote);
}

String strConditionalNothing(bool conditional, const String value)
{
    return conditional ? value : "";
}

String strConditionalTernary(bool conditional, const String valueT, const String valueF)
{
    return conditional ? valueT : valueF;
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

inline unsigned int cstrArrayIndex(const unsigned int index, const unsigned int size)
{
    return constrain(index, 0U, max(0U, size - 1));
}

unsigned int byteToPerc(const unsigned long i)
{
    return cstrPerc(i * 100 / 255);
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

bool le(int x, unsigned int y)
{
    return (x < 0) || (static_cast<unsigned int>(x) <= y);
}

bool le(unsigned int x, int y)
{
    return (y >= 0) && (x <= static_cast<unsigned int>(y));
}

bool le(unsigned int x, unsigned int y)
{
    return x <= y;
}

bool le(int x, int y)
{
    return x <= y;
}

bool gt(int x, unsigned int y)
{
    return (y < 0) || (static_cast<unsigned int>(x) > y);
}

bool gt(unsigned int x, int y)
{
    return (x >= 0) && (x > static_cast<unsigned int>(y));
}

bool gt(unsigned int x, unsigned int y)
{
    return x > y;
}

bool gt(int x, int y)
{
    return x > y;
}

bool ge(int x, unsigned int y)
{
    return (y < 0) || (static_cast<unsigned int>(x) >= y);
}

bool ge(unsigned int x, int y)
{
    return (x >= 0) && (x >= static_cast<unsigned int>(y));
}

bool ge(unsigned int x, unsigned int y)
{
    return x >= y;
}

bool ge(int x, int y)
{
    return x >= y;
}

bool isMatch(const char *subject, const char *matcher)
{
    return 0 == strcmp(subject, matcher);
}

bool isMatch(const char *subject, const String matcher)
{
    return isMatch(subject, matcher.c_str());
}

bool isMatch(const String subject, const char *matcher)
{
    return isMatch(subject.c_str(), matcher);
}

bool isMatch(const String subject, const String matcher)
{
    return isMatch(subject.c_str(), matcher.c_str());
}

unsigned int intLen(const byte value)
{
    return String(value).length();
}

unsigned int intLen(const signed short value)
{
    return String(value).length();
}

unsigned int intLen(const unsigned short value)
{
    return String(value).length();
}

unsigned int intLen(const signed int value)
{
    return String(value).length();
}

unsigned int intLen(const unsigned int value)
{
    return String(value).length();
}

unsigned int intLen(const signed long value)
{
    return String(value).length();
}

unsigned int intLen(const unsigned long value)
{
    return String(value).length();
}

unsigned int intLen(const float value, unsigned short precision)
{
    return String(value, precision).length();
}

unsigned int intLen(const double value, unsigned short precision)
{
    return String(value, precision).length();
}
