#ifndef POKEHEARTGOLD_OVERLAY02_FOLLOW_MON_INTERACTION_R60_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY02_FOLLOW_MON_INTERACTION_R60_PRIVATE_H

#include "global.h"

#include "constants/sndseq.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct InteractionMove {
    u8 unk0;
    u8 duration;
    s8 dx;
    s8 facing;
    s8 dz;
    u8 enabled;
    u8 pad[2];
} InteractionMove;

typedef struct SmallMoveEnv {
    u16 count;
    u16 current;
    void *movement;
} SmallMoveEnv;

typedef struct FollowInteractionEnv {
    u8 pad_000[0x818];
    InteractionMove moves[10];
    u8 state;
    u8 unk_869;
    u8 frame;
    u8 moveIndex;
} FollowInteractionEnv;

extern void *NewMsgDataFromNarc(int, int, int, int);
extern void DestroyMsgData(void *);
extern void *MessageFormat_New(int);
extern void MessageFormat_Delete(void *);
extern void *NewString_ReadMsgData(void *, int);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void String_Delete(void *);
extern void BufferPlayersName(void *, int, void *);
extern void BufferFashionName(void *, int, int);
extern void BufferFashionNameWithArticle(void *, int, int);
extern void BufferBoxMonNickname(void *, int, void *);
extern void BufferBoxMonSpeciesName(void *, int, void *);
extern void BufferLocationName(void *, int, int);
extern void BufferItemName(void *, int, int);
extern void *Save_PlayerData_GetProfile(void *);
extern void *SaveArray_Party_Get(void *);
extern void *GetFirstAliveMonInParty_CrashIfNone(void *);
extern void *Mon_GetBoxMon(void *);
extern int GetMonData(void *, int, void *);
extern void SetMonData(void *, int, void *);
extern int MapHeader_GetMapSec(int);
extern void *Save_FashionData_Get(void *);
extern void *Save_FashionData_GetFashionCase(void *);
extern int sub_0202BA2C(void *, int, int);
extern void FashionCase_GiveFashionItem(void *, int, int);
extern void *Save_VarsFlags_Get(void *);
extern void SetFlag99C(void *);

extern void MapObject_CopyPositionVector(void *, VecFx32 *);
extern void MapObject_SetPositionVector(void *, VecFx32 *);
extern int MapObject_GetFacingDirection(void *);
extern void MapObject_SetFacingDirectionDirect(void *, int);
extern int MapObject_GetXCoord(void *);
extern int MapObject_GetZCoord(void *);
extern void *MapObject_GetFieldSystem(void *);
extern void MapObject_PauseMovement(void *);
extern void MapObject_UnpauseMovement(void *);
extern int MapObject_AreBitsSetForMovementScriptInit(void *);
extern int FollowMon_GetSpecies(void *);
extern void *FollowMon_GetMapObject(void *);

extern void ov01_021F8F74(void *, s8);
extern int ov01_022055DC(void *);
extern void ov01_021FF0E4(void *, int, int, int, int);
extern void ov01_021FF964(void *, int, int, int, int);
extern void ov01_021F8F68(void *, int);
extern void ov01_021F8F08(void *, int);
extern int GetMetatileBehavior(void *, int, int);
extern int MetatileBehavior_IsTallGrass(u8);
extern int MetatileBehavior_IsVeryTallGrass(u8);
extern void GF_AssertFail(void);
extern void ReadWholeNarcMemberByIdPair(void *, int, int);

extern void PlaySE(int);
extern void PlayCryEx(int, int, int, int, int, int);
extern void *Heap_AllocAtEnd(int, int);
extern void Heap_Free(void *);
extern void TaskManager_Call(void *, void *, void *);
extern void *TaskManager_GetFieldSystem(void *);
extern void *TaskManager_GetEnvironment(void *);
extern int *TaskManager_GetStatePtr(void *);
extern void *EventObjectMovementMan_Create(void *, const void *);
extern int EventObjectMovementMan_IsFinish(void *);
extern void EventObjectMovementMan_Delete(void *);

extern s8 FieldSystem_UnkSub108_GetMonMood(void *);
extern void FieldSystem_UnkSub108_SetMonMood(void *, s8);
extern void FollowMon_PlaceholdersSet(void *, void *);
extern void ov02_0224FE70(void *, void *, u8);
extern void ov02_0224FF04(void *, int, int *, int *);
extern int ov02_0224FFD8(void *);
extern int ov02_0224FF5C(void *, void *);
extern void ov02_0224FD9C(const InteractionMove *, void *);
extern void ov02_0224FDF8(const InteractionMove *, u32, int, int);
extern int ov02_0224EF94(void *);
extern void ov02_0224F880(void *, int);
extern int ov02_0224F8FC(void *, void *);
extern void ov02_0224FC08(void *, void *, int);
extern const u8 ov02_02253A70[];
extern int ov02_022507E8(void *);
extern void FollowMon_ExpandInteractionMessage(void *, void *, int, int);
extern void ov02_0224FCE0(void *, void *, int, int, u8);
extern void ov02_0224FE40(void *, const InteractionMove *, void *);
extern int ov02_02250004(void *, void *, int);
extern void ov02_02250504(void *);
extern int ov02_02250594(int, int);
extern int ov02_02250628(int, int);
extern int ov02_022506D4(u32, u32);
extern int ov02_02250738(int, int);
extern int ov02_02250780(void *, int);
extern void ov02_022507B4(void *, u16);

#endif
