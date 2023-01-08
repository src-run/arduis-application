
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "Common.h"
#include "Strand.h"
#include "Palettes.h"

struct ledPatternItem {
    const char        *name;
    void             (*call)();
    void             (*init)();
    const unsigned int callExecSecs;
    const byte         randHuesMili;
    const byte         waitLoopMili;
    const byte         waitFadeMili;
    const byte         glintsChance;
    const byte         rejectChance;
};
//glintsChance
//rejectChance
extern const ledPatternItem ledPatternList[];
extern byte                 ledPatternSeql[];
extern const ledPatternItem ledPatternDeft;

extern bool ledPatternGlintEnabled;
extern int  ledPatternFadeLeveling;

extern bool ledPatternStepInit;
extern bool ledPatternStepRuns;

unsigned int          getLedPatternListSize(const int adds = 0);
const ledPatternItem *getLedPatternDeft();
const ledPatternItem *getLedPatternItem(const unsigned int idx);
const ledPatternItem *getLedPatternItem();
String                getLedPatternItemName(const unsigned int idx);
String                getLedPatternItemName();
const char           *getLedPatternItemNameC(const unsigned int idx);
const char           *getLedPatternItemNameC();
void                (*getLedPatternItemInit())();
void                (*getLedPatternItemCall())();
unsigned int          getLedPatternItemCallExecSecs();
unsigned long         getLedPatternItemRandHuesMili();
unsigned long         getLedPatternItemWaitLoopMili();
unsigned long         getLedPatternItemWaitFadeMili();
unsigned int          getLedPatternItemGlintsChance();
unsigned int          getLedPatternItemRejectChance();

bool hasLedPatternItemGlints();
void addLedPatternItemGlints();
void setLedPatternItemGlintsState();

void incPatternsStep();
void runPatternsStep(const bool wait = true);
bool runPatternsFadeToColor(const bool fade = true, const int increment = LED_PTN_FADE_STEP);
bool runPatternsFadeToBlack(const bool fade = true, const int decrement = LED_PTN_FADE_STEP);
bool runPatternsFadeToColorInner(const int increment);
bool runPatternsFadeToBlackInner(const int decrement);

void setCustomLedColorsActive();

void runStepTwinkle(const byte min = LED_PTN_TWIK_MINL, const byte lim = LED_PTN_TWIK_MAXL, const byte itr = LED_PTN_TWIK_RAND);

void runInitGeneric();

void runStepGeneric();

void runStepColoredStatic(const byte r = 150, const byte g = 150, const byte b = 150);
void runStepColoredStaticW();
void runStepColoredStaticR();
void runStepColoredStaticG();
void runStepColoredStaticB();
void runStepColoredStaticWTwinkle();
void runStepColoredStaticRTwinkle();
void runStepColoredStaticGTwinkle();
void runStepColoredStaticBTwinkle();

void runStepColoredBuilds(const byte r, const byte g, const byte b, const byte d = 25);
void runStepColoredBuildsW();
void runStepColoredBuildsR();
void runStepColoredBuildsG();
void runStepColoredBuildsB();
void runStepColoredBuildsWTwinkle();
void runStepColoredBuildsRTwinkle();
void runStepColoredBuildsGTwinkle();
void runStepColoredBuildsBTwinkle();

void runInitColoredVaried(const byte r, const byte g, const byte b, const byte d = 100);
void runInitColoredVariedW();
void runInitColoredVariedR();
void runInitColoredVariedG();
void runInitColoredVariedB();

void runStepColoredVaried();
void runStepColoredVariedW();
void runStepColoredVariedR();
void runStepColoredVariedG();
void runStepColoredVariedB();
void runStepColoredVariedTwinkle();
void runStepColoredVariedWTwinkle();
void runStepColoredVariedRTwinkle();
void runStepColoredVariedGTwinkle();
void runStepColoredVariedBTwinkle();

void runStepRainbowStatic();
void runStepRainbowStaticTwinkle();
void runStepRainbowNormal();
void runStepRainbowNormalTwinkle();
void runStepRainbowSliderNormal();
void runStepRainbowSliderStripe();

void runStepBuilder(const byte iterations = 4);
void runStepBuilderNormal();
void runStepBuilderNormalTwinkle();
void runStepBuilderFaster();
void runStepBuilderFasterTwinkle();

void runStepSinelon(const byte iterations = 6);
void runStepSinelonNormal();
void runStepSinelonNormalTwinkle();

void runStepSlidingBeater(const CRGBPalette16 palette, const byte time = 8);
void runStepSlidingBeaterClouds();
void runStepSlidingBeaterMagmas();
void runStepSlidingBeaterOceans();
void runStepSlidingBeaterForest();
void runStepSlidingBeaterRandom();
void runStepSlidingBeaterHeater();

void runStepPaletteRounds(const CRGBPalette16 palette, const int multiplier = 2, const bool blend = true);
void runStepPaletteRoundsClouds();
void runStepPaletteRoundsMagmas();
void runStepPaletteRoundsOceans();
void runStepPaletteRoundsForest();
void runStepPaletteRoundsRandom();
void runStepPaletteRoundsHeater();
void runStepPaletteRoundsCloudsTwinkle();
void runStepPaletteRoundsMagmasTwinkle();
void runStepPaletteRoundsOceansTwinkle();
void runStepPaletteRoundsForestTwinkle();
void runStepPaletteRoundsRandomTwinkle();
void runStepPaletteRoundsHeaterTwinkle();

void runStepPaletteCircle();
void runStepPaletteCircleTwinkle();

void runStepJuggler(const byte fade = 20);
void runStepJugglerFaster();
void runStepJugglerFasterTwinkle();
void runStepJugglerLonger();
void runStepJugglerLongerTwinkle();

void runStepRainbowFading(const byte bmp1 = 1, const byte bpm2 = 2);
void runStepRainbowFadingSlow();
void runStepRainbowFadingFast();
void runStepRainbowWholed();

unsigned int getLedPatternListRandIndx();
unsigned int getLedPatternListRandIndxSeql();
unsigned int getLedPatternListStepInit();
unsigned int getLedPatternListStepNext(const unsigned int idx);
unsigned int getLedPatternListStepIndx(const bool inc = false);
unsigned int incLedPatternListStepIndx();
unsigned int getLedPatternListStepNumb();

byte getByteNumStep(byte inc = 0);
byte incByteNumStep(byte add = 1);
