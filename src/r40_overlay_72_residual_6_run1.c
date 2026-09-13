#include "r40_overlay_72_residual_6_private.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef struct {
    u8 pad[0xD24];
    void *managers[4];
} Ov72ManagerOwner;

void ov72_022387D8(void *p) {
    ov72_02238124();
    ov72_02238164();
    ov72_02238194(p);
    ov72_02238408(p);
    Main_SetVBlankIntrCB(ov72_022380FC, p);
}

void ov72_02238800(void *p) {
    int i;
    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0xD34));
    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0xD44));
    SpriteTransfer_DeletePlttTransferTask(PTR(p, 0xD38));
    SpriteTransfer_DeletePlttTransferTask(PTR(p, 0xD48));
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(((Ov72ManagerOwner *)p)->managers[i]);
    }
    SpriteList_Delete(PTR(p, 0xBF8));
    PTR(p, 0xBF8) = NULL;
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}

int ov72_0223886C(void *p) {
    ov72_02239040(p);
    BeginNormalPaletteFade(0, 1, 1, 0, 8, 1, 0x43);
    ov72_022389C8(PTR(p, 4));
    ov72_02238BEC(p);
    ov72_02238EE4(p);
    GfGfx_EngineATogglePlanes(1, 1);
    GfGfx_EngineATogglePlanes(2, 1);
    GfGfx_EngineBTogglePlanes(1, 1);
    GfGfx_EngineBTogglePlanes(2, 1);
    PTR(p, 0x90) = sub_0202D488(PTR(PTR(p, 0), 0), 0);
    PTR(p, 0x94) = PTR(p, 0x90);
    U32(p, 0x9C) = 1;
    U32(p, 0xF4C) = 0;
    if (!ov00_021EC5B4()) {
        void *root = PTR(p, 0);
        if (U32(root, 0x24) != 0) {
            sub_02039418(PTR(root, 0xC));
            ov72_0223A350(p, PTR(p, 0xBD8), 1, 1, 0xF0F);
            ov72_02238680(p, 0x2F, 2);
            ov72_0223A420(p);
        } else {
            Sys_ClearSleepDisableFlag(4);
            U32(p, 0x1C) = 0;
        }
    } else {
        sub_02039418(PTR(PTR(p, 0), 0xC));
        U32(p, 0x1C) = 0x33;
    }
    return 2;
}

int ov72_0223894C(void *p) {
    ov72_022387C4();
    sub_0203A930();
    u32 old = U32(p, 0x1C);
    int result = ov72_0223B660[old](p);
    if (old != U32(p, 0x1C)) {
        *(u16 *)((u8 *)p + 0xFD0) = 0;
        *(u16 *)((u8 *)p + 0xFD2) = 0;
    }
    return result;
}

int ov72_0223897C(void *p) {
    if (PTR(p, 0xFD8) != NULL) {
        SysTask_Destroy(PTR(p, 0xFD8));
        PTR(p, 0xFD8) = NULL;
        PTR(p, 0xFDC) = NULL;
    }
    ov72_02239098(p);
    ov72_02238FFC(p);
    ov72_02238AEC(PTR(p, 4));
    U32(p, 0xFDC) = 0;
    PTR(p, 0x10) = PTR(p, 0x14);
    if (PTR(p, 0x10) == NULL) {
        return 5;
    }
    return 1;
}

void ov72_022389C8(void *p) {
    BgTemplate a = ov72_0223B42C;
    InitBgFromTemplate(p, 0, &a, 0);
    GfGfx_EngineATogglePlanes(1, FALSE);
    BgClearTilemapBufferAndCommit(p, 0);
    BgTemplate b = ov72_0223B410;
    InitBgFromTemplate(p, 1, &b, 0);
    GfGfx_EngineATogglePlanes(2, FALSE);
    BgTemplate c = ov72_0223B448;
    InitBgFromTemplate(p, 4, &c, 0);
    GfGfx_EngineBTogglePlanes(1, FALSE);
    BgClearTilemapBufferAndCommit(p, 4);
    BgTemplate d = ov72_0223B3D8;
    InitBgFromTemplate(p, 5, &d, 0);
    GfGfx_EngineBTogglePlanes(2, FALSE);
    BgTemplate e = ov72_0223B3F4;
    InitBgFromTemplate(p, 6, &e, 0);
    GfGfx_EngineBTogglePlanes(4, TRUE);
    BgClearTilemapBufferAndCommit(p, 6);
    BG_ClearCharDataRange(0, 0x20, 0, (enum HeapID)0x43);
    BG_ClearCharDataRange(4, 0x20, 0, (enum HeapID)0x43);
    BG_ClearCharDataRange(6, 0x20, 0, (enum HeapID)0x43);
}
