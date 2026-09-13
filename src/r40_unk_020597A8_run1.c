#include "r40_unk_020597A8_private.h"

void sub_020597A8(void *p) {
    u8 *data = p;
    u32 size = sub_02070D90();
    int i;
    Party_InitWithMaxSize(*(void **)(data + 0x50), 3);
    for (i = 0; i < 3; i++) {
        Party_AddMon(*(void **)(data + 0x50), *(u8 **)(data + 0x48) + i * size);
    }
}
