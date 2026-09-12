#ifndef OVERLAY96_COURSE_EVENT_R70_PRIVATE_H
#define OVERLAY96_COURSE_EVENT_R70_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern int PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern u8 PokeathlonCourse_GetParticipantCount(void *);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern u8 ov96_021E5F24(void *);
extern void ov96_021E9510(u32 *);
extern void ov96_021E966C(void *, void *, u32, u32, u32, u32, u8, u8, u8, u8, u32);
extern s32 ov96_021FBDEC(s32);
extern void ov96_021FC314(void **);
extern void ov96_021EB5BC(u8 *);
extern void sub_0203A914(void);
extern void *PokeathlonCourse_GetSystem(void *);
extern void PokeathlonCourse_ResetField3A4(void *);
extern void ov96_021FC1A8(void *);
extern void ov96_021FC05C(void *);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void ov96_021E9C0C(void *);
extern void ov96_021EB21C(void *);
extern void FontID_Release(int);
extern const GraphicsBanks ov96_0221C534;
extern const GraphicsModes ov96_0221C434;
extern const BgTemplate ov96_0221C48C;
extern const BgTemplate ov96_0221C4A8;
extern const BgTemplate ov96_0221C4C4;
extern const BgTemplate ov96_0221C4E0;
extern const BgTemplate ov96_0221C454;
extern const BgTemplate ov96_0221C470;
extern const BgTemplate ov96_0221C518;
extern const BgTemplate ov96_0221C4FC;
extern void ov96_021E93B4(void *, int);
extern void ov96_0221A56C(void *, int);
extern void *ov96_021E952C(void *);
extern void ov96_021E9570(void *, int);
extern void ov96_021E87B0(void *, u16);
extern void ov96_021FC690(void *);
extern void ov96_021EA894(void *);
extern void ov96_021E92D0(void);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern BOOL ov96_021E637C(void *);
extern BOOL ov96_021E667C(void *);
extern void ov96_021FBDBC(u8 *);
extern BOOL ov96_021FA6D0(void *, void *);
extern void ov96_021FB630(void *);
extern u32 ov96_021FB60C(void *);
extern void ov96_021FB808(void *, s32);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern void *ov96_021E8A20(void *);
extern void ov96_021E8318(void *, u16);
extern void ov96_021FAF1C(void *);
extern void PokeathlonCourse_SetStateField07(void *, u8);
extern int ov96_021F9240(void *, u8 *);
extern BOOL ov96_021F9CA4(void *);
extern BOOL ov96_021F9CC4(void *);
extern BOOL ov96_021F9D58(void *);
extern void ov96_021F9E3C(void);
extern void ov96_021F9E5C(BgConfig *);
extern void ov96_021F9FE8(BgConfig *, enum HeapID);
extern void ov96_021FA020(BgConfig *, enum HeapID);
#endif
