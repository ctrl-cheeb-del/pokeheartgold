#include "overlay_14_state_handlers_ee4e4_private.h"

u32 ov14_021EE4E4(void *p);
u32 ov14_021EE4FC(void *p);
u32 ov14_021EE538(void *p);
u32 ov14_021EE578(void *p);
u32 ov14_021EE5C8(void *p);
u32 ov14_021EE664(void *p);
u32 ov14_021EE6D0(void *p);
u32 ov14_021EE6F8(void *p);
u32 ov14_021EE7B4(void *p);
u32 ov14_021EE7C4(void *p);
u32 ov14_021EE7D4(void *p);
u32 ov14_021EE7E4(void *p);
u32 ov14_021EE7F4(void *p);
u32 ov14_021EE810(void *p);
u32 ov14_021EE820(void *p);
u32 ov14_021EE830(void *p);
u32 ov14_021EE840(void *p);
u32 ov14_021EE850(void *p);
u32 ov14_021EE860(void *p);
u32 ov14_021EEC8C(void *p);
u32 ov14_021EF6D4(void *p);
u32 ov14_021EF6E4(void *p);
u32 ov14_021EF9BC(void *p);
u32 ov14_021EFDE4(void *p);
u32 ov14_021F00A0(void *p);
u32 ov14_021F0198(void *p);
u32 ov14_021F01B8(void *p);
u32 ov14_021EF93C(void *p);
u32 ov14_021EE87C(void *p);
u32 ov14_021EF248(void *p);
u32 ov14_021EEBFC(void *p);
u32 ov14_021EED28(void *p);
u32 ov14_021EEDB8(void *p);
u32 ov14_021EEF8C(void *p);
u32 ov14_021EFDF4(void *p);
u32 ov14_021EF024(void *p);
u32 ov14_021EF6FC(void *p);
u32 ov14_021EFF00(void *p);
u32 ov14_021EF9CC(void *p);
u32 ov14_021EFB64(void *p);

u32 ov14_021EE4E4(void *p) {
    ov14_021F4CA0(p);
    return ov14_021F0234(p, ov14_021E98AC, 0x65);
}
u32 ov14_021EE4FC(void *p) {
    ov14_021F6AC0(p, 0, 7);
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021F3F6C(p);
    ov14_021F40E8(p, 1);
    ov14_021F3488(p, 2, 0);
    return 0xe;
}
u32 ov14_021EE538(void *p) {
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E8588(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E99F0, 0x67);
}
u32 ov14_021EE578(void *p) {
    if (PCStorage_CountMonsAndEggsInBox(PTR_AT(p, 4), U8_AT(p, 0x25)) == 0x1e) {
        ov14_021F685C(p, 0, 4, 0x25);
        U32_AT(p, 0x30) = 0x5e;
        return 6;
    }
    ov14_021F3488(p, 2, 0);
    ov14_021F6654(PTR_AT(p, 0x34), 0x27);
    ov14_021F4CA0(p);
    return ov14_021F0234(p, ov14_021E98AC, 0x68);
}
u32 ov14_021EE5C8(void *p) {
    ov14_021E8048(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E952C, 0x69);
}
u32 ov14_021EE5E8(void *p) {
    void *cb;
    u8 old = U8_AT(p, 0x1f);
    U8_AT(p, 0x1f) = U8_AT(p, 0x25);
    if (old == U8_AT(p, 0x25)) {
        return 0x6a;
    }
    if (old > U8_AT(p, 0x25)) {
        ov14_021F2DE8(p, U8_AT(p, 0x1f));
        ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 0);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
        cb = ov14_021E92AC;
    } else {
        ov14_021F2DE8(p, U8_AT(p, 0x1f));
        ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 1);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
        cb = ov14_021E9370;
    }
    return ov14_021F0234(p, cb, 0x6a);
}
u32 ov14_021EE664(void *p) {
    U8_AT(p, 0x22) = 2;
    ov14_021F08BC(p);
    return ov14_021F0234(p, ov14_021E9234, 0x6b);
}
u32 ov14_021EE684(void *p) {
    void *q = PTR_AT(PTR_AT(p, 0x34), 0xc);
    PlaySE(0x5ea);
    ov14_021E637C(p);
    ov14_021E6548(p, U32_AT(q, 0xe4), U32_AT(q, 0xe8));
    ov14_021F08F0(p);
    ov14_021E8094(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E954C, 0x6c);
}
u32 ov14_021EE6D0(void *p) {
    ov14_021F5EB4(p, 0);
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E95B4, 0x6d);
}
u32 ov14_021EE6F8(void *p) {
    ov14_021F6AC0(p, 0, 0);
    ov14_021F685C(p, 0, 0, 0x27);
    ov14_021E7588(p, 0x1e);
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    return 0x5b;
}
u32 ov14_021EE728(void *p) {
    void *q = PTR_AT(PTR_AT(p, 0x34), 0xc);
    PlaySE(0x5ea);
    ov14_021E637C(p);
    ov14_021E6548(p, U32_AT(q, 0xe4), U32_AT(q, 0xe8));
    ov14_021F08F0(p);
    ov14_021F6678(PTR_AT(p, 0x34), 0x28);
    if (U8_AT(p, 0x21) == 0xff) {
        ov14_021F685C(p, 0, 0, 0x27);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        ov14_021E7588(p, 0x1e);
    } else {
        ov14_021F685C(p, U8_AT(p, 0x21), 1, 0x27);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 7);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    }
    return 0x5b;
}
u32 ov14_021EE7B4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0xc;
}
u32 ov14_021EE7C4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x29;
}
u32 ov14_021EE7D4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x24;
}
u32 ov14_021EE7E4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x5b;
}
u32 ov14_021EE7F4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    ov14_021F685C(p, 0, 0, 0x27);
    return 0x5b;
}
u32 ov14_021EE810(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x61;
}
u32 ov14_021EE820(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x16;
}
u32 ov14_021EE830(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x3d;
}
u32 ov14_021EE840(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x42;
}
u32 ov14_021EE850(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x51;
}
u32 ov14_021EE860(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    ov14_021F685C(p, 0, 0, 0x27);
    return 0x51;
}
u32 ov14_021EE87C(void *p) {
    u32 v = ov14_021F6A14();
    if (v != -1) {
        if (ov14_021E6070(p, v, 0xac, 0)) {
            PlaySE(0x5eb);
            System_GetTouchNewCoords(&U32_AT(PTR_AT(p, 0x34), 0x40b8), &U32_AT(PTR_AT(p, 0x34), 0x40bc));
            ov14_021E7588(p, v);
            ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
            return ov14_021F18B0(p, v);
        }
        if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            v = U8_AT(p, 0x21);
            ov14_021F7AC4(PTR_AT(p, 0x34), v, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), v);
            ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021F40DC(p);
            if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
                ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            }
            return ov14_021F0234(p, ov14_021EA674, 0x76);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)v);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        ov14_021E765C(p);
        return 0x75;
    }
    v = ov14_021F74B0(p);
    switch (v) {
    case 0x1e:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
        return ov14_021F1128(p);
    case 0x1f:
        PlaySE(0x5dc);
        ov14_021E76B8(p);
        ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x1e);
        return ov14_021F028C(p, 0x75);
    case 0x20:
        PlaySE(0x5dc);
        ov14_021E76B8(p);
        ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x1e);
        return ov14_021F0314(p, 0x75);
    case 0x21:
        PlaySE(0x632);
        return ov14_021F2270(p, 8, 0xab);
    case 0x22:
        PlaySE(0x632);
        return ov14_021F2330(p, 9, 0xac);
    case 0x24:
        PlaySE(0x5dd);
        return ov14_021F2270(p, 7, 0xad);
    case 0x25:
        PlaySE(0x5dc);
        v = U8_AT(p, 0x21);
        ov14_021F7AC4(PTR_AT(p, 0x34), v, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), v);
        return ov14_021F2270(p, 0xb, 0xae);
    case -1:
        if (GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)) == 0x1e) {
            if (gSystem.newKeys & PAD_KEY_LEFT) {
                PlaySE(0x5dc);
                ov14_021E76B8(p);
                return ov14_021F028C(p, 0x75);
            }
            if (gSystem.newKeys & PAD_KEY_RIGHT) {
                PlaySE(0x5dc);
                ov14_021E76B8(p);
                return ov14_021F0314(p, 0x75);
            }
        }
        break;
    case -3: {
        u32 n = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (n < 0x1e) {
            ov14_021E7588(p, n);
        } else if (n != 0x24 && n != 0x25) {
            ov14_021E765C(p);
        }
        PlaySE(0x5dc);
        return ov14_021F0244(p, 0x76);
    }
    case 0x23:
        PlaySE(0x5dd);
        ov14_021E765C(p);
        return ov14_021F2270(p, 0xa, 0x93);
    case -2:
        PlaySE(0x5dd);
        return ov14_021F2270(p, 0xa, 0x94);
    case -4: {
        u32 n = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (n < 0x1e) {
            ov14_021E7588(p, n);
        } else if (n != 0x24 && n != 0x25) {
            ov14_021E765C(p);
        }
        PlaySE(0x5dc);
        break;
    }
    default:
        if (ov14_021E6070(p, v, 0xac, 0)) {
            PlaySE(0x5dd);
            ov14_021E7588(p, v);
            ov14_021F7AC4(PTR_AT(p, 0x34), 0x24, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x24);
            return ov14_021F1808(p, v);
        }
        break;
    }
    return 0x75;
}
u32 ov14_021EEBFC(void *p) {
    if (ov14_021F2A44(PTR_AT(p, 0x34), 0xb) == 1) {
        ov14_021F40DC(p);
        ov14_021F391C(PTR_AT(p, 0x34), 1);
        ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
        ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021F6654(PTR_AT(p, 0x34), 0x25);
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (U8_AT(p, 0x21) < 0x1e) {
        ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021F3488(p, 0x81, 1);
    } else {
        ov14_021F3488(p, 0x82, 1);
    }
    return ov14_021F0234(p, ov14_021E9450, 0x7b);
}
u32 ov14_021EEC8C(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x75;
}
u32 ov14_021EEC9C(void *p) {
    u8 x;
    u8 y;
    u16 idx;
    if (U8_AT(p, 0x21) >= 0x1e && ItemIdIsMail(U16_AT(PTR_AT(p, 0x34), 0x88c8)) == 1) {
        idx = (u16)(U8_AT(p, 0x21) - 0x1e);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)idx);
        DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), idx), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
        PlaySE(0x5f3);
        ov14_021F68C0(p, 4, 0x25);
        U32_AT(p, 0x30) = 0x77;
        return 6;
    }
    ov14_021F68C0(p, 2, 0x25);
    return ov14_021F0254(p, 2);
}
u32 ov14_021EED28(void *p) {
    u8 x;
    u8 y;
    u16 idx;
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 0) {
        idx = U8_AT(p, 0x21);
        if (idx >= 0x1e) {
            idx = (u16)(idx - 0x1e);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)idx);
        DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), idx), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
        ov14_021F391C(PTR_AT(p, 0x34), 0);
        ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
        ov14_021F68C0(p, 3, 0x25);
        ov14_021F5FBC(p, 0);
        U16_AT(PTR_AT(p, 0x34), 0x88c8) = 0;
        U32_AT(p, 0x30) = 0x77;
        return 6;
    }
    return 0x79;
}
u32 ov14_021EEDB8(void *p) {
    u8 x;
    u8 y;
    u16 idx = U8_AT(p, 0x21);
    if (idx < 0x1e) {
        ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021F3488(p, 0x81, 1);
    } else {
        idx = (u16)(idx - 0x1e);
        ov14_021F3488(p, 0x82, 1);
    }
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)idx);
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), idx), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    ov14_021F40DC(p);
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
    ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F6654(PTR_AT(p, 0x34), 0x25);
    if (U8_AT(p, 0x21) < 0x1e) {
        ov14_021F3488(p, 0x81, 1);
    } else {
        ov14_021F3488(p, 0x82, 1);
    }
    return ov14_021F0234(p, ov14_021E9450, 0x7b);
}
u32 ov14_021EEE94(void *p) {
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 1) {
        return 0x7b;
    }
    ov14_021F391C(PTR_AT(p, 0x34), 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 1);
    if (U8_AT(p, 0x21) >= 0x1e) {
        return 0x8b;
    }
    return 0x75;
}
u32 ov14_021EEED4(void *p) {
    u8 x;
    u8 y;
    u16 idx = U8_AT(p, 0x21);
    if (idx >= 0x1e) {
        idx -= 0x1e;
    }
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)idx);
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), idx), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    PlaySE(0x5f3);
    ov14_021F68C0(p, 5, 0x25);
    U32_AT(p, 0x30) = 0x77;
    return 6;
}
u32 ov14_021EEF34(void *p) {
    u8 x;
    u8 y;
    u16 idx = U8_AT(p, 0x21);
    if (idx >= 0x1e) {
        idx -= 0x1e;
    }
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)idx);
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), idx), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    ov14_021F6768(p, U16_AT(p, 0x1c), 0x25);
    U32_AT(p, 0x30) = 0x77;
    return 6;
}
u32 ov14_021EEF8C(void *p) {
    void *blk = PTR_AT(PTR_AT(p, 0x34), 0xc);
    if (U16_AT(blk, 0) == U8_AT(p, 0x21) || U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        ov14_021F1F38(p);
        if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            PlaySE(0x5ea);
            ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x24);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return 0x75;
    }
    PlaySE(0x5ea);
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(blk, 0), 0);
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F40DC(p);
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
    return 0x7f;
}
u32 ov14_021EF024(void *p) {
    void *blk;
    u16 held;
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 1) {
        return 0x7f;
    }
    ov14_021F391C(PTR_AT(p, 0x34), 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    blk = PTR_AT(PTR_AT(p, 0x34), 0xc);
    held = (u16)ov14_021E6070(p, U16_AT(blk, 0), 6, 0);
    ov14_021E6094(p, U16_AT(blk, 0), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U16_AT(blk, 0));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U16_AT(blk, 0), U8_AT((u8 *)PTR_AT(p, 0x34) + U16_AT(blk, 0), 0x4094));
    }
    ov14_021E7588(p, U16_AT(blk, 0));
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = held;
    ov14_021E6094(p, U8_AT(p, 0x21), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21), U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094));
    }
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        U8_AT(p, 0x21) = (u8)U16_AT(blk, 0);
        ov14_021F1F38(p);
        ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return ov14_021F0234(p, ov14_021E94BC, 0x75);
    }
    PlaySE(0x5eb);
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F39D0(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EA728, 0x80);
}
u32 ov14_021EF190(void *p) {
    void *q = PTR_AT(PTR_AT(p, 0x34), 0xc);
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(q, 0), 0);
    PlaySE(0x5ea);
    ov14_021F40DC(p);
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    U8_AT(p, 0x21) = U16_AT(q, 0);
    ov14_021F1F38(p);
    return 0x81;
}
u32 ov14_021EF1EC(void *p) {
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 1) {
        return 0x81;
    }
    ov14_021F391C(PTR_AT(p, 0x34), 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E94BC, 0x75);
}
u32 ov14_021EF248(void *p) {
    u32 v = ov14_021F6A34();
    if (v != -1) {
        if (ov14_021E6070(p, v + 0x1e, 0xac, 0)) {
            ov14_021E7588(p, v + 0x1e);
            ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
            return ov14_021F19F0(p, v + 0x1e);
        }
        ov14_021E765C(p);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(v + 0x1e));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0EE8(p, 0x82);
        }
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0D34(p, 0x82);
        }
        return 0x82;
    }
    v = ov14_021F6A14();
    if (v != -1) {
        if (ov14_021E6070(p, v, 0xac, 0)) {
            ov14_021E7588(p, v);
            ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
            return ov14_021F19F0(p, v);
        }
        ov14_021E765C(p);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)v);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0EE8(p, 0x82);
        }
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0D34(p, 0x82);
        }
        return 0x82;
    }
    if (ov14_021F7B7C(p) == 1) {
        v = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (ov14_021E6070(p, v, 0xac, 0)) {
            PlaySE(0x5dd);
            U8_AT(p, 0x21) = (u8)v;
            U8_AT(p, 0x26) = 1;
            return ov14_021F2330(p, 0xf, 0x97);
        }
        return 0x82;
    }
    v = ov14_021F70C0(p);
    switch (v) {
    case 0x25:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 0);
    case 0x26:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 1);
    case 0x27:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 2);
    case 0x28:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 3);
    case 0x29:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 4);
    case 0x2a:
        PlaySE(0x5dd);
        ov14_021E76B8(p);
        return ov14_021F0D58(p, 5);
    case 0x2b:
        PlaySE(0x5dc);
        ov14_021E76B8(p);
        ov14_021F1004(p, -1);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0EE8(p, 0x82);
        }
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0D34(p, 0x82);
        }
        return 0x82;
    case 0x2c:
        PlaySE(0x5dc);
        ov14_021E76B8(p);
        ov14_021F1004(p, 1);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0EE8(p, 0x82);
        }
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return ov14_021F0D34(p, 0x82);
        }
        return 0x82;
    case 0x2d:
        PlaySE(0x5dc);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
        return ov14_021F2270(p, 0xe, 0xaf);
    case -3: {
        u32 n = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (n < 0x24) {
            if (ov14_021E7588(p, n) == 1) {
                if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
                    ov14_021F6408(p, 0);
                    ov14_021E8620(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
                }
            } else if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
                ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            }
        } else {
            ov14_021E765C(p);
            if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
                ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            }
        }
        PlaySE(0x5dc);
        if (U32_AT(PTR_AT(p, 0x34), 8) != 0) {
            return ov14_021F0244(p, 0x83);
        }
        break;
    }
    case 0x24:
        PlaySE(0x633);
        return ov14_021F2490(p, 1, 0xa1);
    case -2:
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
            PlaySE(0x633);
            return ov14_021F2490(p, 1, 0xa1);
        }
        PlaySE(0x5dc);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return ov14_021F0EE8(p, 0x82);
    default:
        if (ov14_021E6070(p, v, 0xac, 0)) {
            ov14_021E7588(p, v);
            return ov14_021F1B4C(p, v);
        }
        break;
    case -4:
    case -1:
        break;
    }
    return 0x82;
}
u32 ov14_021EF6D4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x82;
}
u32 ov14_021EF6E4(void *p) {
    ov14_021F40DC(p);
    ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return 0x85;
}
u32 ov14_021EF6FC(void *p) {
    void *blk = PTR_AT(PTR_AT(p, 0x34), 0xc);
    u16 prev;
    u16 held;
    if (sub_020199E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10) != 0) {
        return 0x85;
    }
    if (U16_AT(blk, 0) == U8_AT(p, 0x21)) {
        prev = U16_AT(blk, 2);
        ov14_021F1F38(p);
        ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
        if (ItemIdIsMail(U16_AT(PTR_AT(p, 0x34), 0x88c8)) == 1 && prev != U8_AT(p, 0x21)) {
            PlaySE(0x5f3);
            ov14_021F6730(p, 0x25);
            U32_AT(p, 0x30) = 0x87;
            return 6;
        }
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return 0x82;
    }
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(blk, 0), 0);
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    held = (u16)ov14_021E6070(p, U16_AT(blk, 0), 6, 0);
    ov14_021E6094(p, U16_AT(blk, 0), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U16_AT(blk, 0));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U16_AT(blk, 0), U8_AT((u8 *)PTR_AT(p, 0x34) + U16_AT(blk, 0), 0x4094));
    }
    ov14_021E7588(p, U16_AT(blk, 0));
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)U16_AT(blk, 0));
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = held;
    ov14_021E6094(p, U8_AT(p, 0x21), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21), U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094));
    }
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        U8_AT(p, 0x21) = (u8)U16_AT(blk, 0);
        ov14_021F1F38(p);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return 0x82;
    }
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F39D0(PTR_AT(p, 0x34));
    PlaySE(0x5eb);
    return ov14_021F0234(p, ov14_021EA928, 0x86);
}
u32 ov14_021EF8AC(void *p) {
    void *q = PTR_AT(PTR_AT(p, 0x34), 0xc);
    u16 item;
    u8 old;
    u16 prev;
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(q, 0), 0);
    old = U8_AT(p, 0x21);
    prev = U16_AT(q, 2);
    U8_AT(p, 0x21) = U16_AT(q, 0);
    ov14_021F1F38(p);
    item = U16_AT(PTR_AT(p, 0x34), 0x88c8);
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = 0;
    if (ItemIdIsMail(item) == 1 && prev != old) {
        PlaySE(0x5f3);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
        ov14_021F6730(p, 0x25);
        U32_AT(p, 0x30) = 0x87;
        return 6;
    }
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x82;
}
u32 ov14_021EF920(void *p) {
    ov14_021F6688(PTR_AT(p, 0x34), 0x25);
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x82;
}
u32 ov14_021EF93C(void *p) {
    u32 v = ov14_021F7A50(p);
    if (!GridInputHandler_IsButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c))) {
        v = -2;
    }
    switch (v) {
    case -3:
        PlaySE(0x5dc);
        return ov14_021F0244(p, 0x89);
    case -4:
        PlaySE(0x5dc);
        break;
    case -2:
    case 0x24:
        PlaySE(0x5ea);
        return ov14_021F1C4C(p, 0xff);
    default:
        PlaySE(0x5ea);
        return ov14_021F1C4C(p, v);
    case -1:
        break;
    }
    return 0x88;
}
u32 ov14_021EF9BC(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x88;
}
u32 ov14_021EF9CC(void *p) {
    u16 held;
    u32 n;
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(PTR_AT(p, 0x34), 0x44c), 0);
    if (U8_AT(PTR_AT(p, 0x34), 0x44c) == U16_AT(PTR_AT(p, 0x34), 0x88ca)) {
        U16_AT(PTR_AT(p, 0x34), 0x88c8) = 0;
        ov14_021E7588(p, U8_AT(PTR_AT(p, 0x34), 0x44c));
        ov14_021E8620(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        return ov14_021F0234(p, ov14_021E9970, 0x82);
    }
    held = (u16)ov14_021E6070(p, U8_AT(PTR_AT(p, 0x34), 0x44c), 6, 0);
    ov14_021E6094(p, U8_AT(PTR_AT(p, 0x34), 0x44c), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(PTR_AT(p, 0x34), 0x44c));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U8_AT(PTR_AT(p, 0x34), 0x44c), U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(PTR_AT(p, 0x34), 0x44c), 0x4094));
    }
    ov14_021E7588(p, U8_AT(PTR_AT(p, 0x34), 0x44c));
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = held;
    ov14_021E6094(p, U16_AT(PTR_AT(p, 0x34), 0x88ca), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U16_AT(PTR_AT(p, 0x34), 0x88ca));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U16_AT(PTR_AT(p, 0x34), 0x88ca), U8_AT((u8 *)PTR_AT(p, 0x34) + U16_AT(PTR_AT(p, 0x34), 0x88ca), 0x4094));
    }
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        ov14_021E8620(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        return ov14_021F0234(p, ov14_021E9970, 0x82);
    }
    U8_AT(PTR_AT(p, 0x34), 0x44b) = 1;
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    ov14_021F39A0(PTR_AT(p, 0x34), U8_AT(PTR_AT(p, 0x34), 0x44c), 2);
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    n = ov14_021F5564(p, U16_AT(PTR_AT(p, 0x34), 0x88c8));
    sub_02019A60(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10, (u8 *)PTR_AT(p, 0x34) + 0x30 + n * 16);
    sub_02019A60(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10, (u8 *)PTR_AT(p, 0x34) + 0x30 + (n + 1) * 16);
    ov14_021F38B0(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021EAA04, 0x88);
}
u32 ov14_021EFB64(void *p) {
    u32 v = ov14_021F6A24();
    if (v != -1) {
        if (ov14_021E6070(p, v + 0x1e, 0xac, 0)) {
            PlaySE(0x5eb);
            System_GetTouchNewCoords(&U32_AT(PTR_AT(p, 0x34), 0x40b8), &U32_AT(PTR_AT(p, 0x34), 0x40bc));
            ov14_021E7588(p, v + 0x1e);
            ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
            return ov14_021F1D6C(p, v + 0x1e);
        }
        if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            v = (u8)(U8_AT(p, 0x21) - 0x1e);
            ov14_021F7AC4(PTR_AT(p, 0x34), v, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), v);
            ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021F40DC(p);
            if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
                ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            }
            return ov14_021F0234(p, ov14_021EA674, 0x8c);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)v);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        ov14_021E765C(p);
        return 0x8b;
    }
    v = ov14_021F75C8(p);
    switch (v) {
    case 6:
        PlaySE(0x5dd);
        return ov14_021F2490(p, 0, 0xb0);
    case 8:
        PlaySE(0x5dd);
        return ov14_021F2270(p, 7, 0xad);
    case -3: {
        u32 n = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (n <= 5) {
            ov14_021E7588(p, n + 0x1e);
        } else if (n != 8 && n != 9) {
            ov14_021E765C(p);
        }
        PlaySE(0x5dc);
        return ov14_021F0244(p, 0x8c);
    }
    case 7:
    case -2:
        PlaySE(0x633);
        return ov14_021F2270(p, 0xa, 0x9f);
    case 9:
        PlaySE(0x5dc);
        v = (u8)(U8_AT(p, 0x21) - 0x1e);
        ov14_021F7AC4(PTR_AT(p, 0x34), v, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), v);
        return ov14_021F2270(p, 0xb, 0xb1);
    case -4: {
        u32 n = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
        if (n <= 5) {
            ov14_021E7588(p, n + 0x1e);
        } else if (n != 8 && n != 9) {
            ov14_021E765C(p);
        }
        PlaySE(0x5dc);
        break;
    }
    default:
        if (ov14_021E6070(p, v + 0x1e, 0xac, 0)) {
            PlaySE(0x5dd);
            ov14_021E7588(p, v + 0x1e);
            ov14_021F7AC4(PTR_AT(p, 0x34), 8, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8);
            return ov14_021F1CDC(p, v + 0x1e);
        }
        break;
    case -1:
        break;
    }
    return 0x8b;
}
u32 ov14_021EFDE4(void *p) {
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc));
    return 0x8b;
}
u32 ov14_021EFDF4(void *p) {
    void *blk = PTR_AT(PTR_AT(p, 0x34), 0xc);
    u16 prev;
    if (U16_AT(blk, 0) == U8_AT(p, 0x21) || U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        prev = U16_AT(blk, 2);
        ov14_021F1F38(p);
        if (U8_AT(PTR_AT(p, 0x34), 0x44a) == 0) {
            if (ItemIdIsMail(U16_AT(PTR_AT(p, 0x34), 0x88c8)) == 1 && prev != U8_AT(p, 0x21)) {
                PlaySE(0x5f3);
                sub_0201980C(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 7);
                ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
                ov14_021F68C0(p, 7, 0x28);
                U32_AT(p, 0x30) = 0x92;
                return 6;
            }
        } else {
            ov14_021F6654(PTR_AT(p, 0x34), 0x28);
            U8_AT(PTR_AT(p, 0x34), 0x44a) = 0;
        }
        if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            PlaySE(0x5ea);
            ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        }
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8);
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        return 0x8b;
    }
    ov14_021F6654(PTR_AT(p, 0x34), 0x28);
    PlaySE(0x5ea);
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(blk, 0), 0);
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F40DC(p);
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
    return 0x8e;
}
u32 ov14_021EFF00(void *p) {
    void *blk;
    u16 held;
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 1) {
        return 0x8e;
    }
    ov14_021F391C(PTR_AT(p, 0x34), 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    blk = PTR_AT(PTR_AT(p, 0x34), 0xc);
    held = (u16)ov14_021E6070(p, U16_AT(blk, 0), 6, 0);
    ov14_021E6094(p, U16_AT(blk, 0), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U16_AT(blk, 0));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U16_AT(blk, 0), U8_AT((u8 *)PTR_AT(p, 0x34) + U16_AT(blk, 0), 0x4094));
    }
    ov14_021E7588(p, U16_AT(blk, 0));
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = held;
    ov14_021E6094(p, U8_AT(p, 0x21), 6, &U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21));
    if (ov14_021E64D0() == 1) {
        ov14_021F2ED0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21), U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094));
    }
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        if (U8_AT(PTR_AT(p, 0x34), 0x44a) == 0) {
            U8_AT(p, 0x21) = (u8)U16_AT(blk, 0);
            ov14_021F1F38(p);
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x21) - 0x1e));
            ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            return ov14_021F0234(p, ov14_021E94BC, 0x8f);
        }
        U8_AT(PTR_AT(p, 0x34), 0x44a) = 0;
        ov14_021F1F38(p);
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x21) - 0x1e));
        ov14_021E7EE0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021F3488(p, 1, 1);
        return ov14_021F0234(p, ov14_021E9518, 0x8f);
    }
    PlaySE(0x5eb);
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 1);
    ov14_021F39D0(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EAF08, 0x90);
}
u32 ov14_021F00A0(void *p) {
    ov14_021E7588(p, U8_AT(p, 0x21));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x8b;
}
u32 ov14_021F00BC(void *p) {
    void *q = PTR_AT(PTR_AT(p, 0x34), 0xc);
    ov14_021F34C8(PTR_AT(p, 0x34), U16_AT(q, 0), 0);
    PlaySE(0x5ea);
    ov14_021F40DC(p);
    ov14_021F391C(PTR_AT(p, 0x34), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
    if (U8_AT(p, 0x21) < 0x1e) {
        U8_AT(p, 0x21) = U16_AT(q, 0);
    }
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x21) - 0x1e));
    ov14_021F1F38(p);
    return 0x91;
}
u32 ov14_021F0120(void *p) {
    if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 1) {
        return 0x91;
    }
    ov14_021F391C(PTR_AT(p, 0x34), 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E94BC, 0x8f);
}
u32 ov14_021F0164(void *p) {
    ov14_021F6654(PTR_AT(p, 0x34), 0x28);
    sub_020197F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 7);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8);
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x8b;
}
u32 ov14_021F0198(void *p) {
    PlaySE(0x5f3);
    ov14_021F68C0(p, 5, 0x25);
    U32_AT(p, 0x30) = 0xe;
    return 6;
}
u32 ov14_021F01B8(void *p) {
    PlaySE(0x5f3);
    ov14_021F6724(p, 0x25);
    U32_AT(p, 0x30) = 0xe;
    return 6;
}
u32 ov14_021F01D8(void *p, u32 v) {
    BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0xa);
    U32_AT(PTR_AT(p, 0x34), 0x440) = v;
    return 2;
}
u32 ov14_021F0204(void *p, u32 v) {
    BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0xa);
    U32_AT(PTR_AT(p, 0x34), 0x440) = v;
    return 2;
}
