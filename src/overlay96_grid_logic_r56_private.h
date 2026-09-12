#ifndef POKEHEARTGOLD_OVERLAY96_GRID_LOGIC_R56_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_GRID_LOGIC_R56_PRIVATE_H

#include "global.h"

#define R17_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define R17_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define R17_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define R17_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define R17_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R17Node {
    s32 cell;
    s32 row;
    s32 x;
    s32 y;
    void *active;
    s32 score;
    s32 result;
    s32 pad;
} Ov96R17Node;

typedef struct Ov96R17Circle {
    s32 radius;
    u16 x;
    u16 y;
} Ov96R17Circle;

typedef struct Ov96R17Hit {
    s32 cell;
    s32 unk04;
    s32 x;
    s32 y;
    void *unk10;
    s32 score;
    s32 unk18;
    s32 unk1C;
} Ov96R17Hit;

u16 LCRandom(void);
void GF_AssertFail(void);
void VEC_Subtract(const VecFx32 *, const VecFx32 *, VecFx32 *);
fx32 VEC_Mag(VecFx32 *);
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void MI_CpuFill8(void *, u8, u32);
void ov96_021F4558(void *);
void *NewMsgDataFromNarc(int, int, int, int);
void *MessageFormat_New(int);
void MessageFormat_Delete(void *);
void DestroyMsgData(void *);
void RemoveWindow(void *);

void ov96_021F380C(u8, Ov96R17Node **);
s32 ov96_021F38FC(s32, s32);
s32 ov96_021F39F0(Ov96R17Hit *, Ov96R17Node *, s32);
BOOL ov96_021F3A5C(Ov96R17Circle *, fx32, fx32);
BOOL ov96_021F3AB0(void *, u8);
void ov96_021F3AD8(void *, Ov96R17Circle *, s32, s32 *, s32 *);
BOOL ov96_021F3B04(s32, s32, s16 *, s16 *);
void *ov96_021F3BF0(s32, void *, void *);
void ov96_021F3C38(void *);
s32 ov96_021F3930(void *, Ov96R17Circle *, s32, void *, s32, s32, s32 *);
void ov96_021F3888(void *, u8, Ov96R17Circle *, void *, Ov96R17Node **);
s32 ov96_021F342C(void *, void *);
void ov96_021F350C(void *, u8, void *);

#endif
