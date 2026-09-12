#include "overlay40_pc_box_grid_private.h"

void ov40_02235B10(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D6D0((u8 *)w + 0x198);
    ov40_0222D6D0((u8 *)w + 0x1B4);
    Sprite_DeleteAndFreeResources(PTR(w, 0x19C));
    Sprite_DeleteAndFreeResources(PTR(w, 0x1B8));
    ov40_0222D7DC(p);
}
