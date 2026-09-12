#include "overlay40_ui_lifecycle_private.h"

void ov40_0222BC44(int screen) {
    gSystem.screensFlipped = screen;
    GfGfx_SwapDisplay();
}

void ov40_0222BC54(BattleAppWorkRaw *work) {
    InitBgFromTemplate(OV40_PTR(work, 0x24), 2, ov40_02244D00, 0);
}

void ov40_0222BC68(BattleAppWorkRaw *work) {
    Ov40SpriteSystemTemplate system;
    Ov40SpriteResourceCapacities capacities;
    Ov40SpriteManagerTemplate manager;
    OV40_PTR(work, 0x18) = SpriteSystem_Alloc(0x6d);
    system = ov40_02244C80;
    capacities = ov40_02244C54;
    SpriteSystem_Init(OV40_PTR(work, 0x18), &system, &capacities, 0x20);
    manager = ov40_02244C68;
    OV40_PTR(work, 0x1c) = SpriteManager_New(OV40_PTR(work, 0x18));
    if (!SpriteSystem_InitSprites(OV40_PTR(work, 0x18), OV40_PTR(work, 0x1c), 0xc0)) {
        GF_AssertFail();
    }
    if (!SpriteSystem_InitManagerWithCapacities(OV40_PTR(work, 0x18), OV40_PTR(work, 0x1c), &manager)) {
        GF_AssertFail();
    }
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(OV40_PTR(work, 0x18)), 0, 1 << 20);
}
