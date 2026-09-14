#include "overlay02_248728_partial_internal.h"

int ov02_02249B60(void *);
int ov02_02249B80(void *);
int ov02_02249BA8(void *);
int ov02_02249BD8(void *);
int ov02_02249C74(void *);
u8 ov02_0224AB8C(void *);
void ov02_0224A69C(void *, u32, u32, u32, u32);
void ov02_02249420(void);
void ov02_0224AB9C(void *);

int ov02_02249B60(void *p) {
    U32(p, 8)
    ++;
    if ((s32)U32(p, 8) >= 20) {
        U32(p, 8) = 0;
        U32(p, 0)
        ++;
        ov02_0224ADF0(p);
    }
    return 1;
}

int ov02_02249B80(void *p) {
    U32(p, 8)
    ++;
    if ((s32)U32(p, 8) >= 20) {
        U32(p, 8) = 0;
        U32(p, 0)
        ++;
        ov02_0224AB58(p);
        ov02_0224ADF0(p);
    }
    return 1;
}

int ov02_02249BA8(void *p) {
    if (ov02_0224AB8C(p) != 3) {
        return 0;
    }
    PlaySE(0x648);
    U32(p, 0x54) = 2 << 10;
    U32(p, 0x14) = 2;
    U32(p, 0)
    ++;
    return 1;
}

int ov02_02249BD8(void *p) {
    U32(p, 0x2c) = 0;
    U32(p, 0x4c) += U32(p, 0x54);
    U32(p, 0x50) -= U32(p, 0x54);
    U32(p, 0x54) += 2 << 10;
    if ((s32)U32(p, 0x54) > (2 << 15)) {
        U32(p, 0x54) = 2 << 15;
    }
    if ((s32)U32(p, 0x4c) >= (0x5f << 12)) {
        U32(p, 0x4c) = 0x5f << 12;
    }
    if ((s32)U32(p, 0x50) <= (0x61 << 12)) {
        U32(p, 0x50) = 0x61 << 12;
    }
    ov02_0224A69C(p, U32(p, 0x44), U32(p, 0x4c), U32(p, 0x48), U32(p, 0x50));
    U32(p, 0x2c) = 1;
    if (U32(p, 0x18) == 0 && ov02_0224AB8C(p) == 4) {
        U32(p, 0x18) = 1;
        ov02_02249420();
    }
    if (U32(p, 0x4c) == (0x5f << 12) && U32(p, 0x50) == (0x61 << 12)) {
        U32(p, 0x34) = 0x11;
        U32(p, 0x14) = 1;
        U32(p, 0)
        ++;
    }
    return 0;
}

int ov02_02249C74(void *p) {
    if (U32(p, 0x20) == 3) {
        if (ov02_0224AB8C(p) == 2) {
            ov02_0224AB9C(p);
            U32(p, 0) += 2;
        }
        return 0;
    }
    if (U32(p, 0x18) == 0 && ov02_0224AB8C(p) == 4) {
        U32(p, 0x18) = 1;
        ov02_02249420();
    }
    if (ov02_0224AB8C(p) != 2) {
        return 0;
    }
    if (U32(p, 0x18) == 0) {
        U32(p, 0x18) = 1;
        ov02_02249420();
    }
    ov02_0224AB9C(p);
    U32(p, 0)
    ++;
    return 0;
}
