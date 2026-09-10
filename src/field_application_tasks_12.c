#include "field_application_tasks_internal.h"

void sub_0205A408(void) {
}

void sub_0205A40C(void) {
}

void sub_0205A410(int a0, int a1, int a2, void *context) {
    sub_0205A034(*(void **)((u8 *)context + 0x80), sub_02059EBC, 2);
    sub_0205ABBC(*(void **)((u8 *)context + 0x80));
}

void sub_0205A430(int a0, int a1, const u8 *value, void *context) {
    u8 *env = *(u8 **)((u8 *)context + 0x80);
    if (*(u32 *)(env + 0x44) == 0) {
        *(u32 *)(env + 0x30) = *value;
        *(u32 *)(_021D41CC + 8) = *value;
    }
}
