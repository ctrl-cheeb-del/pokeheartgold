#ifndef OVERLAY18_MAP_GRID_R19_INTERNAL_H
#define OVERLAY18_MAP_GRID_R19_INTERNAL_H

#include "global.h"

#define S8_AT(p, n)  (*(s8 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

#pragma require_prototypes off

extern const u8 ov18_021FA35A[];
extern const u8 ov18_021FA4B8[];

void ov18_021F11C0(void *, u32, u32);
void *ov18_021F11EC(void *, const void *);
void ov18_021F1160(void *, u32, u32);
void ov18_021F1294(void *, u32, s16, s16, u32);
void ov18_021F61DC(void *, u32, s8, const void *, u32);
void ov18_021F619C(void *, s8, s8, u32);
void ov18_021F65EC(void *);
void ov18_021F4134(void *);
u32 ov18_021E8B18(u32);

#endif
