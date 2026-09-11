#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_0220B730(u8 *p) {
    if (p == NULL) {
        GF_AssertFail();
    }
    return (*(u32 *)(p + 0x40) >> 2) & 0xff;
}
