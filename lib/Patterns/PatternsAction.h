
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
#include "EffectDefinitionDetail.h"
#include "EffectDefinitionTimers.h"
#include "EffectDefinitionGlints.h"
#include "PatternsActionRunner.h"

class PatternsAction {
    public:
        const EffectDefinitionDetail detail;
        const ActionRunnerPattern    runner;
        const EffectDefinitionTimers timers;
        const EffectDefinitionGlints glints;

        PatternsAction(EffectDefinitionDetail d, ActionRunnerPattern r, EffectDefinitionTimers t, EffectDefinitionGlints g) : detail { d }, runner { r }, timers { t }, glints { g } {}
};
