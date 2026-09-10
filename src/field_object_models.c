#include "field_object_models_internal.h"

void ov01_021F8D80(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra, u32 direction, BOOL a4);
void ov01_021F8E70(LocalMapObject *object, u32 direction, VecFx32 *vec);
void ov01_021F8F08(LocalMapObject *object, BOOL set);
void ov01_021F8F68(LocalMapObject *object, s8 a1);
void ov01_021F8F74(LocalMapObject *object, s8 a1);
BOOL ov01_021F8F88(LocalMapObject *object);
void ov01_021F8FA0(LocalMapObject *object, VecFx32 *vec);
BOOL ov01_021F8FC0(u8 direction, LocalMapObject *object, Sprite *sprite);
void ov01_021F902C(void *a0, LocalMapObject *object);
void ov01_021F9048(LocalMapObject *object);
void ov01_021F9058(LocalMapObject *object);
void ov01_021F9078(LocalMapObject *object);
void ov01_021F90C8(LocalMapObject *object);
void ov01_021F90D0(LocalMapObject *object);
void ov01_021F90FC(LocalMapObject *object);
void ov01_021F9140(LocalMapObject *object);
void ov01_021F9154(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra);
void ov01_021F917C(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra);
void ov01_021F91A4(LocalMapObject *object, Sprite *sprite);
void ov01_021F91E4(LocalMapObject *object);
void ov01_021F91F8(MapObjectManager *manager, u32 a1, u32 a2, u32 a3, u32 a4);
void ov01_021F9250(MapObjectManager *manager);
void FldObjSys_OpenMModelNarc(MapObjectManager *manager);
void FldObjSys_CloseMModelNarc(MapObjectManager *manager);
void ov01_021F92A0(LocalMapObject *object);
MModelGraphicsInfo *ObjectEvent_GetGraphicsInfo(u32 spriteId);
int GetMoveModelNoBySpriteId(u32 spriteId);
u16 *ov01_021F9318(LocalMapObject *object);
u16 *ov01_021F9324(u32 spriteId);
BOOL ov01_021F9344(LocalMapObject *object);
void *ReadMModelFromNarcInternal(MapObjectManager *manager, u32 memberIdx, BOOL atStart);
void ov01_021F93AC(LocalMapObject *object, VecFx32 *dest);
void ov01_021F9408(LocalMapObject *object, u32 direction);
void ov01_021F9424(LocalMapObject *object);
void ov01_021F943C(LocalMapObject *object);
void ov01_021F9440(LocalMapObject *object);
void ov01_021F9444(LocalMapObject *object);
void ov01_021F9448(LocalMapObject *object);

static const UnkObjExtraCallback sUnkObjExtraCallbacks[] = {
    ov01_021F9154,
    ov01_021F917C,
};

void ov01_021F8D80(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra, u32 direction, BOOL a4) {
    BOOL flag4;
    int r0;
    BOOL paused;
    VecFx32 vec;

    paused = ov01_021F9344(object);
    flag4 = MapObject_CheckFlag4(object);
    r0 = ov01_02205564(object);
    if (((u32)extra->unk17 << 29) >> 31) {
        MapObject_CopyFacingVector(object, &vec);
        vec.y = extra->unk14 << 12;
    } else {
        if (paused != 0 || flag4 != 0 || r0 != 0) {
            MapObject_CopyFacingVector(object, &vec);
            vec.x = 0;
            vec.z = 0;
        } else {
            vec.x = 0;
            vec.y = 0;
            vec.z = 0;
        }
        if (a4) {
            ov01_021F8E70(object, direction, &vec);
        }
        vec.y += ov01_022054E0(object);
    }
    if (direction != extra->unk10) {
        sub_02023EE0(sprite, ov01_021FA44C(direction));
        sub_02023F40(sprite, 0);
        extra->unk15 = 0;
    }
    if (paused == 0 && flag4 == 0) {
        sub_02023F04(sprite, 1 << 12);
        if (ov01_021F8FC0((u8)direction, object, sprite)) {
            vec.y -= 2 << 12;
            extra->unk15 = 1;
        } else {
            extra->unk15 = 0;
        }
    }
    if (flag4) {
        sub_02023F04(sprite, 1 << 12);
    }
    MapObject_SetFacingVector(object, &vec);
}

void ov01_021F8E70(LocalMapObject *object, u32 direction, VecFx32 *vec) {
    VecFx32 unused;

    MapObject_CopyFacingVector(object, &unused);
    if (ov01_021FA298(MapObject_GetSpriteID(object)) == 10) {
        switch (direction) {
        case 0:
            vec->z += 1 << 12;
            break;
        case 1:
            vec->z -= 1 << 12;
            break;
        case 2:
            vec->x += 10 << 12;
            break;
        case 3:
            vec->x -= 10 << 12;
            break;
        }
    } else {
        switch (direction) {
        case 2:
            vec->x += 2 << 12;
            break;
        case 3:
            vec->x -= 2 << 12;
            break;
        }
    }
}

void ov01_021F8F08(LocalMapObject *object, BOOL set) {
    UnkObjExtra *extra;
    VecFx32 vec;
    fx32 *p;

    extra = (UnkObjExtra *)sub_0205F40C(object);
    if (set) {
        p = (fx32 *)&vec;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        extra->unk17 |= 4;
        ov01_021FD9CC(MapObject_GetFacingDirection(object), &vec);
        extra->unk12 = vec.x / (1 << 12);
        extra->unk13 = vec.z / (1 << 12);
    } else {
        extra->unk17 &= ~4;
        extra->unk12 = 0;
        extra->unk13 = 0;
    }
}

void ov01_021F8F68(LocalMapObject *object, s8 a1) {
    ((UnkObjExtra *)sub_0205F40C(object))->unk14 = a1;
}

void ov01_021F8F74(LocalMapObject *object, s8 a1) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    extra->unk14 = extra->unk14 + a1;
}

BOOL ov01_021F8F88(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    if (((u32)extra->unk17 << 29) >> 31) {
        return FALSE;
    }
    return TRUE;
}

void ov01_021F8FA0(LocalMapObject *object, VecFx32 *vec) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    vec->x = extra->unk12 << 12;
    vec->z = extra->unk13 << 12;
    vec->y = 0;
}

BOOL ov01_021F8FC0(u8 direction, LocalMapObject *object, Sprite *sprite) {
    int v = sub_02023F30(sprite) / (1 << 12);

    switch (direction) {
    case 0:
        break;
    case 1:
        v -= 20;
        break;
    case 2:
        v -= 40;
        break;
    case 3:
        v -= 60;
        break;
    }
    if (ov01_022055B0(object)) {
        if (direction == 1) {
            if (v < 5 || v >= 15) {
                return TRUE;
            }
        } else if (v < 10) {
            return TRUE;
        }
    } else if ((v >= 5 && v < 10) || v >= 15) {
        return TRUE;
    }
    return FALSE;
}

void ov01_021F902C(void *a0, LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    ov01_02205808(a0, object, extra->sprite);
}

void ov01_021F9048(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    extra->unk17 &= ~1;
}

void ov01_021F9058(LocalMapObject *object) {
    VecFx32 vec;

    ov01_021F9140(object);
    vec.x = 0;
    vec.y = 0;
    vec.z = 0;
    sub_0205F9A0(object, &vec);
}

void ov01_021F9078(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    Sprite *sprite = extra->sprite;

    if (ov01_021FA2D4(object) == TRUE) {
        return;
    }
    if (sprite == NULL) {
        return;
    }
    sUnkObjExtraCallbacks[sub_0205F330(object)](object, sprite, extra);
    *(u32 *)&extra->unk10 = sub_0205F330(object);
    ov01_021FA3E8(object, sprite);
    ov01_021F91A4(object, sprite);
}

void ov01_021F90C8(LocalMapObject *object) {
    ov01_021F91E4(object);
}

void ov01_021F90D0(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);

    if (extra->sprite != NULL) {
        ov01_021F9610(extra->sprite, &extra->unk04);
    }
    ov01_021F95A8(object, extra);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(2 << 20));
}

void ov01_021F90FC(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);

    if (ov01_021FA2D4(object) == TRUE) {
        return;
    }
    if (extra->sprite == NULL) {
        ov01_021F9510(object, extra);
    }
    if (extra->sprite != NULL) {
        ov01_021F9630(extra->sprite, &extra->unk04);
        ov01_021FA3E8(object, extra->sprite);
        MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(2 << 20));
    }
}

void ov01_021F9140(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F3E8(object, 0x14);
    ov01_021F9510(object, extra);
}

void ov01_021F9154(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra) {
    if (*(u32 *)&extra->unk10 != 0) {
        sub_02023EE0(sprite, 0);
        sub_02023F40(sprite, 0);
    }
    sub_02023F04(sprite, 1 << 12);
}

void ov01_021F917C(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra) {
    if (*(u32 *)&extra->unk10 != 1) {
        sub_02023EE0(sprite, 1);
        sub_02023F40(sprite, 0);
    }
    sub_02023F04(sprite, 1 << 12);
}

void ov01_021F91A4(LocalMapObject *object, Sprite *sprite) {
    int v = 1;

    if (MapObject_TestFlagsBits(object, (MapObjectFlagBits)(1 << 9)) == TRUE) {
        v = 0;
    }
    if (MapObject_TestFlagsBits(object, (MapObjectFlagBits)(1 << 12)) == TRUE && MapObject_TestFlagsBits(object, (MapObjectFlagBits)(2 << 12)) == 0) {
        v = 0;
    }
    sub_02023EA4(sprite, v);
}

void ov01_021F91E4(LocalMapObject *object) {
    UnkObjExtra *extra = (UnkObjExtra *)sub_0205F40C(object);
    ov01_021F95A8(object, extra);
}

void ov01_021F91F8(MapObjectManager *manager, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 count;
    u32 priority;

    if (MapObjectManager_GetFlagsBitsMask(manager, (MapObjectFlagBits)1) != 0) {
        GF_AssertFail();
    }
    FldObjSys_OpenMModelNarc(manager);
    count = MapObjectManager_GetObjectCount(manager);
    priority = MapObjectManager_GetPriority(manager) - 1;
    ov01_021F944C(sub_0205F1A0(manager), manager, count, priority, a1, a2, a3, a4);
    MapObjectManager_SetFlagsBits(manager, (MapObjectFlagBits)1);
}

void ov01_021F9250(MapObjectManager *manager) {
    if (sub_0205F5D4(manager) != TRUE) {
        GF_AssertFail();
    }
    ov01_021F94A0(sub_0205F1A0(manager));
    MapObjectManager_ClearFlagsBits(manager, (MapObjectFlagBits)1);
    FldObjSys_CloseMModelNarc(manager);
}

void FldObjSys_OpenMModelNarc(MapObjectManager *manager) {
    MapObjectManager_SetMapModelNarc(manager, NARC_New(NARC_data_mmodel_mmodel, HEAP_ID_FIELD1));
}

void FldObjSys_CloseMModelNarc(MapObjectManager *manager) {
    NARC_Delete(MapObjectManager_GetMapModelNarc(manager));
}

void ov01_021F92A0(LocalMapObject *object) {
    if (MapObjectManager_GetFlagsBitsMask(MapObject_GetManager(object), (MapObjectFlagBits)4) != 0) {
        return;
    }
    if (MapObject_GetFlagsBitsMask(object, (MapObjectFlagBits)(1 << 14)) == 0) {
        return;
    }
    if (MapObject_CheckMovementPaused(object) == 0 || MapObject_CheckFlag4(object) != 0) {
        sub_0205F484(object);
    }
}

MModelGraphicsInfo *ObjectEvent_GetGraphicsInfo(u32 spriteId) {
    MModelGraphicsInfo *info = ov01_022074A8;

    do {
        if (info->spriteId == spriteId) {
            return info;
        }
        info++;
    } while (info->spriteId != 0xFFFF);
    GF_AssertFail();
    return NULL;
}

int GetMoveModelNoBySpriteId(u32 spriteId) {
    MModelGraphicsInfo *info = ObjectEvent_GetGraphicsInfo(spriteId);
    if (info == NULL) {
        return -1;
    }
    return info->mmodelNo;
}

u16 *ov01_021F9318(LocalMapObject *object) {
    return ov01_021F9324(MapObject_GetSpriteID(object));
}

u16 *ov01_021F9324(u32 spriteId) {
    MModelGraphicsInfo *info = ObjectEvent_GetGraphicsInfo(spriteId);
    if (info == NULL) {
        return NULL;
    }
    return &ov01_02206D00[info->unk4_lo];
}

BOOL ov01_021F9344(LocalMapObject *object) {
    if (MapObject_CheckMovementPaused(object) == TRUE && MapObject_CheckFlag4(object) == 0) {
        return TRUE;
    }
    if (MapObject_GetFlagsBitsMask(object, (MapObjectFlagBits)(1 << 8)) != 0) {
        return TRUE;
    }
    return FALSE;
}

void *ReadMModelFromNarcInternal(MapObjectManager *manager, u32 memberIdx, BOOL atStart) {
    void *dest;
    NARC *narc = MapObjectManager_GetMapModelNarc(manager);
    u32 size = NARC_GetMemberSize(narc, memberIdx);

    if (atStart == TRUE) {
        dest = Heap_Alloc(HEAP_ID_FIELD1, size);
    } else {
        dest = Heap_AllocAtEnd(HEAP_ID_FIELD1, size);
    }
    NARC_ReadWholeMember(narc, memberIdx, dest);
    return dest;
}

void ov01_021F93AC(LocalMapObject *object, VecFx32 *dest) {
    VecFx32 pos;
    VecFx32 facing;
    VecFx32 v2;
    VecFx32 v3;

    MapObject_CopyPositionVector(object, &pos);
    MapObject_CopyFacingVector(object, &facing);
    sub_0205F990(object, &v2);
    sub_0205F9B0(object, &v3);
    dest->x = pos.x + facing.x + v2.x + v3.x;
    dest->y = pos.y + facing.y + v2.y + v3.y;
    dest->z = pos.z + facing.z + v2.z + v3.z;
}

void ov01_021F9408(LocalMapObject *object, u32 direction) {
    MapObject_SetFacingDirection(object, direction);
    if (MapObject_CheckFlag14(object) == TRUE) {
        sub_0205F484(object);
    }
}

void ov01_021F9424(LocalMapObject *object) {
    MapObject_SetVisible(object, TRUE);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(1 << 20));
}

void ov01_021F943C(LocalMapObject *object) {
}

void ov01_021F9440(LocalMapObject *object) {
}

void ov01_021F9444(LocalMapObject *object) {
}

void ov01_021F9448(LocalMapObject *object) {
}
