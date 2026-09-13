#ifndef OVERLAY_68_RESIDUAL_16_R40_PRIVATE_H
#define OVERLAY_68_RESIDUAL_16_R40_PRIVATE_H

#include "overlay68_helpers_internal.h"

void GridInputHandler_SetEnabledFlag(void *handler, u32 target);
void GridInputHandler_ClearEnabledFlag(void *handler, u32 target);
void GridInputHandler_SetNextInput(void *handler, int next);
void ScheduleWindowCopyToVram(void *window);
void ManagedSprite_SetAnimateFlag(void *sprite, int flag);
void ManagedSprite_SetAnimationFrame(void *sprite, u16 frame);
void ManagedSprite_SetAnim(void *sprite, int anim);
void ov68_021E66A0(MoveRelearner *d, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void ov68_021E67E0(MoveRelearner *d);
void ov68_021E73A4(MoveRelearner *d, u8 selection, u32 a2);
void ov68_021E7618(MoveRelearner *d, s32 selection, u32 direction);
void ov68_021E7898(MoveRelearner *d, u32 enabled);
void ov68_021E7910(MoveRelearner *d);
void ov68_021E797C(MoveRelearner *d, s32 direction);
void ov68_021E7A18(MoveRelearner *d, u32 selected);

#endif
