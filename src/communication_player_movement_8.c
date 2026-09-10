#include "communication_player_movement_internal.h"

int sub_02057A08(void) {
    return 4;
}

BOOL sub_02057A0C(void) {
    int slot;
    if (_021D41C4 == NULL) {
        return FALSE;
    }
    slot = sub_0203769C();
    return sub_020373B4(slot) != 0;
}
