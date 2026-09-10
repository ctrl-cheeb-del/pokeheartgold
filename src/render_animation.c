#include <string.h>

#include "global.h"

#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "unk_0206979C.h"
typedef struct RenderAnimation {
    u32 flags;
    fx32 frame;
    void *file;
    void *resource;
    NNSG3dAnmObj *object;
    NNSFndAllocator allocator;
} RenderAnimation;
typedef struct RenderModel {
    u32 flags;
    void *file;
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
} RenderModel;
extern const VecFx32 _020FE8A4;
extern const MtxFx33 _020FE8B0;
void sub_02020DA4(MtxFx33 *, u16, u16, u16);
void sub_0206979C(RenderAnimation *animation);
void sub_020697A8(RenderAnimation *animation, void *file, int unused);
void sub_020697BC(RenderAnimation *animation, void *file, int unused);
void sub_020697D0(RenderAnimation *animation, RenderAnimation *source, int unused);
void sub_020697DC(RenderAnimation *animation, int unused, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd);
void sub_02069800(RenderAnimation *animation, void *file, int unused);
void sub_02069818(RenderAnimation *animation);
void sub_0206983C(RenderAnimation *animation, NNSG3dResMdl *model, enum HeapID heapID);
void sub_02069864(RenderAnimation *animation, RenderModel *model, enum HeapID heapID);
void sub_02069870(RenderAnimation *animation, NNSG3dResMdl *model, NNSG3dResTex *texture);
void sub_02069884(RenderAnimation *animation, RenderModel *model);
void sub_02069894(RenderAnimation *animation, RenderModel *model, RenderAnimation *source, int unused, enum HeapID heapID);
void sub_020698B8(RenderAnimation *animation);
void sub_020698D0(RenderAnimation *animation);
BOOL sub_020698E8(RenderAnimation *animation, fx32 step, BOOL loop);
BOOL sub_02069948(RenderAnimation *animation);
void sub_02069958(NNSG3dRenderObj *object);
void sub_02069964(NNSG3dRenderObj *object, NNSG3dResMdl *model);
void sub_02069978(NNSG3dRenderObj *object, UnkOv01_021FFECC_sub *model);
void sub_02069984(NNSG3dRenderObj *object, NNSG3dAnmObj *animation);
void sub_0206998C(NNSG3dRenderObj *object, RenderAnimation *animation);
void sub_02069998(NNSG3dRenderObj *object, UnkOv01_021FFECC_sub *model, RenderAnimation *animation);
void sub_020699AC(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const MtxFx33 *rotation);
void sub_020699BC(int object, VecFx32 *position);
void sub_020699D0(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const u16 *angles);
void sub_0206979C(RenderAnimation *animation) {
    memset(animation, 0, sizeof(*animation));
}
void sub_020697A8(RenderAnimation *animation, void *file, int unused) {
    sub_02069800(animation, file, unused);
    animation->flags |= 1;
}
void sub_020697BC(RenderAnimation *animation, void *file, int unused) {
    sub_02069800(animation, file, unused);
    animation->flags &= ~1;
}
void sub_020697D0(RenderAnimation *animation, RenderAnimation *source, int unused) {
    sub_020697BC(animation, source->file, unused);
}
void sub_020697DC(RenderAnimation *animation, int unused, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd) {
    void *file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, atEnd);
    sub_020697A8(animation, file, unused);
}
void sub_02069800(RenderAnimation *animation, void *file, int unused) {
    sub_0206979C(animation);
    animation->file = file;
    animation->resource = NNS_G3dGetAnmByIdx(file, 0);
}
void sub_02069818(RenderAnimation *animation) {
    if (animation->flags & 1) {
        Heap_Free(animation->file);
        animation->flags &= ~1;
    }
    animation->file = NULL;
    animation->resource = NULL;
}
void sub_0206983C(RenderAnimation *animation, NNSG3dResMdl *model, enum HeapID heapID) {
    HeapExp_FndInitAllocator(&animation->allocator, heapID, 4);
    animation->object = NNS_G3dAllocAnmObj(&animation->allocator, animation->resource, model);
    GF_ASSERT(animation->object != NULL);
}
void sub_02069864(RenderAnimation *animation, RenderModel *model, enum HeapID heapID) {
    sub_0206983C(animation, model->model, heapID);
}
void sub_02069870(RenderAnimation *animation, NNSG3dResMdl *model, NNSG3dResTex *texture) {
    NNS_G3dAnmObjInit(animation->object, animation->resource, model, texture);
}
void sub_02069884(RenderAnimation *animation, RenderModel *model) {
    sub_02069870(animation, model->model, model->texture);
}
void sub_02069894(RenderAnimation *animation, RenderModel *model, RenderAnimation *source, int unused, enum HeapID heapID) {
    sub_020697D0(animation, source, unused);
    sub_02069864(animation, model, heapID);
    sub_02069884(animation, model);
}
void sub_020698B8(RenderAnimation *animation) {
    if (animation->object) {
        NNS_G3dFreeAnmObj(&animation->allocator, animation->object);
        animation->object = NULL;
    }
}
void sub_020698D0(RenderAnimation *animation) {
    sub_020698B8(animation);
    sub_02069818(animation);
    sub_0206979C(animation);
}
BOOL sub_020698E8(RenderAnimation *animation, fx32 step, BOOL loop) {
    fx32 next = animation->frame;
    BOOL done = FALSE;
    fx32 frames = *(u16 *)((u8 *)animation->object->resAnm + 4) << 12;
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
        animation->flags |= 2;
    } else {
        animation->flags &= ~2;
    }
    return done;
}
BOOL sub_02069948(RenderAnimation *animation) {
    if (animation->flags & 2) {
        return TRUE;
    }
    return FALSE;
}
void sub_02069958(NNSG3dRenderObj *object) {
    memset(object, 0, sizeof(*object));
}
void sub_02069964(NNSG3dRenderObj *object, NNSG3dResMdl *model) {
    sub_02069958(object);
    NNS_G3dRenderObjInit(object, model);
}
void sub_02069978(NNSG3dRenderObj *object, UnkOv01_021FFECC_sub *model) {
    sub_02069964(object, model->unkC);
}
void sub_02069984(NNSG3dRenderObj *object, NNSG3dAnmObj *animation) {
    NNS_G3dRenderObjAddAnmObj(object, animation);
}
void sub_0206998C(NNSG3dRenderObj *object, RenderAnimation *animation) {
    sub_02069984(object, animation->object);
}
void sub_02069998(NNSG3dRenderObj *object, UnkOv01_021FFECC_sub *model, RenderAnimation *animation) {
    sub_02069978(object, model);
    sub_0206998C(object, animation);
}
void sub_020699AC(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const MtxFx33 *rotation) {
    GF3dRender_DrawModel(object, position, rotation, scale);
}
void sub_020699BC(int object, VecFx32 *position) {
    sub_020699AC((NNSG3dRenderObj *)object, position, &_020FE8A4, &_020FE8B0);
}
void sub_020699D0(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const u16 *angles) {
    MtxFx33 rotation;
    sub_02020DA4(&rotation, angles[0], angles[1], angles[2]);
    sub_020699AC(object, position, scale, &rotation);
}
