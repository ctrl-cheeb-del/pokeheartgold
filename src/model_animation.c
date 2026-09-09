#include <string.h>

#include "global.h"

#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "sys_task_api.h"
typedef struct ModelResource {
    NNSG3dResFileHeader *file;
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
} ModelResource;
typedef struct ModelAnimation {
    void *file;
    void *resource;
    NNSG3dAnmObj *object;
    fx32 frame;
    BOOL borrowed;
} ModelAnimation;
typedef struct ModelInstance {
    NNSG3dRenderObj render;
    VecFx32 position;
    VecFx32 scale;
    BOOL visible;
    u16 rotation[3];
} ModelInstance;
void sub_02018030(ModelResource *model, NARC *narc, int fileId, enum HeapID heapID);
void sub_0201804C(SysTask *task, void *data);
void sub_02018068(ModelResource *model);
void sub_020180BC(ModelAnimation *animation, ModelResource *model, NARC *narc, int fileId, enum HeapID heapID, NNSFndAllocator *allocator);
void sub_020180E8(ModelAnimation *animation, ModelResource *model, void *file, NNSFndAllocator *allocator);
void sub_020180F8(ModelAnimation *animation, NNSFndAllocator *allocator);
void sub_02018124(ModelAnimation *animation, fx32 step);
BOOL sub_0201815C(ModelAnimation *animation, fx32 step);
void sub_02018198(ModelAnimation *animation, fx32 frame);
fx32 sub_020181A0(ModelAnimation *animation);
fx32 sub_020181A4(ModelAnimation *animation);
void sub_020181B0(ModelInstance *instance, ModelResource *model);
void sub_020181D4(ModelInstance *instance, ModelAnimation *animation);
void sub_020181E0(ModelInstance *instance, ModelAnimation *animation);
void sub_020181EC(ModelInstance *instance);
void sub_02018288(ModelInstance *instance, const MtxFx33 *rotation);
void sub_020182A0(ModelInstance *instance, BOOL visible);
BOOL sub_020182A4(ModelInstance *instance);
void sub_020182A8(ModelInstance *instance, fx32 x, fx32 y, fx32 z);
void sub_020182B0(ModelInstance *instance, fx32 *x, fx32 *y, fx32 *z);
void sub_020182C4(ModelInstance *instance, fx32 x, fx32 y, fx32 z);
void sub_020182CC(ModelInstance *instance, fx32 *x, fx32 *y, fx32 *z);
void sub_020182E0(ModelInstance *instance, u16 rotation, int axis);
u16 sub_020182EC(ModelInstance *instance, int axis);
void sub_020182F8(ModelAnimation *animation, ModelResource *model, void *file, NNSFndAllocator *allocator);
void sub_02018324(ModelResource *model);
void sub_02018030(ModelResource *model, NARC *narc, int fileId, enum HeapID heapID) {
    model->file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, FALSE);
    sub_02018324(model);
}
void sub_0201804C(SysTask *task, void *data) {
    ModelResource *model = data;
    GF3dRender_AllocAndLoadTexResources(model->texture);
    GF3dRender_BindModelSet(model->file, model->texture);
    SysTask_Destroy(task);
}
void sub_02018068(ModelResource *model) {
    u8 *bytes;
    u32 count;
    if (model->texture) {
        NNSG3dTexKey key, key4x4;
        NNS_G3dTexReleaseTexKey(model->texture, &key, &key4x4);
        NNS_GfdFreeTexVram(key);
        NNS_GfdFreeTexVram(key4x4);
        NNS_GfdFreePlttVram(NNS_G3dPlttReleasePlttKey(model->texture));
    }
    if (model->file) {
        Heap_Free(model->file);
    }
    bytes = (u8 *)model;
    count = sizeof(*model);
    do {
        *bytes++ = 0;
    } while (--count);
}
void sub_020180BC(ModelAnimation *animation, ModelResource *model, NARC *narc, int fileId, enum HeapID heapID, NNSFndAllocator *allocator) {
    void *file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, FALSE);
    sub_020182F8(animation, model, file, allocator);
    animation->borrowed = FALSE;
}
void sub_020180E8(ModelAnimation *animation, ModelResource *model, void *file, NNSFndAllocator *allocator) {
    sub_020182F8(animation, model, file, allocator);
    animation->borrowed = TRUE;
}
void sub_020180F8(ModelAnimation *animation, NNSFndAllocator *allocator) {
    u8 *bytes;
    u32 count;
    if (animation->file) {
        NNS_G3dFreeAnmObj(allocator, animation->object);
        if (!animation->borrowed) {
            Heap_Free(animation->file);
        }
    }
    bytes = (u8 *)animation;
    count = sizeof(*animation);
    do {
        *bytes++ = 0;
    } while (--count);
}
void sub_02018124(ModelAnimation *animation, fx32 step) {
    fx32 frames = *(u16 *)((u8 *)animation->object->resAnm + 4) << 12;
    if (step > 0) {
        animation->frame = (animation->frame + step) % frames;
    } else {
        animation->frame += step;
        if (animation->frame < 0) {
            animation->frame += frames;
        }
    }
    animation->object->frame = animation->frame;
}
BOOL sub_0201815C(ModelAnimation *animation, fx32 step) {
    fx32 frames = *(u16 *)((u8 *)animation->object->resAnm + 4) << 12;
    BOOL done = FALSE;
    if (step > 0) {
        if (animation->frame + step < frames) {
            animation->frame += step;
        } else {
            animation->frame = frames;
            done = TRUE;
        }
    } else {
        if (animation->frame + step >= 0) {
            animation->frame += step;
        } else {
            animation->frame = 0;
            done = TRUE;
        }
    }
    animation->object->frame = animation->frame;
    return done;
}
void sub_02018198(ModelAnimation *animation, fx32 frame) {
    animation->frame = frame;
    animation->object->frame = frame;
}
fx32 sub_020181A0(ModelAnimation *animation) {
    return animation->frame;
}
fx32 sub_020181A4(ModelAnimation *animation) {
    return *(u16 *)((u8 *)animation->object->resAnm + 4) << 12;
}
void sub_020181B0(ModelInstance *instance, ModelResource *model) {
    memset(instance, 0, sizeof(*instance));
    NNS_G3dRenderObjInit(&instance->render, model->model);
    instance->visible = TRUE;
    instance->scale.x = FX32_ONE;
    instance->scale.y = FX32_ONE;
    instance->scale.z = FX32_ONE;
}
void sub_020181D4(ModelInstance *instance, ModelAnimation *animation) {
    NNS_G3dRenderObjAddAnmObj(&instance->render, animation->object);
}
void sub_020181E0(ModelInstance *instance, ModelAnimation *animation) {
    NNS_G3dRenderObjRemoveAnmObj(&instance->render, animation->object);
}
void sub_020181EC(ModelInstance *instance) {
    MtxFx33 rotation, part;
    if (instance->visible) {
        MTX_Identity33(&rotation);
        MTX_RotX33(&part, FX_SinIdx(instance->rotation[0]), FX_CosIdx(instance->rotation[0]));
        MTX_Concat33(&part, &rotation, &rotation);
        MTX_RotZ33(&part, FX_SinIdx(instance->rotation[2]), FX_CosIdx(instance->rotation[2]));
        MTX_Concat33(&part, &rotation, &rotation);
        MTX_RotY33(&part, FX_SinIdx(instance->rotation[1]), FX_CosIdx(instance->rotation[1]));
        MTX_Concat33(&part, &rotation, &rotation);
        GF3dRender_DrawModel(&instance->render, &instance->position, &rotation, &instance->scale);
    }
}
void sub_02018288(ModelInstance *instance, const MtxFx33 *rotation) {
    if (instance->visible) {
        GF3dRender_DrawModel(&instance->render, &instance->position, rotation, &instance->scale);
    }
}
void sub_020182A0(ModelInstance *instance, BOOL visible) {
    instance->visible = visible;
}
BOOL sub_020182A4(ModelInstance *instance) {
    return instance->visible;
}
void sub_020182A8(ModelInstance *instance, fx32 x, fx32 y, fx32 z) {
    instance->position.x = x;
    instance->position.y = y;
    instance->position.z = z;
}
void sub_020182B0(ModelInstance *instance, fx32 *x, fx32 *y, fx32 *z) {
    *x = instance->position.x;
    *y = instance->position.y;
    *z = instance->position.z;
}
void sub_020182C4(ModelInstance *instance, fx32 x, fx32 y, fx32 z) {
    instance->scale.x = x;
    instance->scale.y = y;
    instance->scale.z = z;
}
void sub_020182CC(ModelInstance *instance, fx32 *x, fx32 *y, fx32 *z) {
    *x = instance->scale.x;
    *y = instance->scale.y;
    *z = instance->scale.z;
}
void sub_020182E0(ModelInstance *instance, u16 rotation, int axis) {
    instance->rotation[axis] = rotation;
}
u16 sub_020182EC(ModelInstance *instance, int axis) {
    return instance->rotation[axis];
}
void sub_020182F8(ModelAnimation *animation, ModelResource *model, void *file, NNSFndAllocator *allocator) {
    animation->file = file;
    animation->resource = NNS_G3dGetAnmByIdx(file, 0);
    animation->object = NNS_G3dAllocAnmObj(allocator, animation->resource, model->model);
    NNS_G3dAnmObjInit(animation->object, animation->resource, model->model, model->texture);
}
void sub_02018324(ModelResource *model) {
    GF_ASSERT(model->file != NULL);
    model->set = NNS_G3dGetMdlSet(model->file);
    model->model = NNS_G3dGetMdlByIdx(model->set, 0);
    model->texture = NNS_G3dGetTex(model->file);
    if (model->texture) {
        SysTask_CreateOnVWaitQueue(sub_0201804C, model, 1024);
    }
}
