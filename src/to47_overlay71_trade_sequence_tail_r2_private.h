#ifndef OV71_RESIDUAL_2_PRIVATE_H
#define OV71_RESIDUAL_2_PRIVATE_H

#include "global.h"

#include "gf_gfx_loader.h"
#include "heap.h"
#include "overlay_manager.h"
#include "sprite.h"
#include "sys_task_api.h"

typedef struct Ov71Sys {
    u16 unk_000[0x60];
    SysTask *unk_0C0;
    void *tasks[8];
    u32 *unk_0E4;
    u32 unk_0E8;
    u32 unk_0EC;
    u32 unk_0F0;
    u32 unk_0F4;
    u32 unk_0F8;
    void *unk_0FC;
} Ov71Sys;

typedef void *(*Ov71StateInit)(void *data);
typedef BOOL (*Ov71StateMain)(void *work, int *state);
typedef void (*Ov71StateExit)(void *work);

extern Ov71StateInit ov71_0224BBEC[];
extern Ov71StateMain ov71_0224BBF0[];
extern Ov71StateExit ov71_0224BBF4[];
extern u32 ov71_0224BBF8[];

void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int eva, int evb);

void OamManager_ApplyAndResetBuffers(void);
void ov71_022473F0(void);
void ov71_02246D9C(SysTask *task, void *data);

BOOL TradeSequence_Main(OverlayManager *manager, int *state);
void ov71_02246C48(void *unused, void *data);
Ov71Sys *ov71_02246C6C(u32 *a0, void *a1);

#endif // OV71_RESIDUAL_2_PRIVATE_H
