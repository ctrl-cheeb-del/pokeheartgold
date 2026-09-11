#include "global.h"

typedef struct TextContext {
    void *msgData;
    void *template;
    void *string;
    void *dest;
} TextContext;
typedef struct MenuTextWork {
    u8 windows[0x20];
    u16 printers[2];
    void *strings[2];
    u8 pad[8];
    int value;
} MenuTextWork;

void ReadMsgDataIntoString(void *, int, void *);
void StringExpandPlaceholders(void *, void *, void *);
int FontID_String_GetWidth(int, void *, int);
int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, int);
void ov90_02259570(void *, int);
void String_Delete(void *);
void RemoveWindow(void *);
void TextFlags_EndAutoScroll(void);
int TextPrinterCheckActive(u8);
void RemoveTextPrinter(u8);
void ClearFrameAndWindow2(void *, int);
void ClearWindowTilemapAndScheduleTransfer(void *);
void ov90_022594FC(void *, int);
void *Save_PlayerData_GetOptionsAddr(void *);
int Options_GetFrame(void *);
void TextFlags_BeginAutoScroll(int);
void LoadUserFrameGfx2(void *, int, int, int, u8, int);
void AddWindowParameterized(void *, void *, u8, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void *String_New(int, int);
void DrawFrameAndWindow2(void *, int, int, int);
void ScheduleWindowCopyToVram(void *);
extern const u16 ov90_0225C34C[20][2];

void ov90_022592A8(TextContext *, int, void *, int, u8);
int ov90_022592C4(TextContext *, int, void *, int, u8);
int ov90_02259314(TextContext *, int, void *, void *, int);
int ov90_02259350(TextContext *, int, void *, int, u8, u32);
void ov90_022592A8(TextContext *ctx, int msgNo, void *window, int x, u8 speed) {
    ov90_02259350(ctx, msgNo, window, x, speed, 0xf0e00);
}

int ov90_022592C4(TextContext *ctx, int msgNo, void *window, int width, u8 speed) {
    int x;
    ReadMsgDataIntoString(ctx->msgData, msgNo, ctx->dest);
    StringExpandPlaceholders(ctx->template, ctx->string, ctx->dest);
    x = width - FontID_String_GetWidth(0, ctx->string, 0);
    if (x < 0) {
        x = 0;
    }
    return AddTextPrinterParameterizedWithColor(window, 0, ctx->string, x, speed, 0xff, 0xf0e00, 0);
}

int ov90_02259314(TextContext *ctx, int msgNo, void *window, void *string, int speed) {
    ReadMsgDataIntoString(ctx->msgData, msgNo, ctx->dest);
    StringExpandPlaceholders(ctx->template, string, ctx->dest);
    return AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0, speed, 0x1020f, 0);
}

int ov90_02259350(TextContext *ctx, int msgNo, void *window, int x, u8 speed, u32 color) {
    ReadMsgDataIntoString(ctx->msgData, msgNo, ctx->dest);
    StringExpandPlaceholders(ctx->template, ctx->string, ctx->dest);
    return AddTextPrinterParameterizedWithColor(window, 0, ctx->string, x, speed, 0xff, color, 0);
}

void ov90_0225938C(MenuTextWork *, void *, void *, int, int);
void ov90_0225938C(MenuTextWork *arg, void *holder, void *save, int value, int heapId) {
    int frame = Options_GetFrame(Save_PlayerData_GetOptionsAddr(save));
    u8 *base;
    int i;

    TextFlags_BeginAutoScroll(1);
    LoadUserFrameGfx2(*(void **)holder, 2, 1, 0xd, frame, heapId);
    LoadUserFrameGfx2(*(void **)holder, 4, 1, 0xd, frame, heapId);
    base = (u8 *)arg;
    i = 0;
    do {
        int bgId;
        int y;
        if (i == 0) {
            bgId = 2;
            y = 0x13;
        } else {
            bgId = 4;
            y = 1;
        }
        AddWindowParameterized(*(void **)holder, base, bgId, 2, y, 0x1b, 4, 0xc, 0x1f);
        FillWindowPixelBuffer(base, 0);
        arg->strings[i] = String_New(0x80, heapId);
        base += 0x10;
        i++;
    } while (i < 2);
    arg->value = value;
}

void ov90_02259434(void *);
void ov90_02259434(void *arg) {
    u8 *p = arg;
    int i = 0;
    u8 *stringSlot = p;
    u8 *window = p;
    do {
        ov90_022594FC(p, i);
        String_Delete(*(void **)(stringSlot + 0x24));
        RemoveWindow(window);
        i++;
        stringSlot += 4;
        window += 0x10;
    } while (i < 2);
    TextFlags_EndAutoScroll();
}

void ov90_02259464(MenuTextWork *, TextContext *, int, int);
void ov90_02259464(MenuTextWork *work, TextContext *ctx, int msgNo, int i) {
    u32 j;
    u16 printer;
    u8 *window;

    if (work->value == 1) {
        for (j = 0; j < 20; j++) {
            if (msgNo == ov90_0225C34C[j][0]) {
                msgNo = ov90_0225C34C[j][1];
            }
        }
    }
    printer = work->printers[i];
    if (TextPrinterCheckActive((u8)printer)) {
        RemoveTextPrinter((u8)work->printers[i]);
    }
    ov90_02259570(work, i);
    window = work->windows + i * 0x10;
    FillWindowPixelBuffer(window, 0xf);
    work->printers[i] = ov90_02259314(ctx, msgNo, window, work->strings[i], 1);
    DrawFrameAndWindow2(window, 1, 1, 0xd);
    ScheduleWindowCopyToVram(window);
}

void ov90_022594FC(void *arg, int i) {
    u8 *p = arg;
    ov90_02259570(p, i);
    if (TextPrinterCheckActive(*(u16 *)(p + 0x20 + i * 2))) {
        RemoveTextPrinter(*(u16 *)(p + 0x20 + i * 2));
    }
    ClearFrameAndWindow2(p + i * 0x10, 1);
    ClearWindowTilemapAndScheduleTransfer(p + i * 0x10);
}
