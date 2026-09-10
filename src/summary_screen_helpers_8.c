#include "summary_screen_helpers_internal.h"

int sub_0208942C(void *data) {
    if (Sprite_IsAnimated(*(void **)((u8 *)data + 0x504)) == 0) {
        sub_0208AB58(data, -9);
        return 12;
    }
    return 13;
}

int sub_02089454(void *data) {
    if (Sprite_IsAnimated(*(void **)((u8 *)data + 0x508)) == 0) {
        sub_0208AB58(data, 9);
        return 12;
    }
    return 14;
}
