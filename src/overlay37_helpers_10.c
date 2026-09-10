#include "overlay_37_helpers_internal.h"

typedef struct Ov37Hw {
    u8 pad[0x3FF8];
    u32 flag;
} Ov37Hw;

#define OV37_HW     ((volatile u32 *)0x027E0000)
#define OV37_BLDCNT (*(volatile u16 *)0x04000050)

typedef struct Ov37AnimEntry {
    u16 unk_00;
    u16 unk_02;
    u16 seq;
} Ov37AnimEntry;

extern const Ov37AnimEntry ov37_021E7A80[];

void ov37_021E7844(Ov37Work *work, u32 state) {
    work->state = state;
}

void ov37_021E784C(Ov37Work *work, u32 arg1) {
    u32 state = work->state;
    if (work->prevState != state) {
        if (arg1 != 2) {
            work->prevState = state;
        } else if (ov37_021E7D20[state].unk_04 != 0) {
            work->prevState = state;
        }
    }
}

u32 ov37_021E7880(Ov37Work *work, const Ov37YesNoTemplate *tmpl) {
    if (work->yesNoActive == 0) {
        YesNoPrompt_InitFromTemplate(work->yesNoPrompt, tmpl);
        work->yesNoActive = 1;
        return 1;
    }
    return 0;
}

void ov37_021E78A4(Ov37Work *work) {
    if (work->yesNoActive != 0) {
        YesNoPrompt_Reset(work->yesNoPrompt);
        work->yesNoActive = 0;
    }
}

u32 ov37_021E78C4(void) {
    if (TouchscreenHitbox_FindRectAtTouchNew(_021E7968) != (u32)-1) {
        return 1;
    }
    return 0;
}
