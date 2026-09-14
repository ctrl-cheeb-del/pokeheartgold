#include "map_object_movement_lookup_internal.h"

int sub_02061F5C(LocalMapObject *object, int tableId, int value) {
    const int *list;
    int count;
    int i;
    int xDirection;
    int zDirection;
    int objectX;
    int objectZ;
    PlayerAvatar *avatar;
    int playerX;
    int playerZ;
    int direction;

    list = sub_02061E6C(tableId);
    count = sub_02061E00(list, value);
    if (count == 1) {
        return -1;
    }
    direction = sub_02061E90(object);
    if (direction == -1) {
        goto done;
    }
    i = 0;
    do {
        if (list[i] == direction) {
            goto done;
        }
        i++;
    } while (i < count);
    xDirection = -1;
    zDirection = -1;
    objectX = MapObject_GetXCoord(object);
    objectZ = MapObject_GetZCoord(object);
    avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    playerX = PlayerAvatar_GetXCoord(avatar);
    playerZ = PlayerAvatar_GetZCoord(avatar);
    if (objectX > playerX) {
        xDirection = 2;
    } else if (objectX < playerX) {
        xDirection = 3;
    }
    if (objectZ > playerZ) {
        zDirection = 0;
    } else if (objectZ < playerZ) {
        zDirection = 1;
    }
    i = 0;
    if (xDirection == -1) {
        do {
            if (list[i] == zDirection) {
                return zDirection;
            }
            i++;
        } while (i < count);
    } else if (zDirection == -1) {
        do {
            if (list[i] == xDirection) {
                return xDirection;
            }
            i++;
        } while (i < count);
    } else {
        do {
            if (list[i] == xDirection) {
                return xDirection;
            }
            if (list[i] == zDirection) {
                return zDirection;
            }
            i++;
        } while (i < count);
    }
    direction = -1;
done:
    return direction;
}
