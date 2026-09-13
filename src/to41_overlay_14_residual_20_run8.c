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

u32 ov14_021EAF08(void *p) {
    void *q = PTR_AT(p, 0x34);
    u32 r = ov14_021E80A8(p);
    switch (U16_AT(q, 0x10)) {
    case 0:
        if (ov14_021F2A04(PTR_AT(p, 0x34), 0xb) == 0) {
            u32 old = U8_AT(p, 0x21);
            U8_AT(p, 0x21) = (u8)U16_AT(PTR_AT(q, 0xc), 0);
            ov14_021E7AD4(p, old, old, 1);
            if (U8_AT(PTR_AT(p, 0x34), 0x44a) != 0) {
                U8_AT(PTR_AT(p, 0x34), 0x44a) = 0;
                ov14_021E7FEC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
                ov14_021F3488(p, 1, 1);
            }
            U16_AT(q, 0x10) = 1;
        }
        break;
    case 1:
        if (ov14_021E7B8C(p) == 0 && r == 0) {
            U16_AT(q, 0x10) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

u32 ov14_021EAF8C(void *p, u32 *state) {
    *state = ov14_021F7D9C[*state](p);
    if (*state == 0xb3) {
        return 0;
    }
    return 1;
}
