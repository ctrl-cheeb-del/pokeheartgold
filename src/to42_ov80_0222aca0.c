#include "to42_ov80_0222aca0_internal.h"

u32 ov80_0222ACA0(u32 index, u32 field) {
    switch (field) {
    case 0:
        return ov80_0223B724[index].word0;
    case 1:
        return ov80_0223B724[index].values[0];
    case 2:
        return ov80_0223B724[index].values[1];
    case 3:
        return ov80_0223B724[index].values[2];
    case 4:
        return ov80_0223B724[index].values[3];
    case 5:
        return ov80_0223B724[index].values[4];
    case 6:
        return ov80_0223B724[index].values[5];
    case 7:
        return ov80_0223B724[index].values[6];
    case 8:
        return ov80_0223B724[index].values[7];
    case 9:
        return ov80_0223B724[index].values[8];
    case 10:
        return ov80_0223B724[index].values[9];
    case 11:
        return ov80_0223B724[index].values[10];
    case 12:
        return ov80_0223B724[index].byte26;
    case 13:
        return ov80_0223B724[index].byte27;
    default:
        GF_AssertFail();
        return 0;
    }
}

void ov80_0222AD9C(void *a, void *b, u32 index) {
    Overlay80Callback callback = ov80_0223B724[index].init;
    if (callback != NULL) {
        callback(a, b);
    }
}

void ov80_0222ADB4(void *a, void *b, u32 index) {
    Overlay80Callback callback = ov80_0223B724[index].exit;
    if (callback != NULL) {
        callback(a, b);
    }
}

void ov80_0222ADCC(void *unused, void **dest) {
    *dest = Heap_Alloc(0x65, 0x20);
}

void ov80_0222ADDC(void *unused, void **dest) {
    Heap_Free(*dest);
}

void ov80_0222ADE8(void **args, void **dest) {
    *dest = ov80_02239D74(args[0], args[1]);
    SetBgPriority(0, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    GfGfx_EngineATogglePlanes(4, 0);
}

void ov80_0222AE1C(void *unused, void **dest) {
    ov80_02239DB8(*dest);
}
void ov80_0222AE28(void) {
}
void ov80_0222AE2C(void) {
}

void ov80_0222AE30(void) {
    SetBgPriority(0, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    G2x_SetBlendAlpha_(0x04000050, 1, 0x3c, 0x14, 0x14);
    GfGfx_EngineATogglePlanes(4, 0);
}

void ov80_0222AE68(void) {
}

void ov80_0222AE6C(void) {
    SetBgPriority(2, 3);
    SetBgPriority(3, 2);
}

void ov80_0222AE80(void) {
}

void ov80_0222AE84(void) {
    G2x_SetBlendAlpha_(0x04000050, 1, 0x3c, 0x14, 0x14);
}

void ov80_0222AE9C(void) {
}

void ov80_0222AEA0(void **args, void **dest) {
    *dest = ov80_022384D8(args[0]);
}

void ov80_0222AEB0(void *unused, void **dest) {
    ov80_022385B0(*dest);
}

void ov80_0222AEBC(void) {
    SetBgPriority(1, 0);
    SetBgPriority(0, 2);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    G2x_SetBlendAlpha_(0x04000050, 1, 0x3c, 0x14, 0x14);
}

void ov80_0222AEF4(void) {
}
