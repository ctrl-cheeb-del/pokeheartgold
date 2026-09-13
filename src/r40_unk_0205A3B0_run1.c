#include "r40_unk_0205A3B0_private.h"

void sub_0205A3B0(struct UnkStruct_02059E1C *work, int mode, int value) {
    u8 data[3];

    data[2] = value;
    switch (mode) {
    case 0:
        if (work->unk44 == 0) {
            work->unk34 = data[2];
            sub_02037030(0x63, &data[2], 1);
        }
        break;
    case 1:
        if (value == 0) {
            data[1] = work->unk30;
            sub_02037108(0x67, &data[1], 1);
            *(u32 *)&work->pad38[4] = value;
        } else {
            data[0] = 7;
            sub_02037108(0x67, &data[0], 1);
            *(u32 *)&work->pad38[4] = value;
        }
        break;
    }
}
