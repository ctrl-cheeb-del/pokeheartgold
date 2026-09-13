#include "to42_overlay40_r27_u6_private.h"

void ov40_022318C8(void *task, void *arg);
int ov40_022319A4(void *p);
int ov40_02231C78(void *p);
int ov40_02231EA4(void *p);

int ov40_02232094(void *p) {
    switch (WORD(p, 8)) {
    case 0:
        WORD(p, 0x54) = 0;
        BYTE(p, 0x5C) = BYTE(p, 0x5C) + 1;
        BYTE(p, 0x5C) = BYTE(p, 0x5C) % 7;
        WORD(p, 0x58) = ov40_0222DAC0(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA84((u8 *)p + 0x54, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        break;
    case 2:
        GfGfx_EngineATogglePlanes(0x10, 0);
        GfGfx_EngineBTogglePlanes(0x10, 0);
        ov40_0222DBEC(p, BYTE(p, 0x5C));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        WORD(p, 8)
        ++;
        break;
    case 3:
        GfGfx_EngineATogglePlanes(0x10, 1);
        GfGfx_EngineBTogglePlanes(0x10, 1);
        WORD(p, 8)
        ++;
        break;
    case 4:
        if (ov40_0222DA84((u8 *)p + 0x54, 0)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        break;
    default:
        WORD(p, 0x54) = 0;
        ov40_0222BF80(p, 0);
        break;
    }
    return 0;
}

int ov40_02232288(void *p) {
    void *w = Heap_Alloc(0x6D, 0x67 * 4);
    memset(w, 0, 0x67 * 4);
    PTR(p, 0x860) = w;
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    ov40_0222D9E8(w, (u8 *)w + 4, 0);
    ov40_0222BF80(p, 1);
    return 0;
}

int ov40_022322E0(void *p) {
    void *w = PTR(p, 0x860);
    int ok;

    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)w + 8, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, WORD(w, 8), WORD(p, 0x58));
        break;
    case 1:
        ov40_02230964(p, 1);
        ov40_0222D874(p);
        ov40_02230964(p, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(3, 2);
        SetBgPriority(4, 0);
        SetBgPriority(5, 3);
        SetBgPriority(6, 1);
        SetBgPriority(7, 2);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        WORD(p, 8)
        ++;
        break;
    default:
        ov40_0222FB90(p, 0);
        if (ov40_0222C4DC(p) == 1) {
            ok = 0;
            if (WORD(p, 0x86C) == 0) {
                ok = 1;
            } else if (sub_0203088C(PTR((u8 *)p + WORD(p, 0x86C) * 4, 0x87C), 5, ok) == 1) {
                ok = 1;
            } else if (WORD(p, 0x874) == 1) {
                ok = 1;
            }
            if (ok) {
                ov40_02233044(p);
                WORD(w, 0x66 * 4) = 0;
                ov40_0222BF80(p, 9);
            } else {
                WORD(w, 0x66 * 4) = 1;
                ov40_0222BF80(p, 6);
            }
        } else {
            ov40_0222BF80(p, 2);
        }
        break;
    }
    return 0;
}

int ov40_02232470(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        ov40_02233044(p);
        ov40_022307DC(p, 6, 7);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_02232F50(p);
        PTR(w, 0x5D * 4) = TouchHitboxController_Create(ov40_02245134, 3, ov40_02232ED4, p, 0x6D);
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
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}
