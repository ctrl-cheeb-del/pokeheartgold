#ifndef OVERLAY40_TOUCH_INDICATOR_R25_PRIVATE_H
#define OVERLAY40_TOUCH_INDICATOR_R25_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "save_misc_data.h"
#include "sys_task_api.h"
#include "touch_sprite_motion_internal.h"
#include "touchscreen.h"

typedef struct Ov40TouchIndicatorWork {
    u8 pad_0000[0x6F0];
    UnkStruct02087284 *motionB;
    UnkStruct02087284 *motionA;
    u8 pad_06F8[0x3A64];
    s32 active;
    s32 counter;
    UnkStruct02087284 *motion;
    SysTask *task;
} Ov40TouchIndicatorWork;
extern void GF_AssertFail(void);
int ov40_022306F0(void *);
void ov40_02230738(void);
void ov40_0223077C(void *, UnkStruct02087284 *, s16, s16);
int ov40_022307B0(u64);
void ov40_022307DC(void *, int, GFBgLayer);
void ov40_022307FC(SysTask *, Ov40TouchIndicatorWork *);
void ov40_02230864(Ov40TouchIndicatorWork *);
#endif
