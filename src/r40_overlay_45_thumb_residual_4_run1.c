#include "global.h"

#include "r40_overlay_45_thumb_residual_4_private.h"

BOOL ov45_0222A230(void *p, int bit) {
    u32 mask = 1 << bit;
    if (*(u32 *)((u8 *)p + 0xF8) & mask) {
        *(u32 *)((u8 *)p + 0xF8) &= ~mask;
        return TRUE;
    }
    return FALSE;
}

BOOL ov45_0222A25C(void *p, int bit) {
    u32 mask = 1 << bit;
    if (*(u32 *)((u8 *)p + 0xFC) & mask) {
        *(u32 *)((u8 *)p + 0xFC) &= ~mask;
        return TRUE;
    }
    return FALSE;
}

BOOL ov45_0222A288(void *p, int bit) {
    return (*(u32 *)((u8 *)p + 0x100) & (1 << bit)) != 0;
}

BOOL ov45_0222A2A0(void *p, int bit) {
    u32 mask = 1 << bit;
    if (*(u32 *)((u8 *)p + 0x104) & mask) {
        *(u32 *)((u8 *)p + 0x104) &= ~mask;
        return TRUE;
    }
    return FALSE;
}
