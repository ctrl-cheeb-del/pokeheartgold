#include "overlay108_safari_decor_r2_private.h"

BOOL SafariDecoration_Init(void *mgr, u32 *state) {
    switch (*state) {
    case 0: {
        void *args, *p;
        ov108_021E8AD4();
        Heap_Create(3, 0x5f, 0x48000);
        args = OverlayManager_GetArgs(mgr);
        p = OverlayManager_CreateAndGetData(mgr, 0x530, 0x5f);
        MI_CpuFill8(p, 0, 0x530);
        U32(p, 0) = 0x5f;
        ov108_021E8968(p, args);
        Sound_SetSceneAndPlayBGM(0x43, 0, 0);
        (*state)++;
        break;
    }
    case 1:
        if (ov108_021E929C(OverlayManager_GetData(mgr))) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL SafariDecoration_Exit(void *mgr) {
    void *p = OverlayManager_GetData(mgr);
    u32 heap;
    if (!ov108_021E9304(p)) {
        return FALSE;
    }
    ov108_021E8AD4();
    ov108_021E8A88(p);
    heap = U32(p, 0);
    MI_CpuFill8(p, 0, 0x530);
    OverlayManager_FreeData(mgr);
    Heap_Destroy(heap);
    return TRUE;
}

BOOL SafariDecoration_Main(void *mgr, u32 *state) {
    void *p = OverlayManager_GetData(mgr);
    switch (*state) {
    case 0:
        *state = ov108_021E8BC0(p);
        break;
    case 1:
        *state = ov108_021E8B24(p);
        break;
    case 2:
        *state = ov108_021E8B68(p);
        break;
    case 3:
        *state = ov108_021E8C18(p);
        break;
    case 4:
        return TRUE;
    }
    SpriteSystem_DrawSprites(PTR(p, 0x440));
    ov108_021E8E10((u8 *)p + 0x338);
    return FALSE;
}
