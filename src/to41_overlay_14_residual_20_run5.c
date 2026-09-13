#include "to41_overlay_14_residual_20_private.h"

u32 ov14_021E9618(void *p);
u32 ov14_021E9660(void *p);
void ov14_021E96A8(void *p);
u32 ov14_021E98AC(void *p);
u32 ov14_021E9920(void *p);
u32 ov14_021E9970(void *p);
u32 ov14_021E99A0(void *p);
u32 ov14_021E99F0(void *p);
u32 ov14_021EAF8C(void *p, u32 *state);

u32 ov14_021EB170(void *p);
u32 ov14_021EA068(void *p);
u32 ov14_021EA130(void *p);
u32 ov14_021EA728(void *p);
void ov14_021EA1F0(void *p);
u32 ov14_021EA0B8(void *p);
u32 ov14_021EA180(void *p);
u32 ov14_021EA378(void *p);
u32 ov14_021EAF08(void *p);
u32 ov14_021EB0E4(void *p);
u32 ov14_021EA674(void *p);

u32 ov14_021EA408(void *p);
u32 ov14_021EAC24(void *p);
u32 ov14_021EAB54(void *p);

u32 ov14_021EA674(void *p) {
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (U16_AT(q, 0x88c8) != 0) {
            ov14_021F391C(q, 1);
            ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
        }
        U16_AT(q, 0x10)
        ++;
    case 1: {
        u32 a = ov14_021E9F20(p);
        u32 b = ov14_021E9434(p);
        if (a == 0 && b == 0) {
            U16_AT(q, 0x10)
            ++;
        }
        break;
    }
    case 2: {
        u32 a = sub_02019978(PTR_AT(q, 0x2f0), 8);
        u32 b = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 9);
        u32 c = sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0xa);
        if (a == 0 && b == 0 && c == 0) {
            if (U16_AT(PTR_AT(p, 0x34), 0x88c8) != 0) {
                ov14_021F391C(PTR_AT(p, 0x34), 0);
                ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
            }
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    }
    return 1;
}

u32 ov14_021EA728(void *p) {
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (ov14_021F2A04(q, 0xb) != 1) {
            u32 old = U8_AT(p, 0x21);
            U8_AT(p, 0x21) = (u8)U16_AT(PTR_AT(q, 0xc), 0);
            ov14_021E7AD4(p, old, old, 2);
            U16_AT(q, 0x10) = 1;
        }
        break;
    case 1:
        if (ov14_021E7B8C(p) == 0) {
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}
