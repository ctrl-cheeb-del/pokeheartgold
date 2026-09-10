#include "field_overlay_effects_internal.h"

void ov01_021F0FB8(u32 count) {
    Triple value = { 0, 0, 0 };
    u32 i;
    if (!*(void **)ov01_02209B64) {
        GF_ASSERT(FALSE);
    }
    if (!*(void **)(*(u8 **)ov01_02209B64 + 8)) {
        GF_ASSERT(FALSE);
    }
    for (i = 0; i < count; i++) {
        sub_02015484(*(void **)(*(u8 **)ov01_02209B64 + 8), i, &value);
    }
}

BOOL ov01_021F1008(void) {
    u8 *p = *(u8 **)ov01_02209B64;
    void *q;
    if (!p) {
        GF_ASSERT(FALSE);
    }
    q = *(void **)(*(u8 **)ov01_02209B64 + 8);
    if (!q) {
        return TRUE;
    }
    sub_02015460(q);
    return sub_020154B0(*(void **)(*(u8 **)ov01_02209B64 + 8)) == 0;
}

BOOL ov01_021F1044(void) {
    return sub_020154B0(*(void **)(*(u8 **)ov01_02209B64 + 8)) == 0;
}

void ov01_021F1060(void) {
    if (!*(void **)ov01_02209B64) {
        GF_ASSERT(FALSE);
    }
    sub_02014EBC(*(void **)(*(u8 **)ov01_02209B64 + 8));
    Heap_Free(*(void **)(*(u8 **)ov01_02209B64 + 0xC));
    *(void **)(*(u8 **)ov01_02209B64 + 8) = NULL;
    *(void **)(*(u8 **)ov01_02209B64 + 0xC) = NULL;
}

void ov01_021F1094(SysTask *task, void *v) {
    u8 *p = v;
    switch (*(u16 *)p) {
    case 0:
        (*(u16 *)p)++;
        break;
    case 1:
        if (p[3] == 1) {
            ov01_021F1148(*(void **)(p + 4));
            SysTask_Destroy(task);
            (*(u16 *)p)++;
        }
        break;
    }
}
