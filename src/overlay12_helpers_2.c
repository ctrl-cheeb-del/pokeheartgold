#include "global.h"

#include "overlay_manager.h"

typedef struct {
    u8 pad0[4];
    void *bgConfig;
    u8 pad8[0x2430];
    s32 scroll;
} Ov12ScrollData;

typedef struct {
    u8 pad0[0x2C];
    u32 input;
    u8 pad30[0x23DC];
    u32 flags;
} Ov12TextData;
typedef struct {
    u8 pad0[0x14];
    void *allocations[4];
    u8 pad24[7];
    u8 enabled;
} Ov12HeapGroup;
typedef struct {
    u8 pad0[0x198];
    Ov12HeapGroup *heapGroup;
} Ov12Args;
typedef struct {
    u8 pad0[4];
    void *bgConfig;
    void *windows;
    void *paletteData;
    u8 pad10[0x1B4];
    Ov12HeapGroup *heapGroup;
} Ov12MainData;
extern void GF_3DVramMan_Delete(void);
extern BOOL sub_02039998(void);
extern void HandleLoadOverlay(int overlayId, int mode);
extern void GfGfx_EngineATogglePlanes(int mask, BOOL enable);
extern void FreeBgTilemapBuffer(void *bgConfig, int bgId);
extern void BgConfig_CleanupBattleMenuBackgrounds(void *bgConfig);
extern void *GF_3DVramMan_Create(int a0, int a1, int a2, int a3, int a4, void (*callback)(void));
extern void ov12_02239664(void);
extern void PaletteData_PushTransparentBuffers(void *paletteData);
extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(void *bgConfig);
extern void BgSetPosTextAndCommit(void *bgConfig, int bgId, int op, int value);
extern void SysTask_Destroy(void *task);
extern void TextFlags_SetAutoScrollParam(int value);
extern void TextFlags_SetCanABSpeedUpPrint(BOOL value);
extern void TextFlags_SetCanTouchSpeedUpPrint(BOOL value);
extern char SDK_OVERLAY_OVY_18_ID[];
extern void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
extern void sub_0200FBF4(void *callback, void *arg);
extern void PaletteData_FreeBuffers(void *paletteData, int selector);
extern void PaletteData_Free(void *paletteData);
extern void WindowArray_Delete(void *windows, int count);
extern void Heap_Free(void *ptr);
extern void sub_0203A880(void);
extern int ov00_021EC9D4(void);
extern BOOL sub_02035650(void);
extern int WM_GetLinkLevel(void);
extern void sub_0203A930(int value);
extern void PokepicManager_DrawAll(void *manager);
extern void SpriteSystem_DrawSprites(void *renderer);
extern void SpriteSystem_UpdateTransfer(void);
extern void RequestSwap3DBuffers(int sortMode, int bufferMode);
extern void sub_020399FC(int a0, void *bgConfig);
extern void ov06_0221BAF0(void);
extern void sub_02014DA0(void);

void ov12_02238A64(void);
void ov12_022396E8(void);
void ov12_022399BC(void);
void ov12_02239644(void);
void ov12_02238A30(void *bgConfig);
void ov12_0223998C(void *task, Ov12ScrollData *data);
void ov12_0223A620(Ov12TextData *data);




void ov12_0223A088(OverlayManager *man);
BOOL ov12_0223A5E4(OverlayManager *man);
BOOL ov12_0223A218(OverlayManager *man);
BOOL ov12_0223A3A8(OverlayManager *man);
void ov12_0223A7A0(void);
void ov12_02239810(void *unused, Ov12MainData *data);
BOOL ov12_022395BC(int value);
void ov12_022396F0(void);

BOOL ov12_022395BC(int value) {
    switch (value) {
    case 0x42:
    case 0x43:
    case 0x46:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x62:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6E:
    case 0x70:
        return TRUE;
    default:
        return FALSE;
    }
}

void ov12_02239644(void) {
    GF_3DVramMan_Create(5, 0, 2, 0, 2, ov12_02239664);
}
