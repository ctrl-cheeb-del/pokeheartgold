#ifndef R16_OVERLAY102_PRIVATE_H
#define R16_OVERLAY102_PRIVATE_H
#include "global.h"

typedef struct ScrollTask102 {
    void *bg;
    u32 layer;
    u32 axis;
    s32 position;
    s32 target;
    s32 step;
    u16 frames;
    u16 state;
    void *task;
} ScrollTask102;

typedef struct BlendTask102 {
    u32 plane1;
    u32 plane2;
    s32 value;
    s32 target;
    s32 step;
    u32 frames;
    u32 done;
    void *task;
} BlendTask102;

s32 Bg_GetXpos(void *, u32);
s32 Bg_GetYpos(void *, u32);
void BgSetPosTextAndCommit(void *, u8, u8, s32);
void *ov102_021E93D4(void (*)(void *, void *), void *, u32);
void SysTask_Destroy(void *);
s32 _s32_div_f(s32, s32);

void ov102_021EC298(ScrollTask102 *, void *, u32, u32, s32, s32);
BOOL ov102_021EC2EC(ScrollTask102 *);
void ov102_021EC338(void *, ScrollTask102 *);
void ov102_021EC37C(BlendTask102 *, u32, u32, s32, s32, s32);
BOOL ov102_021EC3AC(BlendTask102 *);
void ov102_021EC3D4(void *, BlendTask102 *);
void ov102_021EC410(BlendTask102 *, u32, s32, s32, s32);
BOOL ov102_021EC450(BlendTask102 *);
void ov102_021EC478(void *, BlendTask102 *);

#endif
