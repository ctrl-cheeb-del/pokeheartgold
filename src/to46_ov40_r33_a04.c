#include "to46_ov40_r33_a04_private.h"

int ov40_0223AF3C(void *p) {
    u8 *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        GfGfx_EngineBTogglePlanes(4, FALSE);
        GfGfx_EngineATogglePlanes(4, FALSE);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84(w + 8, 1);
        if (ov40_0222DA00(w, w + 4, 1, 0)) {
            ov40_02230964(p, 1);
            ov40_0223B44C(p);
            ov40_02230964(p, 0);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xc, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 2:
        ov40_0223A430(p);
        if (WORD(p, 0x86c) == 0xd2) {
            ov40_0222D66C(w + 0x114, (u8 *)p + 0x14, 3);
            ov40_0222D66C(w + 0x130, (u8 *)p + 0x14, 0x5e);
            ManagedSprite_SetAnim(PTR(w, 0x118), 0);
            ManagedSprite_SetAnim(PTR(w, 0x134), 3);
        }
        ov40_0223CD14(p);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 3, 0, 0, 0, 0x6d);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 7, 0, 0, 0, 0x6d);
        ov40_02230964(p, 1);
        if (WORD(w, 0x10) == 0) {
            ov40_02230638(w + 0x220, p);
            ov40_022306A0(w + 0x220, 0);
            ov40_022307DC(p, ov40_02230410(w + 0x220), 3);
        } else {
            ov40_0222E79C(w + 0x194, p);
            ov40_0222E7DC(w + 0x194, 0);
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x50, PTR(p, 0x24), 3, 0, 0, 0, 0x6d);
        }
        ov40_02230964(p, 0);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 6, PTR(p, 0x24), 7, 0, 0, 0, 0x6d);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84(w + 8, 0);
        if (ov40_0222DA00(w, w + 4, 0, 0)) {
            if (WORD(w, 0x10) == 0) {
                ov40_022306A0(w + 0x220, 1);
            } else {
                ov40_0222E7DC(w + 0x194, 1);
            }
            GfGfx_EngineBTogglePlanes(4, TRUE);
            GfGfx_EngineATogglePlanes(4, TRUE);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xc, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    default: {
        int i;
        Ov40Outer *outer = p;
        for (i = 0; i < outer->count; i++) {
            outer->ptrs[i] = &outer->entries[i];
        }
        ov40_0222BF80(p, 7);
        break;
    }
    }
    return 0;
}

int ov40_0223B190(void *p) {
    u8 *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        TouchHitboxController_Destroy(PTR(w, 0x188));
        TouchHitboxController_Destroy(PTR(w, 0x18c));
        TouchHitboxController_Destroy(PTR(w, 0x190));
        GfGfx_EngineBTogglePlanes(4, FALSE);
        GfGfx_EngineATogglePlanes(4, FALSE);
        ov40_0223A83C(p);
        ov40_02230964(p, 1);
        if (WORD(w, 0x10) == 0) {
            ov40_0223064C(w + 0x220, p);
        } else {
            ov40_0222E7B8(w + 0x194, p);
        }
        ov40_02230964(p, 0);
        extern void ov40_0223CCA0(void *);
        ov40_0223CCA0(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84(w + 8, 1);
        if (ov40_0222DA00(w, w + 4, 1, 0)) {
            ov40_0222D66C(w + 0x114, (u8 *)p + 0x14, 3);
            ov40_0222D66C(w + 0x130, (u8 *)p + 0x14, 0x6f);
            ManagedSprite_SetAnim(PTR(w, 0x118), 0);
            ManagedSprite_SetAnim(PTR(w, 0x134), 1);
            ov40_0223B4BC(p, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xc, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}
