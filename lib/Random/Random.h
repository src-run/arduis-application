
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "CommonFastLED.h"
#include "Config.h"

void                 setupRandom();

inline byte          randByte()                                                                       __attribute__((always_inline));
inline byte          randByte(byte lim)                                                               __attribute__((always_inline));
inline byte          randByte(byte min, byte lim)                                                     __attribute__((always_inline));

inline unsigned int  randUInt()                                                                       __attribute__((always_inline));
inline unsigned int  randUInt(unsigned int lim)                                                       __attribute__((always_inline));
inline unsigned int  randUInt(unsigned int min, unsigned int lim)                                     __attribute__((always_inline));

inline unsigned long randLong()                                                                       __attribute__((always_inline));
inline unsigned long randLong(unsigned long lim)                                                      __attribute__((always_inline));
inline unsigned long randLong(unsigned long min, unsigned long lim)                                   __attribute__((always_inline));

inline void          addRandomEntr(unsigned int min, unsigned int max)                                __attribute__((always_inline));
inline unsigned int  getRandomEntr()                                                                  __attribute__((always_inline));
void                 setRandomEntr(unsigned int min, unsigned int max, bool inc);

inline unsigned int  getRandomSeed()                                                                  __attribute__((always_inline));
inline unsigned int  getRandomIndx(unsigned int size)                                                 __attribute__((always_inline));

byte randByte()
{
    return random8();
}

byte randByte(byte lim)
{
    return random8(lim);
}

byte randByte(byte min, byte lim)
{
    return random8(min, lim);
}

unsigned int randUInt()
{
    return random16();
}

unsigned int randUInt(unsigned int lim)
{
    return random16(lim);
}

unsigned int randUInt(unsigned int min, unsigned int lim)
{
    return random16(min, lim);
}

unsigned long randLong()
{
    return random();
}

unsigned long randLong(unsigned long lim)
{
    return random(lim);
}

unsigned long randLong(unsigned long min, unsigned long lim)
{
    return random(min, lim);
}

void addRandomEntr(unsigned int min, unsigned int max)
{
    setRandomEntr(min, max, true);
}

unsigned int getRandomEntr()
{
    return analogRead(LED_BUILTIN) * analogRead(LED_BUILTIN) * analogRead(LED_BUILTIN) / analogRead(LED_BUILTIN);
}

unsigned int getRandomSeed()
{
    return random16_get_seed();
}

unsigned int getRandomIndx(unsigned int size)
{
    return randUInt(max(0, size - 1));
}
