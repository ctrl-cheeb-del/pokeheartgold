#include "overlay14_box_ui_actions_internal.h"

void ov14_021E8294(void *p) {
    sub_020198FC(p, 9, 0, 1, 3);
}

void ov14_021E82A8(void *p) {
    sub_020198FC(p, 9, 0, -1, 3);
}

void ov14_021E82BC(void *p) {
    ov14_021F5EB4(p, 0);
    sub_020196E8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa, 0x18, 0x15);
}

void ov14_021E82DC(void *p) {
    ov14_021F5EC4(p, 0);
    sub_020196E8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa, 0x18, 0x15);
}

void ov14_021E82FC(void *p) {
    sub_0201980C(p, 0xa);
    sub_020196E8(p, 0xa, 0x18, 0x18);
}

void ov14_021E8314(void *p) {
    sub_020198FC(p, 0xa, 0, 1, 3);
}

void ov14_021E8328(void *p) {
    sub_020196E8(p, 0xa, 0x18, 0x18);
    sub_020198FC(p, 0xa, 0, -1, 3);
}

u32 ov14_021E834C(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 0xb, &x, &y);
    return y == 0x15;
}

void ov14_021E8368(void *p) {
    sub_0201980C(p, 8);
    sub_0201980C(p, 9);
    sub_020196E8(p, 8, 0, 0x18);
    sub_020196E8(p, 9, 0xc, 0x18);
}

void ov14_021E8394(void *p) {
    u32 i;
    s32 v;
    for (i = 0, v = 5; i < 5; i++, v += 3) {
        sub_020196E8(p, i + 3, 0x20, (s8)v);
    }
    sub_020196E8(p, 0xb, 0x18, 0x18);
}

void ov14_021E83C4(void *p) {
    u32 i;
    s32 v;
    for (i = 0, v = 5; i < 5; i++, v += 3) {
        sub_020196E8(p, i + 3, 0x15, (s8)v);
    }
    sub_020196E8(p, 0xb, 0x18, 0x15);
}

void ov14_021E83F4(void *p) {
    u32 i;
    s32 v;
    for (i = 0, v = 5; i < 5; i++, v += 3) {
        sub_0201980C(p, i + 3);
        sub_020196E8(p, i + 3, 0x20, (s8)v);
    }
    sub_0201980C(p, 0xb);
    sub_020196E8(p, 0xb, 0x18, 0x18);
}

void ov14_021E8434(void *p) {
    u16 i;
    s8 x;
    s8 y;
    sub_02019B1C(p, 3, &x, &y);
    if (x == 0x15) {
        return;
    }
    for (i = 0; i < 5; i++) {
        sub_020198FC(p, i + 3, -1, 0, (u8)(x - 0x15));
    }
    sub_02019B1C(p, 0xb, &x, &y);
    sub_020198FC(p, 0xb, 0, -1, (u8)(y - 0x15));
}

void ov14_021E84A4(void *p) {
    u16 i;
    s8 x;
    s8 y;
    sub_02019B1C(p, 3, &x, &y);
    if (x == 0x20) {
        return;
    }
    for (i = 0; i < 5; i++) {
        sub_020198FC(p, i + 3, 1, 0, (u8)(0x20 - x));
    }
    sub_02019B1C(p, 0xb, &x, &y);
    sub_020198FC(p, 0xb, 0, 1, (u8)(0x18 - y));
}

u32 ov14_021E8514(void *p) {
    u32 i;
    u32 ret = FALSE;
    for (i = 0; i < 5; i++) {
        if (sub_02019978(p, i + 3) == TRUE) {
            ret = TRUE;
        }
    }
    if (sub_02019978(p, 0xb) == TRUE) {
        ret = TRUE;
    }
    return ret;
}

u32 ov14_021E8544(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 3, &x, &y);
    return x != 0x20;
}

void ov14_021E8560(void *p) {
    sub_020196E8(p, 0xc, 0x20, 0xe);
    sub_020198FC(p, 0xc, -1, 0, 0xb);
}

void ov14_021E8588(void *p) {
    sub_020196E8(p, 0xc, 0x15, 0xe);
    sub_020198FC(p, 0xc, 1, 0, 0xb);
}

void ov14_021E85AC(void *p) {
    sub_020196E8(p, 0xe, 0, 0x18);
}

void ov14_021E85BC(void *p) {
    sub_020198FC(p, 0xe, 0, -1, 3);
}

void ov14_021E85D0(void *p) {
    sub_020198FC(p, 0xe, 0, 1, 3);
}

u32 ov14_021E85E4(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 0xe, &x, &y);
    return y == 0x15;
}

void ov14_021E8600(void *p) {
    sub_020196E8(p, 0xf, 0, 0x18);
}

void ov14_021E8610(void *p) {
    sub_020196E8(p, 0xf, 0, 0x15);
}

void ov14_021E8620(void *p) {
    sub_020198FC(p, 0xf, 0, -1, 3);
}

void ov14_021E8634(void *p) {
    sub_020198FC(p, 0xf, 0, 1, 3);
}

u32 ov14_021E8648(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 0xf, &x, &y);
    return y == 0x15;
}

void ov14_021E8664(void *p) {
    ov14_021E82DC(p);
    sub_0201980C(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    sub_0201980C(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    sub_020196E8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8, 0, 0x18);
    sub_020196E8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9, 0xc, 0x18);
    sub_020196E8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0, 0, 0);
    ov14_021F57B8(p);
    ov14_021F4720(p);
    ov14_021F4848(p);
    ov14_021F48B4(p);
    ov14_021F47B8(p, 0x30);
}

void ov14_021E86E0(void *p) {
    sub_020196E8(p, 0, 0, -6);
    sub_020198FC(p, 0, 0, 1, 6);
}

void ov14_021E8704(void *p) {
    sub_020198FC(p, 0, 0, -1, 6);
}

void ov14_021E8718(void *p) {
    sub_020196E8(p, 0xc, 0x15, 8);
    sub_020196E8(p, 6, 0x15, 0xe);
    sub_020196E8(p, 7, 0x15, 0x11);
}

void ov14_021E8740(void *p) {
    ov14_021E8664(p);
    ov14_021F6070(p);
    ov14_021E8718(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
}

void ov14_021E875C(void *p) {
    sub_020196E8(p, 0xc, 0x20, 8);
    sub_020196E8(p, 6, 0x20, 0xe);
    sub_020196E8(p, 7, 0x20, 0x11);
    sub_020198FC(p, 0xc, -1, 0, 0xb);
    sub_020198FC(p, 6, -1, 0, 0xb);
    sub_020198FC(p, 7, -1, 0, 0xb);
}

void ov14_021E87BC(void *p) {
    sub_020198FC(p, 0xc, 1, 0, 0xb);
    sub_020198FC(p, 6, 1, 0, 0xb);
    sub_020198FC(p, 7, 1, 0, 0xb);
}

void ov14_021E87F4(void *p) {
    sub_0201980C(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    sub_0201980C(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    ov14_021E821C(p);
    ov14_021E827C(p);
}

void ov14_021E8824(void *p) {
    if (((u32)U8_AT(p, 0x44e) << 25) >> 29) {
        sub_020198FC(PTR_AT(p, 0x2f0), 0x10, -1, 0, 0xc);
    }
}

void ov14_021E884C(void *p) {
    if (((u32)U8_AT(p, 0x44e) << 25) >> 29) {
        sub_020198FC(PTR_AT(p, 0x2f0), 0x10, 1, 0, 0xc);
    }
}

void ov14_021E8874(void *p) {
    if (((u32)U8_AT(p, 0x44e) << 25) >> 29) {
        sub_0201980C(PTR_AT(p, 0x2f0), 0x10);
        sub_020196E8(PTR_AT(p, 0x2f0), 0x10, 0x14, 0xc);
    }
}

void ov14_021E88A4(void *p) {
    sub_0201980C(p, 0x10);
    sub_020196E8(p, 0x10, 0x20, 0xc);
}

void ov14_021E88BC(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 0x10, &x, &y);
    if (y != 0xf) {
        sub_020198FC(p, 0x10, 0, -1, (u8)(9 - (0x18 - y)));
    }
}

void ov14_021E88F8(void *p) {
    s8 x;
    s8 y;
    sub_02019B1C(p, 0x10, &x, &y);
    if (y != 0x18) {
        sub_020198FC(p, 0x10, 0, 1, (u8)(0x18 - y));
    }
}

void ov14_021E892C(void *p) {
    sub_0201980C(p, 0x10);
    sub_020196E8(p, 0x10, 0, 0xf);
}

void ov14_021E8944(void *p) {
    sub_0201980C(p, 0x10);
    sub_020196E8(p, 0x10, 0, 0x18);
}

void ov14_021E895C(void *p, u32 mask) {
    u16 i;
    u16 v;
    for (i = 0; i < 6; i++) {
        if ((1 << i) & mask) {
            v = i + 0x3a;
        } else {
            v = i + 0x1a;
        }
        FillBgTilemapRect(PTR_AT(PTR_AT(p, 0x34), 0x14), 5, v, (u8)(i + 0xf), 0x12, 1, 1, 0);
    }
    ScheduleBgTilemapBufferTransfer(PTR_AT(PTR_AT(p, 0x34), 0x14), 5);
}

u32 ov14_021E89B8(void *p) {
    void *w;
    PTR_AT(p, 0x18) = Heap_Alloc(9, 0x3c);
    w = PTR_AT(p, 0x18);
    if (U8_AT(p, 0x21) < 0x1e) {
        PTR_AT(w, 0) = ov14_021E60C0(p, U8_AT(p, 0x1f), 0);
        U8_AT(w, 0x11) = 2;
        U8_AT(w, 0x13) = 0x1e;
        U8_AT(w, 0x14) = U8_AT(p, 0x21);
    } else {
        PTR_AT(w, 0) = PTR_AT(p, 8);
        U8_AT(w, 0x11) = 1;
        U8_AT(w, 0x13) = Party_GetCount(PTR_AT(p, 8));
        U8_AT(w, 0x14) = U8_AT(p, 0x21) - 0x1e;
    }
    PTR_AT(w, 4) = PTR_AT(p, 0x10);
    sub_0208AD34(w, Save_PlayerData_GetProfile(PTR_AT(PTR_AT(p, 0), 0)));
    U8_AT(w, 0x12) = 0;
    sub_02089D40(w, ov14_021F7D0C);
    U8_AT(w, 0x16) = 0;
    U8_AT(w, 0x17) = 0;
    U16_AT(w, 0x18) = 0;
    U32_AT(w, 0x1c) = SaveArray_IsNatDexEnabled(PTR_AT(PTR_AT(p, 0), 0));
    PTR_AT(w, 0x20) = Save_SpecialRibbons_Get(PTR_AT(PTR_AT(p, 0), 0));
    U32_AT(w, 0x24) = 0;
    U32_AT(w, 0x28) = 0;
    PTR_AT(w, 0x2c) = sub_02088288(PTR_AT(PTR_AT(p, 0), 0));
    PTR_AT(w, 0x34) = sub_0208828C(PTR_AT(PTR_AT(p, 0), 0));
    PTR_AT(w, 0x30) = PTR_AT(PTR_AT(p, 0), 4);
    PTR_AT(p, 0x14) = OverlayManager_New(gOverlayTemplate_PokemonSummary, w, 9);
    return 0;
}

u32 ov14_021E8A7C(void *p) {
    void *w = PTR_AT(p, 0x18);
    if (U8_AT(p, 0x27) == 0) {
        if (U8_AT(p, 0x21) < 0x1e) {
            U8_AT(p, 0x21) = U8_AT(w, 0x14);
        } else {
            U8_AT(p, 0x21) = U8_AT(w, 0x14) + 0x1e;
        }
    }
    if (U8_AT(p, 0x21) < 0x1e && U32_AT(w, 0x38) == 1) {
        PCStorage_SetBoxModified(PTR_AT(p, 4), U8_AT(p, 0x1f));
    }
    Heap_Free(PTR_AT(p, 0x18));
    return 0;
}

u32 ov14_021E8ACC(void *p) {
    PTR_AT(p, 0x18) = Bag_CreateView(Save_Bag_Get(PTR_AT(PTR_AT(p, 0), 0)), ov14_021F7D14, 9);
    sub_0207789C(PTR_AT(p, 0x18), PTR_AT(PTR_AT(p, 0), 0), 1, 0, PTR_AT(PTR_AT(p, 0), 4));
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_15), 2);
    PTR_AT(p, 0x14) = OverlayManager_New(ov15_022008B8, PTR_AT(p, 0x18), 9);
    return 0;
}

u32 ov14_021E8B1C(void *p) {
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_15));
    U16_AT(p, 0x1c) = BagView_GetItemId(PTR_AT(p, 0x18));
    Heap_Free(PTR_AT(p, 0x18));
    return 0;
}

u32 ov14_021E8B3C(void *p) {
    PTR_AT(p, 0x18) = NamingScreen_CreateArgs(9, 2, 0, 8, PTR_AT(p, 0x10), PTR_AT(PTR_AT(p, 0), 4));
    PCStorage_GetBoxName(PTR_AT(p, 4), U8_AT(p, 0x25), PTR_AT(PTR_AT(p, 0x18), 0x18));
    PTR_AT(p, 0x14) = OverlayManager_New(gOverlayTemplate_NamingScreen, PTR_AT(p, 0x18), 9);
    return 0;
}

u32 ov14_021E8B80(void *p) {
    void *w = PTR_AT(p, 0x18);
    PCStorage_SetBoxName(PTR_AT(p, 4), U8_AT(p, 0x25), PTR_AT(w, 0x18));
    U16_AT(p, 0x1c) = U32_AT(w, 0x14);
    NamingScreen_DeleteArgs(PTR_AT(p, 0x18));
    return 0;
}

u32 ov14_021E8BA4(void *p) {
    u32 x;
    u32 y;
    u32 c;
    u32 d;
    void *q = PTR_AT(p, 0x34);
    u32 a = ov14_021E8514(PTR_AT(q, 0x2f0));
    u32 b = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    c = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    d = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (System_GetTouchHeldCoords(&x, &y) == 0) {
            a = 0xff;
            if (U8_AT(p, 0x24) != 0) {
                a = ov14_021E79D8(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc));
            }
            if (a == 0xff) {
                a = ov14_021E7960(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc));
            }
            ov14_021E6CF8(p, U8_AT(p, 0x21), a);
            ov14_021F40E8(p, 0);
            if (!(a & 0x80)) {
                U8_AT(p, 0x21) = ov14_021E70B0(p, U8_AT(p, 0x21));
            }
            ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8824(PTR_AT(p, 0x34));
            U16_AT(q, 0x10) = 1;
        } else {
            ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc), x, (s16)y - 8);
            ov14_021F4174(p);
            U32_AT(PTR_AT(p, 0x34), 0x40b8) = x;
            U32_AT(PTR_AT(p, 0x34), 0x40bc) = y;
        }
        break;
    case 1:
        if (ov14_021E65C4(p) == 0 && a == 0 && b == 0 && c == 0 && d == 0) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            ov14_021F4174(p);
            ov14_021F40E8(p, U32_AT(PTR_AT(p, 0x34), 0x40c4));
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021E8D20(void *p) {
    s16 sx;
    s16 sy;
    u32 x;
    u32 y;
    void *q = PTR_AT(p, 0x34);
    u32 a = ov14_021E8514(PTR_AT(q, 0x2f0));
    u32 b;
    if (U16_AT(q, 0x10) == 0) {
        ManagedSprite_GetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc), &sx, &sy);
    }
    b = ov14_021E80A8(p);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (U8_AT(PTR_AT(p, 0x34), 0x44a) == 1 && b == 0) {
            U8_AT(PTR_AT(p, 0x34), 0x44a) = 2;
            ov14_021F69F0(p, 0x28);
            ov14_021F3488(p, 1, 0);
        }
        if (System_GetTouchHeldCoords(&x, &y) == 0) {
            u32 r;
            ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc), sx, sy);
            if (U8_AT(PTR_AT(p, 0x34), 0x44a) == 2) {
                r = ov14_021E7960(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc));
            } else {
                r = ov14_021E79AC(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc), ov14_021F7BF0);
            }
            ov14_021E6CF8(p, U8_AT(p, 0x21), r);
            ov14_021F40E8(p, 0);
            U8_AT(p, 0x21) = ov14_021E70B0(p, U8_AT(p, 0x21));
            if (U8_AT(p, 0x21) < 0x1e) {
                U32_AT(PTR_AT(p, 0x34), 0x40c4) = 0;
            } else {
                U32_AT(PTR_AT(p, 0x34), 0x40c4) = 1;
            }
            if (U8_AT(p, 0x21) < 0x1e) {
                if (ov14_021E6070(p, U8_AT(p, 0x21), 0xac, 0) == 0) {
                    U16_AT(q, 0x10) = 3;
                    break;
                }
                ov14_021E7EE0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
                ov14_021E7588(p, 0xff);
                U16_AT(q, 0x10) = 1;
                break;
            }
            ov14_021E7FEC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E8824(PTR_AT(p, 0x34));
            U16_AT(q, 0x10) = 1;
            break;
        }
        if (a == 0 && U8_AT(PTR_AT(p, 0x34), 0x44a) == 0 && (x < 0x10 || y < 0x30 || x >= 0x68)) {
            U8_AT(PTR_AT(p, 0x34), 0x44a) = 1;
            ov14_021E7FB8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
        ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc), x, (s16)y - 8);
        ov14_021F4174(p);
        U32_AT(PTR_AT(p, 0x34), 0x40b8) = x;
        U32_AT(PTR_AT(p, 0x34), 0x40bc) = y;
        break;
    case 1:
    case 2:
        if (ov14_021E6814(p) == 0 && a == 0 && b == 0) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            if (U8_AT(p, 0x21) < 0x1e) {
                U8_AT(p, 0x21) = 0xff;
            }
            ov14_021F4174(p);
            ov14_021F40E8(p, U32_AT(PTR_AT(p, 0x34), 0x40c4));
            U16_AT(q, 0x10) = 5;
        }
        break;
    case 3:
        if (ov14_021E66F4(p) == 0) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            ov14_021E7EE0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E7588(p, 0xff);
            U8_AT(p, 0x21) = 0xff;
            U16_AT(q, 0x10)
            ++;
        }
        break;
    case 4:
        if (b == 0) {
            U16_AT(q, 0x10) = 5;
        }
        break;
    case 5:
        ov14_021F3488(p, 1, 1);
        U8_AT(PTR_AT(p, 0x34), 0x44a) = 0;
        U16_AT(q, 0x10) = 0;
        return 0;
    }
    return 1;
}

u32 ov14_021E8FD4(void *p) {
    u32 x;
    u32 y;
    void *q = PTR_AT(p, 0x34);
    u32 a = sub_02019978(PTR_AT(q, 0x2f0), 0xe);
    u32 b = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xf);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (System_GetTouchHeldCoords(&x, &y) == 0) {
            a = 0xff;
            if (U8_AT(p, 0x24) != 0) {
                a = ov14_021E79D8(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc));
            }
            if (a == 0xff) {
                a = ov14_021E7960(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc));
            }
            if (a == 0xff) {
                a = ov14_021E79AC(U32_AT(PTR_AT(p, 0x34), 0x40b8), U32_AT(PTR_AT(p, 0x34), 0x40bc), ov14_021F7C08);
            }
            ov14_021E6CF8(p, U8_AT(p, 0x21), a);
            ov14_021F40E8(p, 0);
            if (!(a & 0x80)) {
                U8_AT(p, 0x21) = ov14_021E70B0(p, U8_AT(p, 0x21));
            }
            ov14_021E884C(PTR_AT(p, 0x34));
            U16_AT(q, 0x10)
            ++;
        } else {
            ManagedSprite_SetPositionXY(PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc), x, (s16)y - 8);
            ov14_021F4174(p);
            U32_AT(PTR_AT(p, 0x34), 0x40b8) = x;
            U32_AT(PTR_AT(p, 0x34), 0x40bc) = y;
        }
        break;
    case 1:
        if (a == 0 && b == 0) {
            void *m = PTR_AT(q, 0xc);
            if (U32_AT(m, 0xe8) != 0xff && (U32_AT(m, 0xe8) & 0x80)) {
                if (U32_AT(m, 0xe4) >= 0x1e && U32_AT(m, 0xe4) - 0x1e < (u32)(Party_GetCount(PTR_AT(p, 8)) - 1)) {
                    ov14_021E8620(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
                }
            } else {
                ov14_021E8620(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            }
            U16_AT(q, 0x10)
            ++;
        }
        /* fallthrough */
    case 2:
        if (ov14_021E65C4(p) == 0 && b == 0 && U16_AT(q, 0x10) == 2) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            ov14_021F4174(p);
            ov14_021F40E8(p, 0);
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021E9194(void *p) {
    void *q = PTR_AT(p, 0x34);
    sub_02019978(PTR_AT(q, 0x2f0), 0xa);
    switch (U16_AT(q, 0x10)) {
    case 0:
        ov14_021E70E0(p, U8_AT(p, 0x21));
        U16_AT(q, 0x10)
        ++;
        /* fallthrough */
    case 1:
        if (ov14_021E65C4(p) == 0) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021E91E0(void *p) {
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0: {
        u32 n = Party_GetCount(PTR_AT(p, 8)) + 0x1e;
        ov14_021E6CF8(p, U8_AT(p, 0x21), n);
        ov14_021F40E8(p, 0);
        U16_AT(q, 0x10)
        ++;
        break;
    }
    case 1:
        if (ov14_021E65C4(p) == 0) {
            ov14_021E7148(p, PTR_AT(q, 0xc));
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021E9234(void *p) {
    int slotno;
    int boxno;
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0:
        boxno = U8_AT(p, 0x1f);
        slotno = 0;
        PCStorage_FindFirstEmptySlot(PTR_AT(p, 4), &boxno, &slotno);
        ov14_021E6CF8(p, U8_AT(p, 0x21), slotno);
        ov14_021F40E8(p, 0);
        U8_AT(p, 0x21) = 0xff;
        U16_AT(q, 0x10)
        ++;
        break;
    case 1:
        if (ov14_021E65C4(p) == 0) {
            void *m = PTR_AT(q, 0xc);
            ov14_021F34C8(PTR_AT(p, 0x34), U32_AT(m, 0xe4), 1);
            ov14_021E7148(p, m);
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021E92AC(void *p) {
    u32 a;
    u32 b;
    if (U16_AT(PTR_AT(p, 0x34), 0x12) == 0x17) {
        if (GridInputHandler_IsButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c)) == 1) {
            GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        }
        U16_AT(PTR_AT(p, 0x34), 0x12) = 0;
        U16_AT(PTR_AT(p, 0x34), 0x10) = 0;
        return 0;
    }
    ScheduleSetBgPosText(PTR_AT(PTR_AT(p, 0x34), 0x14), 3, 2, 8);
    ov14_021F3210(p, 8);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xe);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    a = sub_020199E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xb);
    ov14_021E8514(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    b = sub_020199E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xb);
    if (a == 1 && b == 0) {
        ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    U16_AT(PTR_AT(p, 0x34), 0x12)
    ++;
    return 1;
}

u32 ov14_021E9370(void *p) {
    u32 a;
    u32 b;
    if (U16_AT(PTR_AT(p, 0x34), 0x12) == 0x17) {
        if (GridInputHandler_IsButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c)) == 1) {
            GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        }
        U16_AT(PTR_AT(p, 0x34), 0x12) = 0;
        U16_AT(PTR_AT(p, 0x34), 0x10) = 0;
        return 0;
    }
    ScheduleSetBgPosText(PTR_AT(PTR_AT(p, 0x34), 0x14), 3, 1, 8);
    ov14_021F3210(p, -8);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xe);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    a = sub_020199E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xb);
    ov14_021E8514(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    b = sub_020199E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xb);
    if (a == 1 && b == 0) {
        ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    U16_AT(PTR_AT(p, 0x34), 0x12)
    ++;
    return 1;
}

u32 ov14_021E9434(void *p) {
    if (ov14_021E8514(PTR_AT(PTR_AT(p, 0x34), 0x2f0))) {
        return 1;
    }
    return 0;
}

u32 ov14_021E9450(void *p) {
    u32 a = ov14_021E8514(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    u32 b = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 8);
    u32 c = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
    u32 d = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa);
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        return 0;
    }
    return 1;
}
