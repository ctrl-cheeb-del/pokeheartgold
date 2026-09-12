#include "overlay40_touch_indicator_r25_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

int ov40_022306F0(void *p) {
    u32 a;
    u32 b;
    u8 c;
    SAVE_MISC_DATA *misc = Save_Misc_Get(PTR(p, 0x830));
    sub_0202AC38(misc, U32(p, 0x86C) + 2, &a, &b, &c);
    sub_0202AC60(misc, U32(p, 0x86C) + 2, -1, -1, c);
    return 1;
}

void ov40_02230738(void) {
    SetBgPriority(0, 1);
    SetBgPriority(1, 3);
    SetBgPriority(2, 0);
    SetBgPriority(3, 1);
    SetBgPriority(4, 1);
    SetBgPriority(5, 3);
    SetBgPriority(6, 0);
    SetBgPriority(7, 1);
}

void ov40_0223077C(void *p, UnkStruct02087284 *motion, s16 x, s16 y) {
    if (U32(p, 0x44) == 0) {
        sub_020879E0(motion, 1);
    }
    sub_020878B0(motion, 1);
    sub_02087948(motion, x, y);
    sub_020878B8(motion, x, y);
}

int ov40_022307B0(u64 value) {
    int digits = 1;
    while (value > 1) {
        value /= 10;
        digits++;
    }
    return digits;
}

void ov40_022307DC(void *p, int member, GFBgLayer layer) {
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), member, PTR(p, 0x24), layer, 0, 0, 0, HEAP_ID_109);
}

void ov40_022307FC(SysTask *task, Ov40TouchIndicatorWork *p) {
    s16 position;
    p->counter++;
    if (p->counter >= 7) {
        SysTask_Destroy(task);
        p->counter = 0;
        p->active = 0;
        sub_02087A54(p->motion);
        sub_02087A08(p->motion, 0, 0);
        sub_020878B0(p->motion, 0);
        sub_020879E0(p->motion, 0);
    } else {
        position = (s16)(p->counter * 2 + 6);
        sub_02087A08(p->motion, position, position);
    }
}

void ov40_02230864(Ov40TouchIndicatorWork *p) {
    u32 x;
    u32 y;
    if (p->active == 1) {
        if (p->task != NULL) {
            SysTask_Destroy(p->task);
        }
        p->task = NULL;
    }
    if (gSystem.screensFlipped == 0) {
        p->motion = p->motionA;
    } else {
        p->motion = p->motionB;
    }
    p->active = 1;
    p->counter = 0;
    System_GetTouchNewCoords(&x, &y);
    sub_02087A30(p->motion);
    sub_020878B0(p->motion, 1);
    sub_020879E0(p->motion, 1);
    sub_020878B8(p->motion, (s16)x, (s16)y);
    sub_02087948(p->motion, (s16)x, (s16)y);
    p->task = SysTask_CreateOnMainQueue((SysTaskFunc)ov40_022307FC, p, 0x1000);
    if (p->task != NULL) {
        ov40_022307FC(p->task, p);
    } else {
        p->active = 0;
        sub_020879E0(p->motion, 0);
        GF_AssertFail();
    }
}
