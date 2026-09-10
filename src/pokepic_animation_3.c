#include "pokepic_animation_internal.h"

void *sub_020171F4(void **array, int index, int expected) {
    void *value = array[index];
    GF_ASSERT(expected == 1);
    return value;
}

void *sub_02017208(void **array, int expected) {
    return sub_020171F4(array, 0, expected);
}

void *sub_02017214(void **array) {
    return sub_02017208(array, 1);
}
