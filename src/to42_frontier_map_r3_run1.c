#include "to42_frontier_map_r3_private.h"

void FrontierMap_SetVramBank(void *bgConfig, u32 mode);
void FrontierMap_LoadPaletteData(FrontierMap *m);
void ov80_02238FA0(FrontierMap *m);
void ov80_02239004(FrontierMap *m, u32 mode, void *profile);

void FrontierMap_Update(u32 a0, FrontierMap *m) {
#pragma unused(a0)
    s32 i;
    u32 mask;
    FrontierMapEntry *e = sub_0209686C(m->unk08, 31);

    if (e->unk00 != NULL) {
        ov42_02229358(&m->unk1C, e->unk00);
    }
    FrontierMap_Scroll(m);
    ov42_022290DC(m->unk20);
    mask = m->unk6C;
    for (i = 0; i < 8; i++) {
        if (m->unk3C[i] != NULL && (mask & 1)) {
            ManagedSprite_TickFrame(m->unk3C[i]);
        }
        mask >>= 1;
    }
    SpriteSystem_DrawSprites(m->unk38);
    SpriteSystem_UpdateTransfer();
    ov80_02239A38();
    RequestSwap3DBuffers(1, 0);
}

void FrontierMap_Scroll(FrontierMap *m) {
    void *args = Frontier_GetLaunchArgs(m->unk08);

    switch (ov80_0222ACA0(*(u8 *)((u8 *)args + 0x20), 12)) {
    default:
    case 0:
        if (m->unk24 != NULL) {
            ov42_02229420(m->unk24, &m->unk1C);
        }
        if (m->unk28 != NULL) {
            if (ov80_0222ACA0(*(u8 *)((u8 *)args + 0x20), 13) == 1) {
                ov42_02229420(m->unk28, &m->unk1C);
            }
        }
        break;
    case 1:
        ov80_02238B7C(m);
        break;
    }
}

void ov80_02238B7C(FrontierMap *m) {
    void *args = Frontier_GetLaunchArgs(m->unk08);
    s16 x = m->unkAA + ov42_022293A8(&m->unk1C);
    s16 y = m->unkA8 + ov42_022293B0(&m->unk1C);
    f32 fx;
    f32 fy;

    if (x > 0) {
        fx = 0.5f + (f32)(x << 12);
    } else {
        fx = (f32)(x << 12) - 0.5f;
    }
    if (y > 0) {
        fy = 0.5f + (f32)(y << 12);
    } else {
        fy = (f32)(y << 12) - 0.5f;
    }
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(m->unk34), (s32)fy, (s32)fx);
    ScheduleSetBgPosText(m->bgConfig, 3, 0, y);
    ScheduleSetBgPosText(m->bgConfig, 3, 3, x);
    if (ov80_0222ACA0(*(u8 *)((u8 *)args + 0x20), 9) != 0xFFFF) {
        if (ov80_0222ACA0(*(u8 *)((u8 *)args + 0x20), 13) == 1) {
            ScheduleSetBgPosText(m->bgConfig, 2, 0, y);
            ScheduleSetBgPosText(m->bgConfig, 2, 3, x);
        }
    }
}

void ov80_02238C78(FrontierMap *m) {
    FrontierMapEvtB b;
    FrontierMapEvtA a;

    while (ov42_02229A08(m->unk30, &a) == 1) {
        ov42_02228068(m->unk14, &a);
    }
    while (ov42_02229AC8(m->unk2C, &b) == 1) {
        if (ov42_02228C80(m->unk18, m->unk14, &b, &a) == 1) {
            ov42_02228068(m->unk14, &a);
        }
    }
}
