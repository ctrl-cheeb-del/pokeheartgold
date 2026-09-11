#include "g2d_renderer_setup_internal.h"
#include "unk_02025C44.h"

void GF_InitG2dRenderer(NNSG2dRendererInstance *instance, fx32 zOffset) {
    NNS_G2dInitRenderer(instance);
    instance->spriteZoffsetStep = zOffset;
}

void sub_02025C54(NNSG2dRenderSurface *surface, NNSG2dViewRect *rect, NNSG2dOamRegisterFunction oam, NNSG2dAffineRegisterFunction affine, NNSG2dRndCellCullingFunction culling, NNSG2dSurfaceType type, NNSG2dRendererInstance *renderer) {
    NNS_G2dInitRenderSurface(surface);
    surface->viewRect = *rect;
    surface->pFuncOamRegister = oam;
    surface->pFuncOamAffineRegister = affine;
    surface->pFuncVisibilityCulling = culling;
    surface->type = type;
    if (renderer != NULL) {
        NNS_G2dAddRendererTargetSurface(renderer, surface);
    }
}

void GF_SetG2dRendererSurface(NNSG2dRenderSurface *surface, NNSG2dViewRect *rect) {
    surface->viewRect = *rect;
}
