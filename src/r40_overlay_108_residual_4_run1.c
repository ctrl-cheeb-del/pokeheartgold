#include "r40_overlay_108_residual_4_private.h"

u32 ov108_021E6090(SafariAreaCustomizer4 *work) {
    u32 offset = work->flagB * 6;

    switch (work->unk08) {
    case 0:
        ManagedSprite_SetPriority(work->areaSprites[work->unk184DF + offset], 0);
        ManagedSprite_SetPriority(work->areaSprites[work->unk184E0 + offset], 0);
        GfGfx_EngineBTogglePlanes(0x10, 0);
        work->unk08++;
        break;
    case 1:
        if (ov108_021E82E0(work, 0)) {
            work->unk184E8 = 1;
            SafariZone_SwapAreasInSet(&work->areaData, work->unk184DF, work->unk184E0);
            ov108_021E84F8(work->sub, work->unk184DF + offset, work->areaData[work->unk184DF * 0x7A]);
            ov108_021E7BB4(work, work->unk184DF, work->areaData[work->unk184DF * 0x7A]);
            ov108_021E84F8(work->sub, work->unk184E0 + offset, work->areaData[work->unk184E0 * 0x7A]);
            ov108_021E7BB4(work, work->unk184E0, work->areaData[work->unk184E0 * 0x7A]);
            work->unk08++;
        }
        break;
    case 2:
        if (ov108_021E82E0(work, 1)) {
            ManagedSprite_SetPriority(work->areaSprites[work->unk184DF + offset], 2);
            ManagedSprite_SetPriority(work->areaSprites[work->unk184E0 + offset], 2);
            GfGfx_EngineBTogglePlanes(0x10, 1);
            work->unk08++;
        }
        break;
    default:
        work->unk184DF = work->unk184E0;
        ov108_021E6850(work);
        work->unk08 = 0;
        work->unk0C = 2;
        return 4;
    }
    return 3;
}
