#ifndef POKEHEARTGOLD_RENDER_ANIMATION_H
#define POKEHEARTGOLD_RENDER_ANIMATION_H

#include "field/field_effect_manager.h"
#include "player_data.h"

enum RenderAnimationFlags {
    RENDER_ANIMATION_OWNS_FILE = 1 << 0, // the file is freed with the animation
    RENDER_ANIMATION_DONE = 1 << 1,      // the last advance reached the end
};

// Embedded by value: one copy loaded per renderer (FieldEffectManager_LoadRenderAnimation), one per
// running effect bound to the renderer's model (FieldEffectManager_InitRenderAnimation).
typedef struct RenderAnimation {
    u32 flags; // enum RenderAnimationFlags
    fx32 frame;
    void *file;
    void *resource;
    NNSG3dAnmObj *object;
    NNSFndAllocator allocator;
} RenderAnimation;

void RenderAnimation_LoadFromNarc(RenderAnimation *animation, int unused, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd);
void RenderAnimation_FreeFile(RenderAnimation *animation);
void RenderAnimation_AllocObjectForModel(RenderAnimation *animation, struct RenderModel *model, enum HeapID heapID);
void RenderAnimation_InitObjectForModel(RenderAnimation *animation, struct RenderModel *model);
void RenderAnimation_InitForModel(RenderAnimation *animation, struct RenderModel *model, RenderAnimation *source, int unused, enum HeapID heapID);
void RenderAnimation_Free(RenderAnimation *animation);
BOOL RenderAnimation_Advance(RenderAnimation *animation, fx32 step, BOOL loop);
BOOL RenderAnimation_IsDone(RenderAnimation *animation);
void RenderObj_InitFromModel(NNSG3dRenderObj *object, struct RenderModel *model);
void RenderObj_InitWithAnimation(NNSG3dRenderObj *object, struct RenderModel *model, RenderAnimation *animation);
void RenderObj_Draw(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const MtxFx33 *rotation);
void RenderObj_DrawAt(NNSG3dRenderObj *object, VecFx32 *position);
void RenderObj_DrawRotated(NNSG3dRenderObj *object, const VecFx32 *position, const VecFx32 *scale, const u16 *angles);

#endif // POKEHEARTGOLD_RENDER_ANIMATION_H
