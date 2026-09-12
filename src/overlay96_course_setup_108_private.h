#ifndef OVERLAY96_COURSE_SETUP_108_PRIVATE_H
#define OVERLAY96_COURSE_SETUP_108_PRIVATE_H

#include "global.h"

typedef struct GfxBanks40 {
    u32 words[10];
} GfxBanks40;

extern const GfxBanks40 ov96_0221D380;
extern void GfGfx_SetBanks(const GfxBanks40 *);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern void ov96_021E9510(void *);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void ov96_021E95F8(void *, void *, int, u16, int, int, int);
extern void ov96_021E93B4(void *, int);
extern void ov96_0221A56C(void *, int);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, int);
extern BOOL IsPaletteFadeFinished(void);
extern BOOL ov96_021E5F24(void *);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern BOOL ov96_021E637C(void *);
extern void ov96_02211B94(void *);
extern BOOL ov96_02211AF0(void *);
extern void ov96_0221236C(void *);
extern BOOL ov96_021E667C(void *);
extern void PokeathlonCourse_SetStateField07(void *, int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, void *);
extern void sub_0203A914(void);
extern void ov96_021E6550(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void ov96_02214234(void *);
extern void ov96_022141B0(void *);
extern void RemoveWindow(void *);
extern void Heap_Free(void *);
extern void ov96_021EB21C(void *);
extern void ov96_021EA894(void *);
extern void ov96_021E9C0C(void *);
extern void OamManager_Free(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void ov96_02214B7C(void *);
extern void ov96_02214690(void *);
extern void FontID_Release(int);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void Main_SetHBlankIntrCB(void *, void *);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void GfGfx_SwapDisplay(void);
extern void Heap_Destroy(int);
extern u8 gSystem[];
int ov96_02211660(void *);
int ov96_022116C8(void *);
void ov96_022117CC(void);
int ov96_022117EC(void *, u8 *);
int ov96_02211870(void *, u8 *);
void ov96_022132FC(void *);

#endif
