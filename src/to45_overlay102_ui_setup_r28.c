#include "global.h"

u32 ov102_021EA268(u8 *p);
void ov102_021EA270(u8 *p, void *dst, int a, int b);
void *ov102_021EA2B4(u8 *p, void *args, int x, int y, int a, int b);
void ov102_021EB1F8(u8 *p, void *narc);
void ov102_021EB29C(u8 *p);
void ov102_021EB2EC(u8 *p, int draw, int enabled);
void ov102_021EB3B4(u8 *p, int draw);
void ov102_021EB46C(u8 *p, void *bgConfig);
void ov102_021EB4D0(u8 *p);
void ov102_021EB524(u8 *p, int enabled);
void ov102_021EB570(u8 *p, int a, int b);

void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int fileId, void *bgConfig, int layer, int a, int b, int c, int heapId);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, int fileId, void *bgConfig, int layer, int a, int b, int c, int heapId);
void *GfGfxLoader_GetScrnDataFromOpenNarc(void *narc, int fileId, int a, void *dst, int heapId);
void BgCommitTilemapBufferToVram(void *bgConfig, int layer);
void FillBgTilemapRect(void *bgConfig, int layer, int tile, int x, int y, int width, int height, int palette);
void CopyToBgTilemapRect(void *bgConfig, int layer, int x, int y, int width, int height, const void *src, int srcX, int srcY, int srcWidth, int srcHeight);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, int layer);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void FillWindowPixelBuffer(void *window, int fill);
void PutWindowTilemap(void *window);
void AddWindow(void *bgConfig, void *window, const void *template);
void *NewString_ReadMsgData(void *msgData, int msgNo);
void String_Delete(void *str);
void Heap_Free(void *ptr);
void Sprite_Delete(void *sprite);
void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
void Sprite_SetDrawFlag(void *sprite, int draw);
int FontID_String_GetWidth(int fontId, void *string, int letterSpacing);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, int x, int y, int speed, u32 color, void *callback);

extern const u8 ov102_021EC808[];

void ov102_021EB1F8(u8 *p, void *narc) {
    void *bgConfig = (void *)ov102_021EA268(*(u8 **)p);

    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 4, bgConfig, 3, 0, 0, 1, 0x23);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 5, bgConfig, 3, 0, 0, 1, 0x23);
    *(void **)(p + 0x54) = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 0xe, 0, p + 0x5c, 0x23);
    *(void **)(p + 0x58) = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 0xf, 0, p + 0x60, 0x23);
    ov102_021EB46C(p, bgConfig);
    ov102_021EB4D0(p);
    ov102_021EB2EC(p, 1, 0);
    ov102_021EB570(p, 0, 1);
    ov102_021EB570(p, 1, 0);
    BgCommitTilemapBufferToVram(bgConfig, 3);
}

void ov102_021EB29C(u8 *p) {
    void *bgConfig = (void *)ov102_021EA268(*(u8 **)p);
    u8 *window;
    u8 *strings;
    int i;

    if (*(void **)(p + 0xc) != NULL) {
        Sprite_Delete(*(void **)(p + 0xc));
    }
    window = p;
    i = 0;
    window += 0x24;
    strings = p;
    for (; i < 3; i++) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        String_Delete(*(void **)(strings + 0x18));
        window += 0x10;
        strings += 4;
    }
    Heap_Free(*(void **)(p + 0x58));
    Heap_Free(*(void **)(p + 0x54));
    BgCommitTilemapBufferToVram(bgConfig, 3);
}

void ov102_021EB2EC(u8 *p, int draw, int enabled) {
    void *bgConfig = (void *)ov102_021EA268(*(u8 **)p);
    u8 *window;
    int i;

    FillBgTilemapRect(bgConfig, 0, 0, 0x17, 0xd, 9, 7, 0x11);
    ov102_021EB524(p, enabled);
    if (draw == 0) {
        BgCommitTilemapBufferToVram(bgConfig, 0);
        return;
    }
    CopyToBgTilemapRect(bgConfig, 0, 0x17, 0xd, 9, 7, *(void **)(p + 0x5c) + 0xc, 0, 0, (u32)(*(u16 **)(p + 0x5c))[0] << 0x15 >> 0x18, (u32)(*(u16 **)(p + 0x5c))[1] << 0x15 >> 0x18);
    window = p;
    i = 0;
    window += 0x24;
    for (; i < 2; i++) {
        int x;

        FillWindowPixelBuffer(window, 0xe);
        x = 0x38 - FontID_String_GetWidth(4, *(void **)(p + 0x18), 0);
        AddTextPrinterParameterizedWithColor(window, 4, *(void **)(p + 0x18), x / 2, 0, 0, 0x3010e, NULL);
        window += 0x10;
        p += 4;
    }
    BgCommitTilemapBufferToVram(bgConfig, 0);
}

void ov102_021EB3B4(u8 *p, int draw) {
    void *bgConfig = (void *)ov102_021EA268(*(u8 **)p);
    int x;

    if (draw == 0) {
        FillBgTilemapRect(bgConfig, 0, 0, 0x18, 0x14, 8, 4, 0x11);
        ClearWindowTilemapAndCopyToVram(p + 0x44);
        ScheduleBgTilemapBufferTransfer(bgConfig, 0);
        return;
    }
    CopyToBgTilemapRect(bgConfig, 0, 0x18, 0x14, 8, 4, *(void **)(p + 0x5c) + 0xc, 0, 7, (u32)(*(u16 **)(p + 0x5c))[0] << 0x15 >> 0x18, (u32)(*(u16 **)(p + 0x5c))[1] << 0x15 >> 0x18);
    FillWindowPixelBuffer(p + 0x44, 0xe);
    x = 0x30 - FontID_String_GetWidth(4, *(void **)(p + 0x20), 0);
    AddTextPrinterParameterizedWithColor(p + 0x44, 4, *(void **)(p + 0x20), x / 2, 0, 0, 0x3010e, NULL);
    ScheduleBgTilemapBufferTransfer(bgConfig, 0);
}

void ov102_021EB46C(u8 *p, void *bgConfig) {
    u32 i;
    const u8 *template;
    u8 *window;
    u8 *strings;

    window = p;
    template = ov102_021EC808;
    i = 0;
    window += 0x24;
    strings = p;
    for (; i < 3; i++) {
        AddWindow(bgConfig, window, template);
        *(void **)(strings + 0x18) = NewString_ReadMsgData(*(void **)(p + 0x14), i);
        template += 8;
        window += 0x10;
        strings += 4;
    }
    PutWindowTilemap(p + 0x24);
    FillWindowPixelBuffer(p + 0x24, 0xe);
    PutWindowTilemap(p + 0x34);
    FillWindowPixelBuffer(p + 0x34, 0xe);
}

void ov102_021EB4D0(u8 *p) {
    u8 args[0x24];

    ov102_021EA270(*(u8 **)p, args, 0, 0);
    *(void **)(p + 0xc) = ov102_021EA2B4(*(u8 **)p, args, 0xdc, 0x78, 5, 1);
    Sprite_SetAnimCtrlSeq(*(void **)(p + 0xc), 2);
    Sprite_SetDrawFlag(*(void **)(p + 0xc), 0);
}
