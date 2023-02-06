
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
    LoopRunBench.timerInit();

    runPatternsStep();

    if (PatternPeriodTimer.ready()) {
        PatternPeriodTimer.setPeriodTime(runTimerPattern());
    }

    if (PalettePeriodTimer.ready() && isLedPaletteStepStarted()) {
        PalettePeriodTimer.setPeriodTime(runTimerPalette());
    }

    if (ByteNumPeriodTimer.ready()) {
        ByteNumPeriodTimer.setPeriodTime(runTimerScaling());
    }

    if (TempHumPeriodTimer.ready()) {
        cycleTemper();
    }

    if (SelectsPeriodTimer.ready()) {
        cycleSelect();
    }

    LoopRunBench.timerStop();
    LoopRunBench.writeInfo();
}

unsigned long runTimerPattern()
{
    EffectFading.levelToMinimum();
    incPatternsStep();
    EffectFading.levelToMaximum();

    return getLedPatternItemCallExecSecs();
}

unsigned long runTimerPalette()
{
    EffectFading.levelToMinimum();
    incPalettesStep();
    EffectFading.levelToMaximum();

    return getLedPaletteItemCallExecSecs();
}

unsigned long runTimerScaling()
{
    EffectScaler.inc();

    return isLedPaletteStepStarted()
        ? getLedPaletteItemRandHuesMili()
        : getLedPatternItemRandHuesMili();
}

void setupCycles()
{
    runTimerPattern();
}
