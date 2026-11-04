#ifndef POKEHEARTGOLD_NINTENDO_WFC_CONNECT_H
#define POKEHEARTGOLD_NINTENDO_WFC_CONNECT_H

#include "frontier_data.h"
#include "options.h"
#include "overlay_manager.h"
#include "sav_system_info.h"
#include "save.h"

struct BattleRoomDownload;

typedef struct NintendoWifiConnectArgs {
    FrontierData *frontierData;
    struct BattleRoomDownload *battleRoomDownload;
    SysInfo *sysInfo;
    SaveData *saveData;
    Options *options;
    void *dwcUserData; // DWC user data, friend key source
    int mode;   // 0: download a Battle Room, 1: upload the record, 2: check the records of a rank
    s32 dwcProfileId; // default DWC profile id
    int incomplete;
    int connectNow; // nonzero: connect right away
} NintendoWifiConnectArgs;

BOOL NintendoWfc_Init(OverlayManager *man, int *state);
BOOL NintendoWfc_Main(OverlayManager *man, int *state);
BOOL NintendoWfc_Exit(OverlayManager *man, int *state);

#endif // POKEHEARTGOLD_NINTENDO_WFC_CONNECT_H
