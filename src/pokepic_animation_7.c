#include "pokepic_animation_internal.h"

void sub_02017B48(PicEntry *data) {
    data->flag1CD = 1;
}

void sub_02017B54(PicEntry *data) {
    u8 value;
    BOOL validA;
    BOOL validB;
    sub_02017280(data, &data->mode1CE);
    value = data->mode1CE;
    validA = TRUE;
    validB = TRUE;
    if (value != 0x1B && value != 0x1D) {
        validB = FALSE;
    }
    if (!validB && value != 0x1C) {
        validA = FALSE;
    }
    GF_ASSERT(validA);
}

void sub_02017B8C(PicEntry *data) {
    sub_02017C78(data, 0);
}

void sub_02017B98(PicEntry *data) {
    sub_02017C78(data, 1);
}

void sub_02017BA4(PicEntry *data) {
    sub_02017C78(data, 2);
}

void sub_02017BB0(PicEntry *data) {
    sub_02017C78(data, 3);
}

void sub_02017BBC(PicEntry *data) {
    sub_02017C78(data, 4);
}

void sub_02017BC8(int op, int *lhs, int *rhs, int *dst) {
    if (op == 0x18) {
        *dst = *rhs;
    } else if (op == 0x19) {
        *dst = *lhs + *rhs;
    } else if (op == 0x1A) {
        *dst += *rhs;
    } else {
        GF_ASSERT(FALSE);
    }
}
