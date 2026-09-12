#include "overlay43_window_display_private.h"

void ov43_0222DF90(void *work, void *coords) {
    int i;

    for (i = 0; i < 8; i++) {
        ov43_0222DF1C(work, i);
    }
    ov43_0222EC14(coords, work);
}
