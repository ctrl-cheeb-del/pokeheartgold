#include "r40_unk_020616FC_private.h"

void sub_020616FC(LocalMapObject *object) {
    u8 *state = sub_0205F394(object);

    while (_020FD5D0[(s8)state[2]](object, state) == TRUE) {
    }
}
