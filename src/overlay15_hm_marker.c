#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "heap.h"

typedef struct BagWorkHmMarker {
    u8 pad000[0x244];
    NARC *narc;
} BagWorkHmMarker;

void *ov15_021FE990(BagWorkHmMarker *, NNSG2dCharacterData **);
void ov15_021FE9B0(BagWorkHmMarker *, Window *, u32);

void *ov15_021FE990(BagWorkHmMarker *work, NNSG2dCharacterData **charData) {
    void *buffer = NARC_AllocAndReadWholeMember(work->narc, 0x25, HEAP_ID_6);
    NNS_G2dGetUnpackedBGCharacterData(buffer, charData);
    return buffer;
}

void ov15_021FE9B0(BagWorkHmMarker *work, Window *window, u32 destY) {
    NNSG2dCharacterData *charData;
    void *buffer = ov15_021FE990(work, &charData);

    BlitBitmapRectToWindow(window, charData->pRawData, 0, 0, 0x68, 0x10, 0, destY, 0x18, 0x10);
    Heap_FreeExplicit(HEAP_ID_6, buffer);
}
