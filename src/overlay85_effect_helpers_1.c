#include "overlay85_effect_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E776C(void *p,void *obj){sub_02069978((u8*)obj+0x5C,(u8*)p+0x190);U32(obj,4)=1;ov85_021E7A20(p,obj);ov85_021E7AC8(p,obj);}
