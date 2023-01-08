
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
    { "palette-circle",          runStepPaletteCircle,              nullptr,               LED_PTN_SEC_CYCLE * 4, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-circle-t",        runStepPaletteCircleTwinkle,       nullptr,               LED_PTN_SEC_CYCLE * 4, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
    { "rainbow-static",          runStepRainbowStatic,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "rainbow-static-t",        runStepRainbowStaticTwinkle,       nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "rainbow-normal",          runStepRainbowNormal,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,   0 },
//    { "rainbow-normal-t",        runStepRainbowNormalTwinkle,       nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "rainbow-slider-normal",   runStepRainbowSliderNormal,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "rainbow-slider-stripe",   runStepRainbowSliderStripe,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "builder-faster",          runStepBuilderFaster,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "builder-faster-t",        runStepBuilderFasterTwinkle,       nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "builder-normal",          runStepBuilderNormal,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,   0 },
//    { "builder-normal-t",        runStepBuilderNormalTwinkle,       nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-clouds",   runStepSlidingBeaterClouds,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-clouds",   runStepPaletteRoundsClouds,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-clouds-t", runStepPaletteRoundsCloudsTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-magmas",   runStepSlidingBeaterMagmas,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-magmas",   runStepPaletteRoundsMagmas,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-magmas-t", runStepPaletteRoundsMagmasTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-forest",   runStepSlidingBeaterForest,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-forest",   runStepPaletteRoundsForest,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-forest-t", runStepPaletteRoundsForestTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-oceans",   runStepSlidingBeaterOceans,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-oceans",   runStepPaletteRoundsOceans,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-oceans-t", runStepPaletteRoundsOceansTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-random",   runStepSlidingBeaterRandom,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-random",   runStepPaletteRoundsRandom,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-random-t", runStepPaletteRoundsRandomTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "sliding-beater-heater",   runStepSlidingBeaterHeater,        nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "palette-rounds-heater",   runStepPaletteRoundsHeater,        nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "palette-rounds-heater-t", runStepPaletteRoundsHeaterTwinkle, nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "juggler-faster",          runStepJugglerFaster,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "juggler-faster-t",        runStepJugglerFasterTwinkle,       nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "juggler-longer",          runStepJugglerLonger,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,   0 },
//    { "juggler-longer-t",        runStepJugglerLongerTwinkle,       nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "sinelon-normal",          runStepSinelonNormal,              nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "sinelon-normal-t",        runStepSinelonNormalTwinkle,       nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "colored-static-w",        runStepColoredStaticW,             nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-static-w-t",      runStepColoredStaticWTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-varied-w",        runStepColoredVariedW,             runInitColoredVariedW, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-varied-w-t",      runStepColoredVariedWTwinkle,      runInitColoredVariedW, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-builds-w",        runStepColoredBuildsW,             nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  10 },
//    { "colored-builds-w-t",      runStepColoredBuildsWTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "colored-static-r",        runStepColoredStaticR,             nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-static-r-t",      runStepColoredStaticRTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-varied-r",        runStepColoredVariedR,             runInitColoredVariedR, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-varied-r-t",      runStepColoredVariedRTwinkle,      runInitColoredVariedR, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-builds-r",        runStepColoredBuildsR,             nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  10 },
//    { "colored-builds-r-t",      runStepColoredBuildsRTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "colored-static-g",        runStepColoredStaticG,             nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-static-g-t",      runStepColoredStaticGTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-varied-g",        runStepColoredVariedG,             runInitColoredVariedG, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-varied-g-t",      runStepColoredVariedGTwinkle,      runInitColoredVariedG, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-builds-g",        runStepColoredBuildsG,             nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  10 },
//    { "colored-builds-g-t",      runStepColoredBuildsGTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "colored-static-b",        runStepColoredStaticB,             nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-static-b-t",      runStepColoredStaticBTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 3, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-varied-b",        runStepColoredVariedB,             runInitColoredVariedB, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  20 },
//    { "colored-varied-b-t",      runStepColoredVariedBTwinkle,      runInitColoredVariedB, LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  60 },
    { "colored-builds-b",        runStepColoredBuildsB,             nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  10 },
//    { "colored-builds-b-t",      runStepColoredBuildsBTwinkle,      nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR,     LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50,  40 },
    { "rainbow-wholed-slow",     runStepRainbowWholed,              nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR * 8, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50, 100 },
    { "rainbow-wholed-fast",     runStepRainbowWholed,              nullptr,               LED_PTN_SEC_CYCLE / 2, LED_STR_SEC_COLOR / 6, LED_PTN_WAIT_LOOP / 2, LED_PTN_FADE_MILI, 50, 100 },
    { "rainbow-fading-slow",     runStepRainbowFadingSlow,          nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50, 100 },
    { "rainbow-fading-fast",     runStepRainbowFadingFast,          nullptr,               LED_PTN_SEC_CYCLE,     LED_STR_SEC_COLOR * 2, LED_PTN_WAIT_LOOP,     LED_PTN_FADE_MILI, 50, 100 },
};

byte                 ledPatternSeql[ARRAY_SIZE(ledPatternList)];
const ledPatternItem ledPatternDeft = {
    "generic",
    runStepGeneric,
    runInitGeneric,
    LED_PTN_SEC_CYCLE,
    LED_STR_SEC_COLOR,
    LED_PTN_WAIT_LOOP,
    LED_PTN_FADE_MILI,
    50,
    0,
};

bool ledPatternGlintEnabled = false;
int  ledPatternFadeLeveling = 0;
bool ledPatternStepInit     = false;
bool ledPatternStepRuns     = false;

unsigned int getLedPatternListSize(const int adds)
{
    static const unsigned int size = ARRAY_SIZE(ledPatternList);

    return size + adds;
}

const ledPatternItem *getLedPatternDeft()
{
    return &ledPatternDeft;
}

const ledPatternItem *getLedPatternItem(const unsigned int idx)
{
    return idx >= getLedPatternListSize() ? getLedPatternDeft() : &(ledPatternList[idx]);
}

const ledPatternItem *getLedPatternItem()
{
    return getLedPatternItem(getLedPatternListStepIndx());
}

String getLedPatternItemName(const unsigned int idx)
{
    return getLedPatternItemNameC(idx);
}

String getLedPatternItemName()
{
    return getLedPatternItemNameC();
}

const char *getLedPatternItemNameC(const unsigned int idx)
{
    return getLedPatternItem(idx)->name;
}

const char *getLedPatternItemNameC()
{
    return getLedPatternItem()->name;
}

void (*getLedPatternItemInit())()
{
    return nullptr != getLedPatternItem()->init
        ? getLedPatternItem()->init
        : getLedPatternDeft()->init;
}

void (*getLedPatternItemCall())()
{
    return nullptr != getLedPatternItem()->call
        ? getLedPatternItem()->call
        : getLedPatternDeft()->call;
}

unsigned int getLedPatternItemCallExecSecs()
{
    return getLedPatternItem()->callExecSecs;
}

unsigned long getLedPatternItemRandHuesMili()
{
    return static_cast<unsigned long>(getLedPatternItem()->randHuesMili);
}

unsigned long getLedPatternItemWaitLoopMili()
{
    return static_cast<unsigned long>(getLedPatternItem()->waitLoopMili);
}

unsigned long getLedPatternItemWaitFadeMili()
{
    return static_cast<unsigned long>(getLedPatternItem()->waitFadeMili);
}

unsigned int getLedPatternItemGlintsChance()
{
    return static_cast<unsigned int>(getLedPatternItem()->glintsChance);
}

unsigned int getLedPatternItemRejectChance()
{
    return static_cast<unsigned int>(getLedPatternItem()->rejectChance);
}

unsigned int getLedPatternListRandIndx()
{
    return LED_PTN_RAND_SEQL ? getLedPatternListRandIndxSeql() : getRandomIndx(getLedPatternListSize());
}

unsigned int getLedPatternListRandIndxSeql()
{
    static bool         beg = false;
    static unsigned int len = getLedPatternListSize();
    static unsigned int pos = 0;

    if (beg == false) {
        beg = true;

        for (unsigned int i = 0; i < len; i++) {
            ledPatternSeql[i] = i;
        }
    }

    if (pos == 0) {
        pos = len;

        for (byte j = 0; j < randByte(6); j++) {
            for (unsigned int i = 0; i < len; i++) {
                const unsigned int n = randUInt(len - 1);
                const byte         v = ledPatternSeql[n];
                ledPatternSeql[n]    = ledPatternSeql[i];
                ledPatternSeql[i]    = v;
            }
        }
    }

    --pos;

    return ledPatternSeql[constrain(pos, 0, len - 1)];
}

unsigned int getLedPatternListStepInit()
{
    return LED_PTN_RAND_INIT ? getLedPatternListRandIndx() : 0;
}

unsigned int getLedPatternListStepNext(const unsigned int idx)
{
    return LED_PTN_RAND_NEXT ? getLedPatternListRandIndx() : ((idx + 1) % getLedPatternListSize());
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

bool hasLedPatternItemGlints()
{
    return ledPatternGlintEnabled;
}

void addLedPatternItemGlints()
{
    if (hasLedPatternItemGlints()) {
        runStepTwinkle();
    }
}

void setLedPatternItemGlintsState()
{
    ledPatternGlintEnabled = LED_PTN_GLNT_ENBL && (randUInt(100) >= getLedPatternItemGlintsChance());
}

void incPatternsStep()
{
    while (true) {
        incLedPatternListStepIndx();

        const unsigned int skip = randByte(100);

        if (!LED_PTN_SKIP_ENBL || skip >= getLedPatternItemRejectChance()) {
            break;
        }

        outStepInfo(true, skip);
    }

    setLedPatternItemGlintsState();
    getLedPatternItemInit()();

    ledPatternStepInit = true;
    ledPatternStepRuns = false;

    FastLED.show();
    FastLED.delay(getLedPatternItemWaitLoopMili());

    outStepInfo();
}

void runPatternsStep(const bool wait)
{
    getLedPatternItemCall()();
    addLedPatternItemGlints();

    ledPatternStepInit = false;
    ledPatternStepRuns = true;

    FastLED.show();
    FastLED.delay(wait ? getLedPatternItemWaitLoopMili() : 0);
}

bool runPatternsFadeToColor(const bool fade, const int increment)
{
    while(fade && runPatternsFadeToColorInner(increment)) {
        runPatternsStep(false);
    }
}

bool runPatternsFadeToColorInner(const int increment)
{
    if (ledPatternFadeLeveling <= LED_STR_BRT) {
        ledPatternFadeLeveling = ledPatternFadeLeveling + increment;
    }

    FastLED.setBrightness(ledPatternFadeLeveling <= LED_STR_BRT ? ledPatternFadeLeveling : LED_STR_BRT);
    FastLED.delay(getLedPatternItemWaitFadeMili());

    return ledPatternFadeLeveling <= LED_STR_BRT;
}

bool runPatternsFadeToBlack(const bool fade, const int decrement)
{
    while(fade && runPatternsFadeToBlackInner(decrement)) {
        runPatternsStep(false);
    }
}

bool runPatternsFadeToBlackInner(const int decrement)
{
    if (ledPatternFadeLeveling > 0) {
        ledPatternFadeLeveling = ledPatternFadeLeveling - decrement;
    }

    FastLED.setBrightness(ledPatternFadeLeveling >= 0 ? ledPatternFadeLeveling : 0);
    FastLED.delay(getLedPatternItemWaitFadeMili());

    if (ledPatternFadeLeveling == 0) {
        FastLED.delay(LED_PTN_WAIT_NEXT);
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
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, getByteNumStep(), 7);
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
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] += CHSV(getByteNumStep() + randByte(64), 200, 255);
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
        ledStrandsActiveColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(getByteNumStep(), 255, 192);
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
        ledStrandsActiveColors[i] = ColorFromPalette(palette, getByteNumStep() + (i * 2), beat - getByteNumStep() + (i * 10));
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
            getByteNumStep() + (i * multiplier),
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
    byte hue = sin8(getByteNumStep());

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
    byte hueBeg = getByteNumStep();
    byte hueEnd = hueBeg + 64;

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}

byte getByteNumStep(byte inc)
{
    static byte hue = randByte();

    hue += inc;

    return hue;
}

byte incByteNumStep(byte add)
{
    return getByteNumStep(add);
}
