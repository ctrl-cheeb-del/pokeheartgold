#ifndef R93_H
#define R93_H
#include "global.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
void GF_AssertFail(void);
void Sprite_DeleteAndFreeResources(void *);
void Sprite_SetAnimCtrlSeq(void *, int);
void ManagedSprite_SetAnimateFlag(void *, int);
void ManagedSprite_SetDrawFlag(void *, int);
void Heap_Free(void *);
void NARC_Delete(void *);
void ov96_021EA894(void *);
void ov96_021E9C0C(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void ov96_0220AD64(u8 *);
void ov96_0220AE28(u8 *);
void ov96_0220AF30(u8 *);
void ov96_0220B1B8(u8 *);
void ov96_0220B324(u8 *);
void ov96_0220B354(u8 *);
BOOL ov96_0220B0A4(void *, void *);
u16 ov96_0220AD4C(void *);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, int);
void SysTask_Destroy(void *);
void ScheduleSetBgPosText(void *, int, int, int);
void *SpriteSystem_GetRenderer(void *);
void G2dRenderer_SetMainSurfaceCoords(void *, int, int);
void FillWindowPixelBuffer(void *, int);
void *ReadMsgData_ExpandPlaceholders(void *, u32, u32, u32);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void String_Delete(void *);
void CopyWindowToVram(void *);
void ov96_02209E70(u8 *);
void ov96_02209F40(void *, void *, u32, u32, u32);
void ov96_0220A660(void *, void *);
void ov96_022098E8(u8 *);
void ov96_022099EC(u8 *);
void ov96_02209BB0(u8 *);
void ov96_02209BF8(u8 *);
void ov96_02209F14(u8 *);
void ov96_0220A0E0(u8 *);
void ov96_0220A704(u8 *, int, int);
void ov96_0220A7F8(u8 *);
void ov96_0220A840(u8 *);
void ov96_0220A87C(u8 *);
BOOL ov96_0220A8CC(u8 *, void *);
u32 ov96_0220AD34(u8 *);
void *Heap_Alloc(u32, u32);
void *ov96_0220D13C(void *, void *, int, int, int, int);
void *ov96_0220AE40(void *, void *, void *, u16);
void ov96_0220B178(void *, void *, void *);
void *ov96_0220A744(void *, void *, void *, void *);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void ov96_021E6168(void *, u32, u32, void *);
void ov96_021EECB8(void *, void *, u16, void *, u32, void *);
void ov96_0220A254(void *, u32, u32);
void ov96_021E8318(void *, u16);
void BufferIntegerAsString(void *, u32, u32, u32, u32, u32);
void ov96_0220A5DC(void *, u32);
#endif
