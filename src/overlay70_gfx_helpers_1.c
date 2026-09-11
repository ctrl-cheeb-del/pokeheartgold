#include "overlay70_gfx_helpers_private.h"

void ov70_02241234(void *work) {
    s32 i;
    u8 *p = work;
    for (i = 0; i < 7; i++, p += 4) {
        void *sprite = R19_PTR(p, 0xee8);
        if (Sprite_GetDrawFlag(sprite)) {
            u32 current = Sprite_GetAnimationNumber(R19_PTR(p, 0xee8));
            if (current != ov70_0224122C(i) + 1) {
                Sprite_SetAnimCtrlSeq(R19_PTR(p, 0xee8), ov70_0224122C(i) + 1);
            }
        }
    }
}

void ov70_0224127C(void *work) {
    Ov70Gfx19 *typed = work;
    typed->plttAlloc = GfGfxLoader_GetPlttData(0x54, 11, &typed->plttData, 0x3d);
    typed->charAlloc = GfGfxLoader_GetCharData(0x54, 12, TRUE, &typed->charData, 0x3d);
    DC_FlushRange(typed->charData, 0x8000);
}

void ov70_022412C8(void *work, void *palette, u32 index, int trainerClass, int gender) {
    u32 avatar = SpriteToUnionRoomAvatarIdx(gender, trainerClass);
    void *paletteData = R19_PTR(palette, 0xc);
    GXS_LoadOBJ((u8 *)R19_PTR(work, 0x14) + avatar * 0x600, ov70_02245CFC[index], 0x200);
    GXS_LoadOBJPltt((u8 *)paletteData + avatar * 0x20, (index + 2) * 0x20, 0x20);
}

void ov70_02241308(void *work) {
    if (R19_U16(work, 0x11dc) != 0) {
        Heap_Free(R19_PTR(work, 0x11e8));
        Heap_Free(R19_PTR(work, 0x11e0));
    }
}

void ov70_02241330(void *work, u32 index, u32 value) {
    ov70_022410F0(R19_PTR(work, 0xf0c), ov70_02245D0A[index * 2], value + (ov70_02245D0C[index].value + 0x20));
}

void ov70_02241358(void *work) {
    s32 i;
    u8 *p = work;
    for (i = 0; i < 8; i++, p += 4) {
        ov70_02238F9C(R19_PTR(p, 0xee4), R19_S16(p, 0x120c), R19_S16(p, 0x120e));
    }
}

void ov70_02241380(void *work) {
    s32 i;
    u8 *p = work;
    for (i = 0; i < 8; i++, p += 4) {
        ov70_02238F9C(R19_PTR(p, 0xee4), R19_S16(p, 0x120c), R19_S16(p, 0x120e) + 0x20);
    }
}

int ov70_022413AC(void *work) {
    R19_PTR(work, 0xbc) = ov70_0223E49C(R19_PTR(R19_PTR(work, 0), 8), R19_PTR(R19_PTR(work, 0), 0xc), R19_U16(work, 0x120), R19_U16(work, 0x122));
    R19_U8(work, 0xcd) = 2;
    R19_U8(work, 0xcf) = 1;
    R19_U8(work, 0xd0) = 0;
    R19_U8(work, 0xce) = 1;
    R19_U16(work, 0xd4) = 0;
    R19_PTR(work, 0xe8) = sub_02088288(R19_PTR(R19_PTR(work, 0), 0x20));
    R19_PTR(work, 0xd8) = R19_PTR(R19_PTR(work, 0), 0x30);
    R19_PTR(work, 0xc0) = R19_PTR(R19_PTR(work, 0), 0x24);
    R19_PTR(work, 0xdc) = Save_SpecialRibbons_Get(R19_PTR(R19_PTR(work, 0), 0x20));
    R19_PTR(work, 0xf0) = sub_0208828C(R19_PTR(R19_PTR(work, 0), 0x20));
    sub_02089D40((u8 *)work + 0xbc, ov70_02245D48);
    sub_0208AD34((u8 *)work + 0xbc, R19_PTR(R19_PTR(work, 0), 0x1c));
    R19_PTR(work, 0xb8) = OverlayManager_New(gOverlayTemplate_PokemonSummary, (u8 *)work + 0xbc, 0x3d);
    R19_U32(work, 0x114) = 1;
    return 2;
}

int ov70_02241468(void *work) {
    int result = 3;
    if (OverlayManager_Run(R19_PTR(work, 0xb8))) {
        OverlayManager_Delete(R19_PTR(work, 0xb8));
        ov70_02238E50(work, 5, R19_U32(work, 0x24));
        result = 4;
    }
    return result;
}
