#include "ov47_wave36_private.h"

void ov47_0225912C(Ov47R5*w,void*a,void**mgr){int i;u8*cursor;ov47_02259D24((u8*)w+0x2c);RemoveWindow(w);Sprite_Delete(w->sprite);SpriteTransfer_DeleteCharTransferTask(w->charRes);SpriteTransfer_DeletePlttTransferTask(w->plttRes);cursor=(u8*)w;for(i=0;i<4;i++){DestroySingle2DGfxResObj(mgr[0x4c],*(void**)(cursor+0x18));cursor+=4;mgr++;}}
