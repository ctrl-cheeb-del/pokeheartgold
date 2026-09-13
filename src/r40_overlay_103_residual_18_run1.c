#include "global.h"

#include "r40_overlay_103_residual_18_private.h"

void ov103_021EE160(R40Ov103Work18 *work) {
    u32 resId;
    for (resId = 0x37F0; resId <= 0x37F2; resId++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, work->narc, GetMonIconNaixEx(0, 0, 0), 0, 2, resId);
    }
    SpriteSystem_LoadPlttResObjFromOpenNarc(work->spriteSystem, work->spriteManager, work->narc, sub_02074490(), 0, 3, 2, 0x37F0);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, work->narc, sub_02074494(), 0, 0x37F0);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, work->narc, sub_02074498(), 0, 0x37F0);
}

void ov103_021EE210(R40Ov103Work18 *work) {
    typedef union {
        u16 raw;
        struct {
            u16 species : 12;
            u16 palette : 4;
        };
    } LocalValue;
    u32 i;
    u32 offset;
    register Mail *mail = *(Mail **)(work->ctx + work->mailIndex * 4 + 0x27C);
    NNSG2dCharacterData *data;
    LocalValue value;
    void *raw;
    u32 loc;
    u32 species;
    for (i = 0, offset = 0; i < 3; i++, offset += 4) {
        value.raw = sub_0202B404(mail, (u8)i, 2, sub_0202B4E4(mail));
        if (value.raw == 0xFFFF || (species = value.species) == 7) {
            ov103_021EE0CC(work->ctx, i + 4, 0);
        } else {
            loc = NNS_G2dGetImageLocation(Sprite_GetImageProxy(*(Sprite **)(*(u8 **)(work->ctx + 0x268 + offset))), (NNS_G2D_VRAM_TYPE)2);
            raw = GfGfxLoader_GetCharDataFromOpenNarc(*(NARC **)(work->ctx + 0x274), species, 0, &data, (enum HeapID)0x9D);
            DC_FlushRange(data->pRawData, 0x200);
            GXS_LoadOBJ(data->pRawData, loc, 0x200);
            Heap_Free(raw);
            ManagedSprite_SetPaletteOverride(*(ManagedSprite **)(work->ctx + 0x268 + offset), value.palette);
            ov103_021EE0CC(work->ctx, i + 4, 1);
        }
    }
}

void ov103_021EE2E0(R40Ov103Work18 *work) {
    NARC *narc = NARC_New((NarcId)0xFC, (enum HeapID)0x9D);
    SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 7, 1, 1, 0x37F3);
    SpriteSystem_LoadPlttResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 10, 0, 2, 1, 0x37F1);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 8, 1, 0x37F1);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 9, 1, 0x37F1);
    NARC_Delete(narc);
}
