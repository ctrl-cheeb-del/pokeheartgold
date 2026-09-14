#ifndef POKEHEARTGOLD_OVERLAY49_CAMERA_LOOKAT_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_CAMERA_LOOKAT_PRIVATE_H

#include "global.h"

#define PTR(p, off)    (*(void **)((u8 *)(p) + (off)))
#define S32_AT(p, off) (*(s32 *)((u8 *)(p) + (off)))

void ov49_02259154(void *object, void *position);
void Camera_PushLookAtToNNSGlb(void);
void ov49_0225CBF4(void *p);

#endif
