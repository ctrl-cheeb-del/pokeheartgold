#include "overlay40_pc_display_r4_private.h"

void ov40_0222CBC0(void *p) {
    SpriteManager_UnloadCharObjById(PTR(p, 0x1C), 0x2711);
    SpriteManager_UnloadCharObjById(PTR(p, 0x1C), 0x2712);
}
