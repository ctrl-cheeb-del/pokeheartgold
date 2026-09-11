#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void *ov96_021F75D4(u8 *p, int i) {
    return p + i * 0x1C + 4;
}

void *ov96_021F75E0(u8 *p, int i) {
    return *(void **)(p + i * 0x1C);
}
