#ifndef OVERLAY96_COURSE_UI_R101_PRIVATE_H
#define OVERLAY96_COURSE_UI_R101_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void ov96_021EA894(void *);
void ov96_021E9C0C(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void RemoveWindow(void *);
void MessageFormat_Delete(void *);
void DestroyMsgData(void *);
void FreeBgTilemapBuffer(void *, u8);
void FontID_Release(int);
void Heap_Free(void *);
void GF_AssertFail(void);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, u32);
int _s32_div_f(int, int);

extern const u32 ov96_0221CF58[7];

void ov96_0220E974(s32 *, s32);
void ov96_0220EAA4(void *);
void ov96_0220EE4C(void *);
void ov96_0220EFD0(u8 *, void *, u32);

#endif
