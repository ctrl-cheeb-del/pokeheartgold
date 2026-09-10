#include "field_effect_path_motion_internal.h"

void *ov01_021FF6B0(void *owner) {
    void *work = ov01_021F1430(owner, 4, 0, 0);
    *(void **)work = owner;
    ov01_021FF6DC(work);
    return work;
}

void ov01_021FF6CC(void *work) {
    ov01_021FF724(work);
    ov01_021F1448(work);
}

void ov01_021FF6DC(void *work) {
    ov01_021F18D4(*(void **)work, 6, 0x79);
    ov01_021F1908(*(void **)work, 6, 0x91);
    ov01_021F1930(*(void **)work, 7, 0x14, 1);
    ov01_021F1758(*(void **)work, 8, 6, 6, 7, 0, ov01_02209200);
}

void ov01_021FF724(void *work) {
    ov01_021F18FC(*(void **)work, 6);
    ov01_021F1924(*(void **)work, 6);
    ov01_021F1970(*(void **)work, 7);
    ov01_021F18C8(*(void **)work, 8);
}

void ov01_021FF74C(void *mapObject) {
    EffectContextPrivate context;
    VecFx32Private position;
    void *manager = ov01_021F146C(mapObject);
    s32 x;
    s32 z;
    context.fieldSystem = MapObject_GetFieldSystem(mapObject);
    context.manager = manager;
    context.work = ov01_021F1450(manager, 11);
    context.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    x = MapObject_GetXCoord(mapObject);
    z = MapObject_GetZCoord(mapObject);
    sub_020611C8(x, z, &position);
    ov01_021F1620(manager, ov01_022091EC, &position, 0, &context, MapObject_GetPriorityPlusValue(mapObject, 2));
}

BOOL ov01_021FF7B0(void *object, void *data) {
    u8 *p = data;
    VecFx32Private position;
    *(FourWordsPrivate *)(p + 0x10) = *(FourWordsPrivate *)sub_02068D98(object);
    *(u32 *)(p + 4) = MapObject_GetID(*(void **)(p + 0x1c));
    *(u32 *)(p + 8) = MapObject_GetMapID(*(void **)(p + 0x1c));
    sub_02068DB8(object, &position);
    *(void **)(p + 0x20) = ov01_021F1740(*(void **)(p + 0x14), 8, &position);
    return TRUE;
}

void ov01_021FF7F4(void *unused, void *data) {
    sub_02023DA4(*(void **)((u8 *)data + 0x20));
}

void ov01_021FF800(void *task, void *data) {
    u8 *p = data;
    if (*(u32 *)p == 0) {
        s32 height;
        sub_02023F04(*(void **)(p + 0x20), 0x1000);
        height = sub_02023F70(*(void **)(p + 0x20));
        if (height / 0x1000 >= 9) {
            ov01_021F1640(task);
        }
    }
}

void ov01_021FF830(void *object, void *data) {
    VecFx32Private position;
    sub_02068DB8(object, &position);
    position.z += 0x8000;
    sub_02023E50(*(void **)((u8 *)data + 0x20), &position);
}
