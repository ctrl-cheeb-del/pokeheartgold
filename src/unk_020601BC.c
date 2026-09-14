#include "unk_020601BC_internal.h"

void sub_020601BC(LocalMapObject *object, u8 behavior) {
    u32 id = MapObject_GetID(object);
    int x;
    int z;
    u8 facing;
    FieldSystem *fieldSystem;
    u32 nextBehavior;

    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        if (id != 0xFD || MapObject_TestFlagsBits(object, (MapObjectFlagBits)0x200) != TRUE) {
            ov01_021FF070(object, 0);
        } else {
            return;
        }
    }
    if (MapObject_GetID(object) != 0xFD || ov01_022055DC(object) == FALSE) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    fieldSystem = MapObject_GetFieldSystem(object);
    if ((u8)(facing + 0xFE) > 1) {
        return;
    }
    ov01_02205604(object, &x, &z);
    nextBehavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass((u8)nextBehavior) == TRUE) {
        ov01_021FF0E4(object, 0, x, z, 1);
        return;
    }
    if (MetatileBehavior_IsVeryTallGrass((u8)nextBehavior) == TRUE) {
        ov01_021FF964(object, 0, x, z, 1);
    }
}

void sub_02060274(LocalMapObject *object, u8 behavior) {
    u32 id = MapObject_GetID(object);
    int x;
    int z;
    u8 facing;
    FieldSystem *fieldSystem;
    u32 nextBehavior;

    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        if (id != 0xFD || MapObject_TestFlagsBits(object, (MapObjectFlagBits)0x200) != TRUE) {
            ov01_021FF070(object, 1);
        } else {
            return;
        }
    }
    if (MapObject_GetID(object) != 0xFD || ov01_022055DC(object) == FALSE) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    fieldSystem = MapObject_GetFieldSystem(object);
    if ((u8)(facing + 0xFE) > 1) {
        return;
    }
    ov01_02205604(object, &x, &z);
    nextBehavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass((u8)nextBehavior) == TRUE) {
        ov01_021FF0E4(object, 1, x, z, 1);
        return;
    }
    if (MetatileBehavior_IsVeryTallGrass((u8)nextBehavior) == TRUE) {
        ov01_021FF964(object, 1, x, z, 1);
    }
}

void sub_02060328(LocalMapObject *object, int unused, u32 value, const u16 *data) {
    u32 kind = ((u32)*data << 21) >> 28;

    if (kind == 0) {
        return;
    }
    if (sub_0205BA94(value) == TRUE) {
        kind = ((u32)*data << 21) >> 28;
        if (kind == 1) {
            ov01_021FE3E8(object);
        } else if (kind == 2) {
            ov01_021FE3F4(object);
        }
    }
    if (sub_02060EA4(object, value) == TRUE) {
        kind = ((u32)*data << 21) >> 28;
        if (kind == 1) {
            ov01_021FE3C4(object);
            return;
        } else if (kind == 2) {
            ov01_021FE3D0(object);
            return;
        }
    } else if (sub_02060ED4(object, value) == TRUE) {
        ov01_021FE3DC(object);
    }
}
