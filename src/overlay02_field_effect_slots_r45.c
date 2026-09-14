#include "constants/sndseq.h"

#include "overlay02_field_effect_slots_r45_private.h"

void ov02_0224D698(Ov02EffectSlotR45 *slot, void *avatar, fx32 dx, fx32 dz) {
    VecFx32 position;
    int i;

    if (slot->active != FALSE) {
        GF_AssertFail();
    }
    PlayerAvatar_CopyPositionVector(avatar, &position);
    Field3dObject_SetPosEx(&slot->object, position.x, position.y + dx, position.z + dz);
    slot->active = TRUE;
    for (i = 0; i < 4; i++) {
        Field3dModelAnimation_FrameSet(&slot->animations[i], 0);
    }
    Field3dObject_SetActiveFlag(&slot->object, TRUE);
    PlaySE(SEQ_SE_DP_UG_023);
}

void ov02_0224D700(Ov02EffectSlotR45 *slot) {
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

void ov02_0224D73C(Ov02EffectSlotR45 *slot, Field3dModel *model, NNSFndAllocator *allocator, void **animationData) {
    int i;

    memset(slot, 0, sizeof(*slot));
    Field3dObject_InitFromModel(&slot->object, model);
    for (i = 0; i < 4; i++) {
        ov01_021FBE70(&slot->animations[i], model, animationData[i], allocator);
        Field3dObject_AddAnimation(&slot->object, &slot->animations[i]);
    }
    Field3dObject_SetActiveFlag(&slot->object, FALSE);
}

void ov02_0224D788(Ov02EffectSlotR45 *slot, NNSFndAllocator *allocator) {
    int i;

    for (i = 0; i < 4; i++) {
        Field3dModelAnimation_Unload(&slot->animations[i], allocator);
    }
    memset(slot, 0, sizeof(*slot));
}

void ov02_0224D7B0(Ov02EffectManagerR45 *manager) {
    VecFx32 position;

    PlayerAvatar_CopyPositionVector(PTR(manager->fieldSystem, 0x40), &position);
    if (position.x - manager->lastPosition.x == 0 && position.y < manager->lastPosition.y && position.z > manager->lastPosition.z) {
        manager->dx = 0;
        manager->dz = 0x20000;
    } else {
        manager->dx = 0x20000;
        manager->dz = 0x10000;
    }
    manager->lastPosition = position;
}

void ov02_0224D820(Ov02EffectManagerR45 *manager) {
    int i;

    ov02_0224D7B0(manager);
    for (i = 0; i < 16; i++) {
        if (manager->slots[i].active == FALSE) {
            ov02_0224D698(&manager->slots[i], PTR(manager->fieldSystem, 0x40), manager->dx, manager->dz);
            return;
        }
    }
    GF_AssertFail();
}
