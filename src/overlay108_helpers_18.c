#include "overlay_108_helpers_internal.h"

/* ---- external prototypes (never defined here) ---- */
extern void *OverlayManager_GetArgs(void *man);
extern void *OverlayManager_GetData(void *man);
extern void *OverlayManager_CreateAndGetData(void *man, u32 size, u32 heapId);
extern void OverlayManager_FreeData(void *man);
extern void Heap_Create(u32 parent, u32 child, u32 size);
extern void Heap_Destroy(u32 heapId);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void Sound_SetSceneAndPlayBGM(u32 scene, u32 a, u32 b);
extern void SafariZone_SetAreaSet(void *a, u32 b, void *c);
extern void *Save_VarsFlags_Get(void *save);
extern void ChangeFlag99D(void *varsFlags, u32 val);
extern void MenuInputStateMgr_SetState(void *mgr, u32 state);
extern void ListMenuItems_Delete(void *items);
extern void sub_020135AC(void *a);
extern void TouchscreenListMenuSpawner_Destroy(void *a);
extern void *TouchscreenListMenuSpawner_Create(u32 heapId, u32 a);
extern void *FontSystem_NewInit(u32 a, u32 heapId);
extern void TextOBJ_Destroy(void *a);
extern void sub_02021B5C(void *a);
extern void sub_02013938(void *a);
extern void SpriteSystem_Free(void *a);
extern void GF_DestroyVramTransferManager(void);
extern void GF_CreateVramTransferManager(u32 a, u32 heapId);
extern void *SpriteSystem_Alloc(u32 heapId);
extern void SpriteSystem_Init(void *a, const void *b, const void *c, u32 d);
extern void SpriteSystem_DestroySpriteManager(void *a, void *b);
extern void SpriteSystem_DrawSprites(void *a);
extern void SpriteSystem_TransferOam(void *a);
extern void SpriteList_RenderAndAnimateSprites(void *a);
extern void SpriteList_Delete(void *a);
extern void SpriteTransfer_DeleteAllCharTransferTasks(void *a);
extern void SpriteTransfer_DeleteAllPlttTransferTasks(void *a);
extern void Delete2DGfxResObjList(void *a);
extern void Destroy2DGfxResObjMan(void *a);
extern void Sprite_DeleteAndFreeResources(void *a);
extern void Sprite_SetDrawFlag(void *a, u32 b);
extern void Sprite_SetAnimCtrlSeq(void *a, u32 b);
extern void thunk_Sprite_Delete(void *a);
extern void thunk_Sprite_SetPriority(void *a, u32 b);
extern void thunk_ClearMainOAM(u32 heapId);
extern void thunk_ClearSubOAM(u32 heapId);
extern void YesNoPrompt_Destroy(void *a);
extern void RemoveWindow(void *a);
extern void ClearWindowTilemapAndCopyToVram(void *a);
extern void GfGfx_SetBanks(const void *a);

typedef struct Ov108Banks {
    u32 data[10];
} Ov108Banks;

extern const Ov108Banks ov108_021EA780;
extern const u32 ov108_021EA9A0;
extern const u32 ov108_021EA98C;

/* ---- forward prototypes for this file ---- */
BOOL SafariAreaCustomizer_Init(void *man, int *state);
BOOL SafariAreaCustomizer_Exit(void *man, int *state);
void ov108_021E59E4(SafariAreaCustomizer *s, void *args);
void ov108_021E5A48(SafariAreaCustomizer *s);
u32 ov108_021E5A78(SafariAreaCustomizer *s);
u32 ov108_021E5A8C(SafariAreaCustomizer *s);
u32 ov108_021E5C54(SafariAreaCustomizer *s);
u32 ov108_021E5D0C(SafariAreaCustomizer *s);
u32 ov108_021E5AA0(SafariAreaCustomizer *s);
u32 ov108_021E5AF0(SafariAreaCustomizer *s);
u32 ov108_021E5B48(SafariAreaCustomizer *s);
u32 ov108_021E5B98(SafariAreaCustomizer *s);
u32 ov108_021E5BFC(SafariAreaCustomizer *s);
u32 ov108_021E5D90(SafariAreaCustomizer *s);
u32 ov108_021E5F10(SafariAreaCustomizer *s);
u32 ov108_021E6010(SafariAreaCustomizer *s);
u32 ov108_021E6068(SafariAreaCustomizer *s);
u32 ov108_021E6240(SafariAreaCustomizer *s);
u32 ov108_021E62B4(SafariAreaCustomizer *s);
u32 ov108_021E63B8(SafariAreaCustomizer *s);
u32 ov108_021E64C0(SafariAreaCustomizer *s);
u32 ov108_021E66AC(SafariAreaCustomizer *s);
u32 ov108_021E6894(SafariAreaCustomizer *s);
u32 ov108_021E69A0(SafariAreaCustomizer *s);
void ov108_021E61E8(SafariAreaCustomizer *s);
void ov108_021E6238(SafariAreaCustomizer *s);
void ov108_021E6804(SafariAreaCustomizer *s);
void ov108_021E6850(SafariAreaCustomizer *s);
void ov108_021E6C48(void);
void ov108_021E6F58(SafariAreaCustomizer *s);
void ov108_021E71EC(SafariAreaCustomizer *s);
void ov108_021E72A4(SafariAreaCustomizer *s);
void ov108_021E72CC(SafariAreaCustomizer *s);
void ov108_021E730C(SafariAreaCustomizer *s);
void ov108_021E7510(SafariAreaCustomizer *s);
void ov108_021E7650(SafariAreaCustomizer *s);
void ov108_021E7700(SafariAreaCustomizer *s, u32 a, u32 b, u32 c);
void ov108_021E78C0(SafariAreaCustomizer *s, u32 idx, u32 anim, u32 on);
void ov108_021E78F4(SafariAreaCustomizer *s, u32 idx, u32 anim);
void ov108_021E838C(SafariAreaCustomizer *s);
void ov108_021E83C8(SafariAreaCustomizer *s);
void ov108_021E83F0(SafariAreaCustomizer *s);
void ov108_021E844C(SafariAreaCustomizer *s);
void ov108_021E846C(SafariAreaCustomizer *s);
void ov108_021E8490(SafariAreaCustomizer *s);
Ov108Sub *ov108_021E84A4(u32 heapId, u16 a, u16 b, void *c);
void ov108_021E84DC(Ov108Sub *s);
void ov108_021E852C(Ov108Sub *s);
void ov108_021E853C(Ov108Sub *s, void *a);
void ov108_021E8674(void *sprite);
void ov108_021E867C(Ov108Sub *s);
void ov108_021E8718(Ov108Sub *s);

/* ================= definitions ================= */

































/* ================= batch 2 ================= */

extern void *Save_SafariZone_Get(void *save);
extern void SafariZone_CopyAreaSet(void *a, u32 b, void *c);
extern void *Save_PlayerData_GetOptionsAddr(void *save);
extern u8 Options_GetTextSpeed(void *opts);
extern u8 Options_GetFrame(void *opts);
extern u32 MenuInputStateMgr_GetState(void *mgr);
extern u32 SafariZone_GetObjectUnlockLevel(void *a);
extern void BeginNormalPaletteFade(u32 a, s32 b, s32 c, u16 d, u32 e, u32 f, u32 heapId);
extern void GfGfx_EngineATogglePlanes(u32 a, u32 b);
extern void GfGfx_EngineBTogglePlanes(u32 a, u32 b);
extern BOOL IsPaletteFadeFinished(void);
extern u32 System_GetTouchHeld(void);
extern void *SpriteManager_New(void *a);
extern void SpriteSystem_InitSprites(void *a, void *b, u32 c);
extern void sub_0200D2A4(void *a, void *b, const void *c, u32 d, u32 e);
extern void *SpriteManager_GetSpriteList(void *a);
extern const u32 ov108_021EA97C;

typedef struct Ov108System {
    u8 pad00[0x44];
    u32 unk44;
} Ov108System;

extern Ov108System gSystem;

BOOL SafariAreaCustomizer_Main(void *man, int *state);
u32 ov108_021E5DB8(SafariAreaCustomizer *s);
u32 ov108_021E5E68(SafariAreaCustomizer *s);
u32 ov108_021E5F38(SafariAreaCustomizer *s);
u32 ov108_021E6090(SafariAreaCustomizer *s);
void ov108_021E81A8(SafariAreaCustomizer *s);
u32 ov108_021E8270(SafariAreaCustomizer *s);
void ov108_021E7C5C(SafariAreaCustomizer *s);
void ov108_021E7CD8(SafariAreaCustomizer *s, u32 a);
void ov108_021E767C(SafariAreaCustomizer *s, u32 a);
void ov108_021E7BFC(SafariAreaCustomizer *s);

void ov108_021E8718(Ov108Sub *s) {
    u32 i;

    SpriteList_Delete(s->spriteList);
    SpriteTransfer_DeleteAllCharTransferTasks(s->resList[0]);
    SpriteTransfer_DeleteAllPlttTransferTasks(s->resList[1]);
    for (i = 0; i < 4; i++) {
        Delete2DGfxResObjList(s->resList[i]);
        Destroy2DGfxResObjMan(s->resMan[i]);
    }
}
