#ifndef TO45_OVERLAY92_TAIL_PRIVATE_H
#define TO45_OVERLAY92_TAIL_PRIVATE_H

#include "global.h"

#include "sys_task_api.h"

typedef struct Ov92Tween {
    s32 value;
    u8 pad04[0x18 - 4];
} Ov92Tween;

typedef struct Ov92SpriteTask {
    s32 state;
    s32 mode;
    s32 counter;
    void *sprite;
    Ov92Tween tween;
    s32 previous;
    s32 *current;
    s32 active;
    u8 pad34[8];
    void *parent;
    s32 extra;
} Ov92SpriteTask;

typedef struct Ov92Work14 {
    u8 pad0000[0x2AE4];
    s32 progress;
    u32 mode;
    u32 index;
    u32 accumulator;
} Ov92Work14;

extern const u16 ov92_02263C34[];

void ov92_0225F338(SysTask *task, Ov92SpriteTask *work);
void ov92_0225F878(Ov92Work14 *work);
void ov92_0225F8B0(Ov92Work14 *work);

#endif
