#ifndef TO47_OVERLAY49_RESOURCE_CURSOR_PRIVATE_H
#define TO47_OVERLAY49_RESOURCE_CURSOR_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

void ov49_0225CDEC(void *state, u32 a, u32 b, u32 heapId, u32 allocatorSize);
void ov49_0225CE88(void *state);
void ov49_0225CED0(void *state);
void ov49_0225CEFC(void *state);
void *ov49_0225CF28(void *state, s32 index, s32 selection, const void *value);

void GF_AssertFail(void);
void *NARC_New(u32 narcId, u32 heapId);
void NARC_Delete(void *narc);
void HeapExp_FndInitAllocator(void *allocator, u32 size, s32 align);
void sub_020181B0(void *a, void *b);
void sub_020181D4(void *a, void *b);
void sub_020181E0(void *a, void *b);
void sub_020182A0(void *a, u32 b);
void *ov49_0225D4FC(u32 a, u32 b, u32 heapId);
void ov49_0225D520(void *resource);
void ov49_0225D5FC(void *a, void *narc, void *resource, u32 count, void *allocator);
void ov49_0225D6AC(void *a, void *allocator);
void ov49_0225D6F0(void *state, void *a);
void ov49_0225D76C(void *state, void *a);
void *ov49_0225D820(void *state);
void ov49_0225D854(void *a, void *narc, void *allocator, void *resource, u32 count);
void ov49_0225D9D0(void *a, void *allocator);
void ov49_0225DC2C(void *a, void *narc, void *allocator, void *resource, u32 count);
void ov49_0225DCBC(void *a, void *allocator);
void ov49_0225CFA8(void *cursor, const void *vec);
void ov49_0225CFEC(void *cursor, const void *vec);

#endif
