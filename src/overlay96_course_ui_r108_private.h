#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_UI_R108_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_UI_R108_PRIVATE_H

#include "global.h"

typedef struct Ov96R108GraphicsModes {
    u32 words[4];
} Ov96R108GraphicsModes;

typedef struct Ov96R108BgTemplate {
    u32 words[7];
} Ov96R108BgTemplate;

typedef struct Ov96R108Entity {
    u8 unk00[8];
    VecFx32 vec08;
    VecFx32 vec14;
    VecFx32 vec20;
    u8 unk2C[0x0D];
    u8 unk39;
    u8 unk3A;
    u8 unk3B;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42[10];
} Ov96R108Entity;

void ov96_022118C4(void *bg);
void ov96_02211A24(void *arg);
void ov96_02212F0C(void *arg0, void *arg1);

#endif // POKEHEARTGOLD_OVERLAY96_COURSE_UI_R108_PRIVATE_H
