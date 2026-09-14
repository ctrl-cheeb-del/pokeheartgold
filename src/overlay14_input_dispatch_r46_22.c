#include "overlay14_input_dispatch_r46_22_private.h"

u32 ov14_021EB388(void *work) {
    u32 input = ov14_021F6A14();

    if (input != -1) {
        if (ov14_021E6070(work, input, 0xac, 0) != 0) {
            PlaySE(0x5eb);
            System_GetTouchNewCoords((u32 *)((u8 *)PTR_AT(work, 0x34) + 0x40b8),
                (u32 *)((u8 *)PTR_AT(work, 0x34) + 0x40bc));
            if (ov14_021E8544(PTR_AT(PTR_AT(work, 0x34), 0x2f0)) == 0) {
                ov14_021F5EE4(work, ov14_021F7D3C, 5);
            }
            ov14_021E7588(work, input);
            ov14_021F2A18(PTR_AT(work, 0x34), 9, 0);
            return ov14_021F039C(work, input);
        }
        if (ov14_021E8544(PTR_AT(PTR_AT(work, 0x34), 0x2f0)) == 1) {
            u32 old = U8_AT(work, 0x21);
            u32 next = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c));
            ov14_021F7AC4(PTR_AT(work, 0x34), old, next);
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), old);
            ov14_021E84A4(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
            ov14_021E8248(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
            ov14_021E82A8(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
            ov14_021E8328(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
            ov14_021E884C(PTR_AT(work, 0x34));
            ov14_021F40E8(work, 0);
            return ov14_021F0234(work, (void *)ov14_021EA180, 0x4a);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), (u8)input);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(work, 0x34), 0x2c), 1);
        ov14_021E765C(work);
        return 0xc;
    }

    input = ov14_021F6F94(work);
    switch (input) {
    case 30:
        PlaySE(0x5dd);
        ov14_021E76B8(work);
        return ov14_021F1128(work);
    case 31:
        PlaySE(0x5dc);
        ov14_021E76B8(work);
        ov14_021F2A18(PTR_AT(work, 0x34), 9, 0);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), 0x1e);
        return ov14_021F028C(work, 0xc);
    case 32:
        PlaySE(0x5dc);
        ov14_021E76B8(work);
        ov14_021F2A18(PTR_AT(work, 0x34), 9, 0);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), 0x1e);
        return ov14_021F0314(work, 0xc);
    case 33:
        PlaySE(0x632);
        return ov14_021F2270(work, 8, 0x95);
    case 34:
        PlaySE(0x632);
        U8_AT(work, 0x2a) = 0;
        U8_AT(work, 0x2b) = 0;
        return ov14_021F2330(work, 9, 0x96);
    case 36:
        PlaySE(0x5dd);
        if (System_GetTouchNew() == 0) {
            U8_AT(work, 0x2a) = 1;
        }
        U8_AT(work, 0x2b) = U8_AT(work, 0x21);
        return ov14_021F2330(work, 3, 0xb2);
    case 37:
        PlaySE(0x5dd);
        U32_AT(work, 0x2c) = 0x25;
        return ov14_021F2270(work, 4, 0x97);
    case 38:
        PlaySE(0x5dd);
        return ov14_021F2270(work, 5, 0x98);
    case 39:
        PlaySE(0x5dd);
        return ov14_021F2270(work, 6, 0x99);
    case 40:
        PlaySE(0x5dd);
        return ov14_021F2270(work, 7, 0x9b);
    case 41: {
        u32 old;
        PlaySE(0x5dc);
        old = U8_AT(work, 0x21);
        ov14_021F7AC4(PTR_AT(work, 0x34), old, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c)));
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), old);
        return ov14_021F2270(work, 0xb, 0x9c);
    }
    case -1: {
        u32 next = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c));
        if (next == 0x1e) {
            if (U32_AT(gSystem, 0x48) & 0x20) {
                PlaySE(0x5dc);
                ov14_021E76B8(work);
                return ov14_021F028C(work, 0xc);
            }
            if (U32_AT(gSystem, 0x48) & 0x10) {
                PlaySE(0x5dc);
                ov14_021E76B8(work);
                return ov14_021F0314(work, 0xc);
            }
        }
        break;
    }
    case -3: {
        u32 next = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c));
        if (next < 0x1e) {
            ov14_021E7588(work, next);
        } else if (next != 0x24 && next != 0x25 && next != 0x26 && next != 0x27 && next != 0x28 && next != 0x29) {
            ov14_021E765C(work);
        }
        PlaySE(0x5dc);
        return ov14_021F0244(work, 0x4a);
    }
    case 35:
        PlaySE(0x5dd);
        ov14_021E765C(work);
        return ov14_021F2270(work, 10, 0x93);
    case -2:
        PlaySE(0x5dd);
        return ov14_021F2270(work, 10, 0x94);
    case -4: {
        u32 next = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c));
        if (next < 0x1e) {
            ov14_021E7588(work, next);
        } else if (next != 0x24 && next != 0x25 && next != 0x26 && next != 0x27 && next != 0x28 && next != 0x29) {
            ov14_021E765C(work);
        }
        PlaySE(0x5dc);
        break;
    }
    default:
        if (ov14_021E6070(work, input, 0xac, 0) != 0) {
            PlaySE(0x5dd);
            ov14_021F5EE4(work, ov14_021F7D3C, 5);
            ov14_021E7588(work, input);
            ov14_021F7AC4(PTR_AT(work, 0x34), 0x24, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c)));
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), 0x24);
            return ov14_021F0530(work, input);
        }
        break;
    }
    return 0xc;
}
