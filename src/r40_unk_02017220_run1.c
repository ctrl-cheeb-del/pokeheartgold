#include "r40_unk_02017220_private.h"

Unk02017220Entry *sub_02017220(Unk02017220Root *root, int index) {
    u8 i;

    for (i = 0; i < 4; i++) {
        Unk02017220Entry *entry = &root->entries[i];
        if (entry->active == 0) {
            MI_CpuFill8(entry, 0, sizeof(Unk02017220Entry));
            entry->active = 1;
            entry->value = _020F61BC[index].value;
            return entry;
        }
    }
    GF_AssertFail();
    return NULL;
}
