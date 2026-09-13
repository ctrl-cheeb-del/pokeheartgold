#ifndef OV96_R98_H
#define OV96_R98_H
#include <nitro/mi/memory.h>

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef union Bits {
    u32 raw;
    struct {
        u32 lo : 2;
        u32 val : 16;
        u32 hi : 14;
    } f;
    struct {
        u32 rest : 30;
        u32 top : 2;
    } g;
    struct {
        u32 v7 : 7;
        u32 pad : 25;
    } h;
    struct {
        u32 a : 24;
        u32 b : 6;
        u32 c : 2;
    } k;
    struct {
        u32 a : 8;
        u32 b : 8;
        u32 f16 : 1;
        u32 f17 : 1;
        u32 f18 : 1;
        u32 f19 : 1;
        u32 hi : 12;
    } e;
    struct {
        u32 w24 : 24;
        u32 t8 : 8;
    } n;
    struct {
        u32 lo7 : 7;
        u32 m12 : 12;
        u32 n12 : 12;
        u32 t1 : 1;
    } m;
} Bits;

typedef struct SortRec {
    u8 key;
    void *spr;
} SortRec;

typedef s32 (*Ov96CmpFunc)(const void *, const void *);
#define BITS(p, o) (*(Bits *)((u8 *)(p) + (o)))

extern u8 gSystem[];
extern void GF_AssertFail(void);
extern s32 _s32_div_f(s32, s32);

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern u32 PokeathlonCourse_GetField1ED(void *);
extern void PokeathlonCourse_IncrementField1ED(void *);
extern void *PokeathlonCourse_AllocPtr4FromHeap(void *, u32);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void PokeathlonCourse_SetVBlankIntrCB(void *);
extern void PokeathlonCourse_SetField1F4(void *, u32);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern void PokeathlonCourse_SetStateField07(void *, u32);

extern u32 ov96_021E637C(void *);
extern void ov96_021E8318(void *, u8);
extern void *ov96_021E8A20(void *);
extern u32 ov96_021E5F24(void *);
extern u32 ov96_021E667C(void *);
extern void ov96_021E6670(void *, u32);
extern void **ov96_021E61D8(void *, u32, void *, void *);
extern void ov96_021E64B8(void *);
extern void ov96_021E6550(void *);
extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u8, u8, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern u32 ov96_021EAA00(void *);
extern void *ov96_021EAF8C(void *);

extern u32 ov96_0220D408(void *);
extern void ov96_0220D420(void *, void *, void *);
extern u32 ov96_0220D630(void *);
extern void ov96_0220D6B0(void *, u32);

extern void ov96_0220E868(void);
extern void ov96_0220E9A0(void *, u8);
extern void ov96_0220EA08(void *);
extern void ov96_0220EAA4(void *);
extern void ov96_0220EB3C(void *);
extern void ov96_0220ED9C(void *);
extern void ov96_0220EE4C(void *);
extern void ov96_0220EE8C(void *);
extern void ov96_0220EFD0(void *, void *, u32);
extern void ov96_0220F03C(void *);
extern u32 ov96_0220F1CC(void *);
extern void ov96_0220F3FC(void *);
extern void ov96_0220F4A0(void *);
extern void ov96_0220FA18(void *, void *);
extern void ov96_0220FF64(void *, void *);
extern void ov96_0221007C(void *, void *, void *, void *);
extern void ov96_022101D0(void *);
extern void ov96_0221022C(void *);
extern void *ov96_02210240(void *, void *, void *, void *, void *, u32, u32, void *);
extern void ov96_022102D4(void *);
extern void ov96_02210324(void *, u8, u16);
extern u32 ov96_022104C4(void *);
extern void *ov96_022107F0(void *, u32);
extern void ov96_02210850(void *);
extern void ov96_0221A56C(void *, u32);

extern void *Heap_Create(u32, u32, u32);
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
extern s32 GF_SinDeg(u16);
extern void sub_0203A994(u32);
extern void sub_0203A914(void);

extern void MATH_QSort(void *ptr, u32 nmemb, u32 size, Ov96CmpFunc func, void *work);
extern void PlaySE(u32);
extern void ManagedSprite_SetPositionXYWithSubscreenOffset(void *, s16, s16, s32);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_ResetSpriteAnimCtrlState(void *);
extern void *ov96_021EAA04(void *, u8);
extern void ov96_021EB0A4(void *, u8, u8, s32 *, s32 *);
extern void ov96_021EB06C(void *, s32, s32, s32 *, s32 *);
extern void ov96_021EB01C(void *, s32, s32, u32);
extern void ov96_021EB10C(void *, f32, f32);
extern void ov96_021EAB38(void *, u32);
extern void ov96_021EAC0C(void *, u32);
extern void ov96_021EABA8(void *, u32);
extern void ov96_0220D52C(void *, void *);
extern void ov96_0220D554(void *, u32);
extern s32 ov96_0220DE90(const void *, const void *);
extern void *ov96_0220F378(void *, u8, u8);
extern u32 ov96_0220F3B4(void *);
extern s32 ov96_0220E8C0(void *, u32, f32 *);

void ov96_0220DEAC(void *a, void *b, void *course);
u32 ov96_0220E22C(void *course, u8 *state);
void ov96_0220E2A8(void *course);
u32 ov96_0220E2DC(void *course, u8 *state);
u32 ov96_0220E394(void *course, u8 *state);
u32 ov96_0220E3F0(void *course);
u32 ov96_0220E5F4(void *course);
u32 ov96_0220E60C(void *course);
u32 ov96_0220E670(void *course);
s16 ov96_0220E6DC(int a0, int a1);
u32 ov96_0220E70C(void *w, u32 i, u32 j);
void *ov96_0220E74C(void *w, u32 i);
void ov96_0220E770(void *w, u32 i, u32 j, s16 *out, void **out2);
u8 ov96_0220E7BC(void *course, u32 idx);
void ov96_0220E818(void *w, u32 a1, u32 i, u32 j);
u32 ov96_0220E834(void *w, u32 i, u32 j);
#endif
