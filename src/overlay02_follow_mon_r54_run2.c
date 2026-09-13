#include "overlay02_follow_mon_r54_private.h"

int ov02_0224EF94(void *fieldSystem);
void ov02_0224F058(void *fieldSystem, void *cond);
int ov02_0224F108(void *fieldSystem, const FollowMonInteractionEntry *entry, void *cond);
void ov02_0224F324(void *mon, void *cond);
void ov02_0224F4BC(void *fieldSystem, void *cond);
void ov02_0224F580(void *fieldSystem, void *cond);
void ov02_0224F5D0(void *fieldSystem, void *cond);
void ov02_0224F5FC(void *fieldSystem, void *cond);

int ov02_0224EF94(void *fieldSystem);
void ov02_0224F058(void *fieldSystem, void *cond);
int ov02_0224F108(void *fieldSystem, const FollowMonInteractionEntry *entry, void *cond);

void ov02_0224F324(void *mon, void *cond) {
    MonDataIdList ids;
    int item;
    int hp;
    int pct;
    int status;
    int friendship;
    int a;
    int b;
    int i;

    item = GetMonData(mon, 6, NULL);
    if (item != 0) {
        U8(cond, 0) = 1;
        U8(cond, 1) = ov02_0224F820(GetItemAttr(item, 5, 0xb));
    } else {
        U8(cond, 0) = 0;
        U8(cond, 1) = 8;
    }
    hp = GetMonData(mon, 0xa3, NULL);
    pct = hp * 100 / GetMonData(mon, 0xa4, NULL);
    if (pct == 100) {
        U8(cond, 2) = 1;
    } else if (pct >= 75) {
        U8(cond, 2) = 2;
    } else if (pct >= 50) {
        U8(cond, 2) = 3;
    } else if (pct >= 25) {
        U8(cond, 2) = 4;
    } else {
        U8(cond, 2) = 5;
    }
    status = GetMonData(mon, 0xa0, NULL);
    if (status & 0x88) {
        U8(cond, 3) = 5;
    } else if (status & 7) {
        U8(cond, 3) = 8;
    } else if (status & 0x10) {
        U8(cond, 3) = 2;
    } else if (status & 0x20) {
        U8(cond, 3) = 3;
    } else if (status & 0x40) {
        U8(cond, 3) = 4;
    } else if (status == 0) {
        U8(cond, 3) = 1;
    } else {
        GF_AssertFail();
        U8(cond, 3) = 1;
    }
    friendship = GetMonData(mon, 0xa1, NULL);
    if (friendship + 2 >= 50) {
        U8(cond, 4) = 4;
    } else if (friendship - 2 <= 50) {
        U8(cond, 4) = 6;
    } else {
        U8(cond, 4) = 5;
    }
    a = GetMonData(mon, 0xb1, NULL);
    b = GetMonData(mon, 0xb2, NULL);
    U8(cond, 5) = ov02_0224F79C(a);
    U8(cond, 6) = ov02_0224F79C(b);
    U8(cond, 7) = GetMonData(mon, 9, NULL);
    U8(cond, 8) = ov02_02253AC0[GetMonNature(mon)];
    if (GetMonData(mon, 0x6f, NULL) == 0) {
        U8(cond, 9) = 1;
    } else {
        U8(cond, 9) = 2;
    }
    ids = ov02_02253A5C;
    U8(cond, 0xb) = 0;
    for (i = 0; i < 5; i++) {
        U8(cond, 0xb) |= (u8)GetMonData(mon, ids.ids[i], NULL) << i;
    }
}

void ov02_0224F4BC(void *fieldSystem, void *cond) {
    void *objects;
    int i;
    int count;
    int playerX;
    int playerZ;

    U8(cond, 0xc) = 0;
    U8(cond, 0xe) = 0;
    U8(cond, 0xf) = 0;
    U8(cond, 0x10) = 0;
    playerX = PlayerAvatar_GetXCoord(PTR(fieldSystem, 0x40));
    playerZ = PlayerAvatar_GetZCoord(PTR(fieldSystem, 0x40));
    count = MapObjectManager_GetObjectCount(PTR(fieldSystem, 0x3c));
    objects = MapObjectManager_GetObjects(PTR(fieldSystem, 0x3c));
    for (i = 0; i < count; i++) {
        if (MapObject_CheckActive(objects) == 1) {
            int x = MapObject_GetXCoord(objects);
            int z = MapObject_GetZCoord(objects);
            int dx = playerX - x;
            int dz = playerZ - z;
            int sprite = MapObject_GetSpriteID(objects);
            if (sprite == 0x54) {
                U8(cond, 0xf) = 1;
            } else if (sprite == 0x55) {
                U8(cond, 0xe) = 1;
            } else if (sprite == 0x56) {
                U8(cond, 0x10) = 1;
            } else if (dx >= -1 && dx <= 1 && dz >= -1 && dz <= 1) {
                int id = MapObject_GetID(objects);
                if (id != 0xfd && id != 0xff) {
                    U8(cond, 0xc)
                    ++;
                }
            }
        }
        MapObjectArray_NextObject2(&objects);
    }
}

void ov02_0224F580(void *fieldSystem, void *cond) {
    int count = 0;
    u8 *events = Field_GetBgEvents(fieldSystem);
    int numEvents = Field_GetNumBgEvents(fieldSystem);
    int i;

    if (numEvents != 0 && events != NULL) {
        for (i = 0; i < numEvents; i++) {
            if (U16(events, 2) == 2 && !FieldSystem_FlagCheck(fieldSystem, HiddenItemScriptNoToFlagId(U16(events, 0)))) {
                count++;
            }
            events += 0x14;
        }
    }
    U8(cond, 0xd) = count;
}

void ov02_0224F5D0(void *fieldSystem, void *cond) {
    switch (LocalFieldData_GetWeatherType(Save_LocalFieldData_Get(PTR(fieldSystem, 0xc)))) {
    case 0:
        U8(cond, 0x11) = 1;
        break;
    case 1:
        U8(cond, 0x11) = 3;
        break;
    default:
        U8(cond, 0x11) = 0;
        break;
    }
}

void ov02_0224F5FC(void *fieldSystem, void *cond) {
    int x = MapObject_GetXCoord(FollowMon_GetMapObject(fieldSystem));
    int z = MapObject_GetZCoord(FollowMon_GetMapObject(fieldSystem));
    int behavior = GetMetatileBehavior(fieldSystem, x, z);
    U8(cond, 0x12) = behavior;
    U16(PTR(fieldSystem, 0x120), 0x882) = behavior;
    if (MetatileBehavior_CanGenerateWalkingEncounters(behavior)) {
        U8(cond, 0x13) = 1;
    } else {
        U8(cond, 0x13) = 2;
    }
}
