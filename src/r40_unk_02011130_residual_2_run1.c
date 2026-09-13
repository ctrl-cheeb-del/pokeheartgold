#include "r40_unk_02011130_residual_2_private.h"

void sub_020117A0(Unk020117A0Dest *dest, const Unk020117A0Config *config, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    sub_02010AB0(dest, dest->data20, dest->data10, config, config->data4, arg2);
    dest->field30 = arg4;
    dest->field34 = config->a8;
    dest->field38 = arg2;
    dest->field3C = arg3;
    dest->field40 = 0;
    dest->field48 = arg5;
    dest->field44 = config->aB;
    sub_02010F84(arg5, config->a9, config->aA, config->a8, arg4, config->a0, config->a1, config->a2, config->a3, dest->field44);
}
