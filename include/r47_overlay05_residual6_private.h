#ifndef TO47_OV05_RESIDUAL6_PRIVATE_H
#define TO47_OV05_RESIDUAL6_PRIVATE_H
#include "global.h"

typedef struct Overlay05State {
    u8 data[0xB81];
    u8 stateTimer;
    u8 stateStep;
    u8 rest[0x7D];
} Overlay05State;
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

int ov05_0221E9F8(Overlay05State *);
void ov05_0221E9C4(Overlay05State *);
void ov05_0221EA18(Overlay05State *);
void ov05_0221EA38(Overlay05State *);
int ov05_0221CCF4(void *);
void ov05_0221E564(Overlay05State *, s32);
void ov05_0221DE6C(Overlay05State *, u32);
void ReadMsgDataIntoString(void *, u32, void *);
u8 AddTextPrinterParameterized(void *, u32, void *, u32, u32, u32, void *);
void FillWindowPixelRect(void *, u32, u32, u32, u32, u32);
void ClearFrameAndWindow2(void *, u32);
void ScheduleBgTilemapBufferTransfer(void *, u32);
void PlaySE(u16);
void GfGfx_EngineATogglePlanes(u32, u32);
void sub_02037AC0(u32);
BOOL sub_02037B38(u32);
u32 sub_0202FE14(void *, u32, u32, u32, void *, void *);
void PaletteData_CopyPalette(void *, u32, u16, u32, u16, u16);
void PaletteData_SetSelectedBufferAll(void *, BOOL);
int ov05_0221C908(Overlay05State *);
int ov05_0221CAB8(Overlay05State *);
int ov05_0221CB70(Overlay05State *);
int ov05_0221CC04(Overlay05State *);
#endif
