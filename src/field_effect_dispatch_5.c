#include "field_effect_dispatch_internal.h"

u32 ov01_02205CF0(void *p, void *env) {
    s32 px = MapObject_GetXCoord(PlayerAvatar_GetMapObject(*(void **)((u8 *)p + 0x40)));
    s32 pz = MapObject_GetZCoord(PlayerAvatar_GetMapObject(*(void **)((u8 *)p + 0x40)));
    s32 fx = MapObject_GetXCoord(FollowMon_GetMapObject(p));
    s32 fz = MapObject_GetZCoord(FollowMon_GetMapObject(p));
    if (fx == px && fz == pz + 1) {
        *(u32 *)((u8 *)env + 0x44) = 1;
        return 2;
    }
    if (fx == px + 1 && fz == pz) {
        *(u32 *)((u8 *)env + 0x44) = 0;
        return 3;
    }
    if (fx + 1 == px && fz == pz) {
        *(u32 *)((u8 *)env + 0x44) = 1;
        return 3;
    }
    GF_AssertFail();
    return 2;
}

BOOL ov01_02205D68(void *p) {
    u32 *env;
    if (!FollowMon_IsActive(p)) {
        return FALSE;
    }
    if (ov01_022057C4(p)) {
        sub_0206A054(p);
        ov01_02205790(p, 0);
        return FALSE;
    }
    env = Heap_AllocAtEnd(0xb, 0x44);
    *env = 0;
    TaskManager_Call(*(void **)((u8 *)p + 0x10), ov01_02205DB4, env);
    return TRUE;
}
