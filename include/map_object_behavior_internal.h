#ifndef POKEHEARTGOLD_MAP_OBJECT_BEHAVIOR_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_BEHAVIOR_INTERNAL_H
#include "global.h"

#include "map_object.h"
#include "overlay_01.h"
#include "overlay_01_022001E4.h"
#include "player_avatar.h"
#include "sys_task.h"
#include "sys_task_api.h"
#include "unk_020689C8.h"

typedef struct TrainerApproachWork {
    int state;
    int done;
    int movement;
    int remaining;
    int unk10;
    int unk14;
    int unk18;
    int timer;
    int effect;
    LocalMapObject *trainer;
    PlayerAvatar *player;
    void *fieldSystem;
} TrainerApproachWork;

u32 sub_0206234C(u32, u32);
int sub_02061200(int, int, int, int);
void sub_020632B0(LocalMapObject *, int, int, int, int, int, int);
BOOL MapObject_IsMovementPaused(LocalMapObject *);
BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *);
void MapObject_SetHeldMovement(LocalMapObject *, u32);
void MapObject_ClearHeldMovementIfActive(LocalMapObject *);

BOOL sub_0206464C(TrainerApproachWork *);
BOOL sub_02064668(TrainerApproachWork *);
BOOL sub_02064694(TrainerApproachWork *);
BOOL sub_020646DC(TrainerApproachWork *);
BOOL sub_02064714(TrainerApproachWork *);
BOOL sub_02064730(TrainerApproachWork *);
BOOL sub_02064748(TrainerApproachWork *);
BOOL sub_02064764(TrainerApproachWork *);
BOOL sub_02064778(TrainerApproachWork *);
BOOL sub_02064790(TrainerApproachWork *);
BOOL sub_020647A8(TrainerApproachWork *);
BOOL sub_020647C0(TrainerApproachWork *);
BOOL sub_020647E8(TrainerApproachWork *);
BOOL sub_02064808(TrainerApproachWork *);
BOOL sub_02064824(TrainerApproachWork *);
BOOL sub_020648A0(TrainerApproachWork *);
BOOL sub_020648C8(TrainerApproachWork *);
BOOL sub_020648E4(TrainerApproachWork *);
int sub_020643B8(LocalMapObject *, int, int, int, int, int);
int sub_020643E4(LocalMapObject *, int, int, int, int, int);
int sub_02064410(LocalMapObject *, int, int, int, int, int);
int sub_0206443C(LocalMapObject *, int, int, int, int, int);
u32 MapObject_GetTrainerNum(LocalMapObject *);
BOOL sub_02063A94(LocalMapObject *);
BOOL sub_02063AC8(LocalMapObject *);

BOOL MapObjectMovementCmd105_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd105_Step2(LocalMapObject *o);
BOOL MapObjectMovementCmd105_Step4(LocalMapObject *o);
BOOL MapObjectMovementCmd105_Step6(LocalMapObject *o);
BOOL MapObjectMovementCmd105_Step8(LocalMapObject *o);
BOOL MapObjectMovementCmd106_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd106_Step2(LocalMapObject *o);
BOOL MapObjectMovementCmd106_Step4(LocalMapObject *o);
BOOL MapObjectMovementCmd106_Step6(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step2(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step4(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step6(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step8(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step10(LocalMapObject *o);
BOOL MapObjectMovementCmd107_Step12(LocalMapObject *o);
BOOL MapObjectMovementCmd109_Step12(LocalMapObject *o);
BOOL MapObjectMovementCmd108_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd110_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd108_Step2(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step0(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step2(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step4(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step6(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step10(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step14(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step16(LocalMapObject *o);
BOOL MapObjectMovementCmd111_Step18(LocalMapObject *o);
BOOL MapObjectMovementCmd112_Step0(LocalMapObject *o);
int sub_020643B8(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ);
int sub_020643E4(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ);
int sub_02064410(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ);
int sub_0206443C(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ);
u32 MapObject_GetTrainerNum(LocalMapObject *object);
BOOL sub_02063A94(LocalMapObject *object);
BOOL sub_02063AC8(LocalMapObject *object);
BOOL sub_0206464C(TrainerApproachWork *work);
BOOL sub_02064668(TrainerApproachWork *work);
BOOL sub_02064694(TrainerApproachWork *work);
BOOL sub_020646DC(TrainerApproachWork *work);
BOOL sub_02064714(TrainerApproachWork *work);
BOOL sub_02064730(TrainerApproachWork *work);
BOOL sub_02064748(TrainerApproachWork *work);
BOOL sub_02064764(TrainerApproachWork *work);
BOOL sub_02064778(TrainerApproachWork *work);
BOOL sub_02064790(TrainerApproachWork *work);
BOOL sub_020647A8(TrainerApproachWork *work);
BOOL sub_020647C0(TrainerApproachWork *work);
BOOL sub_020647E8(TrainerApproachWork *work);
BOOL sub_02064808(TrainerApproachWork *work);
BOOL sub_02064824(TrainerApproachWork *work);
BOOL sub_020648A0(TrainerApproachWork *work);
BOOL sub_020648C8(TrainerApproachWork *work);
BOOL sub_020648E4(TrainerApproachWork *work);

#endif
