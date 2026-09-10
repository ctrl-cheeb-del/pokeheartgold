#include "field_map_object_motion_internal.h"

void ov01_021F77A4(void *obj) {
    u8 *work = sub_0205F40C(obj);
    if (ov01_021FA2D4(obj) != TRUE) {
        void *other = *(void **)(work + 4);
        if (other != NULL) {
            ov01_021FA3E8(obj, other);
            ov01_021F8C88(obj, other);
        }
    }
}

void ov01_021F77D0(void *obj) {
    u8 *work = sub_0205F40C(obj);
    if (ov01_021FA2D4(obj) != TRUE) {
        void *other = *(void **)(work + 4);
        if (other != NULL) {
            if (!ov01_021F9344(obj)) {
                sub_02023F04(other, FX32_ONE);
            }
            ov01_021FA3E8(obj, other);
            ov01_021F8C88(obj, other);
        }
    }
}
