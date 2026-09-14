#include "to45_overlay01_whirlpool_motion_r11_private.h"

int ov01_021F2BC8(struct WaterfallWork *work, TaskManager *taskManager) {
    VecFx32 position;
    VecFx32 step;
    int x = MapObject_GetXCoord(work->obj) + (GetDeltaXByFacingDirection(1) << 1);
    int z = MapObject_GetZCoord(work->obj) + (GetDeltaYByFacingDirection(1) << 1);

    sub_020611C8(x, z, (VecFx32 *)&work->stepX);
    sub_0206121C(work->fieldSystem, (VecFx32 *)&work->stepX);
    work->progress = 0;
    work->targetX = x;
    work->targetY = (work->stepY >> 3) / FX32_ONE;
    work->targetZ = z;
    MapObject_CopyPositionVector(work->obj, &position);
    if (position.z >= work->stepZ) {
        GF_AssertFail();
    }
    if (position.y <= work->stepY) {
        GF_AssertFail();
    }
    step.x = 0;
    step.y = work->stepY - position.y;
    step.z = work->stepZ - position.z;
    step.y /= 64;
    step.z /= 64;
    *(VecFx32 *)&work->deltaX = step;
    work->effect = ov02_0224D598(work->fieldSystem);
    work->state++;
    return 0;
}

int ov01_021F2C88(struct WaterfallWork *work, TaskManager *taskManager) {
    VecFx32 position;

    MapObject_CopyPositionVector(work->obj, &position);
    position.z += work->deltaZ;
    if (position.z > work->stepZ) {
        position.z = work->stepZ;
    } else {
        work->progress += work->deltaZ;
    }
    MapObject_SetPositionVector(work->obj, &position);
    work->counter++;
    if (work->counter >= 32) {
        work->counter = 0;
        work->state++;
    }
    return 0;
}

int ov01_021F2CD4(struct WaterfallWork *work, TaskManager *taskManager) {
    VecFx32 position;

    MapObject_CopyPositionVector(work->obj, &position);
    position.y += work->deltaY;
    if (position.y < work->stepY) {
        position.y = work->stepY;
    }
    position.z += work->deltaZ;
    if (position.z > work->stepZ) {
        position.z = work->stepZ;
    } else {
        work->progress += work->deltaZ;
    }
    MapObject_SetPositionVector(work->obj, &position);
    work->counter++;
    if (work->counter < 64) {
        return 0;
    }
    if (position.z != work->stepZ) {
        GF_AssertFail();
    }
    if (position.y != work->stepY) {
        GF_AssertFail();
    }
    MapObject_SetCurrentX(work->obj, work->targetX);
    MapObject_SetCurrentY(work->obj, work->targetY);
    MapObject_SetCurrentZ(work->obj, work->targetZ);
    sub_02060F78(work->obj);
    ov02_0224D5AC(work->effect);
    return 1;
}

void ov01_021F2D68(FieldSystem *fieldSystem, int direction, struct SurfWork *surf) {
    struct WaterfallWork *work = ov01_021F30D0(sizeof(struct WaterfallWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = fieldSystem->playerAvatar;
    work->obj = PlayerAvatar_GetMapObject(work->playerAvatar);
    work->surf = *surf;
    TaskManager_Call(fieldSystem->taskman, ov01_021F2DD0, work);
}
