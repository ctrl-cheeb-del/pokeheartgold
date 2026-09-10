#include "field_object_motion_effect_internal.h"
typedef struct LocalNineWords {
    u32 v[9];
} LocalNineWords;
extern const u32 ov01_02209258[];
LocalCtx *ov01_021FFC0C(void *owner) {
    LocalCtx *ctx = ov01_021F1430(owner, 4, 0, 0);
    ctx->owner = owner;
    ov01_021FFC38(ctx);
    return ctx;
}

void ov01_021FFC28(LocalCtx *ctx) {
    ov01_021FFC80(ctx);
    ov01_021F1448(ctx);
}

void ov01_021FFC38(LocalCtx *ctx) {
    ov01_021F18D4(ctx->owner, 8, 0x7b);
    ov01_021F1908(ctx->owner, 8, 0x93);
    ov01_021F1930(ctx->owner, 9, 0x16, 1);
    ov01_021F1758(ctx->owner, 0xa, 8, 8, 9, 0, ov01_02209258);
}

void ov01_021FFC80(LocalCtx *ctx) {
    ov01_021F18FC(ctx->owner, 8);
    ov01_021F1924(ctx->owner, 8);
    ov01_021F1970(ctx->owner, 9);
    ov01_021F18C8(ctx->owner, 0xa);
}

BOOL ov01_021FFCA8(void *task, LocalState *s) {
    VecFx32 pos;
    *(LocalNineWords *)&s->x = *(LocalNineWords *)sub_02068D98(task);
    s->sprite = MapObject_GetSpriteID(s->mapObject);
    s->id = MapObject_GetID(s->mapObject);
    s->mapId = MapObject_GetMapID(s->mapObject);
    pos.x = s->x << 16;
    pos.z = s->z << 16;
    pos.y = MapObject_GetPositionVectorYCoord(s->mapObject);
    s->onFloor = sub_0206121C(s->fieldSystem, &pos);
    pos.x += 0x1e << 10;
    pos.y -= 2 << 14;
    pos.z += 0xd << 12;
    sub_02068DA8(task, &pos);
    s->effect = ov01_021F1740(s->resource, 0xa, &pos);
    if (MapObject_TestFlagsBits(s->mapObject, 2 << 8) == TRUE) {
        sub_02023EA4(s->effect, FALSE);
    }
    if (sub_02068D90(task) == 0) {
        sub_02023F1C(s->effect, 2 << 12);
        s->stage = 2;
    }
    return TRUE;
}

void ov01_021FFD64(void *task, LocalState *s) {
    sub_02023DA4(s->effect);
}

void ov01_021FFD70(void *task, LocalState *s) {
    struct {
        VecFx32 target, current;
    } local;
    void *obj = s->mapObject;
    int x, z;
    if (!sub_0205F0F8(obj, s->sprite, s->id, s->mapId)) {
        ov01_021F1640(task);
        return;
    }
    if (MapObject_TestFlagsBits(obj, 2 << 8) == TRUE) {
        sub_02023EA4(s->effect, FALSE);
    } else {
        sub_02023EA4(s->effect, TRUE);
    }
    if (s->onFloor == 0) {
        sub_02068DB8(task, &local.current);
        local.target.x = s->x << 16;
        local.target.z = s->z << 16;
        local.target.y = local.current.y;
        s->onFloor = sub_0206121C(s->fieldSystem, &local.target);
        if (s->onFloor == 1) {
            local.current.y = local.target.y;
            sub_02068DA8(task, &local.current);
        }
    }
    switch (s->stage) {
    case 0:
        sub_02023F04(s->effect, FX32_ONE);
        if (sub_02023F70(s->effect) / FX32_ONE >= 2) {
            s->stage = 1;
        }
        break;
    case 1:
        sub_02023F1C(s->effect, 2 * FX32_ONE);
        sub_02023F04(s->effect, 0);
        s->stage = 2;
    case 2:
        if (!sub_0205F0F8(obj, s->sprite, s->id, s->mapId)) {
            ov01_021F1640(task);
            return;
        }
        x = MapObject_GetXCoord(obj);
        z = MapObject_GetZCoord(obj);
        if (s->x != x || s->z != z) {
            ov01_021F1640(task);
            return;
        }
        if (s->facing != -1 && s->facing != MapObject_GetFacingDirection(obj)) {
            ov01_021F1640(task);
        }
        break;
    }
}

void ov01_021FFE98(void *task, LocalState *s) {
    VecFx32 pos;
    if (!sub_0205F0A8(s->mapObject, s->id, s->mapId)) {
        ov01_021F1640(task);
        return;
    }
    sub_02068DB8(task, &pos);
    sub_02023E50(s->effect, &pos);
}
