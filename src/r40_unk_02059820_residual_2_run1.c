#include "r40_unk_02059820_residual_2_private.h"

int sub_02059A08(void *arg) {
    u8 *data = arg;
    int selected;

    if (gSystem.newKeys & PAD_KEY_UP) {
        data[0x81] = (s8)data[0x81] == 0 ? data[0x80] - 1 : (s8)data[0x81] - 1;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        selected = (s8)data[0x81];
        if (selected == data[0x80] - 1) {
            selected = 0;
        } else {
            selected++;
        }
        data[0x81] = selected;
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(0x5DC);
        if ((s8)data[0x81] < data[0x80] - 1) {
            return 1;
        }
        return 2;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(0x5DC);
        return 2;
    } else {
        return 0;
    }

    PlaySE(0x5DC);
    FillWindowPixelRect(*(void **)(data + 0x7C), 0xF, 0, 0, 0x10, ((u32)((u8 *)*(void **)(data + 0x7C))[8] << 19) >> 16);
    ListMenuUpdateCursorObj(*(void **)(data + 0x78), *(void **)(data + 0x7C), 0, (s8)data[0x81] << 4);
    CopyWindowPixelsToVram_TextMode(*(void **)(data + 0x7C));
    return 0;
}
