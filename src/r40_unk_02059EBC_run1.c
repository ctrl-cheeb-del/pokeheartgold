#include "r40_unk_02059EBC_private.h"

void sub_02059EBC(void *p) {
    if (sub_02037FCC()) {
        _021D41CC = 0;
        sub_0205A034(p, sub_02059F78, 0);
        return;
    }
    if (U32(p, 0x20) != 0) {
        U32(p, 0x28) = 2;
        if (U32(p, 0x20) == 1) {
            if (U32(p, 0x30) == 5) {
                sub_0203894C(PTR(p, 0x18));
            } else if (U32(p, 0x30) == 6) {
                sub_0203898C(PTR(p, 0x18));
            } else {
                sub_02037F64(PTR(p, 0x18));
            }
        } else if (U32(p, 0x20) == 2) {
            sub_0208F814(0);
            sub_02038918(PTR(p, 0x18));
        }
        sub_0205A034(p, sub_0205A0B4, 0xC);
    }
}
