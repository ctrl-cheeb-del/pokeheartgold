#include "global.h"

#include "gf_3d_render.h"
#include "overlay45_model_helpers_r40_private.h"

extern void ov49_02258830(NNSG3dResFileHeader **file, void *narc, int fileId, u32 heapId);
extern void sub_02018068(Ov45R40Model *model);
extern void NNS_G3dMdlSetMdlPolygonIDAll(NNSG3dResMdl *model, int polygonId);
extern void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *model, int alpha);

u32 ov45_022309D0(u32 divisor, u16 value, u32 factor) {
    return ((u16)(value + 1) * factor / divisor) << 12;
}

void ov45_022309E8(Ov45R40Model *model, void *narc, int fileId, u32 heapId) {
    NNSG3dResFileHeader *file;

    ov49_02258830(&file, narc, fileId, heapId);
    model->file = file;
    model->set = NNS_G3dGetMdlSet(model->file);
    model->model = NNS_G3dGetMdlByIdx(model->set, 0);
    model->texture = NNS_G3dGetTex(model->file);
    GF3dRender_BindModelSet(model->file, model->texture);
    NNS_G3dMdlSetMdlPolygonIDAll(model->model, 20);
}

void ov45_02230A44(Ov45R40Model *model) {
    sub_02018068(model);
}

void ov45_02230A4C(Ov45R40Model *model, int alpha) {
    model->alpha = alpha;
    NNS_G3dMdlSetMdlAlphaAll(model->model, alpha);
}
