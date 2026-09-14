#include "overlay105_scene_lifecycle_r46_private.h"

BOOL ov105_021E5B14(OverlayManager *man) {
    Ov105App *app;
    Ov105ModelSet *ms;
    u8 i;

    app = OverlayManager_GetData(man);
    ms = &app->models[0];
    for (i = 0; i < 4; i++) {
        NNS_G3dFreeAnmObj(&app->allocator, ms->anmObj[i]);
        Heap_Free(ms->anmData[i]);
    }
    Heap_Free(ms->fileHeader);
    Camera_Delete(app->camera);
    OverlayManager_FreeData(man);
    GF3dRender_DeleteSimpleManager();
    Heap_Destroy((enum HeapID)0x97);
    return TRUE;
}

void ov105_021E5B68(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(vu32 *)0x04000000 &= 0xFFFFE0FF;
    *(vu32 *)0x04001000 &= 0xFFFFE0FF;
    ov105_021E5C84();
    GF3dRender_InitSimpleManager((enum HeapID)0x97);
    *(vu16 *)0x04000060 = (*(vu16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    G3X_SetEdgeColorTable(ov105_021E5DE0);
    GfGfx_SwapDisplay();
}

void ov105_021E5BCC(Ov105App *app) {
    u8 scene;
    u8 mode;
    VecFx32 target = { 0, 0, 0 };

    app->target = target;
    scene = app->unk9F;
    mode = app->unk9C;
    Camera_Init_FromTargetDistanceAndAngle(&app->target, ov105_021E5E2C[mode][scene].distance, &ov105_021E5E2C[mode][scene].angle, ov105_021E5E2C[mode][scene].perspective, ov105_021E5E2C[mode][scene].perspectiveType, TRUE, app->camera);
    Camera_OffsetLookAtPosAndTarget(&ov105_021E5DF0[app->unk9C][scene], app->camera);
    Camera_SetPerspectiveClippingPlane(ov105_021E5DCC[app->unk9C][scene][0] * FX32_ONE, ov105_021E5DCC[app->unk9C][scene][1] * FX32_ONE, app->camera);
    Camera_SetStaticPtr(app->camera);
}
