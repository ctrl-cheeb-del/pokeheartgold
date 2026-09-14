#ifndef TO45_OV96_R10_PRIVATE_H
#define TO45_OV96_R10_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void *PokeathlonCourse_GetDataCopyArea(void *course);
void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
u32 ov96_021E5F24(void *course);
void *ov96_021E8A20(void *p);
void ov96_021E6454(void *course, u32 value);
void ManagedSprite_SetAnimNoRestart(void *sprite, int anim);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void PlaySE(u32 seqNo);
void GF_AssertFail(void);
void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(const void *, const void *), void *stackBuf);
int ov96_02216C1C(const void *a, const void *b);
void ov96_0221966C(void *work, u8 index, u8 rank, const void *sorted);
void ov96_022196E4(void *work, u32 value);
void ov96_02216C38(void *work, void *arg1, void *course);
void *ov96_022164EC(void *a0, void *a1, u32 x, u32 y, u32 anim, u32 pal);
void *ov96_021EAA04(void *manager, int index);
void *ov96_021EAA20(void *object);
void *ov96_021E8BB0(void *object);
void ov96_021E8BB4(void *object, void *paletteData, void *dest);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void TintPalette_GrayScale(u16 *palette, int count);
void ov96_02217544(void *dst, void *a1, void *a2, void *a3, void *a4, void *a5);
typedef struct R10Work R10Work;
typedef struct R10Course R10Course;
void ov96_0221768C(R10Work *work, R10Course *course);

#endif
