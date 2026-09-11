#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_021F27A8(u8 *p) {
    int i = *(int *)(p + 0xC) - 1;
    if (i < 0) {
        return 0xFF;
    }
    *(int *)(p + 0xC) = i;
    return p[i];
}
