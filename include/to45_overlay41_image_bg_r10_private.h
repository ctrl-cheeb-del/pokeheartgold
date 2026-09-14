#ifndef TO45_OVERLAY41_IMAGE_BG_R10_PRIVATE_H
#define TO45_OVERLAY41_IMAGE_BG_R10_PRIVATE_H

#include "global.h"

#include "bg_window.h"

typedef struct Ov41Work {
    u32 word[512];
} Ov41Work;

typedef struct Ov41PackedImage {
    u16 width;
    u16 height;
    u8 pad04[0x10];
    u32 *pixels;
} Ov41PackedImage;

extern const BgTemplate ov41_0224C018;

void ov41_022467E4(Ov41Work *work, int value);
void ov41_02246CC0(Ov41Work *work, int heapId, int texSize, int plttSize);
void PokepicManager_SetNeedG3IdentityFlag(void *manager, BOOL value);
void ov41_02246C90(Ov41Work *work, int value);
void ov41_02246CB0(Ov41Work *work);
void ov41_02246820(Ov41Work *work);
void ov41_02246D2C(Ov41Work *work);
void Heap_Free(void *ptr);

int ov41_022464BC(Ov41PackedImage *image, int x, int y, int value);
void ov41_02246518(Ov41Work *work, int value, int heapId);
void ov41_02246544(Ov41Work *work, BgConfig *bgConfig, enum HeapID heapId);
void ov41_02246594(Ov41Work *work);

#endif
