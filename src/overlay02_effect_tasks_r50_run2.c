#include "overlay02_effect_slots_r50_private.h"

void ov02_0224E008(u8 *work) {
    int i;

    i = 0;
    work += 0x10;
    do {
        ov02_0224DE6C((Ov02EffectSlot *)work);
        i++;
        work += sizeof(Ov02EffectSlot);
    } while (i < 18);
}

void ov02_0224E020(SysTask *task, void *arg) {
    Ov02EffectTask *data = arg;
    switch (data->state) {
    case 0:
        if (ov02_02253A34[data->kind](data->object) == TRUE) {
            data->state++;
        }
        break;
    case 1:
        ov02_02253A04[data->kind](data->object);
        *data->result = TRUE;
        Heap_Free(data);
        SysTask_Destroy(task);
        break;
    }
}

void ov02_0224E074(void *fieldSystem, u16 *result, int kind, enum HeapID heapID) {
    Ov02EffectTask *data = Heap_Alloc(heapID, sizeof(*data));

    memset(data, 0, sizeof(*data));
    data->object = ov02_02253A1C[kind](fieldSystem);
    data->result = result;
    data->kind = kind;
    *result = FALSE;
    SysTask_CreateOnMainQueue(ov02_0224E020, data, 0);
}
