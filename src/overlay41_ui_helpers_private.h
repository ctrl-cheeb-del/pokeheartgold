#ifndef SOL40_R31_PRIVATE_H
#define SOL40_R31_PRIVATE_H
#include "global.h"
#include <string.h>
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
void FillWindowPixelBuffer(void *,int); void *NewMsgDataFromNarc(int,int,int,int); void GF_AssertFail(void); void *NewString_ReadMsgData(void *,int); int AddTextPrinterParameterizedWithColor(void *,int,void *,int,int,int,int,int); void String_Delete(void *); void DestroyMsgData(void *); void DrawFrameAndWindow2(void *,int,int,int);
void Sprite_SetAnimCtrlSeq(void *,int); void Sprite_Delete(void *); void ov41_0224B084(void *,void *); void SpriteTransfer_DeleteCharTransferTask(void *); void SpriteTransfer_DeletePlttTransferTask(void *); void DestroySingle2DGfxResObj(void *,void *); void SysTask_Destroy(void *); void ov41_0224AD84(void *); void ov41_0224B310(void *); void ov41_0224B270(void *); void ov41_0224B298(void *); void ov41_0224B450(void *); void ov41_0224B374(void *,void *); void PlaySE(int);
int ov41_0224AE78(void *,int,int,int,int,int,int,int,void **); int ov41_0224ADD8(void *,int,int,int,int,int,int,void **); int ov41_0224AE24(void *,int,int,int,int,int,int,int); int ov41_0224AD90(void *,int,int,int,int,int,int); void ov41_0224AFD4(void *,void *); void ov41_0224AF8C(void *,int); void ov41_0224B084(void *,void *); void ov41_0224B21C(void *,void *); void ov41_0224B250(void *); void ov41_0224B270(void *);
#endif
