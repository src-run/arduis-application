
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
#include "Random.h"

class EffectFactorGenerator {
    private:
        byte _resultBase { LED_PAL_FACT_BASE };
        byte _resultMins { LED_PAL_FACT_MINS };
        byte _factor     { LED_PAL_FACT_MINS };

    public:
        EffectFactorGenerator() = default;
        EffectFactorGenerator(byte resultBase, byte resultMins) :
            _resultBase { resultBase },
            _resultMins { resultMins },
            _factor     { resultMins }
        {};

        void refresh();
        byte resolve();
};
