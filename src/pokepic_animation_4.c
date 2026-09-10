#include "pokepic_animation_internal.h"

void sub_0201726C(PicEntry *data, u32 *out) {
    data->cursor++;
    *out = (u32)sub_02017214(data->cursor);
}

void sub_02017280(PicEntry *data, u8 *out) {
    data->cursor++;
    *out = (u8)(u32)sub_02017214(data->cursor);
}

void sub_02017294(PicEntry *data, u8 *out) {
    data->cursor++;
    *out = (u8)(u32)sub_02017214(data->cursor);
    GF_ASSERT(*out < 8);
}

void sub_020172B4(PicEntry *data, u8 *a, u8 *b) {
    sub_02017294(data, a);
    sub_02017294(data, b);
}
