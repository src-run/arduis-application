
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

#define ARRAY_SIZE(A) ((int)(sizeof(A) / sizeof((A)[0])))

uint8_t      minInt8(int16_t i);
uint8_t      maxInt8(int16_t i);
uint8_t      useInt8(int16_t i);
void         setRandom16Seed(uint8_t iterations = 4);
unsigned int getRandomArrayIndex(unsigned int size);

#endif
