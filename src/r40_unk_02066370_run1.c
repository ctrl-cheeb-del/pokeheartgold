#include "global.h"

#include "r40_unk_02066370_private.h"

void sub_02066370(LocalMapObject *object) {
    MapObjectFollowState66370 *state = (MapObjectFollowState66370 *)sub_0205F394(object);

    state->state = 0;
    sub_02066420(object, 0);
    if (state->fixedFacing == 0) {
        VecFx32 facing = _020FE3E8;
        MapObject_SetFacingVector(object, &facing);
        MapObject_SetFlagsBits(object, (MapObjectFlagBits)(1 << 20));
    }
}
