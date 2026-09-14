#include "r47_overlay49_residual12_private.h"

void *ov49_022593C0(void *p) {
    int i;

    for (i = 0; i < U16(p, 0xC); i++) {
        if (ov49_022593FC((u8 *)PTR(p, 8) + i * 0x28)) {
            return (u8 *)PTR(p, 8) + i * 0x28;
        }
    }
    GF_AssertFail();
    return (u8 *)PTR(p, 8) + i * 0x28;
}
