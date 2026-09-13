#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9488(void *p) {
    PromptTemplate template;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = PTR(p, 0x438);
    template.bgId = 4;
    template.tileStart = 0x3a6;
    template.palette = 14;
    template.x = 26;
    template.y = 4;
    template.paletteNum = U32(p, 0x10);
    template.unused = 0;
    template.initialCursorPos = 0;
    YesNoPrompt_InitFromTemplateWithPalette(PTR(p, 0x514), &template);
}

int ov108_021E94E8(void *p) {
    int out;
    switch (YesNoPrompt_HandleInput(PTR(p, 0x514))) {
    case 1:
        out = 1;
        break;
    case 2:
        out = 0;
        break;
    default:
        return -1;
    }
    U32(p, 0x10) = YesNoPrompt_IsInTouchMode(PTR(p, 0x514));
    YesNoPrompt_Reset(PTR(p, 0x514));
    return out;
}
