#include "global.h"

typedef struct VecFx32Private {
    s32 x;
    s32 y;
    s32 z;
} VecFx32Private;

typedef struct CameraTransitionHeadPrivate {
    u16 angle;
    u16 padding;
    VecFx32Private offset;
} CameraTransitionHeadPrivate;

typedef struct CameraTransitionPresetPrivate {
    CameraTransitionHeadPrivate head;
    u32 duration;
} CameraTransitionPresetPrivate;

typedef struct FieldCameraPresetPrivate {
    s32 distance;
    u16 angle[4];
    u16 unkC;
    u16 unkE;
    s32 clipNear;
    s32 clipFar;
    VecFx32Private offset;
} FieldCameraPresetPrivate;

typedef struct FieldCameraControlPrivate {
    void *camera;
    u8 duration;
    u8 step;
    u8 padding6;
    u8 mode;
    CameraTransitionHeadPrivate transition;
    u8 padding18[0x10];
    u32 active;
    u16 targetAngle;
    u16 toggle;
    u32 presetNo;
} FieldCameraControlPrivate;

extern const CameraTransitionPresetPrivate ov01_02206464[];
extern const FieldCameraPresetPrivate ov01_02206478[];
extern u32 ov01_02209B60;

extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void Camera_UnsetStaticPtr(void);
extern void Camera_History_Delete(void *);
extern void Camera_Delete(void *);
extern void Camera_SetAnglePos(const u16 *, void *);
extern void Camera_OffsetLookAtPosAndTarget(const VecFx32Private *, void *);
extern void *Camera_New(u32);
extern void Camera_Init_FromTargetDistanceAndAngle(void *, s32, const u16 *, u16, u8, BOOL, void *);
extern void Camera_SetStaticPtr(void *);
extern void Camera_SetPerspectiveClippingPlane(s32, s32, void *);
extern void Camera_History_New(u32, u32, u32, u32, void *);
extern void GF_AssertFail(void);

void FieldCamera_Delete(void *);
void *ov01_021EAC4C(u32);
void ov01_021EAC64(void *);
void ov01_021EAE50(void *, const u16 *, const u16 *, u32, u8);
void ov01_021EAEA4(void *, const VecFx32Private *, u32, u32);
s32 ov01_021EAEE0(s32, s32, s32);
void ov01_021EAC6C(void *, u32);
void FieldCamera_Create(void *, void *, u32, BOOL);
void ov01_021EACBC(FieldCameraControlPrivate *, u8);
void ov01_021EAD8C(FieldCameraControlPrivate *);
