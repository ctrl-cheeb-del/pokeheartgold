#include "apricorn_mix_internal.h"

int sub_02031D80(UnkStruct_02031CEC *data) {
    ApricornMix *mix = (ApricornMix *)data;
    int i;
    u16 total = 0;
    for (i = 0; i < 5; i++) {
        total += mix->values[i];
    }
    if (total > 100) {
        total = 100;
    }
    return (u8)total;
}
