#ifndef SOL40_OV47_R5_PRIVATE_H
#define SOL40_OV47_R5_PRIVATE_H
#include "global.h"
typedef struct{u8 window[0x14];void*sprite;void*charRes;void*plttRes;u8 rest[0x10];} Ov47R5;
void ov47_02259D24(void*);void RemoveWindow(void*);void Sprite_Delete(void*);void SpriteTransfer_DeleteCharTransferTask(void*);void SpriteTransfer_DeletePlttTransferTask(void*);void DestroySingle2DGfxResObj(void*,void*);
void ov47_0225912C(Ov47R5*,void*,void**);void ov47_02258DC8(Ov47R5*,void*,void**);
#endif
