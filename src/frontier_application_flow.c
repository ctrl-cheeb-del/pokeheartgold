#include "global.h"

#include "field_system.h"
#include "frontier_application_internal.h"
#include "game_stats.h"
#include "heap.h"
#include "launch_application.h"
#include "options.h"
#include "player_data.h"
#include "task.h"
#include "unk_02037C94.h"

typedef struct Main97024 {
    u32 state;
    u32 selection;
    u8 sendData[4];
    u32 frame;
    SaveData *saveData;
    void *unk14;
    Options *options;
    GameStats *gameStats;
    FieldSystem *fieldSystem2;
    Work97024 *subwork;
    FieldSystem *fieldSystem;
    PartyMenuArgs *partyMenu;
    PokemonSummaryArgs *summary;
} Main97024;

Work97024 *sub_02097024(const Input97024 *input, enum HeapID heapID);
void sub_02097060(Work97024 *work);
u32 sub_02097078(Work97024 *work);
void *sub_0209707C(FieldSystem *fieldSystem);
BOOL sub_020970C0(void *data);
typedef BOOL (*State97024)(Main97024 *work);
extern const State97024 _02108EC0[];
extern const OverlayManagerTemplate _02108EA0;
extern const OverlayManagerTemplate _02108EB0;
BOOL sub_020970E4(Main97024 *work);
BOOL sub_02097108(Main97024 *work);
BOOL sub_02097148(Main97024 *work);
BOOL sub_020971AC(Main97024 *work);
BOOL sub_020971D4(Main97024 *work);
BOOL sub_020971EC(Main97024 *work);

Work97024 *sub_02097024(const Input97024 *input, enum HeapID heapID) {
    Work97024 *work = Heap_Alloc(heapID, sizeof(Work97024));
    memset(work, 0, sizeof(Work97024));
    work->input = *input;
    work->menu = sub_02096C88(work, heapID);
    return work;
}

void sub_02097060(Work97024 *work) {
    sub_02096CF4(work->menu);
    sub_02096CC8(work->menu);
    Heap_Free(work);
}

u32 sub_02097078(Work97024 *work) {
    return work->result;
}

void *sub_0209707C(FieldSystem *fieldSystem) {
    Main97024 *work = Heap_Alloc((enum HeapID)11, sizeof(Main97024));
    memset(work, 0, sizeof(Main97024));
    work->fieldSystem = fieldSystem;
    work->saveData = fieldSystem->saveData;
    work->unk14 = fieldSystem->unk84;
    work->options = Save_PlayerData_GetOptionsAddr(fieldSystem->saveData);
    work->gameStats = Save_GameStats_Get(fieldSystem->saveData);
    work->frame = Options_GetFrame(work->options);
    work->fieldSystem2 = fieldSystem;
    return work;
}

BOOL sub_020970C0(void *data) {
    Main97024 *work = data;
    if (_02108EC0[work->state](work) == TRUE) {
        Heap_Free(work);
        return TRUE;
    }
    return FALSE;
}

BOOL sub_020970E4(Main97024 *work) {
    work->subwork = sub_02097024((const Input97024 *)work->sendData, (enum HeapID)11);
    work->state = 1;
    FieldSystem_LaunchApplication(work->fieldSystem, &_02108EA0, work->subwork);
    return FALSE;
}

BOOL sub_02097108(Main97024 *work) {
    if (!FieldSystem_ApplicationIsRunning(work->fieldSystem)) {
        if (sub_02097078(work->subwork) == 0) {
            work->state = 5;
        } else {
            sub_020398D4(1, 1);
            work->partyMenu = PartyMenu_LaunchApp_Unk5(work->fieldSystem, work->selection);
            work->subwork->unk0[0] = 1;
            work->state = 2;
        }
    }
    return FALSE;
}

BOOL sub_02097148(Main97024 *work) {
    u8 slot;
    if (!FieldSystem_ApplicationIsRunning(work->fieldSystem)) {
        slot = work->partyMenu->partySlot;
        Heap_Free(work->partyMenu);
        if (work->partyMenu->selectedAction == 1) {
            work->summary = PokemonSummary_CreateArgs(work->fieldSystem, (enum HeapID)3, 0);
            work->selection = slot;
            work->summary->partySlot = slot;
            PokemonSummary_LearnForget_LaunchApp(work->fieldSystem, work->summary);
            work->state = 3;
        } else {
            work->subwork->unk0[1] = slot;
            FieldSystem_LaunchApplication(work->fieldSystem, &_02108EB0, work->subwork);
            work->subwork->unk0[0] = 3;
            work->state = 4;
        }
    }
    return FALSE;
}

BOOL sub_020971AC(Main97024 *work) {
    if (!FieldSystem_ApplicationIsRunning(work->fieldSystem)) {
        Heap_Free(work->summary);
        work->partyMenu = PartyMenu_LaunchApp_Unk5(work->fieldSystem, work->selection);
        work->state = 2;
    }
    return FALSE;
}

BOOL sub_020971D4(Main97024 *work) {
    if (!FieldSystem_ApplicationIsRunning(work->fieldSystem)) {
        work->state = 5;
    }
    return FALSE;
}

BOOL sub_020971EC(Main97024 *work) {
    sub_02097060(work->subwork);
    return TRUE;
}
