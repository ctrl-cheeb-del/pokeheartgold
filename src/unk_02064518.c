#include "global.h"

#include "unk_02064518_internal.h"

extern u32 MapObject_GetTrainerNum(MapObject *);
extern BOOL MapObjectManager_GetNextObjectWithFlagFromIndex(MapObjectManager *, MapObject **, u32 *, int);
extern int sub_02064298(MapObject *);
extern void GF_AssertFail(void);
extern void *Heap_AllocAtEnd(int, u32);
extern SysTask *SysTask_CreateOnMainQueue(void (*)(SysTask *, TrainerTaskData *), TrainerTaskData *, int);
extern void *SysTask_GetData(SysTask *);
extern void Heap_FreeExplicit(int, void *);
extern void SysTask_Destroy(SysTask *);
extern const TrainerTaskStateFunc _020FE1A4[];

u32 sub_02064518(MapObject *object);
MapObject *sub_02064520(void *unused, MapObjectManager *manager, MapObject *exclude, u32 trainerNum);
SysTask *sub_0206457C(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7);
void *sub_02064598(SysTask *task);
void sub_020645AC(SysTask *task);
SysTask *sub_020645B4(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7);
void *sub_0206460C(SysTask *task);
void sub_02064618(SysTask *task);
void sub_02064630(SysTask *task, TrainerTaskData *data);

u32 sub_02064518(MapObject *object) {
    return MapObject_GetTrainerNum(object);
}

MapObject *sub_02064520(void *unused, MapObjectManager *manager, MapObject *exclude, u32 trainerNum) {
    u32 index = 0;
    MapObject *object;
    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, 1)) {
        do {
            if (object != exclude && (u32)(sub_02064298(object) - 1) <= 1 && MapObject_GetTrainerNum(object) == trainerNum) {
                return object;
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, 1));
    }
    GF_AssertFail();
    return NULL;
}

SysTask *sub_0206457C(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7) {
    return sub_020645B4(a0, a1, a2, a3, a4, a5, a6, a7);
}

void *sub_02064598(SysTask *task) {
    if (task == NULL) {
        GF_AssertFail();
    }
    return sub_0206460C(task);
}

void sub_020645AC(SysTask *task) {
    sub_02064618(task);
}

SysTask *sub_020645B4(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7) {
    u8 *data = Heap_AllocAtEnd(4, 0x30);
    SysTask *task;
    if (data == NULL) {
        GF_AssertFail();
    }
    memset(data, 0, 0x30);
    *(void **)(data + 8) = a3;
    *(void **)(data + 0xC) = a4;
    *(void **)(data + 0x10) = a5;
    *(void **)(data + 0x14) = a6;
    *(void **)(data + 0x18) = a7;
    *(void **)(data + 0x2C) = a0;
    *(void **)(data + 0x24) = a1;
    *(void **)(data + 0x28) = a2;
    task = SysTask_CreateOnMainQueue(sub_02064630, (TrainerTaskData *)data, 0xFF);
    if (task == NULL) {
        GF_AssertFail();
    }
    return task;
}

void *sub_0206460C(SysTask *task) {
    return *(void **)((u8 *)SysTask_GetData(task) + 4);
}

void sub_02064618(SysTask *task) {
    void *data = SysTask_GetData(task);
    Heap_FreeExplicit(4, data);
    SysTask_Destroy(task);
}

void sub_02064630(SysTask *task, TrainerTaskData *data) {
    while (_020FE1A4[*(u32 *)data](data) == TRUE) {}
}
