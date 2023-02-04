
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
    setupOutput();
    setupSystem();
    setupWiring();
    setupRandom();

    setupClocks();
    setupTemper();
    setupSelect();

    checkMinPwr();
    setupStrand();
    setupRelays();

    setupTimers();
    setupCycles();
}

void loop()
{
    runPatternsStep();

    if (PatternPeriodTimer.ready()) {
        PatternPeriodTimer.setPeriodTime(runTimerPattern());
    }

    if (PalettePeriodTimer.ready()) {
        PalettePeriodTimer.setPeriodTime(runTimerPalette());
    }

    if (ByteNumPeriodTimer.ready()) {
        ByteNumPeriodTimer.setPeriodTime(runTimerByteNum());
    }

    if (TempHumPeriodTimer.ready()) {
        cycleTemper();
    }

    if (SelectsPeriodTimer.ready()) {
        cycleSelect();
    }
}

unsigned long runTimerPattern(bool doCycle)
{
    if (doCycle) {
        EffectFading.fadeToLevelMinimum();
        incPatternsStep();
        runPatternsStep();
        EffectFading.fadeToLevelMaximum();
    }

    return getLedPatternItemCallExecSecs();
}

unsigned long runTimerPalette(bool doCycle)
{
    if (doCycle && isLedPaletteStepStarted()) {
        EffectFading.fadeToLevelMinimum();
        incPalettesStep();
        runPatternsStep();
        EffectFading.fadeToLevelMaximum();
    }

    return getLedPaletteItemCallExecSecs();
}

unsigned long runTimerByteNum()
{
    incByteNumStep();

    return isLedPaletteStepStarted()
        ? getLedPaletteItemRandHuesMili()
        : getLedPatternItemRandHuesMili();
}

void setupCycles()
{
    runTimerPattern();
}
