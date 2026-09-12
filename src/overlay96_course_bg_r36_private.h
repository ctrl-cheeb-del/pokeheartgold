#ifndef OVERLAY96_COURSE_BG_R36_PRIVATE_H
#define OVERLAY96_COURSE_BG_R36_PRIVATE_H

#include "global.h"

void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, u32);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, u32);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, u32);

void ov96_021EC3D8(void *, u32);
void ov96_021EC458(void *, u32);

#endif
