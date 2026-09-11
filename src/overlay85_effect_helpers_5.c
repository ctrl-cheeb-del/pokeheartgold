#include "overlay85_effect_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E7C70(void *task,void *v){u8*p=v;u8*obj=(u8*)(u32)U32(p,0x1C);switch(U32(p,4)){case 0:ov85_021E7E88(task,(s32)obj);U32(p,0x10)=0x4000;U32(p,0x14)=0xFFFFFBBC;U32(p,4)++;case 1:U32(obj,0x54)+=U32(p,0x10);U32(p,0x10)+=U32(p,0x14);U32(p,8)++;if((s32)U32(p,8)>=15){U32(p,8)=0;U32(p,0x10)=0;if(U32(p,0xC)==0){U32(p,0xC)=1;return;}U32(obj,0x54)=0;ov85_021E7FC0(task,obj);memset(p,0,0x20);}break;}}
