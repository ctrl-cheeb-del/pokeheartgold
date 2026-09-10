#include "communication_player_movement_internal.h"

void sub_02056FD0(int flag, int x, int z) {
    u8 data[8];
    int facing = PlayerAvatar_GetFacingDirection(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    data[0] = x;
    data[1] = x >> 8;
    data[2] = z;
    data[3] = z >> 8;
    data[4] = facing;
    if (flag) {
        data[4] |= 0x80;
    }
    sub_020376E0(0x16, data);
    _021D41C4->raw[0xEC] = 1;
}

void sub_0205701C(int flag) {
    int x = PlayerAvatar_GetXCoord(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    int z = PlayerAvatar_GetZCoord(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    sub_02056FD0(flag, x, z);
}
