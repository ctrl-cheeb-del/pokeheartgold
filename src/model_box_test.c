#include "model_box_test_internal.h"
#include "unk_0201F990.h"

BOOL sub_0201F990(NNSG3dResMdl *model, const VecFx32 *translation, const MtxFx33 *rotation, VecFx32 *baseScale) {
    BoxTestParams box;
    VecFx32 trans = *translation;
    ModelBounds *bounds = model != NULL ? (ModelBounds *)((u8 *)model + 0x14) : NULL;
    u32 scale[3];
    u32 scaleValue;
    u32 one;
    BOOL result;

    sub_0201FAA4(bounds->x, bounds->y, bounds->z, bounds->width, bounds->height, bounds->depth, &box);
    NNS_G3dGlbSetBaseTrans(&trans);
    MI_Copy36B(rotation, &NNS_G3dGlb.prmBaseRot);
    NNS_G3dGlb.flag &= ~0xa4;
    NNS_G3dGlbSetBaseScale(baseScale);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    scaleValue = bounds->scale;
    scale[0] = scaleValue;
    scale[1] = scaleValue;
    scale[2] = scaleValue;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    result = sub_0201FAC8(&box);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    return result;
}

BOOL sub_0201FA34(const VecFx32 *translation, const SimpleBounds *bounds) {
    BoxTestParams box;
    u32 one;
    BOOL result;

    sub_0201FAA4(0, 0, 0, bounds->x, bounds->y, bounds->z, &box);
    NNS_G3dGlbSetBaseTrans(translation);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    {
        fx32 scaleZ = bounds->scaleZ << 12;
        fx32 scaleY = bounds->scaleY << 12;
        fx32 scaleX = bounds->scaleX << 12;
        VecFx32 scale = { scaleX, scaleY, scaleZ };
        NNS_G3dGeBufferOP_N(0x1b, (const u32 *)&scale, 3);
    }
    result = sub_0201FAC8(&box);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    return result;
}

void sub_0201FAA4(s16 x, s16 y, s16 z, s16 width, s16 height, s16 depth, BoxTestParams *box) {
    box->x = x;
    box->y = y;
    box->z = z;
    box->width = width;
    box->height = height;
    box->depth = depth;
}

BOOL sub_0201FAC8(const BoxTestParams *box) {
    u32 result = 1;
    u32 value = 0x30c1;
    u32 zero;

    NNS_G3dGeBufferOP_N(0x29, &value, 1);
    zero = 0;
    NNS_G3dGeBufferOP_N(0x40, &zero, 1);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    NNS_G3dGeBufferOP_N(0x70, (const u32 *)box, 3);
    NNS_G3dGeFlushBuffer();
    while (G3X_GetBoxTestResult(&result) != 0) {
    }
    return result;
}
