#include "overlay96_course_scene_r77_private.h"

void ov96_021FD060(u8 *p) {
    GfGfxLoader_LoadCharData(0xb2, 1, PTR(p, 0), 0, 0, 0, 0, U32(p, 0x14));
    GfGfxLoader_LoadScrnData(0xb2, 2, PTR(p, 0), 0, 0, 0, 0, U32(p, 0x14));
    GfGfxLoader_LoadScrnData(0xb2, 3, PTR(p, 0), 1, 0, 0, 0, U32(p, 0x14));
    GfGfxLoader_LoadScrnData(0xb2, 4, PTR(p, 0), 2, 0, 0, 0, U32(p, 0x14));
    GfGfxLoader_GXLoadPal(0xb2, 0, 0, 0, 0x40, U32(p, 0x14));
    ov96_02200068(PTR(p, 0x3e0));
}

void ov96_021FD0E4(void *p) {
    ov96_021EB2BC(p, 0xb2, 0x11, 0x68, 1);
    ov96_021EB2F4(p, 0xb2, 0xe, 0x68, 1, 2);
    ov96_021EB334(p, 0xb2, 0x10, 0x68);
    ov96_021EB36C(p, 0xb2, 0xf, 0x68);
}
