#include "field_terrain_dispatch_internal.h"

SoundplateStruct *sub_02054874(FieldSystem *fieldSystem, int x, int z) {
    MapLoadManager *mapLoadManager = fieldSystem->mapLoadManager;
    u8 idx;
    if (ov01_021F654C(mapLoadManager, x, z, &idx) == 0) {
        return NULL;
    }
    return ov01_021F6600(mapLoadManager, idx);
}
