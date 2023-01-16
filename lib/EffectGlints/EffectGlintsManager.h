
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
#include "Utilities.h"

class EffectGlintsManager {
    private:
        const bool _enable { false };
        bool       _result { false };
        byte       _chance { 0 };
        byte       _random { 0 };

    public:
        EffectGlintsManager(bool enable = LED_PTN_GLNT_ENBL) : _enable { enable } {};

        void setChance(const byte chance, const byte base = 100);
        byte getChance();
        byte getChancePercent();
        byte getRandom();
        byte getRandomPercent();
        bool isEnabled();
};
