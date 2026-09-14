#include "global.h"

#include "to46_overlay18_residual7_private.h"

void ov18_021F11C0(void *p, int idx, int draw) {
    if (draw == 1) {
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), 1);
    } else {
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), 0);
    }
}

ManagedSprite *ov18_021F11EC(void *p, const ManagedSpriteTemplate *template) {
    if (*(const u32 *)((const u8 *)template + 0x10) == 1) {
        return SpriteSystem_NewSprite(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), template);
    }
    return SpriteSystem_NewSpriteWithYOffset(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), template, 2 << 20);
}

void ov18_021F121C(void *p, int idx, int dy, int dx, int subscreen) {
    s16 x;
    s16 y;
    if (subscreen == 0) {
        ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), &x, &y);
        ManagedSprite_SetPositionXY(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x + dy, y + dx);
    } else {
        ManagedSprite_GetPositionXYWithSubscreenOffset(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), &x, &y, 2 << 20);
        ManagedSprite_SetPositionXYWithSubscreenOffset(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x + dy, y + dx, 2 << 20);
    }
}

void ov18_021F1294(void *p, int idx, s16 x, s16 y, int subscreen) {
    if (subscreen == 0) {
        ManagedSprite_SetPositionXY(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x, y);
    } else {
        ManagedSprite_SetPositionXYWithSubscreenOffset(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x, y, 2 << 20);
    }
}

void ov18_021F12C8(void *p, int idx, s16 *x, s16 *y, int subscreen) {
    if (subscreen == 0) {
        ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x, y);
    } else {
        ManagedSprite_GetPositionXYWithSubscreenOffset(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), x, y, 2 << 20);
    }
}
