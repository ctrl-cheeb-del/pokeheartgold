#ifndef TO45_OV96_R93_R7_PRIVATE_H
#define TO45_OV96_R93_R7_PRIVATE_H

#include "global.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void GF_AssertFail(void);
void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
void *PokeathlonCourse_GetDataCopyArea(void *course);
void *ov96_021E5F24(void *course);
void *ov96_021E8A20(void *ptr);
u16 ov96_0220AD4C(void *ptr);
void *ov96_0220B758(void *ptr);
u32 ov96_0220B730(void *ptr);
u32 ov96_0220B79C(void *ptr);
u32 ov96_0220B774(void *ptr);
u32 ov96_0220B7B4(void *ptr);
BOOL ov96_0220B744(void *ptr);
void ov96_0220B6EC(void *ptr);
u32 ov96_0220B788(void *ptr);
BOOL System_GetTouchNew(void);
BOOL System_GetTouchHeld(void);
void System_GetTouchNewCoords(u32 *x, u32 *y);
void System_GetTouchHeldCoords(u32 *x, u32 *y);
s32 TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);
BOOL PlaySE(u16 seqNo);
void ManagedSprite_SetAnimNoRestart(void *sprite, u32 animation);
extern const u8 ov96_0221CC04[];

void ov96_0220A298(void *course, int state);
void ov96_0220A424(void *course);
void ov96_0220A4DC(void *course);

#endif
