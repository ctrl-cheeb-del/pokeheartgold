#include "to45_overlay41_graphics_setup_private.h"

void ov41_022466D0(void) {
    GraphicsBanks banks = ov41_0224C06C;
    GfGfx_SetBanks(&banks);
}

void ov41_022466F0(void) {
    NNS_G3dInit();
    G3X_InitMtxStack();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, FALSE);
    G3_SwapBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_W);
    G3_ViewPort(0, 0, 255, 191);
    GF_3DVramMan_InitFrameTexVramManager(2, TRUE);
    GF_3DVramMan_InitFramePlttVramManager(0x4000, TRUE);
}

void ov41_02246778(void) {
    GraphicsModes modes = _0224BF94;
    SetBothScreensModesAndDisable(&modes);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffeF) | GX_PLANEMASK_OBJ;
    NNS_G2dInitOamManagerModule();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_ALL, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_OBJ, TRUE);
}
