#ifndef POKEHEARTGOLD_FRONTIER_RUNTIME_INTERNAL_H
#define POKEHEARTGOLD_FRONTIER_RUNTIME_INTERNAL_H

#include "global.h"

typedef struct FrontierHeaderRecord {
    u16 value;
    u16 pad;
} FrontierHeaderRecord;

typedef struct FrontierRecord {
    u8 pad[12];
    u16 value;
    u8 rest[46];
} FrontierRecord;

typedef struct FrontierWork {
    void *launchArgs;
    void *childManager;
    void *childArgs;
    void (*childExit)(void *);
    u8 freeChildArgs;
    u8 pad_011[3];
    void *system;
    void *map;
    u8 pad_01c;
    u8 mapActive;
    u8 rebuildPending;
    u8 pad_01f;
    u16 taskId;
    u8 exitRequested;
    u8 pad_023;
    FrontierHeaderRecord headerRecords[24];
    FrontierRecord records[32];
    u8 pad_804[0x200];
    u16 extra[8];
    u8 pad_a14[0x40];
} FrontierWork;

typedef struct FrontierLaunchArgsInternal {
    void *data;
    u8 pad[0x1c];
    u8 mode;
} FrontierLaunchArgsInternal;

void GF_AssertFail(void);
void *OverlayManager_New(const void *, void *, int);
void *FrontierMap_Init(void);
void FrontierMap_Free(void *);
void HandleLoadOverlay(u32, int);
void UnloadOverlayByID(u32);
extern u8 SDK_OVERLAY_OVY_80_ID[];
extern u8 SDK_OVERLAY_OVY_81_ID[];
extern u8 SDK_OVERLAY_OVY_42_ID[];
void *OverlayManager_GetData(void *);
void OverlayManager_FreeData(void *);
void ov80_0222A920(void *);
void *OverlayManager_CreateAndGetData(void *, u32, int);
void *OverlayManager_GetArgs(void *);
void *FrontierSystem_Create(FrontierWork *, int, u8);
void FrontierSystem_AddTask(void *, u8, u16);
int FrontierSystem_Main(void *);
int OverlayManager_Run(void *);
void OverlayManager_Delete(void *);
void Heap_Free(void *);
void ov80_022389C4(void *);
void ov80_02238A18(void *);
void ov80_0222AA7C(void *, u8, int);
void *ov80_0222AAD8(void *, int);
void ov80_0222AAF8(void *, void *);

void Frontier_CreateMap(FrontierWork *);
void Frontier_FreeMap(FrontierWork *);
void *Frontier_GetLaunchArgs(FrontierWork *);
void *sub_0209680C(FrontierWork *);
void *Frontier_GetData(FrontierWork *);
void Frontier_SetData(FrontierWork *, void *);
void Frontier_LaunchApplication(FrontierWork *, const void *, void *, u8, void (*)(void *));
void sub_0209684C(FrontierLaunchArgsInternal *);
void sub_02096854(FrontierWork *, u8, u16);
void *sub_02096864(FrontierWork *);
void *sub_02096868(FrontierWork *);
void *sub_0209686C(FrontierWork *, int);
void *sub_02096878(FrontierWork *);
void sub_02096884(FrontierWork *);
int Frontier_Exit(void *);
void sub_02096780(FrontierWork *);
void Frontier_LoadOverlays(void);
void Frontier_UnloadOverlays(void);
int Frontier_Init(void *);
int Frontier_Main(void *, int *);

#endif
