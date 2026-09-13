#include "r40_overlay_73_residual_3_private.h"

void ov73_021E6060(void) {
    SolObjTransferTemplate t = ov73_021EA550;
    ObjCharTransfer_Init(&t);
    ObjPlttTransfer_Init(0x14, 0x32);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov73_021E6090(void *p, void *narc) {
    int i;
    void *walk;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x20, 0, 0x7E, 0, 0x20, 0x32);
    PTR(p, 0x50) = G2dRenderer_Init(0x1E, (u8 *)p + 0x54, 0x32);
    G2dRenderer_SetSubSurfaceCoords((u8 *)p + 0x54, 0, 1 << 20);
    i = 0;
    walk = p;
    while (i < 4) {
        PTR(walk, 0x17C) = Create2DGfxResObjMan(3, i, 0x32);
        i++;
        walk = (u8 *)walk + 4;
    }
    PTR(p, 0x1AC) = AddCharResObjFromOpenNarc(PTR(p, 0x17C), narc, 8, 1, 2, 1, 0x32);
    PTR(p, 0x1B0) = AddPlttResObjFromOpenNarc(PTR(p, 0x180), narc, 7, 0, 2, 1, 0xF, 0x32);
    PTR(p, 0x1B4) = AddCellOrAnimResObjFromOpenNarc(PTR(p, 0x184), narc, 9, 1, 2, 2, 0x32);
    PTR(p, 0x1B8) = AddCellOrAnimResObjFromOpenNarc(PTR(p, 0x188), narc, 10, 1, 2, 3, 0x32);
    SpriteTransfer_CreateCharTransferTask(PTR(p, 0x1AC));
    SpriteTransfer_CreateExtPlttTransferTask(PTR(p, 0x1B0));
}
