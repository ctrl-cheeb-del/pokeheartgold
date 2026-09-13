#include "r40_overlay_72_residual_30_private.h"

extern BOOL Sprite_IsAnimated(void *sprite);
extern void ToggleBgLayer(u32 layer, BOOL enable);
extern void Sprite_SetDrawFlag(void *sprite, BOOL draw);
extern void *NARC_New(u32 narcId, u32 heapId);
extern void NARC_Delete(void *narc);
extern void GfGfxLoader_GXLoadPalFromOpenNarc(void *narc, int member, int location, int offset, int size, u32 heapId);
extern void LoadFontPal0(int location, int offset, u32 heapId);
extern void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, int member, void *bgConfig, int layer, int offset, int size, BOOL compressed, u32 heapId);
extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void *narc, int member, BOOL compressed, void **data, u32 heapId);
extern u16 *GetBgTilemapBuffer(void *bgConfig, int layer);
extern void BgCommitTilemapBufferToVram(void *bgConfig, int layer);
extern void Heap_Free(void *ptr);
extern void *NewMsgDataFromNarc(int mode, int narcId, int fileId, u32 heapId);
extern void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
extern void FillWindowPixelBuffer(void *window, int fillValue);
extern void *NewString_ReadMsgData(void *msgData, int messageId);
extern void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, int x, int y, int speed, u32 color, void *callback);
extern void CopyWindowToVram(void *window);
extern void String_Delete(void *string);
extern void DestroyMsgData(void *msgData);
extern void ClearWindowTilemapAndCopyToVram(void *window);
extern void RemoveWindow(void *window);

BOOL ov72_0223B088(Ov72Residual30 *work) {
    if (Sprite_IsAnimated(work->sprite)) {
        return FALSE;
    }
    ToggleBgLayer(work->bgLayer, FALSE);
    ToggleBgLayer(work->secondBgLayer, FALSE);
    ov72_0223B2C0(work);
    Sprite_SetDrawFlag(work->sprite, FALSE);
    return TRUE;
}
