#include "global.h"

#include "r40_overlay_103_residual_9_private.h"

u32 ov103_021ED4D4(R40Ov103Work9 *work) {
    u32 result = YesNoPrompt_HandleInput(*(YesNoPrompt **)(work->ctx + 0x238));
    switch (result) {
    case 1:
        YesNoPrompt_Reset(*(YesNoPrompt **)(work->ctx + 0x238));
        return ov103_021EEC68[*(u32 *)(work->ctx + 0x23C)][0](work);
    case 2:
        YesNoPrompt_Reset(*(YesNoPrompt **)(work->ctx + 0x238));
        return ov103_021EEC68[*(u32 *)(work->ctx + 0x23C)][1](work);
    default:
        return 4;
    }
}
