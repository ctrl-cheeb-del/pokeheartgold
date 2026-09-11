#include "map_object_state_update_internal.h"

#define IS_GROUND_EFFECT_TILE(object, behavior)                                                           \
    (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE \
        || sub_02060E54(object, behavior) == TRUE || MetatileBehavior_IsPuddle(behavior) == TRUE          \
        || MetatileBehavior_IsShallowWater(behavior) == TRUE || sub_02060EBC(object, behavior) == TRUE    \
        || MetatileBehavior_IsMud(behavior) == TRUE || MetatileBehavior_IsReflective(behavior) != FALSE)

void sub_0206064C(LocalMapObject *object, int behavior) {
    if (sub_02060E54(object, behavior) == TRUE
        || MetatileBehavior_IsShallowWater(behavior) == TRUE
        || MetatileBehavior_IsIce(behavior) == TRUE
        || MetatileBehavior_IsMud(behavior) == TRUE
        || sub_02060EBC(object, behavior) == TRUE
        || MapObject_CheckVisible(object) != FALSE) {
        return;
    }
    ov01_021FF74C(object);
}
