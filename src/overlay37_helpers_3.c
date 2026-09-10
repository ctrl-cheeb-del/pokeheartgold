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

void ov37_021E6818(void **sprites, u32 sel) {
    int i;
    for (i = 0; i < 8; i++) {
        if (i == (int)sel) {
            Sprite_SetAnimCtrlSeq(sprites[i], ov37_021E7A80[i].seq + 1);
        } else {
            Sprite_SetAnimCtrlSeq(sprites[i], ov37_021E7A80[i].seq);
        }
    }
}

void ov37_021E6848(Ov37SpriteHolder *holder, u32 arg1) {
    if (arg1 == 1) {
        Sprite_SetAnimCtrlSeq(holder->unk_20, 0x16);
    } else {
        Sprite_SetAnimCtrlSeq(holder->unk_20, 0x15);
    }
}

u32 ov37_021E6860(Ov37Work *work, u32 arg1) {
    ov37_021E65EC(work);
    if (sub_0203769C() == 0) {
        if (ov37_021E745C() != 1) {
            ov37_021E755C(work);
        }
    } else {
        ov37_021E755C(work);
    }
    ov37_021E73B4(work);
    ov37_021E72E8(&work->winB2, work->unk_4382, work->unk_43B4, 1);
    return arg1;
}

void ov37_021E68AC(Ov37Work *work) {
    ov37_021E73B4(work);
    ov37_021E72E8(&work->winB2, work->unk_4382, work->unk_43B4, 0);
}

u32 ov37_021E68D0(Ov37Work *work, u32 arg1) {
    if (work->unk_0320 == sub_0203769C()) {
        ov37_021E762C(work, 0xD, 0);
    } else {
        ov37_021E762C(work, 0, 0);
    }
    ov37_021E7844(work, 2);
    PlaySE(0x5E4);
    G2x_SetBlendBrightness_((volatile u16 *)0x04000050, 0xE, -6);
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6928(Ov37Work *work, u32 arg1) {
    int i;
    for (i = 0; i < 5; i++) {
        Sprite_SetDrawFlag(work->sprites[i], 0);
    }
    return arg1;
}

u32 ov37_021E694C(Ov37Work *work, u32 arg1) {
    OV37_BLDCNT = 0;
    ov37_021E76D0(work, 1);
    ov37_021E7844(work, 4);
    ov37_021E68AC(work);
    work->unk_9404 = 0;
    return arg1;
}

u32 ov37_021E6980(Ov37Work *work, u32 arg1) {
    Ov37YesNoTemplate tmpl;
    if (ov37_021E76A0(work->printerId)) {
        MI_CpuFill8(&tmpl, 0, sizeof(Ov37YesNoTemplate));
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
        ov37_021E7844(work, 6);
    }
    ov37_021E68AC(work);
    return arg1;
}
