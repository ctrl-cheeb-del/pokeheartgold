#include "overlay92_battle_sequence_r18_private.h"

void ov92_02261B18(void *work) {
    int i;
    u8 *src;
    u8 *dst;
    PTR_AT(work, 0x2188) = ADDR(work, 0x2af4);
    PTR_AT(work, 0x218c) = ADDR(work, 0x108);
    PTR_AT(work, 0x2190) = ADDR(work, 0x10c);
    PTR_AT(work, 0x21ac) = PTR_AT(work, 0x14);
    U32_AT(work, 0x2194) = 0;
    U32_AT(work, 0x21a0) = 0;
    U32_AT(work, 0x21a4) = 0;
    src = work;
    dst = work;
    for (i = 0; i < 2; i++) {
        PTR_AT(dst, 0x2030) = PTR_AT(src, 0xe8);
        PTR_AT(dst, 0x20d0) = PTR_AT(src, 0xe0);
        src += 4;
        dst += 0x50;
    }
    PTR_AT(work, 0x2184) = SysTask_CreateOnMainQueue(ov92_02261A18, ADDR(work, 0x2030), 1 << 12);
}
