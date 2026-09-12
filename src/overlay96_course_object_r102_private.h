#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_OBJECT_R102_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_OBJECT_R102_PRIVATE_H

#include "global.h"

typedef struct Ov96CourseObjectR102 {
    s16 x;
    s16 y;
    u32 flags;
    u8 field8;
    u8 field9;
    u8 fieldA;
} Ov96CourseObjectR102;

void GF_AssertFail(void);
u32 MTRandom(void);
u32 ov96_0220F3BC(const Ov96CourseObjectR102 *obj);
void ov96_0220FB98(Ov96CourseObjectR102 *obj, u8 valueA, u8 value8);
void ov96_0220FBDC(Ov96CourseObjectR102 *obj);

#endif
