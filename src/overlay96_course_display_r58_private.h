#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_DISPLAY_R58_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_DISPLAY_R58_PRIVATE_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R58Ui {
    u8 pad00[0xbc];
    void *first[2];
    void *single;
    void *second[4];
    void *third[4];
} Ov96R58Ui;

#endif
