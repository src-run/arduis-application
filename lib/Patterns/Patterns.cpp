
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

ledChainWaitTimesList ledChainWaitTimes = {
    getLedSolidGreenWait,
    getLedConfettiWait,
    getLedSolidRedWait,
    getLedBpmCloudColorsWait,
    getLedSolidBlueWait,
    getLedBpmLavaColorsWait,
};

ledChainInitFuncsList ledChainInitFuncs = {
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
};

ledChainCallFuncsList ledChainCallFuncs = {
    runLedSolidGreenStep,
    runLedConfettiStep,
    runLedSolidRedStep,
    runLedBpmCloudColorsStep,
    runLedSolidBlueStep,
    runLedBpmLavaColorsStep,
//    runLedRainbowStep,
//    runLedRainbowWithGlitterStep,
//    runLedBpmRainbowNormalColorsStep,
};
//    runLedBpmRainbowStripeColorsStep,
//    runLedJuggleFadeFastStep,
//    runLedJuggleFadeNormStep,
//    runLedJuggleFadeLongStep,
//    ,
//    ,
//    runLedBpmForestColorsStep,
//    runLedBpmOceanColorsStep,
//    runLedBpmPartyColorsStep,
//    runLedBpmHeatColorsStep,

uint8_t ledChainCallRefIndex = 99;
uint8_t ledChainBaseColorHue = 0;

void incSelectedStep(int by)
{
    if (ledChainCallRefIndex == 99) {
        ledChainCallRefIndex = 0;
    } else {
        ledChainCallRefIndex = (ledChainCallRefIndex + 1) % ARRAY_SIZE(ledChainCallFuncs);
    }

    ledChainInitFuncs[ledChainCallRefIndex]();

    char str[100];
    sprintf(str, "Selecting pattern index %d of %d.", ledChainCallRefIndex + 1, ARRAY_SIZE(ledChainCallFuncs));
    Serial.println(str);
}

void runSelectedStep()
{
    ledChainCallFuncs[ledChainCallRefIndex]();

    FastLED.show();
    FastLED.delay(ledChainWaitTimes[ledChainCallRefIndex]());
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

bool runSelectedStepFadeOut()
{
    for (int i = LED_STRDS_BRT; i > 0; i++) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_DELAY);
    }

    setBrightnessNone();

    FastLED.delay(LED_PATTERN_DELAY * 100);

    return true;
}

bool runSelectedStepFadeIn()
{
    for (int i = 0; i <= LED_STRDS_BRT; i++) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_DELAY);
    }

    setBrightnessFull();

    FastLED.delay(LED_PATTERN_DELAY * 2);

    return true;
}

void ledFadeOut(uint8_t increment)
{
    for (int i = LED_STRDS_BRT; i > 0; i = i - increment) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_DELAY);
    }

    setBrightnessNone();

    FastLED.delay(LED_PATTERN_DELAY * 100);
}

void ledFadeIn()
{
    for (int i = 0; i <= LED_STRDS_BRT; i++) {
        setBrightness(i);
        FastLED.delay(LED_PATTERN_DELAY);
    }

    setBrightnessFull();

    FastLED.delay(LED_PATTERN_DELAY * 2);
}

void runLedGenericInit()
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(0, 0, 0));
    FastLED.show();
}

void setLedSolidColor(uint8_t r, uint8_t g, uint8_t b)
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(r, g, b));
}

float getLedSolidGreenWait()
{
	return LED_PATTERN_DELAY;
}

void runLedSolidGreenStep() {
    setLedSolidColor(255,0,0);
}

float getLedSolidRedWait()
{
	return LED_PATTERN_DELAY;
}

void runLedSolidRedStep() {
    setLedSolidColor(0,255,0);
}

float getLedSolidBlueWait()
{
	return LED_PATTERN_DELAY;
}

void runLedSolidBlueStep() {
    setLedSolidColor(0,0,255);
}

float getLedRainbowWait()
{
	return LED_PATTERN_DELAY;
}

void runLedRainbowStep()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, ledChainBaseColorHue, 7);
}

float getLedRainbowWithGlitterWait()
{
	return LED_PATTERN_DELAY;
}

void runLedRainbowWithGlitterStep()
{
    runLedRainbowStep();
    runLedGlitterStep(80);
}

float getLedGlitterWait()
{
	return LED_PATTERN_DELAY;
}

void runLedGlitterStep(fract8 chance)
{
    if(random8() < chance) {
        ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::White;
    }
}

float getLedConfettiWait()
{
	return LED_PATTERN_DELAY;
}

void runLedConfettiStep()
{
    int pos = random16(LED_STRDS_LEN);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 0);
    ledStrandColors[pos] += CHSV(ledChainBaseColorHue + random8(64), 200, 255);
}

float getLedSinelonWait()
{
	return LED_PATTERN_DELAY;
}

void runLedSinelonStep()
{
    int p = beatsin16(13, 0, LED_STRDS_LEN - 1);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 2);
    ledStrandColors[p] += CHSV(ledChainBaseColorHue, 255, 192);
}

float getLedBpmWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmStep(CRGBPalette16 palette, uint8_t time)
{
    uint8_t b = beatsin8(time, 64, 180);

    for(int i = 0; i < LED_STRDS_LEN; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledChainBaseColorHue + (i * 2), b-ledChainBaseColorHue+(i * 10));
    }
}

float getLedBpmCloudColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmCloudColorsStep()
{
    runLedBpmStep(CloudColors_p);
}

float getLedBpmLavaColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmLavaColorsStep()
{
    runLedBpmStep(LavaColors_p);
}

float getLedBpmRainbowNormalColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmRainbowNormalColorsStep()
{
    runLedBpmStep(RainbowColors_p);
}

float getLedBpmRainbowStripeColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmRainbowStripeColorsStep()
{
    runLedBpmStep(RainbowStripeColors_p);
}

float getLedBpmOceanColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmOceanColorsStep()
{
    runLedBpmStep(OceanColors_p);
}

float getLedBpmForestColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmForestColorsStep()
{
    runLedBpmStep(ForestColors_p);
}

float getLedBpmPartyColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmPartyColorsStep()
{
    runLedBpmStep(PartyColors_p);
}

float getLedBpmHeatColorsWait()
{
	return LED_PATTERN_DELAY;
}

void runLedBpmHeatColorsStep()
{
    runLedBpmStep(HeatColors_p);
}

float getLedJuggleWait()
{
	return LED_PATTERN_DELAY;
}

void runLedJuggleStep(uint8_t fade) {
    byte dothue = 0;

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, fade);

    for(int i = 0; i < 8; i++) {
        ledStrandColors[beatsin16(i + 7, 0, LED_STRDS_LEN - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

float getLedJuggleFadeFastWait()
{
	return LED_PATTERN_DELAY;
}

void runLedJuggleFadeFastStep()
{
    runLedJuggleStep(80);
}

float getLedJuggleFadeNormWait()
{
	return LED_PATTERN_DELAY;
}

void runLedJuggleFadeNormStep()
{
    runLedJuggleStep(40);
}

float getLedJuggleFadeLongWait()
{
	return LED_PATTERN_DELAY;
}

void runLedJuggleFadeLongStep()
{
    runLedJuggleStep(10);
}
