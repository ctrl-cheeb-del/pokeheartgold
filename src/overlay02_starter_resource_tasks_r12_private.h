#ifndef TO45_SOL_R6_OVERLAY02_R12_PRIVATE_H
#define TO45_SOL_R6_OVERLAY02_R12_PRIVATE_H

#include "global.h"

#include "constants/heap.h"

#include "bg_window.h"
#include "filesystem.h"
#include "heap.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"
#include "unk_0200A090.h"

void ov02_02249D5C(SysTask *, void *);
void ov02_02249DD8(SysTask *, void *);
void ov02_02249E58(SysTask *, void *);
void ov02_02249E90(SysTask *, void *);
void ov02_02249EC0(void *);
void ov02_02249F6C(void *);
void ov02_02249FD4(void *);
void ov02_0224A028(void *);

void ov02_0224A834(void *, void *);
void ov02_0224A88C(void *, void *);
NARC *ov02_0224A074(void);
void ov02_0224A69C(void *, u32, u32, u32, u32);
void ov02_0224A648(void *);
void GfGfx_EngineATogglePlanes(u8, u8);
void ov02_0224A570(NARC *, u32, NNSG2dPaletteData **);
void ov02_0224A598(BgConfig *, NARC *, u32, NNSG2dCharacterData **);
void ov02_0224A5D0(BgConfig *, NARC *, u32, NNSG2dScreenData **);
void ov02_0224A080(void *, NARC *);
void *sub_020689C8(int, int);
void sub_020689F8(void *);
void ov02_0224A63C(BgConfig *);
void ov02_0224A288(void *);
void FieldMessage_LoadTextPalettes(int, int);

#endif
