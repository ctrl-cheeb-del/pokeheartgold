#ifndef TO47_OVERLAY49_WINDOW_MENU_PRIVATE_H
#define TO47_OVERLAY49_WINDOW_MENU_PRIVATE_H

#include "global.h"

void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void DrawFrameAndWindow1(void *, int, int, int);
void FillWindowPixelBuffer(void *, int);
void ScheduleWindowCopyToVram(void *);
int WindowIsInUse(void *);
void sub_0200E5D4(void *, int);
void ClearWindowTilemapAndScheduleTransfer(void *);
void RemoveWindow(void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void FillWindowPixelRect(void *, int, int, int, int, int);
void GF_AssertFail(void);
void *ListMenuItems_New(int, int);
void *ov49_0225B388(void *, int, int);
void ListMenuItems_AddItem(void *, void *, int);

typedef struct Ov49MenuTemplate {
    u32 words[8];
} Ov49MenuTemplate;

extern const Ov49MenuTemplate ov49_022697AC;

void ov49_0225B0E0(void *, void **, int, int, u8, u8, u8);
void ov49_0225B124(void *);
void ov49_0225B148(void *, void *, int, int);
void ov49_0225B178(void *, int, int, int, u16);
void ov49_0225B198(void *, void *, int);

#endif
