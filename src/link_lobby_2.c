#include "link_lobby_internal.h"

BOOL sub_02058258(void) {
    if (_021D41C8->state == sub_020588F8) {
        return FALSE;
    }
    if (_021D41C8->state != sub_02058930) {
        return TRUE;
    }
    return FALSE;
}

void sub_02058284(void) {
    if (_021D41C8) {
        sub_020398D4(0, 0);
        sub_020582F4(sub_02058A60, 5);
    }
}

void sub_020582A8(void) {
    if (_021D41C8) {
        sub_02037AC0(91);
        sub_020582F4(sub_02058A38, 5);
    }
}

void sub_020582CC(SysTask *task, void *unused) {
    if (_021D41C8 == NULL) {
        SysTask_Destroy(task);
        return;
    }
    if (_021D41C8->state && _021D41C8->paused == 0) {
        _021D41C8->state();
    }
}

void sub_020582F4(LobbyState state, u16 timer) {
    _021D41C8->state = state;
    _021D41C8->timer = timer;
}
