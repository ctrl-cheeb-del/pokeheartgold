#include "r40_unk_0205A03C_private.h"

void sub_0205A03C(void *task, FieldApplicationDataR40 *data) {
    struct {
        void *data;
    } local;
    s32 i;

    local.data = data;
    if (local.data == NULL) {
        SysTask_Destroy(task);
        return;
    }
    for (i = 0; i < 16; i++) {
        data->entries[i] = sub_02035754(i);
        *(void **)(_021D41D8 + i * 4) = data->entries[i];
    }
    if (((FieldApplicationDataR40 *)local.data)->callback != NULL) {
        ((FieldApplicationDataR40 *)local.data)->callback(local.data);
    }
}
