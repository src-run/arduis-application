
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "main.h"

void setup()
{
    setPinModeOutput(LED_BUILTIN, LOW);
    initializeSerial();
    initializeStrand();
    cyclePattern(false);
}

void loop()
{
    runSelectedStep();

    EVERY_N_MILLISECONDS(LED_STR_PAL_CYCLE) {
        cyclePalette();
    }

    EVERY_N_MILLISECONDS(getLedPatternItemRandHuesMili()) {
        cycleRandHue();
    }

    EVERY_N_MILLISECONDS(getLedPatternItemCallExecMili()) {
        cyclePattern();
    }
}

void cyclePalette(bool fadeEnds, bool fadeInit)
{
    if (!isLedPaletteStepStarted()) {
        return;
    }

    while(fadeEnds && runSelectedStepFadeEnds()) {
        runSelectedStep(false);
    }

    incPalettesStep();
    runSelectedStep();

    while(fadeInit && runSelectedStepFadeInit()) {
        runSelectedStep(false);
    }
}

void cyclePattern(bool fadeEnds, bool fadeInit)
{
    while(fadeEnds && runSelectedStepFadeEnds()) {
        runSelectedStep(false);
    }

    incSelectedStep();
    runSelectedStep();

    while(fadeInit && runSelectedStepFadeInit()) {
        runSelectedStep(false);
    }
}

void cycleRandHue()
{
    ledPatternBaseColorHue++;
}
