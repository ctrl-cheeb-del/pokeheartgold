#include "global.h"

#include "bg_window.h"
#include "render_window.h"
#include "text.h"
#include "yes_no_prompt.h"

typedef struct Ov48PromptWorkR15 {
    u32 state;
    u32 printerId;
    u32 textSpeed;
    String *string;
    Window window;
    YesNoPrompt *prompt;
} Ov48PromptWorkR15;

extern const YesNoPromptTemplate ov48_0225B1C4;

void ov48_02259F48(Ov48PromptWorkR15 *);
int ov48_02259F8C(Ov48PromptWorkR15 *);

void ov48_02259F48(Ov48PromptWorkR15 *work) {
    FillWindowPixelBuffer(&work->window, 0xf);
    DrawFrameAndWindow2(&work->window, TRUE, 1, 2);
    ScheduleWindowCopyToVram(&work->window);
    work->printerId = AddTextPrinterParameterized(&work->window, (FontID)1, work->string, 0, 0, work->textSpeed, NULL);
    work->state = 0;
}

int ov48_02259F8C(Ov48PromptWorkR15 *work) {
    int result;

    switch (work->state) {
    case 0: {
        YesNoPromptTemplate template;
        result = 0;
        if (TextPrinterCheckActive((u8)work->printerId)) {
            break;
        }
        template = ov48_0225B1C4;
        template.bgConfig = GetWindowBgConfig(&work->window);
        YesNoPrompt_InitFromTemplate(work->prompt, &template);
        work->state++;
        break;
    }
    case 1:
        result = YesNoPrompt_HandleInput(work->prompt);
        break;
    }
    return result;
}
