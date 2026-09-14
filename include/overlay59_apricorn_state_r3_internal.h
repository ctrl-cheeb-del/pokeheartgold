#ifndef OV59_RESIDUAL_3_PRIVATE_H
#define OV59_RESIDUAL_3_PRIVATE_H

#include "global.h"

typedef u8 Ov59Work;
#define U8_(w, o)  (*(u8 *)((w) + (o)))
#define U16_(w, o) (*(u16 *)((w) + (o)))
#define U32_(w, o) (*(u32 *)((w) + (o)))
#define PTR_(w, o) (*(void **)((w) + (o)))

extern u8 gSystem[];
extern void ov59_02238FF4(Ov59Work *, u32);
extern void ov59_02238AB0(Ov59Work *, u32);
extern void ov59_02238C40(Ov59Work *, u32);
extern u32 ov59_0223A05C(Ov59Work *);
extern void ov59_02238F58(Ov59Work *);
extern int ov59_02238FB4(Ov59Work *);
extern void ApricornBox_SetKurtApricorn(void *, u32, u32);
extern BOOL ov59_022390A8(Ov59Work *, u32);
extern void ov59_0223919C(Ov59Work *, u32, u32);
extern void PlaySE(u32);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern BOOL System_GetTouchNew(void);
extern int ov59_02239F38(Ov59Work *);
extern void ov59_02238CFC(Ov59Work *, u32, u32);
extern BOOL ov59_022385AC(Ov59Work *);
extern void ov59_02238D74(Ov59Work *);
extern void Sprite_SetDrawFlag(void *, u32);
extern void Sprite_ResetAnimCtrlState(void *);
extern BOOL Sprite_IsAnimated(void *);
extern void sub_02031C30(void *, u32, void *);
extern void ov59_02238768(Ov59Work *);
extern void ov59_0223892C(Ov59Work *, u32);
extern void ov59_02238E98(Ov59Work *);
extern int ov59_02238F24(Ov59Work *);
extern void ov59_02238C24(Ov59Work *);
extern void ov59_02238D90(Ov59Work *);

u32 ov59_02238124(Ov59Work *);
u32 ov59_02238218(Ov59Work *);
u32 ov59_022382F4(Ov59Work *);
u32 ov59_0223834C(Ov59Work *);
u32 ov59_022383B4(Ov59Work *);
u32 ov59_022384E4(Ov59Work *);

#endif
