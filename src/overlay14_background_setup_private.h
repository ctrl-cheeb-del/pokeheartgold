#ifndef POKEHEARTGOLD_OVERLAY14_BACKGROUND_SETUP_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BACKGROUND_SETUP_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct R11GraphicsModes {
    u32 word[4];
} R11GraphicsModes;

typedef struct R11BgTemplate {
    u32 word[7];
} R11BgTemplate;

extern const R11GraphicsModes ov14_021F7BC8;
extern const R11BgTemplate ov14_021F7C20;
extern const R11BgTemplate ov14_021F7C3C;
extern const R11BgTemplate ov14_021F7C58;
extern const R11BgTemplate ov14_021F7C74;
extern const R11BgTemplate ov14_021F7C90;
extern const R11BgTemplate ov14_021F7CAC;
extern const R11BgTemplate ov14_021F7CC8;

extern void *BgConfig_Alloc(u32);
extern void SetBothScreensModesAndDisable(const R11GraphicsModes *);
extern void InitBgFromTemplate(void *, u32, const R11BgTemplate *, u32);
extern void BgClearTilemapBufferAndCommit(void *, u32);
extern void BG_ClearCharDataRange(u32, u32, u32, u32);

void ov14_021E5A70(void *);

extern void FreeBgTilemapBuffer(void *, u32);
extern void Heap_Free(void *);
extern void *NewMsgDataFromNarc(u32, u32, u32, u32);
extern void *MessagePrinter_New(u32, u32, u32, u32);
extern void *MessageFormat_New(u32);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void MessagePrinter_Delete(void *);
extern void DestroyMsgData(void *);
extern void *PaletteData_Init(u32);
extern void PaletteData_AllocBuffers(void *, u32, u32, u32);

extern void GfGfxLoader_LoadCharData(u32, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_LoadScrnData(u32, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_GXLoadPal(u32, u32, u32, u32, u32, u32);
extern u32 Options_GetFrame(void *);
extern void LoadUserFrameGfx2(void *, u32, u32, u32, u32, u32);
extern void LoadFontPal1(u32, u32, u32);
extern void LoadFontPal0(u32, u32, u32);

void ov14_021E5C00(void *);
void ov14_021E5C54(void *);
void ov14_021E5D78(void *);
void ov14_021E5DB8(void *);
void ov14_021E5DE0(void *);
void ov14_021E5E74(void *);

#endif
