
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
#include "SelectManager.h"
#include "EffectFading.h"

extern SelectManager EffectSelect;

void setupSelect();
void cycleSelect();
void cycleSelectTwist();
void cycleSelectPress();
void debugSelect();
void debugSelectTwist();
void debugSelectClick();
void debugSelectPress();
