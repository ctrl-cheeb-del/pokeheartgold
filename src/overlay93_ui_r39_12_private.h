#ifndef TO40_R39_OVERLAY93_PRIVATE_H
#define TO40_R39_OVERLAY93_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

#define PAT(p, o) (*(void **)((u8 *)(p) + (o)))

extern const ManagedSpriteTemplate ov93_02262E9C;
extern const ManagedSpriteTemplate ov93_02262ED0;

void ov93_02261BBC(void *sys, void *slots);

#endif
