#include "overlay40_pc_box_grid_private.h"

void ov40_0223320C(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D6D0((u8 *)w + 0xB8);
    Sprite_DeleteAndFreeResources(PTR(w, 0xBC));
    Sprite_DeleteAndFreeResources(PTR(w, 0x98));
    ov40_0222D7DC(p);
}
