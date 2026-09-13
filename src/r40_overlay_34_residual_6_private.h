#ifndef POKEHEARTGOLD_SOL_R40_OVERLAY34_RESIDUAL6_PRIVATE_H
#define POKEHEARTGOLD_SOL_R40_OVERLAY34_RESIDUAL6_PRIVATE_H

#include "global.h"

#define PTR_AT(p, off) (*(void **)((u8 *)(p) + (off)))
#define U32_AT(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16_AT(p, off) (*(u16 *)((u8 *)(p) + (off)))

BOOL FieldSystem_TaskIsRunning(void *fieldSystem);
int ov34_0225DE94(void *work);
int ov34_0225E020(void *work);
void ov34_0225E0E4(void *work);
void ov34_0225E1C4(void *bgConfig, void *arg1, void *entries, int skip, int count, void *out);
BOOL MailMsg_IsInit(void *mail);
BOOL MailMsg_Compare(void *a, void *b);
void ov34_0225E560(void *work);
void *sub_02035754(int index);
void *sub_02035798(int index);
void *sub_0205AA84(void *field);
u32 PlayerProfile_GetTrainerID(void *profile);
int PalPad_PlayerIdIsFriendOrMutual(void *palPad, u32 trainerId);
void BufferPlayersName(void *format, int field, void *profile);
void *String_New(u32 size, int heapId);
void *PalPad_GetNthEntry(void *palPad, int index);
void CopyU16ArrayToString(void *string, const u16 *source);
u8 PalPadEntry_GetFromUnk68Array(void *palPad, int index);
void BufferString(void *format, int field, void *string, int a3, int a4, int a5);
void String_Delete(void *string);
void *ReadMsgData_ExpandPlaceholders(void *format, void *msgData, int msgNo, int heapId);
void *PlayerProfile_GetNamePtr(void *profile);
int PlayerProfile_GetTrainerGender(void *profile);
void *MailMsg_GetExpandedString(void *mail, int heapId);

void ov34_0225E164(void *work);
BOOL ov34_0225E428(void *work, void *mail, u32 value);
void ov34_0225E4A8(void *work, void *profile, void *mail, u32 trainerId);
void ov34_0225E4F8(void *work);
void *ov34_0225E2BC(void *palPad, u32 trainerId, void *format, void *msgData, void *profile);
void ov34_0225E348(void *work, u32 trainerId, void *mail, void *profile);

#endif
