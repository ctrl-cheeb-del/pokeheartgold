#include "union_room_objects.h"

#include "global.h"

#include "constants/save_arrays.h"

#include "assert.h"
#include "field_effects.h"
#include "field_shadow.h"
#include "field_system.h"
#include "field_union_chat_marker.h"
#include "field_warp_reset.h"
#include "heap.h"
#include "mail_message.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pm_string.h"
#include "save.h"
#include "save_palpad.h"
#include "sound_playback.h"
#include "sys_task_api.h"
#include "task.h"
#include "union_room_internal.h"
#include "union_room_talk.h"

s32 CommState_GetJoinResult(void);
s32 CommState_IsAlternateLinked(void);

static void UnionRoomObjects_Task(SysTask *task, void *data);
static BOOL UnionRoomObjects_UpdateGroup(UnionRoomObjects *objects, int index, UnionRoomRecord *record, SavePalPad *palPad);
static void UnionRoomSlots_SetRequest(UnionRoomSlot *slots, int index, u8 request);
static void UnionRoomObjects_UpdatePlayers(UnionRoomObjects *objects, struct UnionRoom *unionRoom, MapObjectManager *mapObjectManager, SavePalPad *palPad);
static void UnionRoomObjects_UpdateMapObjects(UnionRoomObjects *objects, MapObjectManager *mapObjectManager);
static void UnionRoomSlot_DestroyEffects(UnionRoomSlot *slot, BOOL both);
static void UnionRoomSlot_TickEmote(UnionRoomSlot *slot);
static void UnionRoomSlot_Appear(UnionRoomSlot *slot, LocalMapObject *object, u32 x, u32 z);
static void UnionRoomSlot_Leave(UnionRoomSlot *slot, LocalMapObject *object);
static void UnionRoomSlot_StartEmote(UnionRoomSlot *slot, LocalMapObject *object);
static void UnionRoomObjects_ShowRange(MapObjectManager *mapObjectManager, int first, int last);
static void UnionRoomMessage_Init(UnionRoomMessage *message);
static void UnionRoomMessages_Init(UnionChatLogMessages *messages);
static void UnionRoomMessage_Free(UnionRoomMessage *message);
static void UnionRoomMessages_FreeAll(UnionChatLogMessages *messages);
static UnionChatLogMessages *UnionRoomMessages_New(enum HeapID heapID);
static void UnionRoomMessages_Free(UnionChatLogMessages *messages);

UnionRoomObjects *UnionRoomObjects_New(struct UnionRoom *unionRoom) {
    UnionRoomObjects *objects = Heap_Alloc(HEAP_ID_31, sizeof(UnionRoomObjects));
    MIi_CpuClearFast(0, (u32 *)objects, sizeof(UnionRoomObjects));
    objects->unionRoom = unionRoom;
    objects->enabled = 1;
    objects->task = SysTask_CreateOnMainQueue(UnionRoomObjects_Task, objects, 11);
    objects->fieldSystem = UnionRoom_GetFieldSystem(unionRoom);
    objects->palPad = SaveArray_Get(objects->fieldSystem->saveData, SAVE_PALPAD);
    objects->avatar = objects->fieldSystem->playerAvatar;
    Heap_CreateAtEnd(HEAP_ID_FIELD2, HEAP_ID_87, 0x2710);
    objects->messages = UnionRoomMessages_New(HEAP_ID_87);
    UnionRoomObjects_ResetSlots(objects);
    return objects;
}

void UnionRoomObjects_RequestLeaveAll(UnionRoomObjects *objects) {
    int i;
    for (i = 0; i < 51; i++) {
        if (objects->slots[i].state != UNION_ROOM_SLOT_HIDDEN) {
            objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_LEAVE;
        }
    }
}

void UnionRoomObjects_ResetSlots(UnionRoomObjects *objects) {
    int i;
    for (i = 0; i < 51; i++) {
        objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_NONE;
        objects->slots[i].state = UNION_ROOM_SLOT_HIDDEN;
        objects->slots[i].friendship = 0;
        objects->slots[i].emoteRequest = 0;
    }
}

void UnionRoomObjects_Delete(UnionRoomObjects *objects) {
    SysTask_Destroy(objects->task);
    UnionRoomMessages_Free(objects->messages);
    Heap_Destroy(HEAP_ID_87);
    Heap_Free(objects);
}

static void UnionRoomObjects_Task(SysTask *task, void *data) {
    UnionRoomObjects *objects = data;
    struct UnionRoom *unionRoom = objects->unionRoom;

    if (!FieldSystem_TaskIsRunning(objects->fieldSystem)) {
        objects->avatar = objects->fieldSystem->playerAvatar;
        UnionRoomObjects_UpdatePlayers(objects, unionRoom, objects->fieldSystem->mapObjectManager, objects->palPad);
        UnionRoomObjects_UpdateMapObjects(objects, objects->fieldSystem->mapObjectManager);
    }
}

#pragma opt_strength_reduction off

static BOOL UnionRoomObjects_UpdateGroup(UnionRoomObjects *objects, int index, UnionRoomRecord *record, SavePalPad *palPad) {
    BOOL ret = FALSE;
    int i;
    int k;
    UnionRoomRecordInfo *info;
    UnionRoomStatus *status;
    u32 *memberIds;

    if (record == NULL) {
        k = gUnionRoomGroupFirstSlot[index];
        for (i = 0; i < 4; i++) {
            UnionRoomSlots_SetRequest(objects->slots, k, 3);
            k++;
        }
        return FALSE;
    }
    info = &record->info;
    status = &info->status;
    if (info->id != objects->slots[index].id) {
        k = gUnionRoomGroupFirstSlot[index];
        for (i = 0; i < 4; i++) {
            UnionRoomSlots_SetRequest(objects->slots, k, 3);
            k++;
        }
        return FALSE;
    }
    k = gUnionRoomGroupFirstSlot[index];
    memberIds = status->memberIds;
    for (i = 0; i < 4; i++) {
        switch (objects->slots[k].state) {
        case UNION_ROOM_SLOT_HIDDEN:
            if (status->memberAvatars[i] != 0) {
                objects->slots[k].request = UNION_ROOM_SLOT_REQUEST_APPEAR_IN_GROUP;
                objects->slots[k].sprite = status->memberAvatars[i] & 0x7F;
                objects->slots[k].friendship = PalPad_PlayerIdIsFriendOrMutual(palPad, *memberIds);
                ret = TRUE;
            }
            break;
        case UNION_ROOM_SLOT_SHOWN:
            if (status->memberAvatars[i] == 0) {
                UnionRoomSlots_SetRequest(objects->slots, k, 3);
            } else {
                ret = TRUE;
            }
            break;
        case UNION_ROOM_SLOT_LEFT:
            objects->slots[k].request = UNION_ROOM_SLOT_REQUEST_NONE;
            break;
        }
        k++;
        memberIds++;
    }
    return ret;
}

#pragma opt_strength_reduction reset

static void UnionRoomSlots_SetRequest(UnionRoomSlot *slots, int index, u8 request) {
    slots[index].request = request;
}

static void UnionRoomObjects_UpdatePlayers(UnionRoomObjects *objects, struct UnionRoom *unionRoom, MapObjectManager *mapObjectManager, SavePalPad *palPad) {
    int i;

    for (i = 0; i < 10; i++) {
        UnionRoomRecord *record = UnionRoom_GetRecord(unionRoom, i);
        UnionRoomRecordInfo *info;
        PlayerProfile *profile;
        if (record != NULL) {
            info = &record->info;
            profile = &info->profile;
        } else {
            info = NULL;
            profile = NULL;
        }

        switch (objects->slots[i].state) {
        case UNION_ROOM_SLOT_HIDDEN:
            if (record != NULL) {
                objects->slots[i].sprite = PlayerProfile_GetAvatar(profile);
                objects->slots[i].friendship = PalPad_PlayerIdIsFriendOrMutual(palPad, PlayerProfile_GetTrainerID(profile));
                objects->slots[i].id = info->id;
                if (UnionRoomObjects_UpdateGroup(objects, i, record, palPad)) {
                    objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_APPEAR_IN_GROUP;
                } else {
                    objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_APPEAR_ALONE;
                }
            }
            break;
        case UNION_ROOM_SLOT_SHOWN:
            if (record == NULL) {
                UnionRoomSlots_SetRequest(objects->slots, i, 3);
            } else if (info->id != objects->slots[i].id) {
                UnionRoomSlots_SetRequest(objects->slots, i, 3);
            }
            if (UnionRoomObjects_UpdateGroup(objects, i, record, palPad) && objects->slots[i].isWandering == 1) {
                objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_LEAVE;
            }
            break;
        case UNION_ROOM_SLOT_LEFT:
            objects->slots[i].request = UNION_ROOM_SLOT_REQUEST_NONE;
            break;
        }
    }
}

static void UnionRoomObjects_UpdateMapObjects(UnionRoomObjects *objects, MapObjectManager *mapObjectManager) {
    int i;
    u32 x;
    u32 z;
    UnionRoomSlot *slot;
    UnionRoomObjects *cursor;
    LocalMapObject *object;

    GF_ASSERT(objects->avatar != NULL);
    x = PlayerAvatar_GetXCoord(objects->avatar);
    z = PlayerAvatar_GetZCoord(objects->avatar);
    i = 0;
    cursor = objects;
    slot = objects->slots;

    for (; i < 50; i++, cursor = (UnionRoomObjects *)((u8 *)cursor + sizeof(UnionRoomSlot)), slot++) {
        object = MapObjectManager_GetFirstActiveObjectByID(mapObjectManager, i + 1);
        GF_ASSERT(object != NULL);
        switch (cursor->slots[0].state) {
        case UNION_ROOM_SLOT_HIDDEN:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE && (u32)(cursor->slots[0].request - 1) <= 1) {
                UnionRoomSlot_Appear(slot, object, x, z);
            }
            break;
        case UNION_ROOM_SLOT_APPEARING:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                if (cursor->slots[0].request == UNION_ROOM_SLOT_REQUEST_LEAVE) {
                    cursor->slots[0].state = UNION_ROOM_SLOT_HIDDEN;
                    cursor->slots[0].request = UNION_ROOM_SLOT_REQUEST_NONE;
                    UnionRoomSlot_DestroyEffects(slot, TRUE);
                } else {
                    MapObject_ClearHeldMovementIfActive(object);
                    MapObject_SetFlag19(object, FALSE);
                    if (cursor->slots[0].request == UNION_ROOM_SLOT_REQUEST_APPEAR_ALONE && cursor->slots[0].isWandering == 0) {
                        MapObject_ChangeMovement(object, 3);
                        MapObject_SetXRange(object, 1);
                        MapObject_SetYRange(object, 1);
                        cursor->slots[0].isWandering = 1;
                    }
                    cursor->slots[0].state = UNION_ROOM_SLOT_SHOWN;
                    cursor->slots[0].request = UNION_ROOM_SLOT_REQUEST_NONE;
                }
            }
            break;
        case UNION_ROOM_SLOT_SHOWN:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                UnionRoomSlot_StartEmote(slot, object);
                if (cursor->slots[0].request == UNION_ROOM_SLOT_REQUEST_LEAVE) {
                    UnionRoomSlot_Leave(slot, object);
                }
                UnionRoomSlot_TickEmote(slot);
            }
            break;
        case UNION_ROOM_SLOT_LEAVING:
            if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
                MapObject_ClearHeldMovementIfActive(object);
                cursor->slots[0].state = UNION_ROOM_SLOT_LEFT;
                cursor->slots[0].request = UNION_ROOM_SLOT_REQUEST_NONE;
                cursor->slots[0].isWandering = 0;
                MapObject_SetInvisible(object, TRUE);
                MapObject_ClearFlag18(object, FALSE);
            }
            break;
        case UNION_ROOM_SLOT_LEFT:
            cursor->slots[0].state = UNION_ROOM_SLOT_HIDDEN;
            break;
        }
    }

    object = PlayerAvatar_GetMapObject(objects->avatar);
    UnionRoomSlot_StartEmote(&objects->slots[50], object);
    UnionRoomSlot_TickEmote(&objects->slots[50]);
}

static void UnionRoomSlot_DestroyEffects(UnionRoomSlot *slot, BOOL both) {
    if (slot->emote != NULL) {
        if (FieldEffect_IsActive(slot->emote)) {
            FieldEffect_Destroy(slot->emote);
        }
        slot->emote = NULL;
    }
    if (both && slot->friendEffect != NULL) {
        if (FieldEffect_IsActive(slot->friendEffect)) {
            FieldEffect_Destroy(slot->friendEffect);
        }
        slot->friendEffect = NULL;
    }
}

static void UnionRoomSlot_TickEmote(UnionRoomSlot *slot) {
    if (slot->emoteActive != 0) {
        slot->emoteTimer--;
        if (slot->emoteTimer == 0) {
            UnionRoomSlot_DestroyEffects(slot, FALSE);
            slot->emoteActive = 0;
        }
    }
}

static void UnionRoomSlot_Appear(UnionRoomSlot *slot, LocalMapObject *object, u32 x, u32 z) {
    u32 initialX = MapObject_GetInitialX(object);
    u32 initialY = MapObject_GetInitialY(object);
    u32 initialZ = MapObject_GetInitialZ(object);

    if (initialX != x || initialZ != z) {
        PlaySE(SEQ_SE_DP_TELE2);
        MapObject_ChangeSprite(object, slot->sprite);
        UnionRoomSlot_DestroyEffects(slot, FALSE);
        MapObject_SetPositionFromXYZAndDirection(object, initialX, initialY, initialZ, TRUE);
        MapObject_SetFacingDirectionDirect(object, TRUE);
        MapObject_SetHeldMovement(object, 0x44);
        MapObject_SetInvisible(object, FALSE);
        MapObject_ClearFlag18(object, TRUE);
        slot->state = UNION_ROOM_SLOT_APPEARING;
        if (slot->friendship != 0) {
            if (slot->friendship == 1) {
                slot->friendEffect = FieldShadow_CreateFriendShadow(object, 1);
            } else if (slot->friendship >= 2) {
                slot->friendEffect = FieldShadow_CreateFriendShadow(object, 2);
            }
            slot->friendship = 0;
        }
    }
}

static void UnionRoomSlot_Leave(UnionRoomSlot *slot, LocalMapObject *object) {
    MapObject_SetHeldMovement(object, 0x43);
    MapObject_SetFlag19(object, TRUE);
    MapObject_ChangeMovement(object, 0);
    UnionRoomSlot_DestroyEffects(slot, TRUE);
    slot->emoteActive = 0;
    slot->emoteTimer = 0;
    slot->state = UNION_ROOM_SLOT_LEAVING;
}

static void UnionRoomSlot_StartEmote(UnionRoomSlot *slot, LocalMapObject *object) {
    if (slot->emoteRequest == 1 && slot->emoteActive == 0) {
        slot->emote = UnionChatMarker_Spawn(object);
        slot->emoteTimer = 30;
        slot->emoteRequest = 0;
        slot->emoteActive = 1;
    }
}

static void UnionRoomObjects_ShowRange(MapObjectManager *mapObjectManager, int first, int last) {
    LocalMapObject *object;
    for (; first < last; first++) {
        object = MapObjectManager_GetFirstActiveObjectByID(mapObjectManager, first);
        GF_ASSERT(object != NULL);
        MapObject_SetInvisible(object, TRUE);
        MapObject_ClearFlag18(object, FALSE);
        MapObject_SetFlag19(object, TRUE);
    }
}

void UnionRoomObjects_RestoreAfterScript(MapObjectManager *mapObjectManager, UnionRoomObjects *objects) {
    LocalMapObject *object;
    int i;

    object = MapObjectManager_GetFirstActiveObjectByID(mapObjectManager, 0);
    GF_ASSERT(object != NULL);
    if (MapObject_AreBitsSetForMovementScriptInit(object) == TRUE) {
        if (CommState_IsAlternateLinked() || CommState_GetJoinResult()) {
            for (i = 0; i < 10; i++) {
                UnionRoomSlot *slot = &objects->slots[i];
                if (slot->state == UNION_ROOM_SLOT_APPEARING) {
                    object = MapObjectManager_GetFirstActiveObjectByID(mapObjectManager, i + 1);
                    GF_ASSERT(object != NULL);
                    MapObject_ChangeSprite(object, slot->sprite);
                    MapObject_SetFacingDirectionDirect(object, TRUE);
                    MapObject_SetHeldMovement(object, 0x44);
                    MapObject_SetInvisible(object, FALSE);
                    MapObject_ClearFlag18(object, TRUE);
                    slot->state = UNION_ROOM_SLOT_APPEARING;
                    if (slot->friendship != 0) {
                        if (slot->friendship == 1) {
                            slot->friendEffect = FieldShadow_CreateFriendShadow(object, 1);
                        } else if (slot->friendship >= 2) {
                            slot->friendEffect = FieldShadow_CreateFriendShadow(object, 2);
                        }
                        slot->friendship = 0;
                    }
                }
            }
            UnionRoomObjects_ShowRange(mapObjectManager, 11, 51);
        } else {
            UnionRoomObjects_ShowRange(mapObjectManager, 1, 51);
        }
    }
}

static void UnionRoomMessage_Init(UnionRoomMessage *message) {
    message->name = String_New(8, HEAP_ID_87);
    message->string1 = NULL;
    message->string2 = NULL;
    MailMsg_Init_WithBank(&message->mail, 0);
    message->gender = 0;
    message->trainerId = 0;
}

static void UnionRoomMessages_Init(UnionChatLogMessages *messages) {
    int i;
    for (i = 0; i < UNION_CHAT_LOG_NUM_MESSAGES; i++) {
        UnionRoomMessage_Init(&messages->slots[i]);
    }
    messages->count = 0;
    messages->head = 0;
}

static void UnionRoomMessage_Free(UnionRoomMessage *message) {
    Heap_Free(message->name);
    if (message->string1 != NULL) {
        String_Delete(message->string1);
    }
    if (message->string2 != NULL) {
        String_Delete(message->string2);
    }
}

static void UnionRoomMessages_FreeAll(UnionChatLogMessages *messages) {
    int i;
    for (i = 0; i < UNION_CHAT_LOG_NUM_MESSAGES; i++) {
        UnionRoomMessage_Free(&messages->slots[i]);
    }
}

static UnionChatLogMessages *UnionRoomMessages_New(enum HeapID heapID) {
    UnionChatLogMessages *messages = Heap_Alloc((enum HeapID)heapID, sizeof(UnionChatLogMessages));
    UnionRoomMessages_Init(messages);
    return messages;
}

static void UnionRoomMessages_Free(UnionChatLogMessages *messages) {
    UnionRoomMessages_FreeAll(messages);
    Heap_Free(messages);
}
