#ifndef TO40_UNK_02025C44_PRIVATE_H
#define TO40_UNK_02025C44_PRIVATE_H
#include "global.h"
void NNS_G2dInitRenderSurface(NNSG2dRenderSurface *surface);
void NNS_G2dAddRendererTargetSurface(NNSG2dRendererInstance *renderer, NNSG2dRenderSurface *surface);
void sub_02025C54(NNSG2dRenderSurface *surface, NNSG2dViewRect *rect, NNSG2dOamRegisterFunction oam, NNSG2dAffineRegisterFunction affine, NNSG2dRndCellCullingFunction culling, NNSG2dSurfaceType type, NNSG2dRendererInstance *renderer);
BOOL sub_02025C98(const NNSG2dCellData *, const MtxFx32 *, const NNSG2dViewRect *);
#endif
