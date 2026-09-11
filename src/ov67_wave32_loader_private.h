#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
void AddWindow(void *,void *,const void *);void FillWindowPixelBuffer(void *,int);void FontID_Alloc(int,int);void LoadFontPal0(int,int,int);
void *NARC_New(int,int);void NARC_Delete(void *);void GfGfxLoader_LoadCharDataFromOpenNarc(void *,int,void *,int,int,int,int,int);void GfGfxLoader_GXLoadPalFromOpenNarc(void *,int,int,int,int,int);void GfGfxLoader_LoadScrnDataFromOpenNarc(void *,int,void *,int,int,int,int,int);
extern u8 ov67_021E6E98[];extern u8 ov67_021E7020[];
void ov67_021E5EB0(void *);void ov67_021E6008(void *);
#endif
