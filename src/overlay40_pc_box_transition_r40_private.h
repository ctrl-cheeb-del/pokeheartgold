#ifndef POKEHEARTGOLD_OVERLAY40_PC_BOX_TRANSITION_R40_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_PC_BOX_TRANSITION_R40_PRIVATE_H

#include "global.h"

#define OV40_R40_PTR(p, off) (*(void **)((u8 *)(p) + (off)))
#define OV40_R40_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))

typedef int (*Ov40R40StateFunc)(u8 *);

extern const Ov40R40StateFunc ov40_02245C18[];

void TouchHitboxController_IsTriggered(void *controller);
int ov40_0224301C(u8 *work, int value);
void ov40_0224320C(u8 *work, int state);
void ov40_02243EB0(u8 *work, int idx);
void ov40_02243F88(u8 *work);
void ov40_022439B8(u8 *work);
void ov40_02244060(u8 *work);
void ov40_022440A0(u8 *work, int value);

int ov40_02243284(u8 *work);
int ov40_02243538(u8 *work);
void ov40_0224395C(u8 *work);

#endif
