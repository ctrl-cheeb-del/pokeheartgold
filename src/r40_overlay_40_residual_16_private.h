#ifndef SOL_R40_FOLLOWUP_OV40_RES16_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV40_RES16_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
BOOL System_GetTouchHeldCoords(u32 *, u32 *);
void ManagedSprite_TickTwoFrames(void *);
extern const u8 ov40_02244E08[];
extern const u8 ov40_02244E0C[];
BOOL TouchscreenHitbox_TouchHeldIsIn(const void *);
void ov40_0222FA2C(void *, int);
#endif
