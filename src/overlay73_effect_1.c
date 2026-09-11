#include "overlay73_effect_internal.h"

void *ov73_021E7B3C(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A74(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0x18C, 4, 1, 3);
    return out;
}

void *ov73_021E7B84(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A7C(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0xC, 4, 1, 4);
    return out;
}

void *ov73_021E7BC8(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A84(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0xCC, 4, 1, 5);
    return out;
}

void *ov73_021E7C0C(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A74(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0x18C, 4, 0, 0);
    return out;
}

void *ov73_021E7C50(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A7C(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0xC, 4, 0, 1);
    return out;
}

void *ov73_021E7C94(void *save, int heap, int size) {
    void *out = Heap_AllocAtEnd(heap, size);
    u8 *base = sub_020270C4(save);
    if (size != ov73_021E7A84(save)) {
        GF_AssertFail();
    }
    ov73_021E7AC0(save, out, base + 0xCC, 4, 0, 2);
    return out;
}
