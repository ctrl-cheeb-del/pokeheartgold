#include "wireless_connection_state_internal.h"

BOOL sub_02034BE4(void) {
    return _021D4134.work != NULL;
}

BOOL sub_02034BF8(const u8 *a, const u8 *b, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}
