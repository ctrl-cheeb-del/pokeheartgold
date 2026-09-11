#include "overlay49_menu_helpers_private.h"

void ov49_0225AE4C(Ov49R20 *w,void **mgr){int i;if(w->menu)ov49_0225AEE0(w,w->menu);if(w->unk30)ov49_0225B014(w,0,0);for(i=0;i<2;i++){Sprite_Delete(w->sprites[i]);w->sprites[i]=0;}SpriteTransfer_DeleteCharTransferTask(w->res[0]);SpriteTransfer_DeletePlttTransferTask(w->res[1]);for(i=0;i<4;i++)DestroySingle2DGfxResObj(mgr[0x4c+i],w->res[i]);}

void ov49_0225AEA8(Ov49R20 *w,u32 count,int heap,int value){u32 i;u32 offset;GF_ASSERT(w->menu==0);w->menu=ListMenuItems_New(count,heap);i=0;w->count=count;if(i<count){offset=i;do{((int*)((u8*)w->menu+offset))[1]=value;i++;offset+=8;}while(i<count);}}
