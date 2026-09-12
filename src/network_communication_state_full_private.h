#ifndef POKEHEARTGOLD_DWCACCOUNT_H
#define POKEHEARTGOLD_DWCACCOUNT_H

// This module predates the typed declarations in the current public headers.
// Keep its verified DWC and Wi-Fi interfaces private until those headers are
// reconciled for every caller.
#include "global.h"

typedef struct DWCUserData DWCUserData;

typedef struct DWCFriendData {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} DWCFriendData;

BOOL DWC_CheckValidConsole(DWCUserData *userData);
BOOL DWC_CheckHasProfile(DWCUserData *userData);
int DWC_IsValidFriendData(DWCFriendData *friendData);
void DWC_CreateExchangeToken(DWCUserData *, DWCFriendData *);
void DWC_CreateFriendKeyToken(DWCFriendData *friendData, u64 a1);
int DWC_CheckFriendKey(DWCUserData *userData, u64 a1);
int DWC_GetGsProfileId(DWCUserData *userData, DWCFriendData *friendData);
void DWC_CreateUserData(DWCUserData *userData, s32 a1);
void DWC_ClearDirtyFlag(DWCUserData *userData);
int DWC_CheckUserData(DWCUserData *userData);
int DWC_Init(int);
int DWC_IsEqualFriendData(DWCFriendData *friendData0, DWCFriendData *friendData1);

#endif // POKEHEARTGOLD_DWCACCOUNT_H

#ifndef POKEHEARTGOLD_UNK_0202C034_H
#define POKEHEARTGOLD_UNK_0202C034_H

#include "pm_string.h"
#include "save.h"

typedef struct UnkStruct_021D2230 UnkStruct_021D2230;
typedef UnkStruct_021D2230 WiFiList;

void sub_0202C6FC(SaveData *saveData);
void sub_0202C714(SaveData *saveData);
WiFiList *sub_0202C6F4(SaveData *saveData);
int sub_0202C2F8(WiFiList *a0);
DWCUserData *sub_0202C08C(WiFiList *a0);
u16 *sub_0202C254(WiFiList *a0, s32 a1);
u16 *sub_0202C298(WiFiList *a0, s32 a1);
s32 sub_0202C090(WiFiList *a0, s32 a1, s32 a2);
void sub_0202C46C(WiFiList *a0);
void sub_0202C4B0(WiFiList *a0, s32 a1);
u16 sub_0202C318(WiFiList *a0);
void sub_0202C190(WiFiList *a0, int a1, int a2, u32 a3);
void sub_0202C03C(WiFiList *a0);
void sub_0202C2B4(WiFiList *a0, int a1, String *a2);
void sub_0202C270(WiFiList *a0, int a1, String *a2);
DWCFriendData *sub_0202C23C(WiFiList *a0, int a1);

#endif // POKEHEARTGOLD_UNK_0202C034_H

#ifndef POKEHEARTGOLD_PR488_PRIVATE_H
#define POKEHEARTGOLD_PR488_PRIVATE_H

#include "overlay_44_02232E9C.h"
#include "save.h"
#include "save_wifi_history.h"
#include "unk_0202C034.h"

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

void sub_0203778C(MATHRandContext32 *arg0);
void sub_02034154(void);
void sub_02034DE0(void);
void sub_02036274(void);
int sub_02034FE8(void);
void sub_02036024(void);
void sub_02033A0C(int arg0);
void sub_02033AA4(int arg0);
void sub_02033908(int arg0);
void sub_02033ACC(int arg0);
void sub_0203A930(int arg0);
int ov00_021EC9D4(void);
s32 WM_GetLinkLevel(void);
int sub_02035664(void);
void sub_020350A8(int arg0);
void sub_0203622C(void);
void sub_02034B0C(PlayerProfile *playerProfile, int arg1);
int sub_02035ED8(int arg0, int arg1, int arg2, int arg3);
void sub_02035FD8(void);
int sub_02035F14(int arg0, int arg1, int arg2);
void sub_0203528C(void);
int sub_020360E4(int arg0);
void sub_0203624C(void);
int sub_020358B0(void);
int sub_020376F8(void);
int sub_020351AC(int arg0);
void sub_020376E0(int arg0, u8 *arg1);
void sub_02035FE4(void);
void sub_02037184(int arg0, u8 *arg1);
void sub_02033A7C(void *arg0);
void sub_02037988(void);
void ov00_021E6CB8(void);
int ov00_021E5E54(int arg0);
void sub_0203786C(int arg0);
u32 ov00_021E6D7C(s32 arg0, s32 arg1, s32 arg2);
s32 sub_02033FC4(u8 arg0);
void ov00_021E5C84(void (*func0)(), void (*func1)());
s32 ov00_021E6690(void);
int ov00_021E6BE4(int arg0);
int ov00_021E6C68(void);
int ov00_021EC11C(s32 *arg0, s32 *arg1);
void ov00_021EC210(void);
s32 ov00_021E5B6C(void);
int ov45_0222E804(int arg0);
void ov00_021E5900(SaveData *saveData, int arg1, int arg2, int arg3);
void ov00_021E6CA4(void (*func)(u32));
int ov45_0222F274(int arg0);
void ov45_0222F028(int arg0, int arg1);
void ov45_0222F350(int arg0);
void sub_020356EC(int arg0);
s32 sub_02034044(void);
BOOL sub_02035630(void);
BOOL sub_02034BE4(void);
int sub_02033974(void);
void sub_020378E4(int arg0);
int ov45_0222E8F4(void);
int ov45_0222E6C8(void);
int ov45_0222E944(void);
int sub_020348A8(int arg0);
int sub_020348CC(int arg0);
void LoadOVY38(void);
void UnloadOVY38(void);
void sub_02034A20(SaveData *saveData);

s32 sub_02037C94(void);
void sub_02037C98(SaveData *saveData, s8 arg1);
void sub_02037D2C(void);
BOOL sub_02037D78(void);
void sub_02037D8C(SaveData *saveData, s8 arg1, s8 arg2, s32 arg3);
void sub_02037DD4(SaveData *saveData, s8 arg1, s8 arg2, s32 arg3);
void sub_02037E1C(s8 arg0);
void sub_02037E38(void);
void sub_02037E4C(void);
void sub_02037E9C(void);
s32 sub_02037EC8(void);
void sub_02037F18(SaveData *saveData);
void sub_02037F64(s8 arg0);
s32 sub_02037F94(void);
s32 sub_02037FCC(void);
s32 sub_02038070(void);
void sub_02038094(void);
void sub_02037EC0(u32 arg0);
void sub_02037FF0(void);
void sub_020380B0(void);
void sub_020380CC(void);
void sub_020380F4(void);
void sub_02038104(void);
void sub_02038114(SaveData *saveData, s8 arg1);
void sub_02038148(SaveData *saveData, s8 arg1);
void sub_0203817C(void);
void sub_020381C0(void (*func)(), int arg1);
void sub_020381D0(void);
void sub_020381FC(void);
void sub_02038218(void);
void sub_02038260(void);
void sub_0203827C(void);
void sub_02038294(void);
void sub_020382DC(void);
void sub_020382E4(void);
void sub_0203830C(void);
void sub_02038344(void);
void sub_02038358(void);
void sub_02038398(void);
void sub_020383B0(void);
void sub_020383C4(void);
void sub_02038404(void);
void sub_02038408(void);
void sub_02038418(void);
void sub_02038460(void);
void sub_0203847C(void);
void sub_020384B4(void);
void sub_02038508(void);
void sub_02038538(void);
void sub_02038550(void);
void sub_020385B8(void);
void sub_02038610(void);
void sub_02038668(void);
void sub_02038680(void);
void sub_020386AC(void);
void sub_02038710(void);
void sub_0203876C(void);
void sub_020387E8(void);
void sub_02038800(void);
void sub_02038804(void);
void sub_02038854(void);
void sub_020388A8(void);
void sub_020388E0(void);
void sub_02038918(s8 arg0);
void sub_0203893C(void);
void sub_0203894C(s8 arg0);
void sub_0203897C(void);
void sub_0203898C(s8 arg0);
void sub_020389BC(void);
void sub_020389D4(void);
void sub_02038A10(void);
void sub_02038A94(void);
void sub_02038B3C(u8 arg0, u8 arg1, u8 *arg2);
void sub_02038B9C(u32 arg0, u32 arg1, u8 *arg2);
s32 sub_02038C18(void);
void sub_02038C1C(s8 arg0);
void sub_02038C34(void);
void sub_02038C3C(u32 arg0, s32 arg1);
void sub_02038CC4(void);
void sub_02038CE8(void);
void sub_02038D28(SaveData *saveData);
void sub_02038D64(void);
u8 sub_02038D80(void);
BOOL sub_02038D90(void);
void sub_02038E00(void);
void sub_02038E48(void);
void sub_02038E90(void);
void sub_02038E94(void);
void sub_02038EB0(void);
void sub_02038EB4(void);
void sub_02038EB8(void);

void sub_02038F74(u32 arg0, s32 arg1, s32 arg2);
void sub_02038F9C(void);
void sub_0203900C(void);
s32 sub_02039080(s32 arg0);
s32 sub_020390C4(void);
void sub_02039144(void);
void sub_020391D0(void);
void sub_02039220(void);
u8 sub_02039264(void);
BOOL sub_02039274(void);
BOOL sub_020392A0(void);
u32 *sub_020392D8(void);
void sub_020392F4(void);
void sub_02039330(void);
void sub_02039358(void);
void sub_02039378(void);
void sub_020393B4(void);
BOOL sub_020393C8(void);
void sub_02039418(SaveData *saveData);
void sub_0203946C(void);
void sub_020394A0(SaveData *saveData);
void sub_020394F4(void);
void sub_02039528(SaveData *saveData);
void sub_0203957C(void);
BOOL sub_020395B0(void);
void sub_0203960C(void);
void sub_02039694(void);
UnkStruct_ov44_0223197C *sub_020396FC(SaveData *saveData, u32 arg1);
void sub_0203976C(SaveData *saveData, s32 arg1);
void sub_020397C8(void);
u8 sub_020397E4(void);
BOOL sub_020397FC(void);
void sub_0203981C(s32 arg0);
void sub_0203986C(void);
s32 sub_0203988C(void);
UnkStruct_ov44_0223197C *sub_020398C8(void);
void sub_020398D4(s8 arg0, s8 arg1);
BOOL sub_02039918(void);
u8 sub_0203993C(void);
u8 sub_02039954(void);
void sub_0203996C(void *arg0);
void sub_02039980(void *arg0);
int sub_02039998(void);

void sub_020399A4(s8 arg0);
u8 sub_020399B8(void);
void sub_020399DC(u32 errorCode);
void sub_020399EC(void);
void sub_020399FC(void);
void sub_02039A00(void);
BOOL sub_02039AA4(void);
BOOL sub_02039AD8(int arg0);
void sub_02039AF8(void);
void sub_02039B18(void);
void sub_02039B38(void);
void sub_02039B58(void);
void sub_02039B7C(void);
void sub_02039BA0(void);
void sub_02039C14(void);
void sub_02039C60(void);
s32 sub_02039C6C(s32 arg0);
s32 sub_02039D08(void);
int sub_02039D3C(void);
void sub_02039D54(s32 *arg0);
void sub_02039D78(void);
void sub_02039D8C(void);
void sub_02039DC0(void);
void sub_02039DC4(void);
void sub_02039DE4(void);
void sub_02039E30(void);
void sub_02039E7C(void);
void sub_02039E9C(void);
void sub_02039EAC(s32 *arg0);
s32 sub_02039EB4(SaveData *saveData, s32 arg1, u32 *arg2);
void sub_02039F68(SaveWiFiHistory *arg0);
void sub_02039FB8(SaveWiFiHistory *arg0, s32 arg1, s32 arg2, u8 arg3);
s32 sub_02039FD8(enum HeapID heapID);
s32 sub_02039FFC(enum HeapID heapID);
void sub_0203A01C(WiFiList *arg0);
int sub_0203A040(WiFiList *arg0);
BOOL sub_0203A05C(SaveData *saveData);
s32 sub_0203A084(SaveData *saveData, DWCFriendData *arg1, s32 *arg2);
int sub_0203A128(SaveData *saveData, u64 arg1, int *arg2);
s32 sub_0203A1C4(SaveData *saveData, s32 *arg1, enum HeapID heapID);
void sub_0203A280(SaveData *saveData, s32 arg1, s32 arg2, enum HeapID heapID, u32 arg4);
s32 sub_0203A378(SaveData *saveData, s32 arg1);

int ov45_0222F464(void);
void ov45_0222F154(void);
void ov45_0222F70C(void);
void ov45_0222E91C(void);
int ov45_0222F254(void);

DWCFriendData *sub_0203484C(int arg0);
u16 *sub_02034884(int arg0);
void sub_020367A8(void);
void sub_02036904(void);
void sub_020369CC(void);

#endif // POKEHEARTGOLD_PR488_PRIVATE_H
