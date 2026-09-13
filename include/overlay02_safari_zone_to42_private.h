#ifndef OVERLAY02_SAFARI_ZONE_TO42_PRIVATE_H
#define OVERLAY02_SAFARI_ZONE_TO42_PRIVATE_H

#include "global.h"

#include "field_metatile_query_internal.h"
#include "field_system.h"
#include "heap.h"
#include "overlay_02.h"
#include "player_avatar.h"
#include "safari_zone.h"
#include "unk_0205FD20.h"
#include "unk_02097268.h"

int ov02_0224E4CC(void *fieldSystem, u32 behavior);
int ov02_0224E4DC(void *fieldSystem, u32 behavior);
int ov02_0224E31C(s32 x, s32 z);
BOOL ov02_0224E828(FieldSystem *fieldSystem, s32 x, s32 z, int direction, fx32 y, s16 *outA, s16 *outB, BOOL state);
BOOL ov02_0224EB48(FieldSystem *fieldSystem, s32 x, s32 z, int direction, fx32 y, s16 *outA, s16 *outB, BOOL state);
BOOL ov02_0224E640(void *saveData);
u16 ov02_0224E698(FieldSystem *fieldSystem);
u16 ov02_0224E754(FieldSystem *fieldSystem, u16 *objectIndex);
BOOL ov02_0224EE4C(FieldSystem *fieldSystem, s32 x, s32 z, int direction, fx32 y, s16 *outA, s16 *outB, BOOL state);
SafariDecorationArgs *SafariDecoration_CreateArgs(FieldSystem *fieldSystem, enum HeapID heapID);
int ov02_0224EF6C(void *fieldSystem, u32 behavior, u32 which);

#endif
