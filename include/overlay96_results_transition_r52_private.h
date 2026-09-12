#ifndef POKEHEARTGOLD_OVERLAY96_RESULTS_TRANSITION_R52_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_RESULTS_TRANSITION_R52_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "screen_fade.h"
#include "sound.h"
#include "sprite_system.h"
#include "touchscreen.h"

typedef struct Ov96R52Work {
    void *course;
    BgConfig *bgConfig;
    NARC *narc;
    enum HeapID heapId;
    void *spriteSystem;
    void *spriteManager;
    u32 screenMode;
    s32 animCounter;
    u8 selection;
    u8 animIndex;
    u8 participant;
    u8 padding_23;
    u32 mode;
    u32 showRecord;
    u32 flag2C;
    void *message;
    void *unk34;
    ManagedSprite *sprites[4];
} Ov96R52Work;

typedef struct PokeathlonCourseData PokeathlonCourseData;
void *PokeathlonCourse_GetHeapAllocPtr4(PokeathlonCourseData *course);
u32 PokeathlonCourse_GetCurrentParticipantIndex(PokeathlonCourseData *course);
void PokeathlonCourse_SetStateField07(PokeathlonCourseData *course, int value);

void ov96_021EF3A8(Ov96R52Work *work);
void ov96_021EF430(Ov96R52Work *work, u8 selection);
void ov96_021EF610(Ov96R52Work *work);
void ov96_021EF770(Ov96R52Work *work);
void ov96_021EF7C4(Ov96R52Work *work);
void ov96_021EF924(Ov96R52Work *work);
void ov96_021EF95C(Ov96R52Work *work, int value);
void ov96_021EF98C(Ov96R52Work *work);
void ov96_021EFA3C(Ov96R52Work *work);
void ov96_021EFACC(Ov96R52Work *work);
BOOL ov96_021EFB50(PokeathlonCourseData *course);
void ov96_021EFB20(PokeathlonCourseData *course, int value);
BOOL ov96_021EF280(int a, int b);
void PlaySE(u16 seqNo);

void ov96_021EFB58(Ov96R52Work *work);
void ov96_021EFC10(Ov96R52Work *work);
void ov96_021EFC8C(Ov96R52Work *work);
void ov96_021EFD08(PokeathlonCourseData *course);
u32 ov96_021EFD9C(PokeathlonCourseData *course, u8 *state);
u32 ov96_021EFEB8(PokeathlonCourseData *course, u8 *state);
u32 ov96_021EFF3C(PokeathlonCourseData *course, u8 *state);
u32 ov96_021EFFE4(PokeathlonCourseData *course, u8 *state);
u32 ov96_021F008C(PokeathlonCourseData *course, u8 *state);

extern const TouchscreenHitbox ov96_0221BA20[];
extern const TouchscreenHitbox ov96_0221BA2C[];
extern const TouchscreenHitbox ov96_0221BA38[];

#endif
