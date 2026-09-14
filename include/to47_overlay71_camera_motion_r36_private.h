#ifndef TO47_OVERLAY71_CAMERA_MOTION_R36_PRIVATE_H
#define TO47_OVERLAY71_CAMERA_MOTION_R36_PRIVATE_H

#include "global.h"

#include "sys_task_api.h"

typedef struct Ov71MoveStateR36 {
    void *owner;
    SysTask *task;
    u32 unk_08;
    void *camera;
    VecFx32 base;
    VecFx32 rotated;
    VecFx32 position;
    VecFx16 angle;
    u8 pad_3A[2];
    fx32 baseStepX;
    fx32 baseStepY;
    fx32 currentX;
    fx32 currentY;
    fx32 stepX;
    fx32 stepY;
    fx32 targetX;
    fx32 targetY;
    fx32 currentZ;
    fx32 stepZ;
    fx32 targetZ;
    s32 moveFrames;
    u32 state;
    s32 waitFrames;
    s32 frame;
    s16 rotation;
    s16 rotationStep;
} Ov71MoveStateR36;

extern u32 _0224C020[];

fx32 GF_CosDegNoWrap(u16 degrees);
fx32 GF_SinDegNoWrap(u16 degrees);
s32 _s32_div_f(s32 dividend, s32 divisor);
void ov71_022476C4(void *camera, const VecFx32 *position);
void ov71_022476EC(void *camera, const VecFx16 *angle);
void ov71_02247704(void *camera, s32 value);
void ov71_02247730(void *camera, fx32 value);
BOOL ov71_02247738(void *camera);
void ov71_0224A8A8(void *owner);
void ov71_0224A694(Ov71MoveStateR36 *work, fx32 x, fx32 y, fx32 z, s32 frames);
void ov71_0224A6D8(Ov71MoveStateR36 *work);
void ov71_0224A7D0(SysTask *task, Ov71MoveStateR36 *work);

#endif
