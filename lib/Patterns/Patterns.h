
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

#define LED_PATTERN_DELAY 100/LED_STRDS_FPS

void incSelectedStep(int by = 1);
void runSelectedStep();
bool runSelectedStepFadeOut();
bool runSelectedStepFadeIn();
void setBrightness(uint8_t level);
void setBrightnessNone();
void setBrightnessFull();
void ledFadeOut(uint8_t increment = 1);
void ledFadeIn();
void runLedGenericInit();
void  setLedSolidColor(uint8_t r = 150, uint8_t g = 150, uint8_t b = 150);
float getLedSolidGreenWait();
void  runLedSolidGreenStep();
float getLedSolidRedWait();
void  runLedSolidRedStep();
float getLedSolidBlueWait();
void  runLedSolidBlueStep();
float getLedRainbowWait();
void  runLedRainbowStep();
float getLedGlitterWait();
void  runLedGlitterStep(fract8 chance = 80);
float getLedRainbowWithGlitterWait();
void  runLedRainbowWithGlitterStep();
float getLedConfettiWait();
void  runLedConfettiStep();
float getLedSinelonWait();
void  runLedSinelonStep();
float getLedBpmWait();
void  runLedBpmStep(CRGBPalette16 palette, uint8_t time = 8);
float getLedBpmCloudColorsWait();
void  runLedBpmCloudColorsStep();
float getLedBpmLavaColorsWait();
void  runLedBpmLavaColorsStep();
float getLedBpmRainbowNormalColorsWait();
void  runLedBpmRainbowNormalColorsStep();
float getLedBpmRainbowStripeColorsWait();
void  runLedBpmRainbowStripeColorsStep();
float getLedBpmOceanColorsWait();
void  runLedBpmOceanColorsStep();
float getLedBpmForestColorsWait();
void  runLedBpmForestColorsStep();
float getLedBpmPartyColorsWait();
void  runLedBpmPartyColorsStep();
float getLedBpmHeatColorsWait();
void  runLedBpmHeatColorsStep();
float getLedJuggleWait();
void  runLedJuggleStep(uint8_t fade = 20);
float getLedJuggleFadeFastWait();
void  runLedJuggleFadeFastStep();
float getLedJuggleFadeNormWait();
void  runLedJuggleFadeNormStep();
float getLedJuggleFadeLongWait();
void  runLedJuggleFadeLongStep();

//typedef struct {
//    void (*init)();
//    void (*call)();
//    void (*wait)();
//} ledChainListEntry;

//extern ledChainListEntry ledChainList[100];

typedef void (*ledChainInitFuncsList[])();
typedef void (*ledChainCallFuncsList[])();
typedef float (*ledChainWaitTimesList[])();

extern ledChainInitFuncsList ledChainInitFuncs;
extern ledChainCallFuncsList ledChainCallFuncs;
extern ledChainWaitTimesList ledChainWaitTimes;

extern uint8_t ledChainCallRefIndex;
extern uint8_t ledChainBaseColorHue;

#endif
