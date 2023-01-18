
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Select.h"

SelectManager EffectSelect { };

void setupSelect()
{
    EffectSelect.begins();
}

void cycleSelect()
{
    cycleSelectTwist();
    cycleSelectPress();
}

void cycleSelectTwist()
{
    if (EffectSelect.hasClick() && EffectSelect.hasTwistCount()) {
        EffectFading.fadeToLevelMinimum();
        setPatternsStep(EffectSelect.getTwistCount());
        runPatternsStep();
        EffectFading.fadeToLevelMaximum();
    }
}

void cycleSelectPress()
{
    static byte pressCycles { 0 };

    if (EffectSelect.hasPress() && ++pressCycles >= 4) {
        EffectFading.fadeToLevelMinimum();
        rstPatternsStep();
        runPatternsStep();
        EffectFading.fadeToLevelMaximum();
        pressCycles = 0;
    }
}

void debugSelect()
{
    if (EffectSelect.hasTwistCount()) {
        debugSelectTwist();
    }

    if (EffectSelect.hasClick()) {
        debugSelectClick();
    }

    if (EffectSelect.hasPress()) {
        debugSelectPress();
    }
}

void debugSelectTwist()
{
    const String format { F("=== Twist - Movement : %02d (%03d)") };
    char         buffer [ format.length() - 4 + 2 - 4 + 3 + 1 ];

    sprintf(
        buffer,
        format.c_str(),
        EffectSelect.getTwistDiffs(),
        EffectSelect.getTwistCount()
    );

    Serial.println(buffer);
}

void debugSelectClick()
{
    Serial.println(F("=== Twist - Clicked  : TRUE"));
}

void debugSelectPress()
{
    Serial.println(F("=== Twist - Pressed  : TRUE"));
}
