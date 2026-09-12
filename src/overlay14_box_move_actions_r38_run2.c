#include "overlay14_box_move_actions_r38_private.h"

u32 ov14_021F1808(void *p, u32 value) {
    U8_AT(p, 0x21) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    ov14_021F5FBC(p, U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021E8434(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F396C(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
        ov14_021F39D0(PTR_AT(p, 0x34));
        ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    return ov14_021F0234(p, ov14_021EA408, 0x76);
}

u32 ov14_021F18B0(void *p, u32 value) {
    s16 xy[2];
    u16 oldItem = U16_AT(PTR_AT(p, 0x34), 0x88c8);
    U8_AT(p, 0x21) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    if (ov14_021E8544(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        if (oldItem != 0 || U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            ov14_021E83F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        } else if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
            ov14_021E84A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
    } else {
        ov14_021E8234(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E8294(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        ov14_021E8314(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021F5FBC(p, U16_AT(PTR_AT(p, 0x34), 0x88c8));
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F396C(PTR_AT(p, 0x34), U8_AT(p, 0x21), 0);
        ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
        ov14_021F39D0(PTR_AT(p, 0x34));
        ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
        ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    } else if (ov14_021F2A44(PTR_AT(p, 0x34), 11) == 1) {
        ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
        ov14_021F40DC(p);
    }
    ov14_021F2F88(U8_AT(p, 0x21), &xy[1], &xy[0], 0);
    U32_AT(PTR_AT(p, 0x34), 0x40b8) = xy[1] + 8;
    U32_AT(PTR_AT(p, 0x34), 0x40bc) = xy[0] + 8;
    ov14_021F1F24(p);
    return ov14_021F0234(p, ov14_021EA4C8, 0x7e);
}

u32 ov14_021F19F0(void *p, u32 value) {
    s16 xy[2];
    U8_AT(p, 0x21) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    ov14_021F6408(p, 0);
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
        GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
        if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            return 0x82;
        }
        if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
            ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
        }
        return ov14_021F0234(p, ov14_021E99A0, 0x82);
    }
    PlaySE(0x5eb);
    ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
    ov14_021F396C(PTR_AT(p, 0x34), U8_AT(p, 0x21), 2);
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021F39D0(PTR_AT(p, 0x34));
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (ov14_021E85E4(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E85D0(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    } else if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    ov14_021F2F88(U8_AT(p, 0x21), &xy[1], &xy[0], 2);
    U32_AT(PTR_AT(p, 0x34), 0x40b8) = xy[1] + 8;
    U32_AT(PTR_AT(p, 0x34), 0x40bc) = xy[0] + 8;
    ov14_021F1F24(p);
    return ov14_021F0234(p, ov14_021EA778, 0x84);
}

u32 ov14_021F1B4C(void *p, u32 value) {
    U8_AT(p, 0x21) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88ca) = value;
    U16_AT(PTR_AT(p, 0x34), 0x88c8) = ov14_021E6070(p, U8_AT(p, 0x21), 6, 0);
    if (U16_AT(PTR_AT(p, 0x34), 0x88c8) == 0) {
        return 0x82;
    }
    PlaySE(0x5eb);
    U8_AT(PTR_AT(p, 0x34), 0x44b) = 1;
    ov14_021F2A18(PTR_AT(p, 0x34), 11, 0);
    ov14_021F39A0(PTR_AT(p, 0x34), U8_AT(p, 0x21), 2);
    ov14_021F3844(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88c8));
    ov14_021F34C8(PTR_AT(p, 0x34), U8_AT(p, 0x21), 1);
    ov14_021E88BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    if (ov14_021E8648(PTR_AT(PTR_AT(p, 0x34), 0x2f0)) == 1) {
        ov14_021E8634(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
    return ov14_021F0234(p, ov14_021EAA04, 0x88);
}
