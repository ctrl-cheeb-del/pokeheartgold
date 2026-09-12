#include "overlay40_pc_box_grid_private.h"

void ov40_022327BC(void *p) {
    void *w = PTR(p, 0x860);
    ClearWindowTilemapAndCopyToVram((u8 *)w + 0x178);
    RemoveWindow((u8 *)w + 0x178);
    ClearWindowTilemapAndCopyToVram((u8 *)w + 0x188);
    RemoveWindow((u8 *)w + 0x188);
}
