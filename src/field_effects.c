#include <string.h>

#include "global.h"

#include "heap.h"
#include "sys_task_api.h"
#include "unk_020689C8.h"
typedef struct FieldEffect FieldEffect;
typedef struct FieldEffectManager {
    int count;
    int activeCount;
    enum HeapID heapID;
    FieldEffect *effects;
} FieldEffectManager;
typedef void (*EffectCallback)(FieldEffect *, void *);
typedef BOOL (*EffectInit)(FieldEffect *, void *);
struct FieldEffect {
    u32 flags;
    int parameter;
    u32 unk8;
    void *userData;
    SysTask *task;
    FieldEffectManager *manager;
    u8 padding[12];
    VecFx32 position;
    u8 state[128];
    EffectInit init;
    EffectCallback update;
    EffectCallback draw;
    EffectCallback destroy;
    EffectCallback extra1;
    EffectCallback extra2;
};
typedef struct EffectTemplate {
    u32 size;
    EffectInit init;
    EffectCallback destroy;
    EffectCallback update;
    EffectCallback draw;
    EffectCallback extra1;
    EffectCallback extra2;
} EffectTemplate;
typedef struct EffectTemplateShort {
    u32 size;
    EffectInit init;
    EffectCallback destroy;
    EffectCallback update;
    EffectCallback draw;
} EffectTemplateShort;
FieldEffectManager *sub_020689C8(enum HeapID heapID, int count);
void sub_020689E8(FieldEffectManager *manager);
void sub_020689F8(FieldEffectManager *manager);
FieldEffect *sub_02068A08(FieldEffectManager *manager, const EffectTemplate *template, const VecFx32 *position, int parameter, void *userData, u32 priority);
FieldEffect *sub_02068B0C(FieldEffectManager *manager, const EffectTemplateShort *template, const VecFx32 *position, int parameter, void *userData, u32 priority);
void sub_02068B48(int value);
void sub_02068B80(FieldEffectManager *manager);
void sub_02068BAC(FieldEffectManager *manager);
SysTask *sub_02068BDC(FieldEffect *effect, u32 priority);
void sub_02068BFC(SysTask *task, void *data);
FieldEffectManager *sub_02068C08(enum HeapID heapID);
void sub_02068C2C(FieldEffectManager *manager);
FieldEffect *sub_02068C38(enum HeapID heapID, int count);
void sub_02068C5C(FieldEffectManager *manager);
void sub_02068C6C(FieldEffect *effect);
int sub_02068CC4(FieldEffectManager *manager);
FieldEffect *sub_02068CC8(FieldEffectManager *manager);
BOOL sub_02068CCC(FieldEffect *effect);
void sub_02068CD8(FieldEffect *effect);
void sub_02068CE4(FieldEffect *effect, u32 flags);
u32 sub_02068CEC(FieldEffect *effect, u32 flags);
void sub_02068CF4(FieldEffect *effect, EffectInit callback);
BOOL sub_02068CFC(FieldEffect *effect);
void sub_02068D10(FieldEffect *effect, EffectCallback callback);
void sub_02068D18(FieldEffect *effect);
void sub_02068D2C(FieldEffect *effect, EffectCallback callback);
void sub_02068D34(FieldEffect *effect);
void sub_02068D48(FieldEffect *effect, EffectCallback callback);
void sub_02068D50(FieldEffect *effect);
void sub_02068D64(FieldEffect *effect, EffectCallback callback);
void sub_02068D6C(FieldEffect *effect, EffectCallback callback);
void *sub_02068D74(FieldEffect *effect);
void sub_02068D78(FieldEffect *effect, u32 size);
void sub_02068D8C(FieldEffect *effect, int parameter);
int sub_02068D90(FieldEffect *effect);
void sub_02068D94(FieldEffect *effect, void *userData);
UnkOv01_021FFFCC *sub_02068D98(void *data);
void sub_02068D9C(FieldEffect *effect, SysTask *task);
SysTask *sub_02068DA0(FieldEffect *effect);
void sub_02068DA4(FieldEffect *effect, FieldEffectManager *manager);
void sub_02068DA8(FieldEffect *effect, const VecFx32 *position);
void sub_02068DB8(void *data, VecFx32 *position);
BOOL sub_02068DC8(FieldEffect *effect, void *state);
void sub_02068DCC(FieldEffect *effect, void *state);
void sub_02068DD0(FieldEffect *effect, void *state);
void sub_02068DD4(FieldEffect *effect, void *state);
void sub_02068DD8(FieldEffect *effect, void *state);
void sub_02068DDC(FieldEffect *effect, void *state);
FieldEffectManager *sub_020689C8(enum HeapID heapID, int count) {
    FieldEffectManager *manager = sub_02068C08(heapID);
    manager->effects = sub_02068C38(heapID, count);
    manager->count = count;
    manager->heapID = heapID;
    return manager;
}
void sub_020689E8(FieldEffectManager *manager) {
    sub_02068C5C(manager);
    sub_02068C2C(manager);
}
void sub_020689F8(FieldEffectManager *manager) {
    sub_02068B80(manager);
    sub_020689E8(manager);
}
FieldEffect *sub_02068A08(FieldEffectManager *manager, const EffectTemplate *template, const VecFx32 *position, int parameter, void *userData, u32 priority) {
    int i = 0;
    int count = sub_02068CC4(manager);
    FieldEffect *effect = sub_02068CC8(manager);
    SysTask *task;
    do {
        if (!sub_02068CCC(effect)) {
            break;
        }
        i++;
        effect++;
    } while (i < count);
    if (i >= count) {
        return NULL;
    }
    sub_02068CD8(effect);
    sub_02068D8C(effect, parameter);
    sub_02068D94(effect, userData);
    sub_02068DA4(effect, manager);
    if (position) {
        sub_02068DA8(effect, position);
    } else {
        VecFx32 zero = { 0, 0, 0 };
        sub_02068DA8(effect, &zero);
    }
    sub_02068D78(effect, template->size);
    sub_02068CF4(effect, template->init);
    sub_02068D48(effect, template->destroy);
    sub_02068D10(effect, template->update);
    sub_02068D2C(effect, template->draw);
    sub_02068D64(effect, template->extra1);
    sub_02068D6C(effect, template->extra2);
    task = sub_02068BDC(effect, priority);
    if (!task) {
        sub_02068C6C(effect);
        return NULL;
    }
    sub_02068D9C(effect, task);
    if (!sub_02068CFC(effect)) {
        SysTask_Destroy(task);
        sub_02068C6C(effect);
        return NULL;
    }
    sub_02068CE4(effect, 2);
    manager->activeCount++;
    return effect;
}
FieldEffect *sub_02068B0C(FieldEffectManager *manager, const EffectTemplateShort *template, const VecFx32 *position, int parameter, void *userData, u32 priority) {
    EffectTemplate full;
    *(EffectTemplateShort *)&full = *template;
    full.extra1 = sub_02068DD8;
    full.extra2 = sub_02068DDC;
    return sub_02068A08(manager, &full, position, parameter, userData, priority);
}
void sub_02068B48(int value) {
    FieldEffect *effect = (FieldEffect *)value;
    SysTask *task;
    GF_ASSERT(effect != NULL);
    if (sub_02068CCC(effect)) {
        sub_02068D50(effect);
        effect->manager->activeCount--;
        task = sub_02068DA0(effect);
        if (task) {
            SysTask_Destroy(task);
        }
        sub_02068C6C(effect);
    }
}
void sub_02068B80(FieldEffectManager *manager) {
    int count = sub_02068CC4(manager);
    FieldEffect *effect = sub_02068CC8(manager);
    do {
        if (sub_02068CCC(effect) == 1) {
            sub_02068B48((int)effect);
        }
        effect++;
    } while (--count);
}
void sub_02068BAC(FieldEffectManager *manager) {
    int count = sub_02068CC4(manager);
    FieldEffect *effect = sub_02068CC8(manager);
    do {
        if (sub_02068CEC(effect, 3) == 3) {
            sub_02068D34(effect);
        }
        effect++;
    } while (--count);
}
SysTask *sub_02068BDC(FieldEffect *effect, u32 priority) {
    SysTask *task = SysTask_CreateOnMainQueue(sub_02068BFC, effect, priority);
    GF_ASSERT(task != NULL);
    return task;
}
void sub_02068BFC(SysTask *task, void *data) {
    sub_02068D18(data);
}
FieldEffectManager *sub_02068C08(enum HeapID heapID) {
    FieldEffectManager *manager = Heap_Alloc(heapID, sizeof(*manager));
    u8 *bytes;
    u32 count;
    GF_ASSERT(manager != NULL);
    bytes = (u8 *)manager;
    count = sizeof(*manager);
    do {
        *bytes++ = 0;
    } while (--count);
    return manager;
}
void sub_02068C2C(FieldEffectManager *manager) {
    Heap_FreeExplicit(manager->heapID, manager);
}
FieldEffect *sub_02068C38(enum HeapID heapID, int count) {
    FieldEffect *effects;
    count *= sizeof(FieldEffect);
    effects = Heap_Alloc(heapID, count);
    GF_ASSERT(effects != NULL);
    memset(effects, 0, count);
    return effects;
}
void sub_02068C5C(FieldEffectManager *manager) {
    Heap_FreeExplicit(manager->heapID, manager->effects);
}
void sub_02068C6C(FieldEffect *effect) {
    memset(effect, 0, sizeof(*effect));
    sub_02068CF4(effect, sub_02068DC8);
    sub_02068D48(effect, sub_02068DD4);
    sub_02068D10(effect, sub_02068DCC);
    sub_02068D2C(effect, sub_02068DD0);
    sub_02068D64(effect, sub_02068DD8);
    sub_02068D6C(effect, sub_02068DDC);
}
int sub_02068CC4(FieldEffectManager *manager) {
    return manager->count;
}
FieldEffect *sub_02068CC8(FieldEffectManager *manager) {
    return manager->effects;
}
BOOL sub_02068CCC(FieldEffect *effect) {
    return (effect->flags & 1) ? TRUE : FALSE;
}
void sub_02068CD8(FieldEffect *effect) {
    effect->flags |= 1;
}
void sub_02068CE4(FieldEffect *effect, u32 flags) {
    effect->flags |= flags;
}
u32 sub_02068CEC(FieldEffect *effect, u32 flags) {
    return effect->flags & flags;
}
void sub_02068CF4(FieldEffect *effect, EffectInit callback) {
    effect->init = callback;
}
BOOL sub_02068CFC(FieldEffect *effect) {
    void *state = sub_02068D74(effect);
    return effect->init(effect, state);
}
void sub_02068D10(FieldEffect *effect, EffectCallback callback) {
    effect->update = callback;
}
void sub_02068D18(FieldEffect *effect) {
    void *state = sub_02068D74(effect);
    effect->update(effect, state);
}
void sub_02068D2C(FieldEffect *effect, EffectCallback callback) {
    effect->draw = callback;
}
void sub_02068D34(FieldEffect *effect) {
    void *state = sub_02068D74(effect);
    effect->draw(effect, state);
}
void sub_02068D48(FieldEffect *effect, EffectCallback callback) {
    effect->destroy = callback;
}
void sub_02068D50(FieldEffect *effect) {
    void *state = sub_02068D74(effect);
    effect->destroy(effect, state);
}
void sub_02068D64(FieldEffect *effect, EffectCallback callback) {
    effect->extra1 = callback;
}
void sub_02068D6C(FieldEffect *effect, EffectCallback callback) {
    effect->extra2 = callback;
}
void *sub_02068D74(FieldEffect *effect) {
    return effect->state;
}
void sub_02068D78(FieldEffect *effect, u32 size) {
    memset(sub_02068D74(effect), 0, size);
}
void sub_02068D8C(FieldEffect *effect, int parameter) {
    effect->parameter = parameter;
}
int sub_02068D90(FieldEffect *effect) {
    return effect->parameter;
}
void sub_02068D94(FieldEffect *effect, void *userData) {
    effect->userData = userData;
}
UnkOv01_021FFFCC *sub_02068D98(void *data) {
    return ((FieldEffect *)data)->userData;
}
void sub_02068D9C(FieldEffect *effect, SysTask *task) {
    effect->task = task;
}
SysTask *sub_02068DA0(FieldEffect *effect) {
    return effect->task;
}
void sub_02068DA4(FieldEffect *effect, FieldEffectManager *manager) {
    effect->manager = manager;
}
void sub_02068DA8(FieldEffect *effect, const VecFx32 *position) {
    effect->position = *position;
}
void sub_02068DB8(void *data, VecFx32 *position) {
    *position = ((FieldEffect *)data)->position;
}
BOOL sub_02068DC8(FieldEffect *effect, void *state) {
    return TRUE;
}
void sub_02068DCC(FieldEffect *effect, void *state) {
}
void sub_02068DD0(FieldEffect *effect, void *state) {
}
void sub_02068DD4(FieldEffect *effect, void *state) {
}
void sub_02068DD8(FieldEffect *effect, void *state) {
}
void sub_02068DDC(FieldEffect *effect, void *state) {
}
