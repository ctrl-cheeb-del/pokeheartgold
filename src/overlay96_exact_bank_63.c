#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021F81C0(u8 *p, u32 v) {
    p[0x58] = 3;
    *(u32 *)(p + 0x54) = v;
}
