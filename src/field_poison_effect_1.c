#include "field_poison_effect_internal.h"

void *ov01_021FB5D4(enum HeapID heapID, HBlankSystem *hBlankSystem);
void ov01_021FB610(void *unk20);
void FieldSystem_DoPoisonEffect(void *unk20);
void ov01_021FB6C4(SysTask *task, void *data);
void ov01_021FB750(PoisonEffect *effect);
void ov01_021FB788(u16 *dest, int num, int den);
void ov01_021FB7CC(SysTask *task, void *data);
void ov01_021FB7DC(void *unused, void *data);
void ov01_021FB7E8(PoisonEffect *effect);
void ov01_021FB800(SysTask *task, void *data);
void ov01_021FB80C(PoisonEffect *effect);
void ov01_021FB82C(PoisonEffect *effect);

void *ov01_021FB5D4(enum HeapID heapID, HBlankSystem *hBlankSystem) {
    PoisonEffect *effect = Heap_Alloc(heapID, sizeof(PoisonEffect));
    memset(effect, 0, sizeof(PoisonEffect));
    effect->state = 0;
    effect->doubleBuffer = sub_02014A08(heapID, effect->buffers[0], effect->buffers[1]);
    effect->hBlankSystem = hBlankSystem;
    return effect;
}

void ov01_021FB610(void *unk20) {
    PoisonEffect *effect = unk20;
    if (effect->state == 1) {
        ov01_021FB82C(effect);
    }
    sub_02014A38(effect->doubleBuffer);
    Heap_Free(effect);
}

void FieldSystem_DoPoisonEffect(void *unk20) {
    PoisonEffect *effect = unk20;
    GF_ASSERT(effect->state == 0);
    effect->hblankTask = ov01_021FB530(effect->hBlankSystem, ov01_021FB7DC, effect);
    effect->mainTask = SysTask_CreateOnMainQueue(ov01_021FB6C4, effect, 1024);
    effect->vblankTask = SysTask_CreateOnVBlankQueue(ov01_021FB7CC, effect, 1024);
    effect->vblankTask2 = SysTask_CreateOnVBlankQueue(ov01_021FB800, effect, 1024);
    memset(effect->buffers[0], 0, sizeof(effect->buffers[0]));
    memset(effect->buffers[1], 0, sizeof(effect->buffers[1]));
    effect->state = 1;
    effect->seqNo = 0;
    PlaySE(SEQ_SE_DP_DOKU2);
}

void ov01_021FB6C4(SysTask *task, void *data) {
    PoisonEffect *effect = data;
    switch (effect->seqNo) {
    case 0:
        effect->counter = 3;
        effect->seqNo++;
        break;
    case 1:
        effect->counter--;
        ov01_021FB788(sub_02014A4C(effect->doubleBuffer), 3 - effect->counter, 3);
        if (effect->counter <= 0) {
            effect->counter = 3;
            effect->seqNo++;
        }
        break;
    case 2:
        effect->counter--;
        ov01_021FB788(sub_02014A4C(effect->doubleBuffer), effect->counter, 3);
        if (effect->counter <= 0) {
            effect->seqNo++;
        }
        break;
    case 3:
        ov01_021FB82C(effect);
        G3X_SetHOffset(0);
        break;
    }
}

void ov01_021FB750(PoisonEffect *effect) {
    s32 vcount = GX_GetVCount();
    u16 *buffer = sub_02014A60(effect->doubleBuffer);
    if (vcount < 192) {
        s32 line = vcount + 1;
        if (line >= 192) {
            line -= 192;
        }
        if (reg_GX_DISPSTAT & REG_GX_DISPSTAT_HBLK_MASK) {
            G3X_SetHOffset(buffer[line]);
        }
    }
}
