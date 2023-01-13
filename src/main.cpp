
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

    if (PatternPeriodTimer.ready()) {
        PatternPeriodTimer.setPeriodTime(runTimerPattern());
    }

    if (PalettePeriodTimer.ready()) {
        PalettePeriodTimer.setPeriodTime(runTimerPalette());
    }

    if (ByteNumPeriodTimer.ready()) {
        ByteNumPeriodTimer.setPeriodTime(runTimerByteNum());
    }
}

unsigned long runTimerPattern(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle) {
        runPatternsFadeToBlack(fadeToBlack);
        incPatternsStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPatternItemCallExecSecs();
}

unsigned long runTimerPalette(bool fadeToBlack, bool fadeToColor, bool doCycle)
{
    if (doCycle && isLedPaletteStepStarted()) {
        runPatternsFadeToBlack(fadeToBlack);
        incPalettesStep();
        runPatternsStep();
        runPatternsFadeToColor(fadeToColor);
    }

    return getLedPaletteItemCallExecSecs();
}

unsigned long runTimerByteNum()
{
    incByteNumStep();

    return getLedPatternItemRandHuesMili();
}

void setupCycles()
{
    runTimerPattern(false);
}
