#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u16 ov96_0220AD4C(u8 *p) {
    if (p == NULL) {
        GF_AssertFail();
    }
    return *(u32 *)(p + 0x17C) >> 16;
}
