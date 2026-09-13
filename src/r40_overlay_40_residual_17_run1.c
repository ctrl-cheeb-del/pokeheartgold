#include "r40_overlay_40_residual_17_private.h"

void ov40_0222FB40(void *p) {
    u32 unused;
    void *base;

    sub_0202FBF0(PTRAT(p, 0x830), 0x7E, &unused);
    base = PTRAT(p, 0x8B4);
    sub_02030814(base, ADD(base, 0x80), ADD(base, 0xE4), 0, PTRAT(p, 0x830));
}

void ov40_0222FB74(void *task, void *data) {
    ov40_0222BC44(PTRAT(data, 0));
    sub_0203A86C();
    U32AT(data, 4) = 1;
    SysTask_Destroy(task);
}

void *ov40_0222FB90(void *p, void *value) {
    PTRAT(p, 0x52C) = value;
    U32AT(p, 0x530) = 0;
    return SysTask_CreateOnVBlankQueue(ov40_0222FB74, ADD(p, 0x52C), 4);
}
