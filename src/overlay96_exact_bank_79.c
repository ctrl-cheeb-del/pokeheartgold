#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_02200BC8(u8 *p, int i) {
    return *(u16 *)(p + i * 2 + 0x160);
}
