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

u32 ov37_021E6DD0(Ov37Work *work, u32 arg1) {
    BufferPlayersName(work->msgFormat, 0, sub_02034818(0));
    ov37_021E762C(work, 3, 1);
    ov37_021E7844(work, 0x10);
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6E04(Ov37Work *work, u32 arg1) {
    if (ov37_021E76A0(work->printerId)) {
        ov37_021E7844(work, 0x11);
        sub_02037AC0(0xC8);
    }
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6E2C(Ov37Work *work, u32 arg1) {
    if (sub_02037B38(0xC8) || sub_02037454() == 1) {
        BeginNormalPaletteFade(0, 0x10, 0x10, 0, 0x10, 1, 0x27);
        arg1 = 3;
    }
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6E6C(u32 arg0, u32 arg1) {
#pragma unused(arg0)
    return arg1;
}

u32 ov37_021E6E70(Ov37Work *work, u32 arg1) {
    ov37_021E762C(work, 5, 1);
    ov37_021E7844(work, 0x14);
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6E90(Ov37Work *work, u32 arg1) {
    if (ov37_021E76A0(work->printerId)) {
        ov37_021E7844(work, 0xC);
    }
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6EB4(Ov37Work *work, u32 arg1) {
    if (work->printerId != 0xFF && !ov37_021E76A0(work->printerId)) {
        RemoveTextPrinter((u8)work->printerId);
    }
    ov37_021E762C(work, 2, 1);
    ov37_021E7844(work, 0x16);
    PlaySE(0x5E4);
    if (!sub_0203769C()) {
        ov37_021E76D0(work, 0);
    }
    work->unk_93B0 = sub_02037454();
    ov37_021E68AC(work);
    return arg1;
}

u32 ov37_021E6F14(Ov37Work *work, u32 arg1) {
    if (work->unk_93B0 != 0) {
        if (work->unk_93B0 != sub_02037454()) {
            work->unk_93B0 = 0;
        }
    }
    if (ov37_021E76A0(work->printerId)) {
        ov37_021E7844(work, 0x17);
        work->counter = 0;
    }
    ov37_021E68AC(work);
    return arg1;
}
