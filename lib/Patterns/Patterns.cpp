
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "Patterns.h"

SimplePatternList ledChainPatternItems = {
    runLedJuggleFadeFastPattern,
    runLedJuggleFadeNormPattern,
    runLedJuggleFadeLongPattern,
    runLedBpmCloudColorsPattern,
    runLedBpmLavaColorsPattern,
    runLedBpmRainbowNormalColorsPattern,
    runLedBpmRainbowStripeColorsPattern,
    runLedBpmForestColorsPattern,
    runLedBpmOceanColorsPattern,
    runLedBpmPartyColorsPattern,
    runLedBpmHeatColorsPattern,
    runLedRainbowPattern,
    runLedConfettiPattern,
    runLedRainbowWithGlitterPattern,
    runLedSinelonPattern
};

uint8_t ledChainPatternIndex = 0;
uint8_t ledChainBaseColorHue = 0;

void incrementSelectedPattern(int by)
{
    ledChainPatternIndex = (ledChainPatternIndex + 1) % ARRAY_SIZE(ledChainPatternItems);
}

void runLedRainbowPattern()
{
    fill_rainbow(ledStrandColors, LED_STRDS_LEN, ledChainBaseColorHue, 7);
}

void runLedRainbowWithGlitterPattern()
{
    runLedRainbowPattern();
    runLedGlitterPattern(80);
}

void runLedGlitterPattern(fract8 chance)
{
    if(random8() < chance) {
        ledStrandColors[random16(LED_STRDS_LEN)] += CRGB::White;
    }
}

void runLedConfettiPattern()
{
    int pos = random16(LED_STRDS_LEN);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 2);
    ledStrandColors[pos] += CHSV(ledChainBaseColorHue + random8(64), 200, 255);
}

void runLedSinelonPattern()
{
    int p = beatsin16(13, 0, LED_STRDS_LEN - 1);

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, 2);
    ledStrandColors[p] += CHSV(ledChainBaseColorHue, 255, 192);
}

void runLedBpmPattern(CRGBPalette16 palette, uint8_t time = 62)
{
    uint8_t b = beatsin8(time, 64, 255);

    for(int i = 0; i < LED_STRDS_LEN; i++) {
        ledStrandColors[i] = ColorFromPalette(palette, ledChainBaseColorHue + (i * 2), b-ledChainBaseColorHue+(i * 10));
    }
}

void runLedBpmCloudColorsPattern()
{
    runLedBpmPattern(CloudColors_p);
}

void runLedBpmLavaColorsPattern()
{
    runLedBpmPattern(LavaColors_p);
}

void runLedBpmRainbowNormalColorsPattern()
{
    runLedBpmPattern(RainbowColors_p);
}

void runLedBpmRainbowStripeColorsPattern()
{
    runLedBpmPattern(RainbowStripeColors_p);
}

void runLedBpmOceanColorsPattern()
{
    runLedBpmPattern(OceanColors_p);
}

void runLedBpmForestColorsPattern()
{
    runLedBpmPattern(ForestColors_p);
}

void runLedBpmPartyColorsPattern()
{
    runLedBpmPattern(PartyColors_p);
}

void runLedBpmHeatColorsPattern()
{
    runLedBpmPattern(HeatColors_p);
}

void runLedJugglePattern(uint8_t fade = 20) {
    byte dothue = 0;

    fadeToBlackBy(ledStrandColors, LED_STRDS_LEN, fade);

    for(int i = 0; i < 8; i++) {
        ledStrandColors[beatsin16(i + 7, 0, LED_STRDS_LEN - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void runLedJuggleFadeFastPattern()
{
    runLedJugglePattern(80);
}

void runLedJuggleFadeNormPattern()
{
    runLedJugglePattern(40);
}

void runLedJuggleFadeLongPattern()
{
    runLedJugglePattern(10);
}
