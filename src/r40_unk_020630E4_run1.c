#include "r40_unk_020630E4_private.h"

BOOL MapObjectMovementCmd082_Step1(void *mapObject, void *unused) {
    (void)unused;
    if (sub_02062FEC(mapObject, _020FDA1C) == TRUE) {
        return TRUE;
    }
    return FALSE;
}
