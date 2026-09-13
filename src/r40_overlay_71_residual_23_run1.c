#include "r40_overlay_71_residual_23_private.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

#define DRAW(p)                                     \
    do {                                            \
        ov71_022476C4(PTR(p, 0), (u8 *)(p) + 0x14); \
        ov71_022476EC(PTR(p, 0), (u8 *)(p) + 0x20); \
    } while (0)

void ov71_0224926C(void *task) {
    u16 v[3];
    void *p = SysTask_GetData(task);
    U32(p, 0x78) = 0;
    v[2] = 0;
    v[1] = v[2];
    v[0] = v[1];
    ov71_0224782C(PTR(p, 4), 1);
    ov71_0224780C(PTR(p, 4), v);
    U32(p, 0x2C) = 0x58CC;
    U32(p, 0x28) = U32(p, 0x2C) - 0x80000;
    U32(p, 0x80) = 20;
    U32(p, 0x18) = U32(p, 0x28);
    ov71_02248FC8(p, 0, 0, 20);
    ov71_02249004(p, 1, -(s16) * (s16 *)((u8 *)p + 0x56), 30);
    ov71_02249004(p, 2, 0x100, 50);
    ov71_02247730(PTR(p, 0), 0x2000);
    ov71_02247704(PTR(p, 0), 1);
    SysTask_SetFunc(task, ov71_022492FC);
}

void ov71_022492FC(void *task, void *p) {
    ov71_0224903C(p);
    if (U32(p, 0x80) != 0) {
        U32(p, 0x28) += U32(p, 0x2C);
        U32(p, 0x18) = U32(p, 0x28);
        U32(p, 0x80)
        --;
        if (U32(p, 0x80) == 0) {
            SysTask_SetFunc(task, ov71_02249358);
        }
    }
    DRAW(p);
}

void ov71_02249358(void *task, void *p) {
    ov71_0224903C(p);
    U32(p, 0x80)
    ++;
    if (S32(p, 0x80) > 0x6E) {
        S32(p, 0x2C) = (-0x3A800 - S32(p, 0x28)) / 0x35;
        U32(p, 0x80) = 0x35;
        SysTask_SetFunc(task, ov71_022493B8);
    }
    DRAW(p);
}

void ov71_022493B8(void *task, void *p) {
    ov71_0224903C(p);
    if (U32(p, 0x80) != 0) {
        U32(p, 0x28) += U32(p, 0x2C);
        U32(p, 0x18) = U32(p, 0x28);
        U32(p, 0x80)
        --;
        if (U32(p, 0x80) == 0) {
            SysTask_SetFunc(task, ov71_02249414);
        }
    }
    DRAW(p);
}

void ov71_02249414(void *task, void *p) {
    ov71_0224903C(p);
    U32(p, 0x80)
    ++;
    if (S32(p, 0x80) > 1) {
        U32(p, 0x2C) = 0x20000;
        SysTask_SetFunc(task, ov71_02249460);
    }
    DRAW(p);
}

void ov71_02249460(void *task, void *p) {
    if (U32(p, 0x78) == 0) {
        ov71_0224903C(p);
        U32(p, 0x28) += U32(p, 0x2C);
        U32(p, 0x18) = U32(p, 0x28);
        DRAW(p);
        if (ov71_02247738(PTR(p, 0)) == 0) {
            U32(p, 0x78) = 1;
        }
    }
}
