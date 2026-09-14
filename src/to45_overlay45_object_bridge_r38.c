#include "to45_overlay45_object_bridge_r38_private.h"

u32 ov45_022308B8(Overlay45R38Object *object) {
    return object->type;
}

void ov45_022308C0(Overlay45R38Object *object, const s16 *source) {
    Overlay45R38Vec position;

    ov49_02258800(source, (s32 *)&position);
    position.z += 0x10000;
    ov45_022308E4(object, &position);
}

void ov45_022308E4(Overlay45R38Object *object, const Overlay45R38Vec *position) {
    sub_02023E50(object->handle, position);
    sub_020182A8(object->model, position->x, 0x2000, position->z - 0x8000);
}

void ov45_02230908(Overlay45R38Object *object, Overlay45R38Vec *position) {
    *position = *sub_02023E68(object->handle);
}

void ov45_02230920(Overlay45R38Object *object) {
    sub_02023EE0(object->handle, ov45_022309C4(1));
    sub_02023F40(object->handle, 0);
}

void ov45_0223093C(Overlay45R38Object *object, u32 value) {
    object->active = 1;
    object->value = value;
    object->byte2 = 0;
    object->byte3 = 1;
}
