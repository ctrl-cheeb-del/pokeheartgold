#include "to47_overlay71_camera_motion_r36_private.h"

void ov71_0224A694(Ov71MoveStateR36 *work, fx32 x, fx32 y, fx32 z, s32 frames) {
    volatile s32 duration = frames;

    if (frames != 0) {
        work->stepX = (x - work->currentX) / duration;
        work->stepY = (y - work->currentY) / duration;
        work->stepZ = (z - work->currentZ) / duration;
        work->targetX = x;
        work->targetY = y;
        work->targetZ = z;
        work->moveFrames = frames;
    }
}

void ov71_0224A6D8(Ov71MoveStateR36 *work) {
    s32 degrees;

    if (_0224C020[0] != 0) {
        fx32 currentX;
        fx32 currentY;
        s64 product;

        degrees = (u16)work->rotation / 182;
        if (degrees >= 360) {
            degrees -= 360;
        }
        work->rotation -= work->rotationStep;

        if (work->moveFrames != 0) {
            work->moveFrames--;
            if (work->moveFrames != 0) {
                work->currentX += work->stepX;
                work->currentY += work->stepY;
                work->currentZ += work->stepZ;
            } else {
                work->currentX = work->targetX;
                work->currentY = work->targetY;
                work->currentZ = work->targetZ;
            }
            ov71_02247730(work->camera, work->currentZ);
        }

        currentX = work->currentX;
        product = GF_CosDegNoWrap((u16)degrees);
        product *= currentX;
        work->rotated.x = (product + 0x800) >> FX32_SHIFT;
        currentY = work->currentY;
        product = GF_SinDegNoWrap((u16)degrees);
        product *= currentY;
        work->rotated.y = (product + 0x800) >> FX32_SHIFT;
        work->rotated.z = 0;
        work->angle.x -= 0x300;
        ov71_022476EC(work->camera, &work->angle);
        VEC_Add(&work->rotated, &work->base, &work->position);
    } else {
        work->position = work->base;
    }
}

void ov71_0224A7D0(SysTask *task, Ov71MoveStateR36 *work) {
    if (work->frame < 70) {
        work->frame++;
    }

    switch (work->state) {
    case 0:
        ov71_0224A6D8(work);
        ov71_022476C4(work->camera, &work->position);
        work->frame++;
        if (work->frame >= 12) {
            work->frame = 0;
            work->state++;
        }
        break;
    case 1:
        if (!ov71_02247738(work->camera)) {
            ov71_0224A8A8(work->owner);
            work->state++;
        } else {
            work->base.y += work->baseStepX;
            work->base.z += work->baseStepY;
            ov71_0224A6D8(work);
            ov71_022476C4(work->camera, &work->position);
        }
        break;
    case 2:
        work->base.y += work->baseStepX;
        work->base.z += work->baseStepY;
        ov71_0224A6D8(work);
        ov71_022476C4(work->camera, &work->position);
        if (work->frame >= 70) {
            ov71_02247704(work->camera, 0);
            work->waitFrames = 0;
            work->state++;
        }
        break;
    case 3:
        work->waitFrames++;
        if (work->waitFrames > 8) {
            work->task = NULL;
            SysTask_Destroy(task);
        }
        break;
    }
}
