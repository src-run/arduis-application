
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

uint8_t ledBrightnessTracker = 0;

ledChainWaitTimesList ledChainWaitTimes = {
    getLedSolidWhiteWait,
    getLedSolidWhiteGlitterWait,
    getLedSolidGreenWait,
    getLedSolidGreenGlitterWait,
    getLedSolidRedWait,
    getLedSolidRedGlitterWait,
    getLedSolidBlueWait,
    getLedSolidBlueGlitterWait,
    getLedConfettiWait,
    getLedRainbowWait,
    getLedRainbowWithGlitterWait,
    getLedBpmRainbowNormalColorsWait,
    getLedBpmCloudColorsWait,
    getLedBpmLavaColorsWait,
    getLedBpmForestColorsWait,
    getLedBpmOceanColorsWait,
    getLedBpmPartyColorsWait,
    getLedBpmHeatColorsWait,
    getLedBpmRainbowStripeColorsWait,
    getLedJuggleFadeFastWait,
    getLedJuggleFadeNormWait,
    getLedJuggleFadeLongWait,
};

ledChainInitFuncsList ledChainInitFuncs = {
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
    runLedGenericInit,
};

ledChainCallFuncsList ledChainCallFuncs = {
    runLedSolidWhiteStep,
    runLedSolidWhiteGlitterStep,
    runLedSolidGreenStep,
    runLedSolidGreenGlitterStep,
    runLedSolidRedStep,
    runLedSolidRedGlitterStep,
    runLedSolidBlueStep,
    runLedSolidBlueGlitterStep,
    runLedConfettiStep,
    runLedRainbowStep,
    runLedRainbowWithGlitterStep,
    runLedBpmRainbowNormalColorsStep,
    runLedBpmCloudColorsStep,
    runLedBpmLavaColorsStep,
    runLedBpmForestColorsStep,
    runLedBpmOceanColorsStep,
    runLedBpmPartyColorsStep,
    runLedBpmHeatColorsStep,
    runLedBpmRainbowStripeColorsStep,
    runLedJuggleFadeFastStep,
    runLedJuggleFadeNormStep,
    runLedJuggleFadeLongStep,
};

uint8_t ledChainCallRefIndex = 99;
uint8_t ledChainBaseColorHue = 0;

bool sanityCheckFuncPointers()
{
    if ((ARRAY_SIZE(ledChainCallFuncs)) != (ARRAY_SIZE(ledChainInitFuncs))) {
        return false;
    }

    if ((ARRAY_SIZE(ledChainCallFuncs)) != (ARRAY_SIZE(ledChainWaitTimes))) {
        return false;
    }

    return true;
}

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

void runSelectedStep(bool wait)
{
    ledChainCallFuncs[ledChainCallRefIndex]();

    FastLED.show();

    if (wait) {
        FastLED.delay(ledChainWaitTimes[ledChainCallRefIndex]());
    }
}

bool runSelectedStepFadeOut()
{
    if (ledBrightnessTracker > 0) {
        ledBrightnessTracker--;
    }

    setBrightness(ledBrightnessTracker);
    FastLED.delay(LED_PATTERN_TRAN_DELAY);

    if (ledBrightnessTracker == 0) {
        FastLED.delay(LED_PATTERN_NEXT_DELAY);
    }

    return ledBrightnessTracker > 0;
}

bool runSelectedStepFadeIn()
{
    if (ledBrightnessTracker < LED_STRDS_BRT) {
        ledBrightnessTracker++;
    }

    setBrightness(ledBrightnessTracker);
    FastLED.delay(LED_PATTERN_TRAN_DELAY);

    return ledBrightnessTracker < LED_STRDS_BRT;
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

void runLedGenericInit()
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(0, 0, 0));
    FastLED.show();
}

void setLedSolidColor(uint8_t r, uint8_t g, uint8_t b)
{
    fill_solid(ledStrandColors, LED_STRDS_LEN, CRGB(r, g, b));
}

void setLedSolidColorGlitter(uint8_t r, uint8_t g, uint8_t b)
{
    setLedSolidColor(r, g, b);
    runLedGlitterStep(100);
}

float getLedSolidWhiteWait()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runLedSolidWhiteStep() {
    setLedSolidColor(120, 120, 120);
}

float getLedSolidGreenWait()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runLedSolidGreenStep() {
    setLedSolidColor(0, 255, 0);
}

float getLedSolidRedWait()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runLedSolidRedStep() {
    setLedSolidColor(255, 0, 0);
}

float getLedSolidBlueWait()
{
	return LED_PATTERN_STEP_DELAY * 10;
}

void runLedSolidBlueStep() {
    setLedSolidColor(0, 0, 255);
}

float getLedSolidWhiteGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedSolidWhiteGlitterStep() {
    setLedSolidColorGlitter(120, 120, 120);
}

float getLedSolidGreenGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedSolidGreenGlitterStep() {
    setLedSolidColorGlitter(0, 255, 0);
}

float getLedSolidRedGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedSolidRedGlitterStep() {
    setLedSolidColorGlitter(255, 0, 0);
}

float getLedSolidBlueGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedSolidBlueGlitterStep() {
    setLedSolidColorGlitter(0, 0, 255);
}

float getLedRainbowWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedRainbowStep()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, ledChainBaseColorHue, 7);
}

float getLedRainbowWithGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedRainbowWithGlitterStep()
{
    runLedRainbowStep();
    runLedGlitterStep(100);
}

float getLedGlitterWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedGlitterStep(fract8 chance)
{
    if(random8() < chance) {
        ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::White;
        ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::White;
        ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::White;
    }
}

float getLedConfettiWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedConfettiStep()
{
    int pos = random16(LED_STRDS_LEN);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 0);
    ledStrandColors[pos] += CHSV(ledChainBaseColorHue + random8(64), 200, 255);
}

float getLedSinelonWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedSinelonStep()
{
    int p = beatsin16(13, 0, LED_STRDS_LEN - 1);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 2);
    ledStrandColors[p] += CHSV(ledChainBaseColorHue, 255, 192);
}

float getLedBpmWait()
{
	return LED_PATTERN_STEP_DELAY;
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
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmCloudColorsStep()
{
    runLedBpmStep(CloudColors_p);
}

float getLedBpmLavaColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmLavaColorsStep()
{
    runLedBpmStep(LavaColors_p);
}

float getLedBpmRainbowNormalColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmRainbowNormalColorsStep()
{
    runLedBpmStep(RainbowColors_p);
}

float getLedBpmRainbowStripeColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmRainbowStripeColorsStep()
{
    runLedBpmStep(RainbowStripeColors_p);
}

float getLedBpmOceanColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmOceanColorsStep()
{
    runLedBpmStep(OceanColors_p);
}

float getLedBpmForestColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmForestColorsStep()
{
    runLedBpmStep(ForestColors_p);
}

float getLedBpmPartyColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmPartyColorsStep()
{
    runLedBpmStep(PartyColors_p);
}

float getLedBpmHeatColorsWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedBpmHeatColorsStep()
{
    runLedBpmStep(HeatColors_p);
}

float getLedJuggleWait()
{
	return LED_PATTERN_STEP_DELAY;
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
	return LED_PATTERN_STEP_DELAY;
}

void runLedJuggleFadeFastStep()
{
    runLedJuggleStep(80);
}

float getLedJuggleFadeNormWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedJuggleFadeNormStep()
{
    runLedJuggleStep(40);
}

float getLedJuggleFadeLongWait()
{
	return LED_PATTERN_STEP_DELAY;
}

void runLedJuggleFadeLongStep()
{
    runLedJuggleStep(10);
}
