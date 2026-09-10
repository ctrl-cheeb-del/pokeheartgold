#include "field_terrain_dispatch_extended_internal.h"

int sub_02054954(FieldSystem *fieldSystem, VecFx32 *playerPos, int x, int z, u8 *outKind) {
    int dir;
    fx32 hi, lo;
    fx32 h = sub_02054940(fieldSystem, playerPos->y, (x << 16) + 0x8000, (z << 16) + 0x8000, outKind);
    if (h < playerPos->y) {
        hi = playerPos->y;
        lo = h;
        dir = -1;
    } else if (h > playerPos->y) {
        hi = h;
        lo = playerPos->y;
        dir = 1;
    } else {
        return 0;
    }
    if (hi - lo >= 0x14000) {
        if (dir == 0) {
            GF_AssertFail();
        }
    } else {
        dir = 0;
    }
    return dir;
}

BOOL sub_020549A8(FieldSystem *fieldSystem, VecFx32 *playerPos, int xInFront, int yInFront, int a4) {
    u8 kind;
    BOOL ret;
    int slope = sub_02054954(fieldSystem, playerPos, xInFront, yInFront, &kind);
    if (a4 != 0) {
        *(u8 *)a4 = (u8)slope;
    }
    if (slope == 0) {
        ret = sub_020548C0(fieldSystem, xInFront, yInFront);
        if (!ret && kind == 2) {
            GetMetatileBehavior(fieldSystem, xInFront, yInFront);
        }
        return ret;
    }
    return TRUE;
}

u32 sub_020549F4(FieldSystem *fieldSystem, VecFx32 *playerPos, u32 x, u32 y, u32 *a4) {
    u8 kind;
    BOOL ret;
    int slope = sub_02054954(fieldSystem, playerPos, x, y, &kind);
    if (a4 != NULL) {
        *(u8 *)a4 = (u8)slope;
    }
    if (slope == 0) {
        if (Gymmick_CheckCollision(fieldSystem, x, y, playerPos->y, (u32)&ret) == 0) {
            ret = sub_020548C0(fieldSystem, x, y);
            if (!ret && kind == 2) {
                GetMetatileBehavior(fieldSystem, x, y);
            }
            return ret;
        }
        return ret;
    }
    return TRUE;
}

void sub_02054A60(int a0, int a1, int a2, int a3, int a4, int a5, fx32 *out) {
    int x1 = a0 + a2;
    int z1 = a1 + a3;
    int x2 = x1 + a4;
    int z2 = z1 + a5;
    if (x1 < 0 || z1 < 0 || x2 < 0 || z2 < 0) {
        GF_AssertFail();
    }
    out[0] = x1 << 16;
    out[1] = z1 << 16;
    out[2] = x2 << 16;
    out[3] = z2 << 16;
}

BOOL sub_02054A9C(MapProp *mapProp, fx32 *rect, VecFx32 *offset) {
    VecFx32 pos;
    MapProp_GetTranslation(&pos, mapProp);
    pos.x = pos.x + offset->x;
    pos.z = pos.z + offset->z;
    if (rect[0] <= pos.x && pos.x <= rect[2] && rect[1] <= pos.z && pos.z <= rect[3]) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02054AE4(FieldSystem *fieldSystem, int buildModel, fx32 *rect, MapProp **outProp) {
    u8 i;
    u8 j;
    MapPropManager *mgr;
    VecFx32 pos;
    MapProp *prop;
    int idx;
    int model;
    for (i = 0; i < 4; i++) {
        ov01_021F630C(i, fieldSystem->mapLoadManager, &mgr);
        if (mgr == NULL) {
            continue;
        }
        idx = ov01_021F652C(fieldSystem->mapLoadManager, i);
        sub_02054DC8(idx, MapMatrix_GetWidth(fieldSystem->mapMatrix), &pos);
        for (j = 0; j < 32; j++) {
            prop = MapPropManager_GetMapPropByIndex(mgr, j);
            if (sub_02054A9C(prop, rect, &pos)) {
                model = MapProp_GetBuildModel(prop);
                if (model == buildModel) {
                    if (outProp != NULL) {
                        *outProp = prop;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL sub_02054B74(FieldSystem *fieldSystem, int *models, u32 count, fx32 *rect, MapProp **outProp, int *outModel) {
    u8 i;
    u8 j;
    u8 k;
    MapPropManager *mgr;
    VecFx32 pos;
    MapProp *prop;
    int idx;
    int model;
    for (i = 0; i < 4; i++) {
        ov01_021F630C(i, fieldSystem->mapLoadManager, &mgr);
        if (mgr == NULL) {
            continue;
        }
        idx = ov01_021F652C(fieldSystem->mapLoadManager, i);
        sub_02054DC8(idx, MapMatrix_GetWidth(fieldSystem->mapMatrix), &pos);
        for (j = 0; j < 32; j++) {
            prop = MapPropManager_GetMapPropByIndex(mgr, j);
            if (sub_02054A9C(prop, rect, &pos)) {
                model = MapProp_GetBuildModel(prop);
                for (k = 0; k < count; k++) {
                    if (model == models[k]) {
                        if (outProp != NULL) {
                            *outProp = prop;
                        }
                        if (outModel != NULL) {
                            *outModel = model;
                        }
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

BOOL sub_02054C20(FieldSystem *fieldSystem, int buildModel, MapProp **outProp, int *outIdx) {
    u8 i;
    u8 j;
    MapPropManager *mgr;
    MapProp *prop;
    int model;
    for (i = 0; i < 4; i++) {
        ov01_021F630C(i, fieldSystem->mapLoadManager, &mgr);
        if (mgr == NULL) {
            continue;
        }
        for (j = 0; j < 32; j++) {
            prop = MapPropManager_GetMapPropByIndex(mgr, j);
            model = MapProp_GetBuildModel(prop);
            if (model == buildModel) {
                if (outProp != NULL) {
                    *outProp = prop;
                }
                if (outIdx != NULL) {
                    *outIdx = ov01_021F652C(fieldSystem->mapLoadManager, i);
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL sub_02054C90(FieldSystem *fieldSystem, int *models, u32 count, MapProp **outProp, int *outModel) {
    u8 i;
    u8 j;
    u8 k;
    MapPropManager *mgr;
    MapProp *prop;
    int model;
    for (i = 0; i < 4; i++) {
        ov01_021F630C(i, fieldSystem->mapLoadManager, &mgr);
        if (mgr == NULL) {
            continue;
        }
        for (j = 0; j < 32; j++) {
            prop = MapPropManager_GetMapPropByIndex(mgr, j);
            model = MapProp_GetBuildModel(prop);
            for (k = 0; k < count; k++) {
                if (model == models[k]) {
                    if (outProp != NULL) {
                        *outProp = prop;
                    }
                    if (outModel != NULL) {
                        *outModel = model;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
