
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
#include "Config.h"
#include "Utilities.h"

typedef struct {
    const char   *name;
    void        (*call)();
    void        (*init)();
    unsigned long callExecMili;
    unsigned long randHuesMili;
    unsigned long waitLoopMili;
    unsigned long waitFadeMili;
} ledPatternItem;

extern const ledPatternItem ledPatternList[];

extern CRGB ledStrandHoldColors[LED_STR_NUM];

extern int  ledPatternFadeLeveling;
extern byte ledPatternBaseColorHue;

extern bool ledPatternStepInit;
extern bool ledPatternStepRuns;

typedef int (*fptr)();

ledPatternItem      getLedPatternItem();
const String        getLedPatternName();
const unsigned long getLedPatternCallExecMili();
const unsigned long getLedPatternRandHuesMili();
const unsigned long getLedPatternWaitLoopMili();
const unsigned long getLedPatternWaitFadeMili();

int getRandRefIndex();

void  incSelectedStep(bool fade = LED_PTN_FADE_ENBL);
void  runSelectedStep(bool wait = true);
bool  runSelectedStepFadeInit(int increment = LED_PTN_FADE_STEP);
bool  runSelectedStepFadeEnds(int decrement = LED_PTN_FADE_STEP);

void  setHoldColoursActive();
void  runStepHoldingColors();

void  runStepTwinkle(const byte inc, const byte minLevel, const byte maxLevel);
void  runStepTwinkle(const byte inc, const byte maxLevel);
void  runStepTwinkle(const byte inc = 8);

void  runInitGeneric();
void  runInitColoredStatic(byte r, byte g, byte b);
void  runInitColoredStaticW();
void  runInitColoredStaticR();
void  runInitColoredStaticG();
void  runInitColoredStaticB();

void  runStepGeneric();

void  runStepColoredStatic(byte r = 150, byte g = 150, byte b = 150);
void  runStepColoredStaticW();
void  runStepColoredStaticR();
void  runStepColoredStaticG();
void  runStepColoredStaticB();
void  runStepColoredStaticWTwinkle();
void  runStepColoredStaticRTwinkle();
void  runStepColoredStaticGTwinkle();
void  runStepColoredStaticBTwinkle();

void  runStepColoredBuilds(byte r, byte g, byte b, byte d = 25);
void  runStepColoredBuildsW();
void  runStepColoredBuildsR();
void  runStepColoredBuildsG();
void  runStepColoredBuildsB();
void  runStepColoredBuildsWTwinkle();
void  runStepColoredBuildsRTwinkle();
void  runStepColoredBuildsGTwinkle();
void  runStepColoredBuildsBTwinkle();

void  runInitColoredVaried(byte r, byte g, byte b, byte d = 100);
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

void  runStepBuilder(byte iterations = 4);
void  runStepBuilderNormal();
void  runStepBuilderNormalTwinkle();
void  runStepBuilderFaster();
void  runStepBuilderFasterTwinkle();

void  runStepSinelon(byte iterations = 6);
void  runStepSinelonNormal();
void  runStepSinelonNormalTwinkle();

void  runStepSlidingBeater(CRGBPalette16 palette, byte time = 8);
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
void  runStepPaletteCircleTwinkle();

void  runStepJuggler(byte fade = 20);
void  runStepJugglerFaster();
void  runStepJugglerFasterTwinkle();
void  runStepJugglerLonger();
void  runStepJugglerLongerTwinkle();

void runStepRainbowFading(byte bmp1 = 1, byte bpm2 = 2);
void runStepRainbowFadingSlow();
void runStepRainbowFadingFast();
void runStepRainbowWholed();

unsigned int getLedPatternListSize();
unsigned int getLedPatternListRandIndx();
unsigned int getLedPatternListStepInit();
unsigned int getLedPatternListStepNext(unsigned int idx);
unsigned int getLedPatternListStepIndx(bool inc = false);
unsigned int incLedPatternListStepIndx();
unsigned int getLedPatternListStepNumb();

const ledPatternItem *getLedPatternListStepItem(unsigned int idx);
const ledPatternItem *getLedPatternListStepItem();

#endif
