#ifndef OVERLAY_34_SCRATCH_OVERLAY34_REMAINING_INTERNAL_H
#define OVERLAY_34_SCRATCH_OVERLAY34_REMAINING_INTERNAL_H
#include "global.h"
typedef struct {
    u8 raw[0x400];
} Ov34State;
extern int FieldSystem_TaskIsRunning(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void ov34_0225D558(Ov34State *, void *);
extern void ov01_021F6A9C(void *, int, int);
void ov34_0225D5A0(void *, Ov34State *);
#endif
