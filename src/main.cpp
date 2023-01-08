
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
    initializeSystem();
    initializeSerial();
    initializeRandom();
    initializeStrand();
    initializeRelays();
    initializeRunner();
}

void loop()
{
    runSelectedStep();

    if (cyclePaletteMillisTimeRunner.ready()) {
        cyclePaletteMillisTimeRunner.setPeriod(getLedPaletteItemCallExecMili());
        Serial.println("cyclePalette(" + String(cyclePaletteMillisTimeRunner.getPeriod()) + "," + String(cyclePaletteMillisTimeRunner.getElapsed()) + "," + String(cyclePaletteMillisTimeRunner.getRemaining()) + ")");
        cyclePalette();
    }

    if (cyclePatternMillisTimeRunner.ready()) {
        cyclePatternMillisTimeRunner.setPeriod(getLedPatternItemCallExecMili());
        Serial.println("cyclePattern(" + String(cyclePatternMillisTimeRunner.getPeriod()) + "," + String(cyclePatternMillisTimeRunner.getElapsed()) + "," + String(cyclePatternMillisTimeRunner.getRemaining()) + ")");
        cyclePattern();
    }

    if (cycleByteNumMillisTimeRunner.ready()) {
        cycleByteNumMillisTimeRunner.setPeriod(getLedPatternItemRandHuesMili());
        cycleRandHue();
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
    ledPatternIncrByteNumb++;
}
