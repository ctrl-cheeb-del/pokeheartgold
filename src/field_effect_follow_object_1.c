#include "field_effect_follow_object_internal.h"

Ov01FieldEffectCtx *ov01_021FEEEC(FieldEffectManager *manager) {
    Ov01FieldEffectCtx *ctx = (Ov01FieldEffectCtx *)ov01_021F1430(manager, 4, 0, 0);
    ctx->manager = manager;
    ov01_021FEF18(ctx);
    return ctx;
}

void ov01_021FEF08(Ov01FieldEffectCtx *ctx) {
    ov01_021FEFF8(ctx);
    ov01_021F1448(ctx);
}

void ov01_021FEF18(Ov01FieldEffectCtx *ctx) {
    ov01_021F18D4(ctx->manager, 0, 0x7e);
    ov01_021F18D4(ctx->manager, 5, 0x7f);
    ov01_021F1908(ctx->manager, 0, 0x8c);
    ov01_021F1908(ctx->manager, 3, 0x8d);
    ov01_021F1908(ctx->manager, 4, 0x8e);
    ov01_021F1908(ctx->manager, 5, 0x8f);
    ov01_021F1930(ctx->manager, 0, 0x19, 1);
    ov01_021F1930(ctx->manager, 4, 0x10, 1);
    ov01_021F1930(ctx->manager, 5, 0, 1);
    ov01_021F1930(ctx->manager, 6, 1, 1);
    ov01_021F1758(ctx->manager, 0, 0, 0, 0, 0, &ov01_02209178);
    ov01_021F1758(ctx->manager, 5, 5, 3, 4, 0, &ov01_02209190);
    ov01_021F1758(ctx->manager, 6, 5, 4, 5, 0, &ov01_02209160);
    ov01_021F1758(ctx->manager, 7, 5, 5, 6, 0, &ov01_022091A8);
}

void ov01_021FEFF8(Ov01FieldEffectCtx *ctx) {
    ov01_021F18FC(ctx->manager, 0);
    ov01_021F18FC(ctx->manager, 5);
    ov01_021F1924(ctx->manager, 0);
    ov01_021F1924(ctx->manager, 3);
    ov01_021F1924(ctx->manager, 4);
    ov01_021F1924(ctx->manager, 5);
    ov01_021F1970(ctx->manager, 0);
    ov01_021F1970(ctx->manager, 4);
    ov01_021F1970(ctx->manager, 5);
    ov01_021F1970(ctx->manager, 6);
    ov01_021F18C8(ctx->manager, 0);
    ov01_021F18C8(ctx->manager, 5);
    ov01_021F18C8(ctx->manager, 6);
    ov01_021F18C8(ctx->manager, 7);
}

void ov01_021FF070(LocalMapObject *object, int a1) {
    VecFx32 pos;
    FieldEffectFollowArgs args;
    FieldSystem *fieldSys = ov01_021F146C(object);

    args.x = MapObject_GetXCoord(object);
    args.y = MapObject_GetYCoord(object);
    args.z = MapObject_GetZCoord(object);
    args.dx = 0;
    args.dz = 0;
    args.dir = -1;
    args.fieldSys = fieldSys;
    args.taskman = ov01_021F1468(fieldSys);
    args.unk14 = ov01_021F1450(fieldSys, 8);
    args.object = object;
    MapObject_CopyPositionVector(object, &pos);
    ov01_021F1620(fieldSys, &ov01_02209138, &pos, a1, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(object, 2));
}
