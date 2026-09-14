#ifndef OVERLAY89_R2_TO47_PRIVATE_H
#define OVERLAY89_R2_TO47_PRIVATE_H

#include "global.h"

typedef struct Ov89YesNoTemplate {
    void *bgConfig;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
} Ov89YesNoTemplate;

typedef struct Ov89Entry {
    u8 filler_00[9];
    u8 touchX;
    u8 touchY;
    u8 filler_0B;
} Ov89Entry;

typedef struct Ov89Unk20 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
} Ov89Unk20;

#endif
