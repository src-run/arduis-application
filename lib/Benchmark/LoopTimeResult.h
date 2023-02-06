
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
#include "RunningAverage.h"
#include "Config.h"

struct LoopTimeResult {
    const float average;
    const unsigned int minimum;
    const unsigned int maximum;
    const float stdDeviation;
    const float stdError;
    const unsigned short sampleCount;
    const unsigned short sampleAvail;
    const byte sampleFrequency;
};
