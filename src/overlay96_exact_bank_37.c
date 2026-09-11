#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021ECC38(u8 *p, int i, u32 add) {
    if (add != 0) {
        ov96_021ECDD4(p + i * 0x1C, add);
    }
}

void *ov96_021ECC4C(u8 *p, int i) {
    return *(void **)(p + i * 0x1C + 0x10);
}
