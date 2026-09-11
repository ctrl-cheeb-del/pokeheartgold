#include "ov72_wave41_private.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

BOOL NintendoWfc_Main(void *mgr, int *state) {
    u8 *w = OverlayManager_GetData(mgr);
    int idx;
    ov00_021ECB40();
    ov72_022378DC();
    ov00_021ECB40();
    switch (*state) {
    case 0:
        if (sub_02034DB8()) {
            ov72_0223B92C[0] = U32(w, 0x28);
            ov00_021EC294(ov72_02238778, ov72_022387A0);
            *state = 1;
        }
        break;
    case 1:
        idx = U32(w, 0x10) * 12;
        *state = (*(int (**)(u8 *, int))(ov72_0223B654 + idx))(w, *state);
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            *state = 3;
        }
        break;
    case 3:
        idx = U32(w, 0x10) * 12;
        *state = (*(int (**)(u8 *, int))(ov72_0223B658 + idx))(w, *state);
        break;
    case 4:
        if (IsPaletteFadeFinished()) {
            idx = U32(w, 0x10) * 12;
            *state = (*(int (**)(u8 *, int))(ov72_0223B65C + idx))(w, *state);
        }
        break;
    case 5:
        return TRUE;
    }
    if (U32(w, 0xbf8) != 0) {
        SpriteList_RenderAndAnimateSprites((void *)U32(w, 0xbf8));
    }
    return FALSE;
}

BOOL NintendoWfc_Exit(void *mgr) {
    u8 *w = OverlayManager_GetData(mgr);
    if (!IsPaletteFadeFinished()) {
        return FALSE;
    }
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    FontID_Release(4);
    Heap_Free((void *)U32(w, 0x24));
    UnloadOVY38();
    UnloadDwcOverlay();
    ov72_02238800(w);
    DestroyMsgData((void *)U32(w, 0xbdc));
    DestroyMsgData((void *)U32(w, 0xbd8));
    DestroyMsgData((void *)U32(w, 0xbd4));
    MessageFormat_Delete((void *)U32(w, 0xbd0));
    ov72_02238160(w);
    sub_02034DE0();
    Heap_Free((void *)U32(w, 4));
    OverlayManager_FreeData(mgr);
    Main_SetVBlankIntrCB(0, 0);
    Heap_Destroy(0x43);
    return TRUE;
}
