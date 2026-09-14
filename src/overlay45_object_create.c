#include "global.h"

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct Coord {
    s16 x;
    s16 z;
} Coord;

typedef struct Obj {
    u8 state : 4;
    u8 type : 2;
    u8 top : 2;
    u8 unused[3];
    void *ctx;
    void *handle;
    u8 model[0x80];
    u32 lightFlags;
} Obj;

typedef struct Manager {
    void *resource2d;
    void *animation2d;
    void *resource3d;
    void *billboard;
    u8 unused[8];
    u8 modelResource[0x10];
    u8 unused2[4];
    u32 lightFlags;
} Manager;

typedef struct ResourceConfig {
    u16 key;
    u16 resourceId : 15;
    u16 embeddedTexture : 1;
} ResourceConfig;

typedef struct ResourceData {
    u32 words[4];
} ResourceData;

typedef struct BillboardResource {
    void *file0;
    u32 texture;
    const void *ranges;
    ResourceData data;
    u32 texKey;
    u32 tex4x4Key;
    u32 paletteKey;
} BillboardResource;

typedef struct CreateParams {
    void *billboard;
    BillboardResource *resource;
    Vec3 position;
    Vec3 scale;
} CreateParams;

extern const Vec3 ov45_02254C3C;
extern const u8 ov45_02254C98[];
extern Obj *ov45_02230A6C(void *);
extern s32 ov42_02228188(void *, s32);
extern ResourceConfig *ov45_0223099C(s32);
extern void *GF2dGfxRawResMan_GetObjById(void *, s32);
extern void *GF2dGfxRawResObj_GetData(void *);
extern void *GF3dGfxRawResMan_GetObjById(void *, s32);
extern void *GF3dGfxRawResObj_GetTex(void *);
extern u32 GF3dGfxRawResObj_GetTexKey(void *);
extern u32 GF3dGfxRawResObj_GetTex4x4Key(void *);
extern u32 GF3dGfxRawResObj_GetPlttKey(void *);
extern void sub_02026E18(void *, ResourceData *);
extern void sub_02023E2C(BillboardResource *, void *, void *, const void *, ResourceData *);
extern void sub_02023E04(BillboardResource *, void *, void *, const void *, ResourceData *, u32, u32, u32);
extern Coord ov42_022282DC(void *);
extern void ov49_02258800(const Coord *, Vec3 *);
extern void *sub_02023D44(CreateParams *);
extern void sub_02023FE4(void *, void (*)(void *, Obj *), Obj *);
extern void ov45_02230E64(void *, Obj *);
extern void ov45_02230A5C(void *, void *);
extern void sub_020182A8(void *, s32, s32, s32);
extern void ov45_02230A4C(void *);
extern void sub_02023DA4(void *);

Obj *ov45_0223070C(Manager *, void *);
void ov45_02230700(Obj *);
void ov45_02230884(Obj *);
void ov45_0223089C(Obj *, u32);

void ov45_02230700(Obj *o) {
    ov45_02230A4C((u8 *)o + 0x18);
}

Obj *ov45_0223070C(Manager *manager, void *ctx) {
    BillboardResource resource;
    CreateParams create;
    ResourceData data;
    Coord coord;
    ResourceConfig *config;
    void *raw3d;
    void *file0;
    void *texture;
    u32 tex4x4Key;
    u32 texKey;

    Obj *object = ov45_02230A6C(manager);
    object->ctx = ctx;
    Vec3 position = { 0, 0, 0 };
    Vec3 scale = ov45_02254C3C;
    config = ov45_0223099C(ov42_02228188(ctx, 7));
    file0 = GF2dGfxRawResObj_GetData(GF2dGfxRawResMan_GetObjById(manager->resource2d, 0x7F));
    raw3d = GF3dGfxRawResMan_GetObjById(manager->resource3d, config->resourceId);
    texture = GF3dGfxRawResObj_GetTex(raw3d);
    if (config->embeddedTexture == 1) {
        texKey = 0x119;
    } else {
        texKey = 0x118;
    }
    sub_02026E18(GF2dGfxRawResObj_GetData(GF2dGfxRawResMan_GetObjById(manager->animation2d, texKey)), &data);
    if (config->embeddedTexture == 1) {
        sub_02023E2C(&resource, file0, texture, &ov45_02254C98, &data);
    } else {
        texKey = GF3dGfxRawResObj_GetTexKey(raw3d);
        tex4x4Key = GF3dGfxRawResObj_GetTex4x4Key(raw3d);
        sub_02023E04(&resource, file0, texture, &ov45_02254C98, &data, texKey, tex4x4Key, GF3dGfxRawResObj_GetPlttKey(raw3d));
    }
    coord = ov42_022282DC(ctx);
    ov49_02258800(&coord, &position);
    position.z += 0x10000;
    create.billboard = manager->billboard;
    create.resource = &resource;
    create.position = position;
    create.scale = scale;
    object->handle = sub_02023D44(&create);
    sub_02023FE4(object->handle, ov45_02230E64, object);
    ov45_02230A5C(manager->modelResource, object->model);
    sub_020182A8(object->model, position.x, 0x2000, position.z - 0x8000);
    object->state = 1;
    object->top = 1;
    object->type = 0;
    object->lightFlags = manager->lightFlags;
    return object;
}

void ov45_02230884(Obj *o) {
    sub_02023DA4(o->handle);
    memset(o, 0, 0x90);
}

void ov45_0223089C(Obj *o, u32 value) {
    o->state = value;
}
