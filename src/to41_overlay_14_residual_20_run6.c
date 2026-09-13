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

u32 ov14_021EA928(void *p) {
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0:
        ov14_021F391C(q, 1);
        ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 1);
        ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 1);
        U16_AT(q, 0x10) = 1;
        break;
    case 1:
        if (ov14_021F2A04(q, 0xb) == 0) {
            ov14_021F391C(PTR_AT(p, 0x34), 0);
            U16_AT(q, 0x10) = 2;
        }
        break;
    case 2: {
        u32 old = U8_AT(p, 0x21);
        U8_AT(p, 0x21) = (u8)U16_AT(PTR_AT(q, 0xc), 0);
        ov14_021E7AD4(p, old, old, 2);
        U16_AT(q, 0x10) = 3;
        break;
    }
    case 3:
        if (ov14_021E7B8C(p) == 0) {
            PlaySE(0x5ea);
            U16_AT(q, 0x10) = 4;
        }
        break;
    case 4:
        ov14_021F391C(q, 1);
        ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
        U16_AT(q, 0x10) = 5;
        break;
    case 5:
        if (ov14_021F2A04(q, 0xb) == 0) {
            ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
            ov14_021F391C(PTR_AT(p, 0x34), 0);
            U16_AT(q, 0x10) = 6;
        }
        break;
    case 6:
        U16_AT(q, 0x10) = 0;
        return 0;
    }
    return 1;
}
