
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Patterns.h"

const ledPatternItem ledPatternList[] = {

    { "palette-circle",          runStepPaletteCircle,              nullptr,               LED_STR_SEC_CYCLE * 4, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-circle-t",        runStepPaletteCircleTwinkle,       nullptr,               LED_STR_SEC_CYCLE * 4, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },

    { "rainbow-static",          runStepRainbowStatic,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "rainbow-static-t",        runStepRainbowStaticTwinkle,       nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "rainbow-normal",          runStepRainbowNormal,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "rainbow-normal-t",        runStepRainbowNormalTwinkle,       nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "rainbow-slider-normal",   runStepRainbowSliderNormal,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "rainbow-slider-stripe",   runStepRainbowSliderStripe,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "builder-faster",          runStepBuilderFaster,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "builder-faster-t",        runStepBuilderFasterTwinkle,       nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "builder-normal",          runStepBuilderNormal,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "builder-normal-t",        runStepBuilderNormalTwinkle,       nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-clouds",   runStepSlidingBeaterClouds,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-clouds",   runStepPaletteRoundsClouds,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-clouds-t", runStepPaletteRoundsCloudsTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-magmas",   runStepSlidingBeaterMagmas,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-magmas",   runStepPaletteRoundsMagmas,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-magmas-t", runStepPaletteRoundsMagmasTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-forest",   runStepSlidingBeaterForest,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-forest",   runStepPaletteRoundsForest,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-forest-t", runStepPaletteRoundsForestTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-oceans",   runStepSlidingBeaterOceans,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-oceans",   runStepPaletteRoundsOceans,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-oceans-t", runStepPaletteRoundsOceansTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-random",   runStepSlidingBeaterRandom,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-random",   runStepPaletteRoundsRandom,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-random-t", runStepPaletteRoundsRandomTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "sliding-beater-heater",   runStepSlidingBeaterHeater,        nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },
    { "palette-rounds-heater",   runStepPaletteRoundsHeater,        nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "palette-rounds-heater-t", runStepPaletteRoundsHeaterTwinkle, nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "juggler-faster",          runStepJugglerFaster,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "juggler-faster-t",        runStepJugglerFasterTwinkle,       nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "juggler-longer",          runStepJugglerLonger,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,   0 },
    { "juggler-longer-t",        runStepJugglerLongerTwinkle,       nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },

    { "sinelon-normal",          runStepSinelonNormal,              nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "sinelon-normal-t",        runStepSinelonNormalTwinkle,       nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "colored-static-w",        runStepColoredStaticW,             nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-static-w-t",      runStepColoredStaticWTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-varied-w",        runStepColoredVariedW,             runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-varied-w-t",      runStepColoredVariedWTwinkle,      runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-builds-w",        runStepColoredBuildsW,             nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-w-t",      runStepColoredBuildsWTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "colored-static-r",        runStepColoredStaticR,             nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-static-r-t",      runStepColoredStaticRTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-varied-r",        runStepColoredVariedR,             runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-varied-r-t",      runStepColoredVariedRTwinkle,      runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-builds-r",        runStepColoredBuildsR,             nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-r-t",      runStepColoredBuildsRTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "colored-static-g",        runStepColoredStaticG,             nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-static-g-t",      runStepColoredStaticGTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-varied-g",        runStepColoredVariedG,             runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-varied-g-t",      runStepColoredVariedGTwinkle,      runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-builds-g",        runStepColoredBuildsG,             nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-g-t",      runStepColoredBuildsGTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "colored-static-b",        runStepColoredStaticB,             nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-static-b-t",      runStepColoredStaticBTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-varied-b",        runStepColoredVariedB,             runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  20 },
    { "colored-varied-b-t",      runStepColoredVariedBTwinkle,      runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  60 },
    { "colored-builds-b",        runStepColoredBuildsB,             nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  10 },
    { "colored-builds-b-t",      runStepColoredBuildsBTwinkle,      nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI,  40 },

    { "rainbow-wholed-slow",     runStepRainbowWholed,              nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR * 8, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },
    { "rainbow-wholed-fast",     runStepRainbowWholed,              nullptr,               LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI / 2, LED_PTN_FADE_MILI, 100 },
    { "rainbow-fading-slow",     runStepRainbowFadingSlow,          nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },
    { "rainbow-fading-fast",     runStepRainbowFadingFast,          nullptr,               LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI,     LED_PTN_FADE_MILI, 100 },

};

byte ledPatternIncrByteNumb = 0;
int  ledPatternFadeLeveling = 0;
bool ledPatternStepInit     = false;
bool ledPatternStepRuns     = false;

unsigned int getLedPatternListSize()
{
    static const unsigned int size = ARRAY_SIZE(ledPatternList);

    return size;
}

const ledPatternItem *getLedPatternItemDefault()
{
    static const ledPatternItem defaultPatternItem = {
        "generic",
        runStepGeneric,
        runInitGeneric,
        LED_STR_SEC_CYCLE,
        LED_STR_SEC_COLOR,
        LED_PTN_STEP_MILI,
        LED_PTN_FADE_MILI,
    };

    return &defaultPatternItem;
}

const ledPatternItem *getLedPatternItem(const unsigned int idx)
{
    return idx >= getLedPatternListSize() ? getLedPatternItemDefault() : &(ledPatternList[idx]);
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

void (*getLedPatternItemInit())()
{
    return getLedPatternItem()->init != nullptr
        ? getLedPatternItem()->init
        : getLedPatternItemDefault()->init;
}

void (*getLedPatternItemCall())()
{
    return getLedPatternItem()->call != nullptr
        ? getLedPatternItem()->call
        : getLedPatternItemDefault()->call;
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

void incSelectedStep()
{
    while (true) {
        incLedPatternListStepIndx();

        const unsigned int skip = randByte(100);

        if (!LED_PTN_STEP_SKIP || skip >= getLedPatternItemSkipItemFrac()) {
            break;
        }

        outStepInfo(true, skip);
    }

    getLedPatternItemInit()();

    ledPatternStepInit = true;
    ledPatternStepRuns = false;

    FastLED.show();
    FastLED.delay(getLedPatternItem()->waitLoopMili);

    outStepInfo();
}

void runSelectedStep(const bool wait)
{
    getLedPatternItemCall()();

    ledPatternStepInit = false;
    ledPatternStepRuns = true;

    FastLED.show();
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

void setCustomLedColorsActive()
{
    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandsActiveColors[i] = ledStrandsCustomColors[i];
    }
}

void runStepTwinkle(const byte min, const byte lim, const byte itr)
{
    const byte iterations = randByte(0, itr);

    for (byte i = 0; i < iterations; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] += CRGB(
            randByte(min, lim),
            randByte(min, lim),
            randByte(min, lim)
        );
    }
}

void runInitGeneric()
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB(CRGB::Black));
}

void runStepGeneric()
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB(CRGB::Black));
}

void runStepColoredStatic(const byte r, const byte g, const byte b)
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB(r, g, b));
}

void runStepColoredStaticW()
{
    runStepColoredStatic(140, 140, 140);
}

void runStepColoredStaticR()
{
    runStepColoredStatic(240, 0, 0);
}

void runStepColoredStaticG()
{
    runStepColoredStatic(0, 240, 0);
}

void runStepColoredStaticB()
{
    runStepColoredStatic(0, 0, 240);
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
    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, 3);

    for (byte i = 0; i < LED_STR_NUM/25; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] = CRGB(
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
        ledStrandsCustomColors[i] = CRGB(
            randByte(cstrByte(r - d), cstrByte(r + d)),
            randByte(cstrByte(g - d), cstrByte(g + d)),
            randByte(cstrByte(b - d), cstrByte(b + d))
        );
    }

    setCustomLedColorsActive();
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

void runStepColoredVaried()
{
    setCustomLedColorsActive();
}

void runStepColoredVariedW()
{
    runStepColoredVaried();
}

void runStepColoredVariedR()
{
    runStepColoredVaried();
}

void runStepColoredVariedG()
{
    runStepColoredVaried();
}

void runStepColoredVariedB()
{
    runStepColoredVaried();
}

void runStepColoredVariedTwinkle()
{
    setCustomLedColorsActive();
    runStepTwinkle();
}

void runStepColoredVariedWTwinkle()
{
    runStepColoredVariedTwinkle();
}

void runStepColoredVariedRTwinkle()
{
    runStepColoredVariedTwinkle();
}

void runStepColoredVariedGTwinkle()
{
    runStepColoredVariedTwinkle();
}

void runStepColoredVariedBTwinkle()
{
    runStepColoredVariedTwinkle();
}

void runStepRainbowStatic()
{
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, 1, 7);
}

void runStepRainbowStaticTwinkle()
{
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, 1, 7);
    runStepTwinkle();
}

void runStepRainbowNormal()
{
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, ledPatternIncrByteNumb, 7);
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
    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, 1);

    for (byte i = 0; i < iterations; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] += CHSV(ledPatternIncrByteNumb + randByte(64), 200, 255);
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
    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, 1);

    for (byte i = 0; i < iterations; i++) {
        ledStrandsActiveColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(ledPatternIncrByteNumb, 255, 192);
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
        ledStrandsActiveColors[i] = ColorFromPalette(palette, ledPatternIncrByteNumb + (i * 2), beat - ledPatternIncrByteNumb + (i * 10));
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

void runStepPaletteRounds(const CRGBPalette16 palette, const int multiplier, const bool blend)
{
    for (int i = 0; i < LED_STR_NUM; i++) {
        ledStrandsActiveColors[i] = ColorFromPalette(
            palette,
            ledPatternIncrByteNumb + (i * multiplier),
            255,
            blend ? LINEARBLEND : NOBLEND
        );
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
    runStepTwinkle();
}

void runStepJuggler(const byte fade)
{
    byte dothue = 0;

    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, fade);

    for (int i = 0; i < 12; i++) {
        ledStrandsActiveColors[beatsin16(i + randByte(5, 10), 0, LED_STR_NUM - 1)] |= CHSV(dothue, 200, 255);
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
    byte hue = sin8(ledPatternIncrByteNumb);

    fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hue, 255, 255), CHSV(hue, 255, 255), FORWARD_HUES);
}

void runStepGradingStable(byte hueBeg, byte hueEnd)
{
    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}

void runStepRainbowFading(const byte bmp1, const byte bpm2)
{
    byte hueBeg = beatsin8(bmp1, 0, 255);
    byte hueEnd = beatsin8(bpm2, 0, 255);

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), BACKWARD_HUES);
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
    byte hueBeg = ledPatternIncrByteNumb;
    byte hueEnd = ledPatternIncrByteNumb + 64;

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}
