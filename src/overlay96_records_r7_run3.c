#include "overlay96_records_r7_private.h"

void ov96_021E7BA8(Ov96R7Work *w, u16 *records, u16 *out);

void ov96_021E7BA8(Ov96R7Work *w, u16 *records, u16 *out) {
    u8 i;
    u8 participant;
    u8 *base = (u8 *)w;
    u8 *slot;

    for (i = 0; i < 3; i++) {
        participant = (u8)OV96_R7_U32(base + i * 4, 0x3d8);
        slot = base + i * 2;
        if (ov96_021E7D18(OV96_R7_U16(records, participant * 0x2c), OV96_R7_U16(slot, 0x8d4), _0221A7D8[participant])) {
            out[participant] = OV96_R7_U16(slot, 0x8b4);
        }
    }
}
