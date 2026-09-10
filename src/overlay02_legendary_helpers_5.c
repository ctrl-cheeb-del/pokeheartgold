#include "overlay_02_legendary_internal.h"

void ov02_0224662C(void *data) {
    u8 *p = data;
    *(u16 *)(p + 0x10) = 0;
    Camera_SetStaticPtr(*(void **)((u8 *)*(void **)(p + 4) + 0x24));
}
