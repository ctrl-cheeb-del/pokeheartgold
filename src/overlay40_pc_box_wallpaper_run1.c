#include "overlay40_pc_box_wallpaper_private.h"

int ov40_022439CC(u8 *w, int id) {
    int i;
    int n = WORD(w, 0x204);
    for (i = 0; i < n; i++) {
        if (id == WORD(w, 4)) {
            return i;
        }
        w += 0x1C;
    }
    return 0;
}

int ov40_022439F4(u8 *w, int id) {
    int i;
    int found;
    int n = WORD(w, 0x204);
    found = 0;
    for (i = 0; i < n; i++) {
        if (id == WORD(w, 4)) {
            found = 1;
        } else if (found == 1) {
            return i - 1;
        }
        w += 0x1C;
    }
    return n - 1;
}
