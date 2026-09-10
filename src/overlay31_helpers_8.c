#include "global.h"

typedef struct Overlay31State {
    u8 data[0x300];
} Overlay31State;

extern void *MessageFormat_New_Custom(int, int, int);
extern void MessageFormat_Delete(void *);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void DestroyMsgData(void *);
extern void *NewString_ReadMsgData(void *, int);
extern void *String_New(int, int);
extern void String_Delete(void *);
extern void *SysTask_GetData(void *);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern void DestroySysTaskAndEnvironment(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Destroy(int);
extern void RemoveWindow(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void ScheduleWindowCopyToVram(void *);
extern void PlaySE(int);
extern int YesNoPrompt_HandleInputForSave(void *);
extern void YesNoPrompt_Destroy(void *);
extern void BufferItemName(void *, int);
extern void BufferItemNamePlural(void *, int);
extern void BufferItemNameWithIndefArticle(void *, int);
extern void BufferDecorationName(void *, int);
extern void GF_AssertFail(void);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void ClearFrameAndWindow2(void *, int);
extern void *GfGfxLoader_GetScrnData(int, int, int, void **, int);
extern void BG_LoadScreenTilemapData(void *, int, void *, int);
extern void *ScheduleBgTilemapBufferTransfer(void *, int);
extern void Heap_Free(void *);
extern void ov31_0225E060(void *, int, int);
extern int PokeathlonSave_GetUnkB7C_AtIndex(void *, int);
extern int PokeathlonSave_GetUnkB78_AtIndex(void *, int);
extern int PokeathlonSave_GetAthletePoints(void *);
extern int PlayerProfile_GetMoney(void *);
extern int ov03_02257814(void *, int);
extern int IsPaletteFadeFinished(void);
extern void ov31_0225D83C(Overlay31State *, int);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int);
extern int FontID_String_GetWidth(int, void *, int);
typedef struct Overlay31WindowTemplate {
    u32 x, y, base;
} Overlay31WindowTemplate;
extern const Overlay31WindowTemplate ov31_0225EE88[6];
extern const void *_0225EF40[];

void ov31_0225DBA0(Overlay31State *state);
void ov31_0225DCF4(Overlay31State *state);
void ov31_0225D60C(Overlay31State *state);
void ov31_0225D654(Overlay31State *state);
void ov31_0225D710(void *bgConfig, void *task);
int ov31_0225D758(void);
int ov31_0225D75C(Overlay31State *state, u32 selection);
int ov31_0225DAA4(Overlay31State *state, int which);
void ov31_0225E4BC(int kind, void *format, int unused, int value);
void ov31_0225E4EC(int kind, void *format, int unused, int value);
void ov31_0225E51C(int kind, void *format, int unused, int value);
int ov31_0225E774(Overlay31State *state);
int ov31_0225E948(void *unused, int printerState);
void *ov31_0225E9CC(const u8 *args, void *msgData);
void ov31_0225DE00(Overlay31State *state, void *window, void *string, int y);
void ov31_0225E0E4(Overlay31State *state, int screen);
int ov31_0225E12C(u8 *args, int index, int value);
void ov31_0225E474(Overlay31State *state);
void ov31_0225EDA0(Overlay31State *state);
void *ov31_0225E95C(u8 *args, void *msgData);
void ov31_0225D60C(Overlay31State *state);
void ov31_0225D654(Overlay31State *state);

void ov31_0225E474(Overlay31State *state) {
    void *string = NewString_ReadMsgData(*(void **)&state->data[0x158], 0x2a);
    AddTextPrinterParameterizedWithColor(&state->data[0x114], 0, string, 4, 0, 0xff, 0xf0e00, 0);
    ScheduleWindowCopyToVram(&state->data[0x114]);
    String_Delete(string);
}

void ov31_0225E4BC(int kind, void *format, int unused, int value) {
    switch (kind) {
    case 0:
    case 3:
    case 4:
        BufferItemName(format, value);
        break;
    case 1:
        BufferDecorationName(format, value);
        break;
    }
}

void ov31_0225E4EC(int kind, void *format, int unused, int value) {
    switch (kind) {
    case 0:
    case 3:
    case 4:
        BufferItemNamePlural(format, value);
        break;
    case 1:
        BufferDecorationName(format, value);
        break;
    }
}

void ov31_0225E51C(int kind, void *format, int unused, int value) {
    switch (kind) {
    case 0:
    case 3:
    case 4:
        BufferItemNameWithIndefArticle(format, value);
        break;
    case 1:
        BufferDecorationName(format, value);
        break;
    }
}
