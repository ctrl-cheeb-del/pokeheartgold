#include "overlay95_hatch_lifecycle_r9_private.h"
BOOL HatchEggApp_Init(void *manager, int *state) {
    void *work;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    Heap_Create(3, 0x46, 0x40000);
    work = OverlayManager_CreateAndGetData(manager, 0x8C, 0x46);
    memset(work, 0, 0x8C);
    PTR_AT(work, 0) = OverlayManager_GetArgs(manager);
    U32_AT(work, 0x10) = Options_GetTextFrameDelay(PTR_AT(PTR_AT(work, 0), 0x10));
    U32_AT(work, 0x14) = Options_GetFrame(PTR_AT(PTR_AT(work, 0), 0x10));
    PTR_AT(work, 0x38) = ov95_021E5954();
    PTR_AT(work, 0x3C) = PokepicManager_Create(0x46);
    PTR_AT(work, 0x40) = NARC_New(0xB4, 0x46);
    PTR_AT(work, 4) = BgConfig_Alloc(0x46);
    GF_CreateVramTransferManager(0x40, 0x46);
    PTR_AT(work, 0x58) = sub_02016EDC(0x46, 1, 0);
    PaletteData_SetAutoTransparent(PTR_AT(work, 8) = PaletteData_Init(0x46), 1);
    PaletteData_AllocBuffers(PTR_AT(work, 8), 0, 0x200, 0x46);
    PaletteData_AllocBuffers(PTR_AT(work, 8), 2, 0x200, 0x46);
    PaletteData_AllocBuffers(PTR_AT(work, 8), 1, 0x200, 0x46);
    PaletteData_LoadNarc(PTR_AT(work, 8), 0x10, 9, 0x46, 1, 0x20, 0xF0);
    ov95_021E5900();
    ov95_021E5928();
    ov95_021E59F8();
    ov95_021E5A38(PTR_AT(work, 4));
    ov95_021E6FC4(PTR_AT(work, 4));
    ov95_021E619C((u8 *)work + 4);
    TextFlags_SetCanTouchSpeedUpPrint(1);
    PTR_AT(work, 0x88) = ov95_021E7020(PTR_AT(work, 4), PTR_AT(work, 0x54), PTR_AT(work, 0x50), 0x46);
    Sound_Stop();
    Main_SetVBlankIntrCB(ov95_021E5B24, work);
    return TRUE;
}

BOOL HatchEggApp_Main(void *manager, int *state) {
    void *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0: {
        u32 species;
        if (IsPaletteFadeFinished() == 1) {
            (*state)++;
        }
        species = GetMonData(PTR_AT(PTR_AT(work, 0), 0xC), 5, NULL);
        sub_020729A4(PTR_AT(work, 0x40), (u8 *)work + 0x6C, (u16)species, 1);
        if (species == 0x1EA) {
            U32_AT(work, 0x5C) = 1;
        } else {
            U32_AT(work, 0x5C) = 0;
        }
        break;
    }
    case 1:
        if (ov95_021E6300(work) == 0) {
            (*state)++;
        } else {
            PokepicManager_DrawAll(PTR_AT(work, 0x3C));
            ov95_021E5B58();
        }
        break;
    default:
        if (IsPaletteFadeFinished() == 1) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL HatchEggApp_Exit(void *manager, int *state) {
    void *work = OverlayManager_GetData(manager);
    ov95_021E7078(PTR_AT(work, 0x88));
    GF_3DVramMan_Delete(PTR_AT(work, 0x38));
    GfGfx_EngineATogglePlanes(1, 0);
    GfGfx_EngineATogglePlanes(2, 0);
    GfGfx_EngineATogglePlanes(3, 0);
    GfGfx_EngineBTogglePlanes(4, 0);
    PaletteData_FreeBuffers(PTR_AT(work, 8), 0);
    PaletteData_FreeBuffers(PTR_AT(work, 8), 2);
    PaletteData_FreeBuffers(PTR_AT(work, 8), 1);
    PaletteData_Free(PTR_AT(work, 8));
    TextFlags_SetCanTouchSpeedUpPrint(0);
    FreeBgTilemapBuffer(PTR_AT(work, 4), 1);
    FreeBgTilemapBuffer(PTR_AT(work, 4), 2);
    FreeBgTilemapBuffer(PTR_AT(work, 4), 3);
    Heap_Free(PTR_AT(work, 4));
    GF_DestroyVramTransferManager();
    PokepicManager_Delete(PTR_AT(work, 0x3C));
    sub_02016F2C(PTR_AT(work, 0x58));
    NARC_Delete(PTR_AT(work, 0x40));
    ov95_021E6228((u8 *)work + 4);
    OverlayManager_FreeData(manager);
    Heap_Destroy(0x46);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    Field_SetEnvironmentSoundState_None_Unk2();
    return TRUE;
}
