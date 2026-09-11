#ifndef OVERLAY_28_PRIVATE_H
#define OVERLAY_28_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "field_system.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "map_object.h"
#include "math_util.h"
#include "msgdata.h"
#include "script_manager.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "string_util.h"
#include "sys_task.h"
#include "systask_environment.h"
#include "touchscreen.h"
#include "unk_0200A090.h"
#include "unk_02020B8C.h"
#include "unk_0203DB6C.h"

typedef struct DowsingMchnAngle {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} DowsingMchnAngle;

typedef struct DowsingMchnSlot {
    u32 unk0;
    u32 unk4;
    u16 val : 15;
    u16 flag : 1;
} DowsingMchnSlot;

typedef struct DowsingMchn {
    /* 0x000 */ u8 unk000[0x10];
    /* 0x010 */ BgConfig *bgConfig;
    /* 0x014 */ void *unk014;
    /* 0x018 */ FieldSystem *fieldSystem;
    /* 0x01C */ void *unk01C;
    /* 0x020 */ SysTask *task;
    /* 0x024 */ SpriteList *spriteList;
    /* 0x028 */ u8 renderer[0x128];
    /* 0x150 */ GF_2DGfxResMan *resMans[4];
    /* 0x160 */ void *resObjA[4];
    /* 0x170 */ void *resObjB[4];
    /* 0x180 */ Sprite *sprites[8];
    /* 0x1A0 */ String *strings[5];
    /* 0x1B4 */ Window windows[5];
    /* 0x204 */ HiddenItemResponse *hiddenItems;
    /* 0x208 */ s16 unk208;
    /* 0x20A */ s16 unk20A;
    /* 0x20C */ int unk20C;
    /* 0x210 */ u8 unk210[0x4];
    /* 0x214 */ int unk214;
    /* 0x218 */ int unk218;
    /* 0x21C */ u8 unk21C[0x4];
    /* 0x220 */ DowsingMchnSlot slots[4];
    /* 0x250 */ u8 unk250[0xE4];
    /* 0x334 */ int unk334;
    /* 0x338 */ u8 unk338[4];
    /* 0x33C */ int unk33C;
} DowsingMchn;

#endif
