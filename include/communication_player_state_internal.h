#ifndef POKEHEARTGOLD_COMMUNICATION_PLAYER_STATE_INTERNAL_H
#define POKEHEARTGOLD_COMMUNICATION_PLAYER_STATE_INTERNAL_H

#include "global.h"

typedef struct Unk02034354_Entry {
    /* 0x00 */ u8 rules[0x20];
    /* 0x20 */ u8 profile[0x20];
    /* 0x40 */ u8 token[0xC];
    /* 0x4C */ u8 unk4C[0x10];
    /* 0x5C */ u8 mac[6];
    /* 0x62 */ u8 index;
    /* 0x63 */ u8 country;
    /* 0x64 */ u8 region;
    /* 0x65 */ u8 unk65;
    /* 0x66 */ u8 pad66[2];
} Unk02034354_Entry;

typedef struct Unk02034354_Score {
    /* 0x0 */ u16 a;
    /* 0x2 */ u16 b;
    /* 0x4 */ u16 c;
} Unk02034354_Score;

typedef struct Unk02034354 {
    /* 0x000 */ void *unk00;
    /* 0x004 */ void *rules;
    /* 0x008 */ void *save;
    /* 0x00C */ Unk02034354_Entry entries[8];
    /* 0x34C */ void *profiles[8];
    /* 0x36C */ Unk02034354_Score scores[8];
    /* 0x39C */ u8 status[8];
    /* 0x3A4 */ u8 unk3A4;
    /* 0x3A5 */ u8 unk3A5;
    /* 0x3A6 */ u8 curIdx;
    /* 0x3A7 */ u8 unk3A7;
} Unk02034354;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void *Save_PlayerData_GetProfile(void *save);
u32 PlayerProfile_sizeof(void);
void PlayerProfile_Copy(void *src, void *dst);
void PlayerProfile_Init(void *profile);
BOOL PlayerProfile_IsNameEmpty(void *profile);
void LinkBattleRuleset_Copy(void *src, void *dst);
void *sub_0202C08C(void *a);
void sub_0202C4F0(void *a, int b, int c, int d, int e);
void *sub_0202C6F4(void *save);
void *sub_0202C7E0(void *a, int b, int c);
void *Save_FriendGroup_Get(void *save);
void *Save_WiFiHistory_Get(void *save);
u8 WifiHistory_GetPlayerCountry(void *wifi);
u8 WiFiHistory_GetPlayerRegion(void *wifi);
void sub_020357C4(void *a, int b);
void sub_02037030(int a, void *b, int c);
BOOL sub_020373B4(u16 netId);
int sub_02037454(void);
void sub_0203753C(int a, void *b, int c);
int sub_0203769C(void);
int sub_02037824(int a);
int sub_020378AC(int netId);
int sub_0203A084(void *a, void *b, int *c);
u8 sub_0203A378(void *save, int a);
void DWC_CreateExchangeToken(void *a, void *b);

extern Unk02034354 *_021D4130;

void sub_02034354(void *save, void *rules);
void sub_020343E4(void);
BOOL sub_02034420(void);
void sub_02034434(void);
int sub_02034520(void);
void sub_02034524(void);
void sub_0203453C(int netId, int unused, void *packet);
void sub_020345D0(int netId, int unused, void *src);
BOOL sub_02034638(void);
u8 sub_020346D4(void);
void sub_020346E8(int netId);
BOOL sub_02034714(int netId);
BOOL sub_02034730(int netId);
BOOL sub_02034750(int netId);
void sub_0203476C(int netId);
int sub_02034780(void);
int sub_020347A0(void);
BOOL sub_020347CC(void);
void *sub_02034818(int netId);
void *sub_0203484C(int netId);
u8 sub_02034870(int a);
void *sub_02034884(int netId);
u8 sub_020348A8(int netId);
u8 sub_020348CC(int netId);
BOOL sub_020348F0(void);
void sub_02034960(int mode, int delta);
void sub_02034A20(void *save);
void sub_02034AC0(void *save, int b);
void sub_02034AEC(void *save, int b);
void sub_02034B00(void *a);

#endif
