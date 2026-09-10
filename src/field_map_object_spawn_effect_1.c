#include "field_map_object_spawn_effect_internal.h"

typedef struct LocalSpawnArgs {
    void *fieldSystem;
    void *manager;
    void *resource;
    void *mapObject;
    VecFx32 position;
} LocalSpawnArgs;
extern const u32 ov01_02208F88[];
extern const u32 ov01_02208F74[];
typedef struct LocalFourWords {
    u32 v[4];
} LocalFourWords;
typedef struct LocalTenWords {
    u32 v[10];
} LocalTenWords;
typedef struct LocalFourteenWords {
    u32 v[14];
} LocalFourteenWords;
typedef struct LocalSixWords {
    fx32 v[6];
} LocalSixWords;
extern const u32 ov01_02208F9C[];

static const LocalSixWords sSpawnHeights = {
    { 0xe000, 0x14000, 0xe000, 0xe000, 0x14000, 0xe000 }
};

static inline void LocalSpawn(void *obj, void *arg, const u32 *callbacks) {
    LocalSpawnArgs a;
    a.fieldSystem = MapObject_GetFieldSystem(obj);
    a.manager = ov01_021F146C(obj);
    a.resource = ov01_021F1450(a.manager, 1);
    a.mapObject = obj;
    MapObject_CopyPositionVector(obj, &a.position);
    ov01_021F1620(a.manager, callbacks, &a.position, arg, &a, MapObject_GetPriorityPlusValue(obj, 2));
}
LocalTaskCtx *ov01_021FDA14(void *owner) {
    LocalTaskCtx *ctx = ov01_021F1430(owner, 4, 0, 0);
    ctx->owner = owner;
    ov01_021FDA40(ctx);
    return ctx;
}
void ov01_021FDA30(LocalTaskCtx *ctx) {
    ov01_021FDA5C(ctx);
    ov01_021F1448(ctx);
}
void ov01_021FDA40(LocalTaskCtx *ctx) {
    ov01_021F18D4(ctx->owner, 2, 0x23);
    ov01_021F18D4(ctx->owner, 0xd, 0x69);
}
void ov01_021FDA5C(LocalTaskCtx *ctx) {
    ov01_021F18FC(ctx->owner, 2);
    ov01_021F18FC(ctx->owner, 0xd);
}
void ov01_021FDA74(void *obj, void *arg) {
    LocalSpawn(obj, arg, ov01_02208F88);
}
BOOL ov01_021FDAC0(void *task, LocalEffectState *state) {
    VecFx32 pos;
    *(LocalFourWords *)&state->data14 = *(LocalFourWords *)sub_02068D98(task);
    state->mode = sub_02068D90(task);
    state->objectId = MapObject_GetID(state->mapObject);
    state->mapId = MapObject_GetMapID(state->mapObject);
    state->spriteId = MapObject_GetSpriteID(state->mapObject);
    state->scaleX = FX32_ONE;
    state->scaleY = FX32_ONE;
    state->scaleZ = FX32_ONE;
    state->delta = 0x40;
    if (state->mode == 2) {
        state->delta = 0;
    }
    ov01_021FDC7C(state, state->mapObject, &pos);
    sub_02068DA8(task, &pos);
    ov01_021FDD48(task, state);
    return TRUE;
}
void ov01_021FDB34(void *task, LocalEffectState *state) {
    if (state->active == 1) {
        sub_02023DA4(state->effect);
    }
}
void ov01_021FDB44(void *task, LocalEffectState *state) {
    VecFx32 pos;
    void *obj = state->mapObject;
    if (state->spriteId != MapObject_GetSpriteID(obj) || !sub_0205F0A8(obj, state->objectId, state->mapId) || !MapObject_CheckFlag24(obj)) {
        ov01_021F1640(task);
        return;
    }
    state->scaleX += state->delta;
    if (state->scaleX >= 0x1200) {
        state->scaleX = 0x1200;
        state->delta = -state->delta;
    } else if (state->scaleX <= 0xe00) {
        state->scaleX = 0xe00;
        state->delta = -state->delta;
    }
    ov01_021FDC7C(state, obj, &pos);
    sub_02068DA8(task, &pos);
    if (state->active == 0) {
        ov01_021FDD48(task, state);
    }
}
void ov01_021FDBCC(void *task, LocalEffectState *state) {
    struct {
        VecFx32 pos;
        VecFx32 facing;
    } local;
    void *obj = state->mapObject;
    void *source;
    BOOL hidden = FALSE;
    if (state->spriteId != MapObject_GetSpriteID(obj) || !sub_0205F0A8(obj, state->objectId, state->mapId) || !MapObject_CheckFlag24(obj)) {
        ov01_021F1640(task);
        return;
    }
    if (state->active == 0) {
        return;
    }
    MapObject_CopyFacingVector(state->mapObject, &local.facing);
    if (local.facing.y != 0) {
        hidden = TRUE;
    }
    if (MapObject_CheckVisible(obj) == TRUE) {
        hidden = TRUE;
    }
    if (hidden) {
        sub_02023EA4(state->effect, FALSE);
    } else {
        sub_02023EA4(state->effect, TRUE);
    }
    sub_02068DB8(task, &local.pos);
    sub_02023E50(state->effect, &local.pos);
    sub_02023E78(state->effect, &state->scaleX);
    source = ov01_021F72DC(state->mapObject);
    sub_02023EE0(state->effect, sub_02023EF4(source));
    sub_02023F1C(state->effect, sub_02023F30(source));
}
void ov01_021FDC7C(LocalEffectState *state, void *obj, VecFx32 *out) {
    const LocalSixWords init = {
        { 0xe000, 0x14000, 0xe000, 0xe000, 0x14000, 0xe000 }
    };
    struct {
        LocalSixWords heights;
        VecFx32 facing;
    } local;
    fx32 xOffset, zOffset, vertical;
    int onFloor;
    local.heights = init;
    MapObject_CopyFacingVector(obj, &local.facing);
    xOffset = local.facing.x;
    if (MapObject_GetID(obj) == 0xff && MapObject_GetSpriteID(obj) == 0xbc) {
        fx32 base;
        int direction;
        direction = MapObject_GetFacingDirection(obj);
        base = 2;
        base <<= 10;
        if (direction == 1) {
            zOffset = base;
            zOffset += base << 1;
            zOffset -= local.facing.z;
        } else {
            zOffset = local.facing.z;
        }
    } else {
        zOffset = local.facing.z;
    }
    vertical = -(local.facing.y / 6);
    if (MapObject_GetID(obj) == 0xfd && MapObject_GetSpriteID(PlayerAvatar_GetMapObject(*(void **)((u8 *)(void *)state->data14[0] + 0x40))) == 0xbc) {
        vertical = 0;
    }
    MapObject_CopyPositionVector(obj, out);
    onFloor = sub_0206121C((void *)state->data14[0], out);
    out->x += xOffset;
    out->z += zOffset - 7 * FX32_ONE;
    if (onFloor == 0) {
        out->y = 0;
    } else {
        out->y -= local.heights.v[state->mode];
    }
    out->y += vertical;
}
void ov01_021FDD48(void *task, LocalEffectState *state) {
    struct {
        u8 args[40];
        VecFx32 pos;
    } local;
    if (ov01_021F9744(MapObject_GetManager(state->mapObject), state->spriteId, local.args) && ov01_021FA2D4(state->mapObject) != 1) {
        *(void **)local.args = ov01_021F18F0((void *)state->data14[1], 2);
        sub_02068DB8(task, &local.pos);
        state->effect = ov01_021F16EC((void *)state->data14[1], local.args, &local.pos);
        state->active = 1;
    }
}
void ov01_021FDD94(void *task, LocalExtendedEffectState *state) {
    struct {
        u8 args[40];
        VecFx32 pos;
    } local;
    void *oldEffect;
    *(LocalTenWords *)local.args = *(LocalTenWords *)((u8 *)state + 0x10);
    *(void **)local.args = ov01_021F18F0((void *)state->data04[1], 2);
    sub_02068DB8(task, &local.pos);
    state->effect = ov01_021F16EC((void *)state->data04[1], local.args, &local.pos);
    oldEffect = *(void **)((u8 *)state + 0x38);
    sub_02023EE0(state->effect, sub_02023EF4(oldEffect));
    sub_02023F40(state->effect, sub_02023F70(oldEffect));
    sub_02023F1C(state->effect, sub_02023F30(oldEffect));
    sub_02023F04(state->effect, 0);
    sub_02023FC0(state->effect);
}
void ov01_021FDE08(LocalExtendedEffectState *state, VecFx32 *out) {
    LocalSixWords heights = sSpawnHeights;
    int onFloor;
    *out = state->position;
    onFloor = sub_0206121C((void *)state->data04[0], out);
    out->z -= 7 * FX32_ONE;
    if (onFloor == 0) {
        out->y = 0;
    } else {
        out->y -= heights.v[state->mode];
    }
}
void ov01_021FDE64(void *owner, const void *input, void *value, void *callbackArg, void *arg5, int arg6) {
    struct {
        void *manager;
        void *owner;
        void *resource;
        LocalTenWords config;
        void *value;
    } local;
    local.manager = ov01_021F1468(owner);
    local.owner = owner;
    local.resource = ov01_021F1450(owner, 1);
    local.config = *(const LocalTenWords *)input;
    local.value = value;
    ov01_021F1620(owner, ov01_02208F9C, callbackArg, arg5, &local, arg6);
}
BOOL ov01_021FDEAC(void *task, LocalExtendedEffectState *state) {
    VecFx32 pos;
    *(LocalFourteenWords *)state->data04 = *(LocalFourteenWords *)sub_02068D98(task);
    state->mode = sub_02068D90(task);
    state->scaleX = FX32_ONE;
    state->scaleY = FX32_ONE;
    state->scaleZ = FX32_ONE;
    state->delta = 0x40;
    if (state->mode == 2) {
        state->delta = 0;
    }
    sub_02068DB8(task, &state->position);
    ov01_021FDE08(state, &pos);
    sub_02068DA8(task, &pos);
    ov01_021FDD94(task, state);
    sub_02068D18(task);
    return TRUE;
}
void ov01_021FDF14(void *task, LocalExtendedEffectState *state) {
    sub_02023DA4(state->effect);
}
void ov01_021FDF20(void *task, LocalExtendedEffectState *state) {
    VecFx32 pos;
    state->scaleX += state->delta;
    if (state->scaleX >= 0x1200) {
        state->scaleX = 0x1200;
        state->delta = -state->delta;
    } else if (state->scaleX <= 0xe00) {
        state->scaleX = 0xe00;
        state->delta = -state->delta;
    }
    ov01_021FDE08(state, &pos);
    sub_02068DA8(task, &pos);
}
void ov01_021FDF64(void *task, LocalExtendedEffectState *state) {
    VecFx32 pos;
    sub_02068DB8(task, &pos);
    sub_02023E50(state->effect, &pos);
    sub_02023E78(state->effect, &state->scaleX);
}
void ov01_021FDF88(void *obj, void *arg) {
    LocalSpawn(obj, arg, ov01_02208F74);
}
BOOL ov01_021FDFD4(void *task, LocalEffectState *state) {
    VecFx32 pos;
    *(LocalFourWords *)&state->data14 = *(LocalFourWords *)sub_02068D98(task);
    state->mode = sub_02068D90(task);
    state->objectId = MapObject_GetID(state->mapObject);
    state->mapId = MapObject_GetMapID(state->mapObject);
    state->spriteId = MapObject_GetSpriteID(state->mapObject);
    state->scaleX = FX32_ONE;
    state->scaleY = FX32_ONE;
    state->scaleZ = FX32_ONE;
    state->delta = 0x40;
    if (state->mode == 2 || state->mode == 5) {
        state->delta = 0;
    }
    ov01_021FDC7C(state, state->mapObject, &pos);
    pos.y -= 0x514;
    sub_02068DA8(task, &pos);
    ov01_021FE190(task, state);
    return TRUE;
}
void ov01_021FE058(void *task, LocalEffectState *state) {
    VecFx32 pos;
    void *obj = state->mapObject;
    if (state->spriteId != MapObject_GetSpriteID(obj) || !sub_0205F0A8(obj, state->objectId, state->mapId) || !MapObject_CheckFlag24(obj)) {
        ov01_021F1640(task);
        return;
    }
    state->scaleX += state->delta;
    if (state->scaleX >= 0x1200) {
        state->scaleX = 0x1200;
        state->delta = -state->delta;
    } else if (state->scaleX <= 0xe00) {
        state->scaleX = 0xe00;
        state->delta = -state->delta;
    }
    ov01_021FDC7C(state, obj, &pos);
    pos.y -= 0x514;
    sub_02068DA8(task, &pos);
    if (state->active == 0) {
        ov01_021FE190(task, state);
    }
}
void ov01_021FE0EC(void *task, LocalEffectState *state) {
    VecFx32 pos;
    void *obj = state->mapObject;
    void *source;
    if (state->spriteId != MapObject_GetSpriteID(obj) || !sub_0205F0A8(obj, state->objectId, state->mapId) || !MapObject_CheckFlag24(obj)) {
        ov01_021F1640(task);
        return;
    }
    if (state->active == 0) {
        return;
    }
    if (MapObject_CheckVisible(obj) == TRUE) {
        sub_02023EA4(state->effect, FALSE);
    } else {
        sub_02023EA4(state->effect, TRUE);
    }
    sub_02068DB8(task, &pos);
    pos.z -= FX32_ONE;
    sub_02023E50(state->effect, &pos);
    sub_02023E78(state->effect, &state->scaleX);
    source = ov01_021F72DC(state->mapObject);
    sub_02023EE0(state->effect, sub_02023EF4(source));
    sub_02023F1C(state->effect, sub_02023F30(source));
}
void ov01_021FE190(void *task, LocalEffectState *state) {
    struct {
        u8 args[40];
        VecFx32 pos;
    } local;
    void *resource;
    if (ov01_021F9744(MapObject_GetManager(state->mapObject), state->spriteId, local.args) && ov01_021FA2D4(state->mapObject) != 1) {
        if (state->mode <= 2) {
            resource = ov01_021F18F0((void *)state->data14[1], 2);
        } else {
            resource = ov01_021F18F0((void *)state->data14[1], 0xd);
        }
        *(void **)local.args = resource;
        if (ov01_0220553C(state->mapObject)) {
            ov01_02205870(1, state->mapObject, state->effect, local.args);
        }
        sub_02068DB8(task, &local.pos);
        state->effect = ov01_021F16EC((void *)state->data14[1], local.args, &local.pos);
        state->active = 1;
    }
}
