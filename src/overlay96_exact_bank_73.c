#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void *ov96_021FC0D0(void **p, u32 i) {
    if (i >= 3) {
        GF_AssertFail();
    }
    return p[i * 2];
}

void *ov96_021FC0E4(u8 *p) {
    return p + 0x18;
}

void *ov96_021FC0E8(u8 *p) {
    return p + 0x618;
}

int ov96_021FC0F4(void) {
    return 0x600;
}
