#include "overlay85_effect_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E782C(void *p){int count=U32(p,0x30),i=0;u8*base=(u8*)p+0x190;u8*a=base+0x140;u8*b=base+0x4B0;u8*c=base+0x71C;if(count>0)do{if(U32(a,4))sub_020699D0(a+0x5C,a+0x44,a+0x38,a+0x24);if(U32(b,0))sub_020699D0(b+0x24,b+0x18,b+0xC,b+4);if(U32(c,0))sub_020699BC(c+0x10,c+4);i++;a+=0xB0;b+=0x7C;c+=0x68;}while(i<count);}

void ov85_021E78A4(void *p,void *arg){int count;int i;u8 *base;u8 *target;count=U32(p,0x30);i=0;base=(u8*)p+0x190;if(count>0){target=base+0x15C;do{if(U32(base,0x140))ov85_021E8530(target,arg);i++;base+=0xB0;target+=0xB0;}while(i<count);}}
