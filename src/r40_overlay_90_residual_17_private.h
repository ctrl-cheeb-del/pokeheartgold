#ifndef OV90_R17_PRIVATE_H
#define OV90_R17_PRIVATE_H
#include "global.h"
void GF_AssertFail(void);
void *ov90_022588CC(void *, u8);
u8 sub_020348A8(u8);
u8 sub_020348CC(u8);
void *sub_02014A60(void *);
void BgSetPosTextAndCommit(void *, u32, u32, s32);
void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
void FillWindowPixelBuffer(void *, u8);
void *String_New(u32, u32);
void ov90_0225927C(void *, int);
void ov90_0225928C(void *, void *, int);
void GfGfx_EngineATogglePlanes(int, BOOL);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, BOOL, u32);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, BOOL, u32);
#endif
