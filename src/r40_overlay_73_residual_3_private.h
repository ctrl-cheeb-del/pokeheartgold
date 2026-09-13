#ifndef SOL_R40_FOLLOWUP_OV73_3_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV73_3_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct SolObjTransferTemplate {
    u32 word[4];
} SolObjTransferTemplate;
extern const SolObjTransferTemplate ov73_021EA550;
void ObjCharTransfer_Init(const void *);
void ObjPlttTransfer_Init(int, int);
void ObjCharTransfer_ClearBuffers(void);
void ObjPlttTransfer_Reset(void);
void NNS_G2dInitOamManagerModule(void);
void *OamManager_Create(int, int, int, int, int, int, int, int, int);
void *G2dRenderer_Init(int, void *, int);
void G2dRenderer_SetSubSurfaceCoords(void *, int, int);
void *Create2DGfxResObjMan(int, int, int);
void *AddCharResObjFromOpenNarc(void *, void *, int, int, int, int, int);
void *AddPlttResObjFromOpenNarc(void *, void *, int, int, int, int, int, int);
void *AddCellOrAnimResObjFromOpenNarc(void *, void *, int, int, int, int, int);
void SpriteTransfer_CreateCharTransferTask(void *);
void SpriteTransfer_CreateExtPlttTransferTask(void *);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void ov73_021E63BC(void *, void *, u32);
void ov73_021E735C(void *, int, int, void *);
void *YesNoPrompt_Create(int);
int FontID_String_GetWidth(int, void *, int);
u8 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
#endif
