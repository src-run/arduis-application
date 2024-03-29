
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "Common.h"
#include "Switch.h"

extern CRGB ledStrandsActiveColors[LED_STR_NUM];
extern CRGB ledStrandsCustomColors[LED_STR_NUM];

void setupStrand();
