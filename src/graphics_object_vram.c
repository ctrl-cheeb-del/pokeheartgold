#include "graphics_object_internal.h"

NNSGfdTexKey sub_02016170(NNSG2dCharacterData *data) {
    return NNS_GfdAllocTexVram(data->szByte, FALSE, 0);
}
NNSGfdPlttKey sub_02016184(u32 size) {
    return NNS_GfdAllocPlttVram(size << 5, FALSE, 0);
}

void sub_02016198(NNSG2dCharacterData *data, NNSGfdTexKey key, NNSG2dImageProxy *proxy) {
    NNS_G2dLoadImage2DMapping(data, (key << 16) >> 13, (NNS_G2D_VRAM_TYPE)0, proxy);
}

void sub_020161A8(NNSG2dPaletteData *data, NNSGfdPlttKey key, NNSG2dImagePaletteProxy *proxy) {
    u32 size = (key & 0xFFFF0000) >> 16;
    u32 saved = data->szByte;
    data->szByte = size << 3;
    NNS_G2dLoadPalette(data, (key << 16) >> 13, (NNS_G2D_VRAM_TYPE)0, proxy);
    data->szByte = saved;
}
