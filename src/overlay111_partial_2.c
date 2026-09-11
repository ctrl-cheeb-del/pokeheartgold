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

void ov111_021E5F04(void *manager) {
    u8 *p = OverlayManager_GetData(manager);
    YesNoPrompt_Destroy(*(void **)(p + 0x18));
    ov111_021E6710(*(void **)(p + 0x20));
    ov111_021E685C(*(void **)(p + 0x24));
    if (*(void **)(p + 0x14) != NULL) {
        Sprite_DeleteAndFreeResources(*(void **)(p + 0x14));
        *(void **)(p + 0x14) = NULL;
    }
    ov111_021E6170(*(void **)(p + 0xC), *(void **)(p + 0x10));
    ov111_021E5FD4(p);
    ov111_021E5CD4();
    OverlayManager_FreeData(manager);
    Heap_Destroy(0x94);
}
