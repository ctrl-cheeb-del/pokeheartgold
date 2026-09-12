#include "global.h"

typedef struct PlayerAvatar PlayerAvatar;
typedef struct MapObject MapObject;
typedef struct Camera Camera;
typedef struct FieldSystem {
    u8 pad00[0x24];
    Camera *camera;
    u8 pad28[0x18];
    PlayerAvatar *playerAvatar;
} FieldSystem;

extern VecFx32 *Camera_GetCurrentTarget(Camera *);
extern VecFx32 Camera_GetLookAtCamTarget(Camera *);
extern void VEC_Subtract(const VecFx32 *, const VecFx32 *, VecFx32 *);
extern int PlayerAvatar_GetFacingDirection(PlayerAvatar *);
extern void PlayerAvatar_CopyPositionVector(PlayerAvatar *, VecFx32 *);
extern fx32 sub_02054940(FieldSystem *, fx32, fx32, fx32, int);
extern void sub_0205C810(PlayerAvatar *, const VecFx32 *, int);
extern VecFx32 *PlayerAvatar_GetPositionVector(PlayerAvatar *);
extern void Camera_SetLookAtTargetAndRecalcPos(VecFx32 *, Camera *);
extern void Camera_SetFixedTarget(VecFx32 *, Camera *);
extern void Camera_OffsetLookAtPosAndTarget(const VecFx32 *, Camera *);
extern int PlayerAvatar_GetXCoord(PlayerAvatar *);
extern int PlayerAvatar_GetZCoord(PlayerAvatar *);
extern u8 GetMetatileBehavior(FieldSystem *, int, int);
extern BOOL MetatileBehavior_IsWarpStairsEast(u8);
extern BOOL MetatileBehavior_IsWarpStairsWest(u8);
extern BOOL FollowMon_IsActive(FieldSystem *);
extern MapObject *FollowMon_GetMapObject(FieldSystem *);
extern void MapObject_SetFacingDirectionDirect(MapObject *, int);

void sub_02056A54(FieldSystem *fieldSystem);
void sub_02056AEC(FieldSystem *fieldSystem);

void sub_02056A54(FieldSystem *fieldSystem) {
    VecFx32 *cameraTarget;
    VecFx32 playerPosition;
    VecFx32 delta;
    VecFx32 oldLookAt;
    VecFx32 lookAt;
    int direction;

    cameraTarget = Camera_GetCurrentTarget(fieldSystem->camera);
    lookAt = Camera_GetLookAtCamTarget(fieldSystem->camera);
    oldLookAt = lookAt;
    VEC_Subtract(&oldLookAt, cameraTarget, &delta);
    direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    PlayerAvatar_CopyPositionVector(fieldSystem->playerAvatar, &playerPosition);
    if (direction == 3) {
        playerPosition.x -= FX32_ONE * 16;
    } else {
        playerPosition.x += FX32_ONE * 16;
    }
    playerPosition.y = sub_02054940(fieldSystem, playerPosition.y, playerPosition.x, playerPosition.z, 0);
    sub_0205C810(fieldSystem->playerAvatar, &playerPosition, direction);
    Camera_SetLookAtTargetAndRecalcPos(PlayerAvatar_GetPositionVector(fieldSystem->playerAvatar), fieldSystem->camera);
    Camera_SetFixedTarget(PlayerAvatar_GetPositionVector(fieldSystem->playerAvatar), fieldSystem->camera);
    Camera_OffsetLookAtPosAndTarget(&delta, fieldSystem->camera);
}

void sub_02056AEC(FieldSystem *fieldSystem) {
    VecFx32 *cameraTarget;
    VecFx32 playerPosition;
    VecFx32 delta;
    VecFx32 oldLookAt;
    VecFx32 lookAt;
    int direction;
    int x;
    u8 behavior;

    cameraTarget = Camera_GetCurrentTarget(fieldSystem->camera);
    lookAt = Camera_GetLookAtCamTarget(fieldSystem->camera);
    oldLookAt = lookAt;
    VEC_Subtract(&oldLookAt, cameraTarget, &delta);
    direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    PlayerAvatar_CopyPositionVector(fieldSystem->playerAvatar, &playerPosition);
    x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    behavior = GetMetatileBehavior(fieldSystem, x, PlayerAvatar_GetZCoord(fieldSystem->playerAvatar));
    if (MetatileBehavior_IsWarpStairsEast(behavior)) {
        playerPosition.x += FX32_ONE * 16;
        direction = 2;
    } else if (MetatileBehavior_IsWarpStairsWest(behavior)) {
        playerPosition.x -= FX32_ONE * 16;
        direction = 3;
    }
    playerPosition.y = sub_02054940(fieldSystem, playerPosition.y, playerPosition.x, playerPosition.z, 0);
    sub_0205C810(fieldSystem->playerAvatar, &playerPosition, direction);
    Camera_SetLookAtTargetAndRecalcPos(PlayerAvatar_GetPositionVector(fieldSystem->playerAvatar), fieldSystem->camera);
    Camera_SetFixedTarget(PlayerAvatar_GetPositionVector(fieldSystem->playerAvatar), fieldSystem->camera);
    Camera_OffsetLookAtPosAndTarget(&delta, fieldSystem->camera);
    if (FollowMon_IsActive(fieldSystem)) {
        MapObject_SetFacingDirectionDirect(FollowMon_GetMapObject(fieldSystem), direction);
    }
}
