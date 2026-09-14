#include "to45_overlay65_r15_private.h"

u32 ov65_0221FB90(void *window, u32 message, u32 framed, u32 format, void *msgData) {
    void *string = ReadMsgData_ExpandPlaceholders(msgData, format, (void *)message, 0x1A);
    u32 printer;
    if (framed == 1) {
        DrawFrameAndWindow2(window, 1, 0x3D9, 0xA);
    } else {
        DrawFrameAndWindow1(window, 1, 0x3F7, 0xB);
    }
    FillWindowPixelBuffer(window, 0xF);
    printer = AddTextPrinterParameterizedWithColor(window, framed, string, 0, 0, 0xFF, 0x1020F, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(string);
    return printer;
}

void *ov65_0221FC08(void *window) {
    Ov65YesNoTemplate template;
    void *prompt;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.window = window;
    template.flags = 0;
    template.baseTile = 0x180;
    template.palette = 0xE;
    template.x = 0x1A;
    template.y = 0xA;
    template.packed &= ~0xF;
    template.packed &= ~0xF0;
    prompt = YesNoPrompt_Create(0x1A);
    YesNoPrompt_InitFromTemplate(prompt, &template);
    return prompt;
}

s32 ov65_0221FC54(void *window, void *unused, u32 *state, void **prompt, u32 doExtra) {
    s32 result = -1;
    switch (*state) {
    case 0:
        *prompt = ov65_0221FC08(window);
        if (doExtra != 0) {
            ov65_0221F890(doExtra);
        }
        (*state)++;
        break;
    case 1:
        result = YesNoPrompt_HandleInput(*prompt);
        if (result != 0) {
            YesNoPrompt_Destroy(*prompt);
            ov65_0221F8B4();
            *state = 0;
        }
        break;
    }
    return result;
}

void *ov65_0221FCA0(void *items, u32 count, void *window, void *bg) {
    Ov65ListTemplate template;
    AddWindowParameterized(bg, window, 0, 0x13, 1, 0xC, 0xA, 0xD, 0x34D);
    DrawFrameAndWindow1(window, 0, 0x3F7, 0xB);
    template = ov65_022200EC;
    template.headerX = count + 1;
    template.itemX = 5;
    template.callback = ov65_0221FD20;
    template.items = items;
    template.window = window;
    return ListMenuInit(&template, 0, 0, 0x1A);
}
