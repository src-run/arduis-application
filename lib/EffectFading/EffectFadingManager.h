
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
#include "CommonFastLED.h"
#include "Timers.h"
#include "Config.h"
#include "UtilitiesInline.h"

class EffectFadingManager {
    private:
        bool                 _faderEnabled;
        const unsigned short _levelMinimum;
        const unsigned short _levelMaximum;
        const unsigned short _levelChgStep;
        const unsigned short _levelChgWait;
        unsigned short       _levelCurrent;

        bool isLevelMaximum() { return _levelCurrent >= _levelMaximum; }
        bool isLevelMinimum() { return _levelCurrent <= _levelMinimum; }

        void runLevelToMaximumPostOperations();
        void runLevelToMinimumPostOperations();

        void setLevel(const signed int level);
        void setLevelAndRunEffect(const signed int level);

        unsigned short constrainLevelType(const signed int level) { return cstrByte(level); }
        unsigned short constrainLevelConf(const signed int level) { return conInt(constrainLevelType(level), _levelMinimum, _levelMaximum); }

    public:
        EffectFadingManager(
            bool                 faderEnabled = LED_FDR_IS_ACTIVE,
            const unsigned short levelMinimum = LED_FDR_LEVEL_MIN,
            const unsigned short levelMaximum = LED_FDR_LEVEL_MAX,
            const unsigned short levelChgStep = LED_FDR_STEPS_CHG,
            const unsigned short levelChgWait = LED_FDR_WAITS_CHG,
            const unsigned short levelCurrent = LED_FDR_LEVEL_BEG
        ) :
            _faderEnabled { faderEnabled },
            _levelMinimum { constrainLevelType(levelMinimum) },
            _levelMaximum { constrainLevelType(levelMaximum) },
            _levelChgStep { maxInt(levelChgStep, (unsigned short)1) },
            _levelChgWait { maxInt(levelChgWait, (unsigned short)0) },
            _levelCurrent { constrainLevelConf(levelCurrent) }
        {};

        void levelToMaximum();
        void levelToMinimum();
};

// EXTERNAL DECLARATIONS/DEFINITIONS

extern void runPatternsStep();
