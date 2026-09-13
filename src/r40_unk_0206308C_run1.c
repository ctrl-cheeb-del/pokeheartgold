#include "r40_unk_0206308C_private.h"

BOOL MapObjectMovementCmd076_Step1(void *mapObject, void *unused) {
    (void)unused;
    if (sub_02062FEC(mapObject, _020FDA50) == TRUE) {
        return TRUE;
    }
    return FALSE;
}
