#include "communication_manager_internal.h"

BOOL sub_02036630(void) {
    int count = sub_02033FC4((u16)sub_0203993C()) + 1;
    int i;
    for (i = 1; i < count; i++) {
        if (sub_020373B4((u16)i) && *(int *)(_021D4140.work + 0x66C + i * 4) > 3) {
            return FALSE;
        }
    }
    return TRUE;
}
