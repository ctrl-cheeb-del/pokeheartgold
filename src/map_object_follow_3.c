#include "map_object_follow_internal.h"

void sub_020659B8(LocalMapObject *object) {
    u16 *p = (u16 *)((u8 *)sub_0205F394(object) + 10);
    *p = (*p & ~1) | 1;
}
