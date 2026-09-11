#include "overlay14_box_sprite_controls_private.h"

void ov14_021F40E8(void *p, u32 a1) {
    u32 i;
    if (a1 == 1) {
        a1 = 1;
    } else {
        a1 = 0;
    }
    for (i = 0; i < 8; i++) {
        void *sprite = PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x3f0);
        if (sprite != NULL) {
            ManagedSprite_SetDrawFlag(sprite, a1);
            if (a1 == 1) {
                u32 box = U8_AT(p, 0x21);
                if (box != 0xff) {
                    u32 idx = U8_AT((u8 *)PTR_AT(p, 0x34) + box, 0x4094) * 4;
                    u32 prio = ManagedSprite_GetDrawPriority(PTR_AT((u8 *)PTR_AT(p, 0x34) + idx, 0x2fc));
                    ov14_021F2A74(PTR_AT(p, 0x34), i + 0x3d, prio + 1);
                    ManagedSprite_SetPriority(PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x3f0),
                        ManagedSprite_GetPriority(PTR_AT((u8 *)PTR_AT(p, 0x34) + idx, 0x2fc)));
                }
            }
        }
    }
}

void ov14_021F4174(void *p) {
    void *q;
    u16 i;
    s16 x;
    s16 y;
    u32 box = U8_AT(p, 0x21);
    if (box == 0xff) {
        return;
    }
    q = PTR_AT(p, 0x34);
    ManagedSprite_GetPositionXY(PTR_AT((u8 *)q + U8_AT((u8 *)q + box, 0x4094) * 4, 0x2fc), &x, &y);
    for (i = 0; i < 8; i++) {
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)q + i * 4, 0x3f0), x + ov14_021F8070[i], y + ov14_021F8078[i]);
    }
}

void ov14_021F41E4(void *p) {
    u32 i;
    for (i = 0; i < 6; i++) {
        SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x46, FALSE, 1, 0xc123 + i);
    }
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x47, FALSE, 1, 1, 0xc0ff);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x48, TRUE, 0xc0fd);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x49, TRUE, 0xc0fd);
}

void ov14_021F4278(void *p) {
    SpriteTemplate tmpl[2];
    u32 i = 0;
    s32 dx = 0;
    u8 *dst = p;
    tmpl[0] = ov14_021F8140;
    for (; i < 6; dx += 0x22, dst += 4, i++) {
        tmpl[1] = tmpl[0];
        tmpl[1].x += dx;
        tmpl[1].resIdList[0] = 0xc123 + i;
        PTR_AT(dst, 0x338) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), &tmpl[1]);
    }
}

void ov14_021F42EC(void *p) {
    u32 i;
    for (i = 0; i < 4; i++) {
        SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4a, FALSE, 1, 0xc129 + i);
    }
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4b, FALSE, 2, 1, 0xc100);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4c, TRUE, 0xc0fe);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4d, TRUE, 0xc0fe);
}

void ov14_021F4380(void *p) {
    SpriteTemplate tmpl[2];
    u32 i = 0;
    s32 dx = 0;
    u8 *dst = p;
    tmpl[0] = ov14_021F8174;
    for (; i < 4; dx += 0x2e, dst += 4, i++) {
        tmpl[1] = tmpl[0];
        tmpl[1].x += dx;
        tmpl[1].resIdList[0] = 0xc129 + i;
        PTR_AT(dst, 0x350) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), &tmpl[1]);
    }
}

void ov14_021F43F4(void *p, u32 a1) {
    ov14_021F2A18(p, 0, a1);
    ov14_021F2A18(p, 1, a1);
}

void ov14_021F4410(void *q) {
    sub_020136B4(PTR_AT(q, 0x414), -0x30, -8);
}

void ov14_021F4428(void *p) {
    void *q = PTR_AT(p, 0x34);
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x30c), 0xc, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x310), 0xf4, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x314), 0x2b, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x318), 0x80, -0x28);
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x31c), 0x80, -0x1c);
    ov14_021F462C(p);
    ov14_021F29E4(q, 7, 7);
    ov14_021F4410(q);
    TextOBJ_SetSpritesDrawFlag(PTR_AT(q, 0x414), 1);
    TextOBJ_SetSpritesDrawFlag(PTR_AT(q, 0x424), 0);
}

void ov14_021F44B4(void *q, s32 dy) {
    s16 x;
    s16 y;
    u32 i;
    for (i = 4; i <= 8; i++) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)q + i * 4, 0x2fc), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)q + i * 4, 0x2fc), x, y + dy);
    }
    ov14_021F4410(q);
    for (i = 0; i < 4; i++) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)q + i * 4, 0x350), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)q + i * 4, 0x350), x, y + dy);
    }
}

void ov14_021F4530(void *p) {
    s16 x;
    s16 y;
    u32 v = ov14_021E7930(p, U8_AT(p, 0x25));
    if ((u32)U8_AT(PTR_AT(p, 0x34), 0x44d) >> 2 == v >> 2) {
        ov14_021F2A18(PTR_AT(p, 0x34), 6, 1);
    } else {
        ov14_021F2A18(PTR_AT(p, 0x34), 6, 0);
    }
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x314), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x314), 0x2e * (v & 3) + 0x3b, y);
}

void ov14_021F459C(void *p) {
    s16 x2;
    s16 y;
    s16 x1;
    u16 v = U8_AT(PTR_AT(p, 0x34), 0x44d) % 4;
    ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + (v + 0x15) * 4, 0x2fc), &x1, &y);
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x318), &x2, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x318), x1, y);
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x31c), &x2, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x31c), x1, y);
    ov14_021F4410(PTR_AT(p, 0x34));
}

void ov14_021F462C(void *p) {
    NNSG2dCharacterData *charData;
    void *narcBuf;
    u32 i;
    void *buf;
    u32 res = 0x15;
    u32 wp = (u32)U8_AT(PTR_AT(p, 0x34), 0x44d) >> 2;
    wp = wp * 4;
    buf = Heap_AllocAtEnd(0xa, 0x240);
    narcBuf = AllocAtEndAndReadWholeNarcMemberByIdPair(0x13, 0x4a, 0xa);
    NNS_G2dGetUnpackedCharacterData(narcBuf, &charData);
    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(charData->pRawData, buf, 0x240);
        ov14_021F46B0(p, buf, wp, 0x1e, 0x240);
        ov14_021F2C1C(PTR_AT(p, 0x34), res, buf, 0x240);
        res++;
        wp++;
    }
    Heap_Free(narcBuf);
    Heap_Free(buf);
}

void ov14_021F46B0(void *p, u8 *buf, u32 wallpaper, u32 match, u32 size) {
    u32 i;
    u8 v;
    if (wallpaper >= 0x10) {
        if (!PCStorage_IsBonusWallpaperUnlocked(PTR_AT(p, 4), wallpaper - 0x10)) {
            v = 0x28;
        } else {
            v = (u8)(wallpaper + 0x10);
        }
    } else {
        v = (u8)(wallpaper + 0x10);
    }
    for (i = 0; i < size; i++) {
        if (match == buf[i]) {
            buf[i] = v;
        }
    }
}

void ov14_021F46F4(void *q) {
    sub_020136B4(PTR_AT(q, 0x414), -0x48, -8);
    sub_020136B4(PTR_AT(q, 0x424), 0x20, -8);
}

void ov14_021F4720(void *p) {
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x30c), 0xc, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x310), 0xf4, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x314), 0x2b, -0x15);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x318), 0x80, -0x28);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x31c), 0x80, -0x1c);
    ov14_021F49E0(p);
    ov14_021F29E4(PTR_AT(p, 0x34), 7, 5);
    ov14_021F46F4(PTR_AT(p, 0x34));
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x414), 1);
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x424), 1);
}

void ov14_021F47B8(void *p, s32 dy) {
    s16 x;
    s16 y;
    u32 i;
    for (i = 4; i <= 8; i++) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x2fc), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x2fc), x, y + dy);
    }
    ov14_021F46F4(PTR_AT(p, 0x34));
    for (i = 0; i < 6; i++) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x338), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + i * 4, 0x338), x, y + dy);
    }
}

void ov14_021F4848(void *p) {
    s16 x;
    s16 y;
    s32 a = U8_AT(p, 0x25) / 6;
    s32 r;
    if (a == U8_AT(p, 0x1f) / 6) {
        ov14_021F2A18(PTR_AT(p, 0x34), 6, 1);
    } else {
        ov14_021F2A18(PTR_AT(p, 0x34), 6, 0);
    }
    r = U8_AT(p, 0x1f) % 6;
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x314), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x314), 0x22 * r + 0x2b, y);
}

void ov14_021F48B4(void *p) {
    s16 x2;
    s16 y;
    s16 x1;
    u16 r = U8_AT(p, 0x25) % 6;
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x318), &x2, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x318), ov14_021F8068[r], y);
    ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + (r + 0xf) * 4, 0x2fc), &x1, &y);
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x31c), &x2, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x31c), x1, y);
    ov14_021F46F4(PTR_AT(p, 0x34));
}
