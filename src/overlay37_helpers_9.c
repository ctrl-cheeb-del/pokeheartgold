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

u32 ov37_021E76A0(u32 printerId) {
    if (printerId == 0xFF) {
        return 1;
    }
    if (!TextPrinterCheckActive((u8)printerId)) {
        return 1;
    }
    return 0;
}

void ov37_021E76C0(Ov37Work *work) {
    ClearFrameAndWindow2(&work->winB6, 0);
}

void ov37_021E76D0(Ov37Work *work, u32 arg1) {
#pragma unused(work)
    s32 v;
    if (!sub_0203769C()) {
        v = sub_02037454() + arg1;
        if (v > 5) {
            v = 5;
        }
        sub_02038C1C(v);
    }
}
