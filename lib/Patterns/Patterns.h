
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#pragma once

#include "CommonArduino.h"
#include "CommonFastLED.h"
#include "Config.h"
#include "Random.h"
#include "Utilities.h"
#include "Counter.h"
#include "Strand.h"
#include "Palettes.h"
#include "PatternsList.h"
#include "PatternsAction.h"
#include "PatternsActionRunner.h"
#include "EffectDefinitionDetail.h"
#include "EffectDefinitionTimers.h"
#include "EffectDefinitionGlints.h"
#include "EffectFactor.h"
#include "EffectStatus.h"

extern const byte patternSizeItems;

unsigned int getLedPatternListSize();

const PatternsAction*         getLedPatternDeft();
const PatternsAction*         getLedPatternItem(const unsigned int idx);
const PatternsAction*         getLedPatternItem();
const EffectDefinitionDetail* getLedPatternItemActionDetail(const unsigned int idx);
const EffectDefinitionDetail* getLedPatternItemActionDetail();
const ActionRunnerPattern*    getLedPatternItemActionRunner(const unsigned int idx);
const ActionRunnerPattern*    getLedPatternItemActionRunner();
const EffectDefinitionTimers* getLedPatternItemActionTimers(const unsigned int idx);
const EffectDefinitionTimers* getLedPatternItemActionTimers();
const EffectDefinitionGlints* getLedPatternItemActionGlints(const unsigned int idx);
const EffectDefinitionGlints* getLedPatternItemActionGlints();

String       getLedPatternItemName(const unsigned int idx);
String       getLedPatternItemName();
const char*  getLedPatternItemNameC(const unsigned int idx);
const char*  getLedPatternItemNameC();
void       (*getLedPatternItemInit())();
void       (*getLedPatternItemCall())();
unsigned int getLedPatternItemCallExecSecs();
unsigned int getLedPatternItemRandHuesMili();

void runEffectAddonGlints();

void incPatternsStep();
void runPatternsStep(const bool wait = true);

void setCustomLedColorsActive();

void runInitGeneric();
void runStepGeneric();
void runStepTwinkle();

void runStepColoredStatic(const byte r = 150, const byte g = 150, const byte b = 150);
void runStepColoredStaticW();
void runStepColoredStaticR();
void runStepColoredStaticG();
void runStepColoredStaticB();

void runStepColoredBuilds(const byte r, const byte g, const byte b, const byte d = 25);
void runStepColoredBuildsW();
void runStepColoredBuildsR();
void runStepColoredBuildsG();
void runStepColoredBuildsB();

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

void runStepRainbowStatic();
void runStepRainbowNormal();
void runStepRainbowSliderNormal();
void runStepRainbowSliderStripe();

void runStepBuilder(const byte iterations = 4);
void runStepBuilderNormal();
void runStepBuilderFaster();

void runStepSinelon(const byte iterations = 6);
void runStepSinelonNormal();

void runStepSlidingBeater(const CRGBPalette16& palette, const byte time = 8);
void runStepSlidingBeaterClouds();
void runStepSlidingBeaterMagmas();
void runStepSlidingBeaterOceans();
void runStepSlidingBeaterForest();
void runStepSlidingBeaterRandom();
void runStepSlidingBeaterHeater();

void runStepPaletteRounds(const CRGBPalette16& palette, const int multiplier = 2, const bool blend = true);
void runStepPaletteRoundsClouds();
void runStepPaletteRoundsMagmas();
void runStepPaletteRoundsOceans();
void runStepPaletteRoundsForest();
void runStepPaletteRoundsRandom();
void runStepPaletteRoundsHeater();

void runStepPaletteCircle();

void runStepJuggler(const byte fade = 20);
void runStepJugglerFaster();
void runStepJugglerLonger();

void runStepRainbowFading(const byte bmp1 = 1, const byte bpm2 = 2);
void runStepRainbowFadingSlow();
void runStepRainbowFadingFast();
void runStepRainbowWholed();

unsigned int getLedPatternListRandIndx();
unsigned int getLedPatternListRandIndxSeql(bool internalIndex = false);
unsigned int getLedPatternListStepInit();
unsigned int getLedPatternListStepNext(const unsigned int idx);
unsigned int getLedPatternListStepIndx(const bool indexIncr = false);
unsigned int incLedPatternListStepIndx();
unsigned int getLedPatternListStepNumb();
unsigned int getLedPatternListStepNumbReal();

byte getByteNumStep(byte inc = 0);
byte incByteNumStep(byte add = 1);
