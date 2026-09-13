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

void ov72_0223B1C8(Ov72Residual30 *work) {
    void *msgData = NewMsgDataFromNarc(1, 0x1B, 0xBF, work->heapId);
    void *string1;
    void *string2;

    AddWindowParameterized(work->bgConfig, work->window1, work->secondBgLayer, 0xC, 8, 8, 2, work->fontPalette, work->baseTile);
    FillWindowPixelBuffer(work->window1, 0);
    AddWindowParameterized(work->bgConfig, work->window2, work->secondBgLayer, 0xC, 0xE, 8, 2, work->fontPalette, (u16)(work->baseTile + 0x10));
    FillWindowPixelBuffer(work->window2, 0);
    string1 = NewString_ReadMsgData(msgData, 0x2E);
    string2 = NewString_ReadMsgData(msgData, 0x2F);
    AddTextPrinterParameterizedWithColor(work->window1, 4, string1, 0, 0, 0, 0xF0100, NULL);
    AddTextPrinterParameterizedWithColor(work->window2, 4, string2, 0, 0, 0, 0xF0100, NULL);
    CopyWindowToVram(work->window1);
    CopyWindowToVram(work->window2);
    String_Delete(string2);
    String_Delete(string1);
    DestroyMsgData(msgData);
}

void ov72_0223B2C0(Ov72Residual30 *work) {
    ClearWindowTilemapAndCopyToVram(work->window2);
    ClearWindowTilemapAndCopyToVram(work->window1);
    RemoveWindow(work->window2);
    RemoveWindow(work->window1);
}
