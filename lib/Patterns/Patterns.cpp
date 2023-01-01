
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

const ledPatternListEntry ledPatternList[] = {

//    { "rainbow-wholed-slow",     runStepRainbowWholed,              runInitGeneric,        LED_STR_SEC_CYCLE / 6,     LED_STR_SEC_COLOR * 8, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
//    { "rainbow-wholed-fast",     runStepRainbowWholed,              runInitGeneric,        LED_STR_SEC_CYCLE / 6,     LED_STR_SEC_COLOR / 6,     LED_PTN_STEP_MILI / 2, LED_PTN_FADE_MILI },
//    { "rainbow-fading-slow",     runStepRainbowFadingSlow,          runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
//    { "rainbow-fading-fast",     runStepRainbowFadingFast,          runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "palette-circle",          runStepPaletteCircle,              runInitGeneric,        LED_STR_SEC_CYCLE * 4, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "rainbow-static",          runStepRainbowStatic,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-static-t",        runStepRainbowStaticTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-normal",          runStepRainbowNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-normal-t",        runStepRainbowNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "rainbow-slider-normal",   runStepRainbowSliderNormal,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-slider-stripe",   runStepRainbowSliderStripe,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "builder-normal",          runStepBuilderNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-normal-t",        runStepBuilderNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-faster",          runStepBuilderFaster,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-faster-t",        runStepBuilderFasterTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-clouds",   runStepSlidingBeaterClouds,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-clouds",   runStepPaletteRoundsClouds,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-clouds-t", runStepPaletteRoundsCloudsTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-magmas",   runStepSlidingBeaterMagmas,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-magmas",   runStepPaletteRoundsMagmas,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-magmas-t", runStepPaletteRoundsMagmasTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-forest",   runStepSlidingBeaterForest,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-forest",   runStepPaletteRoundsForest,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-forest-t", runStepPaletteRoundsForestTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-oceans",   runStepSlidingBeaterOceans,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-oceans",   runStepPaletteRoundsOceans,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-oceans-t", runStepPaletteRoundsOceansTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-random",   runStepSlidingBeaterRandom,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-random",   runStepPaletteRoundsRandom,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-random-t", runStepPaletteRoundsRandomTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-heater",   runStepSlidingBeaterHeater,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-heater",   runStepPaletteRoundsHeater,        runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "palette-rounds-heater-t", runStepPaletteRoundsHeaterTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "juggler-faster",          runStepJugglerFaster,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-faster-t",        runStepJugglerFasterTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-longer",          runStepJugglerLonger,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-longer-t",        runStepJugglerLongerTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sinelon-normal",          runStepSinelonNormal,              runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sinelon-normal-t",        runStepSinelonNormalTwinkle,       runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-w",        runStepHoldingColors,              runInitColoredStaticW, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-w-t",      runStepColoredStaticWTwinkle,      runInitColoredStaticW, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-w",        runStepHoldingColors,              runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-w-t",      runStepColoredVariedWTwinkle,      runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-w",        runStepColoredBuildsW,             runInitColoredStaticW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-w-t",      runStepColoredBuildsWTwinkle,      runInitColoredStaticW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-r",        runStepHoldingColors,              runInitColoredStaticR, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-r-t",      runStepColoredStaticRTwinkle,      runInitColoredStaticR, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-r",        runStepHoldingColors,              runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-r-t",      runStepColoredVariedRTwinkle,      runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-r",        runStepColoredBuildsR,             runInitColoredStaticR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-r-t",      runStepColoredBuildsRTwinkle,      runInitColoredStaticR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-g",        runStepHoldingColors,              runInitColoredStaticG, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-g-t",      runStepColoredStaticGTwinkle,      runInitColoredStaticG, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-g",        runStepHoldingColors,              runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-g-t",      runStepColoredVariedGTwinkle,      runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-g",        runStepColoredBuildsG,             runInitColoredStaticG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-g-t",      runStepColoredBuildsGTwinkle,      runInitColoredStaticG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-b",        runStepHoldingColors,              runInitColoredStaticB, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-b-t",      runStepColoredStaticBTwinkle,      runInitColoredStaticB, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-b",        runStepHoldingColors,              runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-b-t",      runStepColoredVariedBTwinkle,      runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-b",        runStepColoredBuildsB,             runInitColoredStaticB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-b-t",      runStepColoredBuildsBTwinkle,      runInitColoredStaticB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

};

const uint16_t ledPatternSize = ARRAY_SIZE(ledPatternList);
uint8_t  ledPatternBaseColorHue = 0;
int16_t  ledPatternFadeLeveling = 0;
int16_t  ledPatternCallRefIndex = -1;
CRGB     ledStrandHoldColors[];

int16_t getRandRefIndex()
{
    return random16(0, ARRAY_SIZE(ledPatternList) - 1);
}

void incSelectedStep(bool fade)
{
    setRandom16Seed();

    if (ledPatternCallRefIndex == -1 && LED_PTN_INIT_RAND) {
        ledPatternCallRefIndex = getRandRefIndex();
    }

    ledPatternCallRefIndex = (ledPatternCallRefIndex + 1) % ARRAY_SIZE(ledPatternList);

    if (ledPatternList[ledPatternCallRefIndex].init != nullptr) {
        ledPatternList[ledPatternCallRefIndex].init();
        FastLED.show();
    }

    if (!fade) {
        FastLED.setBrightness(LED_STR_BRT);
    }

    outStepInfo();
}

void runSelectedStep(bool wait)
{
    if (ledPatternList[ledPatternCallRefIndex].call != nullptr) {
        ledPatternList[ledPatternCallRefIndex].call();
        FastLED.show();
    }

    FastLED.delay(wait ? ledPatternList[ledPatternCallRefIndex].waitLoopMili : 0);
}

bool runSelectedStepFadeInit(int increment)
{
    if (ledPatternFadeLeveling <= LED_STR_BRT) {
        ledPatternFadeLeveling = ledPatternFadeLeveling + increment;
    }

    FastLED.setBrightness(ledPatternFadeLeveling <= LED_STR_BRT ? ledPatternFadeLeveling : LED_STR_BRT);
    FastLED.delay(ledPatternList[ledPatternCallRefIndex].waitFadeMili);

    return ledPatternFadeLeveling <= LED_STR_BRT;
}

bool runSelectedStepFadeEnds(int decrement)
{
    if (ledPatternFadeLeveling > 0) {
        ledPatternFadeLeveling = ledPatternFadeLeveling - decrement;
    }

    FastLED.setBrightness(ledPatternFadeLeveling >= 0 ? ledPatternFadeLeveling : 0);
    FastLED.delay(ledPatternList[ledPatternCallRefIndex].waitFadeMili);

    if (ledPatternFadeLeveling == 0) {
        FastLED.delay(LED_PTN_NEXT_MILI);
    }

    return ledPatternFadeLeveling > 0;
}

void setHoldColoursActive()
{
    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandColors[i] = ledStrandHoldColors[i];
    }
}

void runStepHoldingColors()
{
    setHoldColoursActive();
}

void runStepTwinkle(uint8_t level, fract8 chance, uint8_t iterations)
{
    // TODO: RE-ENABLE AFTER DEBUGGING FLASHING ISSUE
    return;

    iterations = random8(0, iterations);

    for (uint8_t i = 0; i < iterations; i++) {
        ledStrandColors[random16(LED_STR_NUM)] += CRGB(random8(level), random8(level), random8(level));
    }
}

void runInitGeneric()
{
    fill_solid(ledStrandColors, LED_STR_NUM, CRGB(0, 0, 0));
}

void runInitColoredStatic(uint8_t r, uint8_t g, uint8_t b)
{
    auto color = CRGB(r, g, b);

    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandHoldColors[i] = color;
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

void runStepColoredStatic(uint8_t r, uint8_t g, uint8_t b)
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

void runStepColoredBuilds(uint8_t r, uint8_t g, uint8_t b, uint8_t d)
{
    fadeToBlackBy(ledStrandColors, LED_STR_NUM, 3);

    for (uint8_t i = 0; i < LED_STR_NUM/25; i++) {
        ledStrandColors[random16(LED_STR_NUM)] = CRGB(
            r == 0 ? random8(0, maxInt8(d * 4)) : random8(minInt8(r - d), maxInt8(r + d)),
            g == 0 ? random8(0, maxInt8(d * 4)) : random8(minInt8(g - d), maxInt8(g + d)),
            b == 0 ? random8(0, maxInt8(d * 4)) : random8(minInt8(b - d), maxInt8(b + d))
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

void runInitColoredVaried(uint8_t r, uint8_t g, uint8_t b, uint8_t d)
{
    runInitGeneric();

    for (int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandHoldColors[i] = CRGB(
            random8(minInt8(r - d), maxInt8(r + d)),
            random8(minInt8(g - d), maxInt8(g + d)),
            random8(minInt8(b - d), maxInt8(b + d))
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
    fill_rainbow(ledStrandColors, LED_STR_NUM, 1, 7);
}

void runStepRainbowStaticTwinkle()
{
    fill_rainbow(ledStrandColors, LED_STR_NUM, 1, 7);
    runStepTwinkle();
}

void runStepRainbowNormal()
{
    fill_rainbow(ledStrandColors, LED_STR_NUM, ledPatternBaseColorHue, 7);
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

void runStepBuilder(uint8_t iterations)
{
    fadeToBlackBy(ledStrandColors, LED_STR_NUM, 1);

    for (uint8_t i = 0; i < iterations; i++) {
        ledStrandColors[random16(LED_STR_NUM)] += CHSV(ledPatternBaseColorHue + random8(64), 200, 255);
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

void runStepSinelon(uint8_t iterations)
{
    fadeToBlackBy(ledStrandColors, LED_STR_NUM, 1);

    for (uint8_t i = 0; i < iterations; i++) {
        ledStrandColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(ledPatternBaseColorHue, 255, 192);
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

void runStepSlidingBeater(CRGBPalette16 palette, uint8_t time)
{
    uint8_t beat = beatsin8(time, 64, 180);

    for (int i = 0; i < LED_STR_NUM; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledPatternBaseColorHue + (i * 2), beat - ledPatternBaseColorHue + (i * 10));
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

void runStepPaletteRounds(CRGBPalette16 palette)
{
    for (int i = 0; i < LED_STR_NUM; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledPatternBaseColorHue + (i * 2), 255, LINEARBLEND);
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
    runStepPaletteRounds(getLedPaletteStep());
}

void runStepJuggler(uint8_t fade) {
    byte dothue = 0;

    fadeToBlackBy(ledStrandColors, LED_STR_NUM, fade);

    for (int i = 0; i < 12; i++) {
        ledStrandColors[beatsin16(i + random8(5, 10), 0, LED_STR_NUM - 1)] |= CHSV(dothue, 200, 255);
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
    uint8_t hue = sin8(ledPatternBaseColorHue);

    fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hue, 255, 255), CHSV(hue, 255, 255), FORWARD_HUES);
}

void runStepGradingStable(uint8_t hueBeg, uint8_t hueEnd)
{
    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}

void runStepRainbowFading(uint8_t bmp1, uint8_t bpm2)
{
    uint8_t hueBeg = beatsin8(bmp1, 0, 255);
    uint8_t hueEnd = beatsin8(bpm2, 0, 255);

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), BACKWARD_HUES);
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
    uint8_t hueBeg = ledPatternBaseColorHue;
    uint8_t hueEnd = ledPatternBaseColorHue + 64;

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}
