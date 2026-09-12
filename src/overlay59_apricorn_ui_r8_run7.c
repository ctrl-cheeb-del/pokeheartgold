#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

BOOL ov59_0223A8E0(OverlayManager *manager, int *state) {
    Ov59R8Work *work;
    switch (*state) {
    case 0:
        ov59_0223ACD0();
        Heap_Create((enum HeapID)3, (enum HeapID)0x86, 9 << 16);
        work = OverlayManager_CreateAndGetData(manager, 0x2F4, (enum HeapID)0x86);
        MI_CpuFill8(work, 0, 0x2F4);
        U32(work, 0) = 0x86;
        PTR(work, 4) = OverlayManager_GetArgs(manager);
        ov59_0223A9E4(work);
        (*state)++;
        break;
    case 1:
        work = OverlayManager_GetData(manager);
        if (ov59_0223AABC(work)) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov59_0223A948(OverlayManager *manager, int *state) {
    Ov59R8Work *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        *state = ov59_0223AB3C(work);
        break;
    case 1:
        *state = ov59_0223AB90(work);
        break;
    case 2:
        *state = ov59_0223ABE4(work);
        break;
    case 4:
        *state = ov59_0223ABEC(work);
        break;
    case 5:
        *state = ov59_0223AC48(work);
        break;
    case 8:
        return TRUE;
    }
    SpriteSystem_DrawSprites(PTR(work, 0x25C));
    ov59_0223C304(PTR(work, 0x78));
    return FALSE;
}

BOOL ov59_0223A9B8(OverlayManager *manager, int *state) {
    Ov59R8Work *work = OverlayManager_GetData(manager);
    if (!ov59_0223AB00(work)) {
        return FALSE;
    }
    ov59_0223AA6C(work);
    OverlayManager_FreeData(manager);
    Heap_Destroy((enum HeapID)0x86);
    return TRUE;
}
