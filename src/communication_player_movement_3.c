#include "communication_player_movement_internal.h"

void sub_020570C8(void *unused) {
    int moveState = PlayerAvatar_GetMoveState(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    int playerMoveState = PlayerAvatar_GetPlayerMoveState(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    if (moveState == 0 && sub_020373B4(sub_0203769C()) && _021D41C4->raw[0xEB] == 0) {
        sub_0205701C(1);
        _021D41C4->raw[0xEB] = 1;
    }
    if (moveState == 1 && playerMoveState == 1) {
        _021D41C4->raw[0xEB] = 0;
    }
}
