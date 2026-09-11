#include "ov57_wave42_private.h"

BOOL ov57_022382F8(Ov57Work *work, u32 state, s32 i) {
    u32 offset = i << 4;
    BOOL done;
    if (work->slots[i].active == 0) {
        return TRUE;
    }
    switch (state) {
    case 0:
        if (work->selected == 0xFF) {
            work->selected = i;
            ov57_02238044((u8 *)work, i);
        }
        break;
    case 2:
        if (work->selected == (u32)i) {
            ov57_02237EB8(work->slots[i].effect, work->slots[i].sprite, TRUE);
            ov57_0223848C((u8 *)work, i);
            ov57_02238508((u8 *)work, i);
        }
        break;
    case 1:
    case 3:
        if (work->selected == 0xFF) {
            done = ov57_022383F8((u8 *)work, i);
            ov57_02237EB8(work->slots[i].effect, work->slots[i].sprite, FALSE);
            if (!done) {
                ov57_02238438((u8 *)work, i);
            }
            work->selected = 0xFF;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return TRUE;
}

void ov57_022383AC(u8 *w) {
    s32 i = 0;
    u8 *p = w;
    for (; i < 8; i++, p += 0x10) {
        if (*(u32 *)(p + 0x34C) == 1) {
            ov57_02238438(w, i);
        }
    }
}

void ov57_022383D0(u8 *w, BOOL draw) {
    s32 i;
    u8 *p = w;
    for (i = 0; i < 8; i++, p += 0x10) {
        if (*(u32 *)(p + 0x34C) == 1) {
            ManagedSprite_SetDrawFlag(*(ManagedSprite **)(p + 0x354), draw);
        }
    }
}

BOOL ov57_022383F8(u8 *w, s32 i) {
    s16 x, y;
    u8 *p = w + i * 0x10;
    if (*(u32 *)(p + 0x34C) == 0) {
        return TRUE;
    }
    ManagedSprite_GetPositionXY(*(ManagedSprite **)(p + 0x354), &x, &y);
    if (ov07_022344E4(x, y, 0xBE, 0x46) <= 0x3C) {
        return TRUE;
    }
    return FALSE;
}

void ov57_02238438(u8 *w, s32 i) {
    Ov57Work *work = (Ov57Work *)w;
    sub_02091054(work->slots[i].x);
    SpriteManager_UnloadCharObjById(work->spriteManager, i + 0x4E20);
    Sprite_DeleteAndFreeResources(work->slots[i].sprite);
    work->slots[i].sprite = NULL;
    work->slots[i].active = 0;
    work->slots[i].x = 0;
    work->slots[i].y = 0;
    work->slots[i].z = 0;
    ov57_02237E90(work->slots[i].effect, 0, 0);
}

void ov57_0223848C(u8 *w, s32 i) {
    if (!ov57_022383F8(w, i)) {
        ManagedSprite_SetOamMode(*(ManagedSprite **)(w + i * 0x10 + 0x354), (GXOamMode)1);
    } else {
        ManagedSprite_SetOamMode(*(ManagedSprite **)(w + i * 0x10 + 0x354), (GXOamMode)0);
    }
}

BOOL ov57_022384C0(u8 *w) {
    s32 i = 0;
    u8 *other = *(u8 **)(w + (*(u32 *)(w + 0x3EC) * 8) + 8);
    for (; i < 8; i++, other += 3, w += 0x10) {
        if (w[0x350] != other[0] || w[0x351] != other[1] || w[0x352] != other[2]) {
            return TRUE;
        }
    }
    return FALSE;
}

void ov57_02238508(u8 *w, s32 i) {
    s16 x, y;
    u32 offset = i << 4;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)(w + offset + 0x354), &x, &y);
    w[offset + 0x351] = (u8)x;
    w[offset + 0x352] = (u8)y;
}

void ov57_0223853C(u8 *w) {
    u8 copy[24];
    s32 i = 0;
    u8 *src = w;
    for (; i < 8; i++, src += 0x10) {
        copy[i * 3] = src[0x350];
        copy[i * 3 + 1] = src[0x351];
        copy[i * 3 + 2] = src[0x352];
    }
    SealCase_SetCapsuleI(*(void **)(*(u8 **)w + 0x20), copy, *(u32 *)(w + 0x3EC));
}

void ov57_0223857C(u8 *out, u8 *w) {
    s32 i;
    for (i = 0; i < 8; i++, w += 0x10, out += 3) {
        out[0] = w[0x350];
        out[1] = w[0x351];
        out[2] = w[0x352];
    }
}

void ov57_022385A4(u8 *out, ManagedSprite *s, s32 yRadius, s32 xRadius) {
    s16 x, y;
    ManagedSprite_GetPositionXY(s, &x, &y);
    out[0] = (u8)(y - xRadius);
    out[1] = (u8)(y + xRadius);
    out[2] = (u8)(x - yRadius);
    out[3] = (u8)(x + yRadius);
}

void ov57_022385DC(u8 *w) {
    ov57_02239814(*(void **)(w + 0xE4), w + 0xEC, 1, 1, 0x15, 0x1E, 2, 0x3A);
    ov57_02239814(*(void **)(w + 0xE4), w + 0x11C, 1, 1, 0x15, 0x14, 2, 0x3A);
    ov57_02239814(*(void **)(w + 0xE4), w + 0x10C, 1, 0x17, 0x15, 8, 2, 0x76);
}
