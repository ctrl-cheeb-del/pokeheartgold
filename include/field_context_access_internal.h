#ifndef POKEHEARTGOLD_FIELD_CONTEXT_ACCESS_INTERNAL_H
#define POKEHEARTGOLD_FIELD_CONTEXT_ACCESS_INTERNAL_H
#include "global.h"

typedef struct TrainerCardBuffer {
    u8 raw[0x66c];
} TrainerCardBuffer;
typedef struct TrainerCardTaskEnv {
    s32 state;
    void *source;
    TrainerCardBuffer copy;
    u8 tail[0x10];
} TrainerCardTaskEnv;
typedef char TrainerCardTaskEnv_SizeCheck[(sizeof(TrainerCardTaskEnv) == 0x684) ? 1 : -1];

void *Heap_Alloc(u32, u32);
void *Heap_AllocAtEnd(u32, u32);
void Heap_Free(void *);
void *FieldSystem_GetSaveData(void *);
void *Save_PlayerData_GetProfile(void *);
u8 PlayerProfile_GetLanguage(void *);
u32 PlayerProfile_GetTrainerID_VisibleHalf(void *);
u32 PlayerProfile_GetTrainerGender(void *);
const u16 *PlayerProfile_GetNamePtr(void *);
u32 PlayerProfile_GetMoney(void *);
void *Save_GameStats_Get(void *);
void *Save_VarsFlags_Get(void *);
void *Save_Frontier_GetStatic(void *);
BOOL CheckGameClearFlag(void *);
BOOL Pokedex_NationalDexIsComplete(void *);
u32 Pokedex_CountDexOwned(void *);
BOOL Pokedex_IsEnabled(void *);
void *Save_Pokedex_Get(void *);
u32 FrontierSave_GetStat(void *, int, int);
BOOL Save_VarsFlags_CheckFlagInArray(void *, int);
void CopyU16StringArrayN(u16 *, const u16 *, u32);
u32 GetIGTHours(void *);
u32 GetIGTMinutes(void *);
void *Save_PlayerData_GetIGTAddr(void *);
void sub_02055624(void *, void *, void *);
void FieldSystem_GetGameClearTime(void *, void *, void *);
u32 GameStats_GetScore(void *);
u32 GameStats_GetCapped(void *, int);
BOOL TrainerCard_SignatureExists(void *);
const void *TrainerCard_GetSignature(void *);
void MI_CpuCopy8(const void *, void *, u32);
void *Save_TrainerCard_Get(void *);
u32 *TrainerCard_GetBadgeShininessArr(void *);
BOOL PlayerProfile_TestBadgeFlag(void *, int);
void *sub_0205ABD8(void *);
void TaskManager_Call(void *, BOOL (*)(void *), void *);
void *TaskManager_GetFieldSystem(void *);
void *TaskManager_GetEnvironment(void *);
void sub_0205AC70(void *);
void sub_0205AC4C(void *);
void TrainerCard_LaunchApp(void *, void *);
BOOL FieldSystem_ApplicationIsRunning(void *);

void *sub_020691A8(u32);
void sub_02068FC8(u32, u8, u8, u8, void *, TrainerCardBuffer *);
void *sub_020691C4(u32);
void sub_020691E0(void *);
u8 sub_020691E8(void *);
void sub_020692A0(u32, u32, u32, u32, u8, TrainerCardBuffer *);
void sub_020692C4(u32, u8, const u16 *, u32, u32, u32, u32, TrainerCardBuffer *);
void sub_02069308(BOOL, void *, const u32 *, const u32 *, const u32 *, u8, TrainerCardBuffer *);
void sub_020693AC(u32, u32, u32, u32, u8, const void *, TrainerCardBuffer *);
void sub_0206940C(void *, void *, TrainerCardBuffer *);
void sub_02069464(void *);
BOOL sub_02069498(void *);
#endif
