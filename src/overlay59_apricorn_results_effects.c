#include "overlay59_apricorn_results_internal.h"

void ov59_0223BFC8(void *task, Ov59ResultScaleTask *data) {
    void *parent = data->parent;

    data->angle += data->angleStep;
    data->scaleX += data->velocity;
    data->scaleY += data->velocity;
    data->timer--;
    if (data->timer != 0) {
        Sprite_SetAffineZRotation(data->sprite, GF_DegreeToSinCosIdx(data->angle));
        Sprite_SetAffineScale(data->sprite, &data->scaleX);
        return;
    }

    Sprite_SetAffineZRotation(data->sprite, 0);
    data->scaleX = FX32_ONE;
    data->scaleY = FX32_ONE;
    data->scaleZ = FX32_ONE;
    Sprite_SetAffineScale(data->sprite, &data->scaleX);
    if (data->hide != 0) {
        Sprite_SetDrawFlag(data->sprite, FALSE);
    }
    OV59_RESULT_U8(parent, 0x4F)
    --;
    Heap_Free(data);
    SysTask_Destroy(task);
}

void ov59_0223C054(void *parent) {
    Ov59ResultShakeTask *data = Heap_Alloc(OV59_RESULT_U32(parent, 0), sizeof(Ov59ResultShakeTask));

    MI_CpuFill8(data, 0, sizeof(Ov59ResultShakeTask));
    data->parent = parent;
    data->counter = 30;
    data->delta = 12;
    PlaySE(0x922);
    SysTask_CreateOnMainQueue(ov59_0223C09C, data, 0);
    OV59_RESULT_U8(parent, 0x4F)
    ++;
}

void ov59_0223C09C(void *task, Ov59ResultShakeTask *data) {
    void *savedTask = task;
    void *parent = data->parent;

    if ((data->phase % 2) == 0) {
        Pokepic_AddAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xC, data->delta);
        Pokepic_AddAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xD, -data->delta);
    } else {
        Pokepic_AddAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xC, -data->delta);
        Pokepic_AddAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xD, data->delta);
    }

    if (data->counter++ >= 8) {
        data->counter = 0;
        if (data->phase++ >= 4) {
            Pokepic_SetAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xC, 0x100);
            Pokepic_SetAttr(OV59_RESULT_PTR(OV59_RESULT_PTR(parent, 0x78), 0x20), 0xD, 0x100);
            OV59_RESULT_U8(parent, 0x4F)
            --;
            Heap_Free(data);
            SysTask_Destroy(savedTask);
        }
    }
}

void ov59_0223C138(void *parent) {
    Ov59ResultShakeTask *data = Heap_Alloc(OV59_RESULT_U32(parent, 0), sizeof(Ov59ResultShakeTask));

    MI_CpuFill8(data, 0, sizeof(Ov59ResultShakeTask));
    data->parent = parent;
    SysTask_CreateOnMainQueue(ov59_0223C16C, data, 0);
    OV59_RESULT_U8(parent, 0x4F)
    ++;
}
