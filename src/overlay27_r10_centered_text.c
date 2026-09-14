#include "overlay27_r10_centered_text_private.h"

#define R27_PTR(work, offset, type) (*(type **)((u8 *)(work) + (offset)))

void ov27_0225BCE8(void *work) {
    int i = 0;
    Window *window = (Window *)((u8 *)work + 0x3F0);

    while (i < 7) {
        if (R27_PTR(work, 0x474, String) != NULL) {
            int delta = 0x48 - (int)FontID_String_GetWidth(0, R27_PTR(work, 0x474, String), 0);
            AddTextPrinterParameterizedWithColor(window, 0, R27_PTR(work, 0x474, String), delta / 2, 0, 0xFF, 0xE0200, NULL);
        }
        i++;
        work = (u8 *)work + 8;
        window = (Window *)((u8 *)window + 0x10);
    }
}
