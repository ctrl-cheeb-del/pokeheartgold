#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

BOOL ov96_021ECDC4(u8 *p) {
    return *(u32 *)(p + 0x18) == 0;
}

void ov96_021ECDD4(u8 *p, u32 add) {
    u32 value = *(u32 *)(p + 0x10) + add;
    if (value > 999) {
        value = 999;
    }
    *(u32 *)(p + 0x10) = value;
    *(u32 *)(p + 0x18) = 1;
}
