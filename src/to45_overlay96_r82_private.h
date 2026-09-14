#ifndef TO45_R3_OV96_82_PRIVATE_H
#define TO45_R3_OV96_82_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96Banks82 {
    u32 raw[10];
} Ov96Banks82;

typedef struct Ov96Out82 {
    u32 unk00;
    float unk04;
    float unk08;
    float unk0C;
    u32 unk10;
    u16 unk14;
    u16 unk16;
    u8 unk18;
    u8 unk19;
} Ov96Out82;

extern const Ov96Banks82 ov96_0221C934;
extern u8 gSystem[];

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
extern void PokeathlonCourse_SetStateField07(void *, u32);
extern void PokeathlonCourse_ResetField3A4(void *);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern u32 ov96_021E5F24(void *);
extern u32 ov96_021E637C(void *);
extern u32 ov96_021E667C(void *);
extern void *ov96_021E8A20(void *);
extern void *ov96_021E60D8(void *, void *, void *);
extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u32, u32, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_0221A56C(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern void ov96_02203CE4(void *);
extern void ov96_02203A64(void *, u32);
extern void ov96_021EB5BC(void *);
extern void ov96_021EB2BC(void *, s32, s32, s32, s32);
extern void ov96_021EB2F4(void *, s32, s32, s32, s32, s32);
extern void ov96_021EB334(void *, s32, s32, s32);
extern void ov96_021EB36C(void *, s32, s32, s32);
extern void ov96_0220223C(void *);
extern u32 ov96_022028BC(void *);
extern void ov96_021E8324(void *, void *);
extern void ov96_022038D4(void *);
extern void ov96_02202958(void *);
extern void ov96_021E8228(void *, u8, u32, u32, u32);
extern void ov96_021EB63C(void *);
extern void ov96_021EB144(void *, u32);

extern void GfGfx_SetBanks(const Ov96Banks82 *);
extern void GfGfxLoader_LoadCharData(u32, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_LoadScrnData(u32, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_GXLoadPal(u32, u32, u32, u32, u32, u32);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 IsPaletteFadeFinished(void);
extern u32 System_GetTouchNew(void);
extern u32 System_GetTouchHeld(void);
extern u32 LCRandom(void);

void ov96_0220144C(s32 *, s32);
void *ov96_0220146C(void *);
u32 ov96_022014A4(void **, void **);
u32 ov96_02201B18(void *);
u32 ov96_02201B34(void *);
void ov96_02201C90(void);
void ov96_02201E10(void *, u32);
void ov96_02201E70(void *);
u32 ov96_02202154(void *, u8 *);
u32 ov96_022021D4(void *, u8 *);
void ov96_0220329C(void *, s32 (*)[5], void *, void *, Ov96Out82 *);

#endif
