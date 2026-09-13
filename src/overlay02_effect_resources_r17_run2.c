#include "overlay02_effect_resources_r17_private.h"

void *ov02_0224A9B8(void *p, void *arg) {
    return ov02_0224A33C(p, arg, 3, 3, 3, -1, 0, 0x81);
}

void ov02_0224A9D8(void *p, void *owner) {
    int i;
    const Ov02R17Entry *entry = ov02_022535E4;
    VecFx32 position;
    VecFx32 offset;
    u32 priority;
    u32 value;
    U32(p, 0x14) = 2;

    for (i = 0; i < 13; i++, entry++) {
        position.x = entry->x;
        position.y = entry->y;
        position.z = 0;
        offset.x = entry->parameter;
        offset.y = 0;
        offset.z = 0;
        value = entry->value;
        priority = entry->priority;
        ov02_0224AA44(p, &position, &offset, value, priority, owner);
        position.x += FX32_CONST(256);
        ov02_0224AA44(p, &position, &offset, value, priority, owner);
    }
}

void ov02_0224AA44(void *p, const VecFx32 *position, const VecFx32 *offset, u32 value, u32 parameter, void *owner) {
    Ov02R17EffectArgs args;

    args.value = value;
    args.owner = owner;
    args.context = p;
    args.offset = *offset;
    sub_02068B0C(PTR(p, 0x1e0), &ov02_02253468, position, parameter, &args, 0x85);
}

int ov02_0224AA80(void *task, Ov02R17TaskWork *work) {
    VecFx32 position;
    Ov02R17TaskArgs *args = sub_02068D98(task);
    work->args = *args;
    work->effectParam = sub_02068D90(task);
    sub_02068DB8(task, &position);
    work->sprite = ov02_0224A3F0(work->args.position.z, &position, work->args.position.x, work->effectParam);
    Sprite_SetDrawFlag(work->sprite, FALSE);
    return TRUE;
}
