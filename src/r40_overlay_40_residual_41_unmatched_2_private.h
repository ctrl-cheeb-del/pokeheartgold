#ifndef SOL_R40_OVERLAY_40_RESIDUAL_41_UNMATCHED_2_PRIVATE_H
#define SOL_R40_OVERLAY_40_RESIDUAL_41_UNMATCHED_2_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_TickFrame(void *sprite);
u32 ManagedSprite_GetActiveAnim(void *sprite);
BOOL ManagedSprite_IsAnimated(void *sprite);
void ManagedSprite_SetAnim(void *sprite, u32 anim);
void ov40_02243E80(void *work, int index, int draw);

void ov40_02243EEC(void *work, int index);
void ov40_02243F38(void *work, int index, int slot);
void ov40_02243F88(void *work);

#endif
