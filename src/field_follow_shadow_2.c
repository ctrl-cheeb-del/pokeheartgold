#include "field_follow_shadow_internal.h"

void ov01_021FD47C(FollowShadow *work) {
    SysTask_Destroy(work->unk24);
}

void ov01_021FD488(FollowShadow *work, VecFx32 *dest) {
    *dest = work->unk14;
}

int ov01_021FD498(fx32 value) {
    return value / 0x1000;
}

void ov01_021FD4A4(FollowShadow *work, int timeOfDay) {
    work->unk10 = ov01_02208EB4[work->unk4];
    work->unk14 = ov01_02208F38[work->unk4];
}

void ov01_021FD4D0(fx32 *value, fx32 target, fx32 step) {
    fx32 cur = *value;
    if (cur < target) {
        cur += step;
        *value = cur;
        if (cur > target) {
            *value = target;
        }
    } else if (cur > target) {
        cur -= step;
        *value = cur;
        if (cur < target) {
            *value = target;
        }
    }
}

void ov01_021FD4F4(SysTask *task, FollowShadow *work) {
    fx32 y;
    VecFx32 scale;
    fx32 alpha;
    fx32 z;
    int state;
    TIMEOFDAY timeOfDay = GF_RTC_GetTimeOfDay();

    state = work->unk0;
    switch (state) {
    case 0:
        work->unk4 = timeOfDay;
        ov01_021FD4A4(work, timeOfDay);
        ov01_021FD624(work, ov01_021FD498(work->unk10));
        work->unk0++;
        break;
    case 1:
        if (work->unk4 == timeOfDay) {
            break;
        }
        work->unk0 = state + 1;
        // fallthrough
    case 2:
        alpha = ov01_02208EB4[timeOfDay];
        scale = ov01_02208F38[timeOfDay];
        ov01_021FD4D0(&work->unk14.x, scale.x, 0x10);
        y = scale.y;
        ov01_021FD4D0(&work->unk14.y, y, 0x10);
        z = scale.z;
        ov01_021FD4D0(&work->unk14.z, z, 0x10);
        ov01_021FD4D0(&work->unk10, alpha, 0x200);
        ov01_021FD624(work, ov01_021FD498(work->unk10));
        if (scale.x == work->unk14.x && y == work->unk14.y && z == work->unk14.z && alpha == work->unk10) {
            work->unk4 = timeOfDay;
            work->unk0 = 1;
        }
        break;
    }
}

void ov01_021FD5CC(FollowShadow *work) {
    int i;
    for (i = 0; i < 4; i++) {
        ov01_021F19F4(work->unk20, &work->unk28[i], 0, ov01_02208E90[i], 0);
        sub_02069978(&work->unk78[i], &work->unk28[i]);
    }
}

void ov01_021FD60C(FollowShadow *work) {
    int i;
    for (i = 0; i < 4; i++) {
        sub_02069784(&work->unk28[i]);
    }
}

void ov01_021FD624(FollowShadow *work, u32 alpha) {
    NNSi_G3dModifyPolygonAttrMask(work->unk28[0].unkC, 1, 0x1F << 16);
    NNS_G3dMdlSetMdlAlphaAll(work->unk28[0].unkC, alpha);
}

void ov01_021FD640(LocalMapObject *object) {
    FieldEffectRendererArgs args;
    VecFx32 pos;
    FieldSystem *fieldSystem = ov01_021F146C(object);
    args.unk0 = (u32)fieldSystem;
    args.unk4 = (FieldSystem *)ov01_021F1450(fieldSystem, 0);
    args.unk8 = object;
    MapObject_CopyPositionVector(object, &pos);
    ov01_021F1620(fieldSystem, &ov01_02208EA0, &pos, 0, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(object, 2));
}

void ov01_021FD684(LocalMapObject *object) {
    FieldEffectRendererArgs args;
    VecFx32 pos;
    FieldSystem *fieldSystem = ov01_021F146C(object);
    args.unk0 = (u32)fieldSystem;
    args.unk4 = (FieldSystem *)ov01_021F1450(fieldSystem, 0);
    args.unk8 = object;
    MapObject_CopyPositionVector(object, &pos);
    ov01_021F1620(fieldSystem, &ov01_02208EC8, &pos, 3, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(object, 2));
}

BOOL ov01_021FD6C8(void *a0, FollowShadowWork *work) {
    *(FieldEffectRendererArgs *)&work->unk14 = *(FieldEffectRendererArgs *)sub_02068D98(a0);
    work->unk10 = sub_02068D90(a0);
    work->unk0 = MapObject_GetSpriteID(work->unk1C);
    work->unk4 = MapObject_GetID(work->unk1C);
    if (MapObject_CheckFlag25(work->unk1C) == TRUE) {
        work->unk8 = sub_0205F544(work->unk1C);
    } else {
        work->unk8 = MapObject_GetMapID(work->unk1C);
    }
    return TRUE;
}

void ov01_021FD714(void *a0, FollowShadowWork *work) {
}

void ov01_021FD718(void *a0, FollowShadowWork *work) {
    VecFx32 pos;
    LocalMapObject *object = work->unk1C;
    if (!sub_0205F0F8(object, work->unk0, work->unk4, work->unk8)) {
        ov01_021F1640((int)a0);
        return;
    }
    if (sub_0205F5E8(object, (MapObjectFlagBits)8)) {
        ov01_021F1640((int)a0);
        return;
    }
    work->unkC = 0;
    if (MapObject_TestFlagsBits(object, (MapObjectFlagBits)0x00100200) == TRUE) {
        work->unkC = 1;
        return;
    }
    MapObject_CopyPositionVector(object, &pos);
    sub_02068DA8(a0, &pos);
}

BOOL ov01_021FD784(void *a0, FollowShadowWork *work) {
    *(FieldEffectRendererArgs *)&work->unk14 = *(FieldEffectRendererArgs *)sub_02068D98(a0);
    work->unk10 = sub_02068D90(a0);
    work->unk0 = MapObject_GetSpriteID(work->unk1C);
    work->unk4 = MapObject_GetID(work->unk1C);
    if (MapObject_CheckFlag25(work->unk1C) == TRUE) {
        work->unk8 = sub_0205F544(work->unk1C);
    } else {
        work->unk8 = MapObject_GetMapID(work->unk1C);
    }
    work->unkC = TRUE;
    return TRUE;
}

void ov01_021FD7D4(void *a0, FollowShadowWork *work) {
    VecFx32 pos;
    VecFx32 scale;
    MtxFx33 mtx;
    FollowShadow *shadow;
    if (work->unkC != 0) {
        return;
    }
    mtx = ov01_02208F14;
    shadow = work->unk18;
    ov01_021FD488(shadow, &scale);
    sub_02068DB8(a0, &pos);
    pos.x -= 0x800;
    pos.y -= 0x4000;
    pos.z += 0x1000;
    sub_020699AC(&shadow->unk78[0], &pos, &scale, &mtx);
}
