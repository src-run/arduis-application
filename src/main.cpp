
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
    setupSystem();
    setupSerial();
    setupRandom();
    setupStrand();
    setupSwitch();
    setupCycles();
    setupTimers();
}

void loop()
{
    runPatternsStep();

    if (PatternTimer.ready()) {
        PatternTimer.setTimePeriod(runTimerCyclePattern());
    }

    if (PaletteTimer.ready()) {
        PaletteTimer.setTimePeriod(runTimerCyclePalette());
    }

    if (ByteNumTimer.ready()) {
        ByteNumTimer.setTimePeriod(runTimerCycleByteNum());
    }
}

unsigned long runTimerCyclePattern(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle) {
        runPatternsFadeToBlack(fadeToBlack);
        incPatternsStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPatternItemCallExecSecs();
}

unsigned long runTimerCyclePalette(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle && isLedPaletteStepStarted()) {
        runPatternsFadeToBlack(fadeToBlack);
        incPalettesStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPaletteItemCallExecSecs();
}

unsigned long runTimerCycleByteNum()
{
    incByteNumStep();

    return getLedPatternItemRandHuesMili();
}

void setupCycles()
{
    runTimerCyclePattern(false);
}
