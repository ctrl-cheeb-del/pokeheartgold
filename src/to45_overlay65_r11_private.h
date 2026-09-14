#ifndef TO45_OV65_R11_PRIVATE_H
#define TO45_OV65_R11_PRIVATE_H

#include "global.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
void ov65_0221FB90(void *, u32, u32, u32, void *);
u32 ov65_0221FC54(void *, void *, void *, void *, u32);
u32 ov65_0221F79C(void *);
u32 ov65_0221F7E0(void *);
void ov65_0221F0C4(void *);
void ov65_0221DE24(void *, u32, u32);
void ov65_0221F5A0(void *, void *, u32, u32, void *);
void *ov65_0221E928(void *, u32, u32);
void *Party_GetMonByIndex(void *, u32);
void *Mon_GetBoxMon(void *);
void BufferBoxMonNickname(void *, u32, void *);
void *ListMenuItems_New(u32, u32);
void ListMenuItems_AppendFromMsgData(void *, void *, u32, u32);
void sub_02034AEC(void *, u32);

u32 ov65_0221F120(void *);
void ov65_0221F0D8(void *, u32, u32);
u32 ov65_0221F258(void *);
u32 ov65_0221F2A8(void *);
u32 ov65_0221F354(void *);
u32 ov65_0221F3B0(void *);
u32 ov65_0221F3F4(void *);
u32 ov65_0221E270(void *);
u32 ov65_0221F4D4(void *);

#endif
