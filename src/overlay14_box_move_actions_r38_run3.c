#include "overlay14_box_move_actions_r38_private.h"

u32 ov14_021F1C4C(void *p, u32 value) {
    s16 xy[2];
    U8_AT(PTR_AT(p, 0x34), 0x44c) = value;
    U8_AT(PTR_AT(p, 0x34), 0x44b) = 0;
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), (s32 *)&xy[1], (s32 *)&xy[0]);
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x328), xy[1], (s16)(xy[0] + 8));
    if (U8_AT(PTR_AT(p, 0x34), 0x44c) == 0xff) {
        return ov14_021F1C04(p);
    }
    if (ov14_021E6AA0(p, U8_AT(p, 0x21), value) == 0) {
        return ov14_021F1C04(p);
    }
    ov14_021E88F8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021EAB54, 0x8a);
}

u32 ov14_021F1CDC(void *p, u32 value) {
    U8_AT(p, 0x21) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    ov14_021F5FBC(p, U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F396C(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
        ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
        ov14_021F39D0(PTR_AT(p, 0x34));
        ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    return ov14_021F0234(p, ov14_021EA408, 0x8c);
}

u32 ov14_021F1D6C(void *p, u32 value) {
    s16 xy[2];
    u16 oldItem;
    U8_AT(p, 0x21) = value;
    oldItem = U16_AT(PTR_AT(p, 0x34), 0x88c8);
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        if (oldItem != 0 || U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            ov14_021E83F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        } else if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
    } else {
        ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021F5FBC(p, U16_AT(PTR_AT(p, 0x34), 0x88c8));
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F396C(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
        ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
        ov14_021F39D0(PTR_AT(p, 0x34));
        ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
        ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        if (ItemIdIsMail(U16_AT(PTR_AT(p, 0x34), 0x88c8)) == 1) {
            ov14_021F6928(p, 0x28, 9);
        } else {
            ov14_021F6928(p, 0x28, 10);
        }
    } else if (ov14_021F2A44(PTR_AT(p, 0x34), 11) == 1) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F40DC(p);
    }
    ov14_021F2F88(U8_AT(p, 0x21), &xy[1], &xy[0], 1);
    U32_AT(PTR_AT(p, 0x34), 0x40b8) = xy[1] + 8;
    U32_AT(PTR_AT(p, 0x34), 0x40bc) = xy[0] + 8;
    ov14_021F1F24(p);
    return ov14_021F0234(p, ov14_021EACD4, 0x8d);
}

void ov14_021F1EB8(void *p) {
    u32 next;
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        void *boxMon;
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
        boxMon = (void *)ov14_021E60C0(p, U8_AT(p, 0x1f), U8_AT(p, 0x21));
        if (GetBoxMonData(boxMon, 0x4c, NULL) == 0) {
            U32_AT(p, 0x2c) = 0x24;
            ov14_021F027C(p, 1);
            return;
        }
        next = 0x7c;
    } else {
        ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
        next = 0x78;
    }
    ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F0234(p, ov14_021E9450, next);
}
