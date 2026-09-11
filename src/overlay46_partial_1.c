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

void ov46_02258F70(void *p) {
    ov46_022592E0(p);
}
