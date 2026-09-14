#ifndef OVERLAY96_COURSE_RESULTS_LIFECYCLE_PRIVATE_H
#define OVERLAY96_COURSE_RESULTS_LIFECYCLE_PRIVATE_H

#include "global.h"

#include "bg_window.h"

typedef struct Ov96BgTemplates6 {
    BgTemplate templates[6];
} Ov96BgTemplates6;

extern const GraphicsModes ov96_0221CC0C;
extern const Ov96BgTemplates6 ov96_0221CCF8;
extern const u32 ov96_0221CC48[6];

void FontID_Alloc(u32, u32);
void FontID_Release(u32);
void String_Delete(void *);
void MessageFormat_Delete(void *);
void DestroyMsgData(void *);
void RemoveWindow(Window *);
void Heap_Free(void *);
void GfGfxLoader_LoadCharData(u32, s32, BgConfig *, u32, u32, u32, u32, u32);
void GfGfxLoader_LoadScrnData(u32, s32, BgConfig *, u32, u32, u32, u32, u32);
void GfGfxLoader_GXLoadPal(u32, s32, u32, u32, u32, u32);
void LoadFontPal0(u32, u32, u32);
void ov96_02209C14(BgConfig *, u32);
void ov96_02209CA8(u8 *);
void ov96_02209D14(u8 *);

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

#endif
