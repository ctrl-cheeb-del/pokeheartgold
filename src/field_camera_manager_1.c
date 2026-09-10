#include "field_camera_manager_internal.h"

void FieldCamera_Create(void *target, void *fieldCamera, u32 presetNo, BOOL history) {
    u8 *owner = fieldCamera;
    const FieldCameraPresetPrivate *preset = &ov01_02206478[presetNo];
    if (presetNo >= 17) {
        GF_AssertFail();
    }
    *(void **)(owner + 0x24) = Camera_New(4);
    Camera_Init_FromTargetDistanceAndAngle(target, preset->distance, preset->angle, preset->unkE, (u8)preset->unkC, TRUE, *(void **)(owner + 0x24));
    Camera_SetStaticPtr(*(void **)(owner + 0x24));
    Camera_SetPerspectiveClippingPlane(preset->clipNear, preset->clipFar, *(void **)(owner + 0x24));
    Camera_OffsetLookAtPosAndTarget(&preset->offset, *(void **)(owner + 0x24));
    if (history) {
        Camera_History_New(7, 6, 2, 4, *(void **)(owner + 0x24));
    }
    *(void **)(owner + 0x28) = ov01_021EAC4C(4);
    ov01_021EAC6C(owner, presetNo);
}

void FieldCamera_Delete(void *p) {
    u8 *q = p;
    ov01_021EAC64(*(void **)(q + 0x28));
    Camera_UnsetStaticPtr();
    Camera_History_Delete(*(void **)(q + 0x24));
    Camera_Delete(*(void **)(q + 0x24));
}

void *ov01_021EAC4C(u32 heapId) {
    void *p = Heap_Alloc(heapId, 0x34);
    MI_CpuFill8(p, 0, 0x34);
    return p;
}

void ov01_021EAC64(void *p) {
    Heap_Free(p);
}

void ov01_021EAC6C(void *fieldCamera, u32 index) {
    u8 *owner = fieldCamera;
    u8 *control = *(void **)(owner + 0x28);
    u8 mode;
    *(void **)control = *(void **)(owner + 0x24);
    *(u32 *)(control + 0x30) = index;
    mode = ov01_02209B60;
    if (mode != 0) {
        u16 angle[4] = { 0, 0, 0, 0 };
        const CameraTransitionPresetPrivate *preset = &ov01_02206464[mode - 1];
        angle[0] = preset->head.angle;
        control[7] = mode;
        Camera_SetAnglePos(angle, *(void **)control);
        Camera_OffsetLookAtPosAndTarget(&preset->head.offset, *(void **)control);
    }
}
