#ifndef OV82_PRIVATE_H
#define OV82_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "obj_char_transfer.h"
#include "sprite.h"
#include "yes_no_prompt.h"

typedef struct Ov82Spr {
    /* 0x00 */ u8 pad00[0x0c];
    /* 0x0c */ const u8 *animPtr;
    /* 0x10 */ Sprite *sprite;
} Ov82Spr;

typedef struct Ov82Work {
    /* 0x000 */ void *unk000;
    /* 0x004 */ u8 pad004[4];
    /* 0x008 */ u8 unk008;
    /* 0x009 */ u8 unk009;
    /* 0x00a */ u8 unk00A;
    /* 0x00b */ u8 unk00B;
    /* 0x00c */ u8 unk00C;
    /* 0x00d */ u8 unk00D;
    /* 0x00e */ u8 unk00E;
    /* 0x00f */ u8 unk00F;
    /* 0x010 */ u16 unk010;
    /* 0x012 */ u8 pad012[4];
    /* 0x016 */ u8 unk016;
    /* 0x017 */ u8 unk017;
    /* 0x018 */ u8 unk018;
    /* 0x019 */ u8 pad019[3];
    /* 0x01c */ u16 unk01C;
    /* 0x01e */ u8 unk01E;
    /* 0x01f */ u8 unk01F;
    /* 0x020 */ u8 pad020[4];
    /* 0x024 */ void *unk024;
    /* 0x028 */ u8 pad028[0x20];
    /* 0x048 */ void *bgConfig;
    /* 0x04c */ Window windows[4];
    /* 0x08c */ void *yesNo;
    /* 0x090 */ u8 unk090;
    /* 0x091 */ u8 pad091[7];
    /* 0x098 */ void *unk098;
    /* 0x09c */ void *options;
    /* 0x0a0 */ void *saveData;
    /* 0x0a4 */ void *unk0A4;
    /* 0x0a8 */ u8 unk0A8[0x15c];
    /* 0x204 */ Ov82Spr *spr204;
    /* 0x208 */ Ov82Spr *spr208;
    /* 0x20c */ u8 pad20C[4];
    /* 0x210 */ void *unk210;
    /* 0x214 */ void *party;
    /* 0x218 */ void *unk218;
    /* 0x21c */ void *unk21C;
    /* 0x220 */ u8 pad220[4];
    /* 0x224 */ u16 unk224;
    /* 0x226 */ u16 unk226;
    /* 0x228 */ u16 unk228;
    /* 0x22a */ u16 unk22A;
    /* 0x22c */ u8 pad22C[0x50];
    /* 0x27c */ u8 unk27C;
    /* 0x27d */ u8 unk27D;
    /* 0x27e */ u8 pad27E[6];
} Ov82Work;

#endif
