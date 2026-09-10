#include "field_overlay_effects_internal.h"

void ov01_021F0960(void *window, s32 endY, s32 endX, s32 startX, s32 startY, u8 fill) {
    if (startY <= 0 || endX <= 0 || startX == startY || endY == endX) {
        return;
    }
    if (startX < 0) {
        startX = 0;
    }
    if (startY > 256) {
        startY = 256;
    }
    if (endY < 0) {
        endY = 0;
    }
    if (endX > 256) {
        endX = 256;
    }
    FillWindowPixelRect(window, fill, (u16)startX, (u16)endY, (u16)(startY - startX), (u16)(endX - endY));
}

void *ov01_021F09BC(int heap) {
    u8 *p = Heap_Alloc(4, 0xCC);
    int i;
    u8 *cursor;
    memset(p, 0, 0xCC);
    i = 0;
    cursor = p;
    do {
        *(void **)(cursor + 4) = ov01_021F0848(heap);
        i++;
        cursor += 4;
    } while (i < 0x30);
    return p;
}

void ov01_021F09EC(void *v) {
    u8 *p = v;
    int i;
    u8 *cursor;
    i = 0;
    cursor = p;
    do {
        ov01_021F0860(*(void **)(cursor + 4));
        i++;
        cursor += 4;
    } while (i < 0x30);
    Heap_Free(p);
}

void ov01_021F0A0C(void *v, u8 a, u8 b, void *ptr, u8 c) {
    u8 *p = v;
    *(void **)p = ptr;
    p[0xC9] = c;
    p[0xC6] = a;
    p[0xC7] = b;
    p[0xC4] = 0;
    p[0xC5] = 0;
    p[0xC8] = 0;
    p[0xCA] = 1;
}
