#include "ov96_wave30_sprite_private.h"

void *ov96_0220AE40(u32 heap,void *a,void *b,u32 value){u8 *p;u32 v;u16 y;if(!a)GF_AssertFail();if(!b)GF_AssertFail();p=Heap_Alloc(heap,0x14);MI_CpuFill8(p,0,0x14);v=U32(p,0x10);v&=0xf80fffff;v|=(value<<25)>>5;U32(p,0x10)=v;y=(u16)(0x16-value*2);PTR(p,4)=ov96_0220D13C(a,b,0,0,4,y);ManagedSprite_SetDrawFlag(PTR(p,4),0);PTR(p,0)=ov96_0220D13C(a,b,0x78,0,1,(u16)(y+1));ManagedSprite_SetDrawFlag(PTR(p,0),0);ManagedSprite_SetAnimateFlag(PTR(p,0),1);return p;}
