#ifndef SOL40_UNK_020659CC_PRIVATE_H
#define SOL40_UNK_020659CC_PRIVATE_H
#include "global.h"

#include "field_system.h"
#include "follow_mon.h"
#include "map_object.h"
#include "overlay_01.h"
#include "player_avatar.h"

typedef struct FollowStateSol {
    u8 state;
    u8 found;
    s16 x;
    s16 z;
    u16 unk6;
    u16 unk8;
    u16 flag0 : 1;
    u16 flags : 15;
} FollowStateSol;

extern BOOL sub_02065D24(LocalMapObject *, FollowStateSol *);
extern void sub_02065D58(LocalMapObject *, FollowStateSol *);
extern int sub_02065D78(LocalMapObject *);
extern BOOL sub_02065DF4(LocalMapObject *, FollowStateSol *);
extern BOOL sub_02065F44(LocalMapObject *);
extern void sub_020664D8(LocalMapObject *);
extern BOOL sub_020623C8();
void sub_020659CC(LocalMapObject *);
BOOL sub_02065A4C(LocalMapObject *, FollowStateSol *);
BOOL sub_02065B70(LocalMapObject *, FollowStateSol *);
#endif
