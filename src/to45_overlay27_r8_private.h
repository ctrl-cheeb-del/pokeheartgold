#ifndef TO45_OV27_R8_PRIVATE_H
#define TO45_OV27_R8_PRIVATE_H

#include "global.h"

#include "bag.h"
#include "bug_contest_internal.h"
#include "field_system.h"
#include "item.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "system.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"
#include "unk_0206D494.h"

typedef struct Ov27Bits {
    u32 bit0 : 1;
    u32 mode : 4;
    u32 rest : 27;
} Ov27Bits;

typedef struct Ov27WorkR8 {
    u8 pad000[0x10];
    FieldSystem *fieldSystem;
    s32 selection;
    SpriteList *spriteList;
    u8 pad01C[0x144 - 0x1C];
    GF_2DGfxResMan *resManagers[4];
    u8 pad154[0x204 - 0x154];
    SpriteResourcesHeader headers[11];
    Sprite *sprites[16];
    u8 pad3D0[0x4CC - 0x3D0];
    u8 paletteData[0x50];
    Ov27Bits bits;
} Ov27WorkR8;

typedef struct Ov27ResourcePair {
    SpriteResource *character;
    SpriteResource *palette;
} Ov27ResourcePair;

extern const u32 ov27_0225CF3C[];
extern const u16 ov27_0225CF94[][2];
extern const u8 ov27_0225CFC8[][8];
extern const u16 ov27_0225D038[][2];
extern const u16 ov27_0225D05C[][2];
extern const u8 ov27_0225D0B4[][4][3];

void ov27_0225A4B8(Ov27WorkR8 *work);
void ov27_0225A9C0(Ov27WorkR8 *work, int value);
void ov27_0225AA7C(Ov27WorkR8 *work);
u32 ov27_0225AE8C(u32 value);
u8 ov27_0225C170(Ov27WorkR8 *work, int selection);

void PlaySE(u16 seqNo);

void ov27_0225AEA8(FieldSystem *, GF_2DGfxResMan **, Ov27ResourcePair *, int, int, int, Bag *, int);
void ov27_0225B010(Ov27WorkR8 *);
s32 ov27_0225B360(s32, s32, const u8 *);
void ov27_0225B398(Ov27WorkR8 *, int);
void ov27_0225B404(Ov27WorkR8 *);

#endif
