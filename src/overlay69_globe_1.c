#include "overlay69_globe_internal.h"

BOOL GeonetGlobe_Init(OverlayManager *man, int *state) {
    u8 *work;
    void *args;
    void *options;
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(vu32 *)0x04000000 &= 0xFFFFE0FF;
    *(vu32 *)0x04001000 &= 0xFFFFE0FF;
    Heap_Create(HEAP_ID_3, HEAP_ID_49, 0x00080000);
    work = OverlayManager_CreateAndGetData(man, 0xC33C, HEAP_ID_49);
    memset(work, 0, 0xC33C);
    *(u32 *)work = 0x31;
    *(u32 *)(work + 0xC300) = gGameLanguage == 1;
    args = OverlayManager_GetArgs(man);
    *(void **)(work + 4) = Save_WiFiHistory_Get(args);
    *(u32 *)(work + 0xC324) = WifiHistory_GetPlayerCountry(*(void **)(work + 4));
    *(u32 *)(work + 0xC328) = WiFiHistory_GetPlayerRegion(*(void **)(work + 4));
    *(u32 *)(work + 0xC334) = WiFiHistory_GetNonJapaneseFlag(*(void **)(work + 4));
    options = Save_PlayerData_GetOptionsAddr(args);
    *(void **)(work + 8) = options;
    ov69_021E60F8(options);
    ov69_021E6118();
    GF3dRender_InitSimpleManager((u8) * (u32 *)work);
    *(void **)(work + 0xC010) = BgConfig_Alloc(*(u32 *)work);
    GfGfx_BothDispOn();
    ResetAllTextPrinters();
    *(void **)(work + 0xC080) = MessageFormat_New_Custom(8, 0x40, *(u32 *)work);
    *(void **)(work + 0xC2DC) = Camera_New(*(u32 *)work);
    *(u32 *)(work + 0xC2F8) = 0;
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    SetKeyRepeatTimers(4, 8);
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    ov69_021E6138(work);
    return TRUE;
}
