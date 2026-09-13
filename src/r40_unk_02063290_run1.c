#include "r40_unk_02063290_private.h"

BOOL MapObjectMovementCmd102_Step1(LocalMapObject *object) {
    u32 *counter = (u32 *)sub_0205F3E4(object);
    (*counter)++;
    if (*counter < 0x15) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}
