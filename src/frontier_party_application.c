#include "frontier_party_application_internal.h"

u32 sub_02066EDC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId) {
    PartyMenuArgs *args = Heap_AllocAtEnd(heapId, sizeof(PartyMenuArgs));
    SaveData *saveData = fieldSystem->saveData;
    u8 i;
    MI_CpuFill8(args, 0, sizeof(PartyMenuArgs));
    args->options = Save_PlayerData_GetOptionsAddr(saveData);
    args->party = SaveArray_Party_Get(saveData);
    args->bag = Save_Bag_Get(saveData);
    args->unk_25 = 0;
    args->context = env->context;
    args->minMonsToSelect = env->minMons;
    args->maxMonsToSelect = env->maxMons;
    args->maxLevel = env->maxLevel;
    args->partySlot = env->partySlot;
    args->menuInputStatePtr = &fieldSystem->menuInputState;
    for (i = 0; i < 6; i++) {
        args->selectedOrder[i] = env->selectedOrder[i];
    }
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PartyMenu, args);
    *env->runningApp = args;
    return 1;
}

u32 sub_02066F90(SummaryWaitEnv *env, FieldSystem *fieldSystem) {
    PartyMenuArgs *args;
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 1;
    }
    args = *env->runningApp;
    switch (args->partySlot) {
    case 7:
        env->result = 0;
        return 4;
    case 6:
        env->result = 1;
        return 4;
    }
    MI_CpuCopy8(args->selectedOrder, env->selectedOrder, 6);
    env->partySlot = args->partySlot;
    Heap_Free(args);
    *env->runningApp = NULL;
    return 2;
}

u32 sub_02066FEC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId) {
    SaveData *saveData = fieldSystem->saveData;
    PokemonSummaryArgs *args = Heap_AllocAtEnd(heapId, sizeof(PokemonSummaryArgs));
    MI_CpuFill8(args, 0, sizeof(PokemonSummaryArgs));
    args->options = Save_PlayerData_GetOptionsAddr(saveData);
    args->party = SaveArray_Party_Get(saveData);
    args->natDexEnabled = SaveArray_IsNatDexEnabled(saveData);
    args->unk2C = sub_02088288(saveData);
    args->unk11 = 1;
    args->partySlot = env->partySlot;
    args->partyCount = Party_GetCount(args->party);
    args->moveToLearn = 0;
    args->unk12 = env->summaryMode;
    args->ribbons = Save_SpecialRibbons_Get(saveData);
    args->menuInputStatePtr = &fieldSystem->menuInputState;
    args->isFlag982Set = sub_0208828C(saveData);
    sub_02089D40(args, _020FE4B0);
    sub_0208AD34(args, Save_PlayerData_GetProfile(saveData));
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PokemonSummary, args);
    *env->runningApp = args;
    return 3;
}
