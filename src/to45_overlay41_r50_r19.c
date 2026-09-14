#include "to45_overlay41_r50_r19_private.h"

void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
void ov41_022462E4(void *, void *, int, int, int, int);
void ov41_02246304(void *, void *, int, int, int, int, int);
void ov41_02246328(void *, void *, int, int, int);
void ov41_02246344(void *, void *, int, int, int);
void *ov41_02246280(void *, int, int, int, int, int);
void ov41_02246360(void *, int);
void ov41_02246374(void *, int);
void ov41_02246388(void *, int);
void ov41_0224639C(void *, int);
void Sprite_SetPriority(void *, int);
void Sprite_Delete(void *);
void *AllocWindows(int, int);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void LoadFontPal0(int, int, int);
void SetBgPriority(int, int);
void BgSetPosTextAndCommit(void *, int, int, int);
void ClearWindowTilemapAndCopyToVram(void *);
void RemoveWindow(void *);
void WindowArray_Delete(void *, int);
void FillWindowPixelBuffer(void *, int);
void CopyWindowToVram(void *);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void *GfGfxLoader_GetScrnData(int, int, int, void **, int);
void LoadRectToBgTilemapRect(void *, int, void *, int, int, int, int);
void BgTilemapRectChangePalette(void *, int, int, int, int, int, int);
void Heap_Free(void *);
void ScheduleBgTilemapBufferTransfer(void *, int);
void *NewMsgDataFromNarc(int, int, int, int);
void GF_AssertFail(void);
void *MessageFormat_New(int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetMatrix(void *, void *);
void *String_New(int, int);
void sub_0202BE60(void *, void *);
int FontID_String_GetWidth(int, void *, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
void String_Delete(void *);
int sub_0202BE98(void *);
void BufferECWord(void *, int, int);
void *NewString_ReadMsgData(void *, int);
void StringExpandPlaceholders(void *, void *, void *);
void DestroyMsgData(void *);
void MessageFormat_Delete(void *);

typedef struct Ov41ScreenData {
    u16 width;
    u16 height;
    u8 pad04[8];
    u16 data[];
} Ov41ScreenData;

void ov41_0224BC04(void *work) {
    Ov41ScreenData *screen;
    void *allocation;

    GfGfxLoader_GXLoadPalFromOpenNarc(PTR_AT(work, 0x194), 0x7E, 0, 0x60, 0x40, 0xE);
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(work, 0x194), 0x7D, PTR_AT(work, 0x54), 1, 0, 0, 0, 0xE);
    allocation = GfGfxLoader_GetScrnData(0x1A, 0x80, 0, (void **)&screen, 0xE);
    LoadRectToBgTilemapRect(PTR_AT(work, 0x54), 1, screen->data, 0, 0, (u8)(screen->width >> 3), (u8)(screen->height >> 3));
    BgTilemapRectChangePalette(PTR_AT(work, 0x54), 1, 0, 0, (u8)(screen->width >> 3), (u8)(screen->height >> 3), 4);
    Heap_Free(allocation);
    ScheduleBgTilemapBufferTransfer(PTR_AT(work, 0x54), 1);
}

void ov41_0224BCA4(void *work) {
    GfGfxLoader_GXLoadPal(0xEF, 0, 4, 0, 0, 0xE);
    GfGfxLoader_LoadScrnData(0xEF, 9, PTR_AT(work, 0x54), 4, 0, 0, 0, 0xE);
    GfGfxLoader_LoadCharData(0xEF, 1, PTR_AT(work, 0x54), 4, 0, 0, 0, 0xE);
}

void ov41_0224BCF0(void *work) {
    ov41_022462E4(PTR_OFS(work, 0x14), PTR_AT(work, 0x194), 0xE9, 0, 1, 0x3E8);
    ov41_02246304(PTR_OFS(work, 0x14), PTR_AT(work, 0x194), 0xEA, 0, 1, 6, 0x3E8);
    ov41_02246328(PTR_OFS(work, 0x14), PTR_AT(work, 0x194), 0xE8, 0, 0x3E8);
    ov41_02246344(PTR_OFS(work, 0x14), PTR_AT(work, 0x194), 0xE7, 0, 0x3E8);
    PTR_AT(work, 0x198) = ov41_02246280(PTR_OFS(work, 0x14), 0x3E8, 0, 0x90, 0x64, 1);
    Sprite_SetPriority(PTR_AT(work, 0x198), 1);
}

void ov41_0224BD8C(void *work) {
    ov41_02246360(PTR_OFS(work, 0x14), 0x3E8);
    ov41_02246374(PTR_OFS(work, 0x14), 0x3E8);
    ov41_02246388(PTR_OFS(work, 0x14), 0x3E8);
    ov41_0224639C(PTR_OFS(work, 0x14), 0x3E8);
    Sprite_Delete(PTR_AT(work, 0x198));
}

void ov41_0224BDCC(void *work) {
    PTR_AT(work, 0x19C) = AllocWindows(0xE, 1);
    AddWindowParameterized(PTR_AT(work, 0x54), PTR_AT(work, 0x19C), 3, 0, 0x12, 0x20, 6, 5, 1);
    LoadFontPal0(0, 0xA0, 0xE);
    SetBgPriority(3, 0);
    SetBgPriority(0, 2);
    SetBgPriority(1, 1);
    BgSetPosTextAndCommit(PTR_AT(work, 0x54), 3, 3, 0);
}

void ov41_0224BE34(void *work) {
    ClearWindowTilemapAndCopyToVram(PTR_AT(work, 0x19C));
    RemoveWindow(PTR_AT(work, 0x19C));
    WindowArray_Delete(PTR_AT(work, 0x19C), 1);
}

void ov41_0224BE5C(void *work) {
    FillWindowPixelBuffer(PTR_AT(work, 0x19C), 0);
    ov41_0224BE80(work);
    CopyWindowToVram(PTR_AT(work, 0x19C));
}

void ov41_0224BE80(void *work) {
    void *msgData = NewMsgDataFromNarc(0, 0x1B, 0xD7, 0xD);
    void *format;
    void *string;
    void *message;
    s32 matrix[3];
    int width;

    if (msgData == NULL) {
        GF_AssertFail();
    }
    format = MessageFormat_New(0xD);
    Sprite_SetAnimCtrlSeq(PTR_AT(work, 0x198), 5);
    matrix[0] = 3 << 16;
    matrix[1] = 9 << 16;
    matrix[2] = 0;
    Sprite_SetMatrix(PTR_AT(work, 0x198), matrix);

    string = String_New(0xC, 0xD);
    sub_0202BE60(PTR_AT(work, 0), string);
    width = FontID_String_GetWidth(0, string, 0);
    AddTextPrinterParameterizedWithColor(PTR_AT(work, 0x19C), 0, string, 0x80 - width / 2, 7, 0, 0x10200, 0);
    String_Delete(string);

    BufferECWord(format, 0, sub_0202BE98(PTR_AT(work, 0)));
    string = String_New(0xC8, 0xD);
    message = NewString_ReadMsgData(msgData, 0x2D);
    StringExpandPlaceholders(format, string, message);
    width = FontID_String_GetWidth(0, string, 0);
    AddTextPrinterParameterizedWithColor(PTR_AT(work, 0x19C), 0, string, 0x80 - width / 2, 0x1B, 0, 0x10200, 0);
    String_Delete(string);
    String_Delete(message);
    DestroyMsgData(msgData);
    MessageFormat_Delete(format);
}
