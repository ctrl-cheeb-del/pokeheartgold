#ifndef TO45_OVERLAY85_EFFECT_R31_PRIVATE_H
#define TO45_OVERLAY85_EFFECT_R31_PRIVATE_H

#include "global.h"

#include "overlay85_helpers_internal.h"
#include "sprite_system.h"
#include "sys_task_api.h"

typedef struct Ov85EffectTaskR31 {
    s32 state;
    s32 timer;
    u32 unk_08;
    s32 soundIndex;
    BattleArcadeWork *work;
    ManagedSprite *sprite;
} Ov85EffectTaskR31;

typedef struct Ov85EffectStateR31 {
    u16 state;
    u16 done;
    s32 timer;
} Ov85EffectStateR31;

typedef struct Ov85SoundListR31 {
    u32 sound[4];
} Ov85SoundListR31;

extern const Ov85SoundListR31 ov85_021EA528;

void ov85_021E815C(SysTask *task, void *taskData);
void ov85_021E825C(BattleArcadeWork *work, Ov85EffectStateR31 *state);

#endif
