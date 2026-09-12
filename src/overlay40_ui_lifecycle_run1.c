#include "overlay40_ui_lifecycle_private.h"

void ov40_0222B934(BattleAppWorkRaw *work) {
    int i;
    GfGfx_EngineATogglePlanes(1, 0);
    GfGfx_EngineATogglePlanes(2, 0);
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineATogglePlanes(8, 0);
    GfGfx_EngineBTogglePlanes(1, 0);
    GfGfx_EngineBTogglePlanes(2, 0);
    GfGfx_EngineBTogglePlanes(4, 0);
    GfGfx_EngineBTogglePlanes(8, 0);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 0);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 1);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 2);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 3);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 4);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 5);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 6);
    FreeBgTilemapBuffer(OV40_PTR(work, 0x24), 7);
    Heap_Free(OV40_PTR(work, 0x24));
    PaletteData_FreeBuffers(OV40_PTR(work, 0x28), 0);
    PaletteData_FreeBuffers(OV40_PTR(work, 0x28), 1);
    PaletteData_FreeBuffers(OV40_PTR(work, 0x28), 2);
    PaletteData_FreeBuffers(OV40_PTR(work, 0x28), 3);
    PaletteData_Free(OV40_PTR(work, 0x28));
    if (*(u32 *)work->raw == 0) {
        sub_0202AC1C(Save_Misc_Get(OV40_PTR(work, 0x830)), OV40_U8(work, 0x5c));
    }
    NARC_Delete(OV40_PTR(work, 0x14));
    SysTask_Destroy(OV40_PTR(work, 0x416c));
    SpriteSystem_FreeResourcesAndManager(OV40_PTR(work, 0x18), OV40_PTR(work, 0x1c));
    SpriteSystem_Free(OV40_PTR(work, 0x18));
    sub_0203A914();
    sub_02021238();
    TouchHitboxController_Destroy(OV40_PTR(work, 0x2c));
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    {
        BattleAppWorkRaw *walker;
        i = 0;
        walker = work;
        do {
            if (OV40_PTR(walker, 0x87c)) {
                Heap_Free(OV40_PTR(walker, 0x87c));
            }
            if (OV40_PTR(walker, 0x88c)) {
                Heap_Free(OV40_PTR(walker, 0x88c));
            }
            i++;
            walker = (BattleAppWorkRaw *)((u8 *)walker + 4);
        } while (i < 4);
    }
    sub_020135AC(OV40_PTR(work, 0x50));
    DestroyMsgData(OV40_PTR(work, 0x48));
    DestroyMsgData(OV40_PTR(work, 0x4c));
    GF_3DVramMan_Delete(OV40_PTR(work, 0x60));
    PokepicManager_Delete(OV40_PTR(work, 0x64));
    ov40_0223D600(work);
    Main_SetVBlankIntrCB(NULL, NULL);
    GF_DestroyVramTransferManager();
}
