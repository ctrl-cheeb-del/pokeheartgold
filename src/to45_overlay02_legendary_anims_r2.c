#include "global.h"

void Heap_Free(void *ptr);
void *Heap_Alloc(int heapId, u32 size);
void MI_CpuFill8(void *dst, u8 value, u32 size);
void Field3dObject_SetActiveFlag(void *object, int active);
void Field3dObject_RemoveAnimation(void *object, void *animation);
void Field3dModelAnimation_Unload(void *animation, void *allocator);
void Field3dModel_Unload(void *model);
void Field3dModelAnimation_LoadFromFilesystem(void *animation, void *model, int narcId, u16 fileId, int heapId, void *allocator);
void Field3dObject_AddAnimation(void *object, void *animation);
int Field3dModelAnimation_FrameAdvanceAndCheck(void *animation, s32 step);
void Field3dModelAnimation_FrameAdvanceAndLoop(void *animation, s32 step);
void Field3dObject_Draw(void *object);

void ov02_02245E68(void *data);
void ov02_02245ED8(void *data, int narcId, const u16 *fileIds, u8 count);
int ov02_02245FD0(void *data);
void ov02_02246048(void *data);

void ov02_02245E68(void *data) {
    u8 *p = data;
    int i;
    int offset;

    Field3dObject_SetActiveFlag(p + 0x10, 0);
    i = 0;
    if (i < p[0x9C]) {
        offset = i;
        do {
            Field3dObject_RemoveAnimation(p + 0x10, *(void **)(p + 0x88) + offset);
            Field3dModelAnimation_Unload(*(void **)(p + 0x88) + offset, p + 0x8C);
            i++;
            offset += 0x14;
        } while (i < p[0x9C]);
    }
    p[0x9C] = 0;
    Field3dModel_Unload(p);
    Heap_Free(*(void **)(p + 0x88));
    Heap_Free(p);
}

void ov02_02245ED8(void *data, int narcId, const u16 *fileIds, u8 count) {
    u8 newCount = count;
    u8 *p = data;
    const u16 *ids = fileIds;
    int narc = narcId;
    int i;
    int offset;

    if (p[0x9C] != 0) {
        i = 0;
        if (i < p[0x9C]) {
            offset = i;
            do {
                Field3dObject_RemoveAnimation(p + 0x10, *(void **)(p + 0x88) + offset);
                Field3dModelAnimation_Unload(*(void **)(p + 0x88) + offset, p + 0x8C);
                i++;
                offset += 0x14;
            } while (i < p[0x9C]);
        }
        Heap_Free(*(void **)(p + 0x88));
    }
    p[0x9C] = newCount;
    *(void **)(p + 0x88) = Heap_Alloc(*(u32 *)(p + 0xA0), p[0x9C] * 0x14);
    MI_CpuFill8(*(void **)(p + 0x88), 0, p[0x9C] * 0x14);
    i = 0;
    if (i < p[0x9C]) {
        offset = i;
        do {
            Field3dModelAnimation_LoadFromFilesystem(*(void **)(p + 0x88) + offset, p, narc, *ids, *(u32 *)(p + 0xA0), p + 0x8C);
            Field3dObject_AddAnimation(p + 0x10, *(void **)(p + 0x88) + offset);
            i++;
            ids++;
            offset += 0x14;
        } while (i < p[0x9C]);
    }
}

int ov02_02245FD0(void *data) {
    u8 *p = data;
    int completed = 0;
    int i;
    int offset;
    s32 step;
    float value;

    i = 0;
    if (i < p[0x9C]) {
        offset = completed;
        do {
            if (*(u16 *)(p + 0x9E) != 0) {
                value = (float)(*(u16 *)(p + 0x9E) << 12) + 0.5f;
            } else {
                value = (float)(*(u16 *)(p + 0x9E) << 12) - 0.5f;
            }
            step = (s32)value;
            completed += Field3dModelAnimation_FrameAdvanceAndCheck(*(void **)(p + 0x88) + offset, step);
            i++;
            offset += 0x14;
        } while (i < p[0x9C]);
    }
    Field3dObject_Draw(p + 0x10);
    return completed == p[0x9C];
}

void ov02_02246048(void *data) {
    u8 *p = data;
    int i;
    int offset;
    s32 step;
    float value;

    i = 0;
    if (i < p[0x9C]) {
        offset = i;
        do {
            if (*(u16 *)(p + 0x9E) != 0) {
                value = (float)(*(u16 *)(p + 0x9E) << 12) + 0.5f;
            } else {
                value = (float)(*(u16 *)(p + 0x9E) << 12) - 0.5f;
            }
            step = (s32)value;
            Field3dModelAnimation_FrameAdvanceAndLoop(*(void **)(p + 0x88) + offset, step);
            i++;
            offset += 0x14;
        } while (i < p[0x9C]);
    }
    Field3dObject_Draw(p + 0x10);
}
