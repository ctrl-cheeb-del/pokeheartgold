#include "overlay40_pc_box_theme_private.h"

void ov40_02238EBC(void *p, u32 *a);
void ov40_02238F00(void *p);
int ov40_0223A034(void *p);
int ov40_0223A080(void *p);
int ov40_0223A158(void *p);

void ov40_02239340(void *p) {
    void *win;
    const Ov40WinTemplate *t = ov40_022453B8;
    int baseTile = 1;
    int i;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x84; i < 2; i++) {
        void *str;
        AddWindowParameterized(PTR(p, 0x24), win, 6, t->x, t->y, t->width, t->height, 0xE, baseTile);
        baseTile += t->width * t->height;
        FillWindowPixelBuffer(win, 0);
        str = NewString_ReadMsgData(PTR(p, 0x48), i + 0x50);
        AddTextPrinterParameterizedWithColor(win, 0, str, ov40_022306C0(win, str), 0, 0xFF, 0xF0D00, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
        win = (u8 *)win + 0x10;
        t++;
    }
}

void ov40_022393F4(void *p) {
    int i;
    void *win = (u8 *)PTR(p, 0x860) + 0x84;
    for (i = 0; i < 2; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}

void ov40_02239418(void *p) {
    void *win;
    const Ov40WinTemplate *t0 = ov40_022453D8;
    const Ov40WinTemplate *t1 = ov40_022453F8;
    int baseTile = 1;
    void *w = PTR(p, 0x860);
    int i;
    void *str;
    for (i = 0, win = (u8 *)w + 0x24; i < 2; i++) {
        InitWindow(win);
        if (WORD(w, 0x1C) == 0) {
            AddWindowParameterized(PTR(p, 0x24), win, 2, t0->x, t0->y, t0->width, t0->height, 0xE, baseTile);
            baseTile += t0->width * t0->height;
        } else {
            AddWindowParameterized(PTR(p, 0x24), win, 2, t1->x, t1->y, t1->width, t1->height, 0xE, baseTile);
            baseTile += t1->width * t1->height;
        }
        FillWindowPixelBuffer(win, 0);
        str = NewString_ReadMsgData(PTR(p, 0x48), 0x43);
        AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D00, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
        win = (u8 *)win + 0x10;
        t0++;
        t1++;
    }
}

void ov40_02239514(void *p) {
    int i;
    void *win = (u8 *)PTR(p, 0x860) + 0x24;
    for (i = 0; i < 2; i++) {
        ClearWindowTilemapAndCopyToVram(win);
        RemoveWindow(win);
        win = (u8 *)win + 0x10;
    }
}

u32 ov40_02239538(void *p, int idx) {
    if (idx >= 0x57) {
        idx = 0;
        GF_AssertFail();
    }
    if (ov40_02245CE8[idx] == 0xFFFF) {
        GF_AssertFail();
    }
    return GameStats_GetCapped(Save_GameStats_Get(PTR(p, 0x830)), ov40_02245CE8[idx]);
}

void ov40_02239574(void *p) {
    void *w = PTR(p, 0x860);
    void *mf;
    void *s;
    u16 nameBuf[0x100];
    int v28;
    int v24;
    int v20;
    void *s2;
    void *tn;
    void *str1;
    int species;
    str1 = String_New(0xFF, 0x6D);
    mf = ov40_0222DAB0(0x6D);
    FillWindowPixelBuffer((u8 *)w + 0x24, 0);
    if (WORD(w, 0x1C) == 0) {
        s = NewString_ReadMsgData(PTR(p, 0x4C), *((u8 *)PTR(w, 0x718) + WORD(w, 0xC) * 0x48) - 1);
    } else {
        s = NewString_ReadMsgData(PTR(p, 0x4C), *((u8 *)PTR(w, 0x714) + WORD(w, 0xC) * 0x1C8) - 1);
    }
    AddTextPrinterParameterizedWithColor((u8 *)w + 0x24, 0, s, 0, 0, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram((u8 *)w + 0x24);
    String_Delete(s);
    FillWindowPixelBuffer((u8 *)w + 0x34, 0);
    if (WORD(w, 0x1C) == 0) {
        s = NewString_ReadMsgData(PTR(p, 0x48), WORD(w, 0x14) + 0x52);
    } else {
        s = NewString_ReadMsgData(PTR(p, 0x48), 0x5B);
    }
    AddTextPrinterParameterizedWithColor((u8 *)w + 0x34, 0, s, 0, 0, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram((u8 *)w + 0x34);
    String_Delete(s);
    tn = sub_020315B8(PTR(p, 0x88C), 0x6D);
    ov40_02230DCC(p, tn);
    switch (WORD(w, 0x14)) {
    case 0:
        v20 = sub_02031700(PTR(p, 0x88C));
        s = NewString_ReadMsgData(PTR(p, 0x48), 0x55);
        s2 = NewString_ReadMsgData(PTR(w, 0x744), ov40_0222E658(v20, 4));
        BufferString(mf, 0, s2, 0, 1, 2);
        break;
    case 1:
        v24 = sub_020316F0(PTR(p, 0x88C));
        s = NewString_ReadMsgData(PTR(p, 0x48), 0x56);
        s2 = String_New(0xFF, 0x6D);
        BufferMonthNameAbbr(mf, 0, v24);
        break;
    case 2:
        species = sub_020315E0(PTR(p, 0x88C));
        v28 = sub_02031610(PTR(p, 0x88C));
        s = NewString_ReadMsgData(PTR(p, 0x48), 0x57);
        if (v28 != 0) {
            species = 0x1EE;
        }
        if (species != 0) {
            s2 = String_New(0xFF, 0x6D);
            GetSpeciesNameIntoArray(species, 0x6D, nameBuf);
            CopyU16ArrayToString(s2, nameBuf);
        } else {
            s2 = NewString_ReadMsgData(PTR(p, 0x48), 0x15);
        }
        BufferString(mf, 0, s2, 0, 1, 2);
        break;
    }
    BufferString(mf, 1, tn, 0, 1, 2);
    StringExpandPlaceholders(mf, str1, s);
    AddTextPrinterParameterizedWithColor((u8 *)w + 0x34, 0, str1, 0, 0x10, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram((u8 *)w + 0x34);
    String_Delete(s);
    String_Delete(s2);
    String_Delete(str1);
    String_Delete(tn);
    MessageFormat_ResetBuffers(mf);
    MessageFormat_Delete(mf);
}

void ov40_022397BC(void *p, int a) {
    void *w = PTR(p, 0x860);
    if (a == 0) {
        ManagedSprite_SetDrawFlag(PTR(w, 0xA8), 1);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0xAC), 1);
        ManagedSprite_SetPositionXY(PTR(w, 0xC4), 0x80, 0xE8);
    } else {
        ManagedSprite_SetDrawFlag(PTR(w, 0xA8), 0);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0xAC), 0);
        ManagedSprite_SetPositionXY(PTR(w, 0xC4), 0x50, 0xE8);
    }
    sub_020136B4(PTR(w, 0xAC), 0x24, -8);
    sub_020136B4(PTR(w, 0xC8), 0x24, -8);
}

void ov40_02239838(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D73C(p, 2);
    PTR(w, 0xA8) = ov40_0222D800(p, 2);
    PTR(w, 0xC4) = ov40_0222D800(p, 2);
    ov40_0222D5AC((u8 *)w + 0xA4, (u8 *)p + 0x14, 2);
    ov40_0222D5AC((u8 *)w + 0xC0, (u8 *)p + 0x14, 2);
    ov40_0222D66C((u8 *)w + 0xA4, (u8 *)p + 0x14, 0x35);
    ov40_0222D66C((u8 *)w + 0xC0, (u8 *)p + 0x14, 3);
    ManagedSprite_SetPositionXY(PTR(w, 0xA8), 0x20, 0xE8);
    ManagedSprite_SetPositionXY(PTR(w, 0xC4), 0x80, 0xE8);
    sub_020136B4(PTR(w, 0xAC), 0x24, -8);
    sub_020136B4(PTR(w, 0xC8), 0x24, -8);
    TextOBJ_SetSpritesDrawFlag(PTR(w, 0xAC), 0);
    TextOBJ_SetSpritesDrawFlag(PTR(w, 0xC8), 1);
    ov40_022397BC(p, 1);
}

void ov40_022398F8(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D6D0((u8 *)w + 0xA4);
    ov40_0222D6D0((u8 *)w + 0xC0);
    Sprite_DeleteAndFreeResources(PTR(w, 0xA8));
    Sprite_DeleteAndFreeResources(PTR(w, 0xC4));
    ov40_0222D7DC(p);
}

void ov40_0223992C(void *p) {
    Ov40Blob12 m = ov40_022453A0;
    WORD(p, 0x20) = m.v[WORD(p, 0x14)];
}

void ov40_02239954(u32 sel, int flag, void *scene) {
    void *w = PTR(scene, 0x860);
    if (flag != 0) {
        return;
    }
    switch (sel) {
    case 0:
        ov40_02230944(scene);
        S32(w, 0xC) = S32(w, 0xC) + 1;
        S32(w, 0xC) = S32(w, 0xC) % S32(w, 0x10);
        ov40_0222BF80(scene, 4);
        break;
    case 1:
        ov40_02230944(scene);
        S32(w, 0x14) = S32(w, 0x14) + 1;
        S32(w, 0x14) = S32(w, 0x14) % S32(w, 0x18);
        ov40_0222BF80(scene, 4);
        break;
    default:
        ov40_02230944(scene);
        ov40_0222BF80(scene, 7);
        break;
    }
}

int ov40_022399B8(void *p) {
    void *w = Heap_Alloc(0x6D, 0xB38);
    memset(w, 0, 0xB38);
    PTR(p, 0x860) = w;
    WORD(w, 0x1C) = WORD(p, 0x86C);
    WORD(w, 0x10) = 3;
    if (!sub_02087E1C(p)) {
        WORD(w, 0x10) = WORD(w, 0x10) - 1;
    }
    WORD(w, 0x18) = 3;
    ov40_0223992C(w);
    WORD(w, 0x744) = WORD(p, 0x48);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    ov40_0222D9E8(w, (u8 *)w + 4, 0);
    PTR(w, 0xDC) = TouchHitboxController_Create(ov40_022453AC, 3, ov40_02239954, p, 0x6D);
    ov40_0222BF80(p, 1);
    return 0;
}

int ov40_02239A58(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)w + 8, 1)) {
            WORD(p, 8) = WORD(p, 8) + 1;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, WORD(w, 8), WORD(p, 0x58));
        break;
    case 1:
        ov40_02230964(p, 1);
        ov40_0222D874(p);
        ov40_02239838(p);
        ov40_02230964(p, 0);
        SetBgPriority(0, 1);
        SetBgPriority(1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(3, 1);
        SetBgPriority(4, 1);
        SetBgPriority(5, 3);
        SetBgPriority(6, 0);
        SetBgPriority(7, 2);
        ov40_0222FB90(p, 0);
        sub_020879E0(PTR(p, 0x6F0), 0);
        WORD(p, 8) = WORD(p, 8) + 1;
        break;
    default:
        if (ov40_0222FBB4(p) != NULL) {
            ov40_0222BF80(p, 2);
        }
        break;
    }
    return 0;
}
