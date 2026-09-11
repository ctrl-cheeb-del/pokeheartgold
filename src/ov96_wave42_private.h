#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct Work {
    u8 d[0x100];
} Work;
#define P32(w, o) (*(void **)((w)->d + (o)))
typedef struct XCfg20 {
    u32 v[5];
} XCfg20;
typedef struct XCfg24 {
    u32 v[6];
} XCfg24;
typedef struct XCfg32 {
    u32 v[8];
} XCfg32;
extern const XCfg20 ov96_0221C2C4;
extern const XCfg24 ov96_0221C2D8;
extern const XCfg32 ov96_0221C2F0;
void ov96_021F8448(Work *);
void *SpriteSystem_Alloc(u32);
void *SpriteManager_New(void *);
void SpriteSystem_Init(void *, void *, void *, int);
void SpriteSystem_InitSprites(void *, void *, int);
void SpriteSystem_InitManagerWithCapacities(void *, void *, void *);
u32 PokeathlonCourse_GetCurrentParticipantIndex(void *);
u32 ov96_021E5F24(void *);
int PokeathlonCourse_GetParticipantCount(void *);
u32 ov96_021EEA80(void *);
BOOL ov96_021F85F4(void *);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
u32 PokeathlonCourse_GetMode(void *);
void *PokeathlonCourse_GetDataCopyArea(void *);
void *ov96_021E8A20(void *);
void GF_AssertFail(void);
void Sprite_DeleteAndFreeResources(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void *Heap_Alloc(int, u32);
void *FontSystem_NewInit(int, int);
void ov96_021F8E94(void *);
void Sprite_Delete(void *);
void sub_02013938(void *);
void RemoveWindow(void *);
void sub_020135AC(void *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Destroy2DGfxResObjMan(void *);
void SpriteList_Delete(void *);
void Heap_Free(void *);
void ov96_021F8728(void *);
void *SpriteSystem_NewSprite(void *, void *, void *);
void ov96_021F85A0(Work *);
void SpriteSystem_LoadCharResObj(void *, void *, int, int, int, int, int);
void SpriteSystem_LoadPlttResObj(void *, void *, int, int, int, int, int, int);
void SpriteSystem_LoadCellResObj(void *, void *, int, int, int, int);
void SpriteSystem_LoadAnimResObj(void *, void *, int, int, int, int);
void ov96_021F8528(Work *);
u32 ov96_021F83DC(void *);
u32 ov96_021F83FC(void *);
void ov96_021F84E4(Work *);
void *ov96_021F86E8(int, void *, void *);
#endif
