#ifndef OV95_RESIDUAL_3_PRIVATE_H
#define OV95_RESIDUAL_3_PRIVATE_H
#include "global.h"
#include "camera.h"

extern u32 GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
extern void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
extern void PaletteData_LoadNarc(void *, int, int, int, int, int, int);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32, BOOL, u32);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32, BOOL, u32);
extern void sub_02015354(u32);
extern void sub_02015394(u32);
extern void *sub_02014DB4(void *, void *, void *, u32, BOOL, int);
extern void *sub_02015524(void *);
extern void *sub_02015264(int, int, int);
extern void sub_0201526C(void *, void *, int, int);
void ov95_021E5D44(void *, void *);
u32 ov95_021E5D98(u32, BOOL);
u32 ov95_021E5DB4(u32, BOOL);
void *ov95_021E5DD0(int);
void *ov95_021E5E18(int, int, int);
#endif
