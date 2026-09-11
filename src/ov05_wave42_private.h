#ifndef OV05_R12_H
#define OV05_R12_H
#include <string.h>

#include "global.h"
extern void *NARC_New(u32, u32);
extern void NARC_Delete(void *);
extern void *NARC_AllocAndReadWholeMember(void *, u32, u32);
extern void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, u32, u32, BOOL, u32);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, u32, u32, BOOL, u32);
extern void BG_LoadPlttData(u32, const void *, u16, u16);
extern void Heap_Free(void *);
extern void sub_0207CAAC(u32, u16 *, u16 *, u16 *);
extern void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, u32, u32, u32, u32);
extern void SpriteSystem_LoadPlttResObjFromOpenNarc(void *, void *, void *, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadCellResObjFromOpenNarc(void *, void *, void *, u32, u32, u32);
extern void SpriteSystem_LoadAnimResObjFromOpenNarc(void *, void *, void *, u32, u32, u32);
typedef u8 R12;
#define P(w, o)   (*(void **)((w) + (o)))
#define U16(w, o) (*(u16 *)((w) + (o)))
#define U32(w, o) (*(u32 *)((w) + (o)))
extern void *GetBgTilemapBuffer(void *, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void ov05_0221DDEC(R12 *, const void *, u32);
extern void ov05_0221DF38(R12 *, void *, u32);
extern u32 CalculateHpBarColor(u32, u32, u32);
extern void AddWindow(void *, void *, const void *);
extern void RemoveWindow(void *);
extern const u8 ov05_0221ECE4[];
extern void ov05_0221CD24(R12 *, const void *, u32);
extern void ov05_0221E2D8(R12 *);
extern void ov05_0221E390(R12 *);
extern void ov05_0221E42C(R12 *);
extern void ov05_0221E4C8(R12 *);
extern void ov05_0221E110(R12 *, u32);
extern void ov05_0221E564(R12 *, u32);
extern const u32 ov05_0221EAEC[6];
extern void sub_0200CE7C(void *, u32, u32, u32, u32, void *, u32, u32);
extern void PrintUIntOnWindow(void *, u32, u32, u32, void *, u32, u32);
extern void sub_0200CDAC(void *, u32, void *, u32, u32);
void ov05_0221DDEC(R12 *, const void *, u32);
void ov05_0221DE38(R12 *);
void ov05_0221E07C(R12 *);
u32 ov05_0221E0A8(R12 *, u32);
void ov05_0221E274(R12 *);
void ov05_0221E5E4(R12 *);
void ov05_0221E60C(R12 *);
void ov05_0221E714(R12 *, u32, void *, u32, u32, u32);
void ov05_0221DC60(R12 *);
void ov05_0221E74C(R12 *, u32, void *, u32, u32, u32);
void ov05_0221E390(R12 *);
void ov05_0221E42C(R12 *);
void ov05_0221E4C8(R12 *);
#endif
