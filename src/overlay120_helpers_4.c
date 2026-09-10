#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

int ov120_0225F8B0(void *owner, void *state) {
    int done;
    switch (U32(state, 0)) {
    case 0:
        PTR(owner, 4) = ov120_0225F0FC(4);
        ov120_0225F120(PTR(owner, 4), 0, PTR(owner, 0), 0xf);
        U32(state, 0) = 1;
        break;
    case 1:
        done = ov120_0225F14C(PTR(owner, 4));
        ScheduleWindowCopyToVram(PTR(owner, 0));
        if (done) {
            U32(state, 0) = 2;
        }
        break;
    case 2:
        ov120_0225F118(PTR(owner, 4));
        U32(state, 0) = 0;
        return 1;
    default:
        GF_AssertFail();
    }
    return 0;
}

int ov120_0225F90C(void *owner, void *state) {
    switch (U32(state, 0)) {
    case 0:
        HBlankSystem_Stop(PTR(owner, 8));
        BeginNormalPaletteFade(3, 0x2a, 0x2a, 0, 0x1c, 1, 4);
        U32(state, 0) = 1;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U32(state, 0) = 2;
        }
        break;
    case 2:
        HBlankSystem_Start(PTR(owner, 8));
        U32(state, 0) = 0;
        return 1;
    default:
        GF_AssertFail();
    }
    return 0;
}

int ov120_0225F970(void *owner, void *state) {
    switch (U32(state, 0)) {
    case 0:
        HBlankSystem_Stop(PTR(owner, 8));
        BeginNormalPaletteFade(3, 0x18, 0x18, 0, 0x1c, 1, 4);
        U32(state, 0) = 1;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U32(state, 0) = 2;
        }
        break;
    case 2:
        HBlankSystem_Start(PTR(owner, 8));
        U32(state, 0) = 0;
        return 1;
    default:
        GF_AssertFail();
    }
    return 0;
}

void ov120_0225F9D4(void *manager, void **out, void *a, void *b, int variant) {
    u32 offset;
    if (variant == 2) {
        GF_AssertFail();
    }
    offset = variant * 0x10;
    ov01_021F0614(manager, a, b, *(u32 *)((u8 *)ov120_02260200 + offset), 1, *(u32 *)((u8 *)ov120_022601F4 + offset), *(u32 *)((u8 *)ov120_022601FC + offset), *(u32 *)((u8 *)ov120_022601F8 + offset), 0x927c0);
    *out = ov01_021F0718(a, b, 0x80000, 0x60000, 0, 0);
    Sprite_SetDrawFlag(*out, 1);
    Sprite_SetDrawPriority(*out, 0x10);
    Sprite_SetPriority(*out, 1);
}

void ov120_0225FA5C(void *a, void *b) {
    ov120_0225FA74(a, b, 1);
}

void ov120_0225FA68(void *a, void *b) {
    ov120_0225FA74(a, b, 0);
}
