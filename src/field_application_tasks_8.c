#include "field_application_tasks_internal.h"

void sub_02059F30(void *p) {
    if (sub_02038070() == TRUE) {
        sub_02091574(*(void **)p);
        sub_0205A034(p, sub_02059EBC, 2);
    }
}

BOOL sub_02059F54(void) {
    int i;
    int count = 0;
    i = 1;
    for (; i < 5; i++) {
        if (sub_02034818(i) != 0) {
            count++;
        }
    }
    return count >= 1;
}
