#ifndef POKEHEARTGOLD_TOUCH_SPRITE_MOTION_INTERNAL_H
#define POKEHEARTGOLD_TOUCH_SPRITE_MOTION_INTERNAL_H

#include "global.h"

#include "filesystem.h"
#include "heap.h"
#include "palette.h"
#include "sprite_system.h"
#include "sys_task_api.h"

typedef struct UnkStruct02087284_Sub {
    /* 0x00 */ ManagedSprite *sprite;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ int unk_08;
    /* 0x0C */ int unk_0C;
} UnkStruct02087284_Sub; // size 0x10

typedef struct UnkStruct02087284 {
    /* 0x000 */ NARC *narc;
    /* 0x004 */ SpriteSystem *spriteSys;
    /* 0x008 */ SpriteManager *spriteMan;
    /* 0x00C */ PaletteData *plttData;
    /* 0x010 */ int count;
    /* 0x014 */ enum HeapID heapId;
    /* 0x018 */ int resBase;
    /* 0x01C */ int unk_1C;
    /* 0x020 */ fx32 yOffset;
    /* 0x024 */ UnkStruct02087284_Sub sprites[12];
    /* 0x0E4 */ int state;
    /* 0x0E8 */ int unk_E8;
    /* 0x0EC */ int unk_EC;
    /* 0x0F0 */ int unk_F0;
    /* 0x0F4 */ SysTask *task;
    /* 0x0F8 */ int unk_F8;
    /* 0x0FC */ int unk_FC;
    /* 0x100 */ int unk_100;
    /* 0x104 */ int unk_104;
} UnkStruct02087284; // size 0x108

UnkStruct02087284 *sub_02087284(int a0, enum HeapID a1, int a2, int a3, fx32 a4, SpriteSystem *a5, SpriteManager *a6, PaletteData *a7);
void sub_0208763C(UnkStruct02087284 *p, int a1);
void sub_020876B0(UnkStruct02087284 *p, int a1);
void sub_020877B4(UnkStruct02087284 *p);
void sub_02087830(UnkStruct02087284 *p);
BOOL sub_02087878(UnkStruct02087284 *p, int a1);
BOOL sub_020878B0(UnkStruct02087284 *p, int a1);
BOOL sub_020878B8(UnkStruct02087284 *p, int x, int y);
BOOL sub_020878EC(UnkStruct02087284 *p, int x, int y);
BOOL sub_02087930(UnkStruct02087284 *p, int x, int y);
BOOL sub_02087948(UnkStruct02087284 *p, s16 x, s16 y);
BOOL sub_02087988(UnkStruct02087284 *p);
BOOL sub_020879E0(UnkStruct02087284 *p, int flag);
void sub_02087A08(UnkStruct02087284 *p, int a1, int a2);
void sub_02087A30(UnkStruct02087284 *p);
void sub_02087A54(UnkStruct02087284 *p);
extern void sub_020873D4(SysTask *task, void *data);

extern const int _02102814[];

typedef char AssertTouchSpriteSize[(sizeof(UnkStruct02087284_Sub) == 0x10) ? 1 : -1];
typedef char AssertTouchMotionSize[(sizeof(UnkStruct02087284) == 0x108) ? 1 : -1];
typedef char AssertTouchSprites[(offsetof(UnkStruct02087284, sprites) == 0x24) ? 1 : -1];
typedef char AssertTouchState[(offsetof(UnkStruct02087284, state) == 0xE4) ? 1 : -1];
typedef char AssertTouchTask[(offsetof(UnkStruct02087284, task) == 0xF4) ? 1 : -1];

#endif
