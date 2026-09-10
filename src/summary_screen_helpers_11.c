#include "summary_screen_helpers_internal.h"

BOOL sub_02089E80(void *data, int bit) {
    void *p = *(void **)((u8 *)data + 0x22C);
    return (*((u8 *)p + 0x15) & (1 << bit)) != 0;
}
