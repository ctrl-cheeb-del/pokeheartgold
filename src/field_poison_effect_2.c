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

void ov01_021FB7CC(SysTask *task, void *data) {
    PoisonEffect *effect = data;
    effect->hblankReady = 0;
    G3X_SetHOffset(0);
}

void ov01_021FB7DC(void *unused, void *data) {
    ov01_021FB7E8(data);
}

void ov01_021FB7E8(PoisonEffect *effect) {
    if (effect->state == 1 && effect->hblankReady == 1) {
        ov01_021FB750(effect);
    }
}

void ov01_021FB800(SysTask *task, void *data) {
    ov01_021FB80C(data);
}

void ov01_021FB80C(PoisonEffect *effect) {
    if (effect->state == 1) {
        sub_02014A8C(effect->doubleBuffer);
        effect->hblankReady = 1;
    }
}

void ov01_021FB82C(PoisonEffect *effect) {
    ov01_021FB554(effect->hblankTask);
    effect->hblankTask = NULL;
    SysTask_Destroy(effect->mainTask);
    effect->mainTask = NULL;
    SysTask_Destroy(effect->vblankTask);
    effect->vblankTask = NULL;
    SysTask_Destroy(effect->vblankTask2);
    effect->vblankTask2 = NULL;
    effect->state = 0;
}
