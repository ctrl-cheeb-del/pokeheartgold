#ifndef TO47_OVERLAY14_BOX_ACTION_HANDLERS_PRIVATE_H
#define TO47_OVERLAY14_BOX_ACTION_HANDLERS_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern void ov14_021E76B8(void *);
extern void ov14_021E8328(void *);
extern void ov14_021E84A4(void *);
extern void ov14_021E884C(void *);
extern u32 ov14_021EA130(void *);
extern u32 ov14_021F0234(void *, void *, u32);
extern u32 ov14_021F0AD8(void *);
extern u32 ov14_021F0C88(void *);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021F40E8(void *, u32);
extern void ov14_021F5EB4(void *, u32);

void ov14_021F2818(void *);
void ov14_021F2858(void *);
void ov14_021F2874(void *);

#endif
