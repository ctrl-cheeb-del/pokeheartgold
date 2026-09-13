#include "overlay89_r8_private.h"

void ov89_0225A760(Ov89Work *work, int mode) {
    int i;
    NNSG3dResTex **slot = work->textures;

    for (i = 0; i < 32; i++, slot++) {
        if (*slot != NULL) {
            DC_FlushRange(*slot, (*slot)->header.size);
            NNS_G3dTexLoad(*slot, TRUE);
            NNS_G3dPlttLoad(*slot, TRUE);
            *slot = NULL;
        }
    }
    if (work->brightnessActive != 0 && mode != 3) {
        SetMasterBrightness(PM_LCD_TOP, work->brightness);
        work->brightnessActive = 0;
    }
}
