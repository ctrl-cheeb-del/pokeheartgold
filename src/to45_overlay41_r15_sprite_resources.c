#include "to45_overlay41_r15_sprite_resources_private.h"

void ov41_02246A94(void *p) {
    Ov41ObjTransferTemplate template = ov41_0224BFA4;

    ObjCharTransfer_InitEx(&template, 0x10, 0x10);
    ObjPlttTransfer_Init(5, 0xE);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7C, 0, 0x1F, 0, 0x7C, 0, 0x1F, 0xE);
    PTR(p, 0x44) = G2dRenderer_Init(0x30, (u8 *)p + 0x58, 0xE);
    G2dRenderer_SetSubSurfaceCoords((u8 *)p + 0x58, 0, 2 << 20);
    PTR(p, 0x48) = Create2DGfxResObjMan(8, 0, 0xE);
    PTR(p, 0x4C) = Create2DGfxResObjMan(5, 1, 0xE);
    PTR(p, 0x50) = Create2DGfxResObjMan(0x30, 2, 0xE);
    PTR(p, 0x54) = Create2DGfxResObjMan(0x30, 3, 0xE);
}

void ov41_02246B34(void *p) {
    int i;
    void *walk;

    SpriteList_Delete(PTR(p, 0x44));
    i = 0;
    walk = p;
    while (i < 4) {
        Destroy2DGfxResObjMan(PTR(walk, 0x48));
        i++;
        walk = (u8 *)walk + 4;
    }
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
}
