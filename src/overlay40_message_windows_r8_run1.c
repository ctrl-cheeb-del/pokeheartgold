#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern void ov40_0222C6C8(void *, int, int);
extern void SetBgPriority(int, int);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern void InitWindow(void *);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void BgClearTilemapBufferAndCommit(void *, int);
extern void FillWindowPixelBuffer(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void ScheduleWindowCopyToVram(void *);
extern void *NewString_ReadMsgData(void *, int);
extern void String_Delete(void *);
extern void OS_WaitVBlankIntr(void);
extern void G2x_SetBlendAlpha_(u32, int, int, int, int);

void ov40_0222DD9C(void *, int);
void ov40_0222DE40(void *);
void ov40_0222DEAC(void *);
void ov40_0222DED0(void *, int);
void ov40_0222DF60(void *, int);
void ov40_0222DFB0(void *);
void ov40_0222DFE8(void *, int);

void ov40_0222DD9C(void *p, int msgId) {
    void *win = (u8 *)p + 0x8A4;
    void *str;

    if (WORD(p, 0x8A0) != 1) {
        WORD(p, 0x8A0) = 1;
        ov40_0222C6C8(p, 6, 0);
        *(vu16 *)0x04001050 = 0;
        SetBgPriority(6, 0);
        InitWindow(win);
        AddWindowParameterized(PTR(p, 0x24), win, 6, 1, 0x13, 0x1E, 4, 0xE, 0x20);
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        FillWindowPixelBuffer(win, 0xCC);
        AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
        OS_WaitVBlankIntr();
        GfGfx_EngineBTogglePlanes(4, 1);
    }
}

void ov40_0222DE40(void *p) {
    if (WORD(p, 0x8A0) != 0) {
        WORD(p, 0x8A0) = 0;
        ClearWindowTilemapAndCopyToVram((u8 *)p + 0x8A4);
        RemoveWindow((u8 *)p + 0x8A4);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        GfGfx_EngineBTogglePlanes(4, 0);
        SetBgPriority(6, 2);
        G2x_SetBlendAlpha_(0x04000050, 4, 0x12, 7, 8);
        G2x_SetBlendAlpha_(0x04001050, 4, 0x12, 7, 8);
    }
}

void ov40_0222DEAC(void *p) {
    ClearWindowTilemapAndCopyToVram((u8 *)p + 0x8A4);
    RemoveWindow((u8 *)p + 0x8A4);
    GfGfx_EngineATogglePlanes(4, 0);
}

void ov40_0222DED0(void *p, int msgId) {
    void *win = (u8 *)p + 0x8A4;
    void *str;

    if (WORD(p, 0x8A0) != 1) {
        WORD(p, 0x8A0) = 1;
        ov40_0222C6C8(p, 2, 0);
        GfGfx_EngineATogglePlanes(4, 1);
        InitWindow(win);
        AddWindowParameterized(PTR(p, 0x24), win, 2, 1, 0x13, 0x1E, 4, 0xE, 0x20);
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        FillWindowPixelBuffer(win, 0xCC);
        AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
    }
}

void ov40_0222DF60(void *p, int msgId) {
    void *win = (u8 *)p + 0x8A4;
    void *str;

    if (WORD(p, 0x8A0) != 0) {
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        FillWindowPixelBuffer(win, 0xCC);
        AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
    }
}

void ov40_0222DFB0(void *p) {
    if (WORD(p, 0x8A0) != 0) {
        WORD(p, 0x8A0) = 0;
        ClearWindowTilemapAndCopyToVram((u8 *)p + 0x8A4);
        RemoveWindow((u8 *)p + 0x8A4);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        GfGfx_EngineATogglePlanes(4, 0);
    }
}

void ov40_0222DFE8(void *p, int msgId) {
    void *win = (u8 *)p + 0x8A4;
    void *str;

    if (WORD(p, 0x8A0) != 1 && WORD(p, 0x89C) != 1) {
        WORD(p, 0x8A0) = 1;
        WORD(p, 0x89C) = 1;
        *(vu16 *)0x04001050 = 0;
        SetBgPriority(6, 0);
        ov40_0222C6C8(p, 6, 0);
        GfGfx_EngineBTogglePlanes(4, 1);
        InitWindow(win);
        AddWindowParameterized(PTR(p, 0x24), win, 6, 1, 0x13, 0x1E, 4, 0xE, 0x20);
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        FillWindowPixelBuffer(win, 0xCC);
        AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
        ScheduleWindowCopyToVram(win);
        String_Delete(str);
    }
}
