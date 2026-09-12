#include "overlay45_lobby_state_r15_private.h"

void ov45_0222BAC4(u8 *p, void *ctx) {
    *(u32 *)&p[0xb4] = SaveArray_CalcCRC16(ctx, &p[0x20], 0x94);
}

BOOL ov45_0222BADC(u8 *p, void *ctx) {
    u16 crc = SaveArray_CalcCRC16(ctx, &p[0x20], 0x94);
    if (crc != *(u32 *)&p[0xb4]) {
        GF_AssertFail();
        return FALSE;
    }
    return TRUE;
}
