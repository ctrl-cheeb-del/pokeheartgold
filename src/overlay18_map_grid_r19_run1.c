#include "overlay18_map_grid_r19_internal.h"

void ov18_021F3FDC(void *p) {
    SpriteManager_UnloadCharObjById(PTR_AT(p, 0x66C), 0xC550);
    SpriteManager_UnloadPlttObjById(PTR_AT(p, 0x66C), 0xC551);
    SpriteManager_UnloadCellObjById(PTR_AT(p, 0x66C), 0xC550);
    SpriteManager_UnloadAnimObjById(PTR_AT(p, 0x66C), 0xC550);
    SpriteManager_UnloadCharObjById(PTR_AT(p, 0x66C), 0xC59C);
    SpriteManager_UnloadPlttObjById(PTR_AT(p, 0x66C), 0xC55E);
    SpriteManager_UnloadCellObjById(PTR_AT(p, 0x66C), 0xC55A);
    SpriteManager_UnloadAnimObjById(PTR_AT(p, 0x66C), 0xC55A);
    SpriteManager_UnloadCharObjById(PTR_AT(p, 0x66C), 0xC59A);
    SpriteManager_UnloadPlttObjById(PTR_AT(p, 0x66C), 0xC55C);
    SpriteManager_UnloadCellObjById(PTR_AT(p, 0x66C), 0xC559);
    SpriteManager_UnloadAnimObjById(PTR_AT(p, 0x66C), 0xC559);
}

void ov18_021F4080(void *p) {
    s16 y = S8_AT(p, 0x18C9) * 32 + 76;
    ov18_021F1294(p, 4, 32, y, 1);
}

void ov18_021F40A0(void *p) {
    ov18_021F61DC(p, 5, (s8)U32_AT(p, 0x1900), ov18_021FA35A, 9);
    ov18_021F65EC(p);
    ov18_021F619C(p, S8_AT(p, 0x18CA), (s8)U32_AT(p, 0x1900), 6);
}

void ov18_021F40E4(void *p) {
    u8 *source = PTR_AT(p, 0);
    u16 x = (s32)U32_AT(source, 0x10) / 32;
    u16 y = (s32)U32_AT(source, 0x14) / 32;

    if (x >= 23) {
        x -= 22;
    }
    ov18_021F1294(p, 2, x * 8 + 68, y * 8 + 44, 2);
    ov18_021F4134(p);
}

void ov18_021F4134(void *p) {
    if (S8_AT(p, 0x18C8) == 0) {
        s32 x = (s32)U32_AT(PTR_AT(p, 0), 0x10) / 32;
        if (x >= 23) {
            ov18_021F11C0(p, 2, 0);
        } else {
            ov18_021F11C0(p, 2, 1);
        }
    } else {
        s32 x = (s32)U32_AT(PTR_AT(p, 0), 0x10) / 32;
        if (x >= 23) {
            ov18_021F11C0(p, 2, 1);
        } else {
            ov18_021F11C0(p, 2, 0);
        }
    }
}

void ov18_021F4188(void *p) {
    u32 i;
    u8 *sprites = p;
    u32 offset = 0x67;

    i = 9;
    sprites += 0x24;
    offset <<= 4;
    for (; i < 59; i++, sprites += 4) {
        PTR_AT(sprites, offset) = ov18_021F11EC(p, ov18_021FA4B8);
        ov18_021F1160(p, i, 1);
        ov18_021F11C0(p, i, 0);
    }
}
