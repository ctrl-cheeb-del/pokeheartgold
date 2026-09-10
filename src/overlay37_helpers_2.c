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

void ov37_021E6540(Ov37Work *work) {
    int i;
    Ov37Window *win;
    for (i = 0, win = work->windows; i < 5; i++, win++) {
        RemoveWindow(win);
    }
    RemoveWindow(&work->winBA);
    RemoveWindow(&work->winB2);
    RemoveWindow(&work->winB6);
}
