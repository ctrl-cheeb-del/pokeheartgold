#include "overlay40_trainer_card_panels_private.h"

int ov40_022413EC(void *p);
int ov40_02241404(void *p);
int ov40_0224141C(void *p);
int ov40_02241434(void *p);
int ov40_0224144C(void *p);
int ov40_02241464(void *p);
int ov40_02241144(void *p);

void ov40_02240E28(void *p, int msgId, int unused) {
    void *win = (u8 *)p + 0x8A4;
    void *w = PTR(p, 0x860);
    void *str;
    (void)unused;
    ov40_0222C6C8(p, 2);
    GfGfx_EngineATogglePlanes(4, 1);
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 2, 1, 0x13, 0x1E, 4, 0xE, 0x12C);
    if (msgId == 0x64) {
        u32 v = WORD(w, 0x80);
        void *fmt = ov40_0222DAB0(0x6D);
        void *name;
        void *s;
        str = String_New(0xFF, 0x6D);
        s = sub_020315B8(v, 0x6D);
        ov40_02230DCC(p, s);
        name = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        BufferString(fmt, 0, s, 0, 1, 2);
        StringExpandPlaceholders(fmt, str, name);
        String_Delete(s);
        String_Delete(name);
        MessageFormat_Delete(fmt);
    } else {
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
    }
    FillWindowPixelBuffer(win, 0xCC);
    AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(str);
}

void ov40_02240F24(void *p, int msgId, int idx) {
    void *win = (u8 *)p + 0x8A4;
    void *w = PTR(p, 0x860);
    void *str;
    if (msgId == 0x64) {
        u32 v = WORD(w, 0x80);
        void *fmt = ov40_0222DAB0(0x6D);
        void *name;
        void *s;
        str = String_New(0xFF, 0x6D);
        s = sub_020315B8(v, 0x6D);
        ov40_02230DCC(p, s);
        name = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        BufferString(fmt, 0, s, 0, 1, 2);
        StringExpandPlaceholders(fmt, str, name);
        String_Delete(s);
        String_Delete(name);
        MessageFormat_Delete(fmt);
    } else if (msgId == 0x66) {
        u32 v = ((u32 *)((u8 *)p + 0x88C))[idx];
        void *fmt = ov40_0222DAB0(0x6D);
        void *name;
        void *s;
        str = String_New(0xFF, 0x6D);
        s = sub_020315B8(v, 0x6D);
        ov40_02230DCC(p, s);
        name = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        BufferString(fmt, 0, s, 0, 1, 2);
        StringExpandPlaceholders(fmt, str, name);
        String_Delete(s);
        String_Delete(name);
        MessageFormat_Delete(fmt);
    } else {
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
    }
    FillWindowPixelBuffer(win, 0xCC);
    AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(str);
}

void ov40_02241054(void *p) {
    void *w = PTR(p, 0x860);
    Ov40Quad a = ov40_02245684;
    Ov40Quad b = ov40_02245694;
    void *src;
    u32 *pa;
    int x;
    void *obj;
    u32 *pb;
    int i;
    ov40_0222D78C(p, 2);
    pa = a.v;
    x = 0x69;
    src = p;
    i = 0;
    obj = (u8 *)w + 0x10;
    pb = b.v;
    src = (u8 *)src + 0x14;
    for (; i < 4; i++) {
        WORD(w, 0x14) = (u32)ov40_0222D800(p, 2);
        ov40_0222D5AC(obj, src, 2);
        ov40_0222D66C(obj, src, *pa);
        if (i != 3) {
            ov40_02240D50(obj, p, i + 1);
        }
        ManagedSprite_SetPositionXY(PTR(w, 0x14), 0x32, (s16)x);
        ManagedSprite_SetAnim(PTR(w, 0x14), *pb);
        sub_020136B4(PTR(w, 0x18), 0x24, -8);
        TextOBJ_SetSpritesDrawFlag(PTR(w, 0x18), 1);
        pa++;
        w = (u8 *)w + 0x1C;
        obj = (u8 *)obj + 0x1C;
        pb++;
        x += 0x24;
    }
}

void ov40_02241114(void *p) {
    void *q;
    void *w = PTR(p, 0x860);
    int i;
    q = (u8 *)w + 0x10;
    for (i = 0; i < 4; i++) {
        ov40_0222D6D0(q);
        Sprite_DeleteAndFreeResources(PTR(w, 0x14));
        q = (u8 *)q + 0x1C;
        w = (u8 *)w + 0x1C;
    }
    ov40_0222D7DC(p);
}

int ov40_02241144(void *p) {
    void *w = PTR(p, 0x860);
    if (ov40_02230D94(p, sub_0203088C(sub_020307F8(), 4, 0))) {
        switch (WORD(p, 8)) {
        case 0:
            ov40_02230964(p, (void *)1);
            if (WORD(w, 0x1CC) == 0) {
                ov40_0223064C((u8 *)w + 0x10C, p);
            } else {
                ov40_0222E7B8((u8 *)w + 0x80, p);
            }
            ov40_02230964(p, NULL);
            ov40_02241A34(p);
            GfGfx_EngineATogglePlanes(4, 0);
            GfGfx_EngineBTogglePlanes(4, 0);
            WORD(p, 8)
            ++;
            break;
        case 1:
            ov40_0222DA84((int *)w + 2, 1);
            if (ov40_0222DA00((int *)w, (int *)w + 1, 1, 0)) {
                ov40_02230964(p, (void *)1);
                ov40_022421FC(p);
                ov40_02241054(p);
                ov40_02230964(p, NULL);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
                WORD(p, 8)
                ++;
            }
            BLEND(p, w, 3, 0xC);
            break;
        case 2:
            ov40_0222DED0(p, 0x115);
            WORD(p, 8)
            ++;
            break;
        case 3:
            if (System_GetTouchNew()) {
                ov40_0222DFB0(p);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
                GfGfx_EngineBTogglePlanes(4, 0);
                GfGfx_EngineATogglePlanes(4, 0);
                WORD(p, 8)
                ++;
            }
            break;
        case 4:
            ov40_0222DA84((int *)w + 2, 1);
            if (ov40_0222DA00((int *)w, (int *)w + 1, 1, 0)) {
                ov40_02241114(p);
                WORD(p, 8)
                ++;
            }
            BLEND(p, w, 3, 0xC);
            break;
        case 5:
            TouchHitboxController_Destroy(PTR(w, 0x608));
            TouchHitboxController_Destroy(PTR(w, 0x60C));
            TouchHitboxController_Destroy(PTR(w, 0x610));
            ov40_0222DAA8((int *)w + 2);
            ov40_02230964(p, (void *)1);
            ov40_02240910(p);
            ov40_0222D88C(p);
            ov40_02230964(p, NULL);
            ov40_0222FB90(p, 1);
            WORD(p, 8)
            ++;
            break;
        default:
            if (ov40_0222FBB4(p) != NULL) {
                if (ov40_0222DA84((int *)w + 2, 0)) {
                    ov40_0222DD08(p);
                    ov40_0222DAA8((int *)w + 2);
                    PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)WORD(p, 0x58));
                    ov40_0222BF64(p, 1, TRUE, (u32 *)PTR(p, 0x10));
                    ov40_0222BF80(p, 5);
                    Heap_Free(w);
                    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
                    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
                    if (sub_0202FC48() == 1) {
                        sub_0202FC24();
                    }
                } else {
                    BLEND(p, w, 1, 2);
                    BLEND(p, w, 3, 0xC);
                }
            }
            break;
        }
    } else {
        if (ov40_02242378(p)) {
            ov40_0222BF80(p, 0xD);
        }
    }
    return 0;
}

int ov40_022413EC(void *p) {
    TouchHitboxController_IsTriggered(PTR(PTR(p, 0x860), 0x60C));
    return 0;
}

int ov40_02241404(void *p) {
    if (ov40_02242AEC(p)) {
        ov40_0222BF80(p, 8);
    }
    return 0;
}

int ov40_0224141C(void *p) {
    if (ov40_022428D4(p)) {
        ov40_0222BF80(p, 8);
    }
    return 0;
}

int ov40_02241434(void *p) {
    if (ov40_02242490(p)) {
        ov40_0222BF80(p, 0x10);
    }
    return 0;
}

int ov40_0224144C(void *p) {
    TouchHitboxController_IsTriggered(PTR(PTR(p, 0x860), 0x610));
    return 0;
}

int ov40_02241464(void *p) {
    if (ov40_0224253C(p)) {
        ov40_0222BF80(p, 0xD);
    }
    return 0;
}
