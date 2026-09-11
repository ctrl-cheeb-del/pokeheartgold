#ifndef SOL40_R37_PRIVATE_H
#define SOL40_R37_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void *ov96_021EB4F4(void *, int, int);
void *ov96_021EB5B8(void *);
void Sprite_SetOamMode(void *, int);
void Sprite_SetDrawPriority(void *, int);
void ov96_021EB52C(void *, int, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetMatrix(void *, VecFx32 *);
int ov96_021F32FC(int, int, int, int, u16);
extern void *ov96_0221DBC8[];
extern void *ov96_0221DBB8[];
#endif
void *Heap_Alloc(int, u32);
void MI_CpuFill8(void *, u8, u32);
typedef struct SolR37Work {
    u8 pad[0x4e4];
    u8 f4e4, f4e5, f4e6, f4e7, f4e8, f4e9, f4ea;
} SolR37Work;

typedef struct SolR37Slot {
    s32 state;
    void *a;
    s32 idx;
    void *sprite;
    void *b;
    s32 slot;
    void *f;
    void *e;
} SolR37Slot;
typedef struct SolR37AnimSlot {
    s32 state;
    void *record;
    s32 kind;
    void *sprite;
} SolR37AnimSlot;
typedef struct SolR37AnimWork {
    SolR37AnimSlot slots[8];
    s32 current;
} SolR37AnimWork;
