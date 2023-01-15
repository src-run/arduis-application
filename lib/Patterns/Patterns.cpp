
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Patterns.h"

bool ledPatternGlintEnabled { false };
int  ledPatternFadeLeveling { 0 };
bool ledPatternStepInit     { false };
bool ledPatternStepRuns     { false };

const PatternsAction* getLedPatternDeft()
{
    return &patternItemDeflt;
}

const PatternsAction* getLedPatternItem(const unsigned int idx)
{
    return idx >= getLedPatternListSize()
        ? getLedPatternDeft()
        : &(patternListItems[idx]);
}

const PatternsAction* getLedPatternItem()
{
    return getLedPatternItem(getLedPatternListStepIndx());
}

const EffectDefinitionDetail* getLedPatternItemActionDetail(const unsigned int idx)
{
    return &(getLedPatternItem(idx)->detail);
}

const EffectDefinitionDetail* getLedPatternItemActionDetail()
{
    return getLedPatternItemActionDetail(getLedPatternListStepIndx());
}

const ActionRunnerPattern* getLedPatternItemActionRunner(const unsigned int idx)
{
    return &(getLedPatternItem(idx)->runner);
}

const ActionRunnerPattern* getLedPatternItemActionRunner()
{
    return getLedPatternItemActionRunner(getLedPatternListStepIndx());
}

const EffectDefinitionTimers* getLedPatternItemActionTimers(const unsigned int idx)
{
    return &(getLedPatternItem(idx)->timers);
}

const EffectDefinitionTimers* getLedPatternItemActionTimers()
{
    return getLedPatternItemActionTimers(getLedPatternListStepIndx());
}

const EffectDefinitionGlints* getLedPatternItemActionGlints(const unsigned int idx)
{
    return &(getLedPatternItem(idx)->glints);
}

const EffectDefinitionGlints* getLedPatternItemActionGlints()
{
    return getLedPatternItemActionGlints(getLedPatternListStepIndx());
}

String getLedPatternItemName(const unsigned int idx)
{
    return String(getLedPatternItemNameC(idx));
}

String getLedPatternItemName()
{
    return String(getLedPatternItemNameC());
}

const char *getLedPatternItemNameC(const unsigned int idx)
{
    return getLedPatternItemActionDetail(idx)->name;
}

const char *getLedPatternItemNameC()
{
    return getLedPatternItemNameC(getLedPatternListStepIndx());
}

void (*getLedPatternItemInit())()
{
    return getLedPatternItem()->runner.init != nullptr
        ? getLedPatternItem()->runner.init
        : getLedPatternDeft()->runner.init;
}

void (*getLedPatternItemCall())()
{
    return getLedPatternItem()->runner.main != nullptr
        ? getLedPatternItem()->runner.main
        : getLedPatternDeft()->runner.main;
}

unsigned int getLedPatternItemCallExecSecs()
{
    return getLedPatternItemActionTimers()->runningTotalSecs;
}

byte getLedPatternItemRandHuesMili()
{
    return getLedPatternItemActionTimers()->iterateMilliSecs;
}

unsigned int getLedPatternListStepInit()
{
    return LED_PTN_RAND_INIT
        ? getLedPatternListRandIndx()
        : 0;
}

unsigned int getLedPatternListStepNext(const unsigned int idx)
{
    return LED_PTN_RAND_NEXT
        ? getLedPatternListRandIndx()
        : ((idx + 1) % getLedPatternListSize());
}

unsigned int getLedPatternListRandIndx()
{
    return LED_PTN_RAND_SEQL
        ? getLedPatternListRandIndxSeql()
        : getRandomIndx(getLedPatternListSize());
}

unsigned int getLedPatternListRandIndxSeql(bool internalIndex)
{
    static bool patternListOrderFirst { true };
    static byte patternListOrderIndex { 0 };

    if (internalIndex) {
        return 0 == patternListOrderIndex && patternListOrderFirst
            ? 1
            : getLedPatternListSize() - patternListOrderIndex;
    }

    if (patternListOrderIndex == 0) {
        patternListOrderIndex = getLedPatternListSize();

        for (byte i = 0; i < patternListOrderIndex; i++) {
            patternListOrder[i] = i;
        }

        for (byte j = 0; j < randByte(1, max(2, LED_PTN_RAND_ENTR)); j++) {
            for (byte i = 0; i < patternListOrderIndex; i++) {
                const byte n { randByte(patternListOrderIndex - 1) };
                const byte v { patternListOrder[n] };

                patternListOrder[n] = patternListOrder[i];
                patternListOrder[i] = v;
            }
        }

        if (patternListOrderFirst && !LED_PTN_RAND_INIT) {
            for (byte i = 0; i < patternListOrderIndex; i++) {
                if (0 == patternListOrder[i]) {
                    patternListOrder[i] = patternListOrder[patternListOrderIndex - 1];
                    patternListOrder[patternListOrderIndex - 1] = 0;

                    break;
                }
            }

            --patternListOrderIndex;
        }

        patternListOrderFirst = false;
    }

    --patternListOrderIndex;

    return patternListOrder[constrain(patternListOrderIndex, 0, getLedPatternListSize() - 1)];
}

unsigned int getLedPatternListStepIndx(const bool indexIncr)
{
    static unsigned int indexCurr { getLedPatternListStepInit() };
    static bool         isRunning { false };

    if (isRunning && indexIncr) {
        indexCurr = getLedPatternListStepNext(indexCurr);
    }

    isRunning = true;

    return indexCurr;
}

unsigned int incLedPatternListStepIndx()
{
    return getLedPatternListStepIndx(true);
}

unsigned int getLedPatternListStepNumb()
{
    return getLedPatternListStepIndx() + 1;
}

unsigned int getLedPatternListStepNumbReal()
{
    return LED_PTN_RAND_INIT || LED_PTN_RAND_SEQL
        ? getLedPatternListRandIndxSeql(true)
        : getLedPatternListStepNumb();
}

void runEffectAddonGlints()
{
    if (getEffectAddonGlintsState()) {
        runStepTwinkle();
    }
}

void setEffectAddonGlintsState(const byte chances)
{
    ledPatternGlintEnabled = 0 != chances && (
        (100 == chances) || (randByte(100) <= chances)
    );
}

bool getEffectAddonGlintsState()
{
    return LED_PTN_GLNT_ENBL && ledPatternGlintEnabled;
}

void incPatternsStep()
{
    while (true) {
        incLedPatternListStepIndx();

        const unsigned int skip = randByte(100);

        if (!LED_PTN_SKIP_ENBL || skip >= getLedPatternItemActionDetail()->skipChance) {
            break;
        }

        outStepInfo(true, skip);
    }

    setEffectAddonGlintsState(
        (isLedPaletteStepNamed()
            ? getLedPaletteItemActionGlints()
            : getLedPatternItemActionGlints()
        )->chances
    );

    getLedPatternItemInit()();

    ledPatternStepInit = true;
    ledPatternStepRuns = false;

    FastLED.show();
    FastLED.delay(LED_PTN_LOOP_MILI);

    outStepInfo();
}

void runPatternsStep(const bool wait)
{
    CycleCount.increment();

    getLedPatternItemCall()();
    runEffectAddonGlints();

    ledPatternStepInit = false;
    ledPatternStepRuns = true;

    FastLED.show();
    FastLED.delay(wait ? LED_PTN_LOOP_MILI : 0);
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
    FastLED.delay(LED_PTN_FADE_MILI);

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
    FastLED.delay(LED_PTN_FADE_MILI);

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

void runStepTwinkle()
{
    const EffectDefinitionGlints* glints {
        isLedPaletteStepStarted()
            ? getLedPaletteItemActionGlints()
            : getLedPatternItemActionGlints()
    };

    const byte loopMax { randByte(glints->amounts) };
    const byte maximum { glints->maximum };
    const byte minimum { glints->minimum };

    for (byte i = 0; i < loopMax; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] += CRGB(
            randByte(minimum, maximum),
            randByte(minimum, maximum),
            randByte(minimum, maximum)
        );
    }
}

void runInitGeneric()
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB::Black);
}

void runStepGeneric()
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB::Black);
}

void runStepColoredStatic(const byte r, const byte g, const byte b)
{
    fill_solid(ledStrandsActiveColors, LED_STR_NUM, CRGB(r, g, b));
}

void runStepColoredStaticW()
{
    runStepColoredStatic(120, 120, 120);
}

void runStepColoredStaticR()
{
    runStepColoredStatic(220, 0, 0);
}

void runStepColoredStaticG()
{
    runStepColoredStatic(0, 220, 0);
}

void runStepColoredStaticB()
{
    runStepColoredStatic(0, 0, 220);
}

void runStepColoredBuilds(const byte r, const byte g, const byte b, const byte d)
{
    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, 3);

    for (unsigned int i = 0; i < LED_STR_NUM/25; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] = CRGB(
            r == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(r - d), cstrByte(r + d)),
            g == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(g - d), cstrByte(g + d)),
            b == 0 ? randByte(0, cstrByte(d * 4)) : randByte(cstrByte(b - d), cstrByte(b + d))
        );
    }
}

void runStepColoredBuildsW()
{
    runStepColoredBuilds(120, 120, 120);
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

void runInitColoredVaried(const byte r, const byte g, const byte b, const byte d)
{
    runInitGeneric();

    for (unsigned int i = 0; i < LED_STR_NUM; ++i) {
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
    runInitColoredVaried(120, 120, 120, 60);
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

void runStepRainbowStatic()
{
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, 1, 7);
}

void runStepRainbowNormal()
{
    fill_rainbow(ledStrandsActiveColors, LED_STR_NUM, getByteNumStep(), 7);
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

    for (unsigned int i = 0; i < iterations; i++) {
        ledStrandsActiveColors[randUInt(LED_STR_NUM)] += CHSV(getByteNumStep() + randByte(64), 200, 255);
    }
}

void runStepBuilderNormal()
{
    runStepBuilder(3);
}

void runStepBuilderFaster()
{
    runStepBuilder(5);
}

void runStepSinelon(const byte iterations)
{
    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, 1);

    for (unsigned int i = 0; i < iterations; i++) {
        ledStrandsActiveColors[beatsin16(13, 10, LED_STR_NUM - 1)] += CHSV(getByteNumStep(), 255, 192);
    }
}

void runStepSinelonNormal()
{
    runStepSinelon(20);
}

void runStepSlidingBeater(const CRGBPalette16& palette, const byte time)
{
    byte beat { beatsin8(time, 64, 180) };

    for (unsigned int i = 0; i < LED_STR_NUM; i++) {
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

void runStepPaletteRounds(const CRGBPalette16& palette, const int multiplier, const bool blend)
{
    for (unsigned int i = 0; i < LED_STR_NUM; i++) {
        ledStrandsActiveColors[i] = ColorFromPalette(
            palette,
            ((unsigned int)getByteNumStep()) + ((unsigned int)(i * multiplier)),
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

void runStepPaletteCircle()
{
    runStepPaletteRounds(getLedPaletteItemComp());
}

void runStepJuggler(const byte fade)
{
    byte dothue { 0 };

    fadeToBlackBy(ledStrandsActiveColors, LED_STR_NUM, fade);

    for (unsigned int i = 0; i < 12; i++) {
        ledStrandsActiveColors[beatsin16(i + randByte(5, 10), 0, LED_STR_NUM - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void runStepJugglerFaster()
{
    runStepJuggler(24);
}

void runStepJugglerLonger()
{
    runStepJuggler(8);
}

void runStepColoredGradedeeeeeeee()
{
    byte hue { sin8(getByteNumStep()) };

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
    byte hueBeg { beatsin8(bmp1, 0, 255) };
    byte hueEnd { beatsin8(bpm2, 0, 255) };

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
    byte hueBeg { getByteNumStep() };
    byte hueEnd { (byte)(hueBeg + 64) };

    if (hueBeg < hueEnd) {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueBeg, 255, 255), CHSV(hueEnd, 255, 255), FORWARD_HUES);
    } else {
        fill_gradient(ledStrandsActiveColors, LED_STR_NUM, CHSV(hueEnd, 255, 255), CHSV(hueBeg, 255, 255), BACKWARD_HUES);
    }
}

byte getByteNumStep(byte inc)
{
    static byte hue { randByte() };

    hue += inc;

    return hue;
}

byte incByteNumStep(byte add)
{
    return getByteNumStep(add);
}
