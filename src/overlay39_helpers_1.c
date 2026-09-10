#include "overlay39_helpers_internal.h"

void ov39_02227060(void *a0, void *a1, Ov39Crc5C *a2) {
    ov39_0222915C(a1, a2);
    a2->crc = SaveArray_CalcCRC16(a0, a2, 0x5C);
}

void ov39_02227080(void *a0, void *a1, void *a2) {
    ov39_02229224(a0, a1, a2);
}
