#include "field_application_tasks_internal.h"

void sub_020597D4(void *p) {
    u8 *data = p;
    u32 size = sub_02070D90();
    u8 source = data[0x84];
    u8 destination = data[0x85];
    int i;
    MI_CpuCopy8(*(u8 **)(data + 0x48) + source * size,
        *(u8 **)(data + 0x4C) + destination * size,
        size);
    Party_InitWithMaxSize(*(void **)(data + 0x50), 3);
    for (i = 0; i < 3; i++) {
        Party_AddMon(*(void **)(data + 0x50), *(u8 **)(data + 0x4C) + i * size);
    }
}
