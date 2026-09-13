#include "r40_unk_02066444_private.h"

int sub_02066444(int value) {
    FourValues group3 = _020FE3F4;
    FourValues group2 = _020FE434;
    FourValues group1 = _020FE444;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (value == group3.values[i]) {
            return 3;
        }
    }
    for (i = 0; i < 4; i++) {
        if (value == group2.values[i]) {
            return 2;
        }
    }
    for (i = 0; i < 4; i++) {
        if (value == group1.values[i]) {
            return 1;
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

void sub_020664D8(LocalMapObject *object) {
    FieldSystem *fieldSystem = MapObject_GetFieldSystem(object);
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    u32 behavior = GetMetatileBehavior(fieldSystem, x, z);

    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        ov01_021FF070(object, 0);
    } else if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE) {
        ov01_021FF8F0(object, 0);
    }

    if (ov01_022055DC(object) != 0) {
        u8 direction = MapObject_GetFacingDirection(object);
        if ((u8)(direction + 0xFE) <= 1) {
            ov01_02205604(object, &x, &z);
            behavior = GetMetatileBehavior(fieldSystem, x, z);
            if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
                ov01_021FF0E4(object, 1, x, z, 1);
                return;
            }
            if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE) {
                ov01_021FF964(object, 1, x, z, 1);
            }
        }
    }
}
