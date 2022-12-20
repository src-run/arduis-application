
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

#define LED_PATTERN_STEP_DELAY 2000/LED_STRDS_FPS
#define LED_PATTERN_TRAN_DELAY LED_PATTERN_STEP_DELAY
#define LED_PATTERN_NEXT_DELAY 0

uint16_t rgbMin(uint16_t val, uint16_t min = 0);
uint16_t rgbMax(uint16_t val, uint16_t max = 255);
void  incSelectedStep(int by = 1);
void  runSelectedStep(bool wait = true);
bool  runSelectedStepFadeOut();
bool  runSelectedStepFadeIn();
void  setBrightness(uint8_t level);
void  setBrightnessNone();
void  setBrightnessFull();
void  ledFadeOut(uint8_t increment = 1);
void  ledFadeIn();
void  runInitGeneric();
float getWaitGeneric();
float getWaitColoredStaticGeneric();
void  runStepColoredStatic(uint8_t r = 150, uint8_t g = 150, uint8_t b = 150);
void  runStepColoredStaticWithTwinkle(uint8_t r = 150, uint8_t g = 150, uint8_t b = 150);
void  runStepColoredStaticWhite();
void  runStepColoredStaticGreen();
void  runStepColoredStaticRed();
void  runStepColoredStaticBlue();
void  runStepColoredStaticWhiteWithTwinkle();
void  runStepColoredStaticGreenWithTwinkle();
void  runStepColoredStaticRedWithTwinkle();
void  runStepColoredStaticBlueWithTwinkle();
float getWaitColoredStaticGenericBuilder();
void  runStepColoredStaticBuilder(uint8_t r, uint8_t g, uint8_t b, uint8_t d = 25);
void  runStepColoredStaticWithTwinkleBuilder(uint8_t r, uint8_t g, uint8_t b, uint8_t d = 25);
void  runStepColoredStaticWhiteBuilder();
void  runStepColoredStaticGreenBuilder();
void  runStepColoredStaticRedBuilder();
void  runStepColoredStaticBlueBuilder();
void  runStepRainbowStatic();
void  runStepRainbowStaticWithTwinkle();
void  runStepRainbowNormal();
void  runStepWithTwinkle(fract8 chance = 80);
void  runStepRainbowNormalWithTwinkle();
void  runStepBuilderNormal();
void  runStepBuilderNormalWithTwinkle();
void  runStepSinelonNormal();
void  runStepSinelonNormalWithTwinkle();
void  runStepSlidingBeat(CRGBPalette16 palette, uint8_t time = 8);
void  runStepSlidingBeatCloud();
void  runStepSlidingBeatLava();
void  runStepRainbowSliderNormal();
void  runStepRainbowSliderStripe();
void  runStepSlidingBeatOcean();
void  runStepSlidingBeatForest();
void  runStepSlidingBeatParty();
void  runStepSlidingBeatHeat();
void  runStepJuggler(uint8_t fade = 20);
void  runStepJugglerFadeFast();
void  runStepJugglerFadeNorm();
void  runStepJugglerFadeLong();

typedef struct {
    String name;
    void  (*call)();
    void  (*init)();
    float (*wait)();
} ledChainListEntry;

extern ledChainListEntry ledChainList[];

extern uint8_t ledChainCallRefIndex;
extern uint8_t ledChainBaseColorHue;
extern int8_t  ledChainFadeLeveling;

#endif
