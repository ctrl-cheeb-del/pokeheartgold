#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct { void *unk0; void *unk4; void *unk8; s32 unkC; } Obj;
void *ov96_021EB5B8(void *);
void ov96_021EB52C(void *, int, int);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetMatrix(void *, const void *);
void *Sprite_GetMatrixPtr(void *);
void *Heap_Alloc(u32, u32);
void Heap_Free(void *);
void MI_CpuFill8(void *, u8, u32);
void *ov96_021FBE20(int, void *);
void ov96_021FBE3C(void *);
void *ov96_021FBE44(u8 *, int);
void ov96_021FBE4C(void **, void *, void *);
void *ov96_021EB4F4(void *, int, int);
void ov96_021FBE54(Obj *, int);
void ov96_021FBEA4(Obj *);
void ov96_021FBEDC(Obj *, const void *);
void ov96_021FBEFC(Obj *, int);
void ov96_021FBF5C(Obj *, s16 *);
void *ov96_021FC028(u32);
void ov96_021FC05C(u8 *);
void ov96_021FC07C(u8 **, void *);
#endif
