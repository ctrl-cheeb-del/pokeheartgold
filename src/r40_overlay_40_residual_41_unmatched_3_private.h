#ifndef OV40_U3_R40_PRIVATE_H
#define OV40_U3_R40_PRIVATE_H
#include "global.h"
typedef struct Ov40State {
    u8 raw[0x300];
} Ov40State;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
void ov40_02244060(Ov40State *);
void ov40_022441F8(Ov40State *);
#endif
