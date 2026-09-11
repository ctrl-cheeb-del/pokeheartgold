#ifndef OV71_PRIVATE_H
#define OV71_PRIVATE_H

#include "global.h"

typedef struct Ov71Opt {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    void *unk_14;
} Ov71Opt;

typedef struct Ov71Src {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
} Ov71Src;

typedef struct Ov71Ctx {
    Ov71Opt *unk_00;
    u32 unk_04;
    void *unk_08;
    void *unk_0C;
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 unk_20;
} Ov71Ctx;

typedef struct Ov71Sys {
    u16 unk_000[0x60];
    u8 pad_0C0[0xC4 - 0xC0];
    void *tasks[8];
    u32 *unk_0E4;
    u32 unk_0E8;
    u32 unk_0EC;
    u8 pad_0F0[4];
    s32 unk_0F4;
} Ov71Sys;

typedef struct Ov71Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Ov71Vec3;

typedef struct Ov71S16Vec3 {
    u16 x;
    u16 y;
    u16 z;
} Ov71S16Vec3;

typedef struct Ov71Cam {
    void *unk_00;
    u8 pad_04[0x5C - 0x04];
    void *unk_5C;
    u32 unk_60;
    void *unk_64;
    Ov71Vec3 unk_68;
    u8 pad_74[0x80 - 0x74];
    Ov71S16Vec3 unk_80;
    u8 pad_86[0x88 - 0x86];
    u32 unk_88;
} Ov71Cam;

typedef struct Ov71Cam2 {
    void *unk_00;
    u8 pad_04[0x74 - 0x04];
    u32 unk_74;
    u32 unk_78;
    u32 unk_7C;
} Ov71Cam2;

typedef struct Ov71Pair {
    void *unk_00;
    void *unk_04;
} Ov71Pair;

typedef struct Ov71Spr {
    u8 pad_00[0x3C];
    void *unk_3C;
} Ov71Spr;

typedef struct Ov71Sprs {
    void *unk_00[2];
    u8 pad_08[0x3C - 0x08];
    void *unk_3C[2];
    Ov71Pair unk_44;
} Ov71Sprs;

typedef struct Ov71TaskWork {
    u32 *unk_00;
    u8 pad_04[0x20 - 0x04];
    u32 unk_20;
} Ov71TaskWork;

typedef struct Ov71Task2 {
    u8 pad_00[0x78];
    void *unk_78;
    void *unk_7C;
} Ov71Task2;

typedef struct Ov71D4 {
    void *unk_00;
    void *unk_04;
    u8 pad_08[0xD4 - 0x08];
    void *unk_D4;
} Ov71D4;

typedef struct Ov71CamSet {
    u8 pad_00[0x18];
    Ov71Cam *unk_18;
    u32 unk_1C;
} Ov71CamSet;

typedef struct Ov71Big {
    u8 pad_000[0x14C];
    u16 unk_14C;
    u16 unk_14E;
    u16 unk_150;
    u16 unk_152;
} Ov71Big;

typedef struct Ov71Flag {
    u8 pad_000[0x168];
    u32 unk_168;
} Ov71Flag;

typedef struct Ov71Owner {
    u8 pad_000[0x168];
    u32 *unk_168;
    void *unk_16C;
} Ov71Owner;

typedef struct Ov71Grid {
    void *unk_00[3];
    Ov71Pair unk_0C;
    u8 pad_14[0x1C - 0x14];
    struct {
        void *unk_00;
        void *unk_04;
    } unk_1C[0x14];
} Ov71Grid;

typedef struct Ov71Anim {
    void *unk_00;
    u32 unk_04;
    u8 pad_08[0x24 - 0x08];
    void *unk_24;
    void *unk_28;
    u8 pad_2C[0x34 - 0x2C];
    u8 unk_34[0x70];
} Ov71Anim;

typedef struct Ov71Sub2 {
    Ov71Ctx *unk_00;
    void *unk_04;
    u8 pad_08[4];
    void *unk_0C;
    u8 pad_10[0x24 - 0x10];
} Ov71Sub2;

typedef struct Ov71Scene {
    Ov71Ctx *unk_00;
    void *unk_04;
    u8 pad_08[0x10 - 0x08];
    Ov71Pair unk_10;
    u8 pad_18[0x20 - 0x18];
    void *unk_20;
    void *unk_24;
    void *unk_28;
    u8 pad_2C[0x34 - 0x2C];
    Ov71Sub2 unk_34;
} Ov71Scene;

typedef struct Ov71Grid2 {
    u8 pad_00[0x0C];
    Ov71Pair unk_0C;
    u8 pad_14[0x1C - 0x14];
    struct {
        void *unk_00;
        void *unk_04;
    } unk_1C[0x14];
} Ov71Grid2;

typedef struct Ov71TaskA {
    u8 pad_00[0x1C];
    u32 *unk_1C;
} Ov71TaskA;

typedef struct Ov71TaskB {
    u32 *unk_00;
} Ov71TaskB;

typedef struct Ov71Bright {
    struct Ov71Task2 *unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} Ov71Bright;

typedef struct Ov71Slide {
    void *unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    Ov71Cam *unk_14;
} Ov71Slide;

typedef struct Ov71SprPair {
    u8 pad_00[0x40];
    void *unk_40[2];
    Ov71Pair unk_48;
} Ov71SprPair;

typedef struct Ov71Fanfare {
    u8 pad_00[8];
    s32 unk_08;
    s32 unk_0C;
} Ov71Fanfare;

typedef struct Ov71Scroll {
    u8 pad_00[0x3A];
    s16 unk_3A;
    s16 unk_3C;
    u8 pad_3E[2];
    s32 unk_40;
} Ov71Scroll;

typedef struct Ov71Cell {
    Ov71Ctx *unk_00;
    void *unk_04;
    u8 pad_08[4];
    void *unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[4];
    u32 unk_20;
    u8 pad_24[0x30 - 0x24];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
} Ov71Cell;

typedef struct Ov71Bgs {
    u8 pad_00[0x0C];
    void *unk_0C;
    void *unk_10;
    u32 unk_14;
} Ov71Bgs;

#endif
