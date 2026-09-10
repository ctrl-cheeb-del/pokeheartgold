#include "field_map_object_motion_internal.h"

void ov01_021F7DA8(void *obj) {
    s8 *work = sub_0205F3E8(obj, 0x14);
    work[0] = -1;
    ov01_021F9510(obj, work + 4);
    if (*(void **)(work + 4) != NULL) {
        sub_0205F484(obj);
    }
}

void ov01_021F7DD0(void *obj) {
    VecFx32 v = { 0, 0, 0 };
    u8 *work = sub_0205F40C(obj);
    ov01_021F95A8(obj, work + 4);
    MapObject_SetFacingVector(obj, &v);
}

void ov01_021F7DFC(void *obj) {
    u8 *work = sub_0205F40C(obj);
    void *p = *(void **)(work + 4);
    if (p != NULL) {
        ov01_021F9610(p, work + 8);
    }
    ov01_021F95A8(obj, work + 4);
    MapObject_SetFlagsBits(obj, 2 << 20);
}

void ov01_021F7E28(void *obj) {
    u8 *work = sub_0205F40C(obj);
    if (ov01_021FA2D4(obj) != TRUE) {
        if (*(void **)(work + 4) == NULL) {
            ov01_021F9510(obj, work + 4);
        }
        if (*(void **)(work + 4) != NULL) {
            ov01_021F9630(*(void **)(work + 4), work + 8);
            ov01_021FA3E8(obj, *(void **)(work + 4));
            MapObject_ClearFlagsBits(obj, 2 << 20);
        }
    }
}
