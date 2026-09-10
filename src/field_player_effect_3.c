#include "field_player_effect_internal.h"

void sub_0205B0DC(Slot *slot, BOOL both) {
    if (slot->effect1 != NULL) {
        if (sub_02068CCC(slot->effect1)) {
            sub_02068B48((int)slot->effect1);
        }
        slot->effect1 = NULL;
    }
    if (both && slot->effect2 != NULL) {
        if (sub_02068CCC(slot->effect2)) {
            sub_02068B48((int)slot->effect2);
        }
        slot->effect2 = NULL;
    }
}

void sub_0205B118(Slot *slot) {
    if (slot->active != 0) {
        slot->timer--;
        if (slot->timer == 0) {
            sub_0205B0DC(slot, FALSE);
            slot->active = 0;
        }
    }
}

void sub_0205B13C(Slot *slot, LocalMapObject *object, u32 x, u32 z) {
    u32 initialX = MapObject_GetInitialX(object);
    u32 initialY = MapObject_GetInitialY(object);
    u32 initialZ = MapObject_GetInitialZ(object);

    if (initialX != x || initialZ != z) {
        PlaySE(0x64e);
        sub_0205E3AC(object, slot->sprite);
        sub_0205B0DC(slot, FALSE);
        MapObject_SetPositionFromXYZAndDirection(object, initialX, initialY, initialZ, TRUE);
        MapObject_SetFacingDirectionDirect(object, TRUE);
        MapObject_SetHeldMovement(object, 0x44);
        MapObject_SetVisible(object, FALSE);
        MapObject_ClearFlag18(object, TRUE);
        slot->state = 1;
        if (slot->effect != 0) {
            if (slot->effect == 1) {
                slot->effect2 = ov01_021FD8E8(object, 1);
            } else if (slot->effect >= 2) {
                slot->effect2 = ov01_021FD8E8(object, 2);
            }
            slot->effect = 0;
        }
    }
}

void sub_0205B1E4(Slot *slot, LocalMapObject *object) {
    MapObject_SetHeldMovement(object, 0x43);
    MapObject_SetFlag19(object, TRUE);
    sub_0205FC94(object, 0);
    sub_0205B0DC(slot, TRUE);
    slot->active = 0;
    slot->timer = 0;
    slot->state = 3;
}

void sub_0205B218(Slot *slot, LocalMapObject *object) {
    if (slot->trigger == 1 && slot->active == 0) {
        slot->effect1 = ov01_02200730(object);
        slot->timer = 30;
        slot->trigger = 0;
        slot->active = 1;
    }
}

void sub_0205B240(MapObjectManager *manager, int first, int last) {
    LocalMapObject *object;
    for (; first < last; first++) {
        object = MapObjectManager_GetFirstActiveObjectByID(manager, first);
        if (object == NULL) {
            GF_AssertFail();
        }
        MapObject_SetVisible(object, TRUE);
        MapObject_ClearFlag18(object, FALSE);
        MapObject_SetFlag19(object, TRUE);
    }
}

void sub_0205B27C(MapObjectManager *objectManager, Manager *manager) {
    LocalMapObject *object;
    int i;

    object = MapObjectManager_GetFirstActiveObjectByID(objectManager, 0);
    if (object == NULL) {
        GF_AssertFail();
    }
    if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
        if (sub_02037FCC() != FALSE || sub_02037F94() != FALSE) {
            for (i = 0; i < 10; i++) {
                Slot *slot = &manager->slots[i];
                if (slot->state == 1) {
                    object = MapObjectManager_GetFirstActiveObjectByID(objectManager, i + 1);
                    if (object == NULL) {
                        GF_AssertFail();
                    }
                    sub_0205E3AC(object, slot->sprite);
                    MapObject_SetFacingDirectionDirect(object, TRUE);
                    MapObject_SetHeldMovement(object, 0x44);
                    MapObject_SetVisible(object, FALSE);
                    MapObject_ClearFlag18(object, TRUE);
                    slot->state = 1;
                    if (slot->effect != 0) {
                        if (slot->effect == 1) {
                            slot->effect2 = ov01_021FD8E8(object, 1);
                        } else if (slot->effect >= 2) {
                            slot->effect2 = ov01_021FD8E8(object, 2);
                        }
                        slot->effect = 0;
                    }
                }
            }
            sub_0205B240(objectManager, 11, 51);
        } else {
            sub_0205B240(objectManager, 1, 51);
        }
    }
}

void sub_0205B338(MessageSlot *slot) {
    slot->string0 = String_New(8, (enum HeapID)0x57);
    slot->string1 = NULL;
    slot->string2 = NULL;
    MailMsg_Init_WithBank(&slot->message, 0);
    slot->unk10 = 0;
    slot->unkC = 0;
}

void sub_0205B35C(MessageSlot *slots) {
    int i;
    for (i = 0; i < 30; i++) {
        sub_0205B338(&slots[i]);
    }
    *(u32 *)&slots[30] = 0;
    *((u32 *)&slots[30] + 1) = 0;
}

void sub_0205B380(MessageSlot *slot) {
    Heap_Free(slot->string0);
    if (slot->string1 != NULL) {
        String_Delete(slot->string1);
    }
    if (slot->string2 != NULL) {
        String_Delete(slot->string2);
    }
}

void sub_0205B3A0(MessageSlot *slots) {
    int i;
    for (i = 0; i < 30; i++) {
        sub_0205B380(&slots[i]);
    }
}

MessageSlot *sub_0205B3B8(int heapId) {
    MessageSlot *slots = Heap_Alloc((enum HeapID)heapId, 0x350);
    sub_0205B35C(slots);
    return slots;
}

void sub_0205B3CC(MessageSlot *slots) {
    sub_0205B3A0(slots);
    Heap_Free(slots);
}
