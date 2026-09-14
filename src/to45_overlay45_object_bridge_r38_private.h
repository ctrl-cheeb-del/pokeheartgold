#ifndef POKEHEARTGOLD_TO45_OVERLAY45_OBJECT_BRIDGE_R38_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY45_OBJECT_BRIDGE_R38_PRIVATE_H

#include "global.h"

typedef struct Overlay45R38Vec {
    s32 x;
    s32 y;
    s32 z;
} Overlay45R38Vec;

typedef struct Overlay45R38Object {
    u8 mode : 4;
    u8 type : 2;
    u8 high : 2;
    u8 active : 1;
    u8 value : 7;
    u8 byte2;
    u8 byte3;
    u8 padding[4];
    void *handle;
    u8 model[0x84];
} Overlay45R38Object;

void ov49_02258800(const s16 *source, s32 *destination);
void sub_02023E50(void *handle, const Overlay45R38Vec *position);
void sub_020182A8(void *model, u32 x, u32 y, u32 z);
const Overlay45R38Vec *sub_02023E68(void *handle);
void sub_02023EE0(void *handle, u32 value);
void sub_02023F40(void *handle, s32 value);
u32 ov45_022309C4(u32 value);

u32 ov45_022308B8(Overlay45R38Object *object);
void ov45_022308C0(Overlay45R38Object *object, const s16 *source);
void ov45_022308E4(Overlay45R38Object *object, const Overlay45R38Vec *position);
void ov45_02230908(Overlay45R38Object *object, Overlay45R38Vec *position);
void ov45_02230920(Overlay45R38Object *object);
void ov45_0223093C(Overlay45R38Object *object, u32 value);

#endif
