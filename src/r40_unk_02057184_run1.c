#include "r40_unk_02057184_candidate_private.h"

void sub_0205724C(int slot, int keepActive, int deleteFromMap) {
    void *avatar;
    u8 *active;
    u8 *entry;
    if (_021D41C4 == NULL) {
        return;
    }
    avatar = *(void **)(_021D41C4->raw + slot * 4 + 4);
    if (avatar != NULL) {
        if (*(void **)(*(u8 **)(_021D41C4->raw + 0x30) + 0x40) != avatar) {
            if (deleteFromMap != 0) {
                PlayerAvatar_DeleteFromMap(avatar);
            } else {
                PlayerAvatar_FreeToHeap(avatar);
            }
        }
        *(void **)(_021D41C4->raw + slot * 4 + 4) = NULL;
    }
    active = &_021D41C4->raw[0x24];
    if (active[slot] != 0 && keepActive == 0) {
        active[slot] = 0;
    }
    entry = _021D41C4->raw + slot;
    entry[0xCC] = 1;
}
