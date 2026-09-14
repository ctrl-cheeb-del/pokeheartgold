#include "to45_overlay40_r27_u14_private.h"

int ov40_02233F28(void *p) {
    u32 *inner = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        if (*inner == 0) {
            PlaySE(0x57A);
        }
        if (*inner != 0x10) {
            *inner += 2;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0x1C, (u8)*inner, (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0x4018, (u8)*inner, (u16)WORD(p, 0x58));
        if (!ov40_02233AEC(p)) {
            *inner = 0;
            WORD(p, 8)
            ++;
        }
        break;
    case 1:
        WORD(p, 8)
        ++;
    case 2:
        ov40_02230964(p, 1);
        ov40_022338D0(p);
        ov40_0223320C(p);
        ov40_02230964(p, 0);
        GfGfx_EngineATogglePlanes(8, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(8, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        *inner = 0;
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222BC44(1);
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
    case 4:
        if (*inner != 0) {
            *inner -= 2;
            break;
        }
        WORD(p, 8)
        ++;
        ov40_0222DAA8(inner);
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)*inner, (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0x1C, (u8)*inner, (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)*inner, (u16)WORD(p, 0x58));
        break;
    default:
        if (ov40_0222DA84(inner, 0)) {
            G2x_SetBlendAlpha_(0x04000050, 4, 0x12, 7, 8);
            G2x_SetBlendAlpha_(0x04001050, 4, 0x12, 7, 8);
            Heap_Free(inner);
            ov40_0222DD08(p);
            ov40_0222DAA8(inner);
            PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)WORD(p, 0x58));
            ov40_0222BF64(p, 1, 1, WORD(p, 0x10));
            ov40_0222BF80(p, 5);
        } else {
            PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)*inner, (u16)WORD(p, 0x58));
            PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)*inner, (u16)WORD(p, 0x58));
        }
        break;
    }
    return 0;
}

int ov40_0223414C(void *p) {
    void *inner = Heap_Alloc(0x6D, 0x2E8);
    memset(inner, 0, 0x2E8);
    PTR(p, 0x860) = inner;
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_41), 2);
    PTR(inner, 0x218) = PTR(p, 0x24);
    WORD(inner, 0x21C) = 0x48;
    WORD(inner, 0x220) = 0x10;
    WORD(inner, 0x224) = 0x6D;
    PTR(inner, 0x238) = sub_0202B998(0x6D);
    PTR(inner, 0x250) = sub_020314A4(0x6D);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    ov40_0222D9E8(inner, (u8 *)inner + 4, 0);
    ov40_0222BF80(p, 1);
    return 0;
}

int ov40_022341E0(void *p) {
    void *inner = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)inner + 8, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    case 1:
        SetBgPriority(0, 0);
        SetBgPriority(2, 0);
        SetBgPriority(1, 3);
        SetBgPriority(3, 2);
        SetBgPriority(4, 0);
        SetBgPriority(6, 1);
        SetBgPriority(5, 3);
        SetBgPriority(7, 2);
        sub_020879E0(PTR(p, 0x6F0), 0);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_0222FB90(p, 0);
        ov40_02230964(p, 1);
        WORD(p, 8)
        ++;
        break;
    default:
        if (ov40_0222FBB4(p)) {
            ov40_02230964(p, 0);
            ov40_02230964(p, 1);
            ov40_0222D874(p);
            ov40_02235A30(p);
            ov40_02230964(p, 0);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
            ov40_0222BF80(p, 2);
        }
        break;
    }
    return 0;
}

int ov40_02234330(void *p) {
    void *inner = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        ov40_02235940(p);
        ov40_022307DC(p, 0x23, 3);
        ov40_022307DC(p, 0x25, 7);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(8, 1);
        ov40_02230964(p, 1);
        PTR(inner, 0x22C) = sub_0202B9B8(Save_FashionData_Get(PTR(p, 0x830)), 0);
        if (PTR(inner, 0x228) == NULL) {
            PTR(inner, 0x228) = ov41_0224B530((u8 *)inner + 0x218, PTR(inner, 0x22C));
            ov41_0224B5D0(PTR(inner, 0x228), 1);
        }
        ov40_02230964(p, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(1, 0);
        Main_SetVBlankIntrCB(ov40_02235900, p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        PaletteData_LoadPaletteSlotFromHardware(PTR(p, 0x28), 0, 0, 0x200);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineATogglePlanes(1, 1);
            ov40_02235B4C(p);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(inner, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    if (PTR(inner, 0x228) != NULL) {
        Thunk_G3X_Reset();
        ov41_0224B554(PTR(inner, 0x228));
        RequestSwap3DBuffers(0, 0);
    }
    return 0;
}
