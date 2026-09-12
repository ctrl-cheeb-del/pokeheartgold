#include "overlay14_box_transition_handlers_private.h"

u32 ov14_021EBF9C(void *p) {
    u32 slot;
    void *mon;
    if (U8_AT(p, 0x21) >= 0x1e) {
        ov14_021F3488(p, 2, 1);
        ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        slot = U8_AT(p, 0x21) - 0x1e;
        if (ov14_021E6480(p, slot) == 0) {
            PlaySE(0x5f3);
            ov14_021F67B0(p, 6, 0x25);
            U8_AT(PTR_AT(p, 0x34), 0x44e) |= 0x80;
            U32_AT(p, 0x30) = 0xe;
            return 6;
        }
        mon = Party_GetMonByIndex(PTR_AT(p, 8), slot);
        if (ItemIdIsMail((u16)GetMonData(mon, 6, 0)) == 1) {
            PlaySE(0x5f3);
            ov14_021F685C(p, 0, 6, 0x25);
            U8_AT(PTR_AT(p, 0x34), 0x44e) |= 0x80;
            U32_AT(p, 0x30) = 0xe;
            return 6;
        }
        if (GetMonData(mon, 0xa2, 0) != 0) {
            PlaySE(0x5f3);
            ov14_021F685C(p, 0, 5, 0x25);
            U8_AT(PTR_AT(p, 0x34), 0x44e) |= 0x80;
            U32_AT(p, 0x30) = 0xe;
            return 6;
        }
    } else {
        ov14_021F43F4(PTR_AT(p, 0x34), 0);
        ov14_021F3488(p, 1, 1);
        ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    }
    if (GetBoxMonData(ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21)), 0x4c, 0) != 0) {
        PlaySE(0x5f3);
        ov14_021F67B0(p, 3, 0x25);
        U8_AT(PTR_AT(p, 0x34), 0x44e) |= 0x80;
        U32_AT(p, 0x30) = 0xe;
        return 6;
    }
    ov14_021F67B0(p, 0, 0x25);
    return ov14_021F0254(p, 1);
}

u32 ov14_021EC0EC(void *p) {
    void *x;
    ov14_021E7278(p);
    x = PTR_AT(PTR_AT(p, 0x34), 0x88dc);
    if (ov14_021F3380(x) == 0) {
        x = PTR_AT(PTR_AT(p, 0x34), 0x88dc);
        if (U8_AT(x, 6) != 0) {
            return 0x1e;
        }
        ov14_021F33E8(x);
        ov14_021E7264(p);
        return 0x1b;
    }
    return 0x1a;
}

u32 ov14_021EC128(void *p) {
    ov14_021F67B0(p, 1, 0x25);
    U32_AT(p, 0x30) = 0x1c;
    return 6;
}
u32 ov14_021EC13C(void *p) {
    ov14_021F67B0(p, 2, 0x25);
    U32_AT(p, 0x30) = 0x1d;
    return 6;
}

u32 ov14_021EC150(void *p) {
    void (*next)(void);
    ov14_021E6100(p, U8_AT(p, 0x1f), U8_AT(p, 0x21));
    ov14_021F6654(PTR_AT(p, 0x34), 0x25);
    ov14_021E765C(p);
    if (U8_AT(p, 0x21) < 0x1e) {
        ov14_021F4958(p, U8_AT(p, 0x1f));
        ov14_021F4A20(p, U8_AT(p, 0x1f));
        if (U32_AT(PTR_AT(p, 0), 8) == 1) {
            ov14_021F685C(p, 0, 0, 0x27);
            U32_AT(p, 0x30) = 0x51;
        } else {
            U32_AT(p, 0x30) = 0xc;
            ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
        ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        ov14_021F43F4(PTR_AT(p, 0x34), 1);
        ov14_021F3488(p, 1, 0);
        U8_AT(p, 0x21) = 0xff;
        next = ov14_021E9450;
    } else {
        ov14_021F08BC(p);
        U8_AT(p, 0x22) = 1;
        U32_AT(p, 0x30) = 0x21;
        ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021F3488(p, 2, 0);
        next = ov14_021E9194;
    }
    return ov14_021F0234(p, next, U32_AT(p, 0x30));
}

u32 ov14_021EC23C(void *p) {
    ov14_021F08F0(p);
    if (U8_AT(p, 0x24) != 0) {
        ov14_021F57B8(p);
    }
    ov14_021E7588(p, U8_AT(p, 0x21));
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x21) - 0x1e));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    U8_AT(p, 0x21) = 0xff;
    if (U32_AT(PTR_AT(p, 0), 8) == 0) {
        ov14_021F685C(p, 0, 0, 0x27);
        return 0x5b;
    }
    return 0x24;
}

u32 ov14_021EC2A4(void *p) {
    void *x = PTR_AT(PTR_AT(p, 0x34), 0x88dc);
    if (ov14_021F33B0(x) == 0) {
        x = PTR_AT(PTR_AT(p, 0x34), 0x88dc);
        ov14_021F33FC(x);
        ov14_021E7264(p);
        ov14_021F3F6C(p);
        ov14_021F67B0(p, 4, 0x25);
        ov14_021E8824(PTR_AT(p, 0x34));
        U32_AT(p, 0x30) = 0x1f;
        return 6;
    }
    return 0x1e;
}
u32 ov14_021EC2EC(void *p) {
    ov14_021F67B0(p, 5, 0x25);
    U32_AT(p, 0x30) = 0x20;
    return 6;
}
u32 ov14_021EC300(void *p) {
    ov14_021F40E8(p, 1);
    if (U8_AT(p, 0x21) < 0x1e) {
        ov14_021F43F4(PTR_AT(p, 0x34), 1);
        ov14_021F3488(p, 1, 0);
    } else {
        ov14_021F3488(p, 2, 0);
    }
    return ov14_021F0234(p, (void *)ov14_021E9450, 0xe);
}
