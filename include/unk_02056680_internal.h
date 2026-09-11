#ifndef UNK_02056680_PRIVATE_H
#define UNK_02056680_PRIVATE_H
#include <string.h>

#include "global.h"
typedef struct TaskManager TaskManager;
typedef struct TransitionWork TransitionWork;
typedef struct PlayerAvatar PlayerAvatar;
typedef struct TransitionEnv {
    u16 unk0;
    u16 state;
    u8 pad4[0x14];
    TransitionWork *work;
} TransitionEnv;
typedef struct AppEnv {
    u16 state;
    u16 parameter;
    void *fieldArg;
    void *saveData;
    u32 value;
} AppEnv;
extern void *TaskManager_GetFieldSystem(TaskManager *);
extern void *TaskManager_GetEnvironment(TaskManager *);
extern void TaskManager_Call(TaskManager *, BOOL (*)(TaskManager *), void *);
extern void CallApplicationAsTask(TaskManager *, const void *, void *);
extern void *Heap_AllocAtEnd(int, u32);
extern void Heap_Free(void *);
extern void MI_CpuClear8(void *, u32);
extern TransitionWork *ov01_021E90C0(void);
extern void ov01_021E90D4(TransitionWork *);
extern void ov01_021E90DC(int, int, TransitionWork *);
extern BOOL ov01_021E971C(void *, TransitionWork *, u8);
extern BOOL ov01_021E9C40(TaskManager *);
extern int PlayerAvatar_GetXCoord(void *);
extern int PlayerAvatar_GetZCoord(void *);
extern int PlayerAvatar_GetFacingDirection(PlayerAvatar *);
extern void *PlayerAvatar_GetMapObject(void *);
extern void FieldMap_FadeScreen(int);
extern BOOL MapObject_IsMovementPaused(void *);
extern void MapObject_ClearHeldMovementIfActive(void *);
extern void MapObject_SetHeldMovement(void *, int);
extern BOOL FollowMon_IsActive(void *);
extern void ov01_02205790(void *, u8);
extern BOOL IsPaletteFadeFinished(void);
extern void GF_AssertFail(void);
extern BOOL sub_02056680(TaskManager *);
extern BOOL sub_020566F8(TaskManager *);
extern BOOL sub_020567B4(TaskManager *);
extern BOOL sub_0205681C(TaskManager *);
extern BOOL sub_02056938(TaskManager *);
extern void sub_02056D00(TaskManager *, u16);
extern BOOL sub_02056D30(TaskManager *);
extern void ov45_02229EE0(void);
extern void ov45_02229F70(void);
extern void ov45_02229F94(void);
extern u32 SDK_OVERLAY_OVY_45_ID;
extern void MapObject_CopyPositionVector(void *, VecFx32 *);
extern void MapObject_SetPositionVector(void *, const VecFx32 *);
extern BOOL MapObject_AreBitsSetForMovementScriptInit(void *);
extern void PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(void *, BOOL);
extern void Field_PlayerAvatar_OrrTransitionFlags(void *, u32);
extern void Field_PlayerAvatar_ApplyTransitionFlags(void *);
extern void *FollowMon_GetMapObject(void *);
extern void sub_0205FC94(void *, int);
extern void sub_02069DC8(void *, int);
extern void *Camera_GetCurrentTarget(void *);
extern VecFx32 Camera_GetLookAtCamTarget(void *);
extern void VEC_Subtract(const VecFx32 *, const VecFx32 *, VecFx32 *);
extern void PlayerAvatar_CopyPositionVector(void *, VecFx32 *);
extern VecFx32 *PlayerAvatar_GetPositionVector(void *);
extern void PlayerAvatar_ToggleAutomaticHeightUpdating(void *, BOOL);
extern void sub_0205C810(void *, const VecFx32 *, int);
extern void Camera_SetLookAtTargetAndRecalcPos(VecFx32 *, void *);
extern void Camera_SetFixedTarget(VecFx32 *, void *);
extern void Camera_OffsetLookAtPosAndTarget(const VecFx32 *, void *);
extern void sub_0205F328(void *, int);
extern void sub_02056BC8(void *);
extern void sub_02056C64(void *);
#endif
