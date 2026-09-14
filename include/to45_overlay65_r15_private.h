#ifndef TO45_OV65_R15_PRIVATE_H
#define TO45_OV65_R15_PRIVATE_H

#include "global.h"

typedef struct Window Window;
typedef struct String String;

typedef struct Ov65WindowPos {
    u16 x;
    u16 y;
} Ov65WindowPos;

typedef struct Ov65WindowSpec {
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 baseTile;
} Ov65WindowSpec;

typedef struct Ov65ListTemplate {
    void *items;
    void (*callback)(u32, u32, u32);
    u32 unk8;
    void *window;
    u16 headerX;
    u16 itemX;
    u32 unk14;
    u32 reserved18;
    u32 reserved1C;
} Ov65ListTemplate;

typedef struct Ov65YesNoTemplate {
    void *window;
    u32 flags;
    u32 baseTile;
    u32 palette;
    u8 x;
    u8 y;
    u8 packed;
    u8 pad13;
} Ov65YesNoTemplate;

extern const Ov65WindowPos ov65_0222010C[14];
extern const Ov65WindowSpec ov65_02220144[8];
extern const Ov65ListTemplate ov65_022200EC;

void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
void FillWindowPixelBuffer(void *, u8);
void RemoveWindow(void *);
u32 Options_GetFrame(void *);
void LoadUserFrameGfx2(void *, u32, u16, u32, u8, u32);
void LoadUserFrameGfx1(void *, u32, u16, u32, u8, u32);
u32 FontID_String_GetWidth(u32, void *, u32);
u32 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
void *ReadMsgData_ExpandPlaceholders(void *, u32, void *, u32);
void DrawFrameAndWindow2(void *, u32, u16, u32);
void DrawFrameAndWindow1(void *, u32, u16, u32);
void ScheduleWindowCopyToVram(void *);
void String_Delete(void *);
void *YesNoPrompt_Create(u32);
void YesNoPrompt_InitFromTemplate(void *, const void *);
s32 YesNoPrompt_HandleInput(void *);
void YesNoPrompt_Destroy(void *);
void ov65_0221F890(u32);
void ov65_0221F8B4(void);
void ov65_0221FD20(u32, u32, u32);
void *ListMenuInit(const void *, u32, u32, u32);

void ov65_0221F8D0(void *, void *, void *);
void ov65_0221FAE0(void *);
void ov65_0221FB4C(Window *, String *, u32, s32, u32, u32);
u32 ov65_0221FB90(void *, u32, u32, u32, void *);
void *ov65_0221FC08(void *);
s32 ov65_0221FC54(void *, void *, u32 *, void **, u32);
void *ov65_0221FCA0(void *, u32, void *, void *);

#endif
