#ifndef SOL40_R33_PRIVATE_H
#define SOL40_R33_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define U16(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
extern u8 ov49_02269764[];
extern u8 ov49_022699AC[];
void ScheduleWindowCopyToVram(void *);
void ov49_0225B3C8(void *,void *,int);
int ov45_0222AA84(void *);
int ov45_0222AAA8(void *);
void ov49_0225B408(void *,int,int);
void ov49_0225B418(void *,int,int,int);
void ov49_0225B42C(void *,int,u16);
void FillWindowPixelBuffer(void *,int);
void Sprite_Delete(void *);
void *Sprite_GetImageProxy(void *);
void ObjCharTransfer_DeleteTaskCopyByProxyPtr(void *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void DestroySingle2DGfxResObj(void *,void *);
void TouchHitboxController_Destroy(void *);
void RemoveWindow(void *);
void Heap_Free(void *);
void BgClearTilemapBufferAndCommit(void *,int);
void BgSetPosTextAndCommit(void *,int,int,int);
void *ov49_0225B388(void *,int,int);
int FontID_String_GetWidth(int,void *,int);
void AddTextPrinterParameterizedWithColor(void *,int,void *,int,int,int,int,int);
#endif
