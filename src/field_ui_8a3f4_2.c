#include "field_ui_8a3f4_internal.h"

void sub_0208A79C(u8 *work) {
    u32 selection;
    sub_0208BBDC(work);
    selection = *(volatile u8 *)(work + 0x7BD);
    selection = selection << 28;
    selection = selection >> 28;
    if (selection == 4) {
        u16 move = *(u16 *)(*(u8 **)(work + 0x22C) + 0x18);
        if (move != 0) {
            sub_0208A7F8(work, move);
        } else {
            sub_0208A7F8(work, -1);
        }
    } else if (selection == 5) {
        sub_0208A7F8(work, -1);
    } else {
        sub_0208A7F8(work, *(u16 *)(work + 0x264 + selection * 2));
    }
}
