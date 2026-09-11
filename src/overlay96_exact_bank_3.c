#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021E6670(u8 *p, u32 v) {
    *(u32 *)(p + 0x718) = v;
}
