#include "field_effect_dispatch_internal.h"

BOOL ov01_0220553C(void *obj) {
    u32 id = MapObject_GetID(obj);
    if (id != 0xfd && id != 0xfa && id != 0xfb) {
        return FALSE;
    }
    return MapObject_GetParam(obj, 2) & 1;
}

BOOL ov01_02205564(void *obj) {
    int id = MapObject_GetSpriteID(obj);
    return id >= 0x19f && id <= 0x1a4;
}

u8 ov01_02205584(void *obj) {
    u16 p = MapObject_GetParam(obj, 1);
    if (MapObject_GetID(obj) != 0xfd) {
        return 0;
    }
    return ((u8)p >> 4) & 0xf;
}

u8 ov01_022055B0(void *obj) {
    u16 p = MapObject_GetParam(obj, 1);
    if (MapObject_GetID(obj) != 0xfd) {
        return 0;
    }
    return (u8)p & 0xf;
}

u8 ov01_022055DC(void *obj) {
    u16 p = MapObject_GetParam(obj, 1);
    if (MapObject_GetID(obj) != 0xfd) {
        return 0;
    }
    return (p >> 8) & 0xf;
}

void ov01_02205604(void *obj, int *x, int *z) {
    u8 dir = MapObject_GetFacingDirection(obj);
    *x = MapObject_GetXCoord(obj);
    *z = MapObject_GetZCoord(obj);
    switch (dir) {
    case 0:
        (*z)++;
        break;
    case 1:
        (*z)--;
        break;
    case 2:
        (*x)++;
        break;
    case 3:
        (*x)--;
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov01_02205664(void *obj, int *x, int *z) {
    u8 dir = MapObject_GetFacingDirection(obj);
    *x = MapObject_GetPreviousXCoord(obj);
    *z = MapObject_GetPreviousZCoord(obj);
    switch (dir) {
    case 0:
        (*z)++;
        break;
    case 1:
        (*z)--;
        break;
    case 2:
        (*x)++;
        break;
    case 3:
        (*x)--;
        break;
    default:
        GF_AssertFail();
        break;
    }
}

u32 ov01_022056C4(void *obj, u32 dir) {
    void *fs = MapObject_GetFieldSystem(obj);
    int x = MapObject_GetXCoord(obj);
    int z = MapObject_GetZCoord(obj);
    switch (dir) {
    case 0:
        z--;
        break;
    case 1:
        z++;
        break;
    case 3:
        x--;
        break;
    case 2:
        x++;
        break;
    case 4:
        x++;
        z++;
        break;
    case 5:
        x--;
        z++;
        break;
    }
    return GetMetatileBehavior(fs, x, z);
}

void ov01_02205720(void *src, void *dst, u32 dir, u32 facing) {
    int v[3];
    MapObject_CopyPositionVector(src, v);
    switch (dir) {
    case 0:
        v[2] -= 0x10000;
        break;
    case 1:
        v[2] += 0x10000;
        break;
    case 3:
        v[0] += 0x10000;
        break;
    case 2:
        v[0] -= 0x10000;
        break;
    }
    MapObject_SetPositionFromVectorAndDirection(dst, v, facing);
}

void *ov01_02205784(void *p) {
    return ov01_0220329C(p, 0);
}

void ov01_02205790(void *p, u32 dir) {
    int v[3];
    void *follow;
    if (FollowMon_IsActive(p)) {
        follow = FollowMon_GetMapObject(p);
        MapObject_CopyPositionVector(PlayerAvatar_GetMapObject(*(void **)((u8 *)p + 0x40)), v);
        MapObject_SetPositionFromVectorAndDirection(follow, v, dir);
    }
}

BOOL ov01_022057C4(void *p) {
    return MapObject_CheckVisible(FollowMon_GetMapObject(p));
}

u32 ov01_022057D0(void *p) {
    return sub_020659B8(FollowMon_GetMapObject(p));
}
