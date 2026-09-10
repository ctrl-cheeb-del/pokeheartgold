#ifndef OV01_022031C0_PRIVATE_H
#define OV01_022031C0_PRIVATE_H
#include "global.h"
typedef struct HeapAllocator {
    u8 raw[0x10];
} HeapAllocator;
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;
typedef struct Copy36 {
    u32 v[9];
} Copy36;
typedef struct SpawnArgs {
    Vec3 pos;
    void *a;
    void *ctx;
    void *b;
    void *mapObj;
    u16 h0, h1;
    s8 byte;
    u8 pad[3];
    Vec3 mapPos;
} SpawnArgs;
extern void *ov01_021F1430(u32, u32, u32, u32);
extern void ov01_021F1448(void *);
extern void *ov01_021F14B4(void *, u32, u32);
extern void HeapExp_FndInitAllocator(void *, u32, u32);
extern void ov01_021FBD38(void *, void *);
extern void Field3dObject_InitFromModel(void *, void *);
extern void Field3dModelAnimation_LoadFromFilesystem(void *, void *, u32, u32, u32, void *);
extern void Field3dObject_AddAnimation(void *, void *);
extern void ov01_021FBDFC(void *);
extern void Field3dModelAnimation_Unload(void *, void *);
extern int sub_0205F0F8(void *, u32, u32, u32);
extern void ov01_021F1640(void *);
extern void sub_02068DB8(void *, void *);
extern void Field3dObject_Draw(void *);
extern Copy36 *sub_02068D98(void *);
extern void sub_02068DA8(void *, Vec3 *);
extern u32 MapObject_GetSpriteID(void *);
extern u32 MapObject_GetID(void *);
extern u32 MapObject_GetMapID(void *);
extern u32 sub_0206121C(void *, Vec3 *);
extern void Field3dObject_SetPos(void *, Vec3 *);
extern void Field3dObject_SetActiveFlag(void *, BOOL);
extern void Field3dModelAnimation_FrameSet(void *, s32);
extern BOOL Field3dModelAnimation_FrameAdvanceAndCheck(void *, s32);
extern void sub_02069DC8(void *, s32);
extern void sub_0205F484(void *);
extern void *ov01_021F146C(void *);
extern void MapObject_CopyPositionVector(void *, Vec3 *);
extern void *ov01_021F1468(void *);
extern void *ov01_021F1450(void *, u32);
extern s32 MapObject_GetPriorityPlusValue(void *, s32);
extern void ov01_021F1620(void *, const void *, Vec3 *, u32, SpawnArgs *, s32);
extern const u8 ov01_022094C8[], ov01_022094DC[], ov01_022094F0[], ov01_02209504[];
extern const Vec3 ov01_022094B0;
extern void *FollowMon_GetMapObject(void *);
extern void *ov01_021F771C(void *);
extern BOOL ov01_022055DC(void *);
extern u32 MapObject_GetFacingDirection(void *);
extern void MapObject_SetPositionVector(void *, Vec3 *);
extern void sub_02023E78(void *, Vec3 *);
extern u32 sub_02023FB0(void *);
extern void GF_CreateNewVramTransferTask(u32, u32, void *, u32);
extern void MapObject_SetVisible(void *, BOOL);
extern u8 ov01_02209B18[];
extern const Vec3 ov01_022094BC;
extern void GF_AssertFail(void);
void *ov01_022031C0(void *);
void ov01_022031E8(void *);
void ov01_022031F8(void *);
void ov01_02203270(void *);
void ov01_0220329C(void *, u32);
void ov01_022033E0(void);
void ov01_022033E4(void *, void *);
BOOL ov01_0220335C(void *, void *);
BOOL ov01_022035DC(void *, void *);
BOOL ov01_02203820(void *, void *);
void ov01_022034B8(void *, void *);
void ov01_022034F8(void *, void *);
void ov01_022035A4(void *, void *);
void ov01_02203654(void *, void *);
void ov01_022037E8(void *, void *);
void ov01_02203890(void *, void *);
void ov01_022039BC(u32, void *, void **);
s32 ov01_022039E0(u32);
#endif
