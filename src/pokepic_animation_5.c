#include "pokepic_animation_internal.h"

void sub_02017504(PicEntry *data) {
    u8 dst, src;
    sub_020172B4(data, &dst, &src);
    data->vars[dst] = data->vars[src];
}

void sub_0201752C(PicEntry *data) {
    u8 dst;
    s32 a, b;
    sub_020172C8(data, &dst, &a, &b);
    data->vars[dst] = a + b;
}

void sub_02017550(PicEntry *data) {
    u8 dst;
    s32 a, b;
    sub_020172C8(data, &dst, &a, &b);
    data->vars[dst] = a * b;
}

void sub_02017578(PicEntry *data) {
    u8 dst;
    s32 a, b;
    sub_0201733C(data, &dst, &a, &b);
    data->vars[dst] = a - b;
}

void sub_0201759C(PicEntry *data) {
    u8 dst;
    s32 a, b;
    sub_0201733C(data, &dst, &a, &b);
    data->vars[dst] = a / b;
}

void sub_020175C4(PicEntry *data) {
    u8 dst;
    s32 a, b;
    sub_0201733C(data, &dst, &a, &b);
    data->vars[dst] = a % b;
}
