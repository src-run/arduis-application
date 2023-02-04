
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
#include "Config.h"

class EffectFadingManager {
    private:
        bool       _faderEnabled;
        const byte _levelMinimum;
        const byte _levelMaximum;
        const byte _levelChgStep;
        const byte _levelChgWait;
        const byte _levelEndWait;
        byte       _levelCurrent;

    public:
        EffectFadingManager(
            bool       faderEnabled = LED_FDR_FADE_ENBL,
            const byte levelMinimum = LED_FDR_LEVEL_MIN,
            const byte levelMaximum = LED_FDR_LEVEL_MAX,
            const byte levelChgStep = LED_FDR_LEVEL_CHG,
            const byte levelChgWait = LED_FDR_LOOP_MILI,
            const byte levelEndWait = LED_FDR_NEXT_MILI
        ) :
            _faderEnabled { faderEnabled },
            _levelMinimum { levelMinimum },
            _levelMaximum { levelMaximum },
            _levelChgStep { levelChgStep },
            _levelChgWait { levelChgWait },
            _levelEndWait { levelEndWait },
            _levelCurrent { LED_FDR_FADE_INIT }
        {};

        bool isEnabled();
        void fadeToLevelMaximum();
        void fadeToLevelMinimum();

    protected:
        bool loopToLevelMaximum();
        bool loopToLevelMinimum();

        bool isLevelMaximum();
        bool isLevelMinimum();

        void setBrightness(const byte waits);
        void setBrightness(const byte level, const byte waits);
};

// EXTERNAL DECLARATIONS/DEFINITIONS

extern void runPatternsStep(const bool, const bool);
