#include "r42_overlay40_pc_box_mode_transition_private.h"

int ov40_0223512C(void *work) {
    void *inner = PTR(work, 0x860);

    switch (S32(work, 8)) {
    case 0:
        S32(inner, 0xC) = 0;
        {
            void *resource = PTR(inner, 0x23C + S32(inner, 0x234) * 4);
            ov39_02227080((u8 *)resource + 0x80, PTR(inner, 0x238));
            PTR(inner, 0x228) = ov41_0224B530((u8 *)inner + 0x218, PTR(inner, 0x238));
        }
        ov41_0224B5D0(PTR(inner, 0x228), 0);
        ov40_02235940();
        ov40_022307DC(work, 0x23, 3);
        ov40_022307DC(work, 0x24, 7);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(4, 1);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(1, 0);
        Main_SetVBlankIntrCB(ov40_02235900, work);
        S32(work, 8)
        ++;
        break;
    case 1:
        PaletteData_LoadPaletteSlotFromHardware(PTR(work, 0x28), 0, 0, 0x200);
        S32(work, 8)
        ++;
        break;
    case 2:
        ov40_0222DA84((u8 *)inner + 8, 0);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 0, 0)) {
            ov41_0224B5D0(PTR(inner, 0x228), 1);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineATogglePlanes(1, 1);
            ov40_02235C7C(work, S32(inner, 0x234));
            ov40_022358C0(work);
            S32(work, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(work, 0x28), 3, 12, (u8)WORD(inner, 8), (u16)WORD(work, 0x58));
        break;
    default:
        ov40_0222BF80(work, 8);
        break;
    }
    if (PTR(inner, 0x228) != NULL) {
        Thunk_G3X_Reset();
        ov41_0224B554(PTR(inner, 0x228));
        RequestSwap3DBuffers(0, 0);
    }
    return 0;
}

int ov40_0223527C(void *work) {
    void *inner = PTR(work, 0x860);

    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451C4)) {
        ov40_02230944(work);
        ov40_0222BF80(work, 9);
    }
    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451D0)) {
        ov40_02230944(work);
        ov40_0222BF80(work, 10);
    }
    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451D4)) {
        if (S32(inner, 0x234) != 0) {
            S32(inner, 0x234)
            --;
        } else {
            S32(inner, 0x234) = S32(inner, 0x2E4) - 1;
        }
        ov40_02230944(work);
        ov40_0222BF80(work, 11);
    }
    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451D8)) {
        S32(inner, 0x234)
        ++;
        S32(inner, 0x234) %= S32(inner, 0x2E4);
        ov40_02230944(work);
        ov40_0222BF80(work, 11);
    }
    if (PTR(inner, 0x228) != NULL) {
        Thunk_G3X_Reset();
        ov41_0224B554(PTR(inner, 0x228));
        RequestSwap3DBuffers(0, 0);
    }
    return 0;
}

int ov40_0223534C(void *work) {
    void *inner = PTR(work, 0x860);

    switch (S32(work, 8)) {
    case 0:
        if (S32(inner, 0xC) == 0) {
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 2);
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 6);
            ov40_02236130(work);
        } else {
            ov40_02230964(work, 1);
            ov40_0222E7B8((u8 *)inner + 0x250, work);
            ov40_02230964(work, 0);
        }
        ov40_0223584C(work);
        S32(work, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)inner + 8, 1);
        if (ov40_0222DA00(inner, (u8 *)inner + 4, 1, 0)) {
            if (PTR(inner, 0x228) != NULL) {
                ov41_0224B57C();
                ov40_0222BC54(work);
                SetBgPriority(2, 0);
                PTR(inner, 0x228) = NULL;
                ov40_02235994();
            }
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 3);
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 7);
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 2);
            BgClearTilemapBufferAndCommit(PTR(work, 0x24), 6);
            S32(work, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(work, 0x28), 3, 12, (u8)WORD(inner, 8), (u16)WORD(work, 0x58));
        break;
    default:
        ov40_0222BF80(work, 3);
        break;
    }
    return 0;
}
