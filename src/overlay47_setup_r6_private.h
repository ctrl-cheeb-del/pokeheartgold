#ifndef TO46_OV47_R6_PRIVATE_H
#define TO46_OV47_R6_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u8 raw[0x100];
} Ov47Windows;

typedef struct {
    u8 raw[0x200];
} Ov47Context;

extern const u8 ov47_02259EE8[];

void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void AddWindow(void *, void *, const void *);
void ov47_0225999C(void *, void *, int, u32);
void *GfGfxLoader_GetCharDataFromOpenNarc(void *, int, int, void *, int);
void ov47_02259C8C(void *, int, int);
BOOL ov45_0222B21C(void *, void *);
void ov47_02259DCC(void *, void *);
void ov45_0222B1FC(void *, void *);
void ov47_02259D74(void *);

void ov47_02259488(void *, void *, void *, void *, int);

#endif
