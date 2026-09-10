#include "field_map_object_motion_internal.h"

void ov01_021F8A4C(void *obj) {
    s8 *work = sub_0205F40C(obj);
    void *other = *(void **)(work + 4);
    int facing;
    if (ov01_021FA2D4(obj) != TRUE && other != NULL) {
        facing = MapObject_GetFacingDirection(obj);
        if (facing != work[0]) {
            sub_02023EE0(other, ov01_021FA44C(facing));
            sub_02023F40(other, 0);
        }
        sub_02023F04(other, FX32_ONE);
        ov01_021FA3E8(obj, other);
        ov01_021F8C88(obj, other);
        work[0] = facing;
        work[2] = sub_0205F330(obj);
    }
}
