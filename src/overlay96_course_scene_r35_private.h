#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_R35_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_R35_PRIVATE_H

#include "global.h"

#include "gf_gfx_planes.h"
#include "screen_fade.h"
#include "sys_task_api.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96CourseSceneCryTask {
    u16 state;
    u16 padding_02;
    s32 timer;
    void *sprite;
    u32 *active;
} Ov96CourseSceneCryTask;

extern const GraphicsBanks ov96_0221B030;

void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
u32 PokeathlonCourse_GetHeapID(void *course);
BOOL ov96_021E5F24(void *course);
void ov96_021ED8DC(void *course);
void ov96_021EDA58(void *course);
void PokeathlonCourse_SetStateField07(void *course, u32 state);
void ov96_021ED0C8(void *obj);
void *ov96_021EAA04(void *manager, u8 index);
void ov96_021EAC0C(void *sprite, u32 value);
void ov96_021EAC5C(void *sprite, u32 value);
BOOL ov96_021EAD78(void *sprite);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void GF_SndStartFadeOutBGM(u32 target, u32 frames);
void PlaySE(u16 seqNo);
BOOL IsCryFinished(void);

void ov96_021EB6A8(void);
u32 ov96_021EB6C8(void *course, u8 *state);
u32 ov96_021EBA98(void *course, u8 *state);
u32 ov96_021EBAFC(void *course, u8 *state);
u32 ov96_021EC1B0(void *course, u8 *state);
void ov96_021EC218(SysTask *task, void *data);
void ov96_021EC298(void *work, u8 index);

#endif // POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_R35_PRIVATE_H
