#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02208AE8(u8 *p, int i, u32 v) {
    *(u32 *)(p + i * 8) = v;
}

void ov96_02208AF0(u8 *p, u32 v) {
    *(u32 *)(p + 0x188) = v;
}
