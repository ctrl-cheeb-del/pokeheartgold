#include "overlay39_helpers_internal.h"

void ov39_02227188(void *a0, Ov39Crc198 *a1, u8 a2) {
    a1->unk177 = a2;
    a1->crc = SaveArray_CalcCRC16(a0, a1, 0x198);
}

void ov39_022271A4(void *a0, const void *a1, void *a2) {
    MI_CpuFill8(a2, 0, 0x80);
    MI_CpuCopy8(a1, a2, 0x80);
}

void ov39_022271C0(const void *src, void *dst) {
    MI_CpuCopy8(src, dst, 0x80);
}
