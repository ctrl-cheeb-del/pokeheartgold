#include "network_communication_state_internal.h"

void sub_02037F18(void *saveData) {
    if (_021D4150 == NULL) {
        if (!Heap_CreateAtEnd(3, 15, 0x7080)) {
            sub_020399EC();
        }
        sub_02037C98(saveData, 9);
        _021D4150->activity4E = 9;
        _021D4150->parameter4F = 0;
        sub_020381C0(sub_020384B4, 0);
    }
}

void sub_02037F64(int request) {
    _021D4150->request4D = request;
    _021D4150->state48 = 3;
    sub_02033AA4(1);
    sub_0203A880();
    sub_020381C0(sub_02038668, 0);
}

int sub_02037F94(void) {
    NetworkState *state = _021D4150;
    if (state == NULL) {
        return -1;
    }
    if (state->callback == sub_020387E8) {
        return 1;
    }
    return -(state->callback == sub_02038800);
}

BOOL sub_02037FCC(void) {
    NetworkState *state = _021D4150;
    if (state == NULL) {
        return FALSE;
    }
    if (state->callback == sub_02038854) {
        return TRUE;
    }
    return FALSE;
}
