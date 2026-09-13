#include "r40_overlay_106_residual_2_private.h"

void ov106_021E5D70(void *arg) {
    u8 *work = arg;
    u8 *config;
    u32 reg;
    *(void **)(work + 0x18) = Camera_New((enum HeapID)0x99);
    GF3dRender_InitSimpleManager((enum HeapID)0x99);
    reg = *(volatile u16 *)0x04000060;
    reg &= 0xFFFFCFFF;
    reg |= 0x10;
    *(volatile u16 *)0x04000060 = reg;
    G3X_SetFog(0, (GXFogBlend)0, (GXFogSlope)0, 0);
    G3X_SetClearColor(0x1F, 0, 0x7FFF, 0x3F, 0);
    config = *(u8 **)work;
    NNS_G3dGlbMaterialColorDiffAmb(*(u16 *)(config + 0x24), *(u16 *)(config + 0x26), *(u32 *)(config + 0x2C));
    config = *(u8 **)work;
    NNS_G3dGlbMaterialColorSpecEmi(*(u16 *)(config + 0x28), *(u16 *)(config + 0x2A), *(u32 *)(config + 0x30));
    config = *(u8 **)work;
    NNS_G3dGlbPolygonAttr(*(u32 *)(config + 0x34), (GXPolygonMode) * (u32 *)(config + 0x38), (GXCull) * (u32 *)(config + 0x3C), *(u32 *)(config + 0x40), *(u32 *)(config + 0x44), *(u32 *)(config + 0x48));
    SetBgPriority(0, 0);
    GfGfx_EngineATogglePlanes(1, 1);
}
