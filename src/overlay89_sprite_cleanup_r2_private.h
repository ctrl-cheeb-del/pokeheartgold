#ifndef OVERLAY89_SPRITE_CLEANUP_R2_PRIVATE_H
#define OVERLAY89_SPRITE_CLEANUP_R2_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void Sprite_DeleteAndFreeResources(void *);
void ov89_022598A8(void *);

#endif
