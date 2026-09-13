#ifndef OV96_R40_RESIDUAL103_PRIVATE_H
#define OV96_R40_RESIDUAL103_PRIVATE_H
#include "global.h"
#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern const u32 ov96_0221CF1C[];
typedef struct Ov96R103Flags {
    u32 low : 8;
    u32 category : 4;
    u32 rest : 20;
} Ov96R103Flags;
typedef struct Ov96R103EntryFlags {
    u32 pad0 : 5;
    u32 busy : 1;
    u32 rest : 26;
} Ov96R103EntryFlags;
u8 *ov96_021E8A20(void *);
void *PokeathlonCourse_GetDataCopyArea(void *);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
u32 MTRandom(void);
void ov96_0220FB98(void *, u8, u32);
void ov96_0220FE38(void *, void *, u32);
void *ov96_0220ED34(void *, void *, u32, u32, u32, u32);
void *ov96_0220ECA4(void *, void *, u32, u32, u32, u32, u32);
void ov96_0220DC7C(void *, void *, void *);
void ov96_0220DEAC(void *, void *, void *);
void ov96_02210390(u32, u32, u16);
void ov96_0221040C(void *, s32);
void ov96_021E6454(void *, u32);
void GF_AssertFail(void);
void Sprite_DeleteAndFreeResources(void *);
void SysTask_Destroy(void *);
int ov96_0220FF68(u32);
void ov96_0220FF88(void *, u32);
void ov96_02210030(void *, void *, u32);
void ov96_0221007C(void *, void *, void *, u32);
void ov96_0221013C(void *, void *);
void ov96_022101D0(void *);
#endif
