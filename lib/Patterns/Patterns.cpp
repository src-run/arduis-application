
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Patterns.h"
#include "stdio.h"

const ledPatternItem ledPatternList[] = {

    { "rainbow-wholed-slow",     runStepRainbowWholed,              runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR * 8, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },
    { "rainbow-wholed-fast",     runStepRainbowWholed,              runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI / 2, LED_PTN_FADE_MILI, 100 },
    { "rainbow-fading-slow",     runStepRainbowFadingSlow,          runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },
    { "rainbow-fading-fast",     runStepRainbowFadingFast,          runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },

    { "palette-circle",          runStepPaletteCircle,              runInitGeneric,        LED_STR_SEC_CYCLE * 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "palette-circle-t",        runStepPaletteCircleTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE * 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "rainbow-static",          runStepRainbowStatic,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "rainbow-static-t",        runStepRainbowStaticTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "rainbow-normal",          runStepRainbowNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "rainbow-normal-t",        runStepRainbowNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "rainbow-slider-normal",   runStepRainbowSliderNormal,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "rainbow-slider-stripe",   runStepRainbowSliderStripe,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "builder-faster",          runStepBuilderFaster,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "builder-faster-t",        runStepBuilderFasterTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "builder-normal",          runStepBuilderNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "builder-normal-t",        runStepBuilderNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-clouds",   runStepSlidingBeaterClouds,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-clouds",   runStepPaletteRoundsClouds,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-clouds-t", runStepPaletteRoundsCloudsTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-magmas",   runStepSlidingBeaterMagmas,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-magmas",   runStepPaletteRoundsMagmas,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-magmas-t", runStepPaletteRoundsMagmasTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-forest",   runStepSlidingBeaterForest,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-forest",   runStepPaletteRoundsForest,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-forest-t", runStepPaletteRoundsForestTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-oceans",   runStepSlidingBeaterOceans,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-oceans",   runStepPaletteRoundsOceans,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-oceans-t", runStepPaletteRoundsOceansTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-random",   runStepSlidingBeaterRandom,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-random",   runStepPaletteRoundsRandom,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-random-t", runStepPaletteRoundsRandomTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "sliding-beater-heater",   runStepSlidingBeaterHeater,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },
    { "palette-rounds-heater",   runStepPaletteRoundsHeater,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "palette-rounds-heater-t", runStepPaletteRoundsHeaterTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "juggler-faster",          runStepJugglerFaster,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "juggler-faster-t",        runStepJugglerFasterTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "juggler-longer",          runStepJugglerLonger,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "juggler-longer-t",        runStepJugglerLongerTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },

    { "sinelon-normal",          runStepSinelonNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "sinelon-normal-t",        runStepSinelonNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "colored-static-w",        runStepHoldingColors,              runInitColoredStaticW, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-static-w-t",      runStepColoredStaticWTwinkle,      runInitColoredStaticW, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-varied-w",        runStepHoldingColors,              runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-varied-w-t",      runStepColoredVariedWTwinkle,      runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-builds-w",        runStepColoredBuildsW,             runInitColoredStaticW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-w-t",      runStepColoredBuildsWTwinkle,      runInitColoredStaticW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "colored-static-r",        runStepHoldingColors,              runInitColoredStaticR, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-static-r-t",      runStepColoredStaticRTwinkle,      runInitColoredStaticR, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-varied-r",        runStepHoldingColors,              runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-varied-r-t",      runStepColoredVariedRTwinkle,      runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-builds-r",        runStepColoredBuildsR,             runInitColoredStaticR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-r-t",      runStepColoredBuildsRTwinkle,      runInitColoredStaticR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "colored-static-g",        runStepHoldingColors,              runInitColoredStaticG, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-static-g-t",      runStepColoredStaticGTwinkle,      runInitColoredStaticG, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-varied-g",        runStepHoldingColors,              runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-varied-g-t",      runStepColoredVariedGTwinkle,      runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-builds-g",        runStepColoredBuildsG,             runInitColoredStaticG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-g-t",      runStepColoredBuildsGTwinkle,      runInitColoredStaticG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

    { "colored-static-b",        runStepHoldingColors,              runInitColoredStaticB, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-static-b-t",      runStepColoredStaticBTwinkle,      runInitColoredStaticB, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-varied-b",        runStepHoldingColors,              runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  25 },
    { "colored-varied-b-t",      runStepColoredVariedBTwinkle,      runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  75 },
    { "colored-builds-b",        runStepColoredBuildsB,             runInitColoredStaticB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-b-t",      runStepColoredBuildsBTwinkle,      runInitColoredStaticB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  50 },

};

byte ledPatternBaseColorHue = 0;
int  ledPatternFadeLeveling = 0;
bool ledPatternStepInit     = false;
bool ledPatternStepRuns     = false;

unsigned int getLedPatternListSize()
{
    static const unsigned int size = ARRAY_SIZE(ledPatternList);

    return size;
}

const ledPatternItem *getLedPatternItem(const unsigned int idx)
{
    static const ledPatternItem def = {
        "generic",
        runStepGeneric,
        runInitGeneric,
        LED_STR_SEC_CYCLE,
        LED_STR_SEC_COLOR,
        LED_PTN_STEP_MILI,
        LED_PTN_FADE_MILI,
    };

    return idx >= getLedPatternListSize() ? &def : &ledPatternList[idx];
}

const ledPatternItem *getLedPatternItem()
{
    return getLedPatternItem(getLedPatternListStepIndx());
}

String getLedPatternItemName(const unsigned int idx)
{
    return getLedPatternItem(idx)->name;
}

String getLedPatternItemName()
{
    return getLedPatternItem()->name;
}

unsigned long getLedPatternItemCallExecMili()
{
    return getLedPatternItem()->callExecMili;
}

unsigned long getLedPatternItemRandHuesMili()
{
    return getLedPatternItem()->randHuesMili;
}

unsigned long getLedPatternItemWaitLoopMili()
{
    return getLedPatternItem()->waitLoopMili;
}

unsigned long getLedPatternItemWaitFadeMili()
{
    return getLedPatternItem()->waitFadeMili;
}

unsigned int getLedPatternItemSkipItemFrac()
{
    return getLedPatternItem()->skipItemFrac;
}

unsigned int getLedPatternListRandIndx()
{
    return getRandomIndx(getLedPatternListSize());
}

unsigned int getLedPatternListStepInit()
{
    return LED_PTN_STEP_RAND ? getLedPatternListRandIndx() : 0;
}

unsigned int getLedPatternListStepNext(const unsigned int idx)
{
    return LED_PTN_STEP_RAND ? getLedPatternListRandIndx() : ((idx + 1) % getLedPatternListSize());
}

unsigned int getLedPatternListStepIndx(const bool inc)
{
    static unsigned int idx = getLedPatternListStepInit();
    static bool         beg = false;

    if (beg && inc == true) {
        idx = getLedPatternListStepNext(idx);
    }

    beg = true;

    return idx;
}

unsigned int incLedPatternListStepIndx()
{
    return getLedPatternListStepIndx(true);
}

unsigned int getLedPatternListStepNumb()
{
    return getLedPatternListStepIndx() + 1;
}

void incSelectedStep(const bool fade)
{
    addRandomEntr();

    while (true) {
        const unsigned int skip = randByte(100);

        incLedPatternListStepIndx();

        if (skip >= getLedPatternItemSkipItemFrac()) {
            break;
        }

        outStepInfo(true, skip);
    }

    if (getLedPatternItem()->init != nullptr) {
        ledPatternStepInit = true;
        ledPatternStepRuns = false;
        getLedPatternItem()->init();
        FastLED.show();
    }

    if (!fade) {
        FastLED.setBrightness(LED_STR_BRT);
    }

    outStepInfo();
}

void runSelectedStep(const bool wait)
{
    if (getLedPatternItem()->call != nullptr) {
        ledPatternStepInit = false;
        ledPatternStepRuns = true;
        getLedPatternItem()->call();
        FastLED.show();
    }

    FastLED.delay(wait ? getLedPatternItem()->waitLoopMili : 0);
}

bool runSelectedStepFadeInit(const int increment)
{
    if (ledPatternFadeLeveling <= LED_STR_BRT) {
        ledPatternFadeLeveling = ledPatternFadeLeveling + increment;
    }

    FastLED.setBrightness(ledPatternFadeLeveling <= LED_STR_BRT ? ledPatternFadeLeveling : LED_STR_BRT);
    FastLED.delay(getLedPatternItem()->waitFadeMili);

    return ledPatternFadeLeveling <= LED_STR_BRT;
}

bool runSelectedStepFadeEnds(const int decrement)
{
    if (ledPatternFadeLeveling > 0) {
        ledPatternFadeLeveling = ledPatternFadeLeveling - decrement;
    }

    FastLED.setBrightness(ledPatternFadeLeveling >= 0 ? ledPatternFadeLeveling : 0);
    FastLED.delay(getLedPatternItem()->waitFadeMili);

    if (ledPatternFadeLeveling == 0) {
        FastLED.delay(LED_PTN_NEXT_MILI);
    }

    return ledPatternFadeLeveling > 0;
}

void setHoldColoursActive()
{
    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandUsedColors[i] = ledStrandHeldColors[i];
    }
}

void runStepHoldingColors()
{
    setHoldColoursActive();
}

void runStepTwinkle(const byte inc, const byte max, const byte min)
{
    const byte iterations = randByte(0, inc);

    for (byte i = 0; i < iterations; i++) {
        ledStrandUsedColors[randUInt(LED_STR_NUM)] += CRGB(
            randByte(min, max),
            randByte(min, max),
            randByte(min, max)
        );
    }
}

void runInitGeneric()
{
    fill_solid(ledStrandUsedColors, LED_STR_NUM, CRGB(0, 0, 0));
}

void runStepGeneric()
{
    fill_solid(ledStrandUsedColors, LED_STR_NUM, CRGB(0, 0, 0));
}

void runInitColoredStatic(const byte r, const byte g, const byte b)
{
    auto color = CRGB(r, g, b);

    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandHeldColors[i] = color;
    }

    setHoldColoursActive();
}

void runInitColoredStaticW()
{
    runInitColoredStatic(140, 140, 140);
}

void runInitColoredStaticR()
{
    runInitColoredStatic(240, 0, 0);
}

void runInitColoredStaticG()
{
    runInitColoredStatic(0, 240, 0);
}

void runInitColoredStaticB()
{
    runInitColoredStatic(0, 0, 240);
}

void runStepColoredStatic(const byte r, const byte g, const byte b)
{
    runInitColoredStatic(r, g, b);
}

void runStepColoredStaticW()
{
    runInitColoredStaticW();
}

void runStepColoredStaticR()
{
    runInitColoredStaticR();
}

void runStepColoredStaticG()
{
    runInitColoredStaticG();
}

void runStepColoredStaticB()
{
    runInitColoredStaticB();
}

void runStepColoredStaticWTwinkle()
{
    runStepColoredStaticW();
    runStepTwinkle();
}

void runStepColoredStaticRTwinkle()
{
    runStepColoredStaticR();
    runStepTwinkle();
}

void runStepColoredStaticGTwinkle()
{
    runStepColoredStaticG();
    runStepTwinkle();
}

void runStepColoredStaticBTwinkle()
{
    runStepColoredStaticB();
    runStepTwinkle();
}

void runStepColoredBuilds(const byte r, const byte g, const byte b, const byte d)
{
    fadeToBlackBy(ledStrandUsedColors, LED_STR_NUM, 3);

    for (byte i = 0; i < LED_STR_NUM/25; i++) {
        ledStrandUsedColors[randUInt(LED_STR_NUM)] = CRGB(
            r == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(r - d), cstrByte(r + d)),
            g == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(g - d), cstrByte(g + d)),
            b == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(b - d), cstrByte(b + d))
        );
    }
}

void runStepColoredBuildsW()
{
    runStepColoredBuilds(140, 140, 140);
}

void runStepColoredBuildsR()
{
    runStepColoredBuilds(220, 0, 0);
}

void runStepColoredBuildsG()
{
    runStepColoredBuilds(0, 220, 0);
}

void runStepColoredBuildsB()
{
    runStepColoredBuilds(0, 0, 220);
}

void runStepColoredBuildsWTwinkle()
{
    runStepColoredBuildsW();
    runStepTwinkle();
}

void runStepColoredBuildsRTwinkle()
{
    runStepColoredBuildsR();
    runStepTwinkle();
}

void runStepColoredBuildsGTwinkle()
{
    runStepColoredBuildsG();
    runStepTwinkle();
}

void runStepColoredBuildsBTwinkle()
{
    runStepColoredBuildsB();
    runStepTwinkle();
}

void runInitColoredVaried(const byte r, const byte g, const byte b, const byte d)
{
    runInitGeneric();

    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandHeldColors[i] = CRGB(
            randByte(cstrByte(r - d), cstrByte(r + d)),
            randByte(cstrByte(g - d), cstrByte(g + d)),
            randByte(cstrByte(b - d), cstrByte(b + d))
        );
    }

    setHoldColoursActive();
}

void runInitColoredVariedW()
{
    runInitColoredVaried(140, 140, 140, 60);
}

void runInitColoredVariedR()
{
    runInitColoredVaried(220, 0, 0);
}

void runInitColoredVariedG()
{
    runInitColoredVaried(0, 220, 0);
}

void runInitColoredVariedB()
{
    runInitColoredVaried(0, 0, 220);
}

void runStepColoredVariedWTwinkle()
{
    setHoldColoursActive();
    runStepTwinkle();
}

void runStepColoredVariedRTwinkle()
{
    setHoldColoursActive();
    runStepTwinkle();
}

void runStepColoredVariedGTwinkle()
{
    setHoldColoursActive();
    runStepTwinkle();
}

void runStepColoredVariedBTwinkle()
{
    setHoldColoursActive();
    runStepTwinkle();
}

void runStepRainbowStatic()
{
    fill_rainbow(ledStrandUsedColors, LED_STR_NUM, 1, 7);
}

void runStepRainbowStaticTwinkle()
{
    fill_rainbow(ledStrandUsedColors, LED_STR_NUM, 1, 7);
    runStepTwinkle();
}

void runStepRainbowNormal()
{
    fill_rainbow(ledStrandUsedColors, LED_STR_NUM, ledPatternBaseColorHue, 7);
}

void runStepRainbowNormalTwinkle()
{
    runStepRainbowNormal();
    runStepTwinkle();
}

void runStepRainbowSliderNormal()
{
    runStepSlidingBeater(RainbowColors_p);
}

void runStepRainbowSliderStripe()
{
    runStepSlidingBeater(RainbowStripeColors_p);
}

void runStepBuilder(const byte iterations)
{
    fadeToBlackBy(ledStrandUsedColors, LED_STR_NUM, 1);

    for (byte i = 0; i < iterations; i++) {
        ledStrandUsedColors[randUInt(LED_STR_NUM)] += CHSV(ledPatternBaseColorHue + randByte(64), 200, 255);
    }
}

void runStepBuilderNormal()
{
    runStepBuilder(3);
}

void runStepBuilderNormalTwinkle()
{
    runStepBuilderNormal();
    runStepTwinkle();
}

void runStepBuilderFaster()
{
    runStepBuilder(6);
}

void runStepBuilderFasterTwinkle()
{
    runStepBuilderFaster();
    runStepTwinkle();
}

void runStepSinelon(const byte iterations)
{
    fadeToBlackBy(ledStrandUsedColors, LED_STR_NUM, 1);

    for (byte i = 0; i < iterations; i++) {
        ledStrandUsedColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(ledPatternBaseColorHue, 255, 192);
    }
}

void runStepSinelonNormal()
{
    runStepSinelon(12);
}

void runStepSinelonNormalTwinkle()
{
    runStepSinelon(12);
    runStepTwinkle();
}

void runStepSlidingBeater(const CRGBPalette16 palette, const byte time)
{
    byte beat = beatsin8(time, 64, 180);

    for (int i = 0; i < LED_STR_NUM; i++) {
        ledStrandUsedColors[i] = ColorFromPalette(palette, ledPatternBaseColorHue + (i * 2), beat - ledPatternBaseColorHue + (i * 10));
    }
}

void runStepSlidingBeaterClouds()
{
    runStepSlidingBeater(CloudColors_p);
}

void runStepSlidingBeaterMagmas()
{
    runStepSlidingBeater(LavaColors_p);
}

void runStepSlidingBeaterOceans()
{
    runStepSlidingBeater(OceanColors_p);
}

void runStepSlidingBeaterForest()
{
    runStepSlidingBeater(ForestColors_p);
}

void runStepSlidingBeaterRandom()
{
    runStepSlidingBeater(PartyColors_p);
}

void runStepSlidingBeaterHeater()
{
    runStepSlidingBeater(HeatColors_p);
}

void runStepPaletteRounds(const CRGBPalette16 palette)
{
    for (int i = 0; i < LED_STR_NUM; i++) {
        ledStrandUsedColors[i] = ColorFromPalette(palette, ledPatternBaseColorHue + (i * 2), 255, LINEARBLEND);
    }
}

void runStepPaletteRoundsClouds()
{
    runStepPaletteRounds(CloudColors_p);
}

void runStepPaletteRoundsMagmas()
{
    runStepPaletteRounds(LavaColors_p);
}

void runStepPaletteRoundsOceans()
{
    runStepPaletteRounds(OceanColors_p);
}

void runStepPaletteRoundsForest()
{
    runStepPaletteRounds(ForestColors_p);
}

void runStepPaletteRoundsRandom()
{
    runStepPaletteRounds(PartyColors_p);
}

void runStepPaletteRoundsHeater()
{
    runStepPaletteRounds(HeatColors_p);
}

void runStepPaletteRoundsCloudsTwinkle()
{
    runStepPaletteRoundsClouds();
    runStepTwinkle();
}

void runStepPaletteRoundsMagmasTwinkle()
{
    runStepPaletteRoundsMagmas();
    runStepTwinkle();
}

void runStepPaletteRoundsOceansTwinkle()
{
    runStepPaletteRoundsOceans();
    runStepTwinkle();
}

void runStepPaletteRoundsForestTwinkle()
{
    runStepPaletteRoundsForest();
    runStepTwinkle();
}

void runStepPaletteRoundsRandomTwinkle()
{
    runStepPaletteRoundsRandom();
    runStepTwinkle();
}

void runStepPaletteRoundsHeaterTwinkle()
{
    runStepPaletteRoundsHeater();
    runStepTwinkle();
}

void runStepPaletteCircle()
{
    runStepPaletteRounds(getLedPaletteItemComp());
}

void runStepPaletteCircleTwinkle()
{
    runStepPaletteCircle();
    runStepTwinkle(4, 0, 80);
}

void runStepJuggler(const byte fade)
{
    byte dothue = 0;

    fadeToBlackBy(ledStrandUsedColors, LED_STR_NUM, fade);

    for (int i = 0; i < 12; i++) {
        ledStrandUsedColors[beatsin16(i + randByte(5, 10), 0, LED_STR_NUM - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void runStepJugglerFaster()
{
    runStepJuggler(24);
}

void runStepJugglerFasterTwinkle()
{
    runStepJugglerFaster();
    runStepTwinkle();
}

void runStepJugglerLonger()
{
    runStepJuggler(8);
}

void runStepJugglerLongerTwinkle()
{
    runStepJugglerLonger();
    runStepTwinkle();
}

void runStepColoredGradedeeeeeeee()
{
    byte hue = sin8(ledPatternBaseColorHue);

    fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hue, 255, 255), CHSV(hue, 255, 255), FORWARD_HUES);
}

void runStepGradingStable(byte hueBeg, byte hueEnd)
{
    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}

void runStepRainbowFading(const byte bmp1, const byte bpm2)
{
    byte hueBeg = beatsin8(bmp1, 0, 255);
    byte hueEnd = beatsin8(bpm2, 0, 255);

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), BACKWARD_HUES);
    }
}

void runStepRainbowFadingSlow()
{
    runStepRainbowFading(1, 2);
}

void runStepRainbowFadingFast()
{
    runStepRainbowFading(5, 7);
}

void runStepRainbowWholed()
{
    byte hueBeg = ledPatternBaseColorHue;
    byte hueEnd = ledPatternBaseColorHue + 64;

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandUsedColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}
