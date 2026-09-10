#include "field_application_tasks_internal.h"

void sub_0205A034(void *p, FieldCallback callback, int state) {
    *(FieldCallback *)((u8 *)p + 0x10) = callback;
    *(int *)((u8 *)p + 0x14) = state;
}
