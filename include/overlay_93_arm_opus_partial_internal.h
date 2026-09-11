#ifndef OV93_ARM_PRIVATE_H
#define OV93_ARM_PRIVATE_H

#include "global.h"
#include "filesystem.h"
#include "palette.h"
#include "sprite_system.h"
#include <nnsys/g3d/gecom.h>

typedef struct Ov93Vtx {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;
} Ov93Vtx; // 0x20

typedef struct Ov93VtxSet {
    u8 _p000[0x0c];
    Ov93Vtx lo[8];  // 0x00c
    Ov93Vtx hi[8];  // 0x10c
} Ov93VtxSet;

typedef struct Ov93Work {
    u8 _p000[0x0c];
    s32 f00c;                      // 0x00c
    s32 f010;                      // 0x010
    u8 _p014[0x1c - 0x14];
    s32 f01c;                      // 0x01c
    s32 f020;                      // 0x020
    SpriteSystem *spriteSystem;    // 0x024
    SpriteManager *spriteManager;  // 0x028
    u8 _p02c[0x8c - 0x2c];
    PaletteData *plttData;         // 0x08c
    u8 _p090[0xd4 - 0x90];
    s32 f0d4;                      // 0x0d4
    s32 f0d8;                      // 0x0d8
    u8 _p0dc[0xe4 - 0xdc];
    s32 f0e4;                      // 0x0e4
    u8 _p0e8[0x21c - 0xe8];
    s32 f21c;                      // 0x21c
    u8 _p220[0x224 - 0x220];
    s32 f224;                      // 0x224
    u8 _p228[0x230 - 0x228];
    fx32 f230;                     // 0x230
    u8 _p234[0x238 - 0x234];
    s32 f238;                      // 0x238
    u8 _p23c[0x270 - 0x23c];
    u32 f270;                      // 0x270
} Ov93Work;

extern const u8 ov93_02262C07[];
extern const ManagedSpriteTemplate ov93_02262C38;

void ov93_0225EE98(void);
void ov93_0225EF0C(Ov93VtxSet *set);
void ov93_0225EF5C(Ov93VtxSet *set);
s32 ov93_0225F8AC(Ov93Work *work, s32 mode);
s32 ov93_0225F8E4(Ov93Work *work, s32 a1, s32 a2, s32 a3, s32 *o1, s32 *o2);
s32 ov93_0225F94C(Ov93Work *work);
s32 ov93_0225F9AC(Ov93Work *work);
void ov93_0225F9D8(Ov93Work *work);
void ov93_0225FABC(Ov93Work *work);
ManagedSprite *ov93_0225FB00(Ov93Work *work);
void ov93_0225FB6C(Ov93Work *work, ManagedSprite *sprite);
void ov93_0225FBE4(ManagedSprite *sprite);


/* Generated integration prototypes. */
void ov93_0225EE98(void);
void ov93_0225EF0C(Ov93VtxSet *set);
void ov93_0225EF5C(Ov93VtxSet *set);
s32 ov93_0225F8AC(Ov93Work *work, s32 mode);
s32 ov93_0225F8E4(Ov93Work *work, s32 a1, s32 a2, s32 a3, s32 *o1, s32 *o2);
s32 ov93_0225F94C(Ov93Work *work);
s32 ov93_0225F9AC(Ov93Work *work);
void ov93_0225F9D8(Ov93Work *work);
void ov93_0225FABC(Ov93Work *work);
ManagedSprite *ov93_0225FB00(Ov93Work *work);
void ov93_0225FB6C(Ov93Work *work, ManagedSprite *sprite);
void ov93_0225FBE4(ManagedSprite *sprite);
#endif
