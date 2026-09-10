#include "field_overlay_effects_internal.h"

SysTask *ov01_021F127C(void *p) {
    return SysTask_CreateOnVBlankQueue(ov01_021F1290, p, 1 << 10);
}

void ov01_021F1290(SysTask *task, Interp *v) {
    u8 *p = (u8 *)v;
    if (*(u32 *)(p + 8) >= 2) {
        sub_02014C08(*(void **)p);
        *(u32 *)(p + 8) = 0;
    }
    sub_02014C40(*(void **)p);
    (*(u32 *)(p + 8))++;
}

void ov01_021F12B4(void *v, void *arg) {
    u8 *p = v;
    *(void **)p = sub_02014AD8(arg);
    *(u32 *)(p + 8) = 0;
    *(void **)(p + 4) = ov01_021F127C(p);
}

void ov01_021F12D0(void *v) {
    u8 *p = v;
    SysTask_Destroy(*(SysTask **)(p + 4));
    sub_02014B9C(*(void **)p);
    sub_02014BD8(*(void **)p);
}

void ov01_021F12E8(void *v, s32 a, s32 b, s32 c, s32 d, s16 e, s32 f, s32 g, s32 h) {
    sub_02014B08(*(void **)v, a, b, c, d, e, f, g, h);
}
