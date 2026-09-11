#ifndef POKEHEARTGOLD_OV33_PRIVATE_H
#define POKEHEARTGOLD_OV33_PRIVATE_H
#include "global.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "msgdata.h"
#include "pm_string.h"
#include "sys_task.h"
#include "system.h"
#include "systask_environment.h"
#include "text.h"
#include "touchscreen.h"
typedef struct Ov33Entry {
    const WindowTemplate *windows;
    const TouchscreenHitbox *hitboxes;
    u8 x;
    u8 y;
    u16 spacing;
} Ov33Entry;
typedef struct Ov33Args {
    u32 *msgIds;
    u8 count;
    u8 unk5;
    u16 selection;
} Ov33Args;
typedef struct Ov33Env {
    BgConfig *bgConfig;
    void *unk04;
    void *unk08;
    Ov33Args *unk0C;
    Ov33Args *args;
    SysTask *task;
    Window windows[2];
    u16 tilemap[0xC0];
    u16 state;
    u16 count;
    s32 touchIdx;
} Ov33Env;
SysTask *ov33_0225D520(BgConfig *bgConfig, void *a1, void *a2, Ov33Args *args);
void ov33_0225D5A8(void *a0, SysTask *task);
BOOL ov33_0225D5CC(void);
static void ov33_0225D5D0(SysTask *task, void *data);
static void ov33_0225D6F8(void);
static void ov33_0225D720(BgConfig *bgConfig);
static void ov33_0225D7B8(BgConfig *bgConfig);
static void ov33_0225D7D4(Ov33Env *env);
static void ov33_0225D820(Ov33Env *env);
static void ov33_0225D84C(Ov33Env *env);
void ov33_0225D8D4(Ov33Env *env);
static void ov33_0225D9D4(Ov33Env *env, u8 palette);
#endif
