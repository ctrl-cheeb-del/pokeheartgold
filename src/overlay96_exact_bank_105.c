#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u16 ov96_022104C4(u8 *p) {
    return *(u16 *)(p + 0xE6) + p[0xE5] * 0x80;
}
