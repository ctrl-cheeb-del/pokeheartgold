#include "global.h"
typedef struct BgConfig BgConfig;

typedef struct {
    u8 pad00[0x6C];
    void *callback;
    u16 value;
} Obj;

extern void GF_AssertFail(void);
extern void SpriteSystem_FreeResourcesAndManager(void *);
extern void SpriteSystem_Free(void *);
extern void Heap_Free(void *);
extern void RemoveTextPrinter(u8);
extern void ClearFrameAndWindow2(void *, int);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void ov111_021E6694(void *);
extern void ov111_021E65D4(void *);
extern void ov111_021E69F4(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void String_Delete(void *);
extern void MessagePrinter_Delete(void *);
extern void NARC_Delete(void *);
extern void FreeBgTilemapBuffer(void *, u8);
extern const u8 _021E6B74[];
extern void Sprite_DeleteAndFreeResources(void *);
extern void LoadFontPal0(int, int, int);
extern void LoadUserFrameGfx2(BgConfig *, int, u16, u8, u8, int);
extern void *OverlayManager_GetData(void *);
extern void YesNoPrompt_Destroy(void *);
extern void ov111_021E6710(void *);
extern void ov111_021E685C(void *);
extern void Sprite_DeleteAndFreeResources(void *);
extern void ov111_021E5FD4(void *);
extern void ov111_021E5CD4(void);
extern void OverlayManager_FreeData(void *);
extern void Heap_Destroy(int);
extern void SpriteSystem_DrawSprites(void *);
extern void SpriteSystem_TransferOam(void);
extern void DoScheduledBgGpuUpdates(void *);

int ov111_021E5C94(int);
void ov111_021E5D08(void *, int);
void ov111_021E6170(void *, void *);
void ov111_021E65CC(Obj *, void *, u16);
BOOL ov111_021E6684(Obj *);
void ov111_021E69F4(void *);
void ov111_021E5FD4(void *);
void ov111_021E5F04(void *);
void ov111_021E5DF0(void *);
void *ov111_021E6A2C(void *);
void ov111_021E6A44(BgConfig *, int, int);
void ov111_021E6710(void *);
void ov111_021E6694(void *);
void ov111_021E6770(void *, int, void *, u16);
void ov111_021E6784(void *);
BOOL ov111_021E67A4(void *);
void ov111_021E685C(void *);

void ov111_021E69F4(void *arg) {
    u8 *p = arg;
    int printer = *(int *)(p + 0x2C);
    if (printer != -1) {
        RemoveTextPrinter((u8)printer);
    }
    if (*(u32 *)(p + 0x1C) != 0) {
        ClearFrameAndWindow2(p + 0x1C, 0);
        ClearWindowTilemapAndCopyToVram(p + 0x1C);
        RemoveWindow(p + 0x1C);
    }
}

void *ov111_021E6A2C(void *arg) {
    u8 *p = arg;
    if (p == NULL) {
        GF_AssertFail();
    }
    if (*(void **)(p + 8) == NULL) {
        GF_AssertFail();
    }
    return *(void **)(p + 8);
}

void ov111_021E6A44(BgConfig *bg, int layer, int heap) {
    LoadFontPal0(0, 0x1C0, heap);
    LoadUserFrameGfx2(bg, layer, 0x3D2, 0xD, 0, heap);
}
