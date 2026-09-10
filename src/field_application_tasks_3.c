#include "field_application_tasks_internal.h"

BOOL sub_02059738(const void *p) {
    return *((const u8 *)p + 0x89) == 3;
}

void *sub_02059748(const void *p) {
    u32 size = sub_02070D90();
    return *(void **)((u8 *)*(void **)((const u8 *)p + 0x48) + size * 3);
}
