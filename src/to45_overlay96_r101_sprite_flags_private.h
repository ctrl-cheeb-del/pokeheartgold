#ifndef TO45_OVERLAY96_R101_SPRITE_FLAGS_PRIVATE_H
#define TO45_OVERLAY96_R101_SPRITE_FLAGS_PRIVATE_H

#include "global.h"

typedef struct Overlay96R101Row {
    void *sprites0[2];
    void *sprites1[2];
    u8 padding[0xC];
} Overlay96R101Row;

typedef struct Overlay96R101Sprite {
    void *sprite;
    u8 padding[0x18];
} Overlay96R101Sprite;

typedef struct Overlay96R101Work {
    u8 padding000[0x20];
    void *unk20;
    u8 padding024[0xA0];
    void *unkC4;
    u8 padding0C8[0x44C];
    Overlay96R101Row rows[2];
    Overlay96R101Sprite sprites[12];
} Overlay96R101Work;

void ov96_021EB144(void *work, int value);
void ov96_0221031C(void *work);
void ManagedSprite_SetAnimateFlag(void *sprite, int value);
void ov96_0220EAC4(void *work);

#endif
