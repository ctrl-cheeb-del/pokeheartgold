#include "field_player_object_sync_internal.h"

void sub_0205AF78(PlayerEffectManager *manager, MapObjectManager *objectManager) {
    int i;
    u32 x;
    u32 z;
    u8 *cursor;
    PlayerEffectSlot *slot;
    PlayerEffectCursor *view;
    LocalMapObject *object;

    if (manager->avatar == NULL) {
        GF_AssertFail();
    }
    x = PlayerAvatar_GetXCoord(manager->avatar);
    z = PlayerAvatar_GetZCoord(manager->avatar);
    cursor = (u8 *)manager;
    i = 0;
    slot = manager->slots;

    for (; i < 50; i++, cursor += 24, slot++) {
        view = (PlayerEffectCursor *)cursor;
        object = MapObjectManager_GetFirstActiveObjectByID(objectManager, i + 1);
        if (object == NULL) {
            GF_AssertFail();
        }
        switch (view->state) {
        case 0:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE && (u32)(view->status - 1) <= 1) {
                sub_0205B13C(slot, object, x, z);
            }
            break;
        case 1:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                if (view->status == 3) {
                    view->state = 0;
                    view->status = 0;
                    sub_0205B0DC(slot, TRUE);
                } else {
                    MapObject_ClearHeldMovementIfActive(object);
                    MapObject_SetFlag19(object, FALSE);
                    if (view->status == 1 && view->effectStarted == 0) {
                        sub_0205FC94(object, 3);
                        MapObject_SetXRange(object, 1);
                        MapObject_SetYRange(object, 1);
                        view->effectStarted = 1;
                    }
                    view->state = 2;
                    view->status = 0;
                }
            }
            break;
        case 2:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                sub_0205B218(slot, object);
                if (view->status == 3) {
                    sub_0205B1E4(slot, object);
                }
                sub_0205B118(slot);
            }
            break;
        case 3:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                MapObject_ClearHeldMovementIfActive(object);
                view->state = 4;
                view->status = 0;
                view->effectStarted = 0;
                MapObject_SetVisible(object, TRUE);
                MapObject_ClearFlag18(object, FALSE);
            }
            break;
        case 4:
            view->state = 0;
            break;
        }
    }

    object = PlayerAvatar_GetMapObject(manager->avatar);
    sub_0205B218(&manager->slots[50], object);
    sub_0205B118(&manager->slots[50]);
}
