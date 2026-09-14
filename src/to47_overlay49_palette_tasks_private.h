#ifndef TO47_OVERLAY49_PALETTE_TASKS_PRIVATE_H
#define TO47_OVERLAY49_PALETTE_TASKS_PRIVATE_H

// global.h MUST be first: it selects Thumb and establishes SDK macro state.
#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "sys_task.h"
#include "sys_task_api.h"

#pragma require_prototypes off

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))

NarcId sub_020776B4(void);
int sub_02077690(void);

SysTask *ov49_0225BA40(void *data, u32 unused, u16 memberNo, u16 heapId);
void ov49_0225BA5C(SysTask *task, void *data);
void ov49_0225BABC(void *unused, void *obj, NARC *narc, u32 which, enum HeapID heapId);

#endif
