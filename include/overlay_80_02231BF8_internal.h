#ifndef OVERLAY_80_02231BF8_PRIVATE_H
#define OVERLAY_80_02231BF8_PRIVATE_H

#include "global.h"

typedef struct FrontierScriptContextPrivate {
    void **frontier;
    u8 pad04[0x18];
    const u8 *scriptPtr;
    u8 pad20[0x58];
    u16 asyncValue;
} FrontierScriptContextPrivate;

typedef struct FrontierLaunchArgsPrivate {
    u8 pad00[8];
    void *saveData;
} FrontierLaunchArgsPrivate;

typedef struct FrontierDataPrivate {
    u8 pad0000[0x10];
    u8 type;
    u8 field11;
    u8 field12;
    u8 field13;
    u16 field14;
    u8 pad016[6];
    u32 result;
    u8 pad020[8];
    void *party;
    void *field2c;
    u8 pad030[0x9e8];
    u8 fieldA18;
    u8 fieldA19;
    u8 fieldA1A;
    u8 fieldA1B;
    u16 fieldA1C;
} FrontierDataPrivate;

typedef struct AppArgsPrivate {
    void *saveData;
    u8 type;
    u8 pad05[3];
    u8 a[4];
    u8 b[4];
    u8 c[4];
    u8 d[4];
    u32 data18;
    u32 data1c;
    u8 pad20[4];
    FrontierDataPrivate *frontierData;
    u16 field28;
    u8 pad2a[6];
} AppArgsPrivate;

u16 FrontierScript_ReadVar(FrontierScriptContextPrivate *);
u16 *FrontierScript_ReadVarPtr(FrontierScriptContextPrivate *);
u16 FrontierScriptContext_ReadHalfWord(FrontierScriptContextPrivate *);
void FrontierScriptContext_Pause(FrontierScriptContextPrivate *, BOOL (*)(FrontierScriptContextPrivate *));
FrontierLaunchArgsPrivate *Frontier_GetLaunchArgs(void *);
FrontierDataPrivate *Frontier_GetData(void *);
void Frontier_SetData(void *, u32);
void *Heap_Alloc(u32, u32);
void Heap_Free(void *);
void Frontier_LaunchApplication(void *, const void *, void *, u32, void (*)(AppArgsPrivate *));

extern const u8 ov80_0223BE24[];
extern const u8 ov80_0223BE34[];
extern const u8 ov80_0223BE44[];
extern const u8 gOverlayTemplate_Battle[];

u32 ov80_022324C4(void *, u32, u8, u32, u32, u32, u16 *);
void ov80_02232824(FrontierDataPrivate *, u32);
void ov80_02232ABC(FrontierDataPrivate *);
void ov80_02232AEC(FrontierDataPrivate *, AppArgsPrivate *);
void ov80_02232F00(FrontierDataPrivate *);
void ov80_02232F08(FrontierDataPrivate *);
void *ov80_02237B8C(FrontierDataPrivate *, FrontierLaunchArgsPrivate *);
void *Party_GetMonByIndex(void *, u32);
void Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(void *, u32, void *);
BOOL ov80_02237D8C(u8);
BOOL IsBattleResultWin(u32);
void BattleSetup_Delete(void *);
u32 ov80_02233280(FrontierDataPrivate *, u32, u32);
u16 *ov80_0222BE9C(FrontierScriptContextPrivate *, u16);
u16 *ov80_0222BE24(FrontierScriptContextPrivate *, u16);
void ov80_022332D0(void *, FrontierDataPrivate *);
void ov80_022333F0(void *, FrontierDataPrivate *);
void ov80_02233490(void *, FrontierDataPrivate *);
void *Save_Frontier_GetStatic(void *);
u32 sub_0205C1F0(u8);
u32 sub_0205C268(u32);
u32 FrontierSave_GetStat(void *, u32, u32);
void ov80_02237FA4(void *, u8, u32);
void ov80_022331E8(void *, u8, u32);
void ov80_0222F44C(FrontierScriptContextPrivate *, void *);

void ov80_02231E4C(AppArgsPrivate *, FrontierDataPrivate *);
void ov80_02231E94(AppArgsPrivate *);
BOOL ov80_02232318(FrontierScriptContextPrivate *);
BOOL ov80_02232368(FrontierScriptContextPrivate *);

BOOL FrtCmd_151(FrontierScriptContextPrivate *);
BOOL FrtCmd_152(FrontierScriptContextPrivate *);
BOOL FrtCmd_153(FrontierScriptContextPrivate *);
BOOL FrtCmd_154(FrontierScriptContextPrivate *);
BOOL FrtCmd_164(FrontierScriptContextPrivate *);
BOOL FrtCmd_155(FrontierScriptContextPrivate *);
BOOL FrtCmd_156(FrontierScriptContextPrivate *);
BOOL FrtCmd_157(FrontierScriptContextPrivate *);
BOOL FrtCmd_158(FrontierScriptContextPrivate *);
BOOL FrtCmd_159(FrontierScriptContextPrivate *);
BOOL FrtCmd_161(FrontierScriptContextPrivate *);
BOOL FrtCmd_162(FrontierScriptContextPrivate *);
BOOL FrtCmd_163(FrontierScriptContextPrivate *);
BOOL FrtCmd_165(FrontierScriptContextPrivate *);
BOOL FrtCmd_080(FrontierScriptContextPrivate *);
BOOL FrtCmd_081(FrontierScriptContextPrivate *);
BOOL FrtCmd_082(FrontierScriptContextPrivate *);
BOOL FrtCmd_166(FrontierScriptContextPrivate *);
BOOL FrtCmd_167(FrontierScriptContextPrivate *);
BOOL FrtCmd_168(FrontierScriptContextPrivate *);
BOOL FrtCmd_169(FrontierScriptContextPrivate *);

#endif
