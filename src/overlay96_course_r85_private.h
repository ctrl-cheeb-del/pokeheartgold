#ifndef OVERLAY96_COURSE_R85_PRIVATE_H
#define OVERLAY96_COURSE_R85_PRIVATE_H

#include "global.h"

typedef struct Ov96R85Object {
    u8 pad00[0x0c];
    u32 state;
    u8 pad10[9];
    u8 flag;
    u8 pad1a[0x2a];
    u16 count;
    u16 level;
} Ov96R85Object;

typedef struct Ov96R85Work {
    Ov96R85Object *objects[12];
    Ov96R85Object *states[12];
    u8 pad60[0x60];
    u32 active;
    u8 groupCount;
    u8 current;
    u8 timer;
    u8 limit;
    u8 base;
    u8 done;
    u8 group;
} Ov96R85Work;

void GF_AssertFail(void);
int ov96_022043C0(Ov96R85Work *, void *);
void ov96_022044A0(Ov96R85Work *, u8, u8, void *);

#endif
