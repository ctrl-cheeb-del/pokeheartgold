#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_ENTITY_MOTION_R17_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_ENTITY_MOTION_R17_PRIVATE_H

#include <nitro/fx/fx_vec.h>

#include "global.h"

typedef struct PokeathlonCourseEntityMotionR17 {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    void *unk10;
    s32 state;
    u8 pad18[8];
    VecFx32 vec20;
    VecFx32 vec2C;
    VecFx32 vec38;
    VecFx32 vec44;
    s32 unk50;
    s32 unk54;
    s8 unk58;
    s8 unk59;
    s8 unk5A;
    s8 unk5B;
    u8 unk5C;
    s8 unk5D;
    s8 unk5E;
    u8 unk5F;
    u32 flags;
} PokeathlonCourseEntityMotionR17;

extern void GF_AssertFail(void);
extern void ov96_02218578(PokeathlonCourseEntityMotionR17 *, int);
extern BOOL ov96_02218934(PokeathlonCourseEntityMotionR17 *);
extern void ov96_02219030(PokeathlonCourseEntityMotionR17 *);
extern void VEC_MultAdd(fx32, const VecFx32 *, const VecFx32 *, VecFx32 *);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern BOOL sub_0200606C(u16, int);

void ov96_02218AF0(PokeathlonCourseEntityMotionR17 *);
void ov96_02218EB8(PokeathlonCourseEntityMotionR17 *);
void ov96_02218F18(PokeathlonCourseEntityMotionR17 *);
void ov96_02218FD4(PokeathlonCourseEntityMotionR17 *);
void ov96_02218FFC(PokeathlonCourseEntityMotionR17 *);
void ov96_02219174(void **, int);
void *ov96_0221935C(void *, u32, u32);
void ov96_02219398(PokeathlonCourseEntityMotionR17 *);
BOOL ov96_022193CC(u32, BOOL);

#endif
