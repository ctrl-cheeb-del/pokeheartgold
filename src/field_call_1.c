#include "field_call_internal.h"

void sub_0205D340(PlayerAvatar *avatar, int arg1, int arg2, int arg3, u16 arg4) {
    int state = PlayerAvatar_GetState(avatar);
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);

    switch (state) {
    case 0:
    case 2:
    case 3:
        ((void (*)(PlayerAvatar *, MapObject *, int, int, int, u16))sub_0205D3A8)(avatar, mapObject, arg1, arg2, arg3, arg4);
        break;
    case 1:
        sub_0205D640(avatar, mapObject, arg1, arg2, arg3, arg4);
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void sub_0205D3A8(PlayerAvatar *avatar, MapObject *mapObject, int unused, int direction, u16 arg4, u16 arg5) {
    switch (sub_0205D40C(avatar, direction)) {
    case 0:
        sub_0205D494(avatar, mapObject, direction, arg4, arg5);
        break;
    case 1:
        sub_0205D4B4(avatar, mapObject, direction, arg4, arg5);
        break;
    case 2:
        sub_0205D610(avatar, mapObject, direction, arg4, arg5);
        break;
    }
}
