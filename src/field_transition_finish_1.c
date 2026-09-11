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

extern const OverlayManagerTemplate _021028B4;
extern const OverlayManagerTemplate _021028C4;
extern const OverlayManagerTemplate gOverlayTemplate_Battle;
extern const OverlayManagerTemplate *_02110594[];
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

BOOL sub_02087C38(Unk87Work *work, enum HeapID heapId) {
    BOOL result;
    u16 bgm;
    FSOverlayID overlayId;

    switch (work->state) {
    case 0:
        if (*(u32 *)work->large != 0) {
            UnloadOverlayByID(OVERLAY_39_ID);
            UnloadOVY38();
        }
        work->state++;
        break;
    case 1:
        work->setup = BattleSetup_New(heapId, 0);
        if (!sub_0202FC48()) {
            sub_0202FC90(work->saveData, heapId, &result, work->setup, *(u32 *)(work->large + 0x86C));
        } else {
            sub_020304F0(work->setup, work->saveData);
            result = TRUE;
        }
        *(BagCursor **)((u8 *)work->setup + 0x10C) = BagCursor_New(heapId);
        *(GameStats **)((u8 *)work->setup + 0x144) = Save_GameStats_Get(work->saveData);
        overlayId = OVERLAY_40_ID;
        if (HandleLoadOverlay(overlayId, OVY_LOAD_ASYNC) == TRUE) {
            ov40_02244920(sub_0202FC5C(), work->setup, heapId);
            UnloadOverlayByID(overlayId);
        }
        *(u32 *)(work->large + 0x874) = 1;
        if (result != TRUE) {
            Heap_Free(*(void **)((u8 *)work->setup + 0x10C));
            BattleSetup_Delete(work->setup);
            work->state = 0;
            return TRUE;
        }
        work->state++;
        break;
    case 2:
        GF_SndHandleSetPlayerVolume(1, 0x7F);
        GF_SndHandleSetPlayerVolume(7, 0x7F);
        sub_02005B68(TRUE);
        if (sub_02087E34(*((u8 *)work->setup + 0x5D)) == TRUE) {
            Sound_SetSceneAndPlayBGM(5, 0x47B, 1);
        } else {
            Sound_SetSceneAndPlayBGM(5, 0x45D, 1);
        }
        work->manager = OverlayManager_New(&gOverlayTemplate_Battle, work->setup, heapId);
        work->state++;
        break;
    default:
        if (OverlayManager_Run(work->manager)) {
            *(u32 *)(work->large + 0x874) = *(u32 *)((u8 *)work->setup + 0x1C4);
            if (*(u32 *)work->large != 0 && *(u32 *)(work->large + 0x874) == 0) {
                **(u8 **)(work->large + 0x878) = 1;
            }
            Heap_Free(*(void **)((u8 *)work->setup + 0x10C));
            BattleSetup_Delete(work->setup);
            OverlayManager_Delete(work->manager);
            sub_02005B68(FALSE);
            Sound_SetScene(0);
            bgm = FieldBGM_GetEffective(work->args, ((FieldSystem *)work->args)->location->mapId);
            Sound_SetFieldBGM(FieldBGM_GetForMapHeader(work->args, ((FieldSystem *)work->args)->location->mapId));
            sub_02055198(NULL, bgm);
            work->state = 0;
            if (*(u32 *)work->large != 0) {
                LoadOVY38();
                HandleLoadOverlay(OVERLAY_39_ID, OVY_LOAD_ASYNC);
            }
            return TRUE;
        }
        break;
    }
    return FALSE;
}
