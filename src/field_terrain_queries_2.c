#include "field_terrain_queries_internal.h"

int sub_02054774(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind) {
    return sub_02054654(fieldSystem, 0, a1, x, z, outKind);
}

int sub_02054790(FieldSystem *fieldSystem, int a1, int a2, fx32 x, fx32 z, u8 *outKind) {
    return sub_02054654(fieldSystem, a1, a2, x, z, outKind);
}

int sub_020547A4(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind) {
    BOOL ok = ov01_021F654C(fieldSystem->mapLoadManager, x / 0x10000, z / 0x10000, NULL);
    if (outKind != NULL) {
        *outKind = ok ? 1 : 0;
    }
    return 0;
}

BOOL sub_020547D8(FieldSystem *fieldSystem, int x, int z, u16 *outAttr) {
    MapLoadManager *mapLoadManager = fieldSystem->mapLoadManager;
    u8 idx;
    u16 *attrs;
    if (!ov01_021F654C(mapLoadManager, x, z, &idx)) {
        *outAttr = 0xFF;
        return FALSE;
    }
    attrs = ov01_021F65E4(mapLoadManager, idx);
    *outAttr = attrs[x % 32 + z % 32 * 32];
    return TRUE;
}

BOOL sub_02054824(FieldSystem *fieldSystem, int x, int z, u16 *outAttr) {
    const u16 *attrs = TerrainAttributes_Get(x / 32 + z / 32 * MapMatrix_GetWidth(fieldSystem->mapMatrix), fieldSystem->terrainAttributes);
    *outAttr = attrs[x % 32 + z % 32 * 32];
    return TRUE;
}
