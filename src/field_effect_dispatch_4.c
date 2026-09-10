#include "field_effect_dispatch_internal.h"

void ov01_0220596C(void *task, void *env) {
    if (GF_GetNumPendingVramTransferTasks() == 0) {
        SysTask_Destroy(task);
        Heap_Free(*(void **)env);
        Heap_Free(env);
    }
}

void ov01_02205990(u32 a, u32 b, u32 c, void *p) {
    u8 *q = p;
    *(u32 *)(q + 4) = a;
    *(u32 *)(q + 8) = b;
    *(u32 *)(q + 0xc) = c;
    if (*(u32 *)(q + 0x1c) == 3) {
        *(u32 *)(q + 0x1c) = 2;
    } else if (*(u32 *)(q + 0x1c) == 0) {
        *(u32 *)(q + 0x1c) = 1;
    }
}

void ov01_022059AC(void *p) {
    u8 *q = p;
    if (q[0xf9]) {
        if (q[0xfa] == 0) {
            s32 x = PlayerAvatar_GetXCoord(*(void **)(q + 0x40));
            s32 z = PlayerAvatar_GetZCoord(*(void **)(q + 0x40));
            u32 direction = PlayerAvatar_GetFacingDirection(*(void **)(q + 0x40));
            FollowMon_InitMapObject(*(void **)(q + 0x3c), x, z, direction, **(void ***)(q + 0x20));
            {
                u8 active = q[0xfa];
                void *follow = *(void **)(q + 0xe4);
                if (active == 1) {
                    ov01_021F9048(follow);
                }
            }
        } else {
            u16 species = FollowMon_GetSpecies(*(void **)(q + 0xe4));
            if (!FollowMon_GetPermissionBySpeciesAndMap(species, **(void ***)(q + 0x20))) {
                MapObject_Remove(*(void **)(q + 0xe4));
                q[0xfa] = 0;
            }
        }
    }
    q[0xf9] = 0;
}

void ov01_02205A34(void *p, int y) {
    int v[3];
    void *obj;
    if (FollowMon_IsActive(p)) {
        obj = FollowMon_GetMapObject(p);
        MapObject_CopyPositionVector(obj, v);
        v[1] = y;
        MapObject_SetPositionVector(obj, v);
    }
}

BOOL ov01_02205A60(void *taskman) {
    void *fs = TaskManager_GetFieldSystem(taskman);
    u32 *state = TaskManager_GetStatePtr(taskman);
    void *obj;
    if (!FollowMon_IsActive(fs)) {
        return TRUE;
    }
    obj = *(void **)((u8 *)fs + 0xe4);
    switch (*state) {
    case 0:
        if (MapObject_CheckMovementPaused(obj)) {
            MapObject_UnpauseMovement(obj);
            *state = 1;
        } else {
            *state = 2;
        }
        break;
    case 1:
        if (MapObject_IsMovementPaused(obj) && MapObject_AreBitsSetForMovementScriptInit(obj)) {
            MapObject_PauseMovement(obj);
            return TRUE;
        }
        break;
    case 2:
        if (MapObject_IsMovementPaused(obj) && MapObject_AreBitsSetForMovementScriptInit(obj)) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ov01_02205AEC(void *p) {
    u8 *env = Heap_AllocAtEnd(0xb, 0x48);
    env[0] = 0;
    env[1] = 0;
    env[2] = 0;
    env[3] = 0;
    TaskManager_Call(*(void **)((u8 *)p + 0x10), ov01_02205B14, env);
}
