#include "global.h"

#include "r40_overlay_109_residual_14_private.h"

void ov109_021E75C8(R40PhotoApp14 *app) {
    TouchscreenListMenuHeader header;
    MI_CpuFill8(&header, 0, sizeof(header));
    header.template = ov109_021E789C;
    header.listMenuItems = FPTR(app, 0x88, ListMenuItem);
    header.bgConfig = FPTR(app, 0x14, BgConfig);
    header.numWindows = 4;
    FPTR(app, 0x84, TouchscreenListMenu) = TouchscreenListMenu_Create(FPTR(app, 0x80, TouchscreenListMenuSpawner), &header, (u8)F32(app, 0xC), 0x18, 0xB, 6, 0);
    ov109_021E7474(app, F8(app, 0x1B), F8(app, 0x1C), 0);
}

int ov109_021E7640(R40PhotoApp14 *app) {
    int result = TouchscreenListMenu_HandleInput(FPTR(app, 0x84, TouchscreenListMenu));
    u32 touch;
    if (result == -1) {
        return -1;
    }
    touch = TouchscreenListMenu_WasLastInputTouch(FPTR(app, 0x84, TouchscreenListMenu));
    TouchscreenListMenu_Destroy(FPTR(app, 0x84, TouchscreenListMenu));
    if (F32(app, 0xC) != touch) {
        ov109_021E75B4(app);
    }
    switch (result) {
    case 0:
        ((u8 *)FPTR(app, 0x10, void))[1] = 1;
        ((u8 *)FPTR(app, 0x10, void))[2] = F8(app, 0x1F);
        return 8;
    case 1:
        ov109_021E73F8(app, 4, 0, 0);
        F8(app, 0x20) = 2;
        return 7;
    case 2:
        ov109_021E7474(app, F8(app, 0x1B), F8(app, 0x1C), 1);
        ov109_021E73F8(app, 2, 0, 0);
        F8(app, 0x20) = 1;
        return 5;
    default:
        ov109_021E7248(app, 0);
        ov109_021E74D4(app, 0);
        ov109_021E7474(app, F8(app, 0x1B), F8(app, 0x1C), 1);
        return 1;
    }
}

void ov109_021E76F0(R40PhotoApp14 *app) {
    YesNoPromptTemplate template;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = FPTR(app, 0x14, BgConfig);
    template.bgId = 0;
    template.tileStart = 0x7A;
    template.plttSlot = 0xE;
    template.x = 0x19;
    template.y = 0x10;
    template.ignoreTouchFlag = (u8)F32(app, 0xC);
    template.initialCursorPos = 1;
    YesNoPrompt_InitFromTemplate(FPTR(app, 0x8C, YesNoPrompt), &template);
}

int ov109_021E7748(R40PhotoApp14 *app) {
    int result = YesNoPrompt_HandleInput(FPTR(app, 0x8C, YesNoPrompt));
    switch (result) {
    case 1:
        ov109_021E5DEC(app, F8(app, 0x1F));
        break;
    case 2:
        break;
    default:
        return 7;
    }
    {
        u32 touch = YesNoPrompt_IsInTouchMode(FPTR(app, 0x8C, YesNoPrompt));
        if (touch != F32(app, 0xC)) {
            F32(app, 0xC) = touch;
        }
    }
    YesNoPrompt_Reset(FPTR(app, 0x8C, YesNoPrompt));
    ov109_021E74D4(app, 0);
    if (result == 1) {
        ov109_021E70C4(app, 3, 3, F8(app, 0x19));
        ov109_021E7524(app);
    }
    ov109_021E7474(app, F8(app, 0x1B), F8(app, 0x1C), 1);
    ov109_021E7248(app, 0);
    ov109_021E73F8(app, 0, 0, 0);
    F8(app, 0x20) = 0;
    return 1;
}
