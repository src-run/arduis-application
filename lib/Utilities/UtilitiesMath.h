
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

inline unsigned int  intLen(const byte           value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const signed short   value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const unsigned short value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const signed int     value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const unsigned int   value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const signed long    value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const unsigned long  value, const unsigned short base = 10,     const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const float          value, const unsigned short precision = 2, const unsigned short minLen = 0) __attribute__((always_inline));
inline unsigned int  intLen(const double         value, const unsigned short precision = 2, const unsigned short minLen = 0) __attribute__((always_inline));

template<typename T>
inline bool lt(int a, T b)
{
    return (a < 0) || (static_cast<T>(a) < b);
}

template<typename T>
inline bool lt(unsigned int a, T b)
{
    return (b >= 0) && (a < static_cast<unsigned int>(b));
}

template<typename T>
inline bool lt(long a, T b)
{
    return (a < 0) || (static_cast<T>(a) < b);
}

template<typename T>
inline bool lt(unsigned long a, T b)
{
    return (b >= 0) && (a < static_cast<unsigned long>(b));
}

template<typename T>
inline bool le(int a, T b)
{
    return (a < 0) || (static_cast<T>(a) <= b);
}

template<typename T>
inline bool le(unsigned int a, T b)
{
    return (b >= 0) && (a <= static_cast<unsigned int>(b));
}

template<typename T>
inline bool le(long a, T b)
{
    return (a < 0) || (static_cast<T>(a) <= b);
}

template<typename T>
inline bool le(unsigned long a, T b)
{
    return (b >= 0) && (a <= static_cast<unsigned long>(b));
}

template<typename T>
inline bool gt(int a, T b)
{
    return (b < 0) || (static_cast<T>(a) > b);
}

template<typename T>
inline bool gt(unsigned int a, T b)
{
    return (a >= 0) && (a > static_cast<unsigned int>(b));
}

template<typename T>
inline bool gt(long a, T b)
{
    return (b < 0) || (static_cast<T>(a) > b);
}

template<typename T>
inline bool gt(unsigned long a, T b)
{
    return (a >= 0) && (a > static_cast<unsigned long>(b));
}

template<typename T>
inline bool ge(int a, T b)
{
    return (b < 0) || (static_cast<T>(a) >= b);
}

template<typename T>
inline bool ge(unsigned int a, T b)
{
    return (a >= 0) && (a >= static_cast<unsigned int>(b));
}

template<typename T>
inline bool ge(long a, T b)
{
    return (b < 0) || (static_cast<T>(a) >= b);
}

template<typename T>
inline bool ge(unsigned long a, T b)
{
    return (a >= 0) && (a >= static_cast<unsigned long>(b));
}

template<typename A, typename B>
auto maxInt(A a, B b) -> decltype(lt(a, b) ? b : a)
{
    return lt(a, b) ? b : a;
}

template<typename A, typename B>
auto minInt(A a, B b) -> decltype(lt(b, a) ? b : a)
{
    return lt(b, a) ? b : a;
}

template<typename A, typename B, typename C>
auto conInt(A val, B min, C lim) -> decltype(minInt(maxInt(val, min), lim))
{
    return minInt(maxInt(val, min), lim);
}

unsigned int intLen(const byte value, const unsigned short base, const unsigned short minLen)
{
    return intLen((unsigned long)value, base, minLen);
}

unsigned int intLen(const signed short value, const unsigned short base, const unsigned short minLen)
{
    return intLen((signed long)value, base, minLen);
}

unsigned int intLen(const unsigned short value, const unsigned short base, const unsigned short minLen)
{
    return intLen((unsigned long)value, base, minLen);
}

unsigned int intLen(const signed int value, const unsigned short base, const unsigned short minLen)
{
    return intLen((signed long)value, base, minLen);
}

unsigned int intLen(const unsigned int value, const unsigned short base, const unsigned short minLen)
{
    return intLen((unsigned long)value, base, minLen);
}

unsigned int intLen(const signed long value, const unsigned short base, const unsigned short minLen)
{
    return maxInt(String(value, base).length(), minLen);
}

unsigned int intLen(const unsigned long value, const unsigned short base, const unsigned short minLen)
{
    return maxInt(String(value, base).length(), minLen);
}

unsigned int intLen(const float value, unsigned short precision, const unsigned short minLen)
{
    return maxInt(String(value, precision).length(), minLen);
}

unsigned int intLen(const double value, unsigned short precision, const unsigned short minLen)
{
    return maxInt(String(value, precision).length(), minLen);
}
