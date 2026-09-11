#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EAF6C(u8 *p, u32 v) {
    *(u32 *)(p + 0x1C) = v;
}

void ov96_021EAF70(u8 *p, u32 a, u32 b) {
    *(u32 *)(p + 0x2C) = a;
    *(u32 *)(p + 0x30) = b;
}
