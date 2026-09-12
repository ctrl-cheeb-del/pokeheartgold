#ifndef POKEHEARTGOLD_OVERLAY02_ROAMER_POKECENTER_R14_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY02_ROAMER_POKECENTER_R14_PRIVATE_H
#include <nnsys.h>

#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void HeapExp_FndInitAllocator(void *, u32, u32);
void *AllocAtEndAndReadWholeNarcMemberByIdPair(u32, u32, u32);
void ov01_021FBD38(void *, void *);
void ov01_021FBDFC(void *);
void ov01_021F1448(void *);
void Field3dObject_InitFromModel(void *, void *);
void Field3dModelAnimation_LoadFromFilesystem(void *, void *, u32, u32, u32, void *);
void Field3dObject_AddAnimation(void *, void *);
void Field3dModelAnimation_Unload(void *, void *);
void MapObject_SetVisible(void *, u32);
void sub_0205F484(void *);
void ov02_0224B784(void *);
void *sub_02068D74(void *);
void sub_02068B48(void *);
void *Save_Roamers_Get(void *);
u8 GetRoamerIsActiveByIndex(void *, u8);
u32 Roamer_GetLocation(void *, u8);
u32 GetRoamMapByLocationIdx(u32);
void RoamerLocationUpdateRand(void *, u8);
void *Roamers_GetRoamMonStats(void *, u8);
u32 GetRoamerData(void *, u32);
void *RoamerSave_GetRepelAddr(void *);
void *Party_GetMonByIndex(void *, u32);
u32 GetMonData(void *, u32, void *);
u32 SpeciesToRoamerIdx(u16);
void RoamerMon_Init(void **);
void *Save_VarsFlags_Get(void *);
void sub_02066BE8(void *, u32, u32);
void SetRoamerData(void *, u32, u32);
u32 LCRandom(void);
void StartMapSceneScript(void *, u32, void *);
void *Heap_AllocAtEnd(u32, u32);
void GF_AssertFail(void);
BOOL sub_02054C20(void *, int, void **, int *);
u32 MapMatrix_GetWidth(void *);
void sub_02054DC8(int, int, VecFx32 *);
void MapProp_GetTranslation(VecFx32 *, void *);
void TaskManager_Call(void *, void *, void *);
BOOL PokecenterAnimRun(void *);
BOOL ov02_0224BE24(void *);
BOOL sub_02054C90(void *, int *, u32, void **, int *);
void *ov01_021FB9E0(void *);
void *MapProp_GetRenderSurface(void *);
void *MapProp_GetResModel(void *);
void MapPropOneShotAnimationManager_LoadPropAnimations(void *, void *, u32, u32, void *, void *, void *, u32, u32, u32);
extern volatile const int ov02_022536E8[2];
void ov02_0224B88C(void *);
void ov02_0224B90C(void *);
BOOL ov02_0224B938(void *);
BOOL ov02_0224B964(void *);
void ov02_BattleExit_HandleRoamerAction(void *, void *);
void ov02_RepelActiveRoamersFromMapNo(void *, u32);
void *ov02_0224BAA8(void *, u32);
BOOL PlayerStepEvent_RepelCounterDecrement(void *, void *);
void PokecenterAnimCreate(void *, u8);
void ov02_0224BDE8(void *, u8, u8);
void ov02_0224BF58(void *, u8);
#endif
