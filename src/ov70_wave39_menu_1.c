#include "ov70_wave39_menu_private.h"

int ov70_02243458(void **out, void *msg, void *unused, void *arg, int id, void *dex) {
    int n;
    int i, count;
    u16 *ids = ov70_0223F658(0x3d, id, &n);
    u16 *p;
    count = ov70_0224342C(arg, dex, n, ids);
    *out = ListMenuItems_New(count + 1, 0x3d);
    i = 0;
    if (n > 0) {
        p = ids;
        do {
            if (Pokedex_CheckMonSeenFlag(dex, *p)) {
                ListMenuItems_AppendFromMsgData(*out, msg, *p, *p);
            }
            i++;
            p++;
        } while (i < (int)n);
    }
    Heap_Free(ids);
    return count;
}
