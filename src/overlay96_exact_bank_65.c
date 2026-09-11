#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021F83BC(int unused, void **p) {
    ov96_021F8918(p[1]);
    ov96_021F8354((u32 *)p);
}

void *ov96_021F83D0(u8 *p) {
    return p + 4 + p[0x5B] * 0x10;
}
