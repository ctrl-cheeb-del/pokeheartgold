#include "field_terrain_queries_internal.h"

void sub_0205489C(void **a0, int a1) {
    if (a1 == 0) {
        *a0 = (void *)&_020FC604;
    } else if (a1 == 1) {
        *a0 = (void *)&_020FC614;
    } else {
        GF_AssertFail();
    }
}

BOOL sub_020548C0(FieldSystem *fieldSystem, int x, int z) {
    u16 attr;
    if (FS_VT(fieldSystem)->getAttr(fieldSystem, x, z, &attr)) {
        if ((u8)((u8)(attr >> 15) & 1) == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

u8 sub_020548EC(FieldSystem *fieldSystem, int x, int z) {
    u16 attr;
    if (FS_VT(fieldSystem)->getAttr(fieldSystem, x, z, &attr)) {
        return (u8)(attr >> 8) & 0x7F;
    }
    return 0;
}
