
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
#include "Palettes.h"
#include "Output.h"
#include "Utilities.h"

#define LED_PTN_STEP_MILI 1000 / LED_STR_FPS
#define LED_PTN_NEXT_MILI 0
#define LED_PTN_FADE_MILI LED_PTN_STEP_MILI
#define LED_PTN_FADE_STEP LED_STR_BRT / 4
#define LED_PTN_FADE_ENBL ((bool)true)
#define LED_PTN_INIT_RAND ((bool)false)
#define LED_PTN_CPAL_RAND ((bool)true)

int16_t getRandRefIndex();

void  incSelectedStep(bool fade = LED_PTN_FADE_ENBL);
void  runSelectedStep(bool wait = true);
bool  runSelectedStepFadeInit(int increment = LED_PTN_FADE_STEP);
bool  runSelectedStepFadeEnds(int decrement = LED_PTN_FADE_STEP);

void  setHoldColoursActive();
void  runStepHoldingColors();

void  runStepTwinkle(uint8_t level = 120, fract8 chance = 40, uint8_t iterations = 8);

void  runInitGeneric();
void  runInitColoredStatic(uint8_t r, uint8_t g, uint8_t b);
void  runInitColoredStaticW();
void  runInitColoredStaticR();
void  runInitColoredStaticG();
void  runInitColoredStaticB();

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
void  runStepRainbowNormalTwinkle();
void  runStepRainbowSliderNormal();
void  runStepRainbowSliderStripe();

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

void  runStepPaletteRounds(CRGBPalette16 palette);
void  runStepPaletteRoundsClouds();
void  runStepPaletteRoundsMagmas();
void  runStepPaletteRoundsOceans();
void  runStepPaletteRoundsForest();
void  runStepPaletteRoundsRandom();
void  runStepPaletteRoundsHeater();
void  runStepPaletteRoundsCloudsTwinkle();
void  runStepPaletteRoundsMagmasTwinkle();
void  runStepPaletteRoundsOceansTwinkle();
void  runStepPaletteRoundsForestTwinkle();
void  runStepPaletteRoundsRandomTwinkle();
void  runStepPaletteRoundsHeaterTwinkle();

void  runStepPaletteCircle();

void  runStepJuggler(uint8_t fade = 20);
void  runStepJugglerFaster();
void  runStepJugglerFasterTwinkle();
void  runStepJugglerLonger();
void  runStepJugglerLongerTwinkle();

void runStepRainbowFading(uint8_t bmp1 = 1, uint8_t bpm2 = 2);
void runStepRainbowFadingSlow();
void runStepRainbowFadingFast();
void runStepRainbowWholed();

typedef struct {
    const char *name;
    void      (*call)();
    void      (*init)();
    uint32_t   callExecMili;
    uint32_t   randHuesMili;
    uint32_t   waitLoopMili;
    uint32_t   waitFadeMili;
} ledPatternListEntry;

extern const ledPatternListEntry ledPatternList[];
extern const uint16_t            ledPatternSize;

extern CRGB ledStrandHoldColors[LED_STR_NUM];

extern int16_t ledPatternCallRefIndex;
extern int16_t ledPatternFadeLeveling;
extern uint8_t ledPatternBaseColorHue;

#endif
