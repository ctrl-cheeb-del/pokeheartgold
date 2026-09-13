#include "r40_unk_0205975C_private.h"
struct S {
    u8 pad[0x89];
    u8 flags;
};

BOOL sub_0205975C(void *p) {
    BOOL ok;
    if (U16(p, 0x86) == 0) {
        ok = sub_02037108(0x6B, (u8 *)p + 0x84, 1);
    } else {
        ok = sub_02037030(0x6B, (u8 *)p + 0x84, 1);
    }
    if (ok) {
        U8(p, 0x89) = 1 | U8(p, 0x89);
    }
    return ok;
}
