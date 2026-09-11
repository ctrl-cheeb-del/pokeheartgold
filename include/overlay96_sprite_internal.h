#ifndef TO40_OV96_R74_PRIVATE_H
#define TO40_OV96_R74_PRIVATE_H
#include "global.h"
typedef struct SpriteTriple {
    void *a;
    void *b;
    void *c;
    void *pad;
} SpriteTriple;
typedef struct SpriteWork {
    u8 pad000[0x184];
    SpriteTriple sprites[12];
} SpriteWork;
void ov96_021FBF90(void *, int);
void *ReadWholeNarcMemberByIdPair(void *, int, int);
void Sprite_Delete(void *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Destroy2DGfxResObjMan(void *);
void SpriteList_Delete(void *);
void Sprite_SetMatrix(void *, const VecFx32 *);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetDrawFlag(void *, BOOL);
void ov96_021FC320(void *);
void ov96_021FC404(void *);
void ov96_021FC450(void *, int);
void G2dRenderer_SetSubSurfaceCoords(void *, int, int);
void G2dRenderer_SetMainSurfaceCoords(void *, int, int);
void ov96_021FC0FC(u8 *, int, int);
void ov96_021FC144(u8 *);
int ov96_021FC164(u8 *, int, int);
void *ov96_021FC188(int);
void ov96_021FC1A8(u8 *);
void ov96_021FC214(u8 *, int);
void ov96_021FC248(u8 *, int, int);
void ov96_021FC28C(u8 *, int, int);
void ov96_021FC2B4(u8 *, BOOL);
void ov96_021FC2E0(u8 *, int, BOOL);
#endif
