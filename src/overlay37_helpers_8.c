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

u32 ov37_021E75C4(void) {
    int i;
    u32 count = 0;
    for (i = 0; i < 5; i++) {
        if (sub_02034818(i)) {
            count++;
        }
    }
    return count;
}

u32 ov37_021E75E0(void) {
    return ov37_021E75C4();
}

u32 ov37_021E75E8(Ov37Work *work) {
    int i;
    u32 changed = 0;
    for (i = 0; i < 5; i++) {
        work->pair[i].prev = work->pair[i].cur;
        work->pair[i].cur = sub_02034818(i);
    }
    for (i = 0; i < 5; i++) {
        if (work->pair[i].prev != work->pair[i].cur) {
            changed = 1;
        }
    }
    return changed;
}
