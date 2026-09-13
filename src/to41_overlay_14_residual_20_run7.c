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

u32 ov14_021EAB54(void *p) {
    s16 a[2];
    void *q = PTR_AT(p, 0x34);
    switch (U16_AT(q, 0x10)) {
    case 0:
        ov14_021F29E4(q, 9, 9);
        U16_AT(q, 0x10) = 1;
    case 1:
        if (U16_AT(q, 0x12) == 4) {
            U16_AT(q, 0x12) = 0;
            U16_AT(q, 0x10) = 2;
            break;
        }
        ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x328), (s32 *)&a[1], (s32 *)&a[0]);
        ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x328), a[1], (s16)(a[0] + 2));
        U16_AT(q, 0x12)
        ++;
        break;
    case 2:
        ov14_021F29E4(q, 9, 8);
        ov14_021F391C(PTR_AT(p, 0x34), 1);
        ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
        U16_AT(q, 0x10) = 3;
        break;
    case 3:
        if (ov14_021F2A04(q, 0xb) == 0) {
            ov14_021F391C(PTR_AT(p, 0x34), 0);
            ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
            U16_AT(q, 0x10) = 4;
        }
        break;
    case 4:
        ov14_021F29E4(q, 9, 8);
        U16_AT(q, 0x10) = 0;
        return 0;
    }
    return 1;
}

u32 ov14_021EAC24(void *p) {
    void *q = PTR_AT(p, 0x34);
    sub_02019978(PTR_AT(q, 0x2f0), 0xf);
    switch (U16_AT(q, 0x10)) {
    case 0:
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 9);
        ov14_021E7AE4(p, U16_AT(PTR_AT(p, 0x34), 0x88ca), 2);
        U16_AT(q, 0x10) = 1;
        break;
    case 1:
        if (ov14_021E7B98(p) == 0) {
            U16_AT(q, 0x10) = 2;
        }
        break;
    case 2:
        ov14_021F391C(PTR_AT(p, 0x34), 1);
        ov14_021F29E4(PTR_AT(p, 0x34), 0xb, 2);
        U16_AT(q, 0x10) = 3;
        break;
    case 3:
        if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 0) {
            ov14_021F391C(PTR_AT(p, 0x34), 0);
            ov14_021F2A18(PTR_AT(p, 0x34), 0xb, 0);
            U16_AT(q, 0x10) = 4;
        }
        break;
    case 4:
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
        U16_AT(q, 0x10) = 0;
        return 0;
    }
    return 1;
}
