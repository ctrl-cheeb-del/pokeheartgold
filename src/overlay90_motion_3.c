#include "overlay90_motion_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov90_0225A108(void *p) {
    if (PTR(p, 0x304)) {
        Main_SetHBlankIntrCB(NULL, NULL);
        sub_02014A38(PTR(p, 0x304));
        PTR(p, 0x304) = NULL;
    }
}
