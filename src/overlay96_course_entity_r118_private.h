#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_ENTITY_R118_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_ENTITY_R118_PRIVATE_H

#include <nitro/fx/fx_vec.h>

#include "global.h"

typedef union Ov96CourseEntityR118Flags {
    u32 raw;
    struct {
        u32 pad0 : 26;
        u32 bit26 : 1;
        u32 bit27 : 1;
        u32 bit28 : 1;
        u32 pad29 : 3;
    } bits;
} Ov96CourseEntityR118Flags;

typedef struct Ov96CourseEntityR118 {
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
    Ov96CourseEntityR118Flags flags;
} Ov96CourseEntityR118;

void *ov96_021EAA20(void *);
u8 ov96_021E90FC(void *);
u16 *ov96_021E8BB0(void *);
void ov96_021EABF4(void *, const VecFx32 *);

void ov96_02218510(void *, int);
void ov96_02218578(Ov96CourseEntityR118 *, int);
BOOL ov96_02218688(Ov96CourseEntityR118 *);

#endif
