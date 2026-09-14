#include "to46_map_object_updates_private.h"

const TileTestFunc _020FD4CC[4] = { sub_0205B8F4, sub_0205B918, sub_0205B93C, sub_0205B960 };
const TileTestFunc _020FD4BC[4] = { sub_0205B918, sub_0205B8F4, sub_0205B960, sub_0205B93C };
const s32 _020FD4AC[4] = { 0, 0, -1, 1 };
const s32 _020FD49C[4] = { -1, 1, 0, 0 };
const s32 _020FD4DC[4] = { 1, 0, 3, 2 };

void sub_0205FEDC(LocalMapObject *object) {
    u8 previous;
    u8 current;
    void *effect;
    sub_02061108(object);
    if (sub_0205F73C(object) == 1) {
        previous = sub_0205F504(object);
        current = sub_0205F514(object);
        effect = ov01_021F9318(object);
        sub_02060AB8(object, previous, current, effect);
        sub_020601BC(object, previous, current, effect);
        sub_0206039C(object, previous, current, effect);
        sub_020603DC(object, previous, current, effect);
        sub_020601A4(object, previous, current, effect);
        sub_02060698(object, previous, current, effect);
        sub_02060700(object, previous, current, effect);
        sub_020607D8(object, previous, current, effect);
    }
}

void sub_0205FF6C(LocalMapObject *object) {
    u8 previous;
    u8 current;
    void *effect;
    sub_02061108(object);
    if (sub_0205F73C(object) == 1) {
        previous = sub_0205F504(object);
        current = sub_0205F514(object);
        effect = ov01_021F9318(object);
        sub_02060AB8(object, previous, current, effect);
        sub_02060274(object, previous, current, effect);
        sub_02060328(object, previous, current, effect);
        sub_0206039C(object, previous, current, effect);
        sub_020603F8(object, previous, current, effect);
        sub_020606CC(object, previous, current, effect);
        sub_02060704(object, previous, current, effect);
        sub_02060708(object, previous, current, effect);
        sub_02060770(object, previous, current, effect);
        sub_020607D8(object, previous, current, effect);
        sub_02060AF0(object, previous, current, effect);
    }
}
