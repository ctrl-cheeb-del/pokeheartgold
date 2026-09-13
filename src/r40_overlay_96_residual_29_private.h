#ifndef OVERLAY96_POSITION_HELPERS_R40_PRIVATE_H
#define OVERLAY96_POSITION_HELPERS_R40_PRIVATE_H
#include "global.h"
typedef struct Ov96PositionObject {
    void *object;
    void *sprite1;
    void *sprite2;
    u8 pad0C[4];
    s32 offsetY;
    s32 offsetX;
    s32 halfHeight;
    s32 radius;
    s32 x;
    s32 y;
    s32 center;
    s32 bottom;
} Ov96PositionObject;
void *ov96_021E8BAC(void *);
BOOL ov96_021E92AC(void *);
void ov96_021EAD88(Ov96PositionObject *, s32, s32, u32);
void Sprite_SetMatrix(void *, VecFx32 *);
void ov96_021EAF94(Ov96PositionObject *, s32, s32);
void ov96_021EB01C(Ov96PositionObject *, s32, s32, u32);
void ov96_021EB03C(Ov96PositionObject *, s32, s32, s32 *, s32 *);
void ov96_021EB06C(Ov96PositionObject *, s32, s32, s32 *, s32 *);
void ov96_021EB0A4(Ov96PositionObject *, s32, s32, s32 *, s32 *);
BOOL ov96_021EB0CC(Ov96PositionObject *, fx32, fx32, s32, s32);
#endif
