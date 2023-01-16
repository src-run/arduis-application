
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

class EffectDefinitionGlints {
    public:
        const byte minimum;
        const byte maximum;
        const byte chances;
        const byte amounts;

        EffectDefinitionGlints(const byte m, const byte l, const byte c, const byte a) : minimum { m }, maximum { l }, chances { c }, amounts { a } {}
};
