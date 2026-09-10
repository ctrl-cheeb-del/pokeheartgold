#include "field_application_tasks_internal.h"

u32 sub_0205A358(const void *p) {
    return *(const u32 *)((const u8 *)p + 0x1C);
}

int sub_0205A35C(const void *p) {
    if (*(const u32 *)((const u8 *)p + 0x44) != 0) {
        return 7;
    }
    if (sub_02037454() < 2) {
        return 7;
    }
    if (sub_0203769C() == 0) {
        if (sub_02037FCC() == TRUE) {
            return *(const int *)((const u8 *)p + 0x40);
        }
    } else if (sub_02037F94() == TRUE) {
        return *(const int *)((const u8 *)p + 0x40);
    }
    return 7;
}

int sub_0205A39C(const void *p) {
    if (sub_02037FCC() == TRUE) {
        return *(const int *)((const u8 *)p + 0x30);
    }
    return 7;
}
