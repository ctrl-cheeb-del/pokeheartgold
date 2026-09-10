#include "communication_player_movement_internal.h"

void sub_02057D50(int slot, int size, const u8 *data) {
    int value = *data;
    if (value == 3) {
        u8 *entry = _021D41C4->raw + slot;
        entry[0xBC] = 0;
    } else {
        u8 *entry = _021D41C4->raw + slot;
        entry[0xE6] = value;
    }
}
