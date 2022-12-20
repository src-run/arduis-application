
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

ledChainListEntry ledChainList[] = {
    { "colored-static-white",         runStepColoredStaticWhite,            runInitGeneric, getWaitColoredStaticGeneric        },
    { "colored-static-white-twinkle", runStepColoredStaticWhiteWithTwinkle, runInitGeneric, getWaitGeneric                     },
    { "colored-static-white-builder", runStepColoredStaticWhiteBuilder,     runInitGeneric, getWaitColoredStaticGenericBuilder },
    { "colored-static-green",         runStepColoredStaticGreen,            runInitGeneric, getWaitColoredStaticGeneric        },
    { "colored-static-green-twinkle", runStepColoredStaticGreenWithTwinkle, runInitGeneric, getWaitGeneric                     },
    { "colored-static-green-builder", runStepColoredStaticGreenBuilder,     runInitGeneric, getWaitColoredStaticGenericBuilder },
    { "colored-static-red",           runStepColoredStaticRed,              runInitGeneric, getWaitColoredStaticGeneric        },
    { "colored-static-red-twinkle",   runStepColoredStaticRedWithTwinkle,   runInitGeneric, getWaitGeneric                     },
    { "colored-static-red-builder",   runStepColoredStaticRedBuilder,       runInitGeneric, getWaitColoredStaticGenericBuilder },
    { "colored-static-blue",          runStepColoredStaticBlue,             runInitGeneric, getWaitColoredStaticGeneric        },
    { "colored-static-blue-twinkle",  runStepColoredStaticBlueWithTwinkle,  runInitGeneric, getWaitGeneric                     },
    { "colored-static-blue-builder",  runStepColoredStaticBlueBuilder,      runInitGeneric, getWaitColoredStaticGenericBuilder },
    { "rainbow-static",               runStepRainbowStatic,                 runInitGeneric, getWaitGeneric                     },
    { "rainbow-static-with-twinkle",  runStepRainbowStaticWithTwinkle,      runInitGeneric, getWaitGeneric                     },
    { "rainbow-normal",               runStepRainbowNormal,                 runInitGeneric, getWaitGeneric                     },
    { "rainbow-normal-with-twinkle",  runStepRainbowNormalWithTwinkle,      runInitGeneric, getWaitGeneric                     },
    { "rainbow-slider-normal",        runStepRainbowSliderNormal,           runInitGeneric, getWaitGeneric                     },
    { "rainbow-slider-stripe",        runStepRainbowSliderStripe,           runInitGeneric, getWaitGeneric                     },
    { "builder-normal",               runStepBuilderNormal,                 runInitGeneric, getWaitGeneric                     },
    { "builder-normal-with-twinkle",  runStepBuilderNormalWithTwinkle,      runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-cloud",           runStepSlidingBeatCloud,              runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-lava",            runStepSlidingBeatLava,               runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-forest",          runStepSlidingBeatForest,             runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-ocean",           runStepSlidingBeatOcean,              runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-party",           runStepSlidingBeatParty,              runInitGeneric, getWaitGeneric                     },
    { "sliding-beat-heat",            runStepSlidingBeatHeat,               runInitGeneric, getWaitGeneric                     },
    { "juggler-fade-fast",            runStepJugglerFadeFast,               runInitGeneric, getWaitGeneric                     },
    { "juggler-fade-norm",            runStepJugglerFadeNorm,               runInitGeneric, getWaitGeneric                     },
    { "juggler-fade-long",            runStepJugglerFadeLong,               runInitGeneric, getWaitGeneric                     },
    { "sinelon-normal",               runStepSinelonNormal,                 runInitGeneric, getWaitGeneric                     },
    { "sinelon-normal-with-twinkle",  runStepSinelonNormalWithTwinkle,      runInitGeneric, getWaitGeneric                     },
};

uint8_t ledChainCallRefIndex = 99;
uint8_t ledChainBaseColorHue = 0;
int8_t ledChainFadeLeveling = 0;

void incSelectedStep(int by)
{
    if (ledChainCallRefIndex == 99) {
        ledChainCallRefIndex = 0;
    } else {
        ledChainCallRefIndex = (ledChainCallRefIndex + 1) % ARRAY_SIZE(ledChainList);
    }

    ledChainList[ledChainCallRefIndex].init();

    char buffer[100];
    sprintf(
        buffer,
        "Selected pattern %02d of %02d: \"%s\"",
        ledChainCallRefIndex + 1,
        ARRAY_SIZE(ledChainList),
        ledChainList[ledChainCallRefIndex].name.c_str()
    );
    Serial.println(buffer);
}

void runSelectedStep(bool wait)
{
    ledChainList[ledChainCallRefIndex].call();

    FastLED.show();

    if (wait) {
        FastLED.delay(ledChainList[ledChainCallRefIndex].wait());
    }
}

bool runSelectedStepFadeOut()
{
    if (ledChainFadeLeveling > 0) {
        ledChainFadeLeveling = ledChainFadeLeveling - 1;
    }

    if (ledChainFadeLeveling < 0) {
        ledChainFadeLeveling = 0;
    }

    setBrightness(ledChainFadeLeveling);
    FastLED.delay(LED_PATTERN_TRAN_DELAY);

    if (ledChainFadeLeveling == 0) {
        FastLED.delay(LED_PATTERN_NEXT_DELAY);
    }

    return ledChainFadeLeveling > 0;
}

bool runSelectedStepFadeIn()
{
    if (ledChainFadeLeveling < LED_STRDS_BRT) {
        ledChainFadeLeveling = ledChainFadeLeveling + 1;
    }

    if (ledChainFadeLeveling > LED_STRDS_BRT) {
        ledChainFadeLeveling = LED_STRDS_BRT;
    }

    setBrightness(ledChainFadeLeveling);
    FastLED.delay(LED_PATTERN_TRAN_DELAY);

    return ledChainFadeLeveling < LED_STRDS_BRT;
}

void setBrightness(uint8_t level)
{
    FastLED.setBrightness(level > 255 ? 255 : level);
}

void setBrightnessNone()
{
    setBrightness(0);
}

void setBrightnessFull()
{
    setBrightness(LED_STRDS_BRT);
}

void ledFadeOut(uint8_t increment)
{
    for (int i = LED_STRDS_BRT; i > 0; i = i - increment) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_STEP_DELAY);
    }

    setBrightnessNone();

    FastLED.delay(LED_PATTERN_STEP_DELAY * 100);
}

void ledFadeIn()
{
    for (int i = 0; i <= LED_STRDS_BRT; i++) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_STEP_DELAY);
    }

    setBrightnessFull();

    FastLED.delay(LED_PATTERN_STEP_DELAY * 2);
}

float getWaitGeneric() {
    return LED_PATTERN_STEP_DELAY;
}

void runInitGeneric()
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(0, 0, 0));
    FastLED.show();
}

uint16_t rgbMin(uint16_t val, uint16_t min) {
    return val >= min ? val : min;
}

uint16_t rgbMax(uint16_t val, uint16_t max) {
    return val <= max ? val : max;
}

void runStepColoredStaticBuilder(uint8_t r, uint8_t g, uint8_t b, uint8_t d)
{
    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 3);

    for (uint8_t i = 0; i < LED_STRDS_LEN/25; i++) {
        ledStrandColors[random16(LED_STRDS_LEN)] = CRGB(
            r == 0 ? random8(0, rgbMax(d * 4)) : random8(rgbMin(r - d), rgbMax(r + d)),
            g == 0 ? random8(0, rgbMax(d * 4)) : random8(rgbMin(g - d), rgbMax(g + d)),
            b == 0 ? random8(0, rgbMax(d * 4)) : random8(rgbMin(b - d), rgbMax(b + d))
        );
    }
}

void runStepColoredStaticWithTwinkleBuilder(uint8_t r, uint8_t g, uint8_t b, uint8_t d)
{
    runStepColoredStaticBuilder(r, g, b, d);
    runStepWithTwinkle(50);
}

float getWaitColoredStaticGenericBuilder()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runStepColoredStaticWhiteBuilder() {
    runStepColoredStaticBuilder(120, 120, 120);
}

void runStepColoredStaticGreenBuilder() {
    runStepColoredStaticBuilder(0, 255, 0);
}

void runStepColoredStaticRedBuilder() {
    runStepColoredStaticBuilder(255, 0, 0);
}

void runStepColoredStaticBlueBuilder() {
    runStepColoredStaticBuilder(0, 0, 255);
}

void runStepColoredStatic(uint8_t r, uint8_t g, uint8_t b)
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(r, g, b));
}

void runStepColoredStaticWithTwinkle(uint8_t r, uint8_t g, uint8_t b)
{
    runStepColoredStatic(r, g, b);
    runStepWithTwinkle(50);
}

float getWaitColoredStaticGeneric()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runStepColoredStaticWhite() {
    runStepColoredStatic(120, 120, 120);
}

void runStepColoredStaticGreen() {
    runStepColoredStatic(0, 255, 0);
}

void runStepColoredStaticRed() {
    runStepColoredStatic(255, 0, 0);
}

void runStepColoredStaticBlue() {
    runStepColoredStatic(0, 0, 255);
}

void runStepColoredStaticWhiteWithTwinkle() {
    runStepColoredStaticWithTwinkle(120, 120, 120);
}

void runStepColoredStaticGreenWithTwinkle() {
    runStepColoredStaticWithTwinkle(0, 255, 0);
}

void runStepColoredStaticRedWithTwinkle() {
    runStepColoredStaticWithTwinkle(255, 0, 0);
}

void runStepColoredStaticBlueWithTwinkle() {
    runStepColoredStaticWithTwinkle(0, 0, 255);
}

void runStepRainbowStatic()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, 1, 7);
}

void runStepRainbowStaticWithTwinkle()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, 1, 7);
    runStepWithTwinkle(50);
}

void runStepRainbowNormal()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, ledChainBaseColorHue, 7);
}

void runStepRainbowNormalWithTwinkle()
{
    runStepRainbowNormal();
    runStepWithTwinkle(50);
}

void runStepWithTwinkle(fract8 chance)
{
    for (uint8_t i = 0; i < 5; i++) {
        if(random8() < chance) {
            ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::WhiteSmoke;
        }
    }
}

void runStepBuilderNormal()
{
    int pos = random16(LED_STRDS_LEN);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 1);
    ledStrandColors[pos] += CHSV(ledChainBaseColorHue + random8(64), 200, 255);
}

void runStepBuilderNormalWithTwinkle()
{
    runStepBuilderNormal();
    runStepWithTwinkle(50);
}

void runStepSinelonNormal()
{
    int p = beatsin16(13, 0, LED_STRDS_LEN - 1);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 1);
    ledStrandColors[p] += CHSV(ledChainBaseColorHue, 255, 192);
}

void runStepSinelonNormalWithTwinkle()
{
    runStepSinelonNormal();
    runStepWithTwinkle(50);
}

void runStepSlidingBeat(CRGBPalette16 palette, uint8_t time)
{
    uint8_t b = beatsin8(time, 64, 180);

    for(int i = 0; i < LED_STRDS_LEN; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledChainBaseColorHue + (i * 2), b-ledChainBaseColorHue+(i * 10));
    }
}

void runStepSlidingBeatCloud()
{
    runStepSlidingBeat(CloudColors_p);
}

void runStepSlidingBeatLava()
{
    runStepSlidingBeat(LavaColors_p);
}

void runStepRainbowSliderNormal()
{
    runStepSlidingBeat(RainbowColors_p);
}

void runStepRainbowSliderStripe()
{
    runStepSlidingBeat(RainbowStripeColors_p);
}

void runStepSlidingBeatOcean()
{
    runStepSlidingBeat(OceanColors_p);
}

void runStepSlidingBeatForest()
{
    runStepSlidingBeat(ForestColors_p);
}

void runStepSlidingBeatParty()
{
    runStepSlidingBeat(PartyColors_p);
}

void runStepSlidingBeatHeat()
{
    runStepSlidingBeat(HeatColors_p);
}

void runStepJuggler(uint8_t fade) {
    byte dothue = 0;

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, fade);

    for(int i = 0; i < 8; i++) {
        ledStrandColors[beatsin16(i + 7, 0, LED_STRDS_LEN - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void runStepJugglerFadeFast()
{
    runStepJuggler(80);
}

void runStepJugglerFadeNorm()
{
    runStepJuggler(40);
}

void runStepJugglerFadeLong()
{
    runStepJuggler(10);
}
