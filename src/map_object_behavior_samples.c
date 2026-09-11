#include "map_object_behavior_samples_internal.h"

void sub_020607D8(LocalMapObject *object, u8 behavior, int unused, const MovementEffect *effect) {
    u8 selected;

    if (effect->kind != 0) {
        if (MapObject_CheckFlag24(object) != TRUE) {
            selected = GetMetatileBehavior_None();

            if (MapObject_GetID(object) == 0xFD) {
                if (ov01_022055DC(object) != 0) {
                    u8 foundBehavior;
                    u8 first;
                    u8 second;
                    u8 third;
                    u8 fourth;
                    u8 fifth;
                    int found;
                    int kind;

                    if (MapObject_CheckFlag24(object) != FALSE) {
                        return;
                    }
                    if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                        selected = behavior;
                    } else {
                        first = sub_02060FA8(object, 1);
                        second = sub_02060FA8(object, 3);
                        third = sub_02060FA8(object, 2);
                        fourth = ov01_022056C4(object, 4);
                        fifth = ov01_022056C4(object, 5);
                        found = FALSE;
                        if (MetatileBehavior_HasReflectiveSurface(first) == TRUE) {
                            foundBehavior = first;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(second) == TRUE) {
                            foundBehavior = second;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(third) == TRUE) {
                            foundBehavior = third;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(fourth) == TRUE) {
                            foundBehavior = fourth;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(fifth) == TRUE) {
                            foundBehavior = fifth;
                            found = TRUE;
                        }
                        if (found == TRUE) {
                            selected = foundBehavior;
                        }
                    }
                    if (selected == GetMetatileBehavior_None()) {
                        return;
                    }
                    MapObject_SetFlag24(object, TRUE);
                    if (MetatileBehavior_IsReflective(selected) == TRUE) {
                        kind = 5;
                    } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                        kind = 3;
                    } else {
                        kind = 4;
                    }
                    ov01_021FDF88(object, kind);
                } else {
                    int kind;
                    if (MapObject_CheckFlag24(object) != FALSE) {
                        return;
                    }
                    if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                        selected = behavior;
                    } else {
                        u8 adjacent = sub_02060FA8(object, 1);
                        if (MetatileBehavior_HasReflectiveSurface(adjacent) == TRUE) {
                            selected = adjacent;
                        }
                    }
                    if (selected == GetMetatileBehavior_None()) {
                        return;
                    }
                    MapObject_SetFlag24(object, TRUE);
                    if (MetatileBehavior_IsReflective(selected) == TRUE) {
                        kind = 2;
                    } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                        kind = 0;
                    } else {
                        kind = 1;
                    }
                    ov01_021FDF88(object, kind);
                }
            } else {
                int kind;
                if (MapObject_CheckFlag24(object) != FALSE) {
                    return;
                }
                if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                    selected = behavior;
                } else {
                    u8 adjacent = sub_02060FA8(object, 1);
                    if (MetatileBehavior_HasReflectiveSurface(adjacent) == TRUE) {
                        selected = adjacent;
                    }
                }
                if (selected == GetMetatileBehavior_None()) {
                    return;
                }
                MapObject_SetFlag24(object, TRUE);
                if (MetatileBehavior_IsReflective(selected) == TRUE) {
                    kind = 2;
                } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                    kind = 0;
                } else {
                    kind = 1;
                }
                ov01_021FDA74(object, kind);
            }
        }
    }
}

void sub_020609D4(LocalMapObject *object, int unused1, int unused2, const MovementEffect *effect) {
    if (effect->kind == 0 || MapObject_CheckFlag24(object) == FALSE) {
        return;
    }
    if (MapObject_GetID(object) == 0xFD && ov01_022055DC(object) != 0) {
        u8 first = sub_02060FA8(object, 1);
        u8 second = sub_02060FA8(object, 3);
        u8 third = sub_02060FA8(object, 2);
        u8 fourth = ov01_022056C4(object, 4);
        u8 fifth = ov01_022056C4(object, 5);
        BOOL found = FALSE;

        if (MetatileBehavior_HasReflectiveSurface(first) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(second) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(third) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(fourth) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(fifth) == TRUE) {
            found = TRUE;
        }
        if (found == FALSE) {
            MapObject_SetFlag24(object, FALSE);
        }
    } else {
        u8 adjacent = sub_02060FA8(object, 1);
        if (MetatileBehavior_HasReflectiveSurface(adjacent) == FALSE) {
            MapObject_SetFlag24(object, FALSE);
        }
    }
}
