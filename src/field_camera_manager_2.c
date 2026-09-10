#include "field_camera_manager_internal.h"

void ov01_021EAE50(void *camera, const u16 *start, const u16 *end, u32 step, u8 total) {
    u16 angle[4] = { 0, 0, 0, 0 };
    s32 change;
    u16 initial = *start;
    if (*end >= initial) {
        u16 difference = *end - initial;
        change = ((s32)difference * (s32)step) / (s32)total;
    } else {
        u16 difference = initial - *end;
        change = -(((s32)difference * (s32)step) / (s32)total);
    }
    angle[0] = initial + change;
    Camera_SetAnglePos(angle, camera);
}

void ov01_021EAEA4(void *camera, const VecFx32Private *delta, u32 step, u32 total) {
    VecFx32Private offset = { 0, 0, 0 };
    offset.x = ov01_021EAEE0(delta->x, step, total);
    offset.z = ov01_021EAEE0(delta->z, step, total);
    Camera_OffsetLookAtPosAndTarget(&offset, camera);
}

s32 ov01_021EAEE0(s32 value, s32 step, s32 total) {
    s32 current = value * step / total;
    s32 previous = value * (step - 1) / total;
    return current - previous;
}
