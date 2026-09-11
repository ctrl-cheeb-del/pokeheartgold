#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_021E9CF4(u8 *p, u32 mask) {
    if (p == NULL) {
        return 0;
    }
    return *(u32 *)(p + 4) & mask;
}

void *ov96_021E9D08(u8 *p, int i) {
    return *(void **)(p + i * 4 + 0xC);
}
