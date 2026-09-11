#ifndef PRIVATE_OVERLAY_80_02229EE0_H
#define PRIVATE_OVERLAY_80_02229EE0_H
#include "global.h"

typedef struct TrainerRecord {
    u32 id;
    u16 species;
    u16 padding_06;
    u16 name[8];
    u16 value18;
    u16 value1A;
    u8 padding_1C[4];
    u16 values20[8];
} TrainerRecord;

void *AllocAndReadWholeNarcMemberByIdPair(int, int, int);
void ReadWholeNarcMemberByIdPair(void *, int, int);
void *NewMsgDataFromNarc(int, int, int, int);
void *NewString_ReadMsgData(void *, int);
void CopyStringToU16Array(void *, u16 *, int);
void String_Delete(void *);
void DestroyMsgData(void *);
void *Heap_Free(void *);
BOOL Party_AddMon(void *, void *);
int Sprite_GetAnimationNumber(void *);
void Sprite_SetAnimationFrame(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_UpdateAnim(void *, fx32);
int Sprite_GetAnimationFrame(void *);
void Sprite_SetMatrix(void *, const VecFx32 *);
int CalculateHpBarColor(int, int, int);
void CopyU16StringArray(const u16 *, u16 *);
u16 LCRandom(void);
int sub_0203769C(void);
void *sub_02034818(int);
void BufferPlayersName(void *, int, void *);
int PlayerProfile_GetTrainerGender(void *);
int PlayerProfile_GetVersion(void *);
void *Save_WiFiHistory_Get(void *);
void sub_02039F68(void *);
void *Save_PlayerData_GetProfile(void *);
u32 GetMonData(void *, int, void *);
void SetMonData(void *, int, void *);
void sub_0207217C(void *, void *, int, int, int, int);
int MapHeader_GetMapSec(int);
void MonSetTrainerMemo(void *, void *, int, int, int);

void *ov80_02229EE0(int, int, int);
void ov80_02229EF4(void *, int, int);
void *ov80_02229F04(TrainerRecord *, int, int, int);
void *ov80_02229F6C(void *, int, u32, int, int, u8, int, int, int);
void ov80_0222A334(void *, void *);
void ov80_0222A3BC(void *, void *, void *);
void ov80_0222A3D4(void *, int);
void ov80_0222A400(void *, int, int, int);
int ov80_0222A43C(int, int);
void ov80_0222A474(TrainerRecord *, int, int, int);
void ov80_0222A480(void *, TrainerRecord *, int, int);
void *ov80_0222A4EC(void *, int, int, int, int, int, int);
void ov80_0222A52C(void *, const u16 *, const u8 *, const u32 *, u32 *, int, int, int);
int ov80_0222A5A4(u32);
void ov80_0222A7CC(void *, int);
int ov80_0222A7EC(void *);
void ov80_0222A840(void *);

#endif
