#ifndef TO45_OV40_R27_U3_PRIVATE_H
#define TO45_OV40_R27_U3_PRIVATE_H

#include "global.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))
#define S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

void BeginNormalPaletteFade(int, int, int, int, int, int, int);
BOOL IsPaletteFadeFinished(void);
void PaletteData_BlendPalettes(void *, int, int, int, u16);
void PlaySE(u16);
BOOL System_GetTouchHeld(void);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);

BOOL ov40_0222C4DC(void *);
void ov40_0222BF80(void *, int);
u32 ov40_0222DAF0(void *);
void ov40_02230E34(void *);
void ov40_02230EB4(void *);
void ov40_02230964(void *, int);
void ov40_0222C750(void *);
void ov40_0222C884(void *);
void ov40_0222CAD8(void *);
void ov40_0222CCAC(void *);
void ov40_0222D2A0(void *);
void ov40_0222CE7C(void *);
void ov40_0222CF10(void *);
void ov40_0222BF64(void *, void *, int, void *);

void sub_02087948(void *, s16, s16);
void sub_020878B8(void *, s16, s16);
void sub_020879E0(void *, int);
void sub_020878B0(void *, int);
void sub_02087A30(void *);
void sub_02087A54(void *);

int ov40_02230ED8(void *);
int ov40_02231100(void *);
int ov40_0223131C(void *);

#endif
