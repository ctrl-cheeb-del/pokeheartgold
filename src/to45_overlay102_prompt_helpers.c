#include "to45_overlay102_prompt_helpers_private.h"

void ov102_021EAFF0(u8 *p, u16 index) {
    VecFx32 matrix;
    s16 position[2];
    int delta;
    float offset;

    if (*(void **)(p + 0x8c) != NULL) {
        ov102_021EAD5C(p + 0x84 + index * 4, position);
        matrix.x = position[0] << FX32_SHIFT;
        matrix.y = position[1] << FX32_SHIFT;
        matrix.z = 0;
    } else {
        matrix.x = 128 << FX32_SHIFT;
        matrix.y = 24 << FX32_SHIFT;
        matrix.z = 0;
    }
    Sprite_SetMatrix(*(Sprite **)(p + 0x60), &matrix);
    delta = 192 - *(s16 *)(p + 0x1e2);
    if (delta > 0) {
        offset = (float)(delta << FX32_SHIFT) + 0.5f;
    } else {
        offset = (float)(delta << FX32_SHIFT) - 0.5f;
    }
    matrix.y += (fx32)offset;
    Sprite_SetMatrix(*(Sprite **)(p + 0x64), &matrix);
    ov102_021EB088(p, 1);
}

void ov102_021EB088(u8 *p, int enabled) {
    if (*(void **)(p + 0x8c) != NULL) {
        if (enabled != 0) {
            Sprite_SetAnimCtrlSeq(*(Sprite **)(p + 0x60), 0);
        } else {
            Sprite_SetAnimCtrlSeq(*(Sprite **)(p + 0x60), 1);
        }
    } else {
        if (enabled != 0) {
            Sprite_SetAnimCtrlSeq(*(Sprite **)(p + 0x60), 14);
        } else {
            Sprite_SetAnimCtrlSeq(*(Sprite **)(p + 0x60), 15);
        }
    }
}

void ov102_021EB0C0(u8 *p, int initialCursorPos) {
    YesNoPromptTemplate template;
    void *bgConfig;
    u8 value;

    bgConfig = ov102_021EA268(*(void **)p);
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgId = 0;
    template.bgConfig = bgConfig;
    template.tileStart = *(u16 *)(p + 0x1ee);
    template.plttSlot = 3;
    template.x = 25;
    template.y = 12;
    value = **(u32 **)(p + 0x1f0);
    template.ignoreTouchFlag = value;
    template.initialCursorPos = (u8)initialCursorPos;
    YesNoPrompt_InitFromTemplate(*(YesNoPrompt **)(p + 0x1e8), &template);
}

int ov102_021EB130(u8 *p) {
    int result;

    switch (YesNoPrompt_HandleInput(*(YesNoPrompt **)(p + 0x1e8))) {
    case YESNORESPONSE_YES:
        result = TRUE;
        break;
    case YESNORESPONSE_NO:
        result = FALSE;
        break;
    default:
        return -1;
    }
    YesNoPrompt_IsInTouchMode(*(YesNoPrompt **)(p + 0x1e8));
    YesNoPrompt_Reset(*(YesNoPrompt **)(p + 0x1e8));
    return result;
}
