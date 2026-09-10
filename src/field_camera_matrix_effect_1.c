#include "field_camera_matrix_effect_internal.h"
typedef struct LocalSevenWords {
    u32 v[7];
} LocalSevenWords;
typedef struct LocalNineWords {
    fx32 v[9];
} LocalNineWords;
extern const u32 ov01_022095B4[];
LocalManager *ov01_02203E40(void *owner) {
    LocalManager *m = ov01_021F1430(owner, 0x68, 0, 0);
    m->owner = owner;
    m->task = NULL;
    m->scale = 0x3f800000;
    ov01_02203E74(m);
    return m;
}
void ov01_02203E64(LocalManager *m) {
    ov01_02203E94(m);
    ov01_021F1448(m);
}
void ov01_02203E74(LocalManager *m) {
    ov01_021F1AB8(m->owner, 0x6a, 0, (u8 *)m + 4, &m->value58, &m->resource);
}
void ov01_02203E94(LocalManager *m) {
    ov01_021F1448(m->resource);
}
void *ov01_02203EA0(void *obj) {
    struct {
        VecFx32 cameraPos, objectPos, spawnPos;
        struct {
            void *manager;
            LocalResource *resource;
            void *object;
            fx32 distance;
            VecFx32 direction;
        } ctx;
    } local;
    void *manager = ov01_021F146C(obj);
    void *cameraOwner = ov01_021F1468(manager);
    local.ctx.manager = manager;
    local.ctx.resource = ov01_021F1450(manager, 19);
    if (local.ctx.resource->task != NULL) {
        return local.ctx.resource->task;
    }
    local.ctx.object = obj;
    MapObject_CopyPositionVector(obj, &local.objectPos);
    Camera_GetLookAtCamPos(&local.cameraPos, *(void **)((u8 *)cameraOwner + 0x24));
    VEC_Subtract(&local.cameraPos, &local.objectPos, &local.ctx.direction);
    local.ctx.distance = VEC_Distance(&local.cameraPos, &local.objectPos);
    local.ctx.distance /= 3;
    VEC_Normalize(&local.ctx.direction, &local.ctx.direction);
    MapObject_CopyPositionVector(obj, &local.spawnPos);
    local.ctx.resource->task = ov01_021F1620(manager, ov01_022095B4, &local.spawnPos, 0, &local.ctx, MapObject_GetPriorityPlusValue(obj, 2));
    return local.ctx.resource->task;
}
void ov01_02203F2C(void *task, u32 value) {
    LocalManager *m = *(LocalManager **)((u8 *)sub_02068D74(task) + 8);
    m->scale = value;
}
BOOL ov01_02203F3C(void *task, LocalState *s) {
    *(LocalSevenWords *)&s->data04 = *(LocalSevenWords *)sub_02068D98(task);
    s->mode = sub_02068D90(task);
    return TRUE;
}
void ov01_02203F68(void) {
}
void ov01_02203F6C(void *task, LocalState *s) {
    VecFx32 input, out;
    MapObject_CopyPositionVector(s->mapObject, &input);
    VEC_MultAdd(s->multiplier, &s->direction, &input, &out);
    sub_02068DA8(task, &out);
}
void ov01_02203F98(void *task, LocalState *s) {
    static const LocalNineWords identity = {
        { FX32_ONE, 0, 0, 0, FX32_ONE, 0, 0, 0, FX32_ONE }
    };
    struct {
        LocalNineWords matrix;
        VecFx32 scale, pos;
    } local;
    local.matrix = identity;
    local.scale.x = (fx32)(4096.0f * (*(float *)&s->resource->scale));
    local.scale.y = (fx32)(4096.0f * (*(float *)&s->resource->scale));
    local.scale.z = (fx32)(4096.0f * (*(float *)&s->resource->scale));
    sub_02068DB8(task, &local.pos);
    GF3dRender_DrawModel((u8 *)s->resource + 4, &local.pos, &local.matrix, &local.scale);
}
