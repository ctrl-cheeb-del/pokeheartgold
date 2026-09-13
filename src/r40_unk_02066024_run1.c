#include "r40_unk_02066024_private.h"

void sub_02066024(LocalMapObject *object) {
    FollowState *state = (FollowState *)sub_0205F394(object);

    if (sub_02066150(object, state) != 0) {
        while (_020FE3D4[state->state](object, state) == TRUE) {
        }
    }
}
