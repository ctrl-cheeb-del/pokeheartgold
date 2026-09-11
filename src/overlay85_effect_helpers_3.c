#include "overlay85_effect_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E7A20(void *p,void *obj){u8 *base=(u8*)p+0x190;u8 *entry=base+0x4B0+0x7C*U32(obj,0x10);U32(entry,0)=1;U32(entry,0x78)=(u32)obj;sub_02069978(entry+0x24,base+0x14);ov85_021E7A54(p,entry);}
