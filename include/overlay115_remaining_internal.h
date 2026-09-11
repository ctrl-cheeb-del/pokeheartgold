#ifndef PRIVATE_OVERLAY_115_H
#define PRIVATE_OVERLAY_115_H
#include "global.h"

typedef struct Ov115Motion {
    u8 raw[0x14];
} Ov115Motion;

typedef struct Ov115Work {
    s16 delay;
    s16 count;
    void *sprites[4];
    Ov115Motion motion[4];
} Ov115Work;

void *ov01_021F0718(void *, void *, void *, void *, int, int);
void Sprite_SetDrawFlag(void *, int);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAffineOverwriteMode(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void ov01_021EFE70(void *, fx32, fx32, int);
void ov115_0225F020(Ov115Work *, void *, void *, void *, void *);
#endif
