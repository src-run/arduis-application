
/*
 * This file is part of the `src-run/arduis-application` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distriBlted with this source code.
 */

#include "Palettes.h"

customPaletteItem ledPaletteList[] = {
    {  1, "BhwS1_Or_Pk_Pu",                                            Palette_BhwS1_Or_Pk_Pu_c,                                            LED_STR_PAL_CYCLE },
    {  2, "BhwS1_Bk_Bl_Gr_Wt",                                         Palette_BhwS1_Bk_Bl_Gr_Wt_c,                                         LED_STR_PAL_CYCLE },
    {  3, "BhwS1_Gr_Bl_Pu",                                            Palette_BhwS1_Gr_Bl_Pu_c,                                            LED_STR_PAL_CYCLE },
    {  4, "BhwS1_Or_Yl",                                               Palette_BhwS1_Or_Yl_c,                                               LED_STR_PAL_CYCLE },
    {  5, "BhwS1_Bk_DkPu_DkBl_DkPu_Bk",                                Palette_BhwS1_Bk_DkPu_DkBl_DkPu_Bk_c,                                LED_STR_PAL_CYCLE },
    {  6, "BhwS1_BlPu_BlGr_Wt_BlGr_BlPu",                              Palette_BhwS1_BlPu_BlGr_Wt_BlGr_BlPu_c,                              LED_STR_PAL_CYCLE },
    {  7, "BhwS1_Rd_DkRd_LtRd_DkRd",                                   Palette_BhwS1_Rd_DkRd_LtRd_DkRd_c,                                   LED_STR_PAL_CYCLE },
    {  8, "BhwS1_Pu_Pi_Pu_Bl_LtBl_Bl_Pu_Pi_Pu_Bl",                     Palette_BhwS1_Pu_Pi_Pu_Bl_LtBl_Bl_Pu_Pi_Pu_Bl_c,                     LED_STR_PAL_CYCLE },
    {  9, "BhwS1_DkGrBl_LtGrBl_DkGrDl",                                Palette_BhwS1_DkGrBl_LtGrBl_DkGrDl_c,                                LED_STR_PAL_CYCLE },
    { 10, "BhwS1_DkGr_Gr_DkGr",                                        Palette_BhwS1_DkGr_Gr_DkGr_c,                                        LED_STR_PAL_CYCLE },
    { 11, "BhwS1_LtGr_LtYl_LtOr_LtRd",                                 Palette_BhwS1_LtGr_LtYl_LtOr_LtRd_c,                                 LED_STR_PAL_CYCLE },
    { 12, "BhwS1_Rd_Pi_Pu",                                            Palette_BhwS1_Rd_Pi_Pu_c,                                            LED_STR_PAL_CYCLE },
    { 13, "BhwS2_DkGr_LtGr_DkGr_YlGr_DkGr",                            Palette_BhwS2_DkGr_LtGr_DkGr_YlGr_DkGr_c,                            LED_STR_PAL_CYCLE },
    { 14, "BhwS2_DkBlGr_BlGr_DkBlGr",                                  Palette_BhwS2_DkBlGr_BlGr_DkBlGr_c,                                  LED_STR_PAL_CYCLE },
    { 15, "BhwS2_LtGr_Gr_DkGr",                                        Palette_BhwS2_LtGr_Gr_DkGr_c,                                        LED_STR_PAL_CYCLE },
    { 16, "BhwS2_DkPuRd_Pu_DkPuRd",                                    Palette_BhwS2_DkPuRd_Pu_DkPuRd_c,                                    LED_STR_PAL_CYCLE },
    { 17, "BhwS2_DkPuBl_LtBl_Pu_LtPu_Pi_RdPu_DkRdPu",                  Palette_BhwS2_DkPuBl_LtBl_Pu_LtPu_Pi_RdPu_DkRdPu_c,                  LED_STR_PAL_CYCLE },
    { 18, "BhwS2_GrGy_GrBl_Gy_LtGy_Gy_Pu_PuGy",                        Palette_BhwS2_GrGy_GrBl_Gy_LtGy_Gy_Pu_PuGy_c,                        LED_STR_PAL_CYCLE },
    { 19, "BhwS2_DkPu_Pu_Bl_BlGr_DkBlGr",                              Palette_BhwS2_DkPu_Pu_Bl_BlGr_DkBlGr_c,                              LED_STR_PAL_CYCLE },
    { 20, "BhwS2_DkGr_Gr_DkGr_DkRd_Rd_DkRd",                           Palette_BhwS2_DkGr_Gr_DkGr_DkRd_Rd_DkRd_c,                           LED_STR_PAL_CYCLE },
    { 21, "BhwS2_DkPu_Pu_Rd_Or_Yl",                                    Palette_BhwS2_DkPu_Pu_Rd_Or_Yl_c,                                    LED_STR_PAL_CYCLE },
    { 22, "BhwS2_GrBl_Gr_LtGr_LtYl_LtGr_Gr_GrBl",                      Palette_BhwS2_GrBl_Gr_LtGr_LtYl_LtGr_Gr_GrBl_c,                      LED_STR_PAL_CYCLE },
    { 23, "BhwS2_DkPu_LtPuRd_DkRd",                                    Palette_BhwS2_DkPu_LtPuRd_DkRd_c,                                    LED_STR_PAL_CYCLE },
    { 24, "BhwS3_Rd_Or_PsOr_Yl_YlOr",                                  Palette_BhwS3_Rd_Or_PsOr_Yl_YlOr_c,                                  LED_STR_PAL_CYCLE },
    { 25, "BhwS3_Yl_Or_Rd_Pi_Pu_LtBl_LtPu_LtBl_Pu_Pi_Or_Pi_Pu_DkPuBl", Palette_BhwS3_Yl_Or_Rd_Pi_Pu_LtBl_LtPu_LtBl_Pu_Pi_Or_Pi_Pu_DkPuBl_c, LED_STR_PAL_CYCLE },
    { 26, "BhwS3_GyRd_LtRdGy_Gy_Rd_LtOr",                              Palette_BhwS3_GyRd_LtRdGy_Gy_Rd_LtOr_c,                              LED_STR_PAL_CYCLE },
    { 27, "BhwS3_Pu_Bl_BlGr_LtGrBl",                                   Palette_BhwS3_Pu_Bl_BlGr_LtGrBl_c,                                   LED_STR_PAL_CYCLE },
    { 28, "BhwS3_LtYl_LtOr_Pi_DkRd_DkPuRd",                            Palette_BhwS3_LtYl_LtOr_Pi_DkRd_DkPuRd_c,                            LED_STR_PAL_CYCLE },
    { 29, "BhwS4_LtBl_DkBl_LtBl_DkBl_LtBl_DkBlGy",                     Palette_BhwS4_LtBl_DkBl_LtBl_DkBl_LtBl_DkBlGy_c,                     LED_STR_PAL_CYCLE },
    { 30, "BhwS4_OrGy_DkGy_OrGy_Yl_Or_OrGy_DkGy_LtOr_LtYl_DkGy",       Palette_BhwS4_OrGy_DkGy_OrGy_Yl_Or_OrGy_DkGy_LtOr_LtYl_DkGy_c,       LED_STR_PAL_CYCLE },
    { 31, "CbSeq_LtBl_DkBl",                                           Palette_CbSeq_LtBl_DkBl_c,                                           LED_STR_PAL_CYCLE },
    { 32, "CbSeq_LtBl_Gr",                                             Palette_CbSeq_LtBl_Gr_c,                                             LED_STR_PAL_CYCLE },
    { 33, "CbSeq_LtBl_Pu",                                             Palette_CbSeq_LtBl_Pu_c,                                             LED_STR_PAL_CYCLE },
    { 34, "CbSeq_LtGr_Bl",                                             Palette_CbSeq_LtGr_Bl_c,                                             LED_STR_PAL_CYCLE },
    { 35, "CbSeq_LtGr_DkGr",                                           Palette_CbSeq_LtGr_DkGr_c,                                           LED_STR_PAL_CYCLE },
    { 36, "CbSeq_Wt_Gy_Bk",                                            Palette_CbSeq_Wt_Gy_Bk_c,                                            LED_STR_PAL_CYCLE },
    { 37, "CbSeq_LtOr_Rd",                                             Palette_CbSeq_LtOr_Rd_c,                                             LED_STR_PAL_CYCLE },
    { 38, "CbSeq_LtOr_DkOr",                                           Palette_CbSeq_LtOr_DkOr_c,                                           LED_STR_PAL_CYCLE },
    { 39, "CbSeq_LtPu_Bl_Gr",                                          Palette_CbSeq_LtPu_Bl_Gr_c,                                          LED_STR_PAL_CYCLE },
    { 40, "CbSeq_LtPu_Bl",                                             Palette_CbSeq_LtPu_Bl_c,                                             LED_STR_PAL_CYCLE },
    { 41, "CbSeq_LtPu_Rd",                                             Palette_CbSeq_LtPu_Rd_c,                                             LED_STR_PAL_CYCLE },
    { 42, "CbSeq_LtPu_DkPu",                                           Palette_CbSeq_LtPu_DkPu_c,                                           LED_STR_PAL_CYCLE },
    { 43, "CbSeq_LtRd_Pu",                                             Palette_CbSeq_LtRd_Pu_c,                                             LED_STR_PAL_CYCLE },
    { 44, "CbSeq_LtRd_DkRd",                                           Palette_CbSeq_LtRd_DkRd_c,                                           LED_STR_PAL_CYCLE },
    { 45, "CbSeq_LtYl_LtGr_Bl",                                        Palette_CbSeq_LtYl_LtGr_Bl_c,                                        LED_STR_PAL_CYCLE },
    { 46, "CbSeq_LtYl_Gr",                                             Palette_CbSeq_LtYl_Gr_c,                                             LED_STR_PAL_CYCLE },
    { 47, "CbSeq_LtYl_Or_Br",                                          Palette_CbSeq_LtYl_Or_Br_c,                                          LED_STR_PAL_CYCLE },
    { 48, "CbSeq_LtYl_Or_Rd",                                          Palette_CbSeq_LtYl_Or_Rd_c,                                          LED_STR_PAL_CYCLE },
    { 49, "CbDiv_Br_Wt_BlGr",                                          Palette_CbDiv_Br_Wt_BlGr_c,                                          LED_STR_PAL_CYCLE },
    { 50, "CbDiv_Pi_YlGr",                                             Palette_CbDiv_Pi_YlGr_c,                                             LED_STR_PAL_CYCLE },
    { 51, "CbDiv_Or_Pu",                                               Palette_CbDiv_Or_Pu_c,                                               LED_STR_PAL_CYCLE },
    { 52, "CbDiv_Rd_Bl",                                               Palette_CbDiv_Rd_Bl_c,                                               LED_STR_PAL_CYCLE },
    { 53, "CbDiv_Rd_Gy",                                               Palette_CbDiv_Rd_Gy_c,                                               LED_STR_PAL_CYCLE },
    { 54, "CbDiv_Rd_Yl_Bl",                                            Palette_CbDiv_Rd_Yl_Bl_c,                                            LED_STR_PAL_CYCLE },
    { 55, "CbDiv_Rd_Yl_Gr",                                            Palette_CbDiv_Rd_Yl_Gr_c,                                            LED_STR_PAL_CYCLE },
    { 56, "CbDiv_Rd_RdOr_Or_OrYl_Yl_YlGr_Gr_GrBl_Bl",                  Palette_CbDiv_Rd_RdOr_Or_OrYl_Yl_YlGr_Gr_GrBl_Bl_c,                  LED_STR_PAL_CYCLE },
    { 57, "CbDiv_PuRd_Wt_Gr",                                          Palette_CbDiv_PuRd_Wt_Gr_c,                                          LED_STR_PAL_CYCLE },
    { 58, "CbQua_LtGr_LtPu_LtOr_LtYl_DkBl_DkPi_DkBr_DkGy",             Palette_CbQua_LtGr_LtPu_LtOr_LtYl_DkBl_DkPi_DkBr_DkGy_c,             LED_STR_PAL_CYCLE },
    { 59, "CbQua_DkGrBl_DkOr_DkPu_DkPi_DkGr_DkYl_DkBr_DkGy",           Palette_CbQua_DkGrBl_DkOr_DkPu_DkPi_DkGr_DkYl_DkBr_DkGy_c,           LED_STR_PAL_CYCLE },
    { 60, "CbQua_LtBl_Bl_LtGr_Gr_LtRd_Rd_LtOr_Or",                     Palette_CbQua_LtBl_Bl_LtGr_Gr_LtRd_Rd_LtOr_Or_c,                     LED_STR_PAL_CYCLE },
    { 61, "CbQua_PsGrBl_PsOr_PsPu_PsPi_PsGr_PsYl_PsBr_PsGy",           Palette_CbQua_PsGrBl_PsOr_PsPu_PsPi_PsGr_PsYl_PsBr_PsGy_c,           LED_STR_PAL_CYCLE },
    { 62, "CbQua_Rd_Bl_Gr_Pu_Or_Yl_Br_Pi",                             Palette_CbQua_Rd_Bl_Gr_Pu_Or_Yl_Br_Pi_c,                             LED_STR_PAL_CYCLE },
    { 63, "CbQua_LtGrBl_LtOr_LtPu_LtPi_LtGr_LtYl_LtBr_LtGy",           Palette_CbQua_LtGrBl_LtOr_LtPu_LtPi_LtGr_LtYl_LtBr_LtGy_c,           LED_STR_PAL_CYCLE },
    { 64, "CbQua_LtGrBl_LtYl_LtPu_LtRd_LtBl_LtOr_LtGr_LtPi",           Palette_CbQua_LtGrBl_LtYl_LtPu_LtRd_LtBl_LtOr_LtGr_LtPi_c,           LED_STR_PAL_CYCLE },
};

unsigned int getLedPaletteListSize(const int adds)
{
    static const unsigned int size = ARRAY_SIZE(ledPaletteList);

    return size + adds;
}

const customPaletteItem* getLedPaletteItem(const unsigned int idx)
{
    static const customPaletteItem def = {
        0,
        "Mysts_Bk_Wi",
        Palette_Mysts_Bk_Wi_c,
        LED_STR_PAL_CYCLE,
    };

    return idx >= getLedPaletteListSize() ? &def : &ledPaletteList[idx];
}

const customPaletteItem* getLedPaletteItem()
{
    return getLedPaletteItem(getLedPaletteListStepIndx().curr);
}

byte getLedPaletteItemPosn(const unsigned int idx)
{
    return getLedPaletteItem(idx)->posn;
}

byte getLedPaletteItemPosn()
{
    return getLedPaletteItem()->posn;
}

String getLedPaletteItemName(const unsigned int idx)
{
    return getLedPaletteItem(idx)->name;
}

String getLedPaletteItemName()
{
    return getLedPaletteItem()->name;
}

CRGBPalette16 getLedPaletteItemComp()
{
    CRGBPalette16 palette = getLedPaletteItem()->comp;

    return palette;
}

unsigned long getLedPaletteItemCallExecMili()
{
    return getLedPaletteItem()->callExecMili;
}

unsigned int getLedPaletteListRandIndx()
{
    return LED_PAL_RAND_SEQL ? getLedPaletteListRandIndxSeql() : getRandomIndx(getLedPaletteListSize());
}

unsigned int getLedPaletteListRandIndxSeql()
{
    static unsigned int pos = 0;

    if (0 == pos) {
        for (byte j = 0; j < randByte(9); j++) {
            for (unsigned int i = 0; i < getLedPaletteListSize(); i++) {
                const unsigned int      n = randUInt(getLedPaletteListSize(-1));
                const customPaletteItem v = ledPaletteList[n];
                ledPaletteList[n] = ledPaletteList[i];
                ledPaletteList[i] = v;
            }
        }

        pos = getLedPaletteListSize();

        Serial.println("####### getLedPaletteListRandIndxSeql #######");
    }

    --pos;

    return max(0, getLedPaletteListSize(-1) - pos);
}

unsigned int getLedPaletteListStepInit()
{
    return LED_PAL_RAND_INIT ? getLedPaletteListRandIndx() : 0;
}

unsigned int getLedPaletteListStepNext(unsigned int idx)
{
    return LED_PAL_RAND_NEXT ? getLedPaletteListRandIndx() : ((idx + 1) % getLedPaletteListSize());
}

ledPaletteIndex getLedPaletteListStepIndx(bool inc)
{
    static unsigned int idxCurr = getLedPaletteListStepInit();
    static unsigned int idxNext = getLedPaletteListStepNext(idxCurr);
    static bool         beg = false;

    if (beg && inc) {
        idxCurr = idxNext;
        idxNext = getLedPaletteListStepNext(idxCurr);
    }

    beg = true;

    return {
        idxCurr,
        idxNext,
    };
}

unsigned int incLedPaletteListStepIndx()
{
    return getLedPaletteListStepIndx(true).curr;
}

unsigned int getLedPaletteListStepNumb()
{
    return getLedPaletteListStepIndx().curr + 1;
}

bool isLedPaletteStepStarted()
{
    return (
        ledPatternStepInit ||
        ledPatternStepRuns
    ) && (
        isMatch(getLedPatternItemNameC(), "palette-circle") ||
        isMatch(getLedPatternItemNameC(), "palette-circle-t")
    );
}

bool isLedPaletteStepRunning()
{
    return isLedPaletteStepStarted() && lt(
        getLedPaletteListStepIndx().curr,
        getLedPaletteListSize()
    );
}

void incPalettesStep()
{
    incLedPaletteListStepIndx();

    if (isLedPaletteStepRunning()) {
        outStepInfo();
    }
}
