#include "map_object_movement_lookup_internal.h"

const int *sub_02061E6C(int id) {
    const MovementListEntry *entry = _020FD838;
    int current = 0;

    while (current != 0x27) {
        if (current == id) {
            return entry->list;
        }
        entry++;
        current = entry->id;
    }
    GF_ASSERT(FALSE);
    return NULL;
}
