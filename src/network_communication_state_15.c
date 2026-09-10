#include "network_communication_state_internal.h"

void sub_02039220(void) {
    if (sub_0203769C() == 0) {
        _021D4150->flag50 = 0;
        sub_020381C0(sub_020391D0, 0);
    } else {
        _021D4150->flag50 = 1;
        sub_020381C0(sub_020391D0, 0);
    }
    _021D4150->result5C = 1;
}

u8 sub_02039264(void) {
    return _021D4150->result5C;
}

BOOL sub_02039274(void) {
    NetworkStateFunc callback = _021D4150->callback;
    if (callback == sub_02039144) {
        return TRUE;
    }
    if (callback == sub_02039C60) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_020392A0(void) {
    NetworkStateFunc callback = _021D4150->callback;
    if (callback == sub_02038F9C) {
        return TRUE;
    }
    if (callback == sub_02039144) {
        return TRUE;
    }
    if (callback == sub_02039C60) {
        return TRUE;
    }
    return FALSE;
}

void *sub_020392D8(void) {
    if (_021D4150 == NULL) {
        GF_AssertFail();
    }
    return _021D4150->scratch34;
}

void sub_020392F4(void) {
    sub_0203786C(0);
    if (ov00_021E6BE4(0)) {
        ov00_021E6C68();
        sub_020381C0(sub_0203847C, 0);
    }
    if (ov00_021E5E54(0) < 0) {
        sub_020381C0(sub_02038E90, 0);
    }
}

void sub_02039330(void) {
    if (_021D4150 != NULL) {
        sub_0201A738(1);
        sub_020343E4();
        sub_020381C0(sub_0203847C, 5);
    }
}

void sub_02039358(void) {
    if (_021D4150 != NULL) {
        _021D4150->flag50 = 0;
        sub_020381C0(sub_020391D0, 0);
    }
}
