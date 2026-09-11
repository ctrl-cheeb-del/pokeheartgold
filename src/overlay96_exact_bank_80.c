#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02200E78(u8 *p, int i, u32 v) {
    *(u32 *)(p + i * 0x10) = v;
}
