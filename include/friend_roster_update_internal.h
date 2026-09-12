#ifndef POKEHEARTGOLD_FRIEND_ROSTER_UPDATE_INTERNAL_H
#define POKEHEARTGOLD_FRIEND_ROSTER_UPDATE_INTERNAL_H

#include "global.h"

typedef struct FriendToken {
    u32 data[3];
} FriendToken;
typedef struct String String;

void *sub_0202C6F4(void *);
void *sub_0202C08C(void *);
void *sub_0202C23C(void *, int);
BOOL DWC_IsValidFriendData(void *);
BOOL DWC_IsEqualFriendData(void *, void *);
int DWC_GetGsProfileId(void *, void *);
BOOL DWC_CheckFriendKey(void *, u64);
void DWC_CreateFriendKeyToken(FriendToken *, u64);
void *sub_02034818(int);
void *sub_0203484C(int);
void *sub_02034884(int);
void MI_CpuCopy8(const void *, void *, u32);
String *PlayerProfile_GetPlayerName_NewString(void *, int);
void sub_0202C270(void *, int, String *);
void String_Delete(String *);
u8 PlayerProfile_GetTrainerGender(void *);
u32 PlayerProfile_GetTrainerID(void *);
void sub_0202C190(void *, int, int, int);
int sub_0202C090(void *, int, int);
String *String_New(u32, int);
void CopyU16ArrayToString(String *, const u16 *);
void sub_0202C2B4(void *, int, String *);
u8 PlayerProfile_GetAvatar(void *);
void sub_02034A20(void *);
int sub_02037454(void);
int sub_0203769C(void);
int sub_02039998(void);
void GF_AssertFail(void);

int sub_0203A084(void *, void *, int *);
int sub_0203A128(void *, u64, int *);
BOOL sub_0203A1C4(void *, int *, int);
void sub_0203A280(void *, int, int, int, int);

#endif
