#ifndef OV47_RESIDUAL_3_PRIVATE_H
#define OV47_RESIDUAL_3_PRIVATE_H
#include "global.h"
void NNS_G2dInitOamManagerModule(void);
void OamManager_Create(int, int, int, int, int, int, int, int, int);
void ObjCharTransfer_InitEx(const void *, int, int);
void ObjPlttTransfer_Init(int, int);
void ObjCharTransfer_ClearBuffers(void);
void ObjPlttTransfer_Reset(void);
void G2dRenderer_SetObjCharTransferReservedRegion(int, int);
void G2dRenderer_SetPlttTransferReservedRegion(int);
void *G2dRenderer_Init(int, void *, int);
void *Create2DGfxResObjMan(int, int, int);
void sub_0203A880(void);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
extern const u8 ov47_02259E58[];
void ov47_02258BB4(void *, int);
#endif
