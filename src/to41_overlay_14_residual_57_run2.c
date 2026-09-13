#include "to41_overlay_14_residual_57_private.h"

void ov14_021F49E0(void *p);
void ov14_021F4A20(void *p, u32 slot);
void ov14_021F4A64(void *p, u32 box, void *dst);
void ov14_021F4B90(void *q, u32 i, s32 x, s32 y, u32 v);
void ov14_021F4BC0(void *p);
void ov14_021F4CA0(void *p);
void ov14_021F4D10(void *q);
void ov14_021F4E68(void *q);
void ov14_021F4EA0(void *q, void *window, u32 i);
void ov14_021F4ED0(void *p);
void ov14_021F4F00(void *p);
void ov14_021F4F24(void *window, void *str, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F4F84(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F4FBC(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F5000(void *q, BoxMonView *mon, u32 win);
void ov14_021F5054(void *q, BoxMonView *mon, u32 win);
void ov14_021F50A0(void *q, BoxMonView *mon, u32 win);
void ov14_021F5114(void *q, BoxMonView *mon, u32 win);
void ov14_021F5190(void *p, BoxMonView *mon, u32 win);
void ov14_021F521C(void *q, BoxMonView *mon, u32 win);
void ov14_021F528C(void *q, BoxMonView *mon, u32 win);
void ov14_021F52FC(void *q, BoxMonView *mon, u32 win);
void ov14_021F5368(void *p, BoxMonView *mon);
void ov14_021F53C0(void *q);
u32 ov14_021F5404(void *p, BoxMonView *mon);
u32 ov14_021F5564(void *p, u32 itemId);
void ov14_021F5620(void *p);
void ov14_021F566C(void *p);
void ov14_021F5718(void *p, void *src, u32 a2, u32 a3, u32 a5);
void ov14_021F57B8(void *p);
void ov14_021F58B8(void *p);
void ov14_021F5950(void *p, u32 win, u32 msgId, u32 style);
void ov14_021F5BD8(void *p, u32 win, u32 msgId, u32 style, u8 align);
void ov14_021F5C84(void *p, u32 style);
void ov14_021F5C94(void *p, u32 win, u32 msgId);
void ov14_021F5E94(void *p);
void ov14_021F5EB4(void *p, u32 style);
void ov14_021F5EC4(void *p, u32 style);
void ov14_021F5ED4(void *p, u32 style);
void ov14_021F5EE4(void *p, BoxMenuEntry *list, u32 count);
void ov14_021F5FBC(void *p, u32 which);

#if 0

#endif

typedef struct {
    void *font;
    void *window;
    void *spriteList;
    void *plttProxy;
    u32 unk10;
    u32 unk14;
    s32 x;
    s32 y;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2c;
} FontOamParam;

#if 0





typedef struct {
    void *font;
    void *window;
    void *spriteList;
    void *plttProxy;
    u32 unk10;
    u32 unk14;
    s32 x;
    s32 y;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2c;
} FontOamParam;

#endif

#if 0

#endif

#if 0

#endif

void ov14_021F4B90(void *q, u32 i, s32 x, s32 y, u32 v) {
    ManagedSprite_SetPositionXY(PTR_AT(q, 0x2fc + i * 4), x, y);
    ov14_021F2A18(q, i, v);
    ov14_021F2A60(q, i, 0);
}

void ov14_021F4BC0(void *p) {
    u32 i;
    u32 off;
    s16 x;
    s16 y;

    ov14_021F4B90(PTR_AT(p, 0x34), 4, 0xc, 0x54, 1);
    ov14_021F4B90(PTR_AT(p, 0x34), 5, 0xf4, 0x54, 1);
    ov14_021F4B90(PTR_AT(p, 0x34), 6, 0x2b, 0x54, 1);
    ov14_021F4B90(PTR_AT(p, 0x34), 7, 0x80, 0x41, 1);
    ov14_021F4B90(PTR_AT(p, 0x34), 8, 0x80, 0x4d, 1);
    for (i = 0, off = 0; i < 6; off += 4, i++) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + off, 0x338), &x, &y);
        ov14_021F4B90(PTR_AT(p, 0x34), i + 0xf, x, 0x54, 1);
    }
    ov14_021F49E0(p);
    ov14_021F29E4(PTR_AT(p, 0x34), 7, 5);
    ov14_021F46F4(PTR_AT(p, 0x34));
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x414), 1);
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x424), 1);
    sub_020137F0(PTR_AT(PTR_AT(p, 0x34), 0x414), 0);
    sub_020137F0(PTR_AT(PTR_AT(p, 0x34), 0x424), 0);
}

void ov14_021F4CA0(void *p) {
    u32 i;

    ov14_021F2A18(PTR_AT(p, 0x34), 4, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 5, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 6, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 7, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 8, 0);
    for (i = 0; i < 6; i++) {
        ov14_021F2A18(PTR_AT(p, 0x34), i + 0xf, 0);
    }
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x414), 0);
    TextOBJ_SetSpritesDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x424), 0);
}

void ov14_021F4D10(void *q) {
    u8 window[0x10];
    FontOamParam param;
    u8 *slot;

    U32_AT(q, 0x410) = (u32)FontSystem_NewInit(2, 0xa);
    slot = (u8 *)q + 0x414;
    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR_AT(q, 0x14), window, 0xc, 2, 0, 2);
    sub_02021AC8(sub_02013688(window, 1, 0xa), 1, 1, slot + 4);
    param.font = PTR_AT(q, 0x410);
    param.window = window;
    param.spriteList = SpriteManager_GetSpriteList(PTR_AT(q, 0x2f8));
    param.plttProxy = SpriteManager_FindPlttResourceProxy(PTR_AT(q, 0x2f8), 0xc101);
    param.unk10 = U32_AT(PTR_AT(q, 0x318), 0);
    param.unk14 = U32_AT(slot, 8);
    param.x = 0x80;
    param.y = -0x1c;
    param.unk20 = 1;
    param.unk24 = 4;
    param.unk28 = 1;
    param.unk2c = 0xa;
    U32_AT(q, 0x414) = (u32)sub_020135D8(&param);
    sub_020138B0(PTR_AT(q, 0x414), 1);
    sub_020138E0(PTR_AT(q, 0x414), 1);
    RemoveWindow(window);

    slot = (u8 *)q + 0x424;
    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR_AT(q, 0x14), window, 5, 2, 0, 2);
    sub_02021AC8(sub_02013688(window, 1, 0xa), 1, 1, slot + 4);
    param.font = PTR_AT(q, 0x410);
    param.window = window;
    param.spriteList = SpriteManager_GetSpriteList(PTR_AT(q, 0x2f8));
    param.plttProxy = SpriteManager_FindPlttResourceProxy(PTR_AT(q, 0x2f8), 0xc101);
    param.unk10 = U32_AT(PTR_AT(q, 0x318), 0);
    param.unk14 = U32_AT(slot, 8);
    param.x = 0x80;
    param.y = -0x1c;
    param.unk20 = 1;
    param.unk24 = 4;
    param.unk28 = 1;
    param.unk2c = 0xa;
    PTR_AT(slot, 0) = sub_020135D8(&param);
    sub_020138B0(PTR_AT(slot, 0), 1);
    sub_020138E0(PTR_AT(slot, 0), 1);
    RemoveWindow(window);
}

void ov14_021F4E68(void *q) {
    u32 i;
    u8 *a;
    u8 *b;

    i = 0;
    a = (u8 *)q + 0x418;
    b = (u8 *)q;
    for (; i < 2; i++) {
        sub_02021B5C(a);
        FontOAM_Delete(PTR_AT(b, 0x414));
        a += 0x10;
        b += 0x10;
    }
    sub_020135AC(PTR_AT(q, 0x410));
}

void ov14_021F4EA0(void *q, void *window, u32 i) {
    void *tmp;

    tmp = sub_02013910(window, 0xa);
    TextOBJ_CopyFromBGWindow(PTR_AT(q, 0x414 + i * 0x10), tmp, window, 0xa);
    sub_02013938(tmp);
}

void ov14_021F4ED0(void *p) {
    const u8 *tmpl;
    u32 off;
    u32 i;

    FontID_Alloc(4, 0xa);
    i = 0;
    tmpl = ov14_021F84B4;
    off = 0;
    for (; i < 0x2c; i++) {
        AddWindow(PTR_AT(PTR_AT(p, 0x34), 0x14), (u8 *)PTR_AT(p, 0x34) + 0x30 + off, tmpl);
        tmpl += 8;
        off += 0x10;
    }
}

void ov14_021F4F00(void *p) {
    u16 i;

    for (i = 0; i < 0x2c; i++) {
        RemoveWindow((u8 *)PTR_AT(p, 0x34) + 0x30 + i * 0x10);
    }
    FontID_Release(4);
}

void ov14_021F4F24(void *window, void *str, s32 x, s32 y, u32 font, u32 color, u32 align) {
    if (align == 1) {
        x -= FontID_String_GetWidth(font, str, 0);
    } else if (align == 2) {
        x -= FontID_String_GetWidth(font, str, 0) / 2;
    } else if (align == 3) {
        x -= FontID_String_GetWidthMultiline(font, str, 0) / 2;
    }
    AddTextPrinterParameterizedWithColor(window, font, str, x, y, 0xff, color, NULL);
}

void ov14_021F4F84(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align) {
    void *str;

    str = NewString_ReadMsgData(msgData, msgId);
    ov14_021F4F24((u8 *)q + 0x30 + win * 0x10, str, x, y, font, color, align);
    String_Delete(str);
}

void ov14_021F4FBC(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align) {
    void *str;

    str = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(PTR_AT(q, 0x24), PTR_AT(q, 0x28), str);
    ov14_021F4F24((u8 *)q + 0x30 + win * 0x10, PTR_AT(q, 0x28), x, y, font, color, align);
    String_Delete(str);
}

void ov14_021F5000(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        BufferBoxMonSpeciesName(PTR_AT(q, 0x24), 0, mon->pid);
        ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 0, 0, 0, 0, 0x10200, 0);
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F5054(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    BufferBoxMonNickname(PTR_AT(q, 0x24), 0, mon->pid);
    ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 1, 0, 0, 0, 0x10200, 0);
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F50A0(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        sub_0200CDAC(PTR_AT(q, 0x1c), 1, (u8 *)q + 0x30 + win * 0x10, 0, 5);
        BufferIntegerAsString(PTR_AT(q, 0x24), 0, mon->level, 3, 0, 1);
        ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 0x5a, 0x10, 0, 0, 0x10200, 0);
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F5114(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        if (mon->marked == 1) {
            if (mon->markKind == 0) {
                ov14_021F4F84(q, PTR_AT(q, 0x20), win, 0x52, 0, 0, 0, 0x70800, 0);
            } else if (mon->markKind == 1) {
                ov14_021F4F84(q, PTR_AT(q, 0x20), win, 0x53, 0, 0, 0, 0x30400, 0);
            }
        }
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F5190(void *p, BoxMonView *mon, u32 win) {
    u32 dexno;

    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        dexno = Pokedex_ConvertToCurrentDexNo(SaveArray_IsNatDexEnabled(PTR_AT(PTR_AT(p, 0), 0)), mon->species);
        if (dexno) {
            sub_0200CDAC(PTR_AT(PTR_AT(p, 0x34), 0x1c), 2, (u8 *)PTR_AT(p, 0x34) + 0x30 + win * 0x10, 0, 5);
            BufferIntegerAsString(PTR_AT(PTR_AT(p, 0x34), 0x24), 0, dexno, 3, 2, 1);
            ov14_021F4FBC(PTR_AT(p, 0x34), PTR_AT(PTR_AT(p, 0x34), 0x20), win, 0x5b, 0x10, 0, 0, 0x10200, 0);
        }
    }
    ScheduleWindowCopyToVram((u8 *)PTR_AT(p, 0x34) + 0x30 + win * 0x10);
}

void ov14_021F521C(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        BufferNatureName(PTR_AT(q, 0x24), 0, mon->nature);
        ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 0x55, 0, 0, 0, 0x10200, 0);
    } else {
        ov14_021F4F84(q, PTR_AT(q, 0x20), win, 0x5d, 0, 0, 0, 0x10200, 0);
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F528C(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (!mon->empty) {
        BufferAbilityName(PTR_AT(q, 0x24), 0, mon->ability);
        ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 0x54, 0, 0, 0, 0x10200, 0);
    } else {
        ov14_021F4F84(q, PTR_AT(q, 0x20), win, 0x5d, 0, 0, 0, 0x10200, 0);
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F52FC(void *q, BoxMonView *mon, u32 win) {
    FillWindowPixelBuffer((u8 *)q + 0x30 + win * 0x10, 0);
    if (mon->item) {
        BufferItemName(PTR_AT(q, 0x24), 0, mon->item);
        ov14_021F4FBC(q, PTR_AT(q, 0x20), win, 0x56, 0, 0, 0, 0x10200, 0);
    } else {
        ov14_021F4F84(q, PTR_AT(q, 0x20), win, 0x5c, 0, 0, 0, 0x10200, 0);
    }
    ScheduleWindowCopyToVram((u8 *)q + 0x30 + win * 0x10);
}

void ov14_021F5368(void *p, BoxMonView *mon) {
    ov14_021F5000(PTR_AT(p, 0x34), mon, 0);
    ov14_021F5054(PTR_AT(p, 0x34), mon, 1);
    ov14_021F50A0(PTR_AT(p, 0x34), mon, 2);
    ov14_021F5114(PTR_AT(p, 0x34), mon, 4);
    ov14_021F5190(p, mon, 5);
    ov14_021F521C(PTR_AT(p, 0x34), mon, 6);
    ov14_021F528C(PTR_AT(p, 0x34), mon, 7);
    ov14_021F52FC(PTR_AT(p, 0x34), mon, 8);
}

void ov14_021F53C0(void *q) {
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x30);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x40);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x50);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x70);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x80);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0x90);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0xa0);
    ClearWindowTilemapAndScheduleTransfer((u8 *)q + 0xb0);
}
