#include "overlay57_lifecycle_private.h"

int ov57_022378DC(OverlayManager *manager, int *state) {
    void *work;
    int i;
    int count;
    int rem;

    Heap_Create(HEAP_ID_3, HEAP_ID_52, 0x80000);
    work = OverlayManager_CreateAndGetData(manager, 0x460, HEAP_ID_52);
    memset(work, 0, 0x460);
    PTR_AT(work, 0) = OverlayManager_GetArgs(manager);
    PTR_AT(work, 0x45C) = NARC_New(0xB4, 0x34);
    U32_AT(work, 0x40C) = MenuInputStateMgr_GetState(PTR_AT(PTR_AT(work, 0), 0x2C));
    PTR_AT(work, 0x458) = AllocMonZeroed(0x34);
    U32_AT(work, 0xD4) = 0xFF;
    rem = 0;
    U32_AT(work, 0x448) = rem;

    count = SealCase_CountUniqueSeals(PTR_AT(PTR_AT(work, 0), 0x20));
    if (count % 8 != 0) {
        rem = 1;
    }
    count = SealCase_CountUniqueSeals(PTR_AT(PTR_AT(work, 0), 0x20));
    U32_AT(work, 0x44C) = rem + count / 8;
    if (S32_AT(work, 0x44C) > 10) {
        U32_AT(work, 0x44C) = 10;
    }

    U32_AT(work, 0x3EC) = ov57_02237E78(PTR_AT(work, 0));
    U32_AT(work, 0x3F0) = ov57_02237E78(PTR_AT(work, 0));
    PTR_AT(work, 0x64) = SealCase_inventory_Get(PTR_AT(PTR_AT(work, 0), 0x20));

    {
        u8 *slot;
        i = 0;
        slot = work;
        for (; i < 12; i++, slot += 8) {
            void *capsule = SealCase_GetCapsuleI(PTR_AT(PTR_AT(work, 0), 0x20), i);
            U32_AT(slot, 4) = 0xFF;
            PTR_AT(slot, 8) = capsule;
        }
    }

    {
        int offset;
        i = 0;
        offset = i;
        for (; i < 6; i++, offset += 4) {
            void *mon = PTR_AT((u8 *)PTR_AT(work, 0) + offset, 4);
            if (mon != NULL) {
                u32 capsule = GetMonData(mon, 0xA2, NULL);
                if (capsule != 0) {
                    U32_AT(work, capsule * 8 - 4) = i;
                }
            }
        }
    }

    ov57_02237CA8(0x34);
    ov57_0223BB5C();
    PTR_AT(work, 0x258) = ov57_02238B28();
    PTR_AT(work, 0xE4) = BgConfig_Alloc(0x34);
    GF_CreateVramTransferManager(0x40, 0x34);
    PTR_AT(work, 0xE8) = PaletteData_Init(0x34);
    PaletteData_SetAutoTransparent(PTR_AT(work, 0xE8), 1);
    PaletteData_AllocBuffers(PTR_AT(work, 0xE8), 0, 0x200, 0x34);
    PaletteData_AllocBuffers(PTR_AT(work, 0xE8), 1, 0x200, 0x34);
    PaletteData_AllocBuffers(PTR_AT(work, 0xE8), 2, 0x200, 0x34);
    PaletteData_AllocBuffers(PTR_AT(work, 0xE8), 3, 0x200, 0x34);
    ov57_02237CEC(PTR_AT(work, 0xE4));
    ov57_02238BCC();
    PTR_AT(work, 0x1C4) = PokepicManager_Create(0x34);
    PTR_AT(work, 0x284) = sub_02016EDC(0x34, 1, 0);
    i = Options_GetFrame(PTR_AT(PTR_AT(work, 0), 0x24));
    ov57_022395B8(PTR_AT(work, 0xE4), PTR_AT(work, 0xE8), i);
    ov57_02239670(PTR_AT(work, 0xE4), PTR_AT(work, 0xE8), i);
    ov57_02239058((u8 *)work + 0xD4);
    sub_020210BC();
    sub_02021148(4);
    ov57_0223BB84(work);
    Main_SetVBlankIntrCB(ov57_02237E38, work);
    ov57_022386F0(work);
    return 1;
}

int ov57_02237AF8(OverlayManager *manager, int *state) {
    void *work = OverlayManager_GetData(manager);

    if (ov57_0223A0E0(work) == NULL) {
        return 1;
    }
    PokepicManager_DrawAll(PTR_AT(work, 0x1C4));
    ov57_02238C0C();
    return 0;
}

int ov57_02237B20(OverlayManager *manager, int *state) {
    void *work;

    work = OverlayManager_GetData(manager);
    GfGfx_EngineATogglePlanes(1, FALSE);
    GfGfx_EngineATogglePlanes(2, FALSE);
    GfGfx_EngineATogglePlanes(4, FALSE);
    GfGfx_EngineATogglePlanes(8, FALSE);
    GfGfx_EngineBTogglePlanes(1, FALSE);
    GfGfx_EngineBTogglePlanes(2, FALSE);
    GfGfx_EngineBTogglePlanes(4, FALSE);
    GfGfx_EngineBTogglePlanes(8, FALSE);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 1);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 2);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 3);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 4);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 5);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 6);
    FreeBgTilemapBuffer(PTR_AT(work, 0xE4), 7);
    Heap_Free(PTR_AT(work, 0xE4));
    PaletteData_FreeBuffers(PTR_AT(work, 0xE8), 0);
    PaletteData_FreeBuffers(PTR_AT(work, 0xE8), 1);
    PaletteData_FreeBuffers(PTR_AT(work, 0xE8), 2);
    PaletteData_FreeBuffers(PTR_AT(work, 0xE8), 3);
    PaletteData_Free(PTR_AT(work, 0xE8));
    ov57_02237E80(PTR_AT(work, 0), (u8)U32_AT(work, 0x3EC));
    Heap_Free(PTR_AT(work, 0x458));
    ov57_022383AC(work);
    TouchHitboxController_Destroy(PTR_AT(work, 0x1EC));
    PokepicManager_Delete(PTR_AT(work, 0x1C4));
    sub_02016F2C(PTR_AT(work, 0x284));
    ov57_02238714(work);
    ov57_022390F4((u8 *)work + 0xD4);
    GF_DestroyVramTransferManager();
    GF_3DVramMan_Delete(PTR_AT(work, 0x258));
    ov57_02237CDC(0x34);
    NARC_Delete(PTR_AT(work, 0x45C));
    MenuInputStateMgr_SetState(PTR_AT(PTR_AT(work, 0), 0x2C), U32_AT(work, 0x40C));
    OverlayManager_FreeData(manager);
    sub_02021238();
    Heap_Destroy(HEAP_ID_52);
    UnloadOverlayByID((int)SDK_OVERLAY_OVY_6_ID);
    UnloadOverlayByID((int)SDK_OVERLAY_OVY_7_ID);
    return 1;
}

void ov57_02237CA8(int unused) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(u32 *)0x04000000 &= 0xFFFFE0FF;
    *(u32 *)0x04001000 &= 0xFFFFE0FF;
}
