#ifndef TO45_OVERLAY96_PART4_PREFIX_PRIVATE_H
#define TO45_OVERLAY96_PART4_PREFIX_PRIVATE_H

#include "global.h"
#define PTR8(p, o) (*(void **)((u8 *)(p) + (o)))

void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
void *PokeathlonCourse_GetDataCopyArea(void *course);
BOOL IsPaletteFadeFinished(void);
BOOL ov96_021E5F24(void *course);
void PokeathlonCourse_SetField5E0_AtIndex(void *course, u8 index, u16 value);
void *ov96_021E8A20(void *ptr);
void ov96_021EB52C(void *ptr, int, int);
void Sprite_SetDrawFlag(void *sprite, BOOL draw);
void ov96_021EB63C(void *ptr, int);
void ov96_021EB144(void *ptr, int);
void ov96_021E8324(void *course, void (*callback)(void));
void ov96_021FFEE8(void);
void ov96_021E8228(void *course, u8 player, u8 type, u8 index, u32 value);
BOOL System_GetTouchNew(void);
BOOL System_GetTouchHeld(void);
extern u8 gSystem[];
int ov96_021FD46C(void *course, u8 *state);
BOOL ov96_021FDB64(void *course);
void ov96_021FDC7C(void *course);

#endif
