#ifndef PRIVATE_OVERLAY_80_02239BF0_H
#define PRIVATE_OVERLAY_80_02239BF0_H

#include "global.h"

typedef BOOL (*Overlay80UpdateFunc)(void *, void *);
extern const Overlay80UpdateFunc ov80_0223DB24[2];

void *ov80_02239938(void *arg0, void *arg1);
void *sub_02096868(void *owner);
void *sub_0209680C(void *owner);
void ov80_0222EFD0(void *out, u32 value, u16 value2, s32 value3);
void ov42_022299C0(void *object, const void *value);

void ov80_02239BF0(void *arg0, void *arg1, u32 type, const s16 *values, s32 count);
void ov80_02239C28(void *owner, void *object);
void ov80_02239C54(void *owner);
BOOL ov80_02239C80(void *owner, void *object);

#endif
