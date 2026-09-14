#ifndef TO45_OVERLAY96_COURSE_SPRITE_LOAD_R36_BEFORE_PRIVATE_H
#define TO45_OVERLAY96_COURSE_SPRITE_LOAD_R36_BEFORE_PRIVATE_H

#include "global.h"

typedef struct Ov96R36Work {
    u32 heapId;
    u8 filler04[0x14];
    void *spriteSystem;
    void *spriteManager;
} Ov96R36Work;

void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void SpriteSystem_LoadCharResObj(void *, void *, int, int, int, int, int);
void SpriteSystem_LoadPlttResObj(void *, void *, int, int, int, int, int, int);
void SpriteSystem_LoadCellResObj(void *, void *, int, int, int, int);
void SpriteSystem_LoadAnimResObj(void *, void *, int, int, int, int);
void ov96_021ECA18(void *);
int ov96_021EDC38(u8, int);
void ov96_021EC82C(void *);

#endif
