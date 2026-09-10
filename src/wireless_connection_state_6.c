#include "wireless_connection_state_internal.h"

int sub_02035610(void) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (sub_020355DC((u16)i)) {
            count++;
        }
    }
    return count;
}

int sub_02035630(void) {
    if (_021D4134.work != NULL && _021D4134.work[0xD92] == 3) {
        return 1;
    }
    return 0;
}

BOOL sub_02035650(void) {
    return _021D4134.work != NULL;
}

int sub_02035664(void) {
    if (_021D4134.work != NULL) {
        return sub_02033920(_021D4134.work);
    }
    return 1;
}

int sub_0203567C(void) {
    if (_021D4134.work != NULL) {
        return sub_02033250(_021D4134.work) & 0xFFFE;
    }
    return 0;
}
