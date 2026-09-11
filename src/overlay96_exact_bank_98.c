#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_0220E850(u8 *p, int i) {
    return (*(u32 *)(p + i * 0xE4 + 0x23C) << 14) >> 16;
}
