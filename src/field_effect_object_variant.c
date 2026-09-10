#include "field_effect_object_variant_internal.h"

Ov01FE780Ctx *ov01_021FE780(void *a0);
void ov01_021FE79C(Ov01FE780Ctx *ctx);
void ov01_021FE7AC(Ov01FE780Ctx *ctx);
void ov01_021FE7D0(Ov01FE780Ctx *ctx);
u32 ov01_021FE7DC(LocalMapObject *obj, u32 x, u32 y, u32 dir, u32 a4);
BOOL ov01_021FE868(void *a0, Ov01FE780Work *work);
void ov01_021FE8B0(void *a0, Ov01FE780Work *work);
void ov01_021FE8C8(void *a0, Ov01FE780Work *work);
void ov01_021FE970(void *a0, Ov01FE780Work *work);
void ov01_021FE9F4(void *a0, void *a1);

const VecFx32 ov01_022090D0 = { 0, 4 * FX32_ONE, 4 * FX32_ONE };
const VecFx32 ov01_022090C4 = { FX32_ONE, FX32_ONE, FX32_ONE };

const UnkOv01_02209280 ov01_022090DC = {
    0x34,
    (UnkOv01_02209280_Cb1)ov01_021FE868,
    (UnkOv01_02209280_Cb1)ov01_021FE8B0,
    (UnkOv01_02209280_Cb2)ov01_021FE8C8,
    (UnkOv01_02209280_Cb2)ov01_021FE970,
};

Ov01FE780Ctx *ov01_021FE780(void *a0) {
    Ov01FE780Ctx *ctx = (Ov01FE780Ctx *)ov01_021F1430(a0, sizeof(Ov01FE780Ctx), 0, 0);
    ctx->manager = a0;
    ov01_021FE7AC(ctx);
    return ctx;
}

void ov01_021FE79C(Ov01FE780Ctx *ctx) {
    ov01_021FE7D0(ctx);
    ov01_021F1448(ctx);
}

void ov01_021FE7AC(Ov01FE780Ctx *ctx) {
    ov01_021F19F4(ctx->manager, &ctx->unk4, 0, 0x56, 0);
    sub_02069978(&ctx->unk18, &ctx->unk4);
}

void ov01_021FE7D0(Ov01FE780Ctx *ctx) {
    sub_02069784(&ctx->unk4);
}

u32 ov01_021FE7DC(LocalMapObject *obj, u32 x, u32 y, u32 dir, u32 a4) {
    Ov01FE780Args args;
    VecFx32 pos = { 0, 0, 0 };
    VecFx32 vec;

    args.dir = dir;
    args.fieldSys = ov01_021F146C(obj);
    args.ctx = (Ov01FE780Ctx *)ov01_021F1450(args.fieldSys, 4);
    args.object = obj;
    if (a4 == 0) {
        FieldSystem *fieldSystem = MapObject_GetFieldSystem(obj);
        pos.x = (x << 16) + (2 << 14);
        pos.z = (y << 16) + (2 << 14);
        sub_0206121C(fieldSystem, &pos);
    } else {
        vec = ov01_022090D0;
        MapObject_CopyPositionVector(obj, &pos);
        sub_0205F9A0(obj, &vec);
    }
    ov01_021F1620(args.fieldSys, &ov01_022090DC, &pos, a4, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(obj, 2));
}

BOOL ov01_021FE868(void *a0, Ov01FE780Work *work) {
    Ov01FE780Args *args = (Ov01FE780Args *)sub_02068D98(a0);
    LocalMapObject *object = args->object;

    work->args = *args;
    work->objId = MapObject_GetID(object);
    work->mapId = MapObject_GetMapID(object);
    work->unk08 = args->dir;
    work->unk18 = sub_02068D90(a0);
    work->unk1C = FX32_ONE;
    work->unk20 = FX32_ONE >> 2;
    return TRUE;
}

void ov01_021FE8B0(void *a0, Ov01FE780Work *work) {
    LocalMapObject *object = work->args.object;
    VecFx32 vec = { 0, 0, 0 };

    sub_0205F9A0(object, &vec);
}

void ov01_021FE8C8(void *a0, Ov01FE780Work *work) {
    VecFx32 vec;
    VecFx32 pos;
    LocalMapObject *object = work->args.object;
    int dir;
    fx32 t;

    if (!sub_0205F0A8(object, work->objId, work->mapId)) {
        ov01_021F1640((int)a0);
        return;
    }
    work->unk00 = 0;
    dir = MapObject_GetFacingDirection(object);
    work->unk04 = dir;
    if (dir == -1) {
        work->unk00 = 1;
        return;
    }
    if (work->unk18 != NULL) {
        work->unk08 = dir;
        t = work->unk1C + work->unk20;
        work->unk1C = t;
        if (t >= 4 * FX32_ONE) {
            work->unk1C = 4 * FX32_ONE;
            work->unk20 = -work->unk20;
        } else if (t <= FX32_ONE) {
            work->unk1C = FX32_ONE;
            work->unk20 = -work->unk20;
        }
        vec.x = 0;
        vec.y = work->unk1C + 4 * FX32_ONE;
        vec.z = 4 * FX32_ONE;
        sub_0205F9A0(object, &vec);
        MapObject_CopyPositionVector(object, &pos);
        pos.y += work->unk1C - FX32_ONE;
        sub_02068DA8(a0, &pos);
    }
}

void ov01_021FE970(void *a0, Ov01FE780Work *work) {
    MtxFx33 mtx;
    VecFx32 pos;
    VecFx32 scale;
    NNSG3dRenderObj *renderObj;
    int angle;

    if (work->unk00 == 1) {
        return;
    }
    if (work->unk08 == -1) {
        return;
    }
    work->unk14++;
    angle = 0;
    scale = ov01_022090C4;
    renderObj = &work->args.ctx->unk18;
    switch (work->unk08) {
    case 0:
        angle = 180;
        break;
    case 1:
        break;
    case 2:
        angle = 270;
        break;
    case 3:
        angle = 90;
        break;
    }
    sub_02020DA4(&mtx, 0, angle, 0);
    sub_02068DB8(a0, &pos);
    sub_020699AC(renderObj, &pos, &scale, &mtx);
}

void ov01_021FE9F4(void *a0, void *a1) {
    Ov01FE780Work *work = (Ov01FE780Work *)sub_02068D74(a0);

    work->unk18 = a1;
    work->unk1C = FX32_ONE;
    work->unk20 = FX32_ONE >> 2;
}
