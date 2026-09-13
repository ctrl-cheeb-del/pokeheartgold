#include "global.h"

#include "r40_overlay_57_residual_5_private.h"

void ov57_022386F0(void *p) {
    *(void **)((u8 *)p + 0x25C) = FontSystem_NewInit(2, HEAP_ID_52);
    FontID_Alloc(2, HEAP_ID_52);
    FontID_Alloc(4, HEAP_ID_52);
}

void ov57_02238714(void *p) {
    FontID_Release(4);
    FontID_Release(2);
    FontOAM_Delete(*(TextOBJ **)((u8 *)p + 0x260));
    sub_02021B5C((UnkStruct_02021AC8 *)((u8 *)p + 0x268));
    FontOAM_Delete(*(TextOBJ **)((u8 *)p + 0x264));
    sub_02021B5C((UnkStruct_02021AC8 *)((u8 *)p + 0x274));
    sub_020135AC(*(UnkStruct_02013534 **)((u8 *)p + 0x25C));
}

void ov57_02238758(void *p) {
    SpriteSystem_LoadPaletteBuffer(*(PaletteData **)((u8 *)p + 0xE8), PLTTBUF_SUB_OBJ, *(SpriteSystem **)((u8 *)p + 0xDC), *(SpriteManager **)((u8 *)p + 0xE0), NARC_graphic_font, 8, FALSE, 1, 2, 0x7530);
}

void ov57_02238794(void *p) {
    ov57_02238758(p);
    ov57_022387E0(p, 0, 0x68, 0xA5, 0);
    ov57_022387E0(p, 1, 0xC0, 0xA5, 0);
}
