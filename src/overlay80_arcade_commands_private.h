#ifndef TO46_OVERLAY_80_02235900_PRIVATE_H
#define TO46_OVERLAY_80_02235900_PRIVATE_H

#include "global.h"

typedef struct FrontierScriptContextPrivate {
    void **frontier;
    u8 pad04[0x18];
    const u8 *scriptPtr;
} FrontierScriptContextPrivate;

typedef struct FrontierLaunchArgsPrivate {
    u8 pad00[8];
    void *saveData;
} FrontierLaunchArgsPrivate;

typedef union ArcadeScriptBackup {
    u32 words[0xB4 / sizeof(u32)];
    struct {
        u8 pad00[0x58];
        u8 selection;
        u8 pad59[0x11];
        u8 order[4];
        u8 pad6E[8];
        u16 valuesA[4];
        u16 valuesB[4];
        u16 resultA;
        u16 resultB;
        u8 pad8A[0x2A];
    } fields;
} ArcadeScriptBackup;

typedef struct ArcadeDataPrivate {
    u8 pad000[0xE];
    u8 count;
    u8 facility;
    u8 flags;
    u8 pad011;
    u8 selection;
    u8 pad013[3];
    u16 resultA;
    u16 resultB;
    u8 pad01A[0x10];
    u8 order[4];
    u16 valuesA[4];
    u16 valuesB[4];
    u8 pad03E[0x896];
    u8 state;
} ArcadeDataPrivate;

FrontierLaunchArgsPrivate *Frontier_GetLaunchArgs(void *ctx);
ArcadeDataPrivate *Frontier_GetData(void *ctx);
void Frontier_SetData(void *ctx, ArcadeDataPrivate *data);
void ov80_02235FEC(void *data);
ArcadeDataPrivate *FrontierFieldSystem_New(void *saveData, u32 mode, u32 facility);
void ov80_0222A840(void *saveData);
u32 sub_0203769C(void);
u16 *FrontierScript_ReadVarPtr(FrontierScriptContextPrivate *ctx);
void *Save_Frontier_GetStatic(void *saveData);
u32 sub_0205C268(u32 value);
u16 FrontierSave_GetStat(void *frontierSave, u32 stat, u32 substat);
u32 sub_0205C11C(u32 value);
u32 sub_02030C5C(void *saveData);
void sub_0204F878(void *saveData, u32 value, u32 mode);
u32 ov80_022385D8(u32 index);
u32 ov80_02238610(u32 index);
void sub_02031108(void *frontierSave, u32 stat, u32 substat, u32 value);
void *Save_FrontierData_Get(void *saveData);
void sub_0202D57C(void *frontierData, u32 stat, u32 value);
u32 sub_0205C048(u32 a, u32 b);
void FrontierFieldSystem_SetRandomFrontierTrainers(ArcadeDataPrivate *data, void *saveData);
void *SaveArray_Party_Get(void *saveData);
void HealParty(void *party);
void sub_02096910(ArcadeDataPrivate *data);

BOOL FrtCmd_179(FrontierScriptContextPrivate *ctx);
BOOL FrtCmd_178(FrontierScriptContextPrivate *ctx);

#endif
