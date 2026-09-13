#include "r40_unk_0205704C_private.h"

void sub_0205704C(int arg0, const Unk0205704CParams *params) {
    u8 data[8];
    u16 value0 = params->value0;
    u16 value1 = params->value1;

    if (value0 >= 0xF000) {
        value0 = 0xEFFF;
    }
    if (value1 >= 0xF000) {
        value1 = 0xEFFF;
    }
    data[0] = arg0 & 0xF;
    data[1] = value0;
    data[2] = ((value0 >> 8) & 1) + ((value1 >> 7) & 2);
    data[3] = value1;
    if (params->flag7 != 0) {
        data[2] |= 0x80;
    }
    data[0] += (params->signed4 % 4) << 4;
    data[0] += params->value5 << 6;
    sub_02037108(0x17, data, 0);
}
