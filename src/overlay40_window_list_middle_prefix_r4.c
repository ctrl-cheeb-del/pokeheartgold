#include "overlay40_window_list_middle_r4_private.h"

int ov40_0222EFD8(void *p, void *owner, void **items)
{
    int start;
    int i;
    void *window;

    (void)owner;
    if (SWORD(p, 0x38) == SWORD(p, 0xC)) {
        return 0;
    }
    if (SWORD(p, 0x10) == SWORD(p, 4)) {
        return 0;
    }

    window = (u8 *)p + 0x18;
    FillWindowPixelBuffer(window, 0);
    {
        int edge = SWORD(p, 0x40);
        int display = SWORD(p, 0x3C);

        start = 0;
        if (display >= edge) {
            int selected = SWORD(p, 0x38);
            int count = SWORD(p, 4);

            start = selected - edge;
            if (selected >= count - (edge + 1)) {
                start = count - SWORD(p, 0x10);
            }
        }
    }
    i = 0;
    if (SWORD(p, 0x10) > 0) {
        items += start * 2;
        do {
            if (items[0] != NULL) {
                AddTextPrinterParameterizedWithColor(window, 0, items[0], 0,
                                                      SWORD(PTR(p, 0x28), 8) * 8 * i + 4, 0xFF, 0x000F0D00, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, items[1], 0x88,
                                                      SWORD(PTR(p, 0x28), 8) * 8 * i + 4, 0xFF, 0x000F0D00, NULL);
            }
            i++;
            items += 2;
        } while (i < SWORD(p, 0x10));
    }
    CopyWindowToVram(window);
    SWORD(p, 0xC) = SWORD(p, 0x38);
    return 0;
}
