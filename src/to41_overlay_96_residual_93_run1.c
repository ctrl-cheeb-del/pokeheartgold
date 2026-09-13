#include "to41_overlay_96_residual_93_private.h"

void ov96_022098E8(u8 *p) {
    NARC_Delete(PTR(p, 0x50));
    ov96_021EA894(PTR(p, 0x10));
    ov96_021E9C0C(PTR(p, 0x14));
    SpriteSystem_FreeResourcesAndManager(PTR(p, 8), PTR(p, 0xc));
    SpriteSystem_Free(PTR(p, 8));
}
