#include "overlay90_motion_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov90_02259EAC(void *p) {
    if (PTR(p, 0x10)) {
        Sprite_Delete(PTR(p, 0x10));
        PTR(p, 0x10) = NULL;
    }
    if (PTR(p, 0x14)) {
        Sprite_Delete(PTR(p, 0x14));
        PTR(p, 0x14) = NULL;
    }
    if (WindowIsInUse(p) == 1) {
        RemoveWindow(p);
    }
}
