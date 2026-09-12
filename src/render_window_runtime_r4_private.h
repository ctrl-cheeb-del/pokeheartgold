#ifndef POKEHEARTGOLD_RENDER_WINDOW_RUNTIME_R4_PRIVATE_H
#define POKEHEARTGOLD_RENDER_WINDOW_RUNTIME_R4_PRIVATE_H

#include "gf_gfx_loader.h"
#include "render_window.h"
#include "sys_task_api.h"

typedef struct WaitingIconRuntimeWork {
    u8 padding[0x486];
    u8 tick;
    u8 frame : 7;
    u8 flag : 1;
    u8 state : 2;
    u8 statePadding : 6;
} WaitingIconRuntimeWork;

void *sub_0200E63C(void *);
void sub_0200F1D4(void *, int);

void sub_0200EB80(BgConfig *, u8, u16, u8, u8, enum HeapID);
void sub_0200F3D0(SysTask *, WaitingIconRuntimeWork *);

#endif
