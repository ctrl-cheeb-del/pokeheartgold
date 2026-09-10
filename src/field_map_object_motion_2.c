#include "field_map_object_motion_internal.h"

void ov01_021F7704(void *obj) {
    u8 *work = sub_0205F40C(obj);
    work[0x15] = 0;
    *(u32 *)((u8 *)MapObject_GetFacingVector(obj) + 4) = 0;
}

void *ov01_021F771C(void *manager) {
    return *(void **)sub_0205F40C(MapObjectManager_GetFirstActiveObjectByID(manager, 0xfd));
}
