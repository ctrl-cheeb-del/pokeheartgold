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

u32 ov37_021E6BFC(Ov37Work *work, u32 arg1) {
    work->flags &= ~0x38;
    work->unk_93BC = 0;
    ov37_021E7844(work, 4);
    ov37_021E6848(&work->holder, 0);
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6C38(Ov37Work *work, u32 arg1) {
    ov37_021E762C(work, 6, 1);
    ov37_021E7844(work, 0xB);
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6C58(Ov37Work *work, u32 arg1) {
    if (ov37_021E76A0(work->printerId)) {
        work->counter = 0;
        ov37_021E7844(work, 0xC);
    }
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6C84(Ov37Work *work, u32 arg1) {
    work->counter++;
    if ((s32)work->counter > 60) {
        BeginNormalPaletteFade(0, 0x10, 0x10, 0, 0x10, 1, 0x27);
        arg1 = 3;
    }
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6CC0(Ov37Work *work, u32 arg1) {
    Ov37YesNoTemplate tmpl;
    if (ov37_021E76A0(work->printerId)) {
        tmpl.bgConfig = work->bgConfig;
        tmpl.unk_04 = 0;
        tmpl.unk_08 = 0xB4;
        tmpl.unk_0C = 8;
        tmpl.unk_10 = 0x19;
        tmpl.unk_11 = 6;
        tmpl.unk_13 = 0;
        if (!ov37_021E7880(work, &tmpl)) {
            GF_AssertFail();
        }
        ov37_021E7844(work, 0xE);
    }
    ov37_021E68AC(work);
    return arg1;
}
