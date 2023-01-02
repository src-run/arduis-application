
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
    fract8        skipItemFrac;
} ledPatternItem;

extern const ledPatternItem ledPatternList[];

extern int  ledPatternFadeLeveling;
extern byte ledPatternBaseColorHue;

extern bool ledPatternStepInit;
extern bool ledPatternStepRuns;

typedef int (*fptr)();

const unsigned int    getLedPatternListSize();
const ledPatternItem *getLedPatternItem(const unsigned int idx);
const ledPatternItem *getLedPatternItem();
const String          getLedPatternItemName(const unsigned int idx);
const String          getLedPatternItemName();
const unsigned long   getLedPatternItemCallExecMili();
const unsigned long   getLedPatternItemRandHuesMili();
const unsigned long   getLedPatternItemWaitLoopMili();
const unsigned long   getLedPatternItemWaitFadeMili();

int getRandRefIndex();

void  incSelectedStep(const bool fade = LED_PTN_FADE_ENBL);
void  runSelectedStep(const bool wait = true);
bool  runSelectedStepFadeInit(const int increment = LED_PTN_FADE_STEP);
bool  runSelectedStepFadeEnds(const int decrement = LED_PTN_FADE_STEP);

void  setHoldColoursActive();
void  runStepHoldingColors();

void  runStepTwinkle(const byte inc, const byte minLevel, const byte maxLevel);
void  runStepTwinkle(const byte inc, const byte maxLevel);
void  runStepTwinkle(const byte inc = LED_PTN_TWIK_RAND);

void  runInitGeneric();
void  runInitColoredStatic(const byte r, const byte g, const byte b);
void  runInitColoredStaticW();
void  runInitColoredStaticR();
void  runInitColoredStaticG();
void  runInitColoredStaticB();

void  runStepGeneric();

void  runStepColoredStatic(const byte r = 150, const byte g = 150, const byte b = 150);
void  runStepColoredStaticW();
void  runStepColoredStaticR();
void  runStepColoredStaticG();
void  runStepColoredStaticB();
void  runStepColoredStaticWTwinkle();
void  runStepColoredStaticRTwinkle();
void  runStepColoredStaticGTwinkle();
void  runStepColoredStaticBTwinkle();

void  runStepColoredBuilds(const byte r, const byte g, const byte b, const byte d = 25);
void  runStepColoredBuildsW();
void  runStepColoredBuildsR();
void  runStepColoredBuildsG();
void  runStepColoredBuildsB();
void  runStepColoredBuildsWTwinkle();
void  runStepColoredBuildsRTwinkle();
void  runStepColoredBuildsGTwinkle();
void  runStepColoredBuildsBTwinkle();

void  runInitColoredVaried(const byte r, const byte g, const byte b, const byte d = 100);
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

void  runStepBuilder(const byte iterations = 4);
void  runStepBuilderNormal();
void  runStepBuilderNormalTwinkle();
void  runStepBuilderFaster();
void  runStepBuilderFasterTwinkle();

void  runStepSinelon(const byte iterations = 6);
void  runStepSinelonNormal();
void  runStepSinelonNormalTwinkle();

void  runStepSlidingBeater(const CRGBPalette16 palette, const byte time = 8);
void  runStepSlidingBeaterClouds();
void  runStepSlidingBeaterMagmas();
void  runStepSlidingBeaterOceans();
void  runStepSlidingBeaterForest();
void  runStepSlidingBeaterRandom();
void  runStepSlidingBeaterHeater();

void  runStepPaletteRounds(const CRGBPalette16 palette);
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

void  runStepJuggler(const byte fade = 20);
void  runStepJugglerFaster();
void  runStepJugglerFasterTwinkle();
void  runStepJugglerLonger();
void  runStepJugglerLongerTwinkle();

void runStepRainbowFading(const byte bmp1 = 1, const byte bpm2 = 2);
void runStepRainbowFadingSlow();
void runStepRainbowFadingFast();
void runStepRainbowWholed();

unsigned int getLedPatternListRandIndx();
unsigned int getLedPatternListStepInit();
unsigned int getLedPatternListStepNext(const unsigned int idx);
unsigned int getLedPatternListStepIndx(const bool inc = false);
unsigned int incLedPatternListStepIndx();
unsigned int getLedPatternListStepNumb();


#endif
