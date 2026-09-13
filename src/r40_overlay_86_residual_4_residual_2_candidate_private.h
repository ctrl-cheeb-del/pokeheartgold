#ifndef POKEHEARTGOLD_R40_OV86_R4R2_PRIVATE_H
#define POKEHEARTGOLD_R40_OV86_R4R2_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "heap.h"
#include "msgdata.h"
#include "sprite_system.h"
#include "unk_02030A98.h"
#include "unk_0205BFF0.h"
typedef struct Work {
    void *man;
    u8 state, unk5, mode, kind;
    u16 unk8, unkA;
    void *bgConfig;
    Window windows[32];
    MsgData *msgData;
    void *msgFmt;
    String *str;
    void *plttData;
    void *options;
    SaveData *saveData;
    void *frontier;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[2];
    Window titleWindow;
} Work;
void ov86_021E6024(Work *, u32, u32, u32, u32, u32, u32, u32);
void ov86_021E6064(Work *, u32, u32, u32, u32, u32, u32, u32);
void ov86_021E5FBC(Work *, u32, u32);
void ov86_021E668C(Work *, int);
void ov86_021E64E0(Work *);
u32 sub_0205C268(u32);
#endif
