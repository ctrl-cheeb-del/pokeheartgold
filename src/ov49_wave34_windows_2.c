#include "ov49_wave34_windows_private.h"

void ov49_0225C78C(void *p,void *mgr){int i=0;u8 *q=p;for(;i<12;i++,q+=4){if(PTR(q,0xbc)){Sprite_Delete(PTR(q,0x7c));PTR(q,0x7c)=0;SpriteTransfer_DeleteCharTransferTask(PTR(q,0xbc));DestroySingle2DGfxResObj(PTR(mgr,0x130),PTR(q,0xbc));PTR(q,0xbc)=0;}}q=p;for(i=0;i<4;i++,q+=4){if(PTR(q,0xac)){SpriteTransfer_DeletePlttTransferTask(PTR(q,0xac));DestroySingle2DGfxResObj(PTR(mgr,0x134),PTR(q,0xac));DestroySingle2DGfxResObj(PTR(mgr,0x138),PTR(q,0xec));DestroySingle2DGfxResObj(PTR(mgr,0x13c),PTR(q,0xfc));PTR(q,0xac)=0;}}}

void *ov49_0225C828(int a,int b,int c,int d){if(b==c)return ov49_02269764+d*8;return ov49_022699AC+a*8;}
