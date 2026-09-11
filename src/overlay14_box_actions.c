#include "overlay14_box_actions_internal.h"

u32 ov14_021F028C(void *p, u32 next);
u32 ov14_021F0314(void *p, u32 next);
u32 ov14_021F039C(void *p, u32 idx);
u32 ov14_021F0418(void *p, u32 idx);
u32 ov14_021F04D4(void *p, u32 idx);
u32 ov14_021F0530(void *p, u32 idx);
u32 ov14_021F0594(void *p, u32 idx);
u32 ov14_021F0660(void *p, u32 idx);
u32 ov14_021F0794(void *p, u32 idx);
u32 ov14_021F07F0(void *p, u32 idx);
u32 ov14_021F083C(void *p, u32 idx);
void ov14_021F08BC(void *p);
void ov14_021F08F0(void *p);
u32 ov14_021F0910(void *p);
u32 ov14_021F09BC(void *p);
u32 ov14_021F0A80(void *p);
u32 ov14_021F0AAC(void *p);
u32 ov14_021F0AD8(void *p);
u32 ov14_021F0B34(void *p);
void ov14_021F0B70(void *p);
void ov14_021F0BB4(void *p);
void ov14_021F0BF4(void *p);
u32 ov14_021F0C0C(void *p);
u32 ov14_021F0C58(void *p);
u32 ov14_021F0C88(void *p);
u32 ov14_021F0CD8(void *p);
u32 ov14_021F0D34(void *p, u32 next);
u32 ov14_021F0D58(void *p, s32 delta);
u32 ov14_021F0EE8(void *p, u32 next);
u32 ov14_021F0F0C(void *p, u32 which);
void ov14_021F1004(void *p, s32 delta);
u32 ov14_021F1058(void *p, u32 next);
u32 ov14_021F1090(void *p, u32 next);
u32 ov14_021F10B4(void *p, u32 next);
u32 ov14_021F10DC(void *p, u32 next);
u32 ov14_021F1100(void *p, u32 next);
void ov14_021F1128(void *p);
u32 ov14_021F1170(void *p, s32 delta);
u32 ov14_021F11F8(void *p, s32 delta);
void ov14_021F1228(void *p, s32 delta);
void ov14_021F129C(void *p, u32 delta);
u32 ov14_021F131C(void *p);
u32 ov14_021F13B0(void *p);
u32 ov14_021F1414(void *p);
u32 ov14_021F1448(void *p, s32 delta);
u32 ov14_021F1504(void *p, s32 delta);

u32 ov14_021F028C(void *p, u32 next) {
    U8_AT(p, 0x1f) = (U8_AT(p, 0x1f) == 0) ? 0x11 : U8_AT(p, 0x1f) - 1;
    ov14_021F2DE8(p, U8_AT(p, 0x1f));
    ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 0);
    ov14_021F29E4(PTR_AT(p, 0x34), 0, 2);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        if (U32_AT(PTR_AT(p, 0), 8) == 2 || U32_AT(PTR_AT(p, 0), 8) == 3) {
            ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
    }
    return ov14_021F0234(p, ov14_021E92AC, next);
}

u32 ov14_021F0314(void *p, u32 next) {
    U8_AT(p, 0x1f) = (U8_AT(p, 0x1f) == 0x11) ? 0 : U8_AT(p, 0x1f) + 1;
    ov14_021F2DE8(p, U8_AT(p, 0x1f));
    ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 1);
    ov14_021F29E4(PTR_AT(p, 0x34), 1, 4);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        if (U32_AT(PTR_AT(p, 0), 8) == 2 || U32_AT(PTR_AT(p, 0), 8) == 3) {
            ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
    }
    return ov14_021F0234(p, ov14_021E9370, next);
}

u32 ov14_021F039C(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F3F6C(p);
    ov14_021F08BC(p);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
        ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    U8_AT(p, 0x22) = 0;
    return ov14_021F0234(p, ov14_021E8BA4, 0xd);
}

u32 ov14_021F0418(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F3F6C(p);
    ov14_021F3044(p);
    ov14_021F3488(p, 1, 1);
    ov14_021F3488(p, 2, 1);
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F685C(p, U8_AT(p, 0x21), 1, 0x27);
    if (Party_GetCount(PTR_AT(p, 8)) != 6) {
        ov14_021F6928(p, 0x28, 1);
    } else {
        ov14_021F6928(p, 0x28, 3);
    }
    ov14_021F08BC(p);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
        ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    U8_AT(p, 0x22) = 2;
    return ov14_021F0234(p, ov14_021E9C88, 0x57);
}

u32 ov14_021F04D4(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F3F6C(p);
    ov14_021F685C(p, U8_AT(p, 0x21), 1, 0x27);
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8824(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EA068, 0x58);
}

u32 ov14_021F0530(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F3F6C(p);
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8824(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EA0B8, 0x4a);
}

u32 ov14_021F0594(void *p, u32 idx) {
    void *mon;
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F3F6C(p);
    mon = Party_GetMonByIndex(PTR_AT(p, 8), idx - 0x1e);
    if (ov14_021E6480(p, idx - 0x1e) == 0 && PCStorage_CountMonsInBox(PTR_AT(p, 4), U8_AT(p, 0x1f)) == 0) {
        ov14_021F6928(p, 0x28, 8);
    } else if (ItemIdIsMail(GetMonData(mon, 6, NULL)) == 1) {
        ov14_021F6928(p, 0x28, 6);
    } else if (GetMonData(mon, 0xa2, NULL) != 0) {
        ov14_021F6928(p, 0x28, 7);
    } else {
        ov14_021F6928(p, 0x28, 0);
    }
    ov14_021F08BC(p);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    U8_AT(p, 0x22) = 1;
    return ov14_021F0234(p, ov14_021E8D20, 0x27);
}

u32 ov14_021F0660(void *p, u32 idx) {
    void *mon;
    u32 i;
    U8_AT(p, 0x21) = idx;
    for (i = 0x1e; i < 0x24; i++) {
        if (i == U8_AT(p, 0x21)) {
            ov14_021F3190(PTR_AT(p, 0x34), i, 0);
        } else {
            ov14_021F3190(PTR_AT(p, 0x34), i, 1);
        }
    }
    ov14_021F3F6C(p);
    ov14_021F3488(p, 2, 1);
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F685C(p, U8_AT(p, 0x21), 1, 0x27);
    mon = Party_GetMonByIndex(PTR_AT(p, 8), idx - 0x1e);
    if (ov14_021E6480(p, idx - 0x1e) == 0) {
        ov14_021F6928(p, 0x28, 8);
    } else if (ItemIdIsMail(GetMonData(mon, 6, NULL)) == 1) {
        ov14_021F6928(p, 0x28, 6);
    } else if (GetMonData(mon, 0xa2, NULL) != 0) {
        ov14_021F6928(p, 0x28, 7);
    } else if (PCStorage_CountEmptySpotsInBox(PTR_AT(p, 4), U8_AT(p, 0x1f)) == 0) {
        ov14_021F6928(p, 0x28, 2);
    } else {
        ov14_021F6928(p, 0x28, 0);
    }
    ov14_021F08BC(p);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
        ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    U8_AT(p, 0x22) = 1;
    return ov14_021F0234(p, ov14_021E9A24, 0x6e);
}

u32 ov14_021F0794(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F3F6C(p);
    ov14_021F685C(p, U8_AT(p, 0x21), 1, 0x27);
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8824(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EA068, 0x6f);
}

u32 ov14_021F07F0(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021F3F6C(p);
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8824(PTR_AT(p, 0x34));
    return ov14_021F0234(p, ov14_021EA0B8, 0x4c);
}

u32 ov14_021F083C(void *p, u32 idx) {
    U8_AT(p, 0x21) = idx;
    ov14_021F3190(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
    ov14_021F3F6C(p);
    if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    } else if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021E8824(PTR_AT(p, 0x34));
    ov14_021F6408(p, 0);
    ov14_021F08BC(p);
    U8_AT(p, 0x22) = 2;
    return ov14_021F0234(p, ov14_021E8FD4, 0x2a);
}

void ov14_021F08BC(void *p) {
    void *buf;
    u32 i;
    void *cur;
    buf = Heap_Alloc(0xa, 0xf0);
    for (i = 0, cur = buf; i < 7; i++, cur = (u8 *)cur + 0x20) {
        PTR_AT(cur, 0) = AllocMonZeroed(0xa);
    }
    U32_AT(buf, 0xe0) = 0;
    PTR_AT(PTR_AT(p, 0x34), 0xc) = buf;
}

void ov14_021F08F0(void *p) {
    void *buf;
    u32 i;
    void *cur;
    buf = PTR_AT(PTR_AT(p, 0x34), 0xc);
    cur = buf;
    for (i = 0; i < 7; i++, cur = (u8 *)cur + 0x20) {
        Heap_Free(PTR_AT(cur, 0));
    }
    Heap_Free(buf);
}

u32 ov14_021F0910(void *p) {
    u32 item;
    if (ov14_021E6070(p, U8_AT(p, 0x21), 0x4c, 0) != 0) {
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        return ov14_021F0234(p, ov14_021E9450, 0x4f);
    }
    item = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    if (item == 0) {
        U32_AT(p, 0x2c) = 0x26;
        return ov14_021F027C(p, 1);
    }
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    if (ItemIdIsMail(item) == 1) {
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        return ov14_021F0234(p, ov14_021E9450, 0x50);
    }
    ov14_021E83F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F6704(p, item, 0x25);
    return ov14_021F0254(p, 0);
}

u32 ov14_021F09BC(void *p) {
    switch (U32_AT(PTR_AT(p, 0), 8)) {
    case 0:
        ov14_021F6AC0(p, 0, 9);
        break;
    case 1:
        ov14_021F6AC0(p, 2, 0x24);
        break;
    case 2:
    default:
        if (U8_AT(p, 0x21) < 0x1e) {
            ov14_021F6AC0(p, 3, 0x27);
        } else {
            ov14_021F6AC0(p, 5, 0xb);
        }
        break;
    }
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021F6654(PTR_AT(p, 0x34), 0x26);
    if (U8_AT(p, 0x24) != 0) {
        ov14_021F57B8(p);
    }
    if (U8_AT(p, 0x21) < 0x1e) {
        ov14_021F3488(p, 1, 0);
    }
    ov14_021F3488(p, 2, 0);
    ov14_021E7E64(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (U32_AT(PTR_AT(p, 0), 8) == 2 && U8_AT(p, 0x21) < 0x1e) {
        return ov14_021F0234(p, ov14_021E94A8, 0x17);
    }
    return ov14_021F0234(p, ov14_021E94A8, 0xe);
}

u32 ov14_021F0A80(void *p) {
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9434, 0x13);
}

u32 ov14_021F0AAC(void *p) {
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9450, 0x19);
}

u32 ov14_021F0AD8(void *p) {
    U8_AT(p, 0x23) = 1;
    ov14_021F43F4(PTR_AT(p, 0x34), 0);
    ov14_021F3488(p, 1, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E94BC, 0x22);
}

u32 ov14_021F0B34(void *p) {
    U8_AT(p, 0x23) = 0;
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
        return ov14_021EC710(p);
    }
    ov14_021E76B8(p);
    return ov14_021F1100(p, 0x25);
}

void ov14_021F0B70(void *p) {
    ov14_021E81A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 1);
    ov14_021F63F0(PTR_AT(p, 0x34));
    ov14_021F63A8(PTR_AT(p, 0x34));
    ov14_021E8368(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E82DC(p);
    ov14_021E7E78(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F30B0(p);
}

void ov14_021F0BB4(void *p) {
    ov14_021E81A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 1);
    ov14_021F63F0(PTR_AT(p, 0x34));
    ov14_021F63B8(PTR_AT(p, 0x34));
    ov14_021E8368(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E7E88(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F311C(p);
}

void ov14_021F0BF4(void *p) {
    ov14_021F30B0(p);
    ov14_021E7E78(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
}

u32 ov14_021F0C0C(void *p) {
    U8_AT(p, 0x21) = 0xff;
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E8020(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    return ov14_021F0234(p, ov14_021E952C, 0x2d);
}

u32 ov14_021F0C58(void *p) {
    U8_AT(p, 0x21) = 0xff;
    ov14_021F3488(p, 1, 1);
    ov14_021E805C(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E954C, 0x2e);
}

u32 ov14_021F0C88(void *p) {
    U8_AT(p, 0x24) = 1;
    U8_AT(p, 0x29) = 0;
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E94BC, 0x2f);
}

u32 ov14_021F0CD8(void *p) {
    U8_AT(p, 0x24) = 0;
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        return ov14_021F0EE8(p, 0x31);
    }
    if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        return ov14_021F0D34(p, 0x31);
    }
    return ov14_021F1090(p, 0x32);
}

u32 ov14_021F0D34(void *p, u32 next) {
    ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9970, next);
}

u32 ov14_021F0D58(void *p, s32 delta) {
    u32 st;
    s32 cur;
    s32 nv;
    u8 x;
    u8 y;
    st = (U32_AT(PTR_AT(p, 0), 8) == 3) ? 0x82 : 0x29;
    cur = U8_AT(p, 0x25);
    nv = delta + cur / 6 * 6;
    if (nv != cur) {
        U8_AT(p, 0x25) = nv;
        ov14_021F48B4(p);
        ov14_021F57B8(p);
    }
    if (U8_AT(p, 0x25) == U8_AT(p, 0x1f)) {
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
            GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
            ov14_021F29E4(PTR_AT(p, 0x34), 9, 0xe);
            return ov14_021F0EE8(p, st);
        }
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6 + 0x25));
            GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
            ov14_021F29E4(PTR_AT(p, 0x34), 9, 0xe);
            ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
            return ov14_021F0234(p, ov14_021E9970, st);
        }
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 0xe);
        return st;
    }
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x2d);
    if (GridInputHandler_IsButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c)) == 1) {
        DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0x2d), &x, &y);
        ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 1);
    }
    if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        return st;
    }
    ov14_021F604C(p);
    if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    return ov14_021F0234(p, ov14_021E9920, st);
}

u32 ov14_021F0EE8(void *p, u32 next) {
    ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9970, next);
}

u32 ov14_021F0F0C(void *p, u32 which) {
    void *cb;
    u32 prev;
    prev = U8_AT(p, 0x1f);
    U8_AT(p, 0x1f) = U8_AT(p, 0x25);
    if (prev > U8_AT(p, 0x25)) {
        ov14_021F2DE8(p, U8_AT(p, 0x1f));
        ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 0);
        cb = ov14_021E92AC;
    } else {
        ov14_021F2DE8(p, U8_AT(p, 0x1f));
        ov14_021E783C(p, ov14_021E7930(p, U8_AT(p, 0x1f)), 1);
        cb = ov14_021E9370;
    }
    switch (which) {
    case 0:
        ov14_021F4848(p);
        if (U8_AT(p, 0x23) == 0) {
            U32_AT(p, 0x30) = 0xc;
        } else {
            U32_AT(p, 0x30) = 0x24;
        }
        break;
    case 1:
        ov14_021F4848(p);
        U32_AT(p, 0x30) = 0x3d;
        break;
    case 2:
        U32_AT(p, 0x30) = 0x47;
        break;
    case 3:
        ov14_021F4848(p);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
        U32_AT(p, 0x30) = 0x29;
        break;
    case 4:
        ov14_021F4848(p);
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
        U32_AT(p, 0x30) = 0x82;
        break;
    }
    return ov14_021F0234(p, cb, U32_AT(p, 0x30));
}

void ov14_021F1004(void *p, s32 delta) {
    s32 v;
    v = U8_AT(p, 0x25) + delta * 6;
    if (v < 0) {
        v += 0x12;
    } else if (v >= 0x12) {
        v -= 0x12;
    }
    U8_AT(p, 0x25) = v;
    ov14_021F49E0(p);
    ov14_021F48B4(p);
    ov14_021F4848(p);
    ov14_021F57B8(p);
    if (delta > 0) {
        ov14_021F29E4(PTR_AT(p, 0x34), 5, 4);
    } else {
        ov14_021F29E4(PTR_AT(p, 0x34), 4, 2);
    }
}

u32 ov14_021F1058(void *p, u32 next) {
    ov14_021F4720(p);
    ov14_021F4848(p);
    ov14_021F48B4(p);
    ov14_021F57B8(p);
    ov14_021E86E0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9554, next);
}

u32 ov14_021F1090(void *p, u32 next) {
    ov14_021E8704(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9590, next);
}

u32 ov14_021F10B4(void *p, u32 next) {
    ov14_021F5EC4(p, 0);
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E95B4, next);
}

u32 ov14_021F10DC(void *p, u32 next) {
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E95B4, next);
}

u32 ov14_021F1100(void *p, u32 next) {
    U8_AT(p, 0x21) = 0xff;
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9434, next);
}

void ov14_021F1128(void *p) {
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    U32_AT(PTR_AT(p, 0x34), 0x43c) = U8_AT(p, 0x1f) % 6;
    U32_AT(p, 0x2c) = U32_AT(PTR_AT(p, 0x34), 0x43c);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 0) {
        ov14_021ED5B0(p);
    } else {
        ov14_021F1100(p, 0x35);
    }
}

u32 ov14_021F1170(void *p, s32 delta) {
    s32 v;
    u8 x;
    u8 y;
    U8_AT(p, 0x25) = delta + U8_AT(p, 0x25) / 6 * 6;
    ov14_021F48B4(p);
    ov14_021F57B8(p);
    v = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
    U32_AT(PTR_AT(p, 0x34), 0x43c) = v;
    GridInputHandler_SetNextLastUnk0FInputs(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8, v, v);
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 1);
    return 0x3d;
}

u32 ov14_021F11F8(void *p, s32 delta) {
    ov14_021F1004(p, delta);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x3d;
}

void ov14_021F1228(void *p, s32 delta) {
    s32 v;
    v = U8_AT(PTR_AT(p, 0x34), 0x44d) + delta * 4;
    if (v < 0) {
        v += 0x18;
    } else if (v >= 0x18) {
        v -= 0x18;
    }
    U8_AT(PTR_AT(p, 0x34), 0x44d) = v;
    if (delta > 0) {
        ov14_021F29E4(PTR_AT(p, 0x34), 5, 4);
    } else {
        ov14_021F29E4(PTR_AT(p, 0x34), 4, 2);
    }
    ov14_021F462C(p);
    ov14_021F4530(p);
    ov14_021F58B8(p);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(PTR_AT(p, 0x34), 0x44d) % 4));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
}

void ov14_021F129C(void *p, u32 delta) {
    u8 x;
    u8 y;
    U8_AT(PTR_AT(p, 0x34), 0x44d) = delta + U8_AT(PTR_AT(p, 0x34), 0x44d) / 4 * 4;
    ov14_021F459C(p);
    ov14_021F58B8(p);
    U32_AT(PTR_AT(p, 0x34), 0x43c) = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
    ((void (*)(void *, s32, u8, u8))GridInputHandler_SetNextLastUnk0FInputs)(
        PTR_AT(PTR_AT(p, 0x34), 0x2c),
        6,
        (u8)U32_AT(PTR_AT(p, 0x34), 0x43c),
        (u8)U32_AT(PTR_AT(p, 0x34), 0x43c));
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), 6), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 1);
}

u32 ov14_021F131C(void *p) {
    if (U8_AT(PTR_AT(p, 0x34), 0x44d) >= 0x10
        && PCStorage_IsBonusWallpaperUnlocked(PTR_AT(p, 4), U8_AT(PTR_AT(p, 0x34), 0x44d) - 0x10) == 0) {
        PlaySE(0x5f3);
        return ov14_021F2270(p, 0xc, 0x42);
    }
    if (U8_AT(PTR_AT(p, 0x34), 0x44d) == ov14_021E7930(p, U8_AT(p, 0x25))) {
        PlaySE(0x5f3);
        return ov14_021F2270(p, 0xc, 0x42);
    }
    if (U8_AT(p, 0x25) != U8_AT(p, 0x1f)) {
        PlaySE(0x5dc);
        return ov14_021F2270(p, 0xc, 0xa5);
    }
    PlaySE(0x5dd);
    return ov14_021F2270(p, 0xc, 0x47);
}

u32 ov14_021F13B0(void *p) {
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    if (Party_GetCount(PTR_AT(p, 8)) != 6) {
        ov14_021F6654(PTR_AT(p, 0x34), 0x27);
        ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E884C(PTR_AT(p, 0x34));
        return ov14_021F0234(p, ov14_021E9434, 0x53);
    }
    ov14_021E83F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F685C(p, 0, 2, 0x25);
    U32_AT(p, 0x30) = 0xe;
    return 6;
}

u32 ov14_021F1414(void *p) {
    ov14_021F6654(PTR_AT(p, 0x34), 0x27);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9450, 0x5c);
}

u32 ov14_021F1448(void *p, s32 delta) {
    s32 v;
    u8 x;
    u8 y;
    U8_AT(p, 0x25) = delta + U8_AT(p, 0x25) / 6 * 6;
    if (System_GetTouchNew() == 0) {
        if (PCStorage_CountMonsAndEggsInBox(PTR_AT(p, 4), U8_AT(p, 0x25)) == 0x1e) {
            PlaySE(0x5f3);
        } else {
            PlaySE(0x5dd);
        }
        return 0x66;
    }
    PlaySE(0x5dd);
    ov14_021F48B4(p);
    ov14_021F57B8(p);
    v = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
    U32_AT(PTR_AT(p, 0x34), 0x43c) = v;
    GridInputHandler_SetNextLastUnk0FInputs(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8, v, v);
    DpadMenuBox_GetPosition(GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(p, 0x34), 0x2c), 8), &x, &y);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), x, y);
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 1);
    return 0x61;
}

u32 ov14_021F1504(void *p, s32 delta) {
    ov14_021F1004(p, delta);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), (u8)(U8_AT(p, 0x25) % 6));
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x61;
}
