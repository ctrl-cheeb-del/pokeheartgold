#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_OPPONENT_PREFIX_R111_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_OPPONENT_PREFIX_R111_PRIVATE_H

#include "global.h"

extern void GF_AssertFail(void);
extern u32 LCRandom(void);

extern const u16 ov96_0221D678[];
extern const u16 ov96_0221D67A[];
extern const u16 ov96_0221D67C[];
extern const u16 ov96_0221D680[];

extern BOOL ov96_022156A8(int x, int y, const u16 (*points)[2]);
int ov96_02214DBC(void *object, const void *source, u8 state, u8 quadrant);
int ov96_02215058(void *object, void *source, int state, int index);

typedef struct Ov96R111MovingObject {
    u8 padding_00[0x24];
    VecFx32 position;
    u8 padding_30[0x48];
    u32 triggered;
} Ov96R111MovingObject;

typedef struct Ov96R111Source {
    u8 padding_00[8];
    VecFx32 position;
} Ov96R111Source;

typedef struct Ov96R111CourseObject {
    u8 padding_00[0x24];
    VecFx32 target;
    VecFx32 position;
    u8 padding_3C[0x3C];
    u32 triggered;
} Ov96R111CourseObject;

#endif
