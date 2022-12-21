
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef _ARDUIS_HR_PATTERNS
#define _ARDUIS_HR_PATTERNS

#include <Arduino.h>
#include <FastLED.h>

#include "Strands.h"
#include "Utilities.h"

#define LED_PATTERN_STEP_DELAY 3000/LED_STR_FPS
#define LED_PATTERN_FADE_DELAY LED_PATTERN_STEP_DELAY / 3

uint8_t minInt8(int16_t i);
uint8_t maxInt8(int16_t i);
uint8_t useInt8(int16_t i);

void  setHoldColoursActive();

void  incSelectedStep(int by = 1);
void  runSelectedStep(bool wait = true);
bool  runSelectedStepFadeInit();
bool  runSelectedStepFadeEnds();

void  runStepTwinkle(uint8_t level = 180, fract8 chance = 50, uint8_t iterations = 8);
void  runInitGeneric();
void  runInitColoredStatic(uint8_t r, uint8_t g, uint8_t b);
void  runInitColoredStaticW();
void  runInitColoredStaticR();
void  runInitColoredStaticG();
void  runInitColoredStaticB();

void  runStepHoldingColors();

void  runStepColoredStatic(uint8_t r = 150, uint8_t g = 150, uint8_t b = 150);
void  runStepColoredStaticW();
void  runStepColoredStaticR();
void  runStepColoredStaticG();
void  runStepColoredStaticB();
void  runStepColoredStaticWTwinkle();
void  runStepColoredStaticRTwinkle();
void  runStepColoredStaticGTwinkle();
void  runStepColoredStaticBTwinkle();

void  runStepColoredBuilds(uint8_t r, uint8_t g, uint8_t b, uint8_t d = 25);
void  runStepColoredBuildsW();
void  runStepColoredBuildsR();
void  runStepColoredBuildsG();
void  runStepColoredBuildsB();
void  runStepColoredBuildsWTwinkle();
void  runStepColoredBuildsRTwinkle();
void  runStepColoredBuildsGTwinkle();
void  runStepColoredBuildsBTwinkle();

void  runInitColoredVaried(uint8_t r, uint8_t g, uint8_t b, uint8_t d = 100);
void  runInitColoredVariedW();
void  runInitColoredVariedR();
void  runInitColoredVariedG();
void  runInitColoredVariedB();
void  runStepColoredVariedWTwinkle();
void  runStepColoredVariedRTwinkle();
void  runStepColoredVariedGTwinkle();
void  runStepColoredVariedBTwinkle();

void  runStepRainbowStatic();
void  runStepRainbowStaticTwinkle();
void  runStepRainbowNormal();
void  runStepRainbowSliderNormal();
void  runStepRainbowSliderStripe();
void  runStepRainbowNormalTwinkle();

void  runStepBuilder(uint8_t iterations = 4);
void  runStepBuilderNormal();
void  runStepBuilderNormalTwinkle();
void  runStepBuilderFaster();
void  runStepBuilderFasterTwinkle();

void  runStepSinelon(uint8_t iterations = 6);
void  runStepSinelonNormal();
void  runStepSinelonNormalTwinkle();

void  runStepSlidingBeater(CRGBPalette16 palette, uint8_t time = 8);
void  runStepSlidingBeaterClouds();
void  runStepSlidingBeaterMagmas();
void  runStepSlidingBeaterOceans();
void  runStepSlidingBeaterForest();
void  runStepSlidingBeaterRandom();
void  runStepSlidingBeaterHeater();

void  runStepJugglerFaders(uint8_t fade = 20);
void  runStepJugglerFadersFaster();
void  runStepJugglerFadersFasterTwinkle();
void  runStepJugglerFadersLonger();
void  runStepJugglerFadersLongerTwinkle();

typedef struct {
    String name;
    void          (*call)();
    void          (*init)();
    unsigned long waitLoopMili;
    unsigned long waitFadeMili;
    bool          autoShowInit;
    bool          autoShowCall;
} ledChainListEntry;

extern ledChainListEntry ledChainList[];
extern CRGB ledStrandHoldColors[LED_STR_NUM];

extern uint8_t ledChainCallRefIndex;
extern uint8_t ledChainBaseColorHue;
extern int8_t  ledChainFadeLeveling;

#endif
