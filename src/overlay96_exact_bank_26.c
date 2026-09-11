#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EAEC8(u8 *p, u32 *a, u32 *b) {
    *a = *(u32 *)(p + 0x20);
    *b = *(u32 *)(p + 0x24);
}
