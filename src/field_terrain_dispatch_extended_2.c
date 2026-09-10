#include "field_terrain_dispatch_extended_internal.h"

void sub_02054DC8(int idx, int width, VecFx32 *pos) {
    pos->x = 0x100000;
    pos->z = 0x100000;
    pos->x = pos->x + ((u16)(idx % width) << 21);
    pos->z = pos->z + ((u16)(idx / width) << 21);
}

BOOL sub_02054E00(u16 a0) {
    int i;
    const u16 *p = _020FC60C;
    for (i = 0; i < 4; i++) {
        if (a0 == *p) {
            return TRUE;
        }
        p++;
    }
    return FALSE;
}

BOOL sub_02054E20(u16 a0) {
    int i;
    const u16 *p;
    if (!sub_02054E00(a0)) {
        return FALSE;
    }
    p = _020FC5FC;
    for (i = 0; i < 3; i++) {
        if (a0 == *p) {
            return TRUE;
        }
        p++;
    }
    return FALSE;
}
