#ifndef TO45_OVERLAY01_WHIRLPOOL_MOTION_R11_PRIVATE_H
#define TO45_OVERLAY01_WHIRLPOOL_MOTION_R11_PRIVATE_H

#include "global.h"

#include "map_object.h"
#include "overlay_01.h"
#include "overlay_01_021F1AFC.h"

struct SurfWork {
    int unk0;
    u32 gender;
    u32 unk8;
    void *unkC;
};

struct WaterfallWork {
    int state;
    int direction;
    int counter;
    int targetX;
    int targetY;
    int targetZ;
    int progress;
    int deltaX;
    int deltaY;
    int deltaZ;
    int stepX;
    int stepY;
    int stepZ;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *obj;
    struct SurfWork surf;
    void *effect;
};

void *ov01_021F30D0(u32 size);
int ov01_021F2DD0(TaskManager *taskManager);
void ov02_0224D5AC(void *effect);
void *ov02_0224D598(FieldSystem *fieldSystem);
void sub_020611C8(int x, int z, VecFx32 *position);
void sub_0206121C(FieldSystem *fieldSystem, VecFx32 *position);
void sub_02060F78(LocalMapObject *object);
int GetDeltaXByFacingDirection(int direction);
int GetDeltaYByFacingDirection(int direction);

int ov01_021F2BC8(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2C88(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2CD4(struct WaterfallWork *work, TaskManager *taskManager);
void ov01_021F2D68(FieldSystem *fieldSystem, int direction, struct SurfWork *surf);

#endif
