#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_INTERNAL_H

#include "global.h"

#pragma require_prototypes off

#define OV96_R92_U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OV96_R92_PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96CourseSceneRect {
    void *unk0;
    s16 x;
    s16 y;
    s32 unk8;
    s32 unkC;
    s16 value;
    s16 unk12;
} Ov96CourseSceneRect;

typedef struct Ov96CourseScenePair {
    u16 x;
    u16 y;
} Ov96CourseScenePair;

void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void PokeathlonCourse_SetStateField07(void *, u8);
void *SpriteManager_GetSpriteList(void *);
extern const Ov96CourseScenePair ov96_0221CC00;

#endif
