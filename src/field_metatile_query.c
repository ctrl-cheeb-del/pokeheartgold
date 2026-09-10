#include "field_metatile_query_internal.h"

u8 GetMetatileBehavior(FieldSystem *fieldSystem, int x, int z) {
    u16 attr;
    int behavior;
    if (FS_VT(fieldSystem)->getAttr(fieldSystem, x, z, &attr)) {
        behavior = (u8)attr;
        return (u8)behavior;
    }
    return 0xFF;
}
