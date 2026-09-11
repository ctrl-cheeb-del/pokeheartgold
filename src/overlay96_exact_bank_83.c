#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

BOOL ov96_02203CC4(u8 *p, int i) {
    return ov96_021EB57C(*(void **)(p + i * 4 + 0x54));
}

void ov96_02203CD4(u8 *p) {
    p[0x70] = 1;
    p[0x71] = 0;
}
