#ifndef SOL_R40_FOLLOWUP_OV40_GAP2_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV40_GAP2_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S64(p, o) (*(s64 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct SolGapEntry {
    u32 a, value, code;
    void *sprite;
    u8 pad[12];
} SolGapEntry;
int ov40_02244054(u32, u32);
void ManagedSprite_SetAnim(void *, int);
void ov40_0224320C(void *, int);
void *String_New(int, int);
void String_Delete(void *);
void String16_FormatInteger(void *, int, int, int, int);
void String_Cat(void *, void *);
#endif
