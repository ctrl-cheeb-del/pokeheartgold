#include "field_map_object_motion_internal.h"

void ov01_021F88F0(void *obj) {
    u8 *work = sub_0205F40C(obj);
    void *other = *(void **)(work + 4);
    int facing;
    if (ov01_021FA2D4(obj) != TRUE && other != NULL) {
        facing = MapObject_GetFacingDirection(obj);
        work[0] = facing;
        work[2] = sub_0205F330(obj);
        sub_02023EE0(other, ov01_021FA44C(facing));
        sub_02023F40(other, 0);
        sub_02023F04(other, 0);
        ov01_021FA3E8(obj, other);
        ov01_021F8C88(obj, other);
    }
}

void ov01_021F894C(void *obj) {
    u8 *work = sub_0205F40C(obj);
    void *other = *(void **)(work + 4);
    if (ov01_021FA2D4(obj) != TRUE && other != NULL) {
        work[0] = MapObject_GetFacingDirection(obj);
        work[2] = sub_0205F330(obj);
        if (sub_02023EF4(other) != FALSE) {
            sub_02023EE0(other, 0);
            sub_02023F40(other, 0);
        }
        sub_02023F04(other, FX32_ONE);
        ((VecFx32 *)MapObject_GetFacingVector(obj))->z = 2 << 10;
        ov01_021FA3E8(obj, other);
        ov01_021F8C88(obj, other);
    }
}
