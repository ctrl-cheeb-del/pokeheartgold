#ifndef OV71_RESIDUAL_22_PRIVATE_H
#define OV71_RESIDUAL_22_PRIVATE_H

#include "global.h"

typedef struct Ov71Cam Ov71Cam;

typedef struct Ov71Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Ov71Vec3;

typedef struct Ov71S16Vec3 {
    s16 x;
    s16 y;
    s16 z;
} Ov71S16Vec3;

typedef struct Ov71Zoom {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    Ov71Cam *unk_10;
} Ov71Zoom;

typedef struct Ov71OrbitCh {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
} Ov71OrbitCh;

typedef struct Ov71Orbit {
    Ov71Cam *unk_00;
    void *unk_04;
    Ov71Vec3 unk_08;
    Ov71Vec3 unk_14;
    Ov71S16Vec3 unk_20;
    u8 pad_26[0x28 - 0x26];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad_34[0x38 - 0x34];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    Ov71OrbitCh unk_5C[3];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7C;
    s32 unk_80;
} Ov71Orbit;

typedef struct Ov71Orbiter {
    u8 pad_000[0xD4];
    void *unk_D4;
    Ov71Cam *unk_D8;
    Ov71Orbit unk_DC;
} Ov71Orbiter;

#endif
