#include "overlay27_r13_value_windows_private.h"

void ov27_0225BF84(Ov27WorkR13 *work, u32 a1, u32 a2, u16 value) {
    BufferIntegerAsString(work->messageFormat, 0, value, 2, 0, 1);
    ov27_0225BED8(work, 0x1f, a1, a2, 6, 2, 0x186, 0, 0);
}

void ov27_0225BFCC(Ov27WorkR13 *work, Ov27PokemonSlotR13 *slot) {
    u32 value = GetMonData(slot->mon, 0xA1, NULL);

    BufferIntegerAsString(work->messageFormat, 0, value, 3, 0, 1);
    ov27_0225BED8(work, 0x21, 0xc, 0x15, 6, 2, 0x192, 4, 0);
}
