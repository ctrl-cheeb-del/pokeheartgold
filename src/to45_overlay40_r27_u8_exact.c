#include "to45_overlay40_r27_u8_private.h"

int ov40_02232A48(void *p) {
    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DED0(p, 0x12B);
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    case 2:
        if (WORD(p, 0x874) == 0) {
            void *unused;
            sub_0202FC90(PTR(p, 0x830), 0x6D, &unused, 0, PTR(p, 0x86C));
            ov40_02244BBC(PTR(p, 0x830), PTR(p, 0x86C));
            sub_0202FC24();
            ov40_0222FDC4(p);
            ov40_0222FCCC(p);
        }
        WORD(p, 8)
        ++;
        break;
    default:
        ov40_0222DFB0();
        ov40_02233044(p);
        ov40_0222BF80(p, 9);
        break;
    }
    return 0;
}

int ov40_02232AF8(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    case 2:
        if (WORD(w, 0x198) == 0) {
            ov40_02230964(p, 1);
            if (WORD(w, 0xC) == 0) {
                ov40_0223064C((u8 *)w + 0x9C, p);
            } else {
                ov40_0222E7B8((u8 *)w + 0x10, p);
            }
            ov40_02230964(p, 0);
            TouchHitboxController_Destroy(PTR(w, 0x174));
            ov40_02232FCC(p);
            ov40_022330B8(p);
        }
        ov40_02230964(p, 1);
        ov40_0222D8C8(p);
        ov40_02230964(p, 0);
        ov40_0222C4E8(p, *(void **)PTR(p, 0x10));
        sub_02087A84(PTR(p, 0x868), 1, 0);
        WORD(p, 8)
        ++;
        break;
    default:
        Heap_Free(w);
        return 1;
    }
    return 0;
}

int ov40_02232BD8(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        TouchHitboxController_Destroy(PTR(w, 0x174));
        GfGfx_EngineBTogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        if (WORD(w, 0xC) == 0) {
            ov40_0223064C((u8 *)w + 0x9C, p);
        } else {
            ov40_0222E7B8((u8 *)w + 0x10, p);
        }
        ov40_02232FCC(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)w + 8, 1);
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 0)) {
            ov40_022330B8(p);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        break;
    case 2:
        ov40_0222FB90(p, 1);
        ov40_02230964(p, 1);
        ov40_0222D88C(p);
        ov40_02230964(p, 0);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
        WORD(p, 8)
        ++;
        break;
    default:
        if (ov40_0222FBB4()) {
            if (ov40_0222DA84((u8 *)w + 8, 0)) {
                ov40_0222DD08(p);
                ov40_0222DAA8((u8 *)w + 8);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, WORD(p, 0x58));
                ov40_0222BF64(p, 1, 1, PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                Heap_Free(w);
            } else {
                PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
                PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, WORD(w, 8), WORD(p, 0x58));
            }
        }
        break;
    }
    return 0;
}

int ov40_02232D44(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        ov40_022307DC(p, 6, 7);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_02232F50(p);
        PTR(w, 0x174) = TouchHitboxController_Create(ov40_02245134, 3, ov40_02232ED4, p, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_02230964(p, 1);
        ov40_02230638((u8 *)w + 0x9C, p);
        ov40_022307DC(p, ov40_02230410((u8 *)w + 0x9C), 3);
        ov40_022306A0((u8 *)w + 0x9C, 0);
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
            ov40_022306A0((u8 *)w + 0x9C, 1);
            ov40_02232F88(p);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            if (WORD(w, 0x198) == 1) {
                WORD(p, 8) = 0xFF;
            } else {
                WORD(p, 8)
                ++;
            }
            WORD(w, 0x198) = 0;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        break;
    case 4:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 5:
        if (IsPaletteFadeFinished() == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    default:
        WORD(p, 0x6D8)
        ++;
        ov40_0222C4B8(p);
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}

void ov40_02232ED4(int hitbox, int event, void *p) {
    void *w = PTR(p, 0x860);

    if (event != 0) {
        return;
    }
    switch (hitbox) {
    case 0:
        ov40_02230944(p);
        ov40_0222BF80(p, 4);
        break;
    case 1:
        ov40_02230944(p);
        if (WORD(p, 0x86C) == 0 || sub_0203088C(PTR(w, 0xA0), 5, 0) == 1) {
            ov40_0222BF80(p, 7);
        } else {
            ov40_0222BF80(p, 5);
        }
        break;
    case 2:
        ov40_02230944(p);
        ov40_0222BF80(p, 8);
        break;
    }
}
