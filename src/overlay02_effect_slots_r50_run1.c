#include "constants/sndseq.h"

#include "overlay02_effect_slots_r50_private.h"

void ov02_0224DE10(Ov02EffectSlot *slot, const VecFx32 *position, fx32 dx, fx32 dz) {
    int i;

    if (slot->active != FALSE) {
        GF_AssertFail();
    }
    Field3dObject_SetPosEx(&slot->object, position->x, position->y + dx, position->z + dz);
    slot->active = TRUE;
    for (i = 0; i < 4; i++) {
        Field3dModelAnimation_FrameSet(&slot->animations[i], 0);
    }
    Field3dObject_SetActiveFlag(&slot->object, TRUE);
    PlaySE(SEQ_SE_DP_UG_023);
}

void ov02_0224DE6C(Ov02EffectSlot *slot) {
    int i;
    BOOL done;

    if (slot->active != FALSE) {
        done = TRUE;
        for (i = 0; i < 4; i++) {
            done &= Field3dModelAnimation_FrameAdvanceAndCheck(&slot->animations[i], FX32_ONE);
        }
        if (done == TRUE) {
            slot->active = FALSE;
            Field3dObject_SetActiveFlag(&slot->object, FALSE);
        }
    }
}

void ov02_0224DEA8(Ov02EffectSlot *slot, Field3dModel *model, NNSFndAllocator *allocator, void **animationData) {
    int i;

    memset(slot, 0, sizeof(*slot));
    Field3dObject_InitFromModel(&slot->object, model);
    for (i = 0; i < 4; i++) {
        ov01_021FBE70(&slot->animations[i], model, animationData[i], allocator);
        Field3dObject_AddAnimation(&slot->object, &slot->animations[i]);
    }
    Field3dObject_SetActiveFlag(&slot->object, FALSE);
}

void ov02_0224DEF4(Ov02EffectSlot *slot, NNSFndAllocator *allocator) {
    int i;

    for (i = 0; i < 4; i++) {
        Field3dModelAnimation_Unload(&slot->animations[i], allocator);
    }
    memset(slot, 0, sizeof(*slot));
}
