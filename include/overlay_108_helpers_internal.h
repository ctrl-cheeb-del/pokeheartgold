#ifndef OV108_PRIVATE_H
#define OV108_PRIVATE_H

#include "global.h"

typedef struct Ov108Sub {
    /* 0x000 */ u32 heapId;
    /* 0x004 */ void *unk04;
    /* 0x008 */ u16 unk08;
    /* 0x00A */ u16 unk0A;
    /* 0x00C */ u16 unk0C;
    /* 0x00E */ u16 unk0E;
    /* 0x010 */ void *spriteList;
    /* 0x014 */ void *unk14;
    /* 0x018 */ u8 pad18[0x144 - 0x018];
    /* 0x144 */ void *resMan[4];
    /* 0x154 */ void *resList[4];
} Ov108Sub; /* 0x164 */

typedef struct Ov108Window {
    u8 dummy[0x10];
} Ov108Window;

typedef struct Ov108Res {
    void **objs;
} Ov108Res;

typedef struct Ov108Vars {
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *unk04;
} Ov108Vars;

typedef struct SafariAreaCustomizer {
    /* 0x00000 */ u32 heapId;
    /* 0x00004 */ u32 unk04;
    /* 0x00008 */ u32 unk08;
    /* 0x0000C */ u32 unk0C;
    /* 0x00010 */ u32 unk10;
    /* 0x00014 */ Ov108Vars *unk14;
    /* 0x00018 */ void *unk18;
    /* 0x0001C */ u8 unk1C[0x340 - 0x01C];
    /* 0x00340 */ void *bgConfig;
    /* 0x00344 */ void *listMenuSpawner;
    /* 0x00348 */ Ov108Sub *sub;
    /* 0x0034C */ void *spriteSystem;
    /* 0x00350 */ void *spriteMan;
    /* 0x00354 */ void *sprites[18];
    /* 0x0039C */ void *fontSystem;
    /* 0x003A0 */ void *unk3A0;
    /* 0x003A4 */ void *textObj;
    /* 0x003A8 */ u8 unk3A8[0x3B4 - 0x3A8];
    /* 0x003B4 */ Ov108Window windows[15];
    /* 0x004A4 */ Ov108Window yesNoWindow;
    /* 0x004B4 */ void *listMenuItems1;
    /* 0x004B8 */ void *listMenuItems2;
    /* 0x004BC */ u8 pad4BC[0x4C0 - 0x4BC];
    /* 0x004C0 */ void *yesNoPrompt;
    /* 0x004C4 */ void (*cb4C4)(struct SafariAreaCustomizer *);
    /* 0x004C8 */ void (*cb4C8)(struct SafariAreaCustomizer *);
    /* 0x004CC */ void *alloc1;
    /* 0x004D0 */ void *alloc2;
    /* 0x004D4 */ u8 pad4D4[0x184DC - 0x4D4];
    /* 0x184DC */ u8 unk184DC;
    /* 0x184DD */ u8 unk184DD;
    /* 0x184DE */ u8 unk184DE;
    /* 0x184DF */ u8 unk184DF;
    /* 0x184E0 */ u8 unk184E0;
    /* 0x184E1 */ u8 unk184E1;
    /* 0x184E2 */ u8 flag0 : 1;
    u8 bit1 : 1;
    u8 flagB : 1;
    u8 mode : 5;
    /* 0x184E3 */ u8 unk184E3;
    /* 0x184E4 */ s16 unk184E4;
    /* 0x184E6 */ s16 unk184E6;
    /* 0x184E8 */ u32 unk184E8;
} SafariAreaCustomizer; /* 0x184EC */

#endif
