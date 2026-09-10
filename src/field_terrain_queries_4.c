#include "field_terrain_queries_internal.h"

int sub_02054940(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind) {
    return FS_VT(fieldSystem)->getHeight(fieldSystem, a1, x, z, outKind);
}
