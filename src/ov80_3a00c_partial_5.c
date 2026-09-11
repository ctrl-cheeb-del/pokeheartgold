#include "ov80_3a00c_partial_internal.h"

void ov80_0223AA4C(void *task, void *data) {
    u8 *p = data;
    if (++*(s32 *)(p + 0x38) >= 0) {
        *(s32 *)(p + 0x38) = 0;
        if (++*(s32 *)(p + 0x3C) >= 8) {
            *(s32 *)(p + 0x3C) = 0;
        }
        PaletteData_LoadPalette(*(void **)(p + 0x1C), p + 0x40 + *(s32 *)(p + 0x3C) * 0x20, 0, 0xC0, 0x20);
    }
}

void ov80_0223AA80(void *work, int mode) {
    u8 *p = (u8 *)work + 0x144;
    MI_CpuFill8(p, 0, 0x14);
    if (mode == 0) {
        *(s32 *)p = 0x5000;
        *(s32 *)(p + 4) = 0x5000;
        SysTask_CreateOnMainQueue(ov80_0223AAD0, p, 0x3E8);
    } else {
        *(s32 *)p = 0x2E00;
        *(s32 *)(p + 4) = 0x7200;
        SysTask_CreateOnMainQueue(ov80_0223AB34, p, 0x3E8);
    }
}

void ov80_0223AAD0(void *task, void *data) {
    u8 *p = data;
    if (p[9] == 0) {
        *(s32 *)p -= 0x800;
        *(s32 *)(p + 4) += 0x800;
        if (*(s32 *)p <= 0x2E00) {
            *(s32 *)p = 0x2E00;
            *(s32 *)(p + 4) = 0x7200;
            p[9]++;
        }
        p[0xA] = 0;
        p[0xB] = *(s32 *)p >> 8;
        p[0xC] = 0xFF;
        p[0xD] = *(s32 *)(p + 4) >> 8;
        p[0xE] = 1;
        p[0xF] = *(s32 *)p >> 8;
        p[0x10] = 0;
        p[0x11] = *(s32 *)(p + 4) >> 8;
    } else {
        p[8] = 1;
        SysTask_Destroy(task);
    }
}

void ov80_0223AB34(void *task, void *data) {
    u8 *p = data;
    if (p[9] == 0) {
        *(s32 *)p += 0x800;
        *(s32 *)(p + 4) -= 0x800;
        if (*(s32 *)p >= 0x5000) {
            *(s32 *)p = 0x5000;
            *(s32 *)(p + 4) = 0x5000;
            p[9]++;
        }
        p[0xA] = 0;
        p[0xB] = *(s32 *)p >> 8;
        p[0xC] = 0xFF;
        p[0xD] = *(s32 *)(p + 4) >> 8;
        p[0xE] = 1;
        p[0xF] = *(s32 *)p >> 8;
        p[0x10] = 0;
        p[0x11] = *(s32 *)(p + 4) >> 8;
    } else {
        p[8] = 1;
        SysTask_Destroy(task);
    }
}

int ov80_0223AB94(void *work, void *object, void *state) {
    u8 *w = work;
    u8 *o = object;
    s32 *s = state;
    switch (s[1]) {
    case 0:
        ManagedSprite_SetPositionXYWithSubscreenOffset(*(void **)(o + 0x90), (s16)(*(s16 *)(w + 0x28) + 0x100), (s16)(*(s16 *)(w + 0x2A) + 0x50), 0x200000);
        ManagedSprite_SetDrawFlag(*(void **)(o + 0x90), 1);
        s[0] = 0x10000;
        s[1]++;
        break;
    case 1:
        s[0] -= 0xF00;
        if (s[0] <= 0xD000) {
            s[0] = 0xD000;
            s[1]++;
        }
        ManagedSprite_SetPositionXYWithSubscreenOffset(*(void **)(o + 0x90), (s16)(s[0] >> 8), (s16)(*(s16 *)(w + 0x2A) + 0x50), 0x200000);
        break;
    default:
        return 1;
    }
    return 0;
}
