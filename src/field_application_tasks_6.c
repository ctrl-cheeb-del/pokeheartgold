#include "field_application_tasks_internal.h"

int sub_02059AD8(const void *p) {
    return sub_0200E5D4(*(void **)((const u8 *)p + 0x7C), 1);
}

void sub_02059AE4(int id, int unused1, int unused2, void *context) {
    u8 *env = sub_0205969C(context);
    if (*(u16 *)(env + 0x86) != id) {
        env[0x89] |= 2;
    }
}

u32 sub_02059B08(void) {
    u32 size = sub_02070D90();
    return size * 3 + 4;
}

void *sub_02059B18(int id, void *context) {
    u8 *env = sub_0205969C(context);
    if (*(u16 *)(env + 0x86) != id) {
        return *(void **)(env + 0x48);
    }
    return NULL;
}

void sub_02059B34(int id, int unused, const u8 *value, void *context) {
    u8 *env = sub_0205969C(context);
    if (*(u16 *)(env + 0x86) != id) {
        env[0x85] = *value;
        env[0x89] |= 2;
    }
}
