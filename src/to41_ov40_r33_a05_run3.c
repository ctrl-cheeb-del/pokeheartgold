#include "to41_ov40_r33_a05_private.h"

void ov40_0223BA70(void *p) {
    Ov40Msg3 ids;
    void *w = PTR(p, 0x860);
    void *win = (u8 *)w + 0x14;
    void *s;
    u32 x;
    ids = ov40_022454A4;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 2, 3, 3, 0x14, 4, 0xE, 0x20);
    FillWindowPixelBuffer(win, 0);
    s = NewString_ReadMsgData(PTR(p, 0x48), ids.e[WORD(w, 0xC)]);
    AddTextPrinterParameterizedWithColor(win, 0, s, 0, 0, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(s);
    win = (u8 *)w + 0x94;
    InitWindow(win);
    AddWindowParameterized(PTR(p, 0x24), win, 6, 0xB, 6, 0xA, 4, 0xE, 0x100);
    FillWindowPixelBuffer(win, 0);
    s = NewString_ReadMsgData(PTR(p, 0x48), 0x5F);
    x = (0x50 - FontID_String_GetWidthMultiline(0, s, 0)) / 2;
    AddTextPrinterParameterizedWithColor(win, 0, s, x, 0, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(s);
    WORD(w, 0x202C) = 1;
    WORD(w, 0x2030) = 1;
}

int ov40_0223BB74(void *p) {
    Ov40BBWork *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (sub_0202FC48()) {
            sub_0202FC24();
        }
        w->block = ov40_022454F0;
        w->block.e[0] = 0;
        w->block.e[1] = (u32)PTR(p, 0x4138);
        ov40_0222FE00(p);
        w->obj = ov40_0222FE8C(0x6D);
        w->value2088 = 0x1F4;
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        ov40_022307DC(p, 4, 3);
        ov40_022307DC(p, 7, 7);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        ov40_0223B4BC(p, 1);
        ov40_0223BA70(p);
        ov40_02230964(p, 1);
        ov40_0222F9D4((u8 *)p + 0x47C, p);
        ov40_0222E9B8((u8 *)p + 0x49C, p, 0, &w->block);
        WORD(p, 0x4E4) = 1;
        ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
        ov40_0222F740((u8 *)p + 0x49C, p, 1);
        ov40_0222F858((u8 *)p + 0x49C, 0x40, 0xB8);
        ov40_0222F488((u8 *)p + 0x49C, p);
        ov40_02230964(p, 0);
        ov40_02230964(p, 1);
        ov40_0223D008(p);
        ov40_0223D1AC(p, 0);
        ov40_02230964(p, 0);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)w + 8, 0);
        if (ov40_0222DA00(w, (u8 *)w + 4, 0, 0)) {
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            ov40_0223D1AC(p, 1);
            ov40_0223077C(p, PTR(p, 0x6F0), 0x10, (s16)(WORD(p, 0x4D8) * 0x18 + 0x4C));
            sub_020879E0(PTR(p, 0x6F0), 1);
            sub_02087A08(PTR(p, 0x6F0), 0xC, 0xC);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xC);
        BLEND(p, w, 2, 0xC);
        break;
    default:
        ov40_0222BF80(p, 4);
        break;
    }
    return 0;
}

int ov40_0223BD98(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_0222FA88((u8 *)p + 0x47C);
        ov40_0222F5EC((u8 *)p + 0x49C, SHALF(p, 0x48C));
        ov40_0222F488((u8 *)p + 0x49C, p);
        sub_020878EC(PTR(p, 0x6F0), 0x10, (s16)(WORD(p, 0x4D8) * 0x18 + 0x4C));
        ov40_0223D244(p);
        if (TouchscreenHitbox_TouchNewIsIn(&ov40_02245494)) {
            ov40_02230944(p);
            if (PTR((u8 *)p + WORD(p, 0x4D4) * 4, 0x2608)) {
                WORD(w, 0x2034) = 6;
                WORD(w, 0x10) = 0;
                WORD(p, 8)
                ++;
            }
        }
        if (TouchscreenHitbox_TouchNewIsIn(&ov40_02245498)) {
            ov40_02230944(p);
            WORD(w, 0x2034) = 5;
            WORD(p, 8)
            ++;
        }
        break;
    case 1:
        ov40_0222FA24((u8 *)p + 0x47C);
        ov40_0222F720((u8 *)p + 0x49C);
        ov40_0222F920((u8 *)p + 0x49C, p);
        ov40_0222FE98(PTR(w, 0x2080));
        ov40_0223D1F0(p);
        ov40_0222FE68(p);
        ov40_0223B538(p);
        ov40_0223B574(p);
        sub_020879E0(PTR(p, 0x6F0), 0);
        sub_02087A08(PTR(p, 0x6F0), 0, 0);
        if (WORD(w, 0x2034) == 5) {
            ov40_0222FA18((u8 *)p + 0x47C);
            ov40_0222F734((u8 *)p + 0x49C);
            WORD(w, 0x2084) = 0;
        }
        WORD(p, 8)
        ++;
    case 2:
        ov40_0222DA84((u8 *)w + 8, 1);
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 0)) {
            ov40_0223B4BC(p, 0);
            if (WORD(w, 0x2034) == 6) {
                ov40_0222D66C((u8 *)w + 0x114, (u8 *)p + 0x14, 3);
                ov40_0222D66C((u8 *)w + 0x130, (u8 *)p + 0x14, 0x5E);
                ManagedSprite_SetAnim(PTR(w, 0x118), 0);
                ManagedSprite_SetAnim(PTR(w, 0x134), 3);
            }
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xC);
        BLEND(p, w, 2, 0xC);
        break;
    default:
        ov40_0222BF80(p, WORD(w, 0x2034));
        break;
    }
    return 0;
}

int ov40_0223BF88(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_0223B538(p);
        ov40_0223B574(p);
        ov40_0222DFB0(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)w + 8, 1);
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 0)) {
            ov40_02230964(p, 1);
            ov40_0223B480(p);
            ov40_02230964(p, 0);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xC);
        break;
    case 2:
        ov40_0222DAA8((u8 *)w + 8);
        ov40_0222D88C(p);
        sub_0203A948(1, 0x6D);
        ov40_0222FB90(p, 1);
        WORD(p, 8)
        ++;
        break;
    default:
        if (ov40_0222FBB4(p)) {
            if (ov40_0222DA84((u8 *)w + 8, 0)) {
                ov40_0222DD08(p);
                ov40_0222DAA8((u8 *)w + 8);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)WORD(p, 0x58));
                ov40_0222BF64(p, 1, 1, PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
                Heap_Free(w);
            } else {
                BLEND(p, w, 1, 2);
                BLEND(p, w, 3, 0xC);
            }
        }
        break;
    }
    return 0;
}

int ov40_0223C0D8(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_022307DC(p, 6, 7);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0223CFA8(p);
        PTR(w, 0x188) = TouchHitboxController_Create(&ov40_022454E0, 4, &ov40_0223CE64, p, 0x6D);
        PTR(w, 0x18C) = TouchHitboxController_Create(&ov40_022454B0, 4, &ov40_0223CF00, p, 0x6D);
        PTR(w, 0x190) = TouchHitboxController_Create(&ov40_0224549C, 2, &ov40_0223CF70, p, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_02230964(p, 1);
        ov40_02230638((u8 *)w + 0x220, p);
        ov40_022307DC(p, ov40_02230410((u8 *)w + 0x220), 3);
        ov40_022306A0((u8 *)w + 0x220, 0);
        ov40_02230964(p, 0);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84((u8 *)w + 8, 0);
        if (ov40_0222DA00(w, (u8 *)w + 4, 0, 0)) {
            ov40_022306A0((u8 *)w + 0x220, 1);
            ov40_0223CD14(p);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xC);
        break;
    default:
        ov40_0222BF80(p, 7);
        break;
    }
    return 0;
}
