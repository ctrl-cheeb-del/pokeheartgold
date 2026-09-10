#include "communication_player_movement_internal.h"

int sub_02057EEC(int value) {
    if (value == 0) {
        return 1;
    }
    if (value == 1) {
        return 0;
    }
    if (value == 2) {
        return 3;
    }
    if (value == 3) {
        return 2;
    }
    GF_AssertFail();
    return 2;
}

int sub_02057F18(int slot) {
    u8 *entry = _021D41C4->raw + slot;
    return entry[0xDC];
}

void sub_02057F28(int facing) {
    int slot;
    u8 *position;
    PlayerAvatar_SetFacingDirection(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40), facing);
    slot = sub_0203769C();
    position = _021D41C4->raw + slot * 8;
    position[0x78] = facing;
    sub_0205701C(0);
}

void sub_02057F58(void) {
    sub_0203E2F4();
    _021D41C4->raw[0xED] = 0;
}

void sub_02057F70(void) {
    sub_0203E30C();
    sub_02057358(1);
}

void sub_02057F80(void) {
    if (_021D41C4->raw[0xEF] == 0) {
        sub_02057F70();
        _021D41C4->raw[0xEF] = 1;
    }
}
