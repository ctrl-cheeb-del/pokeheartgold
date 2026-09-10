#include "field_effect_dispatch_internal.h"

void ov01_02206028(void *target, void *obj) {
    int tx = MapObject_GetXCoord(target);
    int tz = MapObject_GetZCoord(target);
    int ox = MapObject_GetXCoord(obj);
    int oz = MapObject_GetZCoord(obj);
    int dx = tx - ox;
    int dz = tz - oz;
    MapObject_GetFacingDirection(target);
    if (dx < 0) {
        MapObject_SetHeldMovement(obj, 10);
    } else if (dx > 0) {
        MapObject_SetHeldMovement(obj, 11);
    } else if (dz < 0) {
        MapObject_SetHeldMovement(obj, 8);
    } else if (dz > 0) {
        MapObject_SetHeldMovement(obj, 9);
    }
}

int ov01_02206088(u32 sprite) {
    int model = GetMoveModelNoBySpriteId(sprite);
    if (model < 0) {
        GF_AssertFail();
        model = 0;
    }
    return model;
}

void ov01_0220609C(void *p, u32 facing) {
    if (FollowMon_IsActive(p)) {
        MapObject_SetFacingDirection(*(void **)((u8 *)p + 0xe4), facing);
    }
}

BOOL ov01_022060B8(void *p, u32 a, u32 b) {
    u8 *env;
    if (!FollowMon_IsActive(p)) {
        return FALSE;
    }
    if (ov01_022057C4(p)) {
        return FALSE;
    }
    if (a == 0) {
        return FALSE;
    }
    env = Heap_AllocAtEnd(0xb, 0x84);
    MI_CpuFill8(env, 0, 0x84);
    env[1] = a;
    env[3] = b;
    TaskManager_Call(*(void **)((u8 *)p + 0x10), ov01_0220610C, env);
    return TRUE;
}
