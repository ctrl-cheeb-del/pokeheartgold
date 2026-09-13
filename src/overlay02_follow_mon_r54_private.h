#ifndef POKEHEARTGOLD_OV02_RESIDUAL_54_PRIVATE_H
#define POKEHEARTGOLD_OV02_RESIDUAL_54_PRIVATE_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

#define BF(x, b, w) ((u32)(x) << (32 - (b) - (w)) >> (32 - (w)))

typedef struct FollowMonInteractionEntry {
    u8 unk0;
    u8 f1_a : 4;
    u8 f1_b : 4;
    u8 f2_a : 3;
    u8 f2_b : 2;
    u8 f2_c : 3;
    u8 f3_a : 5;
    u8 f3_pad : 3;
    u8 f4_a : 5;
    u8 f4_b : 3;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u16 f8_a : 3;
    u16 f8_pad : 10;
    u16 f8_b : 3;
    u16 fa_a : 3;
    u16 fa_b : 3;
    u16 fa_c : 10;
    u16 unkC;
    u16 unkE;
    u8 f10_pad : 1;
    u8 f10_a : 2;
    u8 f10_b : 2;
    u8 f10_c : 3;
    u8 unk11;
    u16 unk12;
} FollowMonInteractionEntry;

typedef struct MonDataIdList {
    u32 ids[5];
} MonDataIdList;

extern const MonDataIdList ov02_02253A5C;
extern const u32 ov02_02253AC0[];

extern u16 LCRandom(void);
extern void GF_AssertFail(void);
extern int MapHeader_GetMapSec(int);
extern void ReadWholeNarcMemberByIdPair(void *, int, int);
extern void *SaveArray_Party_Get(void *);
extern void *GetFirstAliveMonInParty_CrashIfNone(void *);
extern int GetMonData(void *, int, void *);
extern u8 GetMonNature(void *);
extern int GetItemAttr(u16, int, int);
extern void *Save_VarsFlags_Get(void *);
extern int Save_VarsFlags_CheckFlagInArray(void *, int);
extern void *Save_LocalFieldData_Get(void *);
extern int LocalFieldData_GetWeatherType(void *);
extern void *FollowMon_GetMapObject(void *);
extern int MapObject_GetXCoord(void *);
extern int MapObject_GetZCoord(void *);
extern int MapObject_CheckActive(void *);
extern int MapObject_GetSpriteID(void *);
extern int MapObject_GetID(void *);
extern int MapObjectManager_GetObjectCount(void *);
extern void *MapObjectManager_GetObjects(void *);
extern void MapObjectArray_NextObject2(void *);
extern int PlayerAvatar_GetXCoord(void *);
extern int PlayerAvatar_GetZCoord(void *);
extern void *Field_GetBgEvents(void *);
extern int Field_GetNumBgEvents(void *);
extern int HiddenItemScriptNoToFlagId(int);
extern int FieldSystem_FlagCheck(void *, int);
extern int GetMetatileBehavior(void *, int, int);
extern int MetatileBehavior_CanGenerateWalkingEncounters(int);

extern int ov02_02250594(int, int);
extern int ov02_02250628(int, int);
extern int ov02_022506D4(u32, u32);
extern int ov02_02250738(int, int);
extern int ov02_0224F79C(int);
extern int ov02_0224F820(int);
extern void ov02_0224F644(void *, void *);
extern void ov02_0224F64C(void *, void *);
extern void ov02_0224F698(void *, void *);
extern void ov02_0224F6AC(void *, int, int, void *);
extern void ov02_0224F728(void *, void *);
extern void ov02_0224F76C(int, void *);

#endif
