#ifndef OVERLAY_116_PRIVATE_H
#define OVERLAY_116_PRIVATE_H

#include "global.h"

typedef struct Camera Camera;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Ov116CameraAngle;

typedef struct {
    u8 pad00[0x24];
    Camera *camera;
} Ov116FieldSystem;

typedef struct {
    u32 distance;
    u16 angleX;
    u16 angleY;
    u16 perspective;
    u16 delay;
} Ov116CameraKey;

typedef struct {
    u8 unk00;
    u8 delay;
    u8 duration;
    u8 fadeFrames;
    s32 perspectiveDelta;
    s32 distanceDelta;
    s32 distanceDuration;
    u16 angleX;
    u16 angleY;
} Ov116Sequence;

typedef struct {
    u32 state;
    u32 done;
    u32 unused08;
    void *work;
    Ov116FieldSystem *fieldSystem;
    u32 *completionFlag;
} Ov116Task;

typedef struct {
    void *effect;
    u32 unused04;
    u32 index;
    s32 delay;
} Ov116PanWork;

typedef struct {
    void *effect;
    u8 pad04[4];
    s32 perspectiveInterp[5];
    s32 distanceInterp[5];
    u32 unused30;
    s32 delay;
} Ov116MoveWork;

extern void Camera_SetPerspectiveAngle(u16, Camera *);
extern void Camera_SetAnglePos(const Ov116CameraAngle *, Camera *);
extern void Camera_SetDistance(s32, Camera *);
extern u16 Camera_GetPerspectiveAngle(Camera *);
extern s32 Camera_GetDistance(Camera *);
extern void *Heap_Alloc(int, u32);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void ov01_021EFCF8(int, int, int, u32 *, int);
extern void ov01_021EFCDC(void *, void *);
extern void ov01_021EFE34(void *, s32, s32, int);
extern int ov01_021EFE44(void *);
extern void ov01_021EFEC8(void *, s32, s32, s32, int);
extern int ov01_021EFF28(void *);
extern u32 ov01_021F467C(u32, u32);
extern void ov01_021F46DC(void *);
extern void BeginNormalPaletteFade(int, int, int, u16, int, int, int);
extern int IsPaletteFadeFinished(void);
extern void sub_0200FBF4(int, u16);

void ov116_0225F020(Ov116FieldSystem *, const Ov116CameraKey *);
void ov116_0225F054(void *, Ov116Task *);
void ov116_0225F1BC(void *, Ov116Task *, const Ov116Sequence *);
void ov116_0225F364(void *, Ov116Task *);
void ov116_0225F374(void *, Ov116Task *);

#endif
