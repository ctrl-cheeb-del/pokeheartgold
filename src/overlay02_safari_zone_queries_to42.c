#include "overlay02_safari_zone_to42_private.h"

BOOL ov02_0224E640(void *saveData) {
    u32 trainerId = PlayerProfile_GetTrainerID(Save_PlayerData_GetProfile(saveData));
    int unlockLevel = SafariZone_GetObjectUnlockLevel(Save_SafariZone_Get(saveData));
    u8 digit = trainerId % 10;
    u8 value;

    if (digit < 6) {
        value = digit / 3;
    } else {
        value = (digit - 6) / 2 + 2;
    }
    value = 3 - value;
    return unlockLevel >= value + 1;
}

u16 ov02_0224E698(FieldSystem *fieldSystem) {
    u8 direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    s16 x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    s16 z = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    VecFx32 position;
    s16 outA;
    s16 outB;
    SafariZoneAreaSet *areaSet;
    u8 areaIndex;

    PlayerAvatar_CopyPositionVector(fieldSystem->playerAvatar, &position);
    areaSet = SafariZone_GetAreaSet(Save_SafariZone_Get(fieldSystem->saveData), 0);
    areaIndex = (x - 32) / 32 + (z - 32) / 32 * 3;
    if (areaSet->areas[areaIndex].active_object_count >= 30) {
        return 1;
    }
    if (PlayerAvatar_GetState(fieldSystem->playerAvatar) != 2) {
        return 0;
    }
    if (!ov02_0224E640(fieldSystem->saveData)) {
        return 2;
    }
    if (ov02_0224EE4C(fieldSystem, x, z, direction, position.y, &outA, &outB, TRUE)) {
        return 0;
    }
    return 3;
}

u16 ov02_0224E754(FieldSystem *fieldSystem, u16 *objectIndex) {
    int direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    int x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar) + GetDeltaXByFacingDirection(direction);
    int z = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar) + GetDeltaYByFacingDirection(direction);
    u8 gender = PlayerProfile_GetTrainerGender(Save_PlayerData_GetProfile(fieldSystem->saveData));
    int areaIndex = ov02_0224E31C(x, z);
    SAFARIZONE_AREA *area;
    int i;

    x %= 32;
    z %= 32;
    area = &SafariZone_GetAreaSet(Save_SafariZone_Get(fieldSystem->saveData), 0)->areas[areaIndex];
    for (i = 0; i < area->active_object_count; i++) {
        SafariObjectConfig config;
        SAFARIZONE_OBJECT *object = &area->objects[i];

        GetSafariObjectConfig(&config, object->id, gender);
        if (x >= object->x && z <= object->z && x < object->x + config.width && z > object->z - config.height) {
            if (objectIndex != NULL) {
                *objectIndex = i;
            }
            return object->id;
        }
    }
    *objectIndex = 0;
    return 0xFF;
}
