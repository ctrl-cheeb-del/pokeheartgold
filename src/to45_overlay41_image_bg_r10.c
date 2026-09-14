#include "to45_overlay41_image_bg_r10_private.h"

int ov41_022464BC(Ov41PackedImage *image, int x, int y, int value) {
    int height = image->height;
    int width = image->width;
    int index;
    int shift;
    u32 pixel;

    height <<= 3;
    if (x < 0 || y < 0 || x >= height || y >= width * 8) {
        return 2;
    }
    index = y;
    index *= height;
    x += index;
    index = x;
    shift = index % 8 * 4;
    pixel = image->pixels[index / 8];
    if ((value << shift) == (pixel & (15 << shift))) {
        return 1;
    }
    return 0;
}

void ov41_02246518(Ov41Work *work, int value, int heapId) {
    ov41_022467E4(work, value);
    ov41_02246CC0(work, heapId, 0x2800, 0x20);
    PokepicManager_SetNeedG3IdentityFlag((void *)work->word[8], TRUE);
    ov41_02246C90(work, heapId);
}

void ov41_02246544(Ov41Work *work, BgConfig *bgConfig, enum HeapID heapId) {
    BgTemplate template;

    work->word[0x40 / 4] = (u32)bgConfig;
    template = ov41_0224C018;
    FreeBgTilemapBuffer((BgConfig *)work->word[0x40 / 4], GF_BG_LYR_MAIN_2);
    InitBgFromTemplate((BgConfig *)work->word[0x40 / 4], GF_BG_LYR_MAIN_2, &template, 0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_2, 0x20, 0, heapId);
    BgClearTilemapBufferAndCommit((BgConfig *)work->word[0x40 / 4], GF_BG_LYR_MAIN_2);
}

void ov41_02246594(Ov41Work *work) {
    ov41_02246CB0(work);
    ov41_02246820(work);
    ov41_02246D2C(work);
    Heap_Free((void *)work->word[1]);
    work->word[1] = 0;
    Heap_Free((void *)work->word[4]);
    work->word[4] = 0;
}
