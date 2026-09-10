#include "field_map_object_effect_internal.h"
typedef struct LocalFourWords {
    u32 v[4];
} LocalFourWords;
extern const u32 ov01_022091C0[], ov01_022091D4[];
LocalCtx *ov01_021FF464(void *owner) {
    LocalCtx *c = ov01_021F1430(owner, 4, 0, 0);
    c->owner = owner;
    ov01_021FF490(c);
    return c;
}
void ov01_021FF480(LocalCtx *c) {
    ov01_021FF4D4(c);
    ov01_021F1448(c);
}
void ov01_021FF490(LocalCtx *c) {
    ov01_021F18D4(c->owner, 3, 0x77);
    ov01_021F1908(c->owner, 2, 0x90);
    ov01_021F1930(c->owner, 2, 0x12, 1);
    ov01_021F1758(c->owner, 3, 3, 2, 2, 0, ov01_022091D4);
}
void ov01_021FF4D4(LocalCtx *c) {
    ov01_021F18FC(c->owner, 3);
    ov01_021F1924(c->owner, 2);
    ov01_021F1970(c->owner, 2);
    ov01_021F18C8(c->owner, 3);
}
void ov01_021FF4FC(void *obj, void *arg) {
    struct {
        void *fieldSystem, *manager, *resource, *object;
    } local;
    void *manager = ov01_021F146C(obj);
    local.fieldSystem = MapObject_GetFieldSystem(obj);
    local.manager = manager;
    local.resource = ov01_021F1450(manager, 0xa);
    {
        VecFx32 pos = { 0, 0, 0 };
        local.object = obj;
        ov01_021F1620(manager, ov01_022091C0, &pos, arg, &local, MapObject_GetPriorityPlusValue(obj, 2));
    }
}
BOOL ov01_021FF54C(void *task, LocalState *s) {
    VecFx32 pos = { 0, 0, 0 };
    *(LocalFourWords *)&s->data14 = *(LocalFourWords *)sub_02068D98(task);
    s->sprite = MapObject_GetSpriteID(s->mapObject);
    s->id = MapObject_GetID(s->mapObject);
    s->mapId = MapObject_GetMapID(s->mapObject);
    sub_02068DA8(task, &pos);
    s->effect = ov01_021F1740(s->resource, 3, &pos);
    if (MapObject_TestFlagsBits(s->mapObject, 2 << 8) == TRUE) {
        sub_02023EA4(s->effect, FALSE);
    }
    return TRUE;
}
void ov01_021FF5B8(void *task, LocalState *s) {
    sub_02023DA4(s->effect);
}
void ov01_021FF5C4(void *task, LocalState *s) {
    int mode;
    void *obj = s->mapObject;
    if (!sub_0205F0F8(obj, s->sprite, s->id, s->mapId)) {
        ov01_021F1640(task);
        return;
    }
    mode = sub_02068D90(task);
    if (mode == 1 && !MapObject_CheckFlag26(obj)) {
        ov01_021F1640(task);
        return;
    }
    if (MapObject_TestFlagsBits(obj, 2 << 8) == TRUE) {
        sub_02023EA4(s->effect, FALSE);
    } else {
        sub_02023EA4(s->effect, TRUE);
    }
    if (s->stage == 0) {
        sub_02023F04(s->effect, FX32_ONE);
        if (sub_02023F70(s->effect) / FX32_ONE >= 12) {
            if (mode == 0) {
                ov01_021F1640(task);
                return;
            }
            sub_02023F1C(s->effect, 0);
        }
    }
}
void ov01_021FF658(void *task, LocalState *s) {
    struct {
        VecFx32 facing, pos;
    } local;
    void *obj = s->mapObject;
    if (!sub_0205F0F8(obj, s->sprite, s->id, s->mapId)) {
        ov01_021F1640(task);
        return;
    }
    MapObject_CopyPositionVector(obj, &local.pos);
    MapObject_CopyFacingVector(obj, &local.facing);
    local.pos.x += local.facing.x;
    local.pos.z += local.facing.z;
    local.pos.z += 2 << 14;
    sub_02023E50(s->effect, &local.pos);
}
