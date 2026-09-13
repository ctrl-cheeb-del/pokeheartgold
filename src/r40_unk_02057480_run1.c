#include "r40_unk_02057480_private.h"

BOOL sub_02057480(int x, int z) {
    int count = Field_GetNumObjectEvents(*(void **)&_021D41C4->raw[0x30]);
    ObjectEvent57480 *events = Field_GetObjectEvents(*(void **)&_021D41C4->raw[0x30]);
    int i;
    for (i = 0; i < count; i++, events++) {
        if (x == events->x && z == events->z) {
            return TRUE;
        }
    }
    return FALSE;
}
