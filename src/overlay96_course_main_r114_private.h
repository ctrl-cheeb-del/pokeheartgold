#ifndef R23_OV96_114_PRIVATE_H
#define R23_OV96_114_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern u8 gSystem[];
extern void GF_AssertFail(void);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern u32 PokeathlonCourse_GetField1ED(void *);
extern void PokeathlonCourse_IncrementField1ED(void *);
extern void *PokeathlonCourse_AllocPtr4FromHeap(void *, u32);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void PokeathlonCourse_SetVBlankIntrCB(void *);
extern void PokeathlonCourse_SetField1F4(void *, u32);
extern void PokeathlonCourse_SetStateField07(void *, u32);
extern void *ov96_021E8A20(void *);
extern u32 ov96_021E5F24(void *);
extern u32 ov96_021E637C(void *);
extern u32 ov96_021E667C(void *);
extern void ov96_021E6670(void *, u32);
extern void **ov96_021E61D8(void *, u32, void *, void *);
extern u32 ov96_021EAA00(void *);
extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u32, u32, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_0221A56C(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern void Heap_Create(u32, u32, u32);
extern void Heap_Destroy(u32);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void Main_SetHBlankIntrCB(void *, void *);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void GfGfx_SwapDisplay(void);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void GfGfx_EngineBTogglePlanes(u32, u32);
extern void *BgConfig_Alloc(u32);
extern void *SpriteManager_GetSpriteList(void *);
extern void Sprite_SetDrawPriority(void *, u32);
extern void SpriteSystem_DrawSprites(void *);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 IsPaletteFadeFinished(void);
extern void MI_CpuFill8(void *, u8, u32);
extern void sub_0203A994(u32);
extern void sub_0203A914(void);
extern void ov96_02215FC8(void *);
extern u32 ov96_02216234(void *);
extern u32 ov96_02215864(void *);
extern void ov96_02215FA8(void);
extern void ov96_0221654C(void *);
extern void ov96_0221663C(void *);
extern void ov96_022193E4(void *);
extern void ov96_022162F4(void *);
extern void ov96_02217AE4(void *, void *);
extern void ov96_022163AC(void *);
extern void *ov96_02219F7C(void *, u32);
extern void *ov96_022194C4(void *, void *, void *, void *, void *, void *, u32, void *, void *);
extern void ov96_02217B84(void *, void *);
extern void ov96_022195C8(void *);
extern void ov96_02217544(void *, void *, void *, void *, void *, void *);
extern void ov96_0221587C(void *, void *, void *);
extern void ov96_02218330(void *, void *);
extern void ov96_02219FDC(void *);
extern void ov96_022195E8(void *);
extern void ov96_022177D8(void *);
extern void ov96_02217DBC(void *);
extern void ov96_02216390(void *);
extern void ov96_022165FC(void *);

void ov96_02215958(s32 *, s32);
u32 ov96_02215984(void *, u8 *);
u32 ov96_022159F0(void *, u8 *);
u32 ov96_02215A70(void *, u8 *);
u32 ov96_02215AC4(void *);
u32 ov96_02215CD0(void *);
u32 ov96_02215CE8(void *);
u32 ov96_02215D4C(void *);

#endif
