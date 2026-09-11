#include "global.h"

typedef struct {
    void *fmt;
    void *msg;
    u8 window[0x10];
    void *dst;
    void *src;
    int frameType;
    void *icon;
    int delay;
    int printer;
} TextBox;

extern void DoScheduledBgGpuUpdates(void *);
extern BOOL TextPrinterCheckActive(u8);
extern void RemoveTextPrinter(u8);
extern void FillWindowPixelBuffer(void *, int);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern u8 AddTextPrinterParameterized(void *, int, void *, int, int, int, int);
extern void DrawFrameAndWindow1(void *, int, int, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern void ScheduleWindowCopyToVram(void *);
extern void sub_0200E5D4(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void ClearFrameAndWindow2(void *, int);
extern void GF_AssertFail(void);
extern void *WaitingIcon_New(void *, int);
extern void sub_0200F450(void *);
extern void RemoveWindow(void *);
extern void String_Delete(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern int FontID_String_GetCenterAlignmentX(int, void *, int, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void FreeBgTilemapBuffer(void *, u8);
extern void Heap_Free(void *);
extern const u32 _02259598[];
extern void *YesNoPrompt_Create(int);
extern void YesNoPrompt_InitFromTemplate(void *, void *);
extern void *MessageFormat_New(int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *String_New(int, int);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern int Options_GetTextFrameDelay(void *);
extern void AddWindowParameterized(void *, void *, int, u8, u8, u8, u8, int, u16);

typedef struct {
    void *window;
    int unk04;
    int baseTile;
    int unk0C;
    u8 x;
    u8 y;
    u8 flag0 : 4;
    u8 flag1 : 4;
    u8 unk13;
} YesNoTemplate;
extern void ov46_022592E0(void *);

void ov46_02258F70(void *p);
void ov46_022592E0(void *p);
void ov46_02259210(void *, void *);
void ov46_022592EC(TextBox *, void *, int, int, int, int, int, int, int, void *, int);
void ov46_022592B8(void *p);
void ov46_02259374(TextBox *p, int msgNo);
void ov46_022593F8(TextBox *p);
void ov46_02259450(TextBox *p);
void ov46_02259474(TextBox *p);
void ov46_02259494(TextBox *p);
void ov46_022594E0(TextBox *p, int msgNo);
void ov46_02259534(void **fmt, int value);
void *ov46_02259550(void *window, int baseTile);

void ov46_022592B8(void *p) {
    int i;
    for (i = 0; i < 3; i++) {
        FreeBgTilemapBuffer(*(void **)((u8 *)p + 0xC), (u8)_02259598[i]);
    }
    Heap_Free(*(void **)((u8 *)p + 0xC));
}

void ov46_022592E0(void *p) {
    DoScheduledBgGpuUpdates(*(void **)((u8 *)p + 0xC));
}

void ov46_022592EC(TextBox *p, void *bg, int frameType, int msgNo, int bgId, int x, int y, int width, int baseTile, void *save, int heapId) {
    p->fmt = MessageFormat_New(heapId);
    p->msg = NewMsgDataFromNarc(0, 0x1B, msgNo, heapId);
    p->dst = String_New(0x100, heapId);
    p->src = String_New(0x100, heapId);
    p->frameType = frameType;
    p->delay = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(save));
    p->printer = 0;
    AddWindowParameterized(bg, p->window, 1, (u8)bgId, (u8)x, (u8)y, (u8)width, 9, (u16)baseTile);
}

void ov46_02259374(TextBox *p, int msgNo) {
    if (TextPrinterCheckActive((u8)p->printer)) {
        RemoveTextPrinter((u8)p->printer);
    }
    FillWindowPixelBuffer(p->window, 0xF);
    ReadMsgDataIntoString(p->msg, msgNo, p->src);
    StringExpandPlaceholders(p->fmt, p->dst, p->src);
    AddTextPrinterParameterized(p->window, 1, p->dst, 0, 0, 0xFF, 0);
    if (p->frameType == 0) {
        DrawFrameAndWindow1(p->window, 1, 0x1F, 0xC);
    } else {
        DrawFrameAndWindow2(p->window, 1, 1, 0xB);
    }
    ScheduleWindowCopyToVram(p->window);
}

void ov46_022593F8(TextBox *p) {
    if (TextPrinterCheckActive((u8)p->printer)) {
        RemoveTextPrinter((u8)p->printer);
    }
    if (p->frameType == 0) {
        sub_0200E5D4(p->window, 1);
        ClearWindowTilemapAndScheduleTransfer(p->window);
        return;
    }
    if (p->icon != NULL) {
        ov46_02259474(p);
    }
    ClearFrameAndWindow2(p->window, 1);
    ClearWindowTilemapAndScheduleTransfer(p->window);
}

void ov46_02259450(TextBox *p) {
    if (p->frameType == 1) {
        if (p->icon != NULL) {
            GF_AssertFail();
        }
        p->icon = WaitingIcon_New(p->window, 1);
    }
}

void ov46_02259474(TextBox *p) {
    if (p->frameType == 1) {
        if (p->icon == NULL) {
            GF_AssertFail();
        }
        sub_0200F450(p->icon);
        p->icon = NULL;
    }
}

void ov46_02259494(TextBox *p) {
    if (TextPrinterCheckActive((u8)p->printer)) {
        RemoveTextPrinter((u8)p->printer);
    }
    if (p->icon != NULL) {
        ov46_02259474(p);
    }
    RemoveWindow(p->window);
    String_Delete(p->src);
    String_Delete(p->dst);
    DestroyMsgData(p->msg);
    MessageFormat_Delete(p->fmt);
}

void ov46_022594E0(TextBox *p, int msgNo) {
    int x;
    FillWindowPixelBuffer(p->window, 0);
    ReadMsgDataIntoString(p->msg, msgNo, p->src);
    StringExpandPlaceholders(p->fmt, p->dst, p->src);
    x = FontID_String_GetCenterAlignmentX(0, p->dst, 0, 0xB0);
    AddTextPrinterParameterizedWithColor(p->window, 1, p->dst, x, 0, 0, 0x000F0E00, 0);
}

void ov46_02259534(void **fmt, int value) {
    BufferIntegerAsString(*fmt, 0, value, 5, 2, 1);
}

void *ov46_02259550(void *window, int baseTile) {
    YesNoTemplate t;
    void *prompt = YesNoPrompt_Create(0x77);
    t.window = window;
    t.unk04 = 1;
    t.baseTile = baseTile;
    t.unk0C = 0xD;
    t.x = 0x19;
    t.y = 0xA;
    t.flag0 = 0;
    t.flag1 = 0;
    t.unk13 = 0;
    YesNoPrompt_InitFromTemplate(prompt, &t);
    return prompt;
}
