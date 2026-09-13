#include "r40_unk_02059F78_private.h"

void sub_02059F78(void *p) {
    u8 *profile;
    if (*(int *)((u8 *)p + 0x14) > 0) {
        *(int *)((u8 *)p + 0x14) -= 1;
        return;
    }

    _021D41CC[0]++;
    profile = sub_02035878();
    if (sub_020376F8() != 0 && sub_02059F54() == TRUE && profile[0x1C] != 4) {
        sub_02034434();
        sub_020398D4(1, 1);
        sub_0205A904(11);
        sub_0205A034(p, sub_02059FF8, 0);
    }

    if (sub_02037FCC() == 0) {
        sub_02037FF0();
        sub_0205ABBC(p);
        sub_0205A904(0);
        sub_0205A034(p, sub_02059F30, 2);
    }
}

void sub_02059FF8(void *p) {
    if (sub_02039918() != 0) {
        if (sub_020376F8() == 0) {
            return;
        }
    }
    if (sub_020376F8() == 0) {
        sub_02037FF0();
        sub_0205ABBC(p);
        sub_0205A904(0);
        sub_0205A034(p, sub_02059F30, 2);
    }
}
