#ifndef TO45_OV41_R15_PRIVATE_H
#define TO45_OV41_R15_PRIVATE_H

#include "global.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

typedef struct Ov41ObjTransferTemplate {
    u32 words[4];
} Ov41ObjTransferTemplate;

extern const Ov41ObjTransferTemplate ov41_0224BFA4;

void ObjCharTransfer_InitEx(void *, int, int);
void ObjPlttTransfer_Init(int, int);
void ObjCharTransfer_ClearBuffers(void);
void ObjPlttTransfer_Reset(void);
void NNS_G2dInitOamManagerModule(void);
void OamManager_Create(int, int, int, int, int, int, int, int, int);
void *G2dRenderer_Init(int, void *, int);
void G2dRenderer_SetSubSurfaceCoords(void *, int, int);
void *Create2DGfxResObjMan(int, int, int);
void SpriteList_Delete(void *);
void Destroy2DGfxResObjMan(void *);
void ObjCharTransfer_Destroy(void);
void ObjPlttTransfer_Destroy(void);
void OamManager_Free(void);

void ov41_02246A94(void *);
void ov41_02246B34(void *);

#endif
