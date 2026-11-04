#include "render_animation.h"

#include <string.h>

#include "global.h"

#include "geometry_math.h"
#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "render_model.h"

static void RenderAnimation_Clear(RenderAnimation *animation);
static void RenderAnimation_InitOwned(RenderAnimation *animation, void *file, int unused);
static void RenderAnimation_InitShared(RenderAnimation *animation, void *file, int unused);
static void RenderAnimation_InitFromAnimation(RenderAnimation *animation, RenderAnimation *source, int unused);
static void RenderAnimation_SetFile(RenderAnimation *animation, void *file, int unused);
static void RenderAnimation_AllocObject(RenderAnimation *animation, NNSG3dResMdl *model, enum HeapID heapID);
static void RenderAnimation_InitObject(RenderAnimation *animation, NNSG3dResMdl *model, NNSG3dResTex *texture);
static void RenderAnimation_FreeObject(RenderAnimation *animation);
static void RenderObj_Clear(NNSG3dRenderObj *object);
static void RenderObj_Init(NNSG3dRenderObj *object, NNSG3dResMdl *model);
static void RenderObj_AddAnimObj(NNSG3dRenderObj *object, NNSG3dAnmObj *animation);
static void RenderObj_AddAnimation(NNSG3dRenderObj *object, RenderAnimation *animation);

static const VecFx32 sRenderObjUnitScale = {
    .x = FX32_ONE,
    .y = FX32_ONE,
    .z = FX32_ONE,
};

static const MtxFx33 sRenderObjIdentityRotation = {
    ._00 = FX32_ONE,
    ._01 = 0,
    ._02 = 0,
    ._10 = 0,
    ._11 = FX32_ONE,
    ._12 = 0,
    ._20 = 0,
    ._21 = 0,
    ._22 = FX32_ONE,
};

static void RenderAnimation_Clear(RenderAnimation *animation) {
    memset(animation, 0, sizeof(*animation));
}

static void RenderAnimation_InitOwned(RenderAnimation *animation, void *file, int unused) {
    RenderAnimation_SetFile(animation, file, unused);
    animation->flags |= RENDER_ANIMATION_OWNS_FILE;
}

static void RenderAnimation_InitShared(RenderAnimation *animation, void *file, int unused) {
    RenderAnimation_SetFile(animation, file, unused);
    animation->flags &= ~RENDER_ANIMATION_OWNS_FILE;
}

static void RenderAnimation_InitFromAnimation(RenderAnimation *animation, RenderAnimation *source, int unused) {
    RenderAnimation_InitShared(animation, source->file, unused);
}

void RenderAnimation_LoadFromNarc(RenderAnimation *animation, int unused, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd) {
    void *file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, atEnd);
    RenderAnimation_InitOwned(animation, file, unused);
}

static void RenderAnimation_SetFile(RenderAnimation *animation, void *file, int unused) {
    RenderAnimation_Clear(animation);
    animation->file = file;
    animation->resource = NNS_G3dGetAnmByIdx(file, 0);
}

void RenderAnimation_FreeFile(RenderAnimation *animation) {
    if (animation->flags & RENDER_ANIMATION_OWNS_FILE) {
        Heap_Free(animation->file);
        animation->flags &= ~RENDER_ANIMATION_OWNS_FILE;
    }
    animation->file = NULL;
    animation->resource = NULL;
}

static void RenderAnimation_AllocObject(RenderAnimation *animation, NNSG3dResMdl *model, enum HeapID heapID) {
    HeapExp_FndInitAllocator(&animation->allocator, heapID, 4);
    animation->object = NNS_G3dAllocAnmObj(&animation->allocator, animation->resource, model);
    GF_ASSERT(animation->object != NULL);
}

void RenderAnimation_AllocObjectForModel(RenderAnimation *animation, RenderModel *model, enum HeapID heapID) {
    RenderAnimation_AllocObject(animation, model->model, heapID);
}

static void RenderAnimation_InitObject(RenderAnimation *animation, NNSG3dResMdl *model, NNSG3dResTex *texture) {
    NNS_G3dAnmObjInit(animation->object, animation->resource, model, texture);
}

void RenderAnimation_InitObjectForModel(RenderAnimation *animation, RenderModel *model) {
    RenderAnimation_InitObject(animation, model->model, model->texture);
}

void RenderAnimation_InitForModel(RenderAnimation *animation, RenderModel *model, RenderAnimation *source, int unused, enum HeapID heapID) {
    RenderAnimation_InitFromAnimation(animation, source, unused);
    RenderAnimation_AllocObjectForModel(animation, model, heapID);
    RenderAnimation_InitObjectForModel(animation, model);
}

static void RenderAnimation_FreeObject(RenderAnimation *animation) {
    if (animation->object) {
        NNS_G3dFreeAnmObj(&animation->allocator, animation->object);
        animation->object = NULL;
    }
}

void RenderAnimation_Free(RenderAnimation *animation) {
    RenderAnimation_FreeObject(animation);
    RenderAnimation_FreeFile(animation);
    RenderAnimation_Clear(animation);
}

BOOL RenderAnimation_Advance(RenderAnimation *animation, fx32 step, BOOL loop) {
    fx32 next = animation->frame;
    BOOL done = FALSE;
    fx32 frames = NNS_G3dAnmObjGetNumFrame(animation->object);
    animation->frame = next + step;
    if (step > 0) {
        if (animation->frame >= frames) {
            done = TRUE;
            if (loop == TRUE) {
                animation->frame -= frames;
            } else {
                animation->frame = frames;
            }
        }
    } else {
        if (animation->frame <= 0) {
            done = TRUE;
            if (loop == TRUE) {
                animation->frame += frames;
            } else {
                animation->frame = 0;
            }
        }
    }
    animation->object->frame = animation->frame;
    if (done == TRUE) {
        animation->flags |= RENDER_ANIMATION_DONE;
    } else {
        animation->flags &= ~RENDER_ANIMATION_DONE;
    }
    return done;
}

BOOL RenderAnimation_IsDone(RenderAnimation *animation) {
    if (animation->flags & RENDER_ANIMATION_DONE) {
        return TRUE;
    }
    return FALSE;
}

static void RenderObj_Clear(NNSG3dRenderObj *object) {
    memset(object, 0, sizeof(*object));
}

static void RenderObj_Init(NNSG3dRenderObj *object, NNSG3dResMdl *model) {
    RenderObj_Clear(object);
    NNS_G3dRenderObjInit(object, model);
}

void RenderObj_InitFromModel(NNSG3dRenderObj *object, RenderModel *model) {
    RenderObj_Init(object, model->model);
}

static void RenderObj_AddAnimObj(NNSG3dRenderObj *object, NNSG3dAnmObj *animation) {
    NNS_G3dRenderObjAddAnmObj(object, animation);
}

static void RenderObj_AddAnimation(NNSG3dRenderObj *object, RenderAnimation *animation) {
    RenderObj_AddAnimObj(object, animation->object);
}

void RenderObj_InitWithAnimation(NNSG3dRenderObj *object, RenderModel *model, RenderAnimation *animation) {
    RenderObj_InitFromModel(object, model);
    RenderObj_AddAnimation(object, animation);
}

void RenderObj_Draw(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const MtxFx33 *rotation) {
    GF3dRender_DrawModel(object, position, rotation, scale);
}

void RenderObj_DrawAt(NNSG3dRenderObj *object, VecFx32 *position) {
    RenderObj_Draw(object, position, &sRenderObjUnitScale, &sRenderObjIdentityRotation);
}

void RenderObj_DrawRotated(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const u16 *angles) {
    MtxFx33 rotation;
    Math_CalcRotationMatrixXYZDeg(&rotation, angles[0], angles[1], angles[2]);
    RenderObj_Draw(object, position, scale, &rotation);
}
