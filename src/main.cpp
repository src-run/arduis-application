
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
    setupRunner();
}

void loop()
{
    runPatternsStep();

    if (PatternTimer.ready()) {
        PatternTimer.setPeriodFromSecs(timerCyclePattern());
    }

    if (PaletteTimer.ready()) {
        PaletteTimer.setPeriodFromSecs(timerCyclePalette());
    }

    if (ByteNumTimer.ready()) {
        ByteNumTimer.setPeriodFromMili(timerCycleByteNum());
    }
}

unsigned int timerCyclePattern(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle) {
        runPatternsFadeToBlack(fadeToBlack);
        incPatternsStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPatternItemCallExecSecs();
}

unsigned int timerCyclePalette(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle && isLedPaletteStepStarted()) {
        runPatternsFadeToBlack(fadeToBlack);
        incPalettesStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPaletteItemCallExecSecs();
}

unsigned long timerCycleByteNum()
{
    incByteNumStep();

    return getLedPatternItemRandHuesMili();
}

void setupCycles()
{
    timerCyclePattern(false);
}
