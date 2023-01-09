
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "PatternsList.h"

const PatternsAction patternListItems[] {
    {
        { "palette-circle", 20 },
        { runStepPaletteCircle, nullptr },
        { LED_PTN_SEC_CYCLE * 6, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-static", 20 },
        { runStepRainbowStatic, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-normal", 0 },
        { runStepRainbowNormal, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-slider-normal", 40 },
        { runStepRainbowSliderNormal, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-slider-stripe", 40 },
        { runStepRainbowSliderStripe, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "builder-faster", 20 },
        { runStepBuilderFaster, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "builder-normal", 0 },
        { runStepBuilderNormal, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-clouds", 40 },
        { runStepSlidingBeaterClouds, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-clouds", 20 },
        { runStepPaletteRoundsClouds, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-magmas", 40 },
        { runStepSlidingBeaterMagmas, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-magmas", 20 },
        { runStepPaletteRoundsMagmas, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-forest", 40 },
        { runStepSlidingBeaterForest, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-forest", 20 },
        { runStepPaletteRoundsForest, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-oceans", 40 },
        { runStepSlidingBeaterOceans, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-oceans", 20 },
        { runStepPaletteRoundsOceans, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-random", 40 },
        { runStepSlidingBeaterRandom, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-random", 20 },
        { runStepPaletteRoundsRandom, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sliding-beater-heater", 40 },
        { runStepSlidingBeaterHeater, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "palette-rounds-heater", 20 },
        { runStepPaletteRoundsHeater, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "juggler-faster", 20 },
        { runStepJugglerFaster, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "juggler-longer", 0 },
        { runStepJugglerLonger, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "sinelon-normal", 20 },
        { runStepSinelonNormal, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-static-w", 20 },
        { runStepColoredStaticW, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-varied-w", 20 },
        { runStepColoredVariedW,             runInitColoredVariedW },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-builds-w", 10 },
        { runStepColoredBuildsW, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-static-r", 20 },
        { runStepColoredStaticR, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-varied-r", 20 },
        { runStepColoredVariedR,             runInitColoredVariedR },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-builds-r", 10 },
        { runStepColoredBuildsR, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-static-g", 20 },
        { runStepColoredStaticG, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-varied-g", 20 },
        { runStepColoredVariedG,             runInitColoredVariedG },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-builds-g", 10 },
        { runStepColoredBuildsG, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-static-b", 20 },
        { runStepColoredStaticB, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-varied-b", 20 },
        { runStepColoredVariedB,             runInitColoredVariedB },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "colored-builds-b", 10 },
        { runStepColoredBuildsB, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    /*
    {
        { "rainbow-wholed-slow", 100 },
        { runStepRainbowWholed, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR * 8 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-wholed-fast", 100 },
        { runStepRainbowWholed, nullptr },
        { LED_PTN_SEC_CYCLE / 2, LED_STR_MIL_COLOR / 6 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-fading-slow", 100 },
        { runStepRainbowFadingSlow, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR * 2 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    {
        { "rainbow-fading-fast", 100 },
        { runStepRainbowFadingFast, nullptr },
        { LED_PTN_SEC_CYCLE, LED_STR_MIL_COLOR * 2 },
        { 50, LED_PTN_TWIK_MINL, LED_PTN_TWIK_MAXL }
    },
    */
};

byte       patternListOrder[ARRAY_SIZE(patternListItems)];
const byte patternSizeItems { ARRAY_SIZE(patternListItems) };
