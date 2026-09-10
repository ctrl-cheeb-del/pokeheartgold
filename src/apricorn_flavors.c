#include "apricorn_internal.h"

void sub_020324F4(UnkStruct_02031CEC *data, u8 *out);
u8 sub_02032504(int type, u8 value);
void sub_02032588(u16 *out, u8 *pair, int type);
void sub_020325CC(void *data);

void sub_020324F4(UnkStruct_02031CEC *data, u8 *out) {
    int i;
    ApricornMix *mix = (ApricornMix *)data;
    for (i = 0; i < 5; i++) {
        out[i] = mix->values[i];
    }
}

u8 sub_02032504(int type, u8 value) {
    if (value == 0) {
        return 0;
    }
    switch (type) {
    case 0:
        if (value > 62) {
            return 6;
        }
        if (value > 50) {
            return 5;
        }
        if (value > 40) {
            return 4;
        }
        if (value > 30) {
            return 3;
        }
        if (value > 20) {
            return 2;
        }
        if (value != 0) {
            return 1;
        }
        break;
    case 1:
        if (value > 40) {
            return 4;
        }
        if (value > 30) {
            return 3;
        }
        if (value > 20) {
            return 2;
        }
        if (value != 0) {
            return 1;
        }
        break;
    case 2:
        if (value > 20) {
            return 3;
        }
        if (value > 10) {
            return 2;
        }
        if (value != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

void sub_02032588(u16 *out, u8 *pair, int type) {
    struct PackedMix {
        u16 index : 4;
        u16 strength : 4;
        u16 amount : 8;
    } *packed = (struct PackedMix *)out;
    packed->index = pair[0];
    packed->amount = pair[1];
    packed->strength = sub_02032504((u8)type, pair[1]);
}

void sub_020325CC(void *data) {
    u8 *bytes = data;
    MI_CpuFill8(data, 0, 0x20);
    sub_02031B5C(bytes + 0x18);
    StringFillEOS((u16 *)(bytes + 8), 8);
}
