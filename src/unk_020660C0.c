#include "unk_020660C0_internal.h"

LocalMapObject *sub_020660C0(LocalMapObject *object) {
    u32 index = 0;
    LocalMapObject *other;
    u32 type = MapObject_GetType(object);
    u32 mapId = MapObject_GetMapID(object);
    u32 trainer = sub_02064518(object);
    MapObjectManager *manager = MapObject_GetManager(object);

    switch (type) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &other, &index, (MapObjectFlagBits)1) == TRUE) {
            do {
                if (object != other && mapId == MapObject_GetMapID(other) && trainer == sub_02064518(other)) {
                    return other;
                }
            } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &other, &index, (MapObjectFlagBits)1) == TRUE);
        }
        break;
    }
    return NULL;
}

int sub_02066150(LocalMapObject *object, FollowState660C0 *state) {
    u32 mapId;
    u32 trainer;
    MapObjectManager *manager;
    u32 index;
    LocalMapObject *other;

    manager = MapObject_GetManager(object);
    index = 0;
    mapId = MapObject_GetMapID(object);
    trainer = sub_02064518(object);

    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &other, &index, (MapObjectFlagBits)1) == TRUE) {
        do {
            if (object != other && mapId == MapObject_GetMapID(other) && trainer == sub_02064518(other)) {
                if (state->found == FALSE) {
                    sub_020661CC(object, state, other);
                }
                return TRUE;
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &other, &index, (MapObjectFlagBits)1) == TRUE);
    }
    state->found = FALSE;
    return FALSE;
}
