#include "field_map_object_motion_internal.h"

void ov01_021F73CC(void *obj) {
    s8 *work = sub_0205F3E8(obj, 0x14);
    work[2] = -1;
    ov01_021F9510(obj, work + 4);
    if (*(void **)(work + 4) != NULL) {
        sub_0205F484(obj);
    }
}

void ov01_021F73F4(void *obj) {
    u8 *work = sub_0205F40C(obj);
    ov01_021F95A8(obj, work + 4);
}

void ov01_021F7408(void *obj) {
    u8 *work = sub_0205F40C(obj);
    void *p = *(void **)(work + 4);
    if (p != NULL) {
        ov01_021F9610(p, work + 8);
    }
    ov01_021F95A8(obj, work + 4);
    MapObject_SetFlagsBits(obj, 2 << 20);
}

void ov01_021F7434(void *obj) {
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

void ov01_021F7478(void *obj) {
    typedef struct {
        void *p;
        u8 x04[0xc];
        s8 marker;
        u8 x11[4];
        u8 byte15;
        u8 x16;
        u8 flags;
    } Work;
    Work *work = sub_0205F3E8(obj, 0x18);
    work->marker = -1;
    ov01_021F9510(obj, work);
    work->byte15 = 0;
    work->flags &= ~2;
    work->flags &= ~1;
    if (work->p != NULL) {
        sub_0205F484(obj);
    }
}

void ov01_021F74B4(void *obj) {
    ov01_021F95A8(obj, sub_0205F40C(obj));
}

void ov01_021F74C8(void *obj) {
    u8 *work = sub_0205F40C(obj);
    void *p = *(void **)work;
    if (p != NULL) {
        ov01_021F9610(p, work + 4);
    }
    work[0x17] &= ~2;
    work[0x17] &= ~1;
    ov01_021F95A8(obj, work);
    MapObject_SetFlagsBits(obj, 2 << 20);
}
