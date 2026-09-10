#ifndef POKEHEARTGOLD_BATTLE_TRANSITION_APPLICATION_INTERNAL_H
#define POKEHEARTGOLD_BATTLE_TRANSITION_APPLICATION_INTERNAL_H
#include "global.h"

#include "battle/battle_setup.h"

#include "bag_cursor.h"
#include "field_bgm.h"
#include "field_system.h"
#include "game_stats.h"
#include "heap.h"
#include "overlay_app_manager_internal.h"
#include "overlay_manager.h"
#include "poke_overlay.h"
#include "sound_02004A44.h"
#include "sys_flags.h"
#include "unk_0202FBCC.h"

typedef struct Unk87Work {
    u32 state;
    u32 unk4;
    OverlayManager *manager;
    void *saveData;
    void *setup;
    u8 *large;
    u32 result;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    void *args;
} Unk87Work;

typedef struct Pair87 {
    u32 first;
    u32 second;
} Pair87;

typedef struct FiveValues {
    u32 values[5];
} FiveValues;

extern const OverlayManagerTemplate _021028B4;
extern const OverlayManagerTemplate _021028C4;
extern const OverlayManagerTemplate gOverlayTemplate_Battle;
extern const OverlayManagerTemplate *_02110594[];
extern const FiveValues _021028A0;
extern u8 SDK_OVERLAY_OVY_39_ID;
extern u8 SDK_OVERLAY_OVY_40_ID;

#define OVERLAY_39_ID ((FSOverlayID) & SDK_OVERLAY_OVY_39_ID)
#define OVERLAY_40_ID ((FSOverlayID) & SDK_OVERLAY_OVY_40_ID)

extern void sub_0202FC24(void);
extern void *sub_0202FC5C(void);
extern void sub_0202FC90(void *saveData, enum HeapID heapId, BOOL *result, BattleSetup *setup, u32 value);
extern void sub_020304F0(BattleSetup *setup, void *saveData);
extern void ov40_02244920(void *data, BattleSetup *setup, enum HeapID heapId);
extern void sub_02005B68(BOOL enabled);
extern void *sub_02087FF8(void *large, u32 value);

void *sub_02087A78(OverlayManager *manager);
void sub_02087A84(Pair87 *pair, u32 first, u32 second);
void sub_02087A8C(OverlayManager *manager, u32 mode);
BOOL sub_02087B10(OverlayManager *manager, int *state);
BOOL sub_02087B1C(OverlayManager *manager, int *state);
BOOL sub_02087B28(OverlayManager *manager, int *state);
BOOL sub_02087B34(OverlayManager *manager, int *state);
BOOL sub_02087B40(OverlayManager *manager, int *state);
BOOL sub_02087B4C(OverlayManager *manager, int *state);
BOOL sub_02087B58(OverlayManager *manager, int *state);
BOOL sub_02087B64(OverlayManager *manager, int *state);
BOOL sub_02087BAC(OverlayManager *manager, int *state);
BOOL sub_02087BE8(Unk87Work *work, enum HeapID heapId);
BOOL sub_02087C38(Unk87Work *work, enum HeapID heapId);
const OverlayManagerTemplate *sub_02087E10(u8 index);
BOOL sub_02087E1C(u8 *data);
BOOL sub_02087E34(u32 value);

#endif
