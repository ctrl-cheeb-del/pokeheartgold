#ifndef SOL40_OV49_R20_PRIVATE_H
#define SOL40_OV49_R20_PRIVATE_H
#include "global.h"
typedef struct {u8 p0[0x10];u32 printer;u32 speed;void *str;u8 p1c[0x14];void *unk30;void *menu;u16 count;u8 p3a[2];u32 unk3c;void *res[4];void *sprites[2];} Ov49R20;
int TextPrinterCheckActive(u8); void RemoveTextPrinter(u8);
void ov49_0225AC38(void *); void ClearFrameAndWindow2(void *,int); void ClearWindowTilemapAndScheduleTransfer(void *); void ov49_0225AAC8(void *);void SetWindowPaletteNum(void *,int);void ov49_0225AB14(void);
void FillWindowPixelBuffer(void *,int); void String_Copy(void *,void *);int AddTextPrinterParameterized(void *,int,void*,int,int,int,void*);void DrawFrameAndWindow3(void*,int,int,int,int);
void ov49_0225AEE0(void*,void*);void ov49_0225B014(void*,int,int);void Sprite_Delete(void*);void SpriteTransfer_DeleteCharTransferTask(void*);void SpriteTransfer_DeletePlttTransferTask(void*);void DestroySingle2DGfxResObj(void*,void*);
void *ListMenuItems_New(u32,int);
int ov49_0225AC5C(Ov49R20*);void ov49_0225AC74(Ov49R20*);void ov49_0225ACA8(void*);void ov49_0225ACBC(void);void ov49_0225ACC4(Ov49R20*,void*);void ov49_0225AE4C(Ov49R20*,void**);void ov49_0225AEA8(Ov49R20*,u32,int,int);
#endif
