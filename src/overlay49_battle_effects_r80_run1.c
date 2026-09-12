#include "overlay49_battle_effects_r80_private.h"

u8 ov49_02269154(u8 *work, u32 row, int column) {
    u8 *entry;

    if (row >= 9) {
        GF_AssertFail();
    }
    if (column >= 3) {
        GF_AssertFail();
    }
    entry = work + row * 3;
    entry += column;
    return entry[0x10];
}
