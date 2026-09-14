#include "global.h"

#include "bg_window.h"
#include "menu_input_state.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "render_window.h"
#include "text.h"
#include "yes_no_prompt.h"

typedef struct Ov31R9Work {
    u8 padding_000[4];
    BgConfig *bgConfig;
    u8 padding_008[0xC];
    u8 *data;
    u8 padding_018[4];
    u8 *menuOwner;
    u8 padding_020[0x124];
    Window window;
    MessageFormat *messageFormat;
    MsgData *msgData;
    u8 padding_15C[8];
    Options *options;
    u8 padding_168[8];
    YesNoPrompt *prompt;
    u8 padding_174[0x14];
    String *expanded;
} Ov31R9Work;

void ov31_0225E700(Ov31R9Work *work);

void ov31_0225E700(Ov31R9Work *work) {
    YesNoPromptTemplate template;

    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = work->bgConfig;
    template.bgId = 5;
    template.tileStart = 0x60;
    template.plttSlot = 8;
    template.x = 0x1A;
    template.y = 6;
    template.ignoreTouchFlag = MenuInputStateMgr_GetState((MenuInputStateMgr *)(work->menuOwner + 0x10C));
    template.initialCursorPos = 0;
    template.shapeParam = 0;
    BgClearTilemapBufferAndCommit(work->bgConfig, 5);
    work->prompt = YesNoPrompt_Create((enum HeapID)8);
    YesNoPrompt_InitFromTemplate(work->prompt, &template);
}
