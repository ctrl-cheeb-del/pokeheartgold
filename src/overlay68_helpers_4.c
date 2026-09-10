#include "overlay68_helpers_internal.h"

void ov68_021E5E94(MoveRelearner *d) {
    u32 i;
    Window *window;
    YesNoPrompt_Destroy(d->unk_118);
    for (i = 0, window = d->windows; i < 15; i++, window++) {
        RemoveWindow(window);
    }
    FontID_Release(4);
}

void ov68_021E5EBC(MoveRelearner *d) {
    d->msgData = NewMsgDataFromNarc(0, 0x1b, 0x2EB, HEAP_ID_66);
    d->msgFmt = MessageFormat_New(HEAP_ID_66);
    d->unk_100 = String_New(256, HEAP_ID_66);
    d->unk_104 = NewString_ReadMsgData(d->msgData, 0x19);
    d->unk_108 = NewString_ReadMsgData(d->msgData, 0x1F);
}

void ov68_021E5F18(MoveRelearner *d) {
    DestroyMsgData(d->msgData);
    MessageFormat_Delete(d->msgFmt);
    String_Delete(d->unk_100);
    String_Delete(d->unk_104);
    String_Delete(d->unk_108);
}

u32 ov68_021E5F50(MoveRelearner *d) {
    if (IsPaletteFadeFinished() == TRUE) {
        return d->state;
    }
    return 0;
}
