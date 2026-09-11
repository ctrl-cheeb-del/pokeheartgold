#include "overlay70_ui_helpers_private.h"

void ov70_0223F8A8(u8 *work, u32 value) {
    if (value == 0) {
        *(u32 *)(work + 0x12CC) = 0;
        return;
    }
    value--;
    if (value < 0x82)
        *(u32 *)(work + 0x12CC) = ov70_02245B5C[value];
}

int ov70_0223F8D0(u32 value, u32 *first) {
    const u8 *entry = ov70_022459C8;
    int i = 0;
    for (; (u32)i < 22; i++, entry += 2) {
        if (value == entry[1]) {
            *first = ov70_022459C8[i * 2];
            return ov70_022459C8[(i + 1) * 2] - ov70_022459C8[i * 2];
        }
    }
    return 0;
}
