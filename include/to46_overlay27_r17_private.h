#ifndef TO46_OVERLAY27_R17_PRIVATE_H
#define TO46_OVERLAY27_R17_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "overlay_01.h"
#include "sprite.h"
#include "task.h"

typedef struct Ov27R17FieldSystem {
    u8 padding000[0xD2];
    u8 taskState : 6;
    u8 taskFlag6 : 1;
    u8 taskFlag7 : 1;
} Ov27R17FieldSystem;

typedef struct Ov27R17TaskState {
    u32 state;
    u8 padding004[0x24 - 0x04];
    Ov27R17FieldSystem *fieldSystem;
    u8 padding028[0x218 - 0x28];
    SpriteList *spriteList;
} Ov27R17TaskState;

typedef struct Ov27R17Work {
    u8 padding000[0x18];
    BgConfig *bgConfig;
    u8 padding01C[0x28 - 0x1C];
    Window window28;
    Window window38;
    u8 padding048[4];
    MsgData *msgData;
} Ov27R17Work;

typedef BOOL (*Ov27R17StateFunc)(Ov27R17TaskState *);

extern const Ov27R17StateFunc ov27_0225D4D4[];

void ov27_0225C434(SysTask *task, Ov27R17TaskState *state);
void ov27_0225C4AC(Ov27R17Work *work);
void ov27_0225C540(Ov27R17Work *work);
void ov27_0225C8D0(Window *window, MsgData *msgData, u32 msgId);

#endif
