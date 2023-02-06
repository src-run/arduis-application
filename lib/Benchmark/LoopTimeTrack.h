
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
#include "LoopTimeResult.h"
#include "Config.h"

class LoopTimeTrack {
#if OUT_TIMERS_STAT
    private:
        RunningAverage _tracker        { 100 };
        byte           _timerInitCount { 0 };
        bool           _timerActivated { false };
        unsigned long  _timerBegMillis { 0 };
        const byte     _pollsFrequency { 25 };
#endif

    public:
        LoopTimeTrack() = default;

        void timerInit();
        void timerStop(const bool track = true, const bool write = false);
        void writeInfo(const bool force = false);
};

// EXTERNAL DECLARATIONS/DEFINITIONS

extern void outLoopTimeInfo(const LoopTimeResult&);
