#include "summary_screen_helpers_internal.h"

BOOL sub_0208A3CC(void *data) {
    void *p = *(void **)((u8 *)data + 0x22C);
    signed char value;
    if (*((u8 *)p + 0x12) == 3) {
        return 0;
    }
    value = *((signed char *)data + 0x7BC);
    if (value != 0 && value != 3) {
        return 0;
    }
    return 1;
}
