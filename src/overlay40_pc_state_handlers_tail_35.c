#include "overlay40_pc_state_handlers_tail_35_private.h"

void ov40_0223EDA8(void *p) {
    void *inner = PTR(p, 0x860);
    DestroyMsgData(PTR(inner, 0x4D4));
    Heap_Free(PTR(inner, 0x4DC));
    Heap_Free(PTR(inner, 0x4D0));
    WORD(inner, 0x4D8) = 0;
}

int ov40_0223EDE0(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DF60(p, 0x73);
        BYTE(inner, 0x4C3) = 0xFF;
        BYTE(inner, 0x4C4) = 0xFF;
        ov40_0223DDE8(p, BYTE(inner, 0x4C3), BYTE(inner, 0x4C4));
        ov40_022420B4(p, 1);
        ov40_022307DC(p, 0x39, 7);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 2)) {
            ov40_02230964(p, (void *)1);
            ov40_0222F9D4((u8 *)p + 0x47C, p);
            ov40_0222E8C4((u8 *)p + 0x49C, p, ov40_0224572C);
            ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
            ov40_0222F740((u8 *)p + 0x49C, p, 2);
            ov40_02230964(p, NULL);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    case 2:
        ov40_0222FA88((u8 *)p + 0x47C);
        ov40_0222F6D0((u8 *)p + 0x49C, *(s16 *)((u8 *)p + 0x48C));
        if (ov40_0222F38C((u8 *)p + 0x49C, p)) {
            BYTE(inner, 0x4C3) = sub_02031620(PTR(p, 0x88C));
            BYTE(inner, 0x4C4) = sub_0203162C(PTR(p, 0x88C));
            ov40_0223DDE8(p, BYTE(inner, 0x4C3), BYTE(inner, 0x4C4));
            WORD(p, 8)
            ++;
        }
        if (TouchscreenHitbox_TouchNewIsIn(ov40_02245650)) {
            ov40_02230944(p);
            WORD(p, 8)
            ++;
        }
        break;
    case 3:
        ov40_0222FA24((u8 *)p + 0x47C);
        ov40_0222F720((u8 *)p + 0x49C);
        ov40_0222F920((u8 *)p + 0x49C, p);
        WORD(p, 8)
        ++;
        /* fallthrough */
    case 4:
        ov40_0222DA84((u8 *)inner + 8, 1);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 2)) {
            ov40_022420B4(p, 0);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0xB);
        break;
    }
    return 0;
}

int ov40_0223EFA4(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_022307DC(p, 0x38, 3);
        ov40_022307DC(p, 0x3B, 7);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 2)) {
            ov40_0222DF60(p, 0x7C);
            ov40_0223DF1C(p, 0);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}

int ov40_0223F028(void *p) {
    void *inner = PTR(p, 0x860);
    if (!ov40_0223D5CC(p)) {
        return 0;
    }
    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DF60(p, 0x75);
        PlaySE(0x57D);
        WORD(p, 8)
        ++;
        break;
    case 1: {
        u32 v = BYTE(inner, 0x4C2);
        if (v == 0xFF) {
            if (sub_02087E1C(p) == 1) {
                v = 0xFF;
            } else {
                v = 0xFE;
            }
        }
        if (ov39_02227590(ov40_0223D540(p), HALF(inner, 0x4C0), v, BYTE(inner, 0x4C3), BYTE(inner, 0x4C4)) == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 2: {
        void *q;
        if (ov39_02227D44(ov40_0223D540(p), &q) == 1) {
            StopSE(0x57D, 0);
            ov40_022309DC(p, 7, WORD(q, 0xC), WORD(q, 4));
            WORD(p, 0x4138) = 0;
            WORD(p, 8)
            ++;
        } else {
            StopSE(0x57D, 0);
            WORD(p, 0x510) = 0x76;
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 3:
        if (WORD(p, 0x4138) == 0) {
            ov40_0222DF60(p, WORD(p, 0x510));
            PlaySE(0x57C);
        } else {
            PlaySE(0x577);
        }
        WORD(p, 8)
        ++;
        break;
    default:
        ov40_0222F734((u8 *)p + 0x49C);
        if (WORD(p, 0x4138) == 0) {
            ov40_0222BF80(p, 3);
        } else {
            ov40_0222BF80(p, 0xD);
        }
        break;
    }
    return 0;
}

int ov40_0223F16C(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_0223E024(p);
        ov40_0223E064(p);
        ov40_0222DFB0(p);
        TouchHitboxController_Destroy(PTR(inner, 0x608));
        TouchHitboxController_Destroy(PTR(inner, 0x60C));
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 1);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 0)) {
            ov40_022420B4(p, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0xE);
        break;
    }
    return 0;
}

int ov40_0223F200(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (sub_0202FC48()) {
            sub_0202FC24();
        }
        *(Ov40Blk44 *)((u8 *)inner + 0x4E0) = ov40_022457B0;
        WORD(inner, 0x4E0) = 0;
        WORD(inner, 0x4E4) = WORD(p, 0x4138);
        ov40_0222FE00(p);
        PTR(inner, 0x50C) = ov40_0222FE8C(0x6D);
        ov40_022307DC(p, 4, 3);
        ov40_022307DC(p, 7, 7);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        ov40_0223E0A4(p);
        ov40_02230964(p, (void *)1);
        ov40_0222F9D4((u8 *)p + 0x47C, p);
        ov40_0222E9B8((u8 *)p + 0x49C, p, 0, (u8 *)inner + 0x4E0);
        WORD(p, 0x4E4) = 1;
        ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
        ov40_02230964(p, NULL);
        ov40_02230964(p, (void *)1);
        ov40_0222F740((u8 *)p + 0x49C, p, 1);
        ov40_0222F858((u8 *)p + 0x49C, 0x40, 0xB8);
        ov40_0222F488((u8 *)p + 0x49C, p);
        ov40_02230964(p, NULL);
        ov40_02230964(p, (void *)1);
        ov40_0223D68C(p);
        ov40_0223D830(p, 0);
        ov40_02230964(p, NULL);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            ov40_0223D830(p, 1);
            ov40_0223077C(p, PTR(p, 0x6F0), 0x10, (s16)(WORD(p, 0x4D8) * 0x18 + 0x4C));
            sub_020879E0(PTR(p, 0x6F0), 1);
            sub_02087A08(PTR(p, 0x6F0), 0xC, 0xC);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0xF);
        break;
    }
    return 0;
}

int ov40_0223F3E4(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_0222FA88((u8 *)p + 0x47C);
        ov40_0222F5EC((u8 *)p + 0x49C, *(s16 *)((u8 *)p + 0x48C));
        ov40_0222F488((u8 *)p + 0x49C, p);
        sub_020878EC(PTR(p, 0x6F0), 0x10, (s16)(WORD(p, 0x4D8) * 0x18 + 0x4C));
        ov40_0223D8D4(p);
        if (TouchscreenHitbox_TouchNewIsIn(ov40_0224564C)) {
            ov40_02230944(p);
            WORD(inner, 0xC) = 0x11;
            WORD(p, 8)
            ++;
        }
        if (TouchscreenHitbox_TouchNewIsIn(ov40_02245650)) {
            ov40_02230944(p);
            WORD(inner, 0xC) = 0x10;
            WORD(p, 8)
            ++;
        }
        break;
    case 1:
        ov40_0222FA24((u8 *)p + 0x47C);
        ov40_0222F720((u8 *)p + 0x49C);
        ov40_0222F920((u8 *)p + 0x49C, p);
        ov40_0222FE98(PTR(inner, 0x50C));
        ov40_0223D874(p);
        ov40_0222FE68(p);
        ov40_0223E024(p);
        ov40_0223E064(p);
        sub_020879E0(PTR(p, 0x6F0), 0);
        sub_02087A08(PTR(p, 0x6F0), 0, 0);
        if (WORD(inner, 0xC) == 0x10) {
            ov40_0222FA18((u8 *)p + 0x47C);
            ov40_0222F734((u8 *)p + 0x49C);
            WORD(inner, 0x510) = 0;
        }
        WORD(p, 8)
        ++;
        /* fallthrough */
    case 2:
        ov40_0222DA84((u8 *)inner + 8, 1);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 0)) {
            ov40_022420B4(p, 0);
            if (WORD(inner, 0xC) == 0x11) {
                ov40_0222D66C((u8 *)inner + 0x10, (u8 *)p + 0x14, 3);
                ov40_0222D66C((u8 *)inner + 0x2C, (u8 *)p + 0x14, 0x5E);
                ManagedSprite_SetAnim(PTR(inner, 0x14), 0);
                ManagedSprite_SetAnim(PTR(inner, 0x30), 3);
            }
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, WORD(inner, 0xC));
        break;
    }
    return 0;
}

int ov40_0223F59C(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_022307DC(p, 0x38, 3);
        ov40_022307DC(p, 0x3B, 7);
        ov40_022420B4(p, 0);
        PTR(inner, 0x608) = TouchHitboxController_Create(ov40_022456C4, 5, ov40_02241D10, p, 0x6D);
        PTR(inner, 0x60C) = TouchHitboxController_Create(ov40_02245708, 9, ov40_02241E14, p, 0x6D);
        ov40_0223DF1C(p, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
            ov40_0222DED0(p, 0x7C);
            ov40_0223DBD4(p, 0);
            ov40_0223DD68(p, HALF(inner, 0x4C0));
            ov40_0223DCF0(p, BYTE(inner, 0x4C2));
            ov40_0223DDE8(p, BYTE(inner, 0x4C3), BYTE(inner, 0x4C4));
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}

int ov40_0223F6BC(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_022307DC(p, 6, 7);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_022408AC(p);
        PTR(inner, 0x608) = TouchHitboxController_Create(ov40_022456B4, 4, ov40_02241E40, p, 0x6D);
        PTR(inner, 0x60C) = TouchHitboxController_Create(ov40_02245674, 4, ov40_02241ED4, p, 0x6D);
        PTR(inner, 0x610) = TouchHitboxController_Create(ov40_02245654, 2, ov40_02241F3C, p, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 2:
        WORD(inner, 0x1CC) = 0;
        ov40_02230964(p, (void *)1);
        ov40_02230638((u8 *)inner + 0x10C, p);
        ov40_022307DC(p, ov40_02230410((u8 *)inner + 0x10C), 3);
        ov40_022306A0((u8 *)inner + 0x10C, 0);
        ov40_02230964(p, NULL);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
            ov40_022306A0((u8 *)inner + 0x10C, 1);
            ov40_02241AB0(p);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0x12);
        break;
    }
    return 0;
}

int ov40_0223F830(void *p) {
    void *inner = PTR(p, 0x860);
    TouchHitboxController_IsTriggered(PTR(inner, 0x608));
    return 0;
}

int ov40_0223F848(void *p) {
    if (ov40_0224222C(p)) {
        ov40_0222BF80(p, 0x12);
    }
    return 0;
}

int ov40_0223F860(void *p) {
    void *inner = PTR(p, 0x860);
    if (ov40_02242CFC(p)) {
        Heap_Free(inner);
        return 1;
    }
    return 0;
}

int ov40_0223F880(void *p) {
    void *inner = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        TouchHitboxController_Destroy(PTR(inner, 0x608));
        TouchHitboxController_Destroy(PTR(inner, 0x60C));
        TouchHitboxController_Destroy(PTR(inner, 0x610));
        GfGfx_EngineBTogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        ov40_02240910(p);
        ov40_02230964(p, (void *)1);
        if (WORD(inner, 0x1CC) == 0) {
            ov40_0223064C((u8 *)inner + 0x10C, p);
        } else {
            ov40_0222E7B8((u8 *)inner + 0x80, p);
        }
        ov40_02230964(p, NULL);
        ov40_02241A34(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 1);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 0)) {
            ov40_0222D66C((u8 *)inner + 0x10, (u8 *)p + 0x14, 3);
            ov40_0222D66C((u8 *)inner + 0x2C, (u8 *)p + 0x14, 0x6F);
            ManagedSprite_SetAnim(PTR(inner, 0x14), 0);
            ManagedSprite_SetAnim(PTR(inner, 0x30), 1);
            ov40_022420B4(p, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0xE);
        break;
    }
    return 0;
}

int ov40_0223F984(Ov40Work *work) {
    void *inner = PTR(work, 0x860);
    if (ov40_02230D94(work, sub_0203088C(sub_020307F8(), 4, 0))) {
        switch (WORD(work, 8)) {
        case 0:
            ov40_02230964(work, (void *)1);
            if (WORD(inner, 0x1CC) == 0) {
                ov40_0223064C((u8 *)inner + 0x10C, work);
            } else {
                inner = (u8 *)inner + 0x80;
                ov40_0222E7B8(inner, work);
            }
            ov40_02241A34(work);
            ov40_02230964(work, NULL);
            GfGfx_EngineATogglePlanes(4, 0);
            GfGfx_EngineBTogglePlanes(4, 0);
            WORD(work, 8)
            ++;
            break;
        case 1:
            ov40_0222DA84((u8 *)inner + 8, 1);
            if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 0)) {
                ov40_02230964(work, (void *)1);
                ov40_022421FC(work);
                ov40_02241054(work);
                ov40_02230964(work, NULL);
                BgClearTilemapBufferAndCommit(PTR(work, 0x24), 3);
                BgClearTilemapBufferAndCommit(PTR(work, 0x24), 7);
                WORD(work, 8)
                ++;
            }
            PaletteData_BlendPalettes(PTR(work, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(work, 0x58));
            break;
        case 2:
            ov40_0222DED0(work, 0x115);
            WORD(work, 8)
            ++;
            break;
        case 3:
            if (System_GetTouchNew()) {
                ov40_02241114(work);
                ov40_0222DFB0(work);
                BgClearTilemapBufferAndCommit(PTR(work, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(work, 0x24), 6);
                GfGfx_EngineBTogglePlanes(4, 0);
                GfGfx_EngineATogglePlanes(4, 0);
                WORD(work, 8)
                ++;
            }
            break;
        case 4:
            ov40_02230964(work, (void *)1);
            ov40_02242110(work);
            if (WORD(work, 0x86C) == 0xD2) {
                ov40_0222D66C((u8 *)inner + 0x10, (u8 *)work + 0x14, 3);
                ov40_0222D66C((u8 *)inner + 0x2C, (u8 *)work + 0x14, 0x5E);
                ManagedSprite_SetAnim(PTR(inner, 0x14), 0);
                ManagedSprite_SetAnim(PTR(inner, 0x30), 3);
            }
            ov40_02230964(work, NULL);
            ov40_02241AB0(work);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x14), 0x3E, PTR(work, 0x24), 3, 0, 0, 0, 0x6D);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x14), 0x3E, PTR(work, 0x24), 7, 0, 0, 0, 0x6D);
            ov40_02230964(work, (void *)1);
            if (WORD(inner, 0x1CC) == 0) {
                ov40_02230638((u8 *)inner + 0x10C, work);
                ov40_022306A0((u8 *)inner + 0x10C, 0);
                ov40_022307DC(work, ov40_02230410((u8 *)inner + 0x10C), 3);
            } else {
                ov40_0222E79C((u8 *)inner + 0x80, work);
                inner = (u8 *)inner + 0x80;
                ov40_0222E7DC(inner, 0);
                GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 0x50, PTR(work, 0x24), 3, 0, 0, 0, 0x6D);
            }
            ov40_02230964(work, NULL);
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x14), 6, PTR(work, 0x24), 7, 0, 0, 0, 0x6D);
            WORD(work, 8)
            ++;
            break;
        case 5:
            ov40_0222DA84((u8 *)inner + 8, 0);
            if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
                if (WORD(inner, 0x1CC) == 0) {
                    ov40_022306A0((u8 *)inner + 0x10C, 1);
                } else {
                    ov40_0222E7DC((u8 *)inner + 0x80, 1);
                }
                GfGfx_EngineBTogglePlanes(4, 1);
                GfGfx_EngineATogglePlanes(4, 1);
                WORD(work, 8)
                ++;
            }
            PaletteData_BlendPalettes(PTR(work, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(work, 0x58));
            break;
        default: {
            int i;
            for (i = 0; i < work->count; i++) {
                work->ptrs[i] = &work->entries[i];
            }
            ov40_0222BF80(work, 0x12);
            break;
        }
        }
    } else {
        if (ov40_02242378(work)) {
            ov40_0222BF80(work, 0x17);
        }
    }
    return 0;
}

int ov40_0223FCA0(void *p) {
    void *inner = PTR(p, 0x860);
    TouchHitboxController_IsTriggered(PTR(inner, 0x60C));
    return 0;
}

int ov40_0223FCB8(Ov40Work *work) {
    int i;
    if (ov40_02242AEC(work)) {
        for (i = 0; i < work->count; i++) {
            work->ptrs[i] = &work->entries[i];
        }
        ov40_0222BF80(work, 0x12);
    }
    return 0;
}

int ov40_0223FCF8(Ov40Work *work) {
    int i;
    if (ov40_022428D4(work)) {
        for (i = 0; i < work->count; i++) {
            work->ptrs[i] = &work->entries[i];
        }
        ov40_0222BF80(work, 0x12);
    }
    return 0;
}

int ov40_0223FD38(void *p) {
    if (ov40_02242490(p)) {
        ov40_0222BF80(p, 0x1A);
    }
    return 0;
}

int ov40_0223FD50(void *p) {
    void *inner = PTR(p, 0x860);
    TouchHitboxController_IsTriggered(PTR(inner, 0x610));
    return 0;
}

int ov40_0223FD68(void *p) {
    if (ov40_0224253C(p)) {
        ov40_0222BF80(p, 0x17);
    }
    return 0;
}
