#include "communication_player_movement_internal.h"

int sub_02057B4C(int slot) {
    if (_021D41C4 == NULL) {
        return 0xFFFF;
    }
    if (slot == sub_0203769C()) {
        return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].x;
    }
    if (!sub_02057A0C() || ((CommPlayerManagerLayout *)_021D41C4)->active[slot] == 0) {
        return 0xFFFF;
    }
    return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].x;
}

int sub_02057B9C(int slot) {
    if (_021D41C4 == NULL) {
        return 0xFFFF;
    }
    if (slot == sub_0203769C()) {
        return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].z;
    }
    if (!sub_02057A0C() || ((CommPlayerManagerLayout *)_021D41C4)->active[slot] == 0) {
        return 0xFFFF;
    }
    return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].z;
}
