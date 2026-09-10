#include "communication_player_movement_internal.h"

BOOL sub_020574C4(int x, int z, int excludedSlot) {
    int slot;
    if (x != 0xFFFF && z != 0xFFFF) {
        for (slot = 0; slot < 8; slot++) {
            if (slot != excludedSlot && sub_02057B4C(slot) == x && sub_02057B9C(slot) == z) {
                return TRUE;
            }
        }
        if (sub_02057480(x, z)) {
            return TRUE;
        }
    }
    return sub_020548C0(*(void **)&_021D41C4->raw[0x30], x, z);
}

u32 sub_02057524(int index) {
    u32 table[5] = { 2, 4, 8, 16, 2 };
    if (index >= 5) {
        GF_AssertFail();
    }
    return table[index];
}
