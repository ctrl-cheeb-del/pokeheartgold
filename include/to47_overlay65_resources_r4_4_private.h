#ifndef TO47_OVERLAY65_RESOURCES_R4_4_PRIVATE_H
#define TO47_OVERLAY65_RESOURCES_R4_4_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov65CharTransferConfigR4 {
    u32 words[4];
} Ov65CharTransferConfigR4;

extern const Ov65CharTransferConfigR4 ov65_0221FD48;
extern void *G2dRenderer_Init(int, void *, int);
extern void *Create2DGfxResObjMan(int, int, int);
extern void *AddCharResObjFromOpenNarc(void *, void *, int, int, int, int, int);
extern void *AddPlttResObjFromOpenNarc(void *, void *, int, int, int, int, int, int);
extern void *AddCellOrAnimResObjFromOpenNarc(void *, void *, int, int, int, int, int);
extern void *String_New(u32, int);
extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);

#endif
