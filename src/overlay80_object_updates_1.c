#include "overlay80_object_updates_internal.h"

void ov80_02239BF0(void *arg0, void *arg1, u32 type, const s16 *values, s32 count) {
    u8 *object = ov80_02239938(arg0, arg1);
    u8 *destination = object;
    s32 i;
    MI_CpuFill8(object + 0x26, 0, 0x10);
    object[0x26] = type;
    for (i = 0; i < count; i++) {
        *(s16 *)(destination + 0x28) = *values++;
        destination += 2;
    }
}

void ov80_02239C28(void *owner, void *object) {
    u8 *base = object;
    Overlay80UpdateFunc func = ov80_0223DB24[base[0x26]];
    if (func != NULL && func(owner, object) == TRUE) {
        MI_CpuFill8(base + 0x26, 0, 0x10);
    }
}

void ov80_02239C54(void *owner) {
    u8 *object = sub_02096868(owner);
    s32 i;
    for (i = 0; i < 0x20; i++, object += 0x3C) {
        if (*(void **)object != NULL && *(void **)(object + 0x38) == NULL) {
            ov80_02239C28(owner, object);
        }
    }
}
