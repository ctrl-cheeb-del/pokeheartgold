#include "global.h"

#include "heap.h"
#include "sprite_system.h"
#include "sys_task_api.h"
#include "to45_overlay85_effect_r31_private.h"
#include "unk_02005D10.h"

void ov85_021E815C(SysTask *task, void *taskData) {
    Ov85EffectTaskR31 *data = taskData;

    switch (data->state) {
    case 0:
        if (data->soundIndex < 4) {
            Ov85SoundListR31 sounds = ov85_021EA528;
            data->timer--;
            if (data->timer <= 0) {
                data->timer = 30;
                PlaySE(sounds.sound[data->soundIndex]);
                data->soundIndex++;
            }
        }
        ManagedSprite_TickNFrames(data->sprite, 0x1800);
        if (!ManagedSprite_IsAnimated(data->sprite)) {
            data->state++;
        }
        break;
    case 1:
        Sprite_DeleteAndFreeResources(data->sprite);
        Heap_Free(data);
        SysTask_Destroy(task);
        break;
    }
}
