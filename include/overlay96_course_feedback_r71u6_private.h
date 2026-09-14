#ifndef OVERLAY96_COURSE_FEEDBACK_R71U6_PRIVATE_H
#define OVERLAY96_COURSE_FEEDBACK_R71U6_PRIVATE_H

#include "global.h"

#define F32AT(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

extern void GF_AssertFail(void);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern void sub_0200606C(u32, u32);
extern void sub_020061D0(u32, s32);
extern u32 ov96_021E5F24(void *);
extern void ov96_021E8228(void *, u32, u32, u32, u32);
extern void *ov96_021EB5B8(void *);
extern void ov96_021EAC0C(void *, u32);
extern u8 ov96_0221DC2C[];
extern const s8 ov96_0221DC28[];
extern const f32 ov96_0221C444[];

void ov96_021FBCB8(void *, u8 *);

#endif
