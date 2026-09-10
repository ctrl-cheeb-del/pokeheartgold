#ifndef POKEHEARTGOLD_MAP_OBJECT_FOLLOW_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_FOLLOW_INTERNAL_H
#include "global.h"

#include "field_system.h"
#include "map_object.h"
#include "player_avatar.h"

typedef struct FollowState {
    u8 state;
    u8 found;
    s16 x;
    s16 z;
    u16 unk6;
    LocalMapObject *other;
} FollowState;

int sub_02065CD0(LocalMapObject *, FollowState *);
void sub_020658D4(LocalMapObject *);
void sub_02065998(LocalMapObject *);
u8 sub_0206599C(LocalMapObject *);
u32 sub_020659A8(LocalMapObject *);
void sub_020659B8(LocalMapObject *);
void sub_02066054(LocalMapObject *);
void sub_02066058(LocalMapObject *);
void sub_020661CC(LocalMapObject *, FollowState *, LocalMapObject *);
BOOL sub_020661F0(LocalMapObject *, FollowState *);
void sub_020662C4(LocalMapObject *, u8);
void sub_0206630C(LocalMapObject *);
void sub_02066318(LocalMapObject *);
void sub_02066324(LocalMapObject *);
void sub_02066330(LocalMapObject *);
int sub_02066420(LocalMapObject *, int);
int sub_0206642C(LocalMapObject *);
void sub_02066438(LocalMapObject *);
BOOL sub_0206623C(LocalMapObject *, FollowState *);
u32 sub_0206234C(u32, u32);
int sub_02061200(int, int, int, int);
int GetDeltaXByFacingDirection(int);
int GetDeltaYByFacingDirection(int);
void MapObject_ForceSetHeldMovement(LocalMapObject *, u32);
BOOL sub_02062428(LocalMapObject *);
int ov01_021FFF5C(LocalMapObject *, int);
BOOL sub_02066064(LocalMapObject *, FollowState *);
BOOL sub_020660A0(LocalMapObject *, FollowState *);
BOOL sub_020663B4(LocalMapObject *, FollowState *);
BOOL sub_020663E4(LocalMapObject *, FollowState *);
BOOL sub_0205F73C(LocalMapObject *);
BOOL sub_02065BE8(LocalMapObject *, FollowState *);
BOOL sub_02065C2C(LocalMapObject *, FollowState *);
BOOL sub_02065D24(LocalMapObject *, FollowState *);
void sub_02065D58(LocalMapObject *, FollowState *);
BOOL sub_02065FBC(LocalMapObject *);
BOOL sub_02065C48(LocalMapObject *, FollowState *);
BOOL sub_02065C90(LocalMapObject *, FollowState *);
u32 sub_02069ED4(LocalMapObject *);
void sub_02065FFC(LocalMapObject *);
void sub_02066360(LocalMapObject *);
int sub_02066150(LocalMapObject *, FollowState *);
void ov01_021F1640(int);
void sub_02065CFC(LocalMapObject *, FollowState *);
int sub_02065CD0(LocalMapObject *, FollowState *);
void sub_02065D58(LocalMapObject *, FollowState *);
int sub_02065D78(LocalMapObject *);
int sub_02065DB4(LocalMapObject *);

void sub_020658D4(LocalMapObject *object);
void sub_02065998(LocalMapObject *object);
u8 sub_0206599C(LocalMapObject *object);
u32 sub_020659A8(LocalMapObject *object);
void sub_020659B8(LocalMapObject *object);
void sub_02066054(LocalMapObject *object);
void sub_02066058(LocalMapObject *object);
void sub_020661CC(LocalMapObject *unused, FollowState *state, LocalMapObject *other);
BOOL sub_020661F0(LocalMapObject *object, FollowState *state);
BOOL sub_0206623C(LocalMapObject *object, FollowState *state);
void sub_0206630C(LocalMapObject *o);
void sub_02066318(LocalMapObject *o);
void sub_02066324(LocalMapObject *o);
void sub_02066330(LocalMapObject *o);
int sub_02066420(LocalMapObject *object, int value);
int sub_0206642C(LocalMapObject *object);
void sub_02066438(LocalMapObject *object);
BOOL sub_02066064(LocalMapObject *object, FollowState *state);
BOOL sub_020660A0(LocalMapObject *object, FollowState *state);
BOOL sub_020663B4(LocalMapObject *object, FollowState *state);
BOOL sub_020663E4(LocalMapObject *object, FollowState *state);
BOOL sub_02065BE8(LocalMapObject *object, FollowState *state);
BOOL sub_02065C2C(LocalMapObject *object, FollowState *state);
BOOL sub_02065C48(LocalMapObject *object, FollowState *state);
BOOL sub_02065C90(LocalMapObject *object, FollowState *state);
void sub_02065FFC(LocalMapObject *object);
void sub_02066360(LocalMapObject *object);
BOOL sub_02065D24(LocalMapObject *object, FollowState *state);
void sub_02065D58(LocalMapObject *object, FollowState *state);
int sub_02065CD0(LocalMapObject *object, FollowState *state);
void sub_02065CFC(LocalMapObject *object, FollowState *state);
int sub_02065D78(LocalMapObject *object);
int sub_02065DB4(LocalMapObject *object);

#endif
