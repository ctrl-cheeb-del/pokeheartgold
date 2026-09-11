#include "global.h"

typedef struct OverlayManager OverlayManager;
typedef struct {
    u8 raw[0x200];
} State;
typedef struct {
    void *allocation;
    void *header;
    void *pixels;
    u8 width, height;
} Scrn;

extern void *OverlayManager_GetData(OverlayManager *);
extern void OverlayManager_FreeData(OverlayManager *);
extern void Heap_Destroy(int);
extern void Main_SetVBlankIntrCB(void (*)(void *), void *);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void sub_0200FBF4(int, int);
extern void ResetVisibleHardwareWindows(int);
extern int Pokedex_GetSeenFormByIdx_Unown(void *, int, int);
extern void MenuInputStateMgr_SetState(void *, u32);
extern void sub_02021238(void);
extern void ov113_021E59F8(void);
extern void ov113_021E5B60(State *);
extern int ov113_021E5BB0(State *);
extern void ov113_021E5CF8(State *);
extern void ov113_021E5D28(State *);
extern void ov113_021E5D4C(State *);
extern void ov113_021E5D60(State *);
extern void ov113_021E5E64(State *, int);
extern void ov113_021E5DA4(State *, int);
extern int ov113_021E5F94(State *, u32 *);
extern void ov113_021E5F48(State *);
extern void ov113_021E5ED0(State *);
extern void ov113_021E6300(State *);
extern void ov113_021E650C(State *);
extern void ov113_021E6680(State *);
extern void ov113_021E671C(State *);
extern void ov113_021E6988(State *);
extern void ov113_021E62B0(State *);
extern void ov113_021E69A8(State *);
extern void ov113_021E6754(State *);
extern void ov113_021E66E4(State *);
extern void ov113_021E663C(State *);
extern void ov113_021E6490(State *);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern int Sprite_IsAnimated(void *);
extern int TouchscreenHitbox_FindHitboxAtTouchNew(const void *);
extern const u8 ov113_021E6B82[];
extern void SpriteSystem_TransferOam(void);
extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void FontID_Release(int);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void YesNoPrompt_Destroy(void *);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern void ov113_021E677C(State *);
extern void ov113_021E69CC(State *);
extern void ov113_021E6AB0(State *);
extern void ov113_021E6930(State *);
extern void Sprite_DeleteAndFreeResources(void *);
extern void Sprite_Delete(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_DestroySpriteManager(void *, void *);
extern void NARC_Delete(void *);
extern void SpriteSystem_Free(void *);
extern void GF_DestroyVramTransferManager(void);
extern void thunk_ClearMainOAM(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void *, int, int, void **, int);
extern const u32 ov113_021E6BD0[];
extern const u32 ov113_021E6CD0[];
extern void GfGfx_SetBanks(const void *);
int UnownReport_Exit(OverlayManager *, int *);
int ov113_021E5A48(void *, u8 *);
void ov113_021E5C60(State *);
int ov113_021E5EC4(State *);
int ov113_021E5D80(State *);
int ov113_021E5B70(State *);
void ov113_021E62E0(void);
void ov113_021E6B1C(State *);
void ov113_021E64DC(Scrn *, void *, int, int);
void ov113_021E6274(void *, void *, int, int, u16);
void ov113_021E629C(void *, void *, int, u16);

void ov113_021E6754(State *p) {
    int i = 0;
    u8 *w = (u8 *)p;
    w += 0x68;
    for (; i < 4; i++, w += 0x10) {
        ClearWindowTilemapAndCopyToVram(w);
        RemoveWindow(w);
    }
    YesNoPrompt_Destroy(*(void **)((u8 *)p + 0xA8));
}
