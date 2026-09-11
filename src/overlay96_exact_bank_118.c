#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_022186B8(u8 *p, const s16 *v) {
    *(s32 *)(p + 0x20) = v[0] << 12;
    *(s32 *)(p + 0x24) = v[1] << 12;
}
