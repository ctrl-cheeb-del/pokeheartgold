#include "battle_transition_application_internal.h"

const OverlayManagerTemplate *sub_02087E10(u8 index) {
    return _02110594[index];
}

BOOL sub_02087E1C(u8 *data) {
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(*(SaveData **)(data + 0x830));
    return Save_VarsFlags_FlypointFlagAction(varsFlags, 2, 0x1B);
}

BOOL sub_02087E34(u32 value) {
    FiveValues init = _021028A0;
    u32 i;
    for (i = 0; i < 5; i++) {
        if (value == init.values[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
