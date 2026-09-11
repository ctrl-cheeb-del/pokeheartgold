#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021FDE6C(int unused, u32 x, u32 y) {
    if (x < 0x40 && y < 0x20) {
        return 1;
    }
    return 0;
}
