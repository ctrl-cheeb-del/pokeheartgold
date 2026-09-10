#include "communication_player_movement_internal.h"

void sub_02056E38(void) {
    int i;
    if (_021D41C4 != NULL) {
        for (i = 0; i < 8; i++) {
            sub_0205724C((u8)i, 1, 1);
        }
    }
}

void sub_02056E60(void) {
    if (_021D41C4 != NULL) {
        _021D41C4->raw[0xEC] = 1;
        _021D41C4->raw[0xEE] = 0;
        sub_02056EF4();
        sub_0205701C(1);
        PlayerAvatar_GetXCoord(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
        PlayerAvatar_GetZCoord(*(void **)((u8 *)*(void **)&_021D41C4->raw[0x30] + 0x40));
    }
}

void sub_02056EA0(int flag) {
    int i;
    if (_021D41C4 != NULL) {
        for (i = 0; i < 8; i++) {
            sub_0205724C((u8)i, 0, flag);
        }
        SysTask_Destroy(*(void **)&_021D41C4->raw[0x2C]);
        Heap_Free(_021D41C4);
        _021D41C4 = NULL;
    }
}

BOOL sub_02056EE0(void) {
    return _021D41C4 != NULL;
}
