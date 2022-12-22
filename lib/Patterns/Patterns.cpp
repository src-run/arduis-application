
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
#include "math.h"

ledChainListEntry ledChainList[] = {

    { "colored-static-w",         runStepHoldingColors,         runInitColoredStaticW, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-w-twinkle", runStepColoredStaticWTwinkle, runInitColoredStaticW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-w",         runStepHoldingColors,         runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-w-twinkle", runStepColoredVariedWTwinkle, runInitColoredVariedW, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-w",         runStepColoredBuildsW,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-w-twinkle", runStepColoredBuildsWTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-r",         runStepHoldingColors,         runInitColoredStaticR, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-r-twinkle", runStepColoredStaticRTwinkle, runInitColoredStaticR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-r",         runStepHoldingColors,         runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-r-twinkle", runStepColoredVariedRTwinkle, runInitColoredVariedR, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-r",         runStepColoredBuildsR,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-r-twinkle", runStepColoredBuildsRTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-g",         runStepHoldingColors,         runInitColoredStaticG, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-g-twinkle", runStepColoredStaticGTwinkle, runInitColoredStaticG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-g",         runStepHoldingColors,         runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-g-twinkle", runStepColoredVariedGTwinkle, runInitColoredVariedG, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-g",         runStepColoredBuildsG,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-g-twinkle", runStepColoredBuildsGTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "colored-static-b",         runStepHoldingColors,         runInitColoredStaticB, LED_STR_SEC_CYCLE / 3, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-static-b-twinkle", runStepColoredStaticBTwinkle, runInitColoredStaticB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-b",         runStepHoldingColors,         runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-varied-b-twinkle", runStepColoredVariedBTwinkle, runInitColoredVariedB, LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-b",         runStepColoredBuildsB,        runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "colored-builds-b-twinkle", runStepColoredBuildsBTwinkle, runInitGeneric,        LED_STR_SEC_CYCLE / 2, LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "rainbow-static",           runStepRainbowStatic,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-static-twinkle",   runStepRainbowStaticTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-normal",           runStepRainbowNormal,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-normal-twinkle",   runStepRainbowNormalTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "rainbow-slider-normal",    runStepRainbowSliderNormal,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "rainbow-slider-stripe",    runStepRainbowSliderStripe,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "builder-normal",           runStepBuilderNormal,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-normal-twinkle",   runStepBuilderNormalTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-faster",           runStepBuilderFaster,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "builder-faster-twinkle",   runStepBuilderFasterTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sliding-beater-clouds",    runStepSlidingBeaterClouds,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sliding-beater-magmas",    runStepSlidingBeaterMagmas,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sliding-beater-forest",    runStepSlidingBeaterForest,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sliding-beater-oceans",    runStepSlidingBeaterOceans,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sliding-beater-random",    runStepSlidingBeaterRandom,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sliding-beater-heater",    runStepSlidingBeaterHeater,   runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "juggler-faster",           runStepJugglerFaster,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-faster-twinkle",   runStepJugglerFasterTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-longer",           runStepJugglerLonger,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "juggler-longer-twinkle",   runStepJugglerLongerTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

    { "sinelon-normal",           runStepSinelonNormal,         runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },
    { "sinelon-normal-twinkle",   runStepSinelonNormalTwinkle,  runInitGeneric,        LED_STR_SEC_CYCLE,     LED_STR_SEC_COLOR, LED_PTN_STEP_MILI, LED_PTN_FADE_MILI },

};

uint8_t ledChainCallRefIndex = 99;
uint8_t ledChainBaseColorHue = 0;
int8_t  ledChainFadeLeveling = 0;
CRGB    ledStrandHoldColors[];

uint8_t minInt8(int16_t i) {
    return i >= 0 ? i : 0;
}

uint8_t maxInt8(int16_t i) {
    return i <= 255 ? i : 255;
}

uint8_t useInt8(int16_t i) {
    return i <= 255 ? (i >= 0 ? i : 0) : 255;
}

void setHoldColoursActive()
{
    for(int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandColors[i] = ledStrandHoldColors[i];
    }
}

void incSelectedStep(int by)
{
    if (ledChainCallRefIndex == 99) {
        ledChainCallRefIndex = 0;
    } else {
        ledChainCallRefIndex = (ledChainCallRefIndex + 1) % ARRAY_SIZE(ledChainList);
    }

    if (ledChainList[ledChainCallRefIndex].init != nullptr) {
        ledChainList[ledChainCallRefIndex].init();
        FastLED.show();
    }

    uint16_t listArrLen = ARRAY_SIZE(ledChainList);
    uint16_t nameMaxLen = 0;
    String   outsFmtBeg = "Selected pattern %02d of %02d: %-";
    String   outsFmtEnd = "s (%02lus / %02lums / %02lums / %02lums)";
    String   outsFmtAll;
    char     outsBuffer[100];

    for (uint8_t i = 0; i < listArrLen; i++) {
        nameMaxLen = ledChainList[i].name.length() > nameMaxLen ? ledChainList[i].name.length() : nameMaxLen;
    }

    outsFmtAll = outsFmtBeg + nameMaxLen;
    outsFmtAll = outsFmtAll + outsFmtEnd;

    sprintf(
        outsBuffer,
        outsFmtAll.c_str(),
        ledChainCallRefIndex + 1,
        listArrLen,
        ledChainList[ledChainCallRefIndex].name.c_str(),
        ledChainList[ledChainCallRefIndex].callExecMili/1000,
        ledChainList[ledChainCallRefIndex].randHuesMili,
        ledChainList[ledChainCallRefIndex].waitLoopMili,
        ledChainList[ledChainCallRefIndex].waitFadeMili
    );

    Serial.println(outsBuffer);
}

void runSelectedStep(bool wait)
{
    if (ledChainList[ledChainCallRefIndex].call != nullptr) {
        ledChainList[ledChainCallRefIndex].call();
        FastLED.show();
    }

    FastLED.delay(wait ? ledChainList[ledChainCallRefIndex].waitLoopMili : 0);
}

bool runSelectedStepFadeInitNew()
{
    if (ledChainFadeLeveling > 255) {
        ledChainFadeLeveling = 255;
    }

    if (ledChainFadeLeveling < 255) {
        ledChainFadeLeveling = ledChainFadeLeveling + 1;
    }

    for(int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandColors[i] = CHSV(ledStrandColors[i], 255, ledChainFadeLeveling);
    }

    FastLED.show();

    return ledChainFadeLeveling < 255;
}

bool runSelectedStepFadeEndsNew()
{
    if (ledChainFadeLeveling < 0) {
        ledChainFadeLeveling = 0;
    }

    if (ledChainFadeLeveling > 0) {
        ledChainFadeLeveling = ledChainFadeLeveling - 1;
    }

    for(int i = 0; i < LED_STR_NUM; ++i) {
        ledStrandColors[i] = CHSV(ledStrandColors[i], 255, ledChainFadeLeveling);
    }

    FastLED.show();

    return ledChainFadeLeveling > 0;
}

bool runSelectedStepFadeInit()
{
    if (!LED_PTN_FADE_ENBL) {
        FastLED.setBrightness(LED_STR_BRT);
        FastLED.delay(ledChainList[ledChainCallRefIndex].waitFadeMili);

        return false;
    }

    if (ledChainFadeLeveling > LED_STR_BRT) {
        ledChainFadeLeveling = LED_STR_BRT;
    }

    if (ledChainFadeLeveling <= LED_STR_BRT) {
        ledChainFadeLeveling = ledChainFadeLeveling + 1;
    }

    FastLED.setBrightness(ledChainFadeLeveling <= LED_STR_BRT ? ledChainFadeLeveling : LED_STR_BRT);
    FastLED.delay(ledChainList[ledChainCallRefIndex].waitFadeMili);

    return ledChainFadeLeveling <= LED_STR_BRT;
}

bool runSelectedStepFadeEnds()
{
    if (!LED_PTN_FADE_ENBL) {
        FastLED.setBrightness(LED_STR_BRT);
        FastLED.delay(ledChainList[ledChainCallRefIndex].waitFadeMili);

        return false;
    }

    if (ledChainFadeLeveling < 0) {
        ledChainFadeLeveling = 0;
    }

    if (ledChainFadeLeveling > 0) {
        ledChainFadeLeveling = ledChainFadeLeveling - 1;
    }

    FastLED.setBrightness(ledChainFadeLeveling >= 0 ? ledChainFadeLeveling : 0);
    FastLED.delay(ledChainList[ledChainCallRefIndex].waitFadeMili);

    if (ledChainFadeLeveling == 0) {
        FastLED.delay(LED_PTN_NEXT_MILI);
    }

    return ledChainFadeLeveling > 0;
}

void runInitGeneric()
{
    fill_solid(ledStrandColors, LED_STR_NUM, CRGB(0, 0, 0));
}

void runStepTwinkle(uint8_t level, fract8 chance, uint8_t iterations)
{
    iterations = random8(0, iterations);

    for (uint8_t i = 0; i < iterations; i++) {
        ledStrandColors[random16(LED_STR_NUM)] += CRGB(random8(level), random8(level), random8(level));
    }
}

void runInitColoredVaried(uint8_t r, uint8_t g, uint8_t b, uint8_t d)
{
    runInitGeneric();

    for(int i = 0; i < LED_STR_NUM; ++i) {
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

void runStepColoredStatic(uint8_t r, uint8_t g, uint8_t b)
{
    runInitColoredStatic(r, g, b);
}

void runStepHoldingColors()
{
    setHoldColoursActive();
}

void runInitColoredStatic(uint8_t r, uint8_t g, uint8_t b)
{
    auto color = CRGB(r, g, b);

    for(int i = 0; i < LED_STR_NUM; ++i) {
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
    fill_rainbow(ledStrandColors, LED_STR_NUM, ledChainBaseColorHue, 7);
}

void runStepRainbowNormalTwinkle()
{
    runStepRainbowNormal();
    runStepTwinkle();
}

void runStepBuilder(uint8_t iterations)
{
    fadeToBlackBy(ledStrandColors, LED_STR_NUM, 1);

    for(uint8_t i = 0; i < iterations; i++) {
        ledStrandColors[random16(LED_STR_NUM)] += CHSV(ledChainBaseColorHue + random8(64), 200, 255);
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
        ledStrandColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(ledChainBaseColorHue, 255, 192);
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

    for(int i = 0; i < LED_STR_NUM; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledChainBaseColorHue + (i * 2), beat - ledChainBaseColorHue + (i * 10));
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

void runStepRainbowSliderNormal()
{
    runStepSlidingBeater(RainbowColors_p);
}

void runStepRainbowSliderStripe()
{
    runStepSlidingBeater(RainbowStripeColors_p);
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

void runStepJuggler(uint8_t fade) {
    byte dothue = 0;

    fadeToBlackBy(ledStrandColors, LED_STR_NUM, fade);

    for(int i = 0; i < 12; i++) {
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
