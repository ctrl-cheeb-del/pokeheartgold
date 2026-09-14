#ifndef TO46_OVERLAY_14_RESIDUAL_32_PRIVATE_H
#define TO46_OVERLAY_14_RESIDUAL_32_PRIVATE_H

#include "global.h"

void PlaySE(u32);
void GridInputHandler_SetNextInput(void *, u32);
void *GridInputHandler_GetDpadBox(void *, u32);
void DpadMenuBox_GetPosition(void *, u8 *, u8 *);
void ManagedSprite_SetPositionXY(void *, s32, s32);
void GridInputHandler_SetButtonInputMode(void *, u32);

void ov14_021F3044(void *);
void ov14_021E7ED0(void *);
void ov14_021E7EE0(void *);
u32 ov14_021F0234(void *, void *, u32);
u32 ov14_021E9518(void *);
void ov14_021F08BC(void *);
void ov14_021E91E0(void *);
void ov14_021E637C(void *);
void ov14_021F08F0(void *);
void ov14_021E765C(void *);
void ov14_021E7F4C(void *);
void ov14_021E8328(void *);
void ov14_021E95B4(void *);
void ov14_021F6678(void *, u32);
void ov14_021F685C(void *, u32, u32, u32);

void ov14_021EDE38(void *);
void ov14_021EDE70(void *);
void ov14_021EDE88(void *);
void ov14_021EDF08(void *);
u32 ov14_021EDF28(void *);

#endif
