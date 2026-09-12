#include "overlay102_easy_chat_input_r4_private.h"

int ov102_021E7EEC(void *unused, int x, int y) {
    int touchX;
    int touchY;
    if (!System_GetTouchHeld()) {
        return 0;
    }
    touchX = U16(gSystem, 0x60);
    if (x < touchX - 10 || x > touchX + 10) {
        return 0;
    }
    touchY = U16(gSystem, 0x62);
    if (y < touchY - 12 || y > touchY + 12) {
        return 0;
    }
    return 1;
}

int ov102_021E7F30(void *unused, int x, int y) {
    int touchY;
    if (!System_GetTouchHeld()) {
        return 0;
    }
    if (x < 0x12 || x > 0xec) {
        return 0;
    }
    touchY = U16(gSystem, 0x62);
    if (y < touchY - 0x18 || y > touchY + 0x18) {
        return 0;
    }
    return 1;
}
