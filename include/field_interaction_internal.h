#ifndef POKEHEARTGOLD_FIELD_INTERACTION_INTERNAL_H
#define POKEHEARTGOLD_FIELD_INTERACTION_INTERNAL_H
#include "global.h"

#include "field_system.h"
#include "map_events_internal.h"
#include "map_object.h"
#include "metatile_behavior.h"
#include "player_avatar.h"
#include "script_manager.h"
#include "unk_02054648.h"

// Offsets match asm/include/unk_0203DB6C.inc usage in sub_0203DE04.
void sub_0203DB6C(void);
void sub_0203DB70(void);
BOOL sub_0203DB74(void);
u32 _GetCoordsOfFacingTile(FieldSystem *fieldSystem, int *x, int *z);
u8 sub_0203DBD4(PlayerAvatar *avatar, LocalMapObject *object);
void FieldSystem_GetFacingObject(FieldSystem *fieldSystem, LocalMapObject **ret_p);
BOOL sub_0203DC64(FieldSystem *fieldSystem, LocalMapObject **localMapObject);
u16 GetInteractedBackgroundEventScript(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents);
u8 BgEventIsUncollectedHiddenItem(FieldSystem *fieldSystem, BgEvent *bgEvent);
BOOL BgEventDirectionIsCompatibleWithPlayerFacing(FieldSystem *fieldSystem, BgEvent *bgEvent);
u32 sub_0203DDA4(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents);
u16 sub_0203DE04(FieldSystem *fieldSystem, const CoordEvent *coordEvents, int numEvents);

void sub_0203DB6C(void);
void sub_0203DB70(void);
BOOL sub_0203DB74(void);
u32 _GetCoordsOfFacingTile(FieldSystem *fieldSystem, int *x, int *z);
u8 sub_0203DBD4(PlayerAvatar *avatar, LocalMapObject *object);
void FieldSystem_GetFacingObject(FieldSystem *fieldSystem, LocalMapObject **ret_p);
BOOL sub_0203DC64(FieldSystem *fieldSystem, LocalMapObject **localMapObject);
u16 GetInteractedBackgroundEventScript(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents);
u8 BgEventIsUncollectedHiddenItem(FieldSystem *fieldSystem, BgEvent *bgEvent);
BOOL BgEventDirectionIsCompatibleWithPlayerFacing(FieldSystem *fieldSystem, BgEvent *bgEvent);
u32 sub_0203DDA4(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents);
u16 sub_0203DE04(FieldSystem *fieldSystem, const CoordEvent *coordEvents, int numEvents);

#endif
