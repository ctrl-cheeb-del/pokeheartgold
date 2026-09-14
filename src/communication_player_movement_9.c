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

typedef struct CommPlayerExtendedLayout {
    u8 pad00[0x34];
    PlayerPosition local[8];
    u8 pad74[0x40];
    u8 valuesB4[8];
    u8 padBC[0x10];
    u8 valuesCC[8];
} CommPlayerExtendedLayout;

int sub_02057BEC(int slot) {
    if (sub_02057B4C(slot) == 0xFFFF) {
        return 0xFFFF;
    }
    return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].x
        + GetDeltaXByFacingDirection(((CommPlayerPositionLayout *)_021D41C4)->local[slot].facing);
}

int sub_02057C24(int slot) {
    if (sub_02057B9C(slot) == 0xFFFF) {
        return 0xFFFF;
    }
    return ((CommPlayerPositionLayout *)_021D41C4)->local[slot].z
        + GetDeltaYByFacingDirection(((CommPlayerPositionLayout *)_021D41C4)->local[slot].facing);
}

void sub_02057C5C(int slot, int value) {
#define STATE (*(CommPlayerExtendedLayout *volatile *)&_021D41C4)
    u8 *valuesB4 = STATE->valuesB4;
    if (valuesB4[slot] != value) {
        valuesB4[slot] = value;
        STATE->local[slot].pad5[2] = 0;
        STATE->valuesCC[slot] = 1;
        STATE->local[slot].pad5[0] = 2;
    }
#undef STATE
}
