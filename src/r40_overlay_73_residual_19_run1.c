#include "r40_overlay_73_residual_19_private.h"

void ov73_021E847C(void *p) {
    int i;
    void *walk;

    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0xD34));
    SpriteTransfer_DeletePlttTransferTask(PTR(p, 0xD38));
    i = 0;
    walk = p;
    while (i < 4) {
        Destroy2DGfxResObjMan(PTR(walk, 0xD24));
        i++;
        walk = (u8 *)walk + 4;
    }
    SpriteList_Delete(PTR(p, 0xBF8));
    PTR(p, 0xBF8) = NULL;
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}

int ov73_021E84D0(void *p) {
    void *value;

    ov73_021E8B64(p);
    BeginNormalPaletteFade(0, 1, 1, 0, 8, 1, 0x96);
    ov73_021E8628(PTR(p, 4));
    ov73_021E8730(p);
    ov73_021E8A08(p);
    GfGfx_EngineATogglePlanes(1, 1);
    GfGfx_EngineATogglePlanes(2, 1);
    GfGfx_EngineBTogglePlanes(1, 1);
    GfGfx_EngineBTogglePlanes(2, 1);
    sub_02039418(PTR(PTR(p, 0), 0xC));
    ov73_021EA12C(p);
    value = sub_0202D488(PTR(PTR(p, 0), 0), 0);
    PTR(p, 0x90) = value;
    PTR(p, 0x94) = PTR(p, 0x90);
    U32(p, 0x9C) = 1;
    U32(p, 0xF0C) = 0;
    if (ov00_021EC5B4() == 0) {
        if (PTR(PTR(p, 0), 0x24) != NULL) {
            ov73_021E9FF8(p, PTR(p, 0xBD8), 1, 1, 0xF0F);
            ov73_021E83EC(p, 0x2F, 2);
            ov73_021EA15C(p);
        } else {
            U32(p, 0x1C) = 0;
        }
    } else {
        U32(p, 0x1C) = 0x33;
    }
    return 2;
}

int ov73_021E85AC(void *p) {
    int oldState;
    int newState;
    int result;

    ov73_021E8440(p);
    sub_0203A930();
    oldState = U32(p, 0x1C);
    result = ov73_021EA848[oldState](p);
    newState = U32(p, 0x1C);
    if (oldState != newState) {
        U16(p, 0xF90) = 0;
        U16(p, 0xF92) = 0;
    }
    return result;
}

int ov73_021E85DC(void *p) {
    if (PTR(p, 0xF98) != NULL) {
        SysTask_Destroy(PTR(p, 0xF98));
        PTR(p, 0xF98) = NULL;
        PTR(p, 0xF9C) = NULL;
    }
    ov73_021E8BBC(p);
    ov73_021E8B20(p);
    ov73_021E870C(PTR(p, 4));
    PTR(p, 0xF9C) = NULL;
    PTR(p, 0x10) = PTR(p, 0x14);
    if (PTR(p, 0x10) == NULL) {
        return 5;
    }
    return 1;
}

void ov73_021E8628(void *p) {
    SolBgTemplate t0 = ov73_021EA70C;

    InitBgFromTemplate(p, 0, &t0, 0);
    GfGfx_EngineATogglePlanes(1, 0);
    BgClearTilemapBufferAndCommit(p, 0);
    {
        SolBgTemplate t1 = ov73_021EA6F0;
        InitBgFromTemplate(p, 1, &t1, 0);
        GfGfx_EngineATogglePlanes(2, 0);
        {
            SolBgTemplate t2 = ov73_021EA728;
            InitBgFromTemplate(p, 4, &t2, 0);
            GfGfx_EngineBTogglePlanes(1, 0);
            BgClearTilemapBufferAndCommit(p, 4);
            {
                SolBgTemplate t3 = ov73_021EA6D4;
                InitBgFromTemplate(p, 5, &t3, 0);
            }
        }
    }
    GfGfx_EngineBTogglePlanes(2, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x96);
    BG_ClearCharDataRange(4, 0x20, 0, 0x96);
}
