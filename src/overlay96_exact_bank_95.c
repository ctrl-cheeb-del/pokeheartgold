#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u32 ov96_0220B774(u8 *p) {
    if (p == NULL) {
        GF_AssertFail();
    }
    return (*(u32 *)(p + 0x44) << 23) >> 31;
}

u32 ov96_0220B788(u8 *p) {
    if (p == NULL) {
        GF_AssertFail();
    }
    return (*(u32 *)(p + 0x44) << 22) >> 31;
}
